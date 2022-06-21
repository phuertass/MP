/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
//
// Programa que lee una secuencia indefinida de caracteres de la entrada
// est�ndar y "comprime" todas las l�neas de esa secuencia, eliminando
// los separadores que hay en cada l�nea, exceptuando el '\n'.
//
// Procesamiento a nivel de LINEA y gestion cl�sica (MALA DECISION) 
//
// Fichero: ComprimeLineas-ProcesamientoLineasClasico.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	const int TAM = 256;	// M�xima longitud de la cadena empleada
	char cad[TAM];			// para leer cada l�nea

	int pos_escritura;  // posici�n donde escribir 
	int pos_lectura;	// posici�n donde leer 


	cin.getline(cad, TAM);	// Lectura adelantada de una cadena

	while (!cin.eof()) {

		if (strlen(cad) > 0) {

			/* Algoritmo: 

			Recorrer todas las componentes que hay en el vector
				Si la componente actual no es un separador
					ponedla donde indique pos_escritura
				Avanzar pos_lectura
			*/

			pos_escritura = 0;		
		
			for (pos_lectura = 0; pos_lectura < strlen(cad); pos_lectura++){

				char c = cad[pos_lectura];	// Car�cter a estudiar

				if (c!=' ' && c!='\t' && c!='\v' && c!='\f' && c!='\r') {

					cad[pos_escritura] = cad[pos_lectura];
					pos_escritura++;					
				
				}	// OJO: "pos_lectura" SIEMPRE avanza (for), mientras que
					// "pos_escritura" lo hace cuando salta un separador.

			} // for 

			cad[pos_escritura] = '\0';	// IMPORTANTE

		} // if (strlen(cad) > 0)

		cout << cad << endl;		// enviarla "comprimida" a cout

		cin.getline(cad, TAM);		// Nueva lectura

	} // while (!cin.eof()) 

	return (0);
}

/***************************************************************************/
/***************************************************************************/
