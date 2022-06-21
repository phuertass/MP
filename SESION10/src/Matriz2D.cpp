/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Implementación de las funciones de la clase Matriz2D
//
// Declaraciones en Matriz2D.h
//
// Fichero: Matriz2D.cpp
//
/***************************************************************************/


#include "Matriz2D.h"
#include "TipoBaseMatriz.h"

#include <cstring>
#include <string>
#include <iostream>
using namespace std;

/***********************************************************************/
//Constructor sin argumentos, que crea una matriz vacía
Matriz2D :: Matriz2D() {
	datos = 0;
	fils = 0;
	cols = 0;
}

/***********************************************************************/
// Constructor con un argumento, que crea una matriz cuadrada con el 
//número de filas y columnas indicado en el argumento.

Matriz2D :: Matriz2D(int n) {
	ReservarMemoria(n, n);
}

/***********************************************************************/
// Constructor con dos argumentos, que crea una matriz con el número de 
//filas indicado en el primer argumento y con el número de columnas 
//indicado en el segundo.

/*
Matriz2D:: Matriz2D(int fils, int cols){
	ReservarMemoria(fils, cols);
	Ecualiza(VALOR_DEF);
}

/***********************************************************************/
//Constructor con tres argumentos, que crea una matriz con el número de 
//filas indicado en el primer argumento y con el número de columnas 
//indicado en el segundo argumento. Además inicia todas las casillas de la 
//matriz al valor especificado con el tercer argumento.

Matriz2D :: Matriz2D(int fils, int cols, TipoBaseMatriz valor){
	ReservarMemoria(fils, cols);
	Ecualiza(valor);
}

/***********************************************************************/
//Constructor de copia
Matriz2D :: Matriz2D(const Matriz2D &m){
	ReservarMemoria(m.NumFilas() , m.NumColumnas());
	CopiarDatos(m);
}

/***********************************************************************/
// Destructor

Matriz2D :: ~Matriz2D(void){
	LiberarMemoria();
}


/***********************************************************************/
// SOBRECARGA DE OPERADORES
TipoBaseMatriz & Matriz2D :: operator () (const int fila, const int columna)
{
	return Valor(fila, columna);
}

TipoBaseMatriz & Matriz2D :: operator () (const int fila, 
const int columna) const
{
	return Valor(fila, columna);
}	

/***********************************************************************/
/***********************************************************************/
// Operador de asignación desde otro dato Matriz2D
// Parámetros: otra (referencia), objeto que sirve de modelo. 

Matriz2D & Matriz2D :: operator = (const Matriz2D & otro)
{
	if (this != &otro) { // Evitar autoasignación

		// Libera la memoria ocupada
		LiberarMemoria();	

		// Reserva de memoria para los datos del otro vector
		ReservarMemoria (otro.fils, otro.cols);

		// Copia los campos privados y los coeficientes
		CopiarDatos(otro);
	}
	return (*this);  // Devuelve el objeto implicito:
					 // parte izquierda de la asignación
}

Matriz2D & Matriz2D:: operator = (const TipoBaseMatriz & otro){
	Ecualiza(otro);
	return (*this);
}

/***********************************************************************/
/***********************************************************************/
// Operador == 
// Dos datos Matriz2D son iguales si tienen el mismo número de filas,
// columnas y los contenidos son iguales y en las mismas posiciones 
bool Matriz2D :: operator == (const Matriz2D & otro) const
{
	return EsIgualA(otro);
}

/***********************************************************************/
/***********************************************************************/
// Operador !=
// Dos datos Matriz2D son distintos si no tienen el mismo número de
// filas, columnas o los contenidos son distintos en las mismas 
//posiciones
bool Matriz2D::operator != (const Matriz2D & otro) const
{
	if( (*this)==otro)
		return false;
	else
		return !EsIgualA(otro);
}

/***********************************************************************/
/***********************************************************************/
// Operador unario +
// Devuelve una copia del objeto.
Matriz2D & Matriz2D::operator + (const Matriz2D & otro)
{
	// Si tienen las mismas dimensiones las sumamos, si no devolvemos
	// this
	if(fils == otro.NumFilas() && cols == otro.NumColumnas()){
		for(int i = 0; i < fils; i++)
			for(int j = 0; j < cols; j++)
				Valor(i,j) += otro.Valor(i,j);
		return (*this);
	}
	else
		return (*this);
}

