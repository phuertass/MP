/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Programa que rellena aleatoriamente una matriz de enteros y ordena 
// (por filas) una parte rectangular.  
// Un buen ejemplo de reutilizaci�n de funciones ya implementadas porque usa 
// las funciones de ProcesamientoArrayInt. 
//
// Fichero: I_OrdenaMatrizEnteros.cpp
// 
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "ProcesamientoArrayInt.h"
#include "Funcs_MatrizEnteros.h"

using namespace std;


/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// Matriz base. De ella se extrer� una submatriz ("m_orden_filas") 
	// y de �sta �ltima se ordenar�n sus filas independientemente. 

	int m [NUM_FILAS][NUM_COLUMNAS] = {0};
	int filas_m = NUM_FILAS;    
	int columnas_m = NUM_COLUMNAS; 


	/************************************************************************/
	// Relena completamente la matriz con n�meros aleatorios entre 
	// "MIN_ALEAT" y "MAX_ALEAT" y muestra el resultado.

	RellenaMatriz (m, NUM_FILAS, NUM_COLUMNAS, MIN_ALEAT, MAX_ALEAT); 

	MuestraMatriz ("Original", m, NUM_FILAS, NUM_COLUMNAS, 
		            filas_m,columnas_m); 

	MuestraMatriz ("Original (otra presentacion)", 
		            m, NUM_FILAS, NUM_COLUMNAS, 
					0, NUM_FILAS-1, 0, NUM_COLUMNAS-1); 


	/************************************************************************/
	// Pedir los �ndices de filas y columnas que delimitan la zona 
	// rectangular de "m" sobre la que vamos a trabajar.

	int fil_inic, fil_fin; // filas inicial y final
	int col_inic, col_fin; // columnas inicial y final

	do {
		cout << endl; 
		cout << "Fila inicial (0 - " << NUM_FILAS-1 << ") = "; 
		cin >> fil_inic;
	} while ((fil_inic<0) || (fil_inic>=NUM_FILAS));

	do {
		cout << endl; 
		cout << "Fila final (0 - " << NUM_FILAS-1 << ")   = "; 
		cin >> fil_fin;
	} while ((fil_fin<0) || (fil_fin>=NUM_FILAS));

	if (fil_inic > fil_fin) 
		Intercambia (&fil_inic, &fil_fin); 


	do {
		cout << endl; 
		cout << "Columna inicial (0 - " << NUM_COLUMNAS-1 << ") = "; 
		cin >> col_inic;
	} while ((col_inic<0) || (col_inic>=NUM_COLUMNAS));

	do {
		cout << endl; 
		cout << "Columna final (0 - " << NUM_COLUMNAS-1 << ")   = "; 
		cin >> col_fin;
	} while ((col_fin<0) || (col_fin>=NUM_COLUMNAS));

	if (col_inic > col_fin) 
		Intercambia (&col_inic, &col_fin); 
	
 
 	cout << endl;
	cout << "Procesando entre filas ...... " << setw(2) << fil_inic 
	     << " y " << setw(2) << fil_fin << endl; 
 	cout << endl;
	cout << "Procesando entre columnas ... " << setw(2) << col_inic 
	     << " y " << setw(2) << col_fin << endl; 
 	cout << endl;


	/***********************************************************************/
 	// Preparar la matriz resultado ("m_orden_filas").
 	// Se declara con el mismo tama�o que la matriz base. 

	int m_orden_filas [NUM_FILAS][NUM_COLUMNAS] = {0};
   

	// Rellenar una zona rectangular de "m_orden_filas" desde la 
	// posici�n (0,0) tomando los valores de "m" y mostrar la submatriz. 

	ExtraeSubmatriz (m_orden_filas, m, NUM_FILAS, NUM_COLUMNAS, 
					 fil_inic, fil_fin, col_inic, col_fin); 

	int filas_m_orden_filas    = fil_fin - fil_inic + 1;    
	int columnas_m_orden_filas = col_fin - col_inic + 1;


	MuestraMatriz ("Preparada para ordenar", 
					m_orden_filas, NUM_FILAS, NUM_COLUMNAS, 
		            filas_m_orden_filas, columnas_m_orden_filas); 

	MuestraMatriz ("Zona de interes sobre original", 
					m, NUM_FILAS,NUM_COLUMNAS, 
					fil_inic, fil_fin, col_inic, col_fin); 


	/***********************************************************************/
 	// Ordenar la matriz reducida

	OrdenaMatriz (m_orden_filas, NUM_FILAS, NUM_COLUMNAS, 
				  0, filas_m_orden_filas-1, 0, columnas_m_orden_filas-1); 

	MuestraMatriz ("Matriz reducida ordenada", 
					m_orden_filas, NUM_FILAS, NUM_COLUMNAS, 
		            filas_m_orden_filas, columnas_m_orden_filas); 

	MuestraMatriz ("Matriz original (debe estar igual) ", 
		            m, NUM_FILAS, NUM_COLUMNAS, 
					0, NUM_FILAS-1, 0, NUM_COLUMNAS-1);
	
	

 	// Preparar la matriz resultado ("m_orden_columnas").
 	// Se declara con el mismo tama�o que la matriz base. 

	int m_orden_columnas [NUM_FILAS][NUM_COLUMNAS] = {0};
   

	// Rellenar una zona rectangular de "m_orden_columnas" desde la 
	// posici�n (0,0) tomando los valores de "m" y mostrar la submatriz. 

	ExtraeSubmatriz (m_orden_columnas, m, NUM_FILAS, NUM_COLUMNAS, 
					 fil_inic, fil_fin, col_inic, col_fin); 

	int filas_m_orden_columnas    = fil_fin - fil_inic + 1;    
	int columnas_m_orden_columnas = col_fin - col_inic + 1;


	MuestraMatriz ("Preparada para ordenar", 
					m_orden_columnas, NUM_FILAS, NUM_COLUMNAS, 
		            filas_m_orden_columnas, columnas_m_orden_columnas); 

	MuestraMatriz ("Zona de interes sobre original", 
					m, NUM_FILAS,NUM_COLUMNAS, 
					fil_inic, fil_fin, col_inic, col_fin); 


	/***********************************************************************/
 	// Ordenar la matriz reducida
	
	//TRASPONER
	int ftras = columnas_m_orden_columnas;
	int ctras = filas_m_orden_columnas;
	int columnas_tras [NUM_FILAS][NUM_COLUMNAS] = {0};

	for(int i=0; i<NUM_FILAS; i++){
		for(int j=0; j<NUM_COLUMNAS;j++){
			columnas_tras[j][i] = m_orden_columnas[i][j];
		}
	}

	//ORDENAMOS LA MATRIZ TRASPUESTA POR FILAS	
	OrdenaMatriz (columnas_tras, NUM_FILAS, NUM_COLUMNAS, 
				  0, ftras, 0, ctras-1);

	//TRASPONEMOS DE NUEVO	 DE NUEVO
	for(int i=0; i<NUM_FILAS; i++){
		for(int j=0; j<NUM_COLUMNAS;j++){
			m_orden_columnas[i][j] = columnas_tras[j][i];
		}
	}

	MuestraMatriz ("Matriz reducida ordenada", 
					m_orden_columnas, NUM_FILAS, NUM_COLUMNAS, 
		            filas_m_orden_columnas, columnas_m_orden_columnas); 

	MuestraMatriz ("Matriz original (debe estar igual) ", 
		            m, NUM_FILAS, NUM_COLUMNAS, 
					0, NUM_FILAS-1, 0, NUM_COLUMNAS-1); 

	return 0;
}

/***************************************************************************/
/***************************************************************************/
