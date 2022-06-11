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
// Fichero: Prueba_VectorMarcas_Fase8.cpp
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

int main (int argc, char ** argv)
{
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	//.......................................................................
	// Procesar línea de órdenes

	if (argc < 2 || argc > 3) {
		cerr << endl;
		cerr << "Error. Número incorrecto de argumentos." << endl; 
		cerr << "Uso: " << argv[0] << " <fichero> [prueba]" << endl;
		cerr << endl;
		exit (1);
	} 

	string nombre_fich   = argv[1];
	
	if (!ExisteFichero(nombre_fich)) {
		cerr << endl;
		cerr << "Error. El fichero "<< nombre_fich << " no existe o "; 
		cerr << "los permisos no son correctos." << endl;
		cerr << endl;
	}

	string nombre_prueba;

	if (argc == 3) nombre_prueba = argv[2];


	//.......................................................................
	// LECTURA

	// Crear vector de marcas de una prueba

	VectorMarcas marcas_prueba;

	if (argc == 2) {

		cerr << endl;
		cerr << "Creando vector de marcas desde: " << nombre_fich << endl; 
		VectorMarcas vector (nombre_fich);
		cout << "Vector creado." << endl;
		cout << vector	<< endl;
		marcas_prueba = vector;
		cout << "Vector copiado." << endl;
	}
	else {

		cerr << endl;
		cerr << "Creando vector de marcas desde: " << nombre_fich << endl; 
		cerr << "Se toman las marcas de la prueba: " << nombre_prueba << endl; 

		VectorMarcas vector (nombre_fich, nombre_prueba);
		marcas_prueba = vector;
	}
	
	//.......................................................................
	// MOSTRAR RESULTADO

	// Mostrar contenido de "marcas_prueba" 

	if (marcas_prueba.EstaVacio()) {
		cout << endl; 
		cerr << "Coleccion de marcas vacia." << endl; 
		cerr << "No hay marcas de la prueba " << nombre_prueba << endl; 
		cout << endl; 
	}

	else {

		cerr << endl; 
		cerr << "Se han leido " << setw(3) << marcas_prueba.GetNum_marcas()
		     << " marcas de " << marcas_prueba.GetNombre() << endl; 
		cerr << endl; 
		cerr << marcas_prueba << endl;
		cerr << endl; 
	
		//...................................................................
		// ORDENAR Y MOSTRAR RESULTADO

		marcas_prueba.OrdenarPorTiempos();


		// Mostrar contenido de "marcas_prueba" a través de ToString()

		cerr << "Marcas ordenadas de la prueba " 
		     << marcas_prueba.GetNombre()  << endl; 
		cerr << endl; 
		cerr << marcas_prueba << endl;
		cerr << endl; 

	}

	//......................................................................


	// Descartar el contenido actual.

	marcas_prueba.EliminaTodosVectorMarcas(); 
	
	cerr << endl; 
	cerr << "marcas_prueba tras marcas_prueba.EliminaTodos())" << endl; 
	cerr << endl; 
	cerr << marcas_prueba << endl; 
	cerr << endl; 


	// Cargar su nuevo contenido desde un fichero de una prueba

	string nombre_in  = "marcas_prueba_100ML_2021.txt";
	string nombre_out = "out_"+ nombre_in; 

	cerr << endl; 
	cerr << "Leyendo marcas del fichero: "<< nombre_in << endl; 
	cerr << endl; 

	marcas_prueba.LeerVectorMarcas (nombre_in);

	cerr << endl; 
	cerr << "marcas_prueba tras marcas_prueba.LeerVectorMarcas  (" 
	     << nombre_in <<")" << endl; 
	cerr << marcas_prueba << endl; 
	cerr << endl; 

	cerr << endl; 
	cerr << "-------------------------------------------------------" << endl; 
	cerr << endl; 



	// Guardar contenido en un fichero de prueba

	cerr << endl; 
	cerr << "Guardando marcas en fichero: "<< nombre_out << endl; 
	cerr << endl; 

	marcas_prueba.EscribirVectorMarcas (nombre_out); 

	if (!ExisteFichero(nombre_out)) 

		cerr << "\tError: No se pudo crear " << nombre_out << endl; 

	else {

		cerr << endl; 
		cerr << "Se ha guardado en "<< nombre_out << endl; 
		cerr << endl; 
	}


	// Leer contenido desde un fichero de prueba

	cerr << endl; 
	cerr << "Leyendo marcas del fichero: "<< nombre_out << endl; 
	cerr << endl; 

	if (!ExisteFichero(nombre_out)) {
		
		cerr << "\tError en fichero " << nombre_out << ": ";
		cerr << "No existe o no tiene permiso." << endl; 
	}
	else {

		marcas_prueba.LeerVectorMarcas (nombre_out);
	}
	
	cerr << endl; 
	cerr << "marcas tras marcas.LeerVectorMarcas("<< nombre_out << ")" << endl; 
	cerr << marcas_prueba << endl; 
	cerr << endl; 	


	cerr << endl; 
	cerr << "-------------------------------------------------------" << endl; 
	cerr << endl; 


	return 0;
}

/***************************************************************************/
/***************************************************************************/