/***********************************************************************/
/***********************************************************************/
// Operador unario -
// Devuelve una copia del objeto.
Matriz2D & Matriz2D::operator - (const Matriz2D & otro)
{
	// Si tienen las mismas dimensiones las restamos, si no devolvemos
	// this
	if(fils == otro.NumFilas() && cols == otro.NumColumnas()){
		for(int i = 0; i < fils; i++)
			for(int j = 0; j < cols; j++)
				Valor(i,j) -= otro.Valor(i,j);
		return (*this);
	}
	else
		return (*this);
}

/***********************************************************************/
/***********************************************************************/
// Operador binario +
// Recibe dos matrices y devuelve la suma de ellas.
// Si no tienen las mismas dimensiones devuelve una matriz vacía.
Matriz2D operator + (const Matriz2D & m1, const Matriz2D & m2)
{
	Matriz2D m3;
	if(m1.NumFilas() == m2.NumFilas() && m1.NumColumnas() == m2.NumColumnas())
	{
		m3.ReservarMemoria(m1.NumFilas(), m1.NumColumnas());
		for(int i=0; i<m1.NumFilas(); i++)
			for(int j=0; j<m1.NumColumnas(); j++)
				m3.Valor(i,j) = m1.Valor(i,j) + m2.Valor(i,j);
	}
	return m3;
}

// Recibe una matriz y un valor y devuelve la suma de 
// la matriz y el valor en todas sus casillas.
Matriz2D operator + (const Matriz2D & m1, const TipoBaseMatriz & m2)
{	
	Matriz2D m3(m1.NumFilas(), m1.NumColumnas());
	for(int i=0; i<m1.NumFilas(); i++)
		for(int j=0; j<m1.NumColumnas(); j++)
			m3.Valor(i,j) = m1.Valor(i,j) + m2;
	return m3;
}

// Recibe una matriz y un valor y devuelve la suma de 
// la matriz y el valor en todas sus casillas.
Matriz2D operator + (const TipoBaseMatriz & m1, const Matriz2D & m2)
{
	Matriz2D m3(m2.NumFilas(), m2.NumColumnas());
	for(int i=0; i<m2.NumFilas(); i++)
		for(int j=0; j<m2.NumColumnas(); j++)
			m3.Valor(i,j) = m1 + m2.Valor(i,j);
	return m3;
}

/***********************************************************************/
/***********************************************************************/
// Operador binario -
// Recibe dos matrices y devuelve la resta de ellas.
// Si no tienen las mismas dimensiones devuelve una matriz vacía.
Matriz2D operator - (const Matriz2D & m1, const Matriz2D & m2)
{
	Matriz2D m3;
	if(m1.NumFilas() == m2.NumFilas() && m1.NumColumnas() == m2.NumColumnas())
	{
		m3.ReservarMemoria(m1.NumFilas(), m1.NumColumnas());
		for(int i=0; i<m1.NumFilas(); i++)
			for(int j=0; j<m1.NumColumnas(); j++)
				m3.Valor(i,j) = m1.Valor(i,j) - m2.Valor(i,j);
	}
	return m3;
}

// Recibe una matriz y un valor y devuelve la resta de
// la matriz y el valor en todas sus casillas.
Matriz2D operator - (const Matriz2D & m1, const TipoBaseMatriz & m2)
{
	Matriz2D m3(m1.NumFilas(), m1.NumColumnas());
	for(int i=0; i<m1.NumFilas(); i++)
		for(int j=0; j<m1.NumColumnas(); j++)
			m3.Valor(i,j) = m1.Valor(i,j) - m2;
	return m3;
}

// Recibe una matriz y un valor y devuelve la resta de
// la matriz y el valor en todas sus casillas.
Matriz2D operator - (const TipoBaseMatriz & m1, const Matriz2D & m2)
{
	Matriz2D m3(m2.NumFilas(), m2.NumColumnas());
	for(int i=0; i<m2.NumFilas(); i++)
		for(int j=0; j<m2.NumColumnas(); j++)
			m3.Valor(i,j) = m1 - m2.Valor(i,j);
	return m3;
}



// Operadores combinados += y -=
Matriz2D & Matriz2D::operator += (const TipoBaseMatriz & valor)
{
	for(int i=0; i<fils; i++)
		for(int j=0; j<cols; j++)
			datos[i][j] += valor;
	return (*this);
}
Matriz2D & Matriz2D::operator -= (const TipoBaseMatriz & valor)
{
	for(int i=0; i<fils; i++)
		for(int j=0; j<cols; j++)
			datos[i][j] -= valor;
	return (*this);
}

