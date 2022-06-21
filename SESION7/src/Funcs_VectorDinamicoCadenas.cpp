/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// RELACION DE PROBLEMAS 2
//
// Definición de las funciones declaradas en Funcs_VectorDinamicoCadenas.h
//  
// Fichero: Funcs_VectorDinamicoCadenas.cpp
//
/***************************************************************************/

#include <iostream> 
#include <iomanip> 
#include <cstring>

#include "Funcs_VectorDinamicoCadenas.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Crear vector dinámico de cadenas.
// Argumentos: 
// 		capacidad_inicial, número de casillas con las que se crea el vector.
//                         Por defecto: TAM_INICIAL
// 		el_tipo_redimension, tipo de redimensión. Por defecto: EnBloques
//
// Devuelve: el vector dinámico creado.
//
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es "capacidad_inicial"

VectorDinamicoCadenas CreaVectorDinamico (int capacidad_inicial, 
								TipoRedimension el_tipo_redimension )
{
	VectorDinamicoCadenas nuevo; 

	nuevo.capacidad = TAM_INICIAL;
	nuevo.usados = 0;
	nuevo.lineas = new char * [TAM_INICIAL];

	nuevo.tipo_redimension = el_tipo_redimension;

	return (nuevo); 
}

/***************************************************************************/
/***************************************************************************/
// Inicializar vector dinámico de cadenas.
// Parámetros: 
// 		v (referencia), el vector que se va a Inicializar. 
// 		capacidad_inicial, número de casillas con las que se crea el vector.
// Devuelve: el vector dinámico creado.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es "capacidad_inicial"

void InicializaVectorDinamico (VectorDinamicoCadenas & v, 
	                            int capacidad_inicial)
{
	v.capacidad = TAM_INICIAL;
	v.usados = 0;
	v.lineas = new char * [TAM_INICIAL];
}

/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas usadas de un vector dinámico.
// Recibe: v, el vector que se va a consultar.
// Devuelve: el número de casillas usadas de un vector dinámico

int UsadosVectorDinamico (const VectorDinamicoCadenas v)
{
	return (v.usados);
}

/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas reservadas de un vector dinámico.
// Recibe: v, el vector que se va a consultar.
// Devuelve: el número de casillas reservadas de un vector dinámico

 int CapacidadVectorDinamico (const VectorDinamicoCadenas v)
{
	return (v.capacidad);
}
 
/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector dinámico de acuerdo al tipo de redimensión indicado. 
// Parámetros: 	
//		v (referencia), Vector dinámico de cadenas.  
//		tipo, tipo de redimensión que se va a emplear 

void Redimensiona (VectorDinamicoCadenas & v, TipoRedimension tipo)
{
	int lineas_ocupadas = v.capacidad;
	
	// Actualizar capacidad (de la nueva estructura)
    switch (tipo) {

        case (DeUnoEnUno): // 1 casilla más
            v.capacidad++;
            break;

        case (EnBloques): // TAM_BLOQUE casillas más
            v.capacidad+=TAM_BLOQUE;
            break;

        case (Duplicando): // Duplicar tamaño
            v.capacidad*=2;
            break;
    }
	// Reservar en el vector de punteros para un bloque adicional 
	char ** tmp = new char * [v.capacidad];
	
	// Copiar lo que hay y liberar el original tras la copia 
	for (int l=0; l<v.usados; l++) {

		// Opción 1 (recomendable): utilizando las cadenas ya existentes, 
		// haciendo que los punteros de "tmp" apunten a éstas.  

		tmp[l] = v.lineas[l];

		// Opción 2: Pidiendo nueva memoria con los punteros de "tmp", 
		// copiando lo que ya existe (la memoria referenciada por los 
		// punteros de "lineas") y liberando la memoria referenciada éstos.
		/* 		
		tmp[l]=new char[strlen(v.lineas[l])+1];
		strcpy(tmp[l], v.lineas[l]);

		delete [] v.lineas[l];
		*/
	}
	
	// Liberar el vector de punteros original
	delete [] v.lineas;

	// Reajustar el puntero principal
	v.lineas = tmp;
}

/***************************************************************************/
/***************************************************************************/
// Reajusta el vector dinámico para que no hayan casillas vacías.
// Recibe: 	
//		v (referencia), Vector dinámico de cadenas.  

