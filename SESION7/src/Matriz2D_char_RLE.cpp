/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Fichero con la definición de las funciones asociadas el tipo Matriz2D.
// Declaraciones en Matriz2D_char_RLE.h
//
// Matriz2D: Matriz 2D dinamica de datos TipoBase en la que cada 
// fila es un vector dinamico independiente. 
//
// Tipo básico descrito en el video dedicado a la implementación de Matriz2D
// Está particularizado para el tipo char (TipoBase es char) y para el 
// problema de la codificación RLE
//
// Fichero: Matriz2D_char_RLE.cpp
//
/***************************************************************************/

#include "Matriz2D_char_RLE.h"
#include "TipoBase_char.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std; 

/***************************************************************************/
/***************************************************************************/
// FUNCIONES "PRIVADAS"
/***************************************************************************/
/***************************************************************************/
// Reserva memoria para los datos de una matriz dinámica con "nfils" filas 
// y "ncols" columnas. 
// El contenido de las "nfils"x"ncols" casillas queda INDEFINIDO.
// Parámetros:
//		nfils, número de filas de la matriz.
//		ncols, número de columnas de la matriz. 
// Devuelve: un dato Matriz2D con memoria reservada.
// 		El contenido de las "fils"x"cols" casillas queda indefinido. 
//
// PRE: nfils >= 0 && ncols >= 0
// NOTA: Tanto "nfils" como "nols" deben ser estrictamente positivos para poder 
// 		 disponer de una matriz no vacía. Si alguno de los dos valores fuera 0  
//		 no se reserva memoria, y la matriz queda vacía. 

Matriz2D ReservaMemoria (int nfils, int ncols);

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por una matriz dinámica. 
// Parámetros: 
//		matriz (referencia), la matriz que va a "liberarse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void LiberaMemoria (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// FIN FUNCIONES "PRIVADAS"
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

Matriz2D CreaMatriz (int nfils, int ncols, TipoBase valor)
{
	// Pedir memoria para los datos
	
	Matriz2D matriz = ReservaMemoria (nfils, ncols); 
	
	Ecualiza (matriz, valor);

	return (matriz); 
}

/***************************************************************************/
/***************************************************************************/
// "Destruye" una matriz dinámica y la deja en un estado no útil (vacía). 
// Parámetros: 
//		matriz (referencia), la matriz que va a "destruirse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void DestruyeMatriz (Matriz2D & matriz)
{
	LiberaMemoria (matriz); 
}

/***************************************************************************/
/***************************************************************************/
// Ecualizar una matriz: cambia todos los todos valores de la matriz y los 
// fija todos iguales e iguales a "valor".
// Parámetros: matriz (referencia), la matriz que va a modificarse. 
//		   valor, el valor común  que se escribirá en todas las casillas.

void Ecualiza (Matriz2D & matriz, TipoBase valor)
{
	for (int f=0; f<matriz.fils; f++) 
		for (int c=0; c<matriz.cols; c++) 
			matriz.datos[f][c] = valor;
}

/***************************************************************************/
/***************************************************************************/
// Deja la matriz en un estado no útil (vacía). 
// Parámetros: 
//		matriz (referencia), la matriz que va a "vaciarse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void EliminaTodos (Matriz2D & matriz)
{
	DestruyeMatriz (matriz); 
}

/***************************************************************************/
/***************************************************************************/
// Devuelve el número de filas/columnas de la matriz.
// Recibe: matriz, la matriz que se va a consultar. 

int NumFilas (const Matriz2D & matriz)
{
	return (matriz.fils);
}

/***************************************************************************/
/***************************************************************************/

int NumColumnas (const Matriz2D & matriz)
{
	return (matriz.cols);
}

/***************************************************************************/
/***************************************************************************/
// Consulta si una matriz está vacía.
// Recibe: true si la matriz "matriz" esta vacia. 

bool EstaVacia (Matriz2D & matriz)
{
	return ((matriz.fils == 0) || (matriz.cols == 0) || (matriz.datos == 0));
}

/***************************************************************************/
/***************************************************************************/
// Devuelve un string con el resultado de "serializar" una matriz.
// Recibe: matriz, la matriz que va a serializarse. 

string ToString (Matriz2D matriz)
{
	string cad;

	// string delimitador = "..................................";

	// cad = "\n" + delimitador + "\n";
	// cad = cad + "Filas = " + to_string(matriz.fils) + 
	      ", Columnas = " + to_string (matriz.cols) + "\n";
	// cad = cad + delimitador + "\n\n";

	if (!EstaVacia(matriz)) {	

		for (int f=0; f<matriz.fils; f++) {
			
			// cad = cad + "Fila " + to_string(f) + " --> ";
			
			for (int c=0; c<matriz.cols; c++) 
				cad = cad + matriz.datos[f][c];
			cad = cad + "\n";
		}
	} 

	// cad = cad + "\n\n" + delimitador + "\n\n";

	return (cad);
}

/***************************************************************************/
/***************************************************************************/
// Consulta ó modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consulta. Si se utiliza como lvalue se emplea 
// para modificación.
//
// PRE: 0<=num_fila<NumFilas(m)
// PRE: 0<=num_columna<NumColumnas(m)

