/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Programa de prueba de las funciones de la clase Lista
//
// Fichero: III_Demo-Lista.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "TipoBase_Lista.h"
#include "Lista.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{

	Lista lista(5, 5);

	Lista sub (lista.SubLista(1,5) );

	cout<<lista.ToString("lista original")<<endl;
	cout<<sub.ToString("sublista")<<endl;

	cout << "Iguales lista y sub == " 
	     << (lista==sub ? "SI": "NO") << endl;	
	cout << endl;

	cout << "Distintos lista y sub != " 
	     << (lista!=sub ? "SI": "NO") << endl;	
	cout << endl;

	cout<<"Modifico un valor de sublista"<<endl;
	sub[2] = 11;

	cout << "Iguales lista y sub == " 
	     << (lista==sub ? "SI": "NO") << endl;	
	cout << endl;

	cout << "Distintos lista y sub != " 
	     << (lista!=sub ? "SI": "NO") << endl;	
	cout << endl;

	cout << "Prueba de operador asignacion, lista=2"<<endl;
	lista = 2;
	cout<<lista.ToString("Lista")<<endl;

	cout << "Operador de asignacion sub = lista"<<endl;
	sub = lista;
	cout<<sub.ToString("sublista")<<endl;

	cout << "Prueba del operador [] como lvalue y ravlue"<<endl;
	cout << "Lista[1]=11"<<endl;
	cout << "int x = Lista[1]"<<endl;
	lista[1] = 11;
	TipoBaseLista x = lista[1];
	cout<<lista.ToString("lista original")<<endl;

	cout << "----------------------------------------------------------"<<endl;
	cout << "Prueba de operadores relacionales"<<endl;

	Lista a(10);
	for(int i=0; i<10; i++)
		a[i] = i;
	Lista b(10);
	for(int i=0; i<10; i++)
		b[i] = i*10;

	cout<<a.ToString("Lista a")<<endl;
	cout<<b.ToString("Lista b")<<endl;

	cout << "a < b " 
	     << (a<b ? "SI": "NO") << endl;	
	cout << endl;

	cout << "a >= b " 
	     << (a>b ? "SI": "NO") << endl;	
	cout << endl;

	cout << "b > a " 
	     << (b>a ? "SI": "NO") << endl;	
	cout << endl;

	cout << "b <= a " 
	     << (b<=a ? "SI": "NO") << endl;	
	cout << endl;

	cout << "b >= a " 
	     << (b>=a ? "SI": "NO") << endl;	
	cout << endl;

	cout << "a == b " 
	     << (a==b ? "SI": "NO") << endl;
	cout << endl;

	cout << "a != b " 
	     << (a!=b ? "SI": "NO") << endl;
	cout << endl;

	cout << "Igualando a b..."<<endl;
	a=b;
	cout << endl;

	cout << "a == b " 
	     << (a==b ? "SI": "NO") << endl;
	cout << endl;

	cout << "a != b " 
	     << (a!=b ? "SI": "NO") << endl;
	cout << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/
