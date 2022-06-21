/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Programa que lee una cadena y localiza la posici�n del primer car�cter 
// espacio ' ') en una cadena de caracteres "cl�sica".
// Se indica su posici�n (0: primer car�cter, 1:segundo car�cter, etc.).
// 
// Fichero: I_PosicionPrimerBlanco.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
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
	
	while ((*p != ' ') && (*p != '\0')) p++;
	// Alternativa: 	while ((*p != ' ') && (*p)) p++;

	cout << "Posicion del primer blanco = "; 
	if (*p != '\0') // Alternativa:    if (*p)
		cout << p-cad;
	else 
		cout << "NO HAY ESPACIOS";

	cout << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/
