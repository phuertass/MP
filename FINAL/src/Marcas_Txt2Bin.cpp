/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Proyecto. Fase 9. 
//
// Fichero: Marcas_Txt2Bin.cpp
//
// Uso: Marcas_Txt2Bin <fichero_txt> <fichero_bin> 
// 
// Convierte el fichero de marcas <fichero_txt> (datos en forma de texto)   
// en el fichero de marcas <fichero_bin> (datos en binario). 
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

	if (argc != 3) {
		cerr << endl;
		cerr << "Error: Número incorrecto de argumentos." << endl; 
		cerr << "Uso: " << argv[0] << " <fichero_txt> <fichero_bin> " << endl;
		cerr << endl;
		exit (1);
	} 

	string fuente  = argv[1];
	string destino = argv[2];

	if (!ExisteFichero(fuente)) {
		cerr << endl;
		cerr << "Error: El fichero "<< fuente << " no existe o "; 
		cerr << "los permisos no son correctos." << endl;
		cerr << endl;
		exit (2);	
	}


	cerr << endl; 
	cerr << "Las marcas se leen del fichero: " << fuente << endl; 
	cerr << "Las marcas se escriben en el fichero: " << destino << endl; 
	cerr << endl; 

	//.......................................................................
	// LECTURA

	// Crear la matriz de marcas 

	MatrizMarcas marcas;


	// Leer los datos de un fichero de texto

	marcas.LeerMatrizMarcasTxt (fuente);


	//.......................................................................
	// MOSTRAR RESULTADO

	cout << endl;

	if (marcas.EstaVacia()) 

		cout << "Matriz vacia." << endl; 

	else {

		cout << "Marcas leidas." << endl; 
		cout << marcas << endl;

	}
	
	cout << endl; 

	//.......................................................................

	cout << endl; 
	cout << "Guardando marcas (binario) en " << destino << " ...";

	marcas.EscribirMatrizMarcasBin (destino);

	cout << "... guardadas." << endl; 
	cout << endl; 

	//.......................................................................

	return 0;
}

/***************************************************************************/