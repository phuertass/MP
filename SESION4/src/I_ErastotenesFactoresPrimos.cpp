/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Fichero: Eratostenes_Array_para_Descomposicion.cpp
//
/*	
	Uso de los primos calculados mediante la criba de Eratóstenes.
	Se usarán para descomposición los primos hasta MAX_PRIMO (incluido).
	
	Aplicación: Calcular la descomposición en factores primos de un número.
*/
/***************************************************************************/
 
#include <iostream>
#include <iomanip>
#include <string>
#include "FuncionesErastotenes.h"
using namespace std;


/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// Valor terminador para la lectura 
	const int TERMINADOR = 0; 
	
	// Mostrar DATOS_POR_LINEA núms. por línea
	const int DATOS_POR_LINEA = 10; 
			

	// Máximo primo permitido en el resultado. 
	const int MAX_PRIMO = 5000; 
	
	
	// Máximo número de primos que se pueden almacenar. 
	// PRE: MAX_DATOS <= MAX_PRIMO
	// Todos estarán entre 1 y MAX_PRIMO (Es posible que no quepan todos)	
	const int MAX_DATOS = 1000;

	// El vector "primos" contendrá los "MAX_DATOS" primeros primos 
	int  primos[MAX_DATOS];
	
	// Número máximo de factores primos permitidos
	const int MAX_FACTORES = 50;

	
	/***********************************************************************/
	// Calcular, guardar y mostrar los primos
	/***********************************************************************/
	// Leer el valor máximo (todos los primos calculados serán menores)

	cout << endl;
	cout << "Se calcularan los primos menores que " << MAX_PRIMO << endl;
	cout << "con un máximo de " << MAX_DATOS << " valores." << endl;
	cout << endl;
	
	// Emplearemos un vector de datos lógicos para la criba de manera que  
	// "es_primo[i]" será TRUE si "i" es primo. 	
	bool es_primo[MAX_PRIMO+1]; 	
	
	//Calculo de los numeros primos
	int num_primos = CalcularPrimos(es_primo, primos, MAX_PRIMO, MAX_DATOS);	
	
	/***********************************************************************/
	// Mostrar los primos calculados
	/***********************************************************************/
	MostrarPrimos(primos, num_primos, DATOS_POR_LINEA);

	
	/***********************************************************************/
	// Calcular y mostrar descomposición en factores primos
	/***********************************************************************/
	const string TITULO_LECTURA = "Valor a descomponer (finalizar con " + 
	                              to_string(TERMINADOR) + ") : ";

	int valor; // Número a descomponer
	
	//  Lectura	

	do {
		cout << endl;
		cout << TITULO_LECTURA;
		cin >> valor;
	} while ((valor <= 1) && (valor !=TERMINADOR));
	
	
	while (valor !=TERMINADOR) {
				
		Pareja descomposicion[MAX_FACTORES] = {{0,0}};
	
		int utilizados_descomposicion = 0; // Inicializar descomposición

		
		/*******************************************************************/
		// Calcular descomposición en factores primos
		/*******************************************************************/		

		int n = valor; // copia para salvaguardar "valor"
	
		// Los primos que se evalúan como posibles divisores de "n" se 
		// toman del array "primos". 
		// Se empieza con el 2 (ocupa la casilla 1 de "primos"). Recuerde 
		// que la casilla 0 está ocupada por el 1.
			
		int pos_primo = 1;					
		int candidato = primos[pos_primo];  // El primer candidato es 2
						
		int veces = 0; // exponente --> candidato^veces 
										  
		while ((n > 1) && (pos_primo<num_primos) && 
		   	   (utilizados_descomposicion<MAX_FACTORES)) {
			
			if  (n % candidato == 0)	{ // "candidato" es un factor primo
				
				veces = 1; 
				
				// Se sigue probando con el mismo factor ("candidato")
				
				n = n / candidato;
			
				while (n % candidato == 0) {
					
					veces++; 
					n = n / candidato;
				}
				
				// Actualizar el array de factores primos
				descomposicion[utilizados_descomposicion].primo = candidato;				
				descomposicion[utilizados_descomposicion].potencia = veces;
				
				utilizados_descomposicion++;
			} 
			
			// Probar con el siguiente primo
			pos_primo++;
			candidato = primos[pos_primo];
				
		} // while 
		

		if ((pos_primo>=num_primos) || 
			(utilizados_descomposicion>=MAX_FACTORES))  {
		
			utilizados_descomposicion = 0; 
		}	


		/*******************************************************************/
		// Mostrar descomposición en factores primos
		/*******************************************************************/	

		if (utilizados_descomposicion == 0) {

			cout << endl; 
			cout << "ERROR: Faltan primos para resultado o se requieren " 
			     << "demasiados factores." << endl;
			cout << endl; 

		}

		else {
					
			cout << endl; 
			cout << valor << " = ";

			for (int i=0; i<utilizados_descomposicion; i++) {
				
				int veces_primo = descomposicion[i].potencia; 
				
				if (veces_primo > 0) { // No se muestran los 
									   // valores no primos

					cout << setw(2) << descomposicion[i].primo;  // base

					// Se escribe el exponente solo si es mayor que 1
					if (veces_primo > 1) cout <<  "^" << veces_primo;
					
					if (i<utilizados_descomposicion-1) 
						cout << " * "; // evita el último *
				}

			} // for

			cout << endl; 
		}


		// Lectura del siguiente valor a descomponer
		
		do {
			cout << endl;
			cout << TITULO_LECTURA; 
			cin >> valor;
		} while ((valor <= 1) && (valor !=TERMINADOR));
		
				
	} // while (valor !=TERMINADOR) 
		
	
	cout << endl;
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
