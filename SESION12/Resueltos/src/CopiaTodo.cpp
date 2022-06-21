/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
//
// Lee una secuencia indefinida de caracteres de la entrada est�ndar
// y los copia literalmente en la salida est�ndar.
//
// Procesamiento a nivel de CARACTER 
//
// Fichero: CopiaTodo.cpp
//
/***************************************************************************/
 
#include <iostream>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	char c;

	c = cin.get();	// Lectura adelantada

	// Comprobaci�n del f�n de fichero en el flujo de entrada. 
	// Debe realizarse despu�s de una lectura, de ah� que con este 
	// esquema sea neceario realizar la lectura adelantada.

	while (!cin.eof()) {

		cout.put (c);	// Procesamiento del car�cter le�do
	
		c = cin.get(); 	// Lectura adelantada
	}
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
