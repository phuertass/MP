/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Programa de prueba de las funciones de la clase Lista
//
// Fichero: IV_Demo-Lista.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "TipoBase_Lista.h"
#include "Lista.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main(void)
{
	Lista leida("/home/phuertas/UNIVERSIDAD/MP/SESION13/ficheros/datos_de_lista.txt");
	cout << leida << endl;

	leida.EscribirLista("/home/phuertas/UNIVERSIDAD/MP/SESION13/ficheros/datos_de_lista_escritura.txt");

	Lista l2;
	for (int i = 0; i < 10; i++){
		TipoBaseLista tb= TipoBaseLista(i);
		l2+= tb;
	}
	cout << l2 << endl;

	l2.LeerLista("/home/phuertas/UNIVERSIDAD/MP/SESION13/ficheros/datos_de_lista.txt");
	cout << l2 << endl;



	return 0;
}

/***************************************************************************/
/***************************************************************************/
