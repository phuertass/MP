/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// RELACION DE PROBLEMAS 2
//
// Declaraci�n del tipo "VectorDinamico"y de las funciones de gesti�n.
// Implementaciones en FuncsVectorDinamico.cpp
//
// Versi�n completa.
//  
// Fichero: FuncsVectorDinamico.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef VECTOR_DINAMICO
#define VECTOR_DINAMICO

#include "TipoBaseVector.h"
#include <string>
using namespace std; 

/***************************************************************************/
/***************************************************************************/
// Tipo enumerado para representar los tipos de redimensionamiento permitidos

enum class TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};

// Capacidad inicial 
const int TAM_INICIAL = 10; 

// Tamanio del bloque para redimensionar
const int TAM_BLOQUE = 5;

// Un "VectorDinamico" se representa (por ahora) con un struct  

typedef struct {

	TipoBaseVector * datos; 	// Puntero para acceder a los datos
	int usados;			// Num. casillas usadas
	int capacidad;		// NUm. casillas reservadas

	// PRE: 0 <= usados <= capacidad 
	// Inicialmente, capacidad = TAM_INICIAL

	TipoRedimension tipo_redimension; // M�todo de redimensi�n del conjunto.

} VectorDinamico;


/***************************************************************************/
/***************************************************************************/
// Prototipos de las funciones ofertadas: 
/*

VectorDinamico CreaVectorDinamico (int capacidad_inicial=TAM_INICIAL, 
 					 TipoRedimension tipo=TipoRedimension::EnBloques);

void LiberaVectorDinamico (VectorDinamico & v);

void  RedimensionaVectorDinamico (VectorDinamico & v);

void  ReajustaVectorDinamico (VectorDinamico & v);

int UsadosVectorDinamico (const VectorDinamico v);

int CapacidadVectorDinamico (const VectorDinamico v); 

void EcualizaVectorDinamico (VectorDinamico & v, const TipoBaseVectorVector valor);

void EliminaTodosVectorDinamico (VectorDinamico & v);

void Clona (VectorDinamico & destino, const VectorDinamico & origen);

string ToString (const VectorDinamico v);

TipoBaseVector & ValorVectorDinamico (VectorDinamico v, const int num_casilla);

void AniadeVectorDinamico (VectorDinamico & v, const TipoBaseVector valor);

void InsertaVectorDinamico (VectorDinamico & v, const TipoBaseVector valor, 
	                        const int num_casilla);

void EliminaVectorDinamico (VectorDinamico & v, const int num_casilla);

//...........................................................................

TipoRedimension LeeTipoRedimension (void);

void MuestraTipoRedimension (TipoRedimension);

//...........................................................................

TipoBaseVector TransformaATipoBaseVector (char * valor_cad);

void Intercambia (TipoBaseVector & r1, TipoBaseVector & r2);

//...........................................................................
// NUEVAS FUNCIONES

VectorDinamico ObtenerCopiaVectorDinamicoOrdenado (const VectorDinamico & v, 
	                                            const char * creciente="si");

void OrdenaVectorDinamico (VectorDinamico & v, const char * creciente="si");

void OrdenaVectorDinamicoCreciente (VectorDinamico & v);

void OrdenaVectorDinamicoDecreciente (VectorDinamico & v);

VectorDinamico ObtenerCopiaMezclaVectoresDinamicos (const VectorDinamico & v1, 
                      const VectorDinamico & v2, const char * selectiva="no");

void MezclaVectoresDinamicos (VectorDinamico &mezcla,const VectorDinamico &v1, 
                          const VectorDinamico & v2,  const char * selectiva);

void MezclaVectoresDinamicosTotal (VectorDinamico &v3,const VectorDinamico &v1, 
                                   const VectorDinamico & v2);

void MezclaVectoresDinamicosSelectiva (VectorDinamico & v3, 
	            const VectorDinamico & v1, const VectorDinamico & v2);

//...........................................................................
*/


/***************************************************************************/
/***************************************************************************/
// Crear vector din�mico
// Par�metros: capacidad_inicial, n�mero de casillas para crear el vector.
// 		   tipo, el tipo de redimensi�n que se va a aplicar. 
// Devuelve: el vector din�mico creado.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es "capacidad_inicial"
//       El n�mero tipo de redimensi�n es "tipo"

VectorDinamico CreaVectorDinamico (int capacidad_inicial=TAM_INICIAL, 
 					 TipoRedimension tipo=TipoRedimension::EnBloques);

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector din�mico
// Par�metros: v (referencia) El vector que se va liberar.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es 0

void LiberaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas usadas de un vector din�mico.
// Par�metros: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas usadas de un vector din�mico

int UsadosVectorDinamico (const VectorDinamico v);

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas reservadas de un vector din�mico.
// Recibe: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas reservadas de un vector din�mico

 int CapacidadVectorDinamico (const VectorDinamico v); 

