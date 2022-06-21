/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Proyecto. Fase 8.
//
// Incluye:
//	* Constructor de copia (y otros constructores)
//	* Destructor
//	* Operador de asignación
//	* Operadores de acceso () y []
//  * Operadores binarios + y -
//  * Operadores combinados += y -=
//  * Operadores << y >>
//	* NOVEDAD: Constructor desde fichero y métodos de E/S
//
// Fichero: Prueba_MatrizMarcas_Fase8.cpp
//
// FASE 8
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "utils.h"

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
	cout.setf(ios::fixed);	   // Notación de punto fijo para los reales
	cout.setf(ios::showpoint); // Mostrar siempre decimales

	// Crear la matriz de marcas tomando los datos de un fichero

	MatrizMarcas marcas("todas_marcas_nacional_2021.txt");

	cerr << endl;
	cerr << "marcas tras marcas (\"todas_marcas_nacional_2021.txt\")" << endl;
	cerr << marcas << endl;
	cerr << endl;

	// Ordenar y guatrdar copia ordenada

	marcas.OrdenarPorTiempos();

	cerr << endl;
	cerr << "marcas tras marcas.Ordena (1, marcas.NumFilas())" << endl;
	cerr << marcas << endl;
	cerr << endl;

	marcas.EscribirMatrizMarcas("todas_marcas_nacional_2021_ordenado.txt");

	// Descartar el contenido actual.

	marcas.EliminaTodos();

	cerr << endl;
	cerr << "marcas tras marcas.EliminaTodos())" << endl;
	cerr << marcas << endl;
	cerr << endl;

	// Cargar su nuevo contenido desde un fichero

	marcas.LeerMatrizMarcas("todas_marcas_nacional_2021.txt");

	cerr << endl;
	cerr << "marcas tras marcas.LeerMatrizMarcas "
		 << "(\"todas_marcas_nacional_2021.txt\")" << endl;
	cerr << marcas << endl;
	cerr << endl;

	cerr << endl;
	cerr << "-------------------------------------------------------" << endl;
	cerr << endl;


	// Cargar su nuevo contenido desde un fichero de una prueba

	string nombre_in = "marcas_prueba_100ML_2021.txt";
	string nombre_out = "out_" + nombre_in;

	// Leer contenido desde un fichero de marcas

	cerr << endl;
	cerr << "Leyendo marcas del fichero: " << nombre_in << endl;
	cerr << endl;

	marcas.LeerMatrizMarcas(nombre_in);


	cerr << endl;
	cerr << "marcas tras marcas.LeerMatrizMarcas (" << nombre_in << ")" << endl;
	cerr << marcas << endl;
	cerr << endl;

	// Guardar contenido en un fichero de marcas

	cerr << endl;
	cerr << "Guardando marcas en fichero: " << nombre_out << endl;
	cerr << endl;

	marcas.EscribirMatrizMarcas(nombre_out);


	if (!ExisteFichero(nombre_out))

		cerr << "\tError: No se pudo crear " << nombre_out << endl;

	else
	{

		cerr << endl;
		cerr << "Se ha guardado en " << nombre_out << endl;
		cerr << endl;
	}


	// Leer contenido desde un fichero de marcas

	cerr << endl;
	cerr << "Leyendo marcas del fichero: " << nombre_out << endl;
	cerr << endl;

	if (!ExisteFichero(nombre_out))
	{

		cerr << "\tError en fichero " << nombre_out << ": ";
		cerr << "No existe o no tiene permiso." << endl;
	}
	else
	{

		marcas.LeerMatrizMarcas(nombre_out);
	}


	cerr << endl;
	cerr << "marcas tras marcas.LeerMatrizMarcas(" << nombre_out << ")" << endl;
	cerr << marcas << endl;
	cerr << endl;

	cerr << endl;
	cerr << "-------------------------------------------------------" << endl;
	cerr << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/
