/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
//
// Programa que lee un fichero de texto con n�meros enteros separados 
// por separadores (espacios, tabuladores y saltos de l�nea) y muestra en la 
// salida est�ndar la suma de todos esos n�meros.
//
// Fichero: SumaEnteros.cpp
//
/***************************************************************************/

#include <iostream>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	int n;
	int cont=0, sum=0;

	while (cin >> n) { 
		sum += n;
		cont++;
	}

	cout << "\n\nLa suma total de los " << cont;
	cout << " enteros procesados es " << sum << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/