/***************************************************************************/
/***************************************************************************/
// Deja el vector din�mico vac�o
// Par�metros: v (referencia) El vector que se va "vaciar"
// POST: El n�mero de casillas usadas es 0

void EliminaTodosVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Inicializa el vector din�mico copiando en todas las casillas "valor" 
// Par�metros: 	v (referencia) El vector que se va inicializar
//				valor, el valor que se va a copiar en todas las casillas.

void EcualizaVectorDinamico (VectorDinamico & v, const TipoBaseVector valor);

/***************************************************************************/
/***************************************************************************/
// Copia profunda. Hace una copia profunda de "origen" en "destino".
// Argumentos: destino (referencia), el vector que recibe la copia. 
//             origen (referencia), el vector del que se hace la copia. 

void Clona (VectorDinamico & destino, const VectorDinamico & origen);

/***************************************************************************/
/***************************************************************************/
// Serializa un dato de tipo "VectorDinamico"
// Recibe: v, el vector que se va a serializar.

string ToString (const VectorDinamico v);

/***************************************************************************/
/***************************************************************************/
// A�ade un valor al vector din�mico
// Recibe: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a a�adir al vector. 
// PRE: hay espacio disponible en el vector din�mico

void AniadeVectorDinamico (VectorDinamico & v, const TipoBaseVector valor);

/***************************************************************************/
/***************************************************************************/
// Consulta � modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consultar el valor de la casilla "num_casilla". 
// Si se utiliza como lvalue se emplea para modificar el valor de la 
// casilla num_"casilla".
// 
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

TipoBaseVector & ValorVectorDinamico (VectorDinamico v, const int num_casilla);

/***************************************************************************/
/***************************************************************************/
// Inserci�n. Inserta un valor en una posici�n dada. Los valores que est�n 
// desde esa posici�n (incluida) hasta la �ltima se �desplazan� una posici�n 
// hacia �ndices mayores.
// Si el vector din�mico estuviera lleno se tiene que redimensionar (de 
// acuerdo al tipo de redimensi�n establecido) para poder acoger a "valor". 

void InsertaVectorDinamico (VectorDinamico & v, const TipoBaseVector valor, 
	                        const int num_casilla);

/***************************************************************************/
/***************************************************************************/
// Borrado. Elimina un valor en una posici�n dada. Los valores que est�n 
// desde la posici�n siguiente a la dada hasta la �ltima se �desplazan� una 
// posici�n hacia �ndices menores. 
//
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

void EliminaVectorDinamico (VectorDinamico & v, const int num_casilla);

/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector din�mico "v" de acuerdo al tipo de redimensi�n 
// registrado en "v". 
// Adem�s, copia todos los datos en el nuevo vector.  
// Par�metros: 	
//		v (referencia), referencia al vector que se va a redimensionar. 
			
void  RedimensionaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Redimensiona un vector din�mico para que no haya espacio libre.
// Copia todos los datos en el nuevo vector.
// POST: capacidad = usados

void  ReajustaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Transforma "valor_cad" a TipoBaseVector

TipoBaseVector TransformaATipoBaseVector (char * valor_cad);

/***************************************************************************/
/***********************************************s****************************/
// Lee y devuelve el tipo de redimensionamiento que se emplear�.
// Devuelve: el valor del tipo enumerado apropiado al valor leido.

TipoRedimension LeeTipoRedimension (void);

/***************************************************************************/
/***************************************************************************/
// Muestra el tipo de redimensionamiento que se emplear�
// Recibe: el valor del tipo enumerado asociado al tipo de redimensi�n.

void MuestraTipoRedimension (TipoRedimension);
	
/***************************************************************************/
/***************************************************************************/
// Ordena el vector din�mico v y devuelve un nuevo vector din�mico que 
// contiene los datos de v ordenados. 
// El vector v no se modifica. 
// Los datos resultantes est�n en orden creciente (por defecto). 
// Si desea un orden decreciente deber� indicarlo de manera expl�cita 
// escribiendo como segundo argumento no, NO, No � incluso nO.

VectorDinamico ObtenerCopiaVectorDinamicoOrdenado (const VectorDinamico & v, 
	                                            const char * creciente="si");

/***************************************************************************/
/***************************************************************************/
// Ordena el vector din�mico v, modific�ndose su contenido (la ordenaci�n se 
// hace sobre el propio vector v). El segundo argumento sigue las mismas 
// normas que la versi�n anterior.
// Par�metros:
//		v (referencia), referencia al vector din�mico que se ordena. 
//		creciente, 

void OrdenaVectorDinamico (VectorDinamico & v, const char * creciente="si");

