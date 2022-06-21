/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Fichero de cabecera con declaraciones de los tipos "Nodo", "PNodo" 
// y "Lista", por un lado, y la declaraci�n de las funciones sobre �stos. 
// Declaraci�n de las funciones m�nimas que gestionan listas simples.
// Versi�n m�nima de la biblioteca.
// 
// Implementaci�n en Lista.cpp
//
// Fichero: Lista.h
//
/***************************************************************************/

#ifndef LISTAMINIMA
#define LISTAMINIMA

#include <string>
#include "TipoBaseLista.h"
#include "GeneradorAleatorioEnteros.h"

using namespace std; 


/***************************************************************************/
// Definiciones de tipos

// Cada nodo de la lista es de tipo "Nodo"

struct Nodo {	
   TipoBase info; 
   Nodo *sig; 
};

typedef Nodo * PNodo; 	// Para los punteros a nodos
typedef Nodo * Lista;	// Para la lista
/***************************************************************************/
/***************************************************************************/
// Crea una lista enlazada con "num_nodos" nodos. Inicializa todos los nodos 
// a un valor com�n, el indicado en el par�metro "valor". 
// La funcionalidad ser�a similar a la de un constructor.
// Par�metros:
//  	num_nodos, n�mero de nodos que se van a crear. 
//		valor, valor com�n que se copiar� en las casillas. 
// Devuelve: un dato de tipo Lista.
//
// PRE: num_nodos >= 0 
// NOTA: Si num_nodos==0 la lista queda vac�a. 

Lista CreaLista (int num_nodos=0, TipoBase valor=VALOR_DEF);

/***************************************************************************/
/***************************************************************************/
// Crea una lista enlazada con "num_valores" nodos. Inicializa todos los nodos 
// a un valor aleatorio 
// La funcionalidad ser�a similar a la de un constructor.
// Par�metros:
//  	num_nodos, n�mero de nodos que se van a crear. 
//		min_aleat, minimo valor para generar los numeros aleatorios
//		min_aleat, maximo valor para generar los numeros aleatorios
// Devuelve: un dato de tipo Lista.
//
// PRE: num_valores >= 0 
// NOTA: Si num_valores==0 la lista queda vac�a. 

Lista CreaListaAleatoria(int num_valores=0, int min_aleat=0, 
int max_aleat=100);

/***************************************************************************/
/***************************************************************************/
// "Destruye" una lista y la deja en un estado no �til (vac�a). 
// La funcionalidad ser�a similar a la de un destructor.
// Par�metros: 
//		l (referencia), la lista que va a "destruirse". 
// POST: La matriz queda vac�a (todos sus campos a cero)

void DestruyeLista (Lista & l);

/***************************************************************************/
/***************************************************************************/
//Ecualizar. Cambia todos los valores de la lista l y los fija todos iguales
//e iguales a valor.

void Ecualiza(Lista & l, TipoBase valor=VALOR_DEF);

/***************************************************************************/
/***************************************************************************/
// Devuelve el n�mero de nodos de una lista
// Par�metros: 
//		l (referencia), la lista que va a procesarse. 
// Devuelve: n�mero de nodos de la lista

int NumElementos (const Lista & l);

/***************************************************************************/
/***************************************************************************/
// Consulta si una lista est� vac�a (sin nodos)
// Par�metros: 
//		l (referencia), la lista que va a procesar. 
// Devuelve: true, si la lista est� vac�a
   
bool EstaVacia (const Lista & l);

/***************************************************************************/
/***************************************************************************/
// Devuelve un string con el resultado de ``serializar'' una lista.
// Par�metros: 
//		l (referencia), la lista que va a procesar. 

string ToString (const Lista & l);

/***************************************************************************/
/***************************************************************************/
// Consulta � modifica el valor de un nodo dado por su posici�n. 
// Si se utiliza como rvalue se emplea para consulta. Si se utiliza como 
// lvalue se emplea para modificaci�n.
//
// Par�metros: 
//		l (referencia), la lista que va a consultar/modificar. 
//		pos, posici�n de la lista a la que se accede.
//
// PRE: 1<= pos <= NumElementos (l)

TipoBase & Valor (const Lista & l, int pos);

