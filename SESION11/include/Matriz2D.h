/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Fichero de cabecera de la clase Matriz2D
//
// Implementaci�n en Matriz2D.cpp
//
// Fichero: Matriz2D.h
//
/***************************************************************************/
#ifndef CLASS_MATRIZ2D
#define CLASS_MATRIZ2D

#include "Secuencia.h"
#include "TipoBaseMatriz.h"

#include <string>
using namespace std;

/////////////////////////////////////////////////////////////////////////////

class Matriz2D {

private:
 
	// Núm.casillas disponibles (capacidad) por defecto
    static const int TAMANIO = 50; 

	// Si el porcentaje de casillas usadas > PORC_PETICION --> Crecimiento
    static const int PORC_PETICION = 75; 
	// La capacidad aumenta PORC_CRECIMIENTO sobre la capacida actual
    static const int PORC_CRECIMIENTO = 10; 
	// El valor mínimo de casillas para el crecimiento será MIN_CRECIMIENTO
    static const int MIN_CRECIMIENTO = 5; 

	// Si el porcentaje de casillas usadas < PORC_REDUCCION --> Decrecimiento
    static const int PORC_REDUCCION = 50; 
	// La capacidad queda PORC_EXTRA sobre la ocupación actual
    static const int PORC_EXTRA = 20; 


	// "vector_privado" es un puntero a un array dinámico de 
	// datos "TipoBaseMatriz"
    TipoBaseMatriz ** datos;	// Puntero a vector de punteros a los datos
	int fils;			// Num. de filas
	int cols; 			// Num. de columnas

    
public:

    /***********************************************************************/
    //Constructor sin argumentos, que crea una matriz vacía
	Matriz2D();
	
    /***********************************************************************/
    // Constructor con un argumento, que crea una matriz cuadrada con el 
	//número de filas y columnas indicado en el argumento.

    Matriz2D(int n);

	/***********************************************************************/
	//Constructor con tres argumentos, que crea una matriz con el número de 
	//filas indicado en el primer argumento y con el número de columnas 
	//indicado en el segundo argumento. Además inicia todas las casillas de la 
	//matriz al valor especificado con el tercer argumento.

	Matriz2D(int fils, int cols, TipoBaseMatriz valor=VALOR_DEF);

	/***********************************************************************/
	//Constructor de copia

	Matriz2D(const Matriz2D &m);

	/***********************************************************************/
	// Destructor

	~Matriz2D();

	/***********************************************************************/
	// Sobrecarga de operadores

    /***********************************************************************/
    // Metodo de acceso individual a elementos: operator ()
    // Metodo de escritura / lectura
    // PRE: 1 <= indice <= TotalUtilizados()
    
    TipoBaseMatriz & operator () (const int fila, const int columna);     
    TipoBaseMatriz & operator () (const int fila, const int columna) const;


	/***********************************************************************/
	/***********************************************************************/
	// Operador de asignación desde otro dato Matriz2D
	// Parámetros: otra (referencia), objeto que sirve de modelo. 

	Matriz2D & operator = (const Matriz2D & otro);
	Matriz2D & operator = (const TipoBaseMatriz & otro);

	/***********************************************************************/
	/***********************************************************************/
	// Operador == 
	// Dos datos Matriz2D son iguales si tienen el mismo número de filas,
	// columnas y los contenidos son iguales y en las mismas posiciones 
	bool operator == (const Matriz2D & otro) const; 

	/***********************************************************************/
	/***********************************************************************/
	// Operador unario +
	// Devuelve una copia del objeto.
	Matriz2D & operator + (const Matriz2D & otro);

	/***********************************************************************/
	/***********************************************************************/
	// Operador unario -
	// Devuelve una copia del objeto.
	Matriz2D & operator - (const Matriz2D & otro);

	/***********************************************************************/
    // Operador binarios de adición y borrado

    friend Matriz2D operator + (const Matriz2D & m1, 
                                 const Matriz2D & m2);
    friend Matriz2D operator + (const Matriz2D & m, 
                                 const TipoBaseMatriz & valor);
    friend Matriz2D operator + (const TipoBaseMatriz & valor, 
                                 const Matriz2D & m);
	
	friend Matriz2D operator - (const Matriz2D & m1,
								 const Matriz2D & m2);
	friend Matriz2D operator - (const Matriz2D & m, 
								 const TipoBaseMatriz & valor);
	friend Matriz2D operator - (const TipoBaseMatriz & valor, 
								 const Matriz2D & m);
	
