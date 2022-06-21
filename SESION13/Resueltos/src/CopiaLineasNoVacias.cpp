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
// est�ndar y muestra en la salida est�ndar �nicamente las l�neas no 
// vac�as que hay en esa secuencia.
//
// Procesamiento a nivel de LINEA 
//
// Fichero: CopiaLineasNoVacias.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	const int TAM = 256;	// M�xima longitud de la cadena empleada
	char cad[TAM];			// para leer cada l�nea

	cin.getline(cad, TAM);	// Lectura adelantada de una cadena

	while (!cin.eof()) {

		if (strlen(cad) > 0) {	// Si la longitud es mayor que cero, 
			cout << cad;	    // no est� vac�a: enviarla a cout
			cout << endl;  
		}
		
		cin.getline(cad, TAM);		// Nueva lectura
	}
   
	return (0);
}

/***************************************************************************/
/***************************************************************************/