/***********************************************************************/
// Metodos de consulta de dimensiones

int Matriz2D:: NumFilas() const{
	return fils;
}

int Matriz2D :: NumColumnas() const{
	return cols;
}

/***********************************************************************/
// Metodo que consulta si esta vacia

bool Matriz2D :: EsVacia() const{
	return (fils == 0 or cols == 0 or datos == 0);
}

/***********************************************************************/
// Metodo que elimina todos los elementos de la matriz

void Matriz2D :: EliminaTodos(){
	LiberarMemoria();
}

//Ecualizar. Cambia todos los todos valores de la matriz por valor.
void Matriz2D :: Ecualiza(TipoBaseMatriz valor){
	for (int i = 0; i < fils; i++)
		for (int j = 0; j < cols; j++)
			datos[i][j] = valor;
}

/***********************************************************************/
// Metodo que consulta el valor de una casilla de la matriz
TipoBaseMatriz & Matriz2D :: Valor(int i, int j){
	return datos[i][j];
}

/***********************************************************************/
// Metodo que consulta el valor de una casilla de la matriz
TipoBaseMatriz & Matriz2D :: Valor(int i, int j) const{
	return datos[i][j];
}


//Metodo de copia profunda
void Matriz2D :: Clona(const Matriz2D &m){
	LiberarMemoria();
	ReservarMemoria(m.fils, m.cols);
	CopiarDatos(m);
}

/***********************************************************************/
// Compone un string con todos los caracteres que están
// almacenados en la secuencia y lo devuelve.
string Matriz2D :: ToString(){
	string cad;

	string delimitador = "..................................";

	cad = "\n" + delimitador + "\n";
	cad = cad + "Filas = " + to_string(fils) + 
	      ", Columnas = " + to_string (cols) + "\n\n";

	for (int f=0; f<fils; f++) {
		cad = cad + "Fila " + to_string(f) + " --> ";
		
		for (int c=0; c<cols; c++) 
			cad = cad + to_string(datos[f][c]) + "  ";
		cad = cad + "\n";
	}
	cad = cad + delimitador + "\n\n";

	return (cad);
}

/***********************************************************************/
//Comparación. Devuelve true si la matriz a comparar es igual a esta
//(dimensiones y contenidos).
bool Matriz2D :: EsIgualA(const Matriz2D &m) const{
	bool igual = true;

	if (fils != m.fils or cols != m.cols)
		igual = false;
	else {
		for (int i = 0; i < fils and igual; i++)
			for (int j = 0; j < cols and igual; j++)
				if (datos[i][j] != m.datos[i][j])
					igual = false;
	}
	return igual;
}

/***********************************************************************/
//Eliminar fila. Elimina la fila num_fila de la matriz matriz

void Matriz2D :: EliminaFila(int num_fila){
	if(num_fila>=0 && num_fila<fils)
	{
		for(int i=num_fila; i<fils-1; i++)
		{
			//matriz.datos[i] = matriz.datos[i+1];
			memmove(datos[i], datos[i+1],
			sizeof(TipoBaseMatriz)*(fils));
		}

		delete [] datos[fils-1];
		fils-=1;
	}
}

/***********************************************************************/
//Eliminar columna. Elimina la columna num_col de la matriz matriz.

void Matriz2D :: EliminaColumna(int num_col){
	if(num_col>=0 && num_col<cols)
	{
		for(int i=0; i<fils; i++)
		{
			TipoBaseMatriz * p = datos[i];
			memmove(p+num_col, p+num_col+1, 
			sizeof(TipoBaseMatriz)*(cols-num_col-1));
		}
	}
	cols -= 1;
}

/***********************************************************************/
// Añadir una fila. La fila nueva (una dato Secuencia) debe tener el
// mismo número de casillas que columnas tenga la matriz.

void Matriz2D :: Aniade (const Secuencia & fila_nueva){
	if(fila_nueva.TotalUtilizados() == cols)
	{
		datos[fils] = new TipoBaseMatriz[cols];
		for(int i=0; i<cols; i++)
			datos[fils][i] = fila_nueva.Valor(i);
		fils++;
	}
}

/***********************************************************************/
/*
Método para insertar una fila en una posición dada. La fila nueva (una dato
Secuencia) debe tener el mismo número de casillas que columnas tenga la
matriz. La posición indicada será la posición que tendrá la fila 
después de la inserción.
*/

