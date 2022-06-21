/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Fichero: Funcs_MatrizEnteros.cpp
// 
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "config_matrices.h"
#include "ProcesamientoArrayInt.h"
#include "Funcs_MatrizEnteros.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Rellena completamente una matriz con n�meros aleatorios. 
//
// Par�metros: 
//		m, matriz que se rellena. 
//		NUM_FILAS, n�mero de filas de la matriz. 
//		NUM_COLUMNAS, n�mero de columnas de la matriz. 
//
// PRE: "m" se declar� con tama�o NUM_FILAS x NUM_COLUMNAS
//
// NOTA: Se modifica "m", pero no importa ya que no necesitamos "retroceder". 

void RellenaMatriz  (int (*m) [NUM_COLUMNAS], 
					  const int NUM_FILAS, const int NUM_COLUMNAS, 
					  const int MENOR_ALEAT, const int MAYOR_ALEAT)
{
	for (int f=0; f<NUM_FILAS; f++) {

		RellenaVector (*m, NUM_COLUMNAS, MENOR_ALEAT, MAYOR_ALEAT);

		m++;
	}

} 

/***************************************************************************/
/***************************************************************************/
// Muestra el contenido de una matriz. 
//
// Par�metros: 
//		msg, mensaje de cabecera.
//		m, matriz que se muestra. 
//		NUM_FILAS, n�mero de filas de la matriz. 
//		NUM_COLUMNAS, n�mero de columnas de la matriz. 
// 		filas_usadas, filas ocupadas de la matriz.
// 		cols_usadas, columnas ocupadas de la matriz.
//
//
// PRE: "m" se declar� con tama�o NUM_FILAS x NUM_COLUMNAS
//
// NOTA: Se modifica "m", pero no importa ya que no necesitamos "retroceder".

void MuestraMatriz (string msg, int (*m) [NUM_COLUMNAS], 
	                const int NUM_FILAS, const int NUM_COLUMNAS, 
	                int filas_usadas, int cols_usadas)
{
	cout << endl; 
	cout << "-----------------------------------------------------" << endl;
	cout << msg << endl; 
	cout << endl; 

	for (int f=0; f<filas_usadas; f++) {	

		string msg_linea = "Fila " + to_string(f) + ": "; 

		MuestraVector (msg_linea, *m, cols_usadas, cols_usadas);
		
		m++;
	}

	cout << "-----------------------------------------------------" << endl;
	cout << endl; 
}

/***************************************************************************/
/***************************************************************************/
// Muestra el contenido de una matriz. 
// Par�metros: 
//		msg, mensaje de cabecera.
//		m, matriz que se muestra. 
//		NUM_FILAS, n�mero de filas de la matriz. 
//		NUM_COLUMNAS, n�mero de columnas de la matriz. 
//		fil_inic y fil_fin, n�mero de la fila inicial y final (resp.) 
//			sobre la matriz "orig" que se van a copiar en "dest". 
//		col_inic y col_fin, n�mero de la columna inicial y final (resp.) 
//			sobre la matriz "orig" que se van a copiar en "dest". 

void MuestraMatriz (string msg, int (*m) [NUM_COLUMNAS], 
	                const int NUM_FILAS, const int NUM_COLUMNAS, 
					const int fil_inic, const int fil_fin, 
					const int col_inic, const int col_fin)
{
	cout << endl; 
	cout << "-----------------------------------------------------" << endl;
	cout << msg << endl; 
	cout << endl; 


	int num_fils = fil_fin - fil_inic + 1;
	int num_cols = col_fin - col_inic + 1; 

 	m += fil_inic;

	for (int f=0; f<num_fils; f++) {

		string msg_linea = "Fila " + to_string(f) + ": "; 

		int * inicio = ((int *) (m)) + col_inic; 

		MuestraVector (msg_linea, inicio, num_cols, num_cols);

		m++;
	}

	cout << "-----------------------------------------------------" << endl;
	cout << endl; 
}


