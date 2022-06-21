/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Fichero con la definición de las funciones asociadas el tipo Matriz2D
//
// Matriz2D: Matriz 2D dinamica de datos int en la que cada 
// fila es un vector dinamico independiente. 
//
// Tipo básico descrito en el video dedicado a la implementación de Matriz2D
//
// Fichero: Matriz2D.cpp
//
/***************************************************************************/

#include "Matriz2D.h"

#include <string>
#include <cstring>
using namespace std; 

/***************************************************************************/
/***************************************************************************/
// Crea una matriz dinámica con "nfils" filas y "ncols" columnas. 
// El contenido de las "fils"x"cols" casillas se inicializa a un valor común, 
// el indicado en el parámetro "valor"
// Parámetros:
//		nfils, número de filas de la matriz (por defecto 0).
//		ncols, número de columnas de la matriz (por defecto 0).
//		valor, valor común que se copiará en las casillas (por defecto 0). 
// Devuelve: un dato de tipo Matriz2D.
//
// PRE: nfils >= 0 && ncols >= 0
// NOTA: Tanto "nfils" como "nols" deben ser estrictamente positivos para poder 
// 		 disponer de una matriz no vacía. Si alguno de los dos valores fuera 0  
//		 no se reserva memoria, y la matriz queda vacía. 

