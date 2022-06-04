/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
// 
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 7
//
// Programa que transforma ficheros con datos correspondientes a una 
// serie de grupos de valores reales para transformar de binario a texto.
//
// Los ficheros (binarios) est�n compuestos por un n�mero indeterminado
// de bloques de datos y cada uno de ellos est� formado por los datos
// correspondientes a una serie de grupos de valores reales.
//
//		Por ejemplo, un bloque podr�a ser el siguiente:
//			3 2 3.1 0.4 5 1.0 1.0 1.0 1.0 1.0 2 5.2 4.7
//		donde puede distinguir tres grupos de datos (indicado por el
//		primer n�mero del bloque) y cada grupo empieza por un valor 
//		entero (2, 5 y 2) seguido por tantos valores reales como indique 
//		el valor entero que encabeza cada grupo:
//			3 grupos
//			grupo 1, 2 datos: 3.1 y 0.4
//			grupo 2, 5 datos: 1.0, 1.0, 1.0, 1.0 y 1.0
//			grupo 3, 2 datos: 5.2 y 4.7
//
// Uso: Bin2text <FichBin> <FichText>
//			<FichBin>	Es el fichero de entrada, que contiene los datos 
//						en formato binario.
//			<FichText>	Es el fichero de salida, que contiene los datos 
//						en formato texto.
//
// Fichero: Bin2text.cpp
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

/***************************************************************************/
/***************************************************************************/

void Bin2Text (ifstream & fi, ofstream & fo); 

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{
	
	// Comprobar numero de argumentos  

	if (argc !=3) {
		cerr << "Error: Numero de argumentos incorrecto. " << endl;
		cerr << "Formato: " << argv[0] << "<fich1> <fich2>" << endl;
		cerr << "   <fich1> es un fich. (binario) con datos de entrada" << endl;
		cerr << "   <fich2> es un fich. (texto), resultado de ";
		cerr << "transformar <fich1>." << endl;
		exit (1);
	}
	
	// Asociar flujos a ficheros 

	// fo --> fluo de entrada, binario
	ifstream fi; 
	fi.open (argv[1], ios::binary);
	if (!fi) {
		cerr << "Error: No pudo abrirse " << argv[1] << endl;
		exit (2);
	}

	// fo --> fluo de salida, texto
	ofstream fo; 
	fo.open (argv[2]);
	if (!fo) {
		cerr << "Error: No pudo crearse " << argv[2] << endl;
		exit (3);
	}

	// Conversion binario -> texto

	Bin2Text (fi, fo); 
	
	// Desasociar flujos

	fi.close();
	fo.close();

	return (0);
}

/***************************************************************************/
/***************************************************************************/

void Bin2Text (ifstream & fi, ofstream & fo)
{
	fo.setf (ios::fixed);
	fo.setf (ios::showpoint);

	int num_bloques;

	// Lectura del num. de bloques de la primera linea 
	fi.read (reinterpret_cast <char *> (&num_bloques), sizeof(int)); 

	while (!(fi.eof())) {

		// Escritura del num. de bloques
		fo << setw (8) << num_bloques; 


		for (int bloque=0; bloque < num_bloques; bloque++) {

			int num_elems_en_bloque;

			// Lectura/Escritura del num. de elementos de cada bloque
			fi.read (reinterpret_cast <char *> (&num_elems_en_bloque), 
					 sizeof(int));
			fo << setw (8) << num_elems_en_bloque; 

			for (int elem=0; elem < num_elems_en_bloque; elem++) {

				double valor; 

				// Lectura/Escritura de cada uno de los elementos 
				fi.read (reinterpret_cast <char *> (&valor), 
					     sizeof(double));
				fo << setw (8) << setprecision(2) << valor; 

			} // for elem

		} // for bloque

		fo << endl;

		// Lectura del num. de bloques de la siguiente linea 
		fi.read (reinterpret_cast <char *> (&num_bloques), sizeof(int));

	} // while (!(fi.eof()))
}

/***************************************************************************/
/***************************************************************************/
