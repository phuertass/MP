/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
//
// Programa que lee una serie indefinida de n�meros enteros de la entrada
// est�ndar y los copia, en el mismo orden, en la salida est�ndar.
//	 *	En la secuencia de entrada se pueden usar espacios, tabuladores o
//		saltos de l�neas (en cualquier n�mero y combinaci�n) para separar
//		dos n�meros enteros consecutivos.
//	 *	En la secuencia de salida se separan dos enteros consecutivos con
//		un salto de l�nea.
//
// Fichero: CopiaEnteros.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	int n;

	while (cin >> n)  
		cout << setw(10) << n << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/
