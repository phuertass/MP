/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Proyecto Gestion de marcas de atletismo
//
// Declaraci�n del tipo "VectorMarcas"y de las funciones de gesti�n.
// Implementaciones en VectorMarcas.cpp
//
//  
// Fichero: VectorMarcas.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef VECTORMARCAS_H
#define VECTORMARCAS_H


#include "RegistroDeMarca.h"
#include "utils.h"
#include <string>
using namespace std; 



/***************************************************************************/
/***************************************************************************/


// Capacidad inicial 
const int TAM_INICIAL = 10; 

// Tamanio del bloque para redimensionar
const int TAM_BLOQUE = 5;

typedef RegistroDeMarca TipoBaseVector;	// Tipo de los elementos de la estructura din�mica

class VectorMarcas{
	private:

		string nombre;

		RegistroDeMarca * las_marcas;

		int num_marcas;

		int capacidad;

	public:
	/***************************************************************************/
	/***************************************************************************/
	// Constructores

	// Crear vector din�mico
	// Par�metros: capacidad_inicial, n�mero de casillas con las que se crea el
	// vector.
	// 		   tipo, el tipo de redimensi�n que se va a aplicar.
	// Devuelve: el vector din�mico creado.
	// POST: El n�mero de casillas usadas es 0
	//       El n�mero de casillas reservadas es "capacidad_inicial"
	//       El n�mero tipo de redimensi�n es "tipo"

	VectorMarcas (int capacidad_inicial=TAM_INICIAL, string n="");

	/**
	 * @brief Constructor de copia 
	 * @param v VectorMarcas a copiar
	 */

	VectorMarcas (const VectorMarcas & v);

	/**
 	* @brief Constructor a partir de un fichero
 	* 
 	* @param nombre : ficHero de tipo PRUEBA
	* @param nombre_prueba (opcional) : nombre de la prueba
 	* @return VectorMarcas 
 	*/	
	VectorMarcas (const string &nombre);
	VectorMarcas (const string & nombre_fichero_marcas,
	const string & nombre_prueba);
	

	/**
	 * @brief Destroy the Vector Marcas object
	 * 
	 */
	~VectorMarcas();

	/**
	 * @brief Sobrecarga del operador =
	 * 
	 * @param v : VectorMarcas a copiar
	 * @return VectorMarcas& 
	 */
	VectorMarcas & operator=(const VectorMarcas & v);
	/***************************************************************************/
	/***************************************************************************/
	// Calcula el n�mero de casillas usadas de un vector din�mico.
	// Par�metros: v, el vector que se va a consultar.
	// Devuelve: el n�mero de casillas usadas de un vector din�mico

	int UsadosVectorMarcas ();

	/***************************************************************************/
	/***************************************************************************/
	// Calcula el n�mero de casillas reservadas de un vector din�mico.
	// Recibe: v, el vector que se va a consultar.
	// Devuelve: el n�mero de casillas reservadas de un vector din�mico

	int CapacidadVectorMarcas (); 

	/***************************************************************************/
	/***************************************************************************/
	// Deja el vector din�mico vac�o
	// Par�metros: v (referencia) El vector que se va "vaciar"
	// POST: El n�mero de casillas usadas es 0

	void EliminaTodosVectorMarcas ();

	/***************************************************************************/
	/***************************************************************************/
	// Inicializa el vector din�mico copiando en todas las casillas "valor" 
	// Par�metros: 	v (referencia) El vector que se va inicializar
	//				valor, el valor que se va a copiar en todas las casillas.

	void EcualizaVectorMarcas (const TipoBaseVector valor);

	/***************************************************************************/
	/***************************************************************************/
	// Copia profunda. Hace una copia profunda de "origen" en "destino".
	// Argumentos: destino (referencia), el vector que recibe la copia. 
	//             origen (referencia), el vector del que se hace la copia. 

	void Clona (const VectorMarcas & origen);

	/***************************************************************************/
	/***************************************************************************/
	// Serializa un dato de tipo "VectorMarcas"
	// Recibe: v, el vector que se va a serializar.

	//string ToString ();

	/***************************************************************************/
	/***************************************************************************/
	// A�ade un valor al vector din�mico
	// Recibe: 	
	//		v (referencia), referencia al vector que se va a modificar. 
	//		valor, valor que se va a a�adir al vector. 
	// PRE: hay espacio disponible en el vector din�mico

	void AniadeVectorMarcas (const TipoBaseVector valor);

	/***************************************************************************/
	/***************************************************************************/
	// Consulta � modifica el valor de una casilla dada. Si se utiliza como 
	// rvalue se emplea para consultar el valor de la casilla "num_casilla". 
	// Si se utiliza como lvalue se emplea para modificar el valor de la 
	// casilla num_"casilla".
	// 
	// PRE: 0<=num_casilla<UsadosVectorMarcas(v)

	TipoBaseVector & ValorVectorMarcas (const int num_casilla);

	/***************************************************************************/
	/***************************************************************************/
	// Inserci�n. Inserta un valor en una posici�n dada. Los valores que est�n 
	// desde esa posici�n (incluida) hasta la �ltima se �desplazan� una posici�n 
	// hacia �ndices mayores.
	// Si el vector din�mico estuviera lleno se tiene que redimensionar (de 
	// acuerdo al tipo de redimensi�n establecido) para poder acoger a "valor". 

	void InsertaVectorMarcas (const TipoBaseVector valor, 
								const int num_casilla);

	/***************************************************************************/
	/***************************************************************************/
	// Borrado. Elimina un valor en una posici�n dada. Los valores que est�n 
	// desde la posici�n siguiente a la dada hasta la �ltima se �desplazan� una 
	// posici�n hacia �ndices menores. 
	//
	// PRE: 0<=num_casilla<UsadosVectorMarcas(v)

