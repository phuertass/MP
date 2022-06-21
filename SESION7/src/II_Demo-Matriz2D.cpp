/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// RELACION DE PROBLEMAS 2
//
// Prueba de las funciones declaradas en Matriz2D.h
//  
// Fichero: II_Demo-Matriz2D.cpp
//
/***************************************************************************/
#include <iostream>
#include "Matriz2D.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// Lectura de las dimensiones de la matriz

	int num_filas, num_cols; 

	do  {
		cout << endl;
		cout << "Introduzca num. filas de la matriz: ";
		cin >> num_filas; 
	} while (num_filas <= 0);	

	do  {
		cout << endl;
		cout << "Introduzca num. columnas de la matriz: ";
		cin >> num_cols; 
	} while (num_cols <= 0);	

	cout << endl << endl;

	// .....................................................................
	// Creación de una matriz y rellenar sus casillas  

	Matriz2D m = CreaMatriz (num_filas, num_cols);

	for (int f=0; f<m.fils; f++) 
		for (int c=0; c<m.cols; c++) 
			m.datos[f][c] = ((10*(f+1))+c+1);
		
	cout << "Matriz rellena: ";
	cout << ToString (m);

	// .....................................................................
	// Destruye la matriz

	DestruyeMatriz (m);

	// .....................................................................
	// Creación de una matriz (todas las casillas a cero) y mostrala 

	Matriz2D m0 = CreaMatriz (num_filas, num_cols);

	cout << "Matriz con todos 0: ";
	cout << ToString (m0);

	// .....................................................................
	// Creación de una matriz (todas las casillas a 9) y mostrala 

	Matriz2D m9 = CreaMatriz (num_filas, num_cols, 9);

	cout << "Matriz con todos 9: ";
	cout << ToString (m9);

	// .....................................................................
	// Creación de una matriz vacia (0x0, todas las casillas a 0) y mostrala 

	Matriz2D m_vacia = CreaMatriz ();

	cout << "Matriz vacia: ";
	cout << ToString (m_vacia);

	Matriz2D m_nueva = CreaMatriz(5,5);

	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++)
		{
			m_nueva.datos[i][j] = (i+j)*10;
		}
	}

	cout<<ToString(m_nueva);

	//Elimina fila matriz
	EliminaFila(m_nueva, 2);
	cout<<"Matriz con la fila 2 eliminada"<<endl;
	cout << ToString(m_nueva);
	////Elimina columna matriz
	cout<<"Eliminando la columna 2..."<<endl;
	EliminaColumna(m_nueva, 2);
	cout<<"Matriz con la columna 2 eliminada"<<endl;
	cout << ToString(m_nueva);

	//Prueba submatriz
	Matriz2D resultado = CreaMatriz(5,5);
	int fila_inic=1;
	int col_inic=1;
	cout<<"Fila inicial->"<<fila_inic<<endl;
	cout<<"Columna inicial->"<<col_inic<<endl;
	SubMatriz(resultado, m_nueva, fila_inic,col_inic,3,3);
	cout<<"Submatriz nueva"<<endl;
	cout<<ToString(resultado);

	EspejoVertical(m_nueva);
	cout<<"Matriz con espejo vertical"<<endl;
	cout << ToString(m_nueva);


	EspejoHorizontal(m_nueva);
	cout<<"Matriz con espejo horizontal"<<endl;
	cout << ToString(m_nueva);
	// .....................................................................
	// Destruye las matrices 

	DestruyeMatriz (m0);
	DestruyeMatriz (m9);
	DestruyeMatriz (m_vacia);
	DestruyeMatriz (resultado);
	//DestruyeMatriz (m_nueva);

	// .....................................................................

	return 0; 
}

/***************************************************************************/
/***************************************************************************/