/***************************************************************************/
/***************************************************************************/
// Ordena (sentido creciente) el vector din�mico v. 
// Se modifica su contenido (la ordenaci�n se hace sobre el propio vector v). 
// Par�metros:
//		v (referencia), referencia al vector din�mico que se ordena. 

void OrdenaVectorDinamicoCreciente (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Ordena (sentido creciente) el vector din�mico v. 
// Se modifica su contenido (la ordenaci�n se hace sobre el propio vector v). 
// Par�metros:
//		v (referencia), referencia al vector din�mico que se ordena. 

void OrdenaVectorDinamicoDecreciente (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/

void Intercambia (TipoBaseVector & r1, TipoBaseVector & r2);


/***************************************************************************/
/***************************************************************************/
// Mezcla dos vectores din�micos ordenados y devuelve un nuevo vector 
// din�mico con el resultado de la mezcla. 
// La mezcla puede ser selectiva (sin valores repetidos) -por defecto- o no 
// (sin valores repetidos, solo se selecciona uno).  
// Par�metros: 	
//		v1 (referencia), referencia al primer vector din�mico. 
//		v2 (referencia), referencia al segundo vector din�mico. 
//      selectiva (referencia, par�metro OPCIONAL). Si su valor es "si", "SI", 
//             "Si" � "sI" la mezcla ser� selectiva (sin valores repetidos). 
//              La mezcla ser� completa (puede tener valores repetidos) si se 
//              llama con cualquier otro valor (o ninguno).
//
// PRE: "v1" y "v2" est�n ordenados
// POST: Los vectores v1 y v2 NO se modifican.

VectorDinamico ObtenerCopiaMezclaVectoresDinamicos (const VectorDinamico & v1, 
                      const VectorDinamico & v2, const char * selectiva="no");

/***************************************************************************/
/***************************************************************************/
// Mezcla dos vectores din�micos ordenados y devuelve el resultado de la 
// mezcla en otro vector din�mico que ya existe. 
// La mezcla puede ser selectiva (sin valores repetidos, solo se selecciona 
// uno de ellos) o no selectiva -por defecto- (puede contener repetidos).  
// Par�metros: 	
//		mezcla (referencia), referencia al vector din�mico con el resultado. 
//		v1 (referencia), referencia al primer vector din�mico que se mezcla. 
//		v2 (referencia), referencia al segundo vector din�mico que se mezcla.  
//      selectiva (referencia, par�metro OPCIONAL). Si su valor es "si", "SI", 
//             "Si" � "sI" la mezcla ser� selectiva (sin valores repetidos). 
//              La mezcla ser� completa (puede tener valores repetidos) si se 
//              llama con cualquier otro valor (o ninguno).
//
// PRE: "v1" y "v2" est�n ordenados
// POST: El contenido original de "mezcla" se pierde. Se sustituye por la 
//       mezcla de "v1" y "v2".  
// POST: Los vectores "v1" y "v2" NO se modifican.


void MezclaVectoresDinamicos (VectorDinamico &mezcla,const VectorDinamico &v1, 
                          const VectorDinamico & v2,  const char * selectiva);

/***************************************************************************/
/***************************************************************************/
// Mezcla no selectiva de dos vectores din�micos.
// La mezcla puede contener valores repetidos. 
// Par�metros: 	
//		mezcla (referencia), referencia al vector din�mico con el resultado. 
//		v1 (referencia), referencia al primer vector din�mico que se mezcla. 
//		v2 (referencia), referencia al segundo vector din�mico que se mezcla. 
// 
// PRE: "v1" y "v2" est�n ordenados
// POST: El contenido original de "mezcla" se pierde. Se sustituye por la 
//       mezcla de "v1" y "v2".  
// POST: Los vectores "v1" y "v2" NO se modifican.

void MezclaVectoresDinamicosTotal (VectorDinamico &v3,const VectorDinamico &v1, 
                                   const VectorDinamico & v2);

/***************************************************************************/
/***************************************************************************/
// Mezcla selectiva de dos vectores din�micos.
// En el caso de encontrar valores repetidos solo selecciona uno de ellos.
// Par�metros: 	
//		mezcla (referencia), referencia al vector din�mico con el resultado. 
//		v1 (referencia), referencia al primer vector din�mico que se mezcla. 
//		v2 (referencia), referencia al segundo vector din�mico que se mezcla. 
// 
// PRE: "v1" y "v2" est�n ordenados
// POST: El contenido original de "mezcla" se pierde. Se sustituye por la 
//       mezcla de "v1" y "v2".  
// POST: Los vectores "v1" y "v2" NO se modifican.

void MezclaVectoresDinamicosSelectiva (VectorDinamico & v3, 
	            const VectorDinamico & v1, const VectorDinamico & v2);

/***************************************************************************/
/***************************************************************************/

#endif
