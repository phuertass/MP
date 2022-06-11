/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Proyecto. Fase 7. 
// OPERADORES ARITMETICOS Y COMBINADOS 
// 
// Incluye: 
//	* Constructor de copia (y otros constructores)
//	* Destructor
//	* Operador de asignación
//	* Operadores de acceso () y []
//  * Operadores binarios + y -
//  * Operadores combinados += y -=
//  * NOVEDAD: operadores << y >>
//
// Fichero: Prueba_VectorMarcas_Fase7.cpp
//
// FASE 7
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "Fecha.h"
#include "Tiempo.h"
#include "RegistroDeMarca.h"

#include "VectorMarcas.h"

using namespace std;
	
/***************************************************************************/
/***************************************************************************/

int main()
{
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	VectorMarcas v; 

	cin >> v; 	// Operador >> de "VectorMarcas"

	cout << v;  // Operador << de "VectorMarcas"

	return 0;
}

/***************************************************************************/
/***************************************************************************/