void Reajusta (VectorDinamicoCadenas & v)
{

	if (v.usados != v.capacidad) { 

		// Reservar las casillas estrictamente necesarias
		char ** tmp = new char * [v.usados];
			
		// Copiar lo que hay y liberar el original tras la copia 
		for (int l=0; l<v.usados; l++) {

			tmp[l]=new char[strlen(v.lineas[l])+1];
			strcpy(tmp[l], v.lineas[l]);

			delete [] v.lineas[l];
		}
			
		// Liberar el vector de punteros original
		delete [] v.lineas;

		// Reajustar el puntero principal
		v.lineas = tmp;

		// Actualizar capacidad
		v.capacidad = v.usados;
	}
}


/***************************************************************************/
/***************************************************************************/
// Añade un valor al vector dinámico. Si no hubiera espacio se redimensiona 
// para poder alojar al nuevo valor.  
// Pârámetros: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		cadena, cadena que se va a añadir al vector dinámico. 

void AniadeVectorDinamico (VectorDinamicoCadenas & v, char * cadena)
{
	// Si no cabe --> redimensiona

	if (UsadosVectorDinamico(v)==CapacidadVectorDinamico(v)) { 

			Redimensiona (v, EnBloques); // Redimensionar 

	}

	// Hay sitio en "lineas" para un puntero con el que poder apuntar a 
	// la cadena clásica "cadena" (ya existe, reside en el Heap). 
	// No es preciso reservar memoria. 

	v.lineas[v.usados] =cadena;	
	v.usados++; // Actualizar el contador
}

/***************************************************************************/
/***************************************************************************/
// Calcula el número de líneas totales y vacías, además del número de 
// párrafos en "lineas".
// Recibe: 	
//		v (referencia), Vector dinámico de cadenas.  
//		cl (referencia), número de líneas. 
//		cv (referencia), número de líneas vacías.
//		cp (referencia), número de párrafos.

void Calculos_lineas (const VectorDinamicoCadenas & v, 
	                  int & cl, int & cv, int & cp)
{
	// Número de líneas (trivial)

	cl = v.usados;

	// Número de líneas vacías

	cv = 0;

	for (int l=0; l<v.usados; l++) 

		if (strlen(v.lineas[l])==0) cv++;

	// Número de párrafos

	cp = 0;

	bool en_parrafo = false;

	for (int l=0; l<v.usados; l++) {

		if (strlen(v.lineas[l])==0 && en_parrafo) 
			en_parrafo = false;	
	
		if (strlen(v.lineas[l])!=0 && !en_parrafo) {
			en_parrafo = true;
			cp++;
		}
	}

}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por "lineas".
// Recibe: 	
//		v (referencia), Vector dinámico de cadenas.  
// POST: lineas = 0 Y num_lineas = 0

void LiberaMemoria (VectorDinamicoCadenas & v)
{
	if (v.lineas) {

		for (int l=0; l<v.usados; l++) 
			delete [] v.lineas[l];
					
		delete [] v.lineas;

		v.lineas = 0; 

		v.usados = 0;
		v.capacidad = 0;
	}
}

/***************************************************************************/
/***************************************************************************/
// Mostrar contenido de "lineas"

void MostrarVectorDinamicoCadenas (const VectorDinamicoCadenas & v) 
{
	cout << endl; 
	cout << "Usados    = " << v.usados << endl; 	
	cout << "Capacidad = " << v.capacidad << endl; 	
	cout << endl; 
	
	for (int l=0; l<v.usados; l++) 
		cout << "[" << setw(4) << l << "] " <<"|"<< v.lineas[l] <<"|"<< endl;
	cout << endl; 
}

/***************************************************************************/
/***************************************************************************/
// Devuelve una copia de una línea del vector dinámico   
// PRE: 0 <= num_linea < UsadosVectorDinamico(v)

char * LineaVectorDinamicoCadenas (const VectorDinamicoCadenas & v, 
	                               const int num_linea)
{
	char * la_linea = nullptr; 

	if (num_linea >= 0 && num_linea < v.usados) {

		la_linea = new char [strlen(v.lineas[num_linea])+1];
		memcpy (la_linea, v.lineas[num_linea], strlen(v.lineas[num_linea])+1);

	}

	return la_linea; 
}

/***************************************************************************/
/***************************************************************************/