Matriz2D CreaMatriz (int nfils, int ncols, TipoBaseMatriz valor)
{
	// Pedir memoria para los datos
	
	Matriz2D matriz = ReservaMemoria (nfils, ncols); 
	
	// Inicializar las casillas de la matriz

	for (int f=0; f<matriz.fils; f++) 
		for (int c=0; c<matriz.cols; c++) 
			matriz.datos[f][c] = valor;

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
		matriz.datos = new int * [nfils];

		for (int f=0; f<nfils; f++) {

			// "matriz[f]" apuntará a un vector de datos int
			matriz.datos[f] = new int [ncols];
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
// Devuelve un string con el resultado de "serializar" una matriz.
// Parámetros: matriz (referencia), la matriz que va a serializarse. 

string ToString (const Matriz2D & matriz)
{
	string cad;

	string delimitador = "..................................";

	cad = "\n" + delimitador + "\n";
	cad = cad + "Filas = " + to_string(matriz.fils) + 
	      ", Columnas = " + to_string (matriz.cols) + "\n\n";

	for (int f=0; f<matriz.fils; f++) {
		cad = cad + "Fila " + to_string(f) + " --> ";
		
		for (int c=0; c<matriz.cols; c++) 
			cad = cad + to_string(matriz.datos[f][c]) + "  ";
		cad = cad + "\n";
	}
	cad = cad + delimitador + "\n\n";

	return (cad);
}

/***************************************************************************/
/***************************************************************************/


/***************************************************************************/
/***************************************************************************/
// Devuelve el número de filas/columnas de la matriz.
// Parámetros: matriz (referencia), la matriz que se va a consultar. 

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
// Consulta ó modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consulta. Si se utiliza como lvalue se emplea 
// para modificación.
// Parámetros: matriz (referencia), la matriz. 
//			   num_fila, número de fila.
//			   num_columna, número de columna.
// PRE: 0<=num_fila<NumFilas(m)
// PRE: 0<=num_columna<NumColumnas(m)

int & Valor (const Matriz2D & matriz, int num_fila, int num_columna) 
{
	return (matriz.datos[num_fila][num_columna]);
}	

/***************************************************************************/
/***************************************************************************/
//¿Vacía?. Devuelve true si la matriz está vacía.
bool EstaVacia(const Matriz2D & matriz)
{
	return (matriz.fils == 0 && matriz.cols == 0);
};

//Ecualizar. Cambia todos los todos valores de la matriz por valor.
void Ecualiza(Matriz2D & matriz, TipoBaseMatriz valor)
{
	for (int f=0; f<matriz.fils; f++) 
		for (int c=0; c<matriz.cols; c++) 
			matriz.datos[f][c] = valor;
};

//Vacíar matriz dinámica. Deja la matriz en un estado no útil (vacía). La
//matriz queda con todos sus campos a cero.
void EliminaTodos (Matriz2D & matriz)
{
	LiberaMemoria(matriz);
};

//Copia profunda. Hace una copia profunda de origen en destino.
void Clona (Matriz2D & destino, const Matriz2D & origen)
{
	LiberaMemoria(destino);

	destino = ReservaMemoria(origen.fils, origen.cols);

	for (int f=0; f<destino.fils; f++) 
		for (int c=0; c<destino.cols; c++) 
			destino.datos[f][c] = origen.datos[f][c];
};

//Comparación. Devuelve true si las matrices una y otra son exactamente iguales 
//(dimensiones y contenidos).
bool SonIguales (const Matriz2D & una, const Matriz2D & otra)
{
	bool iguales = false;

	if(otra.fils == una.fils && otra.cols == una.cols)
	{
		for (int f=0; f<una.fils; f++) 
			for (int c=0; c<una.cols; c++)
			{
				if(una.datos[f][c] != otra.datos[f][c])
					return false;
			}

		iguales=true;	
	}
	return iguales;
				
};

//Eliminar fila. Elimina la fila num_fila de la matriz matriz
void EliminaFila (Matriz2D & matriz, int num_fila)
{
	if(num_fila>=0 && num_fila<matriz.fils)
	{
		for(int i=num_fila; i<matriz.fils-1; i++)
		{
			//matriz.datos[i] = matriz.datos[i+1];
			memmove(matriz.datos[i], matriz.datos[i+1],
			sizeof(TipoBaseMatriz)*(matriz.fils));
		}

		delete [] matriz.datos[matriz.fils-1];
		matriz.fils-=1;
	}
};

//Eliminar columna. Elimina la columna num_col de la matriz matriz.
void EliminaColumna (Matriz2D & matriz, int num_col)
{
	if(num_col>=0 && num_col<matriz.cols)
	{
		for(int i=0; i<matriz.fils; i++)
		{
			TipoBaseMatriz * p = matriz.datos[i];
			memmove(p+num_col, p+num_col+1, 
			sizeof(TipoBaseMatriz)*(matriz.cols-num_col-1));
		}
	}
	matriz.cols -= 1;
};

//Espejo horizontal. Cambia de orden las filas de matriz (la primera
//pasa a ser la última y la última la primera, la segunda la penúltima y la
//penúltima la segunda, etc.).
void EspejoHorizontal (Matriz2D & matriz)
{
	for(int i=0; i<matriz.fils/2; i++)
	{
		Intercambia(matriz.datos[i], matriz.datos[matriz.fils-i-1]);
	}
};

//Espejo vertical. Cambia de orden las columnas de matriz (la primera
//pasa a ser la última y la última la primera, la segunda la penúltima y la
//penúltima la segunda, etc.).
void EspejoVertical (Matriz2D & matriz)
{
	for(int i=0; i<matriz.fils; i++)
	{
		for(int j=0; j<matriz.cols/2; j++)
		{
			Intercambia( matriz.datos[i][j], matriz.datos[i][matriz.cols-j-1]);
		}
	}
};

//Submatriz. Extrae una submatriz de original y la deja en
//resultado. La submatriz resultado es una zona rectangular de
//original que empieza en la casilla (fila_inic, col_inic) y que
//tiene (un máximo de) num_filas filas y num_cols columnas.
void SubMatriz (Matriz2D & resultado, const Matriz2D & original,
int fila_inic, int col_inic, int num_filas, int num_cols)
{
	if(fila_inic<0 or fila_inic>num_filas or col_inic<0 or col_inic>num_cols
	or num_filas>original.fils or num_cols>original.cols)
		return;

	LiberaMemoria(resultado);

	resultado = ReservaMemoria(num_filas, num_cols);

	int fila_res=0;
	int col_res=0;
	for(int i=0; i<resultado.fils; i++,fila_res++)
	{
		for(int j=0, col_res=0; j<resultado.cols; j++,col_res=0)
		{
			resultado.datos[i][j] = original.datos[i+fila_inic][j+col_inic];
		}
	}
};

void Intercambia(TipoBaseMatriz * &a, TipoBaseMatriz * &b)
{
	TipoBaseMatriz * tmp = a;
	a = b;
	b = tmp;
};

void Intercambia(TipoBaseMatriz &a, TipoBaseMatriz &b)
{
	TipoBaseMatriz tmp = a;
	a = b;
	b = tmp;
};