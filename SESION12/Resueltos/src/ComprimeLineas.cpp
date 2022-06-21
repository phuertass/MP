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
// Procesamiento a nivel de CARACTER 
//
// Fichero: ComprimeLineas.cpp
//
/***************************************************************************/

#include <iostream>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	char c;

	c = cin.get();	// lectura adelantada

	while (!cin.eof()) {

		// Si el car�cter no es un separador, escribirlo. 
		// Excepci�n: el car�cter '\n' tambi�n se escribe

		if (c!=' ' && c!='\t' && c!='\v' && c!='\f' && c!='\r') 
			cout << c;					
				
		c = cin.get();	// lectura adelantada

	} // while (!cin.eof()) 

	return (0);
}

/***************************************************************************/
/***************************************************************************/
