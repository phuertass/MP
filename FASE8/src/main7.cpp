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
// Fichero: RankingMarcas_Fase7.cpp
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
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	//.......................................................................
	// LECTURA

	// Crear la matriz de marcas. Tras crearse, todas las filas están vacías.  

	MatrizMarcas marcas; 

	// Leer el contenido de "marcas" desde cin

	cin >> marcas; 


	//.......................................................................
	// MOSTRAR RESULTADO

	// Mostrar contenido de "marcas" 

	cout << marcas << endl;

	//.......................................................................

	return 0;
}

/***************************************************************************/
/***************************************************************************/
