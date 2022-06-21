/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Fichero de cabecera asociado al tipo Matriz2D
// Definiciones en Matriz2D_char_RLE.cpp
//
// Matriz2D: Matriz 2D dinamica de datos de tipo TipoBase en lhara que cada 
// fila es un vector dinamico independiente. 
//
// Está particularizado para el tipo char (TipoBase es char) y para el 
// problema de la codificación RLE
//
// Fichero: Matriz2D_char_RLE.h 
//
/***************************************************************************/

#ifndef MATRIZ2D_CHAR_RLE
#define MATRIZ2D_CHAR_RLE

#include <string>
#include "TipoBase_char.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/
// Definiciones de tipos

typedef struct {

	TipoBase ** datos;	// Puntero a vector de punteros a los datos

	int fils;			// Num. de filas
	int cols; 			// Num. de columnas

} Matriz2D;


/***************************************************************************/
/***************************************************************************/
// Prototipos
/*

Matriz2D CreaMatriz (int nfils, int ncols, TipoBase valor);
void DestruyeMatriz (Matriz2D & matriz);

void Ecualiza (Matriz2D & matriz, TipoBase valor=VALOR_DEF);
void EliminaTodos (Matriz2D & matriz);

int NumFilas (const Matriz2D & matriz);
int NumColumnas (const Matriz2D & matriz);
bool EstaVacia (Matriz2D & matriz);
bool SonIguales (const Matriz2D & una, const Matriz2D & otra);

string ToString (Matriz2D matriz);

TipoBase & Valor (const Matriz2D & matriz, int num_fila, int num_columna); 
 
void Clona (Matriz2D & destino, const Matriz2D & origen);

*/
/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
/***************************************************************************/
// Crea una matriz dinámica con "nfils" filas y "ncols" columnas. 
// El contenido de las "fils"x"cols" casillas se inicializa a un valor común, 
// el indicado en el parámetro "valor" (0 si TipoBase es int, 0.0 si TipoBase
// es double y 'x' si TipoBase es char). 
// La funcionalidad sería similar a la de un constructor.
// Parámetros:
//		nfils, número de filas de la matriz (por defecto 0).
//		ncols, número de columnas de la matriz (por defecto 0).
//		valor, valor común que se copiará en las casillas. 
// Devuelve: un dato de tipo Matriz2D.
//
// PRE: nfils >= 0 && ncols >= 0
// NOTA: Tanto "nfils" como "nols" deben ser estrictamente positivos para poder 
// 		 disponer de una matriz no vacía. Si alguno de los dos valores fuera 0  
//		 no se reserva memoria, y la matriz queda vacía. 

Matriz2D CreaMatriz (int nfils=0, int ncols=0, TipoBase valor=VALOR_DEF);

/***************************************************************************/
/***************************************************************************/
// "Destruye" una matriz dinámica y la deja en un estado no útil (vacía). 
// Parámetros: 
//		matriz (referencia), la matriz que va a "destruirse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void DestruyeMatriz (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Ecualizar una matriz: cambia todos los todos valores de la matriz y los 
// fija todos iguales e iguales a "valor".
// Parámetros: matriz (referencia), la matriz que va a modificarse. 
//		   valor, el valor común  que se escribirá en todas las casillas.

void Ecualiza (Matriz2D & matriz, TipoBase valor=VALOR_DEF);

/***************************************************************************/
/***************************************************************************/
// Deja la matriz en un estado no útil (vacía). 
// Parámetros: 
//		matriz (referencia), la matriz que va a "vaciarse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void EliminaTodos (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Devuelve el número de filas/columnas de la matriz.
// Recibe: matriz, la matriz que se va a consultar. 

int NumFilas (const Matriz2D & matriz);
int NumColumnas (const Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Consulta si una matriz está vacía.
// Recibe: true si la matriz "matriz" esta vacia. 

bool EstaVacia (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Devuelve un string con el resultado de "serializar" una matriz.
// Recibe: matriz, la matriz que va a serializarse. 

string ToString (Matriz2D matriz);

/***************************************************************************/
/***************************************************************************/
// Consulta ó modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consulta. Si se utiliza como lvalue se emplea 
// para modificación.
//
// PRE: 0<=num_fila<NumFilas(m)
// PRE: 0<=num_columna<NumColumnas(m)

TipoBase & Valor (const Matriz2D & matriz, int num_fila, int num_columna); 

/***************************************************************************/
/***************************************************************************/
// Copia profunda. Hace una copia profunda de matrices.
// El contenido de la matriz "destino" se pierde, se sustituye por una  
// copia del contenido de "origen" . 
// Recibe: destino, matriz clon.
//         origen, matriz original.
 
void Clona (Matriz2D & destino, const Matriz2D & origen);

/***************************************************************************/
/***************************************************************************/
// Comprueba si dos matrices son exactamente iguales (dimensiones y contenido)
// Recibe: "una" y "otra", las dos matrices que se comparan.
// Devuelve true si las dos matrices son exactamente iguales.

bool SonIguales (const Matriz2D & una, const Matriz2D & otra);

/***************************************************************************/
/***************************************************************************/

#endif
