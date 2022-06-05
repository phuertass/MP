/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Proyecto. Fase 9.
//
// Incluye:
//	* Constructor de copia (y otros constructores)
//	* Destructor
//	* Operador de asignación
//	* Operadores de acceso () y []
//  * Operadores binarios + y -
//  * Operadores combinados += y -=
//  * Operadores << y >>
//	* Constructor desde fichero y métodos de E/S
//	* NOVEDAD: Gestión de flujos binarios.
//
// Fichero: RankingMarcas_Fase9.cpp
//
// Uso: RankingMarcas_Fase9 <fich_marcas_entrada> [<fich_marcas_salida>]
//
// Lee el fichero de marcas <fich_marcas_entrada>, ordena las marcas por
// prueba (ordenación creciente por tiempo) y muestra el resultado de
// la ordenación.
// Si se indica un nombre del fichero de marcas <fich_marcas_salida> para
// el resultado, se guardan las marcas ordenadas en ese fichero.
//
// IMPORTANTE:
//	1) El fichero <fich_marcas_entrada> puede ser de texto o binario.
//  2) Los formatos de <fich_marcas_entrada> y <fich_marcas_salida> son iguales
//
// FASE 9
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

int main(int argc, char **argv)
{
	cout.setf(ios::fixed);	   // Notación de punto fijo para los reales
	cout.setf(ios::showpoint); // Mostrar siempre decimales

	//.......................................................................
	// Procesar línea de órdenes

	if (argc < 2 || argc > 3)
	{
		cerr << endl;
		cerr << "Error: Número incorrecto de argumentos." << endl;
		cerr << "Uso: " << argv[0] << " <fich_marcas_entrada> "
			 << "[<fich_marcas_salida>]" << endl;
		cerr << endl;
		exit(1);
	}

	string fuente = argv[1];
	string destino;

	if (!ExisteFichero(fuente))
	{
		cerr << endl;
		cerr << "Error: El fichero " << fuente << " no existe o ";
		cerr << "los permisos no son correctos." << endl;
		cerr << endl;
		exit(2);
	}

	cerr << endl;
	cerr << "Las marcas se leen del fichero: " << fuente << endl;

	if (argc == 3)
	{
		destino = argv[2];
		cerr << "Las marcas se guardan en el fichero: " << destino << endl;
	}
	cerr << endl;

	ifstream fi;
	fi.open(fuente);
	MatrizMarcas marcastotal;
	VectorMarcas v2;
	while (!fi.eof())
	{
		string linea;
		getline(fi, linea);
		cout << linea << endl;

		// LECTURA
		// Crear la matriz de marcas tomando los datos de un fichero
		if (ExisteFichero(linea))
		{
			MatrizMarcas marcas(linea);

			marcastotal = marcas + marcastotal;

			// MOSTRAR RESULTADO
			if (marcas.EstaVacia())
				cout << "Matriz vacia." << endl;
		}
	}
	fi.close();

	marcastotal.OrdenarPorTiempos();
	cout << marcastotal << endl;
	
	// Si se ha indicado un fichero de destino, se guardan las marcas
	// ordenadas en ese fichero en forma texto
	if (argc == 3)
	{ // Guardar una copia después de ordenar
		cout << fuente << " -> " << destino << endl;

		marcastotal.EscribirMatrizMarcas (destino, true);  // texto

	}

	return 0;
}

/***************************************************************************/