/***************************************************************************/
/***************************************************************************/
// Elimina todos los valores. 
// Al finalizar, NumElementos(l)==0 EstaVacia(l)==true. 
// La lista, aunque vac�a, sigue ``activa''.

void  EliminaTodos (Lista & l);

/***************************************************************************/
/***************************************************************************/
// A�ade (al final de la lista) un nodo con el valor indicado en "valor". 
//
// Par�metros:
// 		l (referencia), lista resultante.
//		valor, el valor que se a�ade a la lista "l"

void Aniade (Lista & l, TipoBase valor);

/***************************************************************************/
/***************************************************************************/
// Comprueba si una lista est� ordenada.
// Par�metros: 
//	l (referencia) lista a comprobar
// Devuelve: true, si la lista est� ordenada

bool EstaOrdenada (const Lista l);

/***************************************************************************/
/***************************************************************************/
// Ordena una lista (algoritmo de seleccion).
// Par�metros: 
//	l (referencia) lista a ordenar.

void OrdenaSeleccion (Lista & l);
void OrdenaInsercion (Lista & l);
void OrdenaIntercambio (Lista & l);
void OrdenaIntercambioMejorado (Lista & l);

/***************************************************************************/
/***************************************************************************/
//Copia profunda. Hace una copia profunda de origen en destino.

void Clona(Lista & destino, const Lista & origen);

/***************************************************************************/
/***************************************************************************/
//Comparación. Devuelve true si las listas una y otra son exactamente 
//iguales (dimensiones y contenidos).

bool SonIguales (const Lista & una, const Lista & otra);

/***************************************************************************/
/***************************************************************************/
//Sublista. Extrae una lista de original y la deja en resultado. La
//lista resultado es una copia de una parte de original formada por
//un máximo de num_nodos nodos, formada a partir del nodo que ocupa
//la posición pos_inic de original.
//Considere todos los posibles casos entre num_nodos, pos_inic y el
//número de nodos de original y resuélvalos de la mejor manera posi-
//ble. Por ejemplo,
//• Si la lista original tiene 5 nodos, y le pedimos una sublista de 8 nodos
//desde la posición 3 sólo disponemos de tres (posiciones 3, 4 y 5). La
//función construirá y rellenará una lista de 3 nodos.
//• Sobre la misma lista, si pedimos una sublista de 6 nodos desde la
//posición 8, no podremos porque la posición inicial no está dentro de
//la lista. La función construirá y “rellenará” una lista vacía. Lo mismo
//ocurre si la posición inicial fuera, por ejemplo,-1.

void SubLista (Lista & resultado, const Lista & original,
int pos_inic, int num_nodos);

/***************************************************************************/
/***************************************************************************/
//Cambia todos los valores de una lista existente con numeros aleatorios
//comprendidos entre los valores indicados.

void RellenaAleatoriamente(Lista & l, int minimo_aleatorio , 
int max_aleatorio);

/***************************************************************************/
/***************************************************************************/
//Eliminar. Elimina el nodo que ocupa la posición pos.

void Elimina (Lista & l, int pos);

/***************************************************************************/
/***************************************************************************/
//Insertar. Inserta en la posición pos un nodo con el valor indicado en valor.
//El nuevo nodo ocupará la posición pos.

void Inserta (Lista & l, TipoBase valor, int pos);

/***************************************************************************/
/***************************************************************************/
//Invertir lista

void InvertirLista (Lista & l);

/***************************************************************************/
/***************************************************************************/
//Funcion para insertar un nuevo dato en su posición correcta. En
//el caso que la lista ya tuviera ese valor, se insertará el nuevo delante de la primera
//aparición.

void InsertaValorListaOrdenada (Lista &l, TipoBase v);

/***************************************************************************/
/***************************************************************************/
//Funcion para, dado un dato, eliminar la celda que lo contiene. En
//el caso que la lista tuviera ese valor repetido, se eliminará la primera aparición de
//éste.

void EliminaValorListaOrdenada (Lista &l, TipoBase v);


int PosicionListaOrdenada (const Lista &l, TipoBase v);

void MezclaListasClasico (Lista &l,
const Lista &l1, const Lista &l2);

void MezclaListas (Lista &l, Lista &l1, Lista &l2);

void Intercambia(Lista &l, int pos1, int pos2);
void Intercambia(Nodo * & a, Nodo * & b);
#endif