TipoBase & Valor (const Matriz2D & matriz, int num_fila, int num_columna) 
{
	return (matriz.datos[num_fila][num_columna]);
}	

/***************************************************************************/
/***************************************************************************/
// Copia profunda. Hace una copia profunda de matrices.
// El contenido de la matriz "destino" se pierde, se sustituye por una  
// copia del contenido de "origen" . 
// Recibe: destino matriz clon.
//         origen, matriz original.

void Clona (Matriz2D & destino, const Matriz2D & origen)
{
	// Limpiar la matriz destino
	LiberaMemoria (destino);

	// Pedir memoria para poder recibir los datos de "origen" 
	destino = ReservaMemoria (origen.fils, origen.cols);

	// Copiar fila a fila (completas)
	for (int f=0; f<destino.fils; f++) 
		memcpy (destino.datos[f], origen.datos[f], 
			    destino.cols*sizeof(TipoBase));
}

/***************************************************************************/
/***************************************************************************/
// Comprueba si dos matrices son exactamente iguales (dimensiones y contenido)
// Recibe: "una" y "otra", las dos matrices que se comparan.
// Devuelve true si las dos matrices son exactamente iguales.

bool SonIguales (const Matriz2D & una, const Matriz2D & otra)
{
	bool filas_iguales = (una.fils == otra.fils);
	bool cols_iguales  = (una.cols == otra.cols);
	bool dimensiones_iguales  = (filas_iguales && cols_iguales);

	bool iguales = false; 

	// Si las dimensiones coinciden podemos seguir. Si no coinciden entonces 
	// son diferentes (en ese caso no entra al if pero nos hemos asegurado 
	// que "iguales" vale false). 

	if (dimensiones_iguales) {

		int filas = una.fils; // una.fils == otra.fils
		int cols =  una.cols; // una.cols == otra.cols

		// La comprobación se hará con ciclos while para salir cuando se 
		// encuentre una discrepancia entre "una" y "otra". 


		int f = 0; // Primera fila

		bool sigo = true;

		while (f<filas && sigo) {

			int c = 0; // Primera columna de la fila "f"

			while (c<cols && sigo) {

				// Si se encuentra una diferencia, terminar. Si no, 
				// continuar con la siguiente columna.

				if (una.datos[f][c] != otra.datos[f][c]) sigo = false;
				else c++;

			} // while c

			// Si todo coincide hasta el momento (sigo == true) continuar 
			// con la siguiente fila.
			
			if (sigo) f++; 

		} // while f

		// En este punto, si "sigo" no ha cambiado de valor (inicialmente 
		// true) es porque no ha encontrado diferencias, por lo que cambiamos 
		// el valor de "iguales" para hacerlo true (estaba fijado a false).
		// Si "sigo" es false (se encontró alguna diferencia) el valor de 
		// "iguales" no se cambia y sigue a false. 

		if (sigo) iguales = true;
	}

	return (iguales);
}

/***************************************************************************/
/***************************************************************************/


/***************************************************************************/
/***************************************************************************/
//
// FUNCIONES "PRIVADAS"
//
/***************************************************************************/
/***************************************************************************/
// Reserva memoria para los datos de una matriz dinámica con "nfils" filas 
// y "ncols" columnas. 
// El contenido de las "nfils"x"ncols" casillas queda INDEFINIDO.
// Parámetros:
//		nfils, número de filas de la matriz.
//		ncols, número de columnas de la matriz. 
// Devuelve: un dato Matriz2D con memoria reservada.
// 		El contenido de las "fils"x"cols" casillas queda indefinido. 
//
// PRE: nfils >= 0 && ncols >= 0
// NOTA: Tanto "nfils" como "nols" deben ser estrictamente positivos para poder 
// 		 disponer de una matriz no vacía. Si alguno de los dos valores fuera 0  
//		 no se reserva memoria, y la matriz queda vacía. 

Matriz2D ReservaMemoria (int nfils, int ncols)
{
	Matriz2D matriz; 

	// Por defecto, matriz vacía
	matriz.datos = 0;
	matriz.fils  = 0;
	matriz.cols  = 0;

	// Solo si se cumplen las precondiciones se reserva memoria 

	if (nfils>0 && ncols>0) {

		// "matriz" apuntará a un vector de punteros a las filas
		matriz.datos = new TipoBase * [nfils];

		for (int f=0; f<nfils; f++) {

			// "matriz[f]" apuntará a un vector de datos int
			matriz.datos[f] = new TipoBase [ncols];
		}

		matriz.fils = nfils;
		matriz.cols = ncols;
	}

	return (matriz);
}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por una matriz dinámica. 
// Parámetros: 
//		matriz (referencia), la matriz que va a "liberarse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void LiberaMemoria (Matriz2D & matriz)
{
	if (matriz.datos != 0) {

		// Liberar cada una de las filas
		for (int f=0; f<matriz.fils; f++)
 			delete [] matriz.datos[f];

 		// Liberar el vector de punteros
 		delete [] matriz.datos; 
   
		// La matriz debe quedar "vacía" --> la referencia "matriz" pone a 0 
		// el puntero que da acceso al vector de punteros a filas

		matriz.datos = 0;
		matriz.fils  = 0;
		matriz.cols  = 0;
	}
}

/***************************************************************************/
/***************************************************************************/