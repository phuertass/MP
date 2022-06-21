/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
//
// Programa que muestra información sobre una imagen guardada en un 
// fichero PGM. La información se extrae de la cabecera del fichero.
//
// Uso: InfoPGM <Imagen_PGM>
//
// Fichero: InfoPGM.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


bool ExisteFichero (const string & nombre);


int main (int argc, char **argv)
{

	// Control de errores

	if (argc != 2) {
		cerr << "Error: Numero de argumentos incorrecto" << endl;
		cerr << "Formato: " << argv[0] << " <Imagen_PGM>" << endl;
		exit (1);
	}

	if (!ExisteFichero(argv[1])) {
		cerr << "Error: No pudo abrirse " << argv[1] << endl;
		exit (2);
	}

	// Abrir el fichero para lectura

	ifstream f(argv[1]);  


	const int TAM = 256;
	char cad [TAM];
	

	f.getline (cad, TAM); 

	if (strcmp("P5", cad)) {
		cerr << "Error: " << argv[1] << " NO es un fichero PGM." << endl;
		exit (3);
	}

	cout<< endl;
	cout<< "Fichero PGM = " << argv[1] << endl;


	// Lectura de comentarios

	cout<< endl;
	cout<< "Comentarios:" << endl;

	f.getline (cad, TAM);
	
	while (cad[0]=='#') {

		cout << "\t" << cad << endl;

		f.getline (cad, TAM);
	}



	istringstream is;
	is.str (cad); 
	
	int columnas, filas;
	
	is >> columnas >> filas;

	cout << endl;
	cout << "Dimensiones: " << filas << " filas x " 
		 << columnas << " columnas." << endl;
	cout << endl;


	// Leer el maximo valor

	f.getline (cad, TAM);

	int m = atoi(cad); 

	cout << "Max. valor = " << m << endl;
	cout << endl;


	f.close ();

	return 0;
}


bool ExisteFichero (const string & nombre)
{

	ifstream fichero;

	fichero.open (nombre);

	bool problema = fichero.fail();
	if (!problema) fichero.close();

	return ((problema) ? false : true);
}