/***************************************************************************/
/***************************************************************************/
// Copia completa de una matriz.
// Par�metros: 
//		dest, matriz resultado. 
//		orig, matriz origen. 
//		NUM_FILAS, n�mero de filas de las matrices. 
//		NUM_COLUMNAS, n�mero de columnas de las matrices. 
//
// PRE: "orig" y "dest" se declararon con tama�o NUM_FILAS x NUM_COLUMNAS
// NOTA: Se modifican "dest" y "orig", pero no importa ya que no 
// 		necesitamos "retroceder".

void CopiaMatriz (int (*dest) [NUM_COLUMNAS], int (*orig) [NUM_COLUMNAS], 
				  const int NUM_FILAS, const int NUM_COLUMNAS)
{
	for (int f=0; f<NUM_FILAS; f++) {

		memcpy (dest, orig, NUM_COLUMNAS*sizeof(int)); 
		dest++;
		orig++;
	}
}
		
/***************************************************************************/
/***************************************************************************/
// "Extrae" una submatriz y copia los valores en otra matriz.
//
// Par�metros: 
//		dest, matriz resultado. 
//		orig, matriz origen. 
//		NUM_FILAS y NUM_COLUMNAS, n�mero de filas y columnas reservadas 
//			para ambas matrices. 
//		fil_inic y fil_fin, n�mero de la fila inicial y final  
//			sobre la matriz "orig" que se van a copiar en "dest". 
//		col_inic y col_fin, n�mero de la columna inicial y final (resp.) 
//			sobre la matriz "orig" que se van a copiar en "dest". 
//
// PRE: "orig" y "dest" se declararon con tama�o NUM_FILAS x NUM_COLUMNAS
// NOTA: Se modifican "dest" y "orig", pero no importa ya que no 
// 		 necesitamos "retroceder".

void ExtraeSubmatriz (int (*dest) [NUM_COLUMNAS],int (*orig) [NUM_COLUMNAS], 
					  const int NUM_FILAS, const int NUM_COLUMNAS, 
					  const int fil_inic, const int fil_fin, 
					  const int col_inic, const int col_fin)
{
	int num_fils_dest = fil_fin - fil_inic + 1;
	int num_cols_dest = col_fin - col_inic + 1;


	for (int f=0; f<num_fils_dest; f++) {

		int * inicio_bloque = (int *) (orig + fil_inic + f); 

		memcpy (dest, inicio_bloque + col_inic, num_cols_dest*sizeof(int)); 

		dest++;
	}

} 

/***************************************************************************/
/***************************************************************************/
// Ordena una matriz.
// Par�metros: 
//		m, matriz a ordenar. 
//		NUM_FILAS y NUM_COLUMNAS, n�mero de filas y columnas de la matriz. 
//		fil_inic y fil_fin, n�mero de la fila inicial y final (resp.) 
//			sobre la matriz "m" entre las que se va a ordenar. 
//		col_inic y col_fin, n�mero de la columna inicial y final (resp.) 
//			sobre la matriz "m" entre las que se va a ordenar. 
//
// PRE: "m" se declar� con tama�o NUM_FILAS x NUM_COLUMNAS
// NOTA: Se modifica "m", pero no importa ya que no necesitamos "retroceder".

 void OrdenaMatriz (int (*m) [NUM_COLUMNAS], 
					const int NUM_FILAS, const int NUM_COLUMNAS, 
				    const int fil_inic, const int fil_fin, 
					const int col_inic, const int col_fin)
 {

	int num_fils = fil_fin - fil_inic + 1;
	int num_cols = col_fin - col_inic + 1; 

 	m += fil_inic;

	for (int f=0; f<num_fils; f++) {

		int * inicio = ((int *) (m)) + col_inic; 

		OrdenaSeleccion (inicio, num_cols);

		m++;
	}

 }

/***************************************************************************/
/***************************************************************************/
