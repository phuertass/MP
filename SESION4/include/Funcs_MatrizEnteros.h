/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Fichero: Funcs_MatrizEnteros.h
// 
/***************************************************************************/

#ifndef FUNCS_MATRIZ_ENTEROS
#define FUNCS_MATRIZ_ENTEROS

#include <string>
#include "config_matrices.h"

using namespace std;


/***************************************************************************/
// Rellena una matriz con números aleatorios. 
// Parámetros: 
//		m, matriz que se rellena. 
//		NUM_FILAS, número de filas de la matriz. 
//		NUM_COLUMNAS, número de columnas de la matriz. 
//
// PRE: "m" se declaró con tamaño NUM_FILAS x NUM_COLUMNAS

void RellenaMatriz (int (*m) [NUM_COLUMNAS], 
				     const int NUM_FILAS,   const int NUM_COLUMNAS, 
					 const int MENOR_ALEAT, const int MAYOR_ALEAT); 

/***************************************************************************/
// Muestra el contenido de una matriz. 
// Parámetros: 
//		msg, mensaje de cabecera.
//		m, matriz que se muestra. 
//		NUM_FILAS, número de filas de la matriz. 
//		NUM_COLUMNAS, número de columnas de la matriz. 
// 		filas_usadas, filas ocupadas de la matriz.
// 		cols_usadas, columnas ocupadas de la matriz.
//
// PRE: "m" se declaró con tamaño NUM_FILAS x NUM_COLUMNAS

void MuestraMatriz (string msg, int (*m) [NUM_COLUMNAS], 
				    const int NUM_FILAS,   const int NUM_COLUMNAS, 
	                int filas_usadas, int cols_usadas);

/***************************************************************************/
// Muestra el contenido de una matriz. 
// Parámetros: 
//		msg, mensaje de cabecera.
//		m, matriz que se muestra. 
//		NUM_FILAS, número de filas de la matriz. 
//		NUM_COLUMNAS, número de columnas de la matriz. 
//		fil_inic y fil_fin, número de la fila inicial y final (resp.) 
//			sobre la matriz "orig" que se van a copiar en "dest". 
//		col_inic y col_fin, número de la columna inicial y final (resp.) 
//			sobre la matriz "orig" que se van a copiar en "dest". 

void MuestraMatriz (string msg, int (*m) [NUM_COLUMNAS], 
	                const int NUM_FILAS, const int NUM_COLUMNAS, 
					const int fil_inic, const int fil_fin, 
					const int col_inic, const int col_fin);

/***************************************************************************/
// Copia completa de una matriz.
// Parámetros: 
//		dest, matriz resultado. 
//		orig, matriz origen. 
//		NUM_FILAS, número de filas de las matrices. 
//		NUM_COLUMNAS, número de columnas de las matrices. 
//
// PRE: "orig" y "dest" se declararon con tamaño NUM_FILAS x NUM_COLUMNAS

void CopiaMatriz (int (*dest) [NUM_COLUMNAS], int (*orig) [NUM_COLUMNAS], 
				  const int NUM_FILAS, const int NUM_COLUMNAS); 

/***************************************************************************/
// "Extrae" una submatriz y copia los valores en otra matriz.
//
// Parámetros: 
//		dest, matriz resultado. 
//		orig, matriz origen. 
//		NUM_FILAS y NUM_COLUMNAS, número de filas y columnas reservadas 
//			para ambas matrices. 
//		fil_inic y fil_fin, número de la fila inicial y final  
//			sobre la matriz "orig" que se van a copiar en "dest". 
//		col_inic y col_fin, número de la columna inicial y final (resp.) 
//			sobre la matriz "orig" que se van a copiar en "dest". 
//
// PRE: "orig" y "dest" se declararon con tamaño NUM_FILAS x NUM_COLUMNAS

void ExtraeSubmatriz (int (*dest) [NUM_COLUMNAS],int (*orig) [NUM_COLUMNAS], 
					  const int NUM_FILAS, const int NUM_COLUMNAS, 
					  const int fil_inic, const int fil_fin, 
					  const int col_inic, const int col_fin); 

/***************************************************************************/
// Ordena una matriz.
// Parámetros: 
//		m, matriz a ordenar. 
//		NUM_FILAS y NUM_COLUMNAS, número de filas y columnas de la matriz. 
//		fil_inic y fil_fin, número de la fila inicial y final (resp.) 
//			sobre la matriz "m" entre las que se va a ordenar. 
//		col_inic y col_fin, número de la columna inicial y final (resp.) 
//			sobre la matriz "m" entre las que se va a ordenar. 
//
// PRE: "m" se declaró con tamaño NUM_FILAS x NUM_COLUMNAS
// NOTA: Se modifica "m", pero no importa ya que no necesitamos "retroceder".

void OrdenaMatriz (int (*m) [NUM_COLUMNAS], 
				   const int NUM_FILAS, const int NUM_COLUMNAS, 
				   const int fil_inic, const int fil_fin, 
				   const int col_inic, const int col_fin);

/***************************************************************************/
/***************************************************************************/

#endif