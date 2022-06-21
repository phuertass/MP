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

int main (void)
{

	Lista lista(5, 5);

	Lista sub (lista.SubLista(1,5) );

	cout<<lista.ToString("lista original")<<endl;
	cout<<sub.ToString("sublista")<<endl;

	cout << "----------------------------------------------------------"<<endl;
	cout << "Prueba de operadores relacionales"<<endl;

	Lista a(10);
	for(int i=0; i<10; i++)
		a[i] = i;
	Lista b(10);
	for(int i=0; i<10; i++)
		b[i] = i*10;

	Lista c(3);
	for(int i=0; i<3; i++)
		c[i] = i;
	
	Lista d(1);
	d[0] = 10;

	cout<<a.ToString("Lista a")<<endl;
	cout<<b.ToString("Lista b")<<endl;
	cout<<c.ToString("Lista c")<<endl;
	cout<<d.ToString("Lista d")<<endl;

	cout << "a < b " 
	     << (a<b ? "SI": "NO") << endl;	
	cout << endl;

	cout << "c < d " 
		 << (c<d ? "SI": "NO") << endl;
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

	cout << "Prueba de operador binario +"<<endl;
	Lista m1 = a + b;
	cout<<m1.ToString("a+b")<<endl;

	cout << "Prueba de operador binario +"<<endl;
	TipoBaseLista x = 3;
	m1 = x + a + x;
	cout<<m1.ToString("x+a+x")<<endl;

	cout << "Prueba de operador binario -"<<endl;
	cout<<a.ToString("a")<<endl;
	cout<<c.ToString("c")<<endl;
	m1 = a - c;
	cout<<m1.ToString("a-c")<<endl;

	cout << "Prueba de operador binario -"<<endl;
	m1 = a - x;
	cout<<m1.ToString("a-x")<<endl;

	cout << "Prueba de operador unario +="<<endl;
	m1 += x;
	cout<<m1.ToString("m1+=x")<<endl;

	cout << "Prueba de operador unario -="<<endl;
	m1 -= x;
	cout<<m1.ToString("m1-=x")<<endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/
