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
// Fichero: RankingMarcas_Fase8.cpp
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

int main(int argc, char **argv)
{
	cout.setf(ios::fixed);	   // Notación de punto fijo para los reales
	cout.setf(ios::showpoint); // Mostrar siempre decimales

	//.......................................................................
	// Procesar línea de órdenes

	if (argc != 2)
	{
		cerr << endl;
		cerr << "Error: Número incorrecto de argumentos." << endl;
		cerr << "Uso: " << argv[0] << " <fichero_marcas>" << endl;
		cerr << endl;
		exit(1);
	}

	if (!ExisteFichero(argv[1]))
	{
		cerr << endl;
		cerr << "Error: El fichero " << argv[1] << " no existe o ";
		cerr << "los permisos no son correctos." << endl;
		cerr << endl;
		exit(2);
	}

	//.......................................................................
	// LECTURA

	// Crear la matriz de marcas tomando los datos de un fichero


	MatrizMarcas marcas(argv[1]);

	cout << "Matriz de marcas creada a partir del fichero " << argv[1] << endl;

	cout << "<< Matriz marcas : "<< endl << endl << marcas << endl;

	//return 0;

	//.......................................................................
	// MOSTRAR RESULTADO

	// Mostrar contenido de "marcas" directamente

	cout << endl;

	if (marcas.EstaVacia())

		cout << "Matriz vacia." << endl;

	else
	{
		// Prueba del operador <<

		cout << marcas;

		// Mostrar contenido de "marcas" a través de ToString()

		cout << "Marcas leidas - Ranking general 2021\n" << marcas << endl;

		// Guardar una copia antes de ordenar


		marcas.EscribirMatrizMarcas("copia_sin_ordenar.txt");

		// Leer desde el fichero recién creado

		cout << "----------------------------------------" << endl;

		marcas.LeerMatrizMarcas("copia_sin_ordenar.txt");

		cout << "MARCAS LEIDAS COPIA SIN ORDENAR\n" << marcas << endl;



		cout << "----------------------------------------" << endl;

		//.......................................................................
		// ORDENAR Y MOSTRAR RESULTADO

		marcas.OrdenarPorTiempos();

		// Mostrar contenido de "marcas"

		cout << ("Ranking general 2021 ordenado\n") << marcas << endl;

		// Guardar una copia después de ordenar


		marcas.EscribirMatrizMarcas("copia_tras_ordenar.txt");

		//.......................................................................
		// MAS PRUEBAS

		MatrizMarcas otras_marcas;
				


		otras_marcas.LeerMatrizMarcas("copia_sin_ordenar.txt");
		

		// Mostrar contenido de "marcas" a través de ToString()

		cout << ("Copia sin ordenar leida\n") << otras_marcas << endl;

	}

	cout << endl;

	//.......................................................................

	return 0;
}

/***************************************************************************/
/***************************************************************************/