	void EliminaVectorMarcas (const int num_casilla);

	/***************************************************************************/
	/***************************************************************************/
	// Redimensiona el vector din�mico "v" de acuerdo al tipo de redimensi�n 
	// registrado en "v". 
	// Adem�s, copia todos los datos en el nuevo vector.  
	// Par�metros: 	
	//		v (referencia), referencia al vector que se va a redimensionar. 
				
	void  RedimensionaVectorMarcas ();

	/***************************************************************************/
	/***************************************************************************/
	// Redimensiona un vector din�mico para que no haya espacio libre.
	// Copia todos los datos en el nuevo vector.
	// POST: capacidad = usados

	void  ReajustaVectorMarcas ();

	/***************************************************************************/
	//Getters y Setters de la clase VectorMarcas

	string GetNombre();
	void SetNombre(string n);

	/***************************************************************************/
	int GetNum_marcas();
	void setNum_marcas(int n);

	/***************************************************************************/
	TipoBaseVector operator()(int n);
	TipoBaseVector operator[](int n);

	/***************************************************************************/
	int GetCapacidad();

	//Funciones de ordenacion
	void OrdenarPorTiempos(const bool asc=true);
	void OrdenarPorNombre(const bool asc=true);
	void OrdenarPorFecha(const bool asc=true);

	/**
	 * @brief Suma binaria de dos vectores
	 * Se concatenan los valores de ambos
	 * @param v : vector a sumar
	 * @param v2 : vector a sumar
	 * @return VectorMarcas 
	 */
	friend VectorMarcas operator+(const VectorMarcas &v, const VectorMarcas &v2);

	/**
 	* @brief Suma binaria de VectorMarcas + RegistroDeMarca
 	* 
 	* @param v : VectorMarcas
 	* @param r : RegistroDeMarca
 	* @return VectorMarcas 
 	*/
	friend VectorMarcas operator+(const VectorMarcas &v, const RegistroDeMarca &r);
	friend VectorMarcas operator+(const RegistroDeMarca &r, const VectorMarcas &v);

	/**
 	* @brief Resta binaria de un vector y una licencia
 	* Se devuelve un nuevo vector sin los registros con licencia == n
 	* 
 	* @param v : VectorMarcas
 	* @param n : string
 	* @return VectorMarcas 
 	*/
	friend VectorMarcas operator-(const VectorMarcas &v, const string &n);

	/**
	 * @brief Sobrecarga del operador +=
	 * Se añaden todos los registros del segundo en el primero
	 * @param v : VectorMarcas a sumar
	 * @return VectorMarcas& 
	 */
	VectorMarcas & operator+=(const VectorMarcas &v);

	/**
	 * @brief Sobrecarga del operador +=
	 * Se añade el registro al vector
	 * @param r : RegistroDeMarca a sumar
	 * @return VectorMarcas& 
	 */
	VectorMarcas & operator+=(const RegistroDeMarca &r);

	/**
	 * @brief Sobrecarga del operador -=
	 * Elimina todos los registros con licencia == n
	 * @param n : string
	 * @return VectorMarcas& 
	 */
	VectorMarcas & operator-=(const string &n);

	/**
	 * @brief Sobrecarga del operador <<
	 * 
	 * @param os : flujo de salida
	 * @param v : VectorMarcas
	 * @return ostream& 
	 */
	friend ostream & operator << (ostream &os, const VectorMarcas &v);

	/**
	 * @brief Sobrecarga del operador >>
	 * 
	 * @param is : flujo de entrada
	 * @param v : VectorMarcas
	 * @return istream& 
	 */
	friend istream & operator >> (istream &is, VectorMarcas &v);

	bool EstaVacio();

	/**
	 * @brief Metodo de escritura en fichero
	 * Guarda un dato VectorMarcas en un fichero de texto llamado nombre. El
		fichero será un fichero de prueba.
	 * 
	 * @param nombre : nomre del fichero
	 * 
	 * @cond Si el vector esta vacio no se crea el fichero
	 * @cond El vector no se modifica
	 */
	void EscribirVectorMarcas (const string & nombre) const;

	/**
	 * @brief Metodo de lectura de fichero
	 * Lee un dato VectorMarcas de un fichero de texto llamado nombre. El
	 * fichero será un fichero de prueba.
	 * @param nombre : nombre del fichero
	 */
	void LeerVectorMarcas (const string & nombre);

	private: 
		/**
		 * @brief Reserva memoria para una capacidad dada
		 * 
		 * @param capacidad_inicial : tamaño inicial del vector
		 */
		void ReservaMemoria(int capacidad_inicial=TAM_INICIAL);

		/***************************************************************************/
		/***************************************************************************/
		// Libera la memoria ocupada por un vector din�mico
		// Par�metros: v (referencia) El vector que se va liberar.
		// POST: El n�mero de casillas usadas es 0
		//       El n�mero de casillas reservadas es 0
		void LiberaVectorMarcas ();

		/**
		 * @brief Copia los datos desde un vector explicito origen al implicito
		 * 
		 * @param origen : vector explicito a copiar
		 */
		void CopiarDatos (const VectorMarcas & origen);

		/**
		 * @brief Devuelve un objeto RegistroDeMarca a partir de una posicion
		 * 
		 * @param n : posicion del vector
		 * @return TipoBaseVector 
		 */
		TipoBaseVector GetMarca(int n);

		/**
		 * @brief Intercambia los elementos de dos posiciones
		 * 
		 * @param i : posicion 1
		 * @param j : posicion 2
		 */
		void Intercambia(int i, int j);

};


#endif
