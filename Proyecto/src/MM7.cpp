/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Proyecto. Fase 7. 
// OPERADORES DE FLUJO 
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
// Fichero: Prueba_MatrizMarcas_Fase7.cpp
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
#include "MatrizMarcas.h"

using namespace std;
	
/***************************************************************************/
/***************************************************************************/

int main()
{

	MatrizMarcas m; 

	cin >> m; 	// Operador >> de "MatrizMarcas"

	cout << m; 	// Operador << de "MatrizMarcas"

	return 0;
}

/***************************************************************************/
/***************************************************************************/
