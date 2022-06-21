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

	Lista lista(5, 5);

	Lista sub(lista.SubLista(1, 3));

	cout << lista.ToString("lista original") << endl;
	cout << sub.ToString("sublista") << endl;

	cout << "Prueba de operador >>" << endl;
	Lista l;
	TipoBaseLista a = TipoBaseLista(1);
	TipoBaseLista b = TipoBaseLista(2);
	TipoBaseLista c = TipoBaseLista(3);
	TipoBaseLista d = TipoBaseLista(4);
	cin >> l;

	cout << "----------------------------------------------------------" << endl;
	cout << "Prueba de operador <<" << endl;

	cout << l << endl;
	cout << "----------------------------------------------------------" << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/
