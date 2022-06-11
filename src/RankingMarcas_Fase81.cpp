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
// Uso: RankingMarcas_Fase8 <fich_marcas_entrada> [<fich_marcas_salida>]  
// 
// Lee el fichero de marcas <fich_marcas_entrada>, ordena las marcas por 
// prueba (ordenación creciente por tiempo) y muestra el resultado de 
// la ordenación.  
// Si se indica un nombre del fichero de marcas <fich_marcas_salida> para 
// el resultado, se guardan las marcas ordenadas en ese fichero.
//
// FASE 8
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

	if (argc < 2 || argc > 3) {
		cerr << endl;
		cerr << "Error: Número incorrecto de argumentos." << endl; 
		cerr << "Uso: " << argv[0] << " <fich_marcas_entrada> "
			 << "[<fich_marcas_salida>]" << endl;
		cerr << endl;
		exit (1);
	} 

	string fuente  = argv[1];
	string destino;

	if (!ExisteFichero(fuente)) {
		cerr << endl;
		cerr << "Error: El fichero "<< fuente << " no existe o "; 
		cerr << "los permisos no son correctos." << endl;
		cerr << endl;
		exit (2);	
	}

	cerr << endl; 
	cerr << "Las marcas se leen del fichero: " << fuente << endl; 

	if (argc==3)  {
		destino = argv[2];
		cerr << "Las marcas se guardan en el fichero: " << destino << endl; 	
	}
	cerr << endl; 

	// LECTURA
	// Crear la matriz de marcas tomando los datos de un fichero

	MatrizMarcas marcas (fuente);

	// MOSTRAR RESULTADO

	cout << endl;

	if (marcas.EstaVacia()) cout << "Matriz vacia." << endl; 

	else {
	
		// Mostrar contenido de "marcas" a través de ToString()
		cout << marcas.ToString ("Marcas leidas") << endl;

		// Ordenar y mostar el resultado
		marcas.Ordena (1, marcas.NumFilas());
		
		cout << marcas.ToString ("Ranking - marcas ordenadas") << endl;

		if (argc==3)  // Guardar una copia después de ordenar
		
			marcas.EscribirMatrizMarcas (destino);
	}

	cout << endl; 

	//.......................................................................

	return 0;
}

/***************************************************************************/