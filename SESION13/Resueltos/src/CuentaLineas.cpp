/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
// 
// Lee una secuencia indefinida de caracteres de la entrada est�ndar 
// y los copia en la salida est�ndar y muestra en la salida est�ndar 
// el n�mero de l�neas no vac�as que hay en esa secuencia.
// Nota: Se entiende que una l�nea es vac�a si contiene �nicamente el 
// car�cter '\n'
//
// Procesamiento a nivel de LINEA 
//
// Fichero: CuentaLineas.cpp
//
/***************************************************************************/

#include <iostream>
#include <string>

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	int contador_vacias = 0;
	int contador_no_vacias = 0;
	int contador_total = 0;

	string cad; 

	getline(cin, cad);	// Lectura adelantada de una cadena

	while (!cin.eof()) {

		contador_total++; 

		if (cad.length()>0) 
			contador_no_vacias ++; // L�nea NO vac�a
		else 
			contador_vacias++; // L�nea vac�a

		getline(cin, cad);	// Nueva lectura
	}

	cout << endl; 
	cout << "Lineas totales   = " << contador_total << endl; 
	cout << "Lineas vacias    = " << contador_vacias << endl; 
	cout << "Lineas no vacias = " << contador_no_vacias << endl; 
	cout << endl; 

	return 0;
}

/***************************************************************************/
/***************************************************************************/
