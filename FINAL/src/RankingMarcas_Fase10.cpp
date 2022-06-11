/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Proyecto Gestion de marcas de atletismo
//
// Fichero: RankingMarcas_Fase10.cpp
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

	marcastotal.OrdenarPorTiempos(true, 0, marcastotal.NumFilas());
	//marcastotal.OrdenarPorNombre(false, 0, marcastotal.NumFilas());

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