	// Operadores combinados += y -=
	Matriz2D & operator += (const TipoBaseMatriz & valor);
	Matriz2D & operator -= (const TipoBaseMatriz & valor);

	/***********************************************************************/
	/***********************************************************************/
	// Operador !=
	// Dos datos Matriz2D son distintos si no tienen el mismo número de
	// filas, columnas o los contenidos son distintos en las mismas 
	//posiciones
    bool operator != (const Matriz2D & otro) const; 

	/***********************************************************************/
	// Metodos de consulta de dimensiones

	int NumFilas() const;
	int NumColumnas() const;

	/***********************************************************************/
	// Metodo que consulta si esta vacia

	bool EsVacia() const;

	/***********************************************************************/
	// Metodo que elimina todos los elementos de la matriz

	void EliminaTodos();
   
    /***********************************************************************/
    // Compone un string con todos los caracteres que están
    // almacenados en la secuencia y lo devuelve.

    string ToString();

	/***********************************************************************/
	//Eliminar fila. Elimina la fila num_fila de la matriz matriz
	void EliminaFila (int num_fila);

	/***********************************************************************/
	//Eliminar columna. Elimina la columna num_col de la matriz matriz.
	void EliminaColumna (int num_col);

	/***********************************************************************/
	// Añadir una fila. La fila nueva (una dato Secuencia) debe tener el
	// mismo número de casillas que columnas tenga la matriz.

	void Aniade ( const Secuencia & fila_nueva);

	/***********************************************************************/
	/*
	Método para insertar una fila en una posición dada. La fila nueva (una dato
	Secuencia) debe tener el mismo número de casillas que columnas tenga la
	matriz. La posición indicada será la posición que tendrá la fila 
	después de la inserción.
	*/

	void Inserta (int indice, const Secuencia & fila_nueva);

	/***********************************************************************/
	/*
	Métodos que devuelven un objeto de otra clase. Se trata de obtener una fi-
	la/columna completa. El objeto devuelto será de la clase Secuencia:
	*/
	Secuencia Fila (int indice);
	Secuencia Columna (int indice);

	/***********************************************************************/
	/*
	Método que devuelve un objeto de la clase. Se trata de obtener una submatriz de
	la matriz implícita y devolverla. La submatriz es una zona rectangular de la matriz
	implícita que empieza en la casilla de coordenadas (fila_inic, col_inic) y
	que tiene (un máximo de) num_filas filas y num_cols columna
	*/
	Matriz2D SubMatriz (int fila_inic, int col_inic,
	int num_filas, int num_cols);

    /***********************************************************************/

	//Espejos verticales y horizontales

	//Espejo vertical. Cambia de orden las columnas de matriz (la primera
	//pasa a ser la última y la última la primera, la segunda la penúltima y la
	//penúltima la segunda, etc.).
	void EspejoVertical();

	//Espejo horizontal. Cambia de orden las filas de matriz (la primera
	//pasa a ser la última y la última la primera, la segunda la penúltima y la
	//penúltima la segunda, etc.).
	void EspejoHorizontal();



private:

    /***********************************************************************/

	// Pide memoria para guardar "num_casillas" datos	

	void ReservarMemoria (const int fils, const int cols);

    /***********************************************************************/
	// Libera memoria

	void LiberarMemoria (void);

    /***********************************************************************/
	// Copiar datos desde otro objeto de la clase
	// PRE: Se ha reservado memoria para los datos

	void CopiarDatos (const Matriz2D & otro); 

    /***********************************************************************/
		/***********************************************************************/
	// Metodo que inicializa todas las casillas de la matriz a un valor
	// especificado en el argumento, si no se especifica ningun valor, se
	// inicializan todas las casillas a VALOR_DEF

	void Ecualiza(TipoBaseMatriz valor = VALOR_DEF);

	/***********************************************************************/
	// Metodo que consulta el valor de una casilla de la matriz

	TipoBaseMatriz & Valor(int fil, int col);
	TipoBaseMatriz & Valor(int fil, int col) const;

	/***********************************************************************/
	// Metodo de copia profunda

	void Clona(const Matriz2D &m);

	void Intercambia(TipoBaseMatriz * &a, TipoBaseMatriz * &b);
	void Intercambia(TipoBaseMatriz &a, TipoBaseMatriz &b);

	/***********************************************************************/
	//Comparación. Devuelve true si la matriz a comparar es igual a esta
	//(dimensiones y contenidos).

	bool EsIgualA(const Matriz2D &m) const;


};

/////////////////////////////////////////////////////////////////////////////

#endif