void Matriz2D::Inserta (int indice, const Secuencia & fila_nueva){
	if(fila_nueva.TotalUtilizados() == cols)
	{
		datos[fils] = new TipoBaseMatriz[cols];
		//Mover todas las filas una posición hacia abajo
		for(int i=fils; i>indice; i--)
		{
			memmove(datos[i], datos[i-1],
			sizeof(TipoBaseMatriz)*(fils));
		}
		for(int i=0; i<cols; i++)
			datos[indice][i] = fila_nueva.Valor(i);
		
		fils++;
		
		
	}
}

/***********************************************************************/
/*
Método que devuelve un objeto de la clase. Se trata de obtener una submatriz de
la matriz implícita y devolverla. La submatriz es una zona rectangular de la matriz
implícita que empieza en la casilla de coordenadas (fila_inic, col_inic) y
que tiene (un máximo de) num_filas filas y num_cols columna
*/
Matriz2D Matriz2D::SubMatriz(int fila_inicio, int fila_fin, int col_inicio, 
int col_fin)
{
	Matriz2D submatriz(fila_fin-fila_inicio+1, col_fin-col_inicio+1);
	for(int i=fila_inicio; i<=fila_fin; i++)
	{
		for(int j=col_inicio; j<=col_fin; j++)
		{
			submatriz.datos[i-fila_inicio][j-col_inicio] = datos[i][j];
		}
	}
	return submatriz;
}

/***********************************************************************/
/*
Métodos que devuelven un objeto de otra clase. Se trata de obtener una fi-
la/columna completa. El objeto devuelto será de la clase Secuencia:
*/
Secuencia Matriz2D::Fila(int indice)
{
	Secuencia fila(cols);
	for(int i=0; i<cols; i++)
	{
		fila.Aniade(datos[indice][i]);
	}
	return fila;
}

Secuencia Matriz2D::Columna(int indice)
{
	Secuencia columna(fils);
	for(int i=0; i<fils; i++)
	{
		columna.Aniade(datos[i][indice]);
	}
	return columna;
}

//Espejos verticales y horizontales
//Espejo horizontal. Cambia de orden las filas de matriz (la primera
//pasa a ser la última y la última la primera, la segunda la penúltima y la
//penúltima la segunda, etc.).
void Matriz2D::EspejoHorizontal ()
{
	for(int i=0; i<fils/2; i++)
	{
		Intercambia(datos[i], datos[fils-i-1]);
	}
};

//Espejo vertical. Cambia de orden las columnas de matriz (la primera
//pasa a ser la última y la última la primera, la segunda la penúltima y la
//penúltima la segunda, etc.).
void Matriz2D::EspejoVertical ()
{
	for(int i=0; i<fils; i++)
	{
		for(int j=0; j<cols/2; j++)
		{
			Intercambia( datos[i][j], datos[i][cols-j-1]);
		}
	}
};

void Matriz2D::Intercambia(TipoBaseMatriz * & a, TipoBaseMatriz * & b)
{
	TipoBaseMatriz * aux = a;
	a = b;
	b = aux;
}

void Matriz2D::Intercambia(TipoBaseMatriz &a, TipoBaseMatriz &b)
{
	TipoBaseMatriz aux = a;
	a = b;
	b = aux;
}


////////////////////////////////////////////////////////////////////////
// PRIVATE

void Matriz2D :: ReservarMemoria (int nfils, int ncols)
{

	// Por defecto, matriz vacía
	datos = 0;
	fils  = 0;
	cols  = 0;

	// Solo si se cumplen las precondiciones se reserva memoria 

	if (nfils>0 && ncols>0) {

		// "matriz" apuntará a un vector de punteros a las filas
		datos = new int * [nfils];

		for (int f=0; f<nfils; f++) {

			// "matriz[f]" apuntará a un vector de datos int
			datos[f] = new int [ncols];
		}

		fils = nfils;
		cols = ncols;
	}

}

void Matriz2D::LiberarMemoria()
{
	if (datos) {

		//for (int f=0; f<fils; f++)
			//delete  datos[f];
		
		delete []datos;

		datos = 0;
		fils  = 0;
		cols  = 0;
	}
}

void Matriz2D::CopiarDatos(const Matriz2D &m)
{
	for (int f=0; f<fils; f++)
		for (int c=0; c<cols; c++)
			datos[f][c] = m.datos[f][c];
}