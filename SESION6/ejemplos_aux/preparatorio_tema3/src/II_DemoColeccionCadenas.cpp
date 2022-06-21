/***************************************************************************/
// METODOLOG�A DE LA PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//
// Fichero: II_DemoColeccionCadenas.cpp
//
/*	
	Programa que lee una secuencia indeterminada de cadenas de caracteres 
	(termina al encontrar en la lectura el fin de fichero) y las guarda en 
	memoria (incluidas las l�neas vac�as) en un array de caracteres, 
	una cadena tras otra, consecutivamente. Se guardan los terminadores '\0'.

	Cada vez que se lee una nueva cadena, se a�ade a la estructura din�mica 
	(redimensi�n b�sica, se reserva el espacio m�nimo preciso, se pide memoria 
	para los caracteres ya guardados m�s los de la cadena nueva), que se 
	guarda a continuaci�n de que ocupaba la �ltima posici�n.

	El programa mostrar� el n�mero total de l�neas, l�neas no vac�as y 
	p�rrafos. Finalmente calcular� cual es la cadena m�s larga entre todas 
	las guardadas.
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "Funcs_ColeccionCadenas.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main()
{
	//.......................................................................
	// En "v" se guardar�n las cadenas leidas. 

	ColeccionCadenas v = CreaColeccionCadenas ();


	//.......................................................................
	// Rellenar "v": se termina al encontrar EOF en cin 

	string cadena; // Para leer cada una de las cadenas 

	while (getline (cin, cadena)) {

		
		// Reservar memoria para la cadena cl�sica. 
		// Se necesita un car�cter m�s que la longitud de "cadena". 
		// La longitud de "cadena" se calcula con el m�todo "length" de string

		int long_cadena = cadena.length();
		char * cadena_nueva = new char [long_cadena+1];


		// VERSI�N 1 (nivel: principiante)
		/*
			1) Copiar car�cter a car�cter desde el string a la cadena cl�sica
			2) A�adir el '\0'
		*/

		// 1. Copiar car�cter a car�cter desde el string a la cadena cl�sica
		for (int pos=0; pos<long_cadena; pos++) 
			cadena_nueva[pos] = cadena.at(pos);	

		// 2. A�adir el '\0'
		cadena_nueva[long_cadena] = '\0';


		// VERSI�N 2 (nivel: experto)
		/*
			Usar el m�todo c_str() de la clase string para obtener una 
			cadena cl�sica desde un dato string (por supuesto con el '\0')

			Por ejemplo, la l�nea 
				cout << "|" << cadena.c_str() << "|" << endl; 
			env�a a cout el resultado de la conversi�n (entre barras)
		
			En este problema bastar�a con escribir la instrucci�n: 

			strcpy(cadena_nueva, cadena.c_str());	
		*/

		// "cadena_nueva" nos lleva a una zona del Heap reservada e 
		// inicializada correctamente. Pasamos esa direcci�n a la funci�n 
		// "AniadeVectorDinamico" para que a�ada la nueva cadena a "v".

		AniadeCadenaColeccionCadenas (v, cadena_nueva); 

		MostrarColeccionCadenas (v);

		delete [] cadena_nueva;

	} // while


	//.......................................................................
	// Mostrar ocupaci�n y contenido de "v" 

	cout << endl;
	cout << "Casillas usadas = " << CadenasEnColeccionCadenas(v) << endl;  
	cout << endl; 

	//.......................................................................
	// Mostrar contenido de "v"

	MostrarColeccionCadenas (v); 

	//.......................................................................
	// C�lculos sobre "lineas"

	int n_lineas, n_vacias, n_parrafos;

	CalculosLineasColeccionCadenas (v, n_lineas, n_vacias, n_parrafos);

	//.......................................................................
	// Mostrar resultados

	cout << endl; 
	cout << "CALCULOS SOBRE LAS LINEAS LEIDAS" << endl; 
	cout << endl;

	cout << "Num. total lineas  = " << setw(3) << n_lineas << endl;
	cout << "Num. lineas vacias = " << setw(3) << n_vacias << endl;
	cout << "Num. parrafos      = " << setw(3) << n_parrafos << endl;
	cout << endl;

	//.......................................................................
	// Procesar el contenido de "v" (calcular la cadena m�s larga)

	int num_cadenas = CadenasEnColeccionCadenas(v);

	if (num_cadenas > 0) {

		cout << endl; 
		cout << "Calculando la mayor cadena de las " 
		     << setw(3) << num_cadenas << " guardadas" << endl; 
		cout << endl; 

		char * una_cadena; 

		// La primera cadena ser� la primera mayor

		ExtraeCadenaColeccionCadenas (una_cadena, v, 0);

		int pos_cadena_mayor = 0; 
		int long_cadena_mayor = strlen(una_cadena);

		delete [] una_cadena;


		// Procesar el resto de las cadenas

		for (int n=1; n<num_cadenas; n++) {

			ExtraeCadenaColeccionCadenas (una_cadena, v, n);

			int long_una_cadena = strlen(una_cadena);

			// Si procede, actualizar los datos de la cadena mayor

			if (long_una_cadena > long_cadena_mayor) {
				pos_cadena_mayor = n; 
				long_cadena_mayor = long_una_cadena;
			}

			delete [] una_cadena;			
		}

		// Nos quedamos con la mayor cadena (su posici�n es "pos_cadena_mayor")

		ExtraeCadenaColeccionCadenas (una_cadena, v, pos_cadena_mayor);

		cout << endl; 
		cout << "Posicion de la mayor cadena = " 
		     << setw(3) << pos_cadena_mayor << endl; 
		cout << "Contenido:  " << una_cadena << endl; 
		cout << "Longitud =  " << strlen(una_cadena) << endl; 
		cout << endl; 

		delete [] una_cadena;			
	}
	else {
		cout << endl; 
		cout << "No hay cadenas guardadas." << endl; 	
		cout << endl; 
	}

	//......................................................................
	// Liberar la memoria ocupada por "lineas"

	cout << endl;
	cout << "Liberando memoria .... " ;

	LiberaMemoriaColeccionCadenas (v); 

	cout << "Memoria liberada";
	cout << endl;

	//.......................................................................

	return 0;
}

/***************************************************************************/
/***************************************************************************/