/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// RELACION DE PROBLEMAS 2
//
// Declaraci�n del tipo "VectorDinamico" y de las funciones b�sicas para 
// su gesti�n. 
//
// Implementaciones en VectorDinamico_basico.cpp
//  
// Fichero: VectorDinamico_basico.h
//
/***************************************************************************/
 
#ifndef VECTOR_DINAMICO
#define VECTOR_DINAMICO

#include <string>
using namespace std; 

/***************************************************************************/
/***************************************************************************/

// Capacidad inicial 
const int TAM_INICIAL = 10; 

// Tamanio del bloque para redimensionar
const int TAM_BLOQUE = 5;

// Valor por defecto para los valores del vector
const int VALOR_DEF = 0;


// Tipo enumerado para representar tipos de redimensionamiento
enum class TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};

typedef int TipoBase; // Tipo de los datos almacenados

typedef struct {
	TipoBase * datos; // Puntero para acceder a los datos

	int usados; // Num. casillas usadas

	int capacidad; // Num. casillas reservadas

	// PRE: 0 <= usados <= capacidad
	// Inicialmente, capacidad = TAM_INICIAL
	TipoRedimension tipo_redim; // Modelo de crecimiento

} VectorDinamico;

/***************************************************************************/
/***************************************************************************/
// Crear vector din�mico
// Argumentos: 
//	capacidad_inicial, n�mero de casillas con las que se crea el vector.
// 		   tipo, el tipo de redimensi�n que se va a aplicar. 
// Devuelve: el vector din�mico creado.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es "capacidad_inicial"

VectorDinamico CreaVectorDinamico (int cap_inic=TAM_INICIAL,
TipoRedimension tipo=TipoRedimension::EnBloques);

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector din�mico
// Argumentos: v (referencia) El vector que se va liberar.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es 0

void LiberaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Deja el vector din�mico vac�o
// Argumentos: v (referencia) El vector que se va "vaciar"
// POST: El n�mero de casillas usadas es 0

void EliminaTodosVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas usadas de un vector din�mico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas usadas de un vector din�mico

int UsadosVectorDinamico (const VectorDinamico v);

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas reservadas de un vector din�mico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas reservadas de un vector din�mico

int CapacidadVectorDinamico (const VectorDinamico v); 

/***************************************************************************/
/***************************************************************************/
// Serializa un dato de tipo "VectorDinamico"
// Argumentos: v (referencia), el vector que se va a serializar.

string ToString (const VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// A�ade un valor al vector din�mico
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a a�adir al vector. 
// PRE: hay espacio disponible en el vector din�mico

void AniadeVectorDinamico (VectorDinamico & v, const TipoBase valor);

/***************************************************************************/
/***************************************************************************/
// Consulta � modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consultar el valor de la casilla "num_casilla". 
// Si se utiliza como lvalue se emplea para modificar el valor de la 
// casilla num_"casilla".
// 
// Argumentos: 	
//		v (referencia), referencia al vector. 
//		num_casilla, n�mero de casilla (�ndice) en la que estamos interesados.
//
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

TipoBase & ValorVectorDinamico (const VectorDinamico & v, const int num_casilla);

/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector din�mico "v" de acuerdo al tipo de redimensi�n 
// registrado en "v". 
// Adem�s, copia todos los datos en el nuevo vector.  
// Argumentos: 	
//		v (referencia), referencia al vector que se va a redimensionar. 
			
void  RedimensionaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Redimensiona un vector din�mico para que no haya espacio libre.
// Copia todos los datos en el nuevo vector.
// Argumentos: 	
//		v (referencia), referencia al vector que se va a reajustar. 
// POST: capacidad = usados

void  ReajustaVectorDinamico (VectorDinamico & v);



//Copia profunda. Hace una copia profunda de origen en destino.
void Clona (VectorDinamico & destino,
const VectorDinamico & origen);

//Ecualización. Inicializa el vector dinámico, sustituyendo el contenido de to-
//das las casillas por el valor valor.
void EcualizaVectorDinamico (VectorDinamico & v,
const TipoBase valor);

//Inserción. Inserta un valor en una posición dada. Los valores que es-
//tán desde esa posición (incluida) hasta la última se “desplazan” una po-
//sición hacia índices mayores. Si el vector dinámico estuviera lleno se
//tiene que redimensionar (de acuerdo al tipo de redimensión estableci-
//do) para poder acoger al nuevo valor. Se establece la precondición:
//PRE: 0<=num_casilla<UsadosVectorDinamico(v)
void InsertaVectorDinamico (VectorDinamico &v,
const TipoBase valor, const int num_casilla);

//Borrado. Elimina un valor en una posición dada. Los valo-
//res que están desde la posición siguiente a la dada hasta
//la última se “desplazan” una posición hacia índices menores.
//PRE: 0<=num_casilla<UsadosVectorDinamico(v)
void EliminaVectorDinamico (VectorDinamico & v,
const int num_casilla);

//Borrado. Elimina los elementos repetidos
void EliminaRepetidosFisico(VectorDinamico & v);

//Borrado. Elimina los elementos repetidos con el metodo
//de los apuntadores
void EliminaRepetidosApuntadores(VectorDinamico & v);

//Funcion que devuelve true si valor se encuentra en v entre los extremos
//ext1 y ext2
bool Esta(const VectorDinamico & v, TipoBase valor, int ext1,int ext2);

//Metodo que mezcla los vectores y devuelve el vector de copia
VectorDinamico ObtenerCopiaMezclaVectores
(const VectorDinamico & v1, const VectorDinamico & v2,
const char * selectiva="no");

//Metodo para mezclar los vectores de forma selectiva si queremos
//eliminar los repetidos o de forma estandar si no
void MezclaVectores (VectorDinamico & mezcla,
const VectorDinamico & v1, const VectorDinamico & v2,
const char * selectiva="no");

//Funcion de ordenacion con el criterio pasado por el tercer argumento
VectorDinamico OrdenaIntercambio (VectorDinamico & v, bool (*f) (TipoBase a, TipoBase b)); 

void Intercambia(VectorDinamico & v, int a, int b);

bool MenorPrimero(TipoBase a, TipoBase b);

bool MayorPrimero(TipoBase a, TipoBase b);

/***************************************************************************/
/***************************************************************************/

#endif
