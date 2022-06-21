/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Programa sencillo que trabaja sobre una cadena de caracteres ``cl�sica''. 
// Lee  una cadena y la imprime salt�ndose la primera palabra y evitando 
// escribirla car�cter a car�cter.
// El programa tiene en cuenta que puede haber ninguna, una o m�s palabras.  
// Si hay m�s de una palabra, est�n separadas por caracteres separadores.
//
// Fichero: I_SaltaPrimeraPalabra.cpp
//
/***************************************************************************/
/***************************************************************************/
 
#include <iostream>
#include <cctype>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main(void)
{
	const int TOPE = 100; 
	char cad[TOPE];

	cout << "Introduzca una cadena: ";
	cin.getline(cad, TOPE);
	
	char * p = cad; // Apuntar al primer car�cter
	
	// Saltar los separadores iniciales --> inicio de una palabra
	while (isspace(*p) && (*p != '\0')) p++;
	
	if (*p) {
		
		// Buscar el siguiente separador --> saltar la primera palabra
		while (!isspace(*p) && (*p != '\0')) p++;
	
		// Saltar separadores --> inicio de la segunda palabra
		while (isspace(*p) && (*p != '\0')) p++;
	
		if (*p != '\0')  cout << p;
		else cout << "SOLO HAY UNA PALABRA";
	}
	
	else cout << "NO HAY PALABRAS";
	
	cout << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/