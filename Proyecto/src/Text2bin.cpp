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
// serie de grupos de valores reales para transformar de texto a binario.
//
// Los ficheros (de texto) contienen un número indeterminado de líneas, 
// cada una de ellas con los datos correspondientes a una serie de grupos 
// de valores reales.
//
//		Por ejemplo, una línea podría ser la siguiente:
//			3 2 3.1 0.4 5 1.0 1.0 1.0 1.0 1.0 2 5.2 4.7
//		donde puede distinguir tres grupos de datos (indicado por el
//		primer número de la línea) y cada grupo empieza por un valor 
//		entero (2, 5 y 2) seguido por tantos valores reales como indique 
//		el valor entero que encabeza cada grupo:
//			3 grupos
//			grupo 1, 2 datos: 3.1 y 0.4
//			grupo 2, 5 datos: 1.0, 1.0, 1.0, 1.0 y 1.0
//			grupo 3, 2 datos: 5.2 y 4.7
//
// Uso: Text2bin  <FichText> <FichBin>
//			<FichText>	Es el fichero de entrada, que contiene los datos 
//						en formato texto.
//			<FichBin>	Es el fichero de salida, que contiene los datos 
//						en formato binario.
//
// Fichero: Text2bin.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

/***************************************************************************/
/***************************************************************************/

void Text2Bin (ifstream & fi, ofstream & fo); 

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{
	
	// Comprobar numero de argumentos  

	if (argc !=3) {
		cerr << "Error: Numero de argumentos incorrecto." << endl;
		cerr << "Formato: " << argv[0] << "<fich1> <fich2>" << endl;
		cerr << "   <fich1> es un fich. (texto) con datos de entrada" << endl;
		cerr << "   <fich2> es un fich. binario, resultado de ";
		cerr << "transformar <fich1>" << endl;
		exit (1);
	}
	
	// Asociar flujos a ficheros 

	// fi --> fluo de entrada, texto
	ifstream fi; 
	fi.open (argv[1]);
	if (!fi) {
		cerr << "Error: No pudo abrirse " << argv[1] << endl;
		exit (2);
	}

	// fo --> fluo de salida, binario
	ofstream fo; 
	fo.open (argv[2], ios::binary);
	if (!fo) {
		cerr << "Error: No pudo crearse " << argv[2] << endl;
		exit (3);
	}

	// Conversion texto -> binario
	
	Text2Bin (fi, fo); 

	// Desasociar flujos

	fi.close();
	fo.close();

	return (0);
}

/***************************************************************************/
/***************************************************************************/

void Text2Bin (ifstream & fi, ofstream & fo)
{
	int num_bloques;
	int num_elems_en_bloque;
	double valor; 

	while (fi >> num_bloques) {	// Intenta leer el primer campo

		// Graba el num. de bloques de la linea actual
		fo.write ((const char *) &num_bloques, sizeof(int));

		for (int bloque=0; bloque < num_bloques; bloque++) {

			fi >> num_elems_en_bloque;

			// Graba el num. de elementos del bloque actual
			fo.write ((const char *) &num_elems_en_bloque, sizeof(int));

			for (int elem=0; elem<num_elems_en_bloque; elem++) {

				fi >> valor; 

				// Graba cada uno de los elementos
				fo.write ((const char *) &valor, sizeof(double));

			} // for elem

		} // for bloque
	
	} // while 

}

/***************************************************************************/
/***************************************************************************/
