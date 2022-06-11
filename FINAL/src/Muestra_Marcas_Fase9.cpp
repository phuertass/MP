/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Proyecto. Fase 9. 
//
// Fichero: Muestra_Marcas_Fase9.cpp
//
// Uso: Muestra_Marcas_Fase9 <fich_marcas>  
// 
// Muestra la información guardada en el fichero de marcas <fich_marcas> 
//
// IMPORTANTE: El fichero <fich_marcas> puede ser de texto o binario. 
//
// FASE 9
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "UtilsMarcas.h"
#include "MatrizMarcas.h"

using namespace std;
	
/***************************************************************************/

int main (int argc, char ** argv)
{
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	//.......................................................................
	// Procesar línea de órdenes

	if (argc != 2) {
		cerr << endl;
		cerr << "Error: Número incorrecto de argumentos." << endl; 
		cerr << "Uso: " << argv[0] << " <fichero_marcas>" << endl;
		cerr << endl;
		exit (1);
	}

	if (!ExisteFichero(argv[1])) {
		cerr << endl;
		cerr << "Error: El fichero "<< argv[1] << " no existe o "; 
		cerr << "los permisos no son correctos." << endl;
		cerr << endl;
		exit (2);	
	}

	cerr << endl; 
	cerr << "Las marcas se leen del fichero: " << argv[1] << endl; 
	cerr << endl; 

	//.......................................................................

	// Crear la matriz de marcas 
	MatrizMarcas marcas;

	// Leer los datos de un fichero de marcas
	marcas.LeerMatrizMarcas (argv[1], true);
	
	//MatrizMarcas m(argv[1]);
	//cout << "Matriz de marcas leida del fichero " << m << endl;
	
	cout << endl;

	if (marcas.EstaVacia()) 

		cout << "Matriz vacia." << endl; 

	else {
		cout << "Marcas leidas." << endl; 
		cout << marcas << endl;
	}
	
	cout << endl; 
	
	//.......................................................................

	return 0;
}

/***************************************************************************/