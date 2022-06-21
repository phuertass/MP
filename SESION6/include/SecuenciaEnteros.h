#include <iostream>
#include <string>
#include <cstring>
#include "GeneradorAleatorioEnteros.h"
using namespace std;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class SecuenciaEnteros
{
private:

    static const int TAMANIO = 100; // Núm.casillas disponibles
    int vector_privado[TAMANIO];

    // PRE: 0 <= total_utilizados <= TAMANIO

    int total_utilizados; // Núm.casillas ocupadas

public:

    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaEnteros (void) : total_utilizados (0)
    {}

    /***********************************************************************/
    // Constructores con argumentos

    /*******************************************************/
    // Construye una secuencia con "n_datos" valores
    // PRE: 0 <= n_datos <= TAMANIO
    // PRE: A partir de "p" hay "n_datos" valores
    SecuenciaEnteros (int * p, int n_datos);

    /*******************************************************/
    // Construye una secuencia con "n_datos" valores iguales
    // PRE: 0 <= n_datos <= TAMANIO
    SecuenciaEnteros (int n_datos, int valor=0);

    /*******************************************************/
    // Construye una secuencia con "n_datos" valores aleatorios
    // PRE: 0 <= n_datos <= TAMANIO
    SecuenciaEnteros (int n_datos, int min_aleat, int max_aleat);

    /***********************************************************************/
    // Devuelve el número de casillas ocupadas

    int TotalUtilizados();
    

    /***********************************************************************/
    // Devuelve el número de casillas disponibles

    int Capacidad (void);

    /***********************************************************************/
    // Añade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // 		La adición se realiza si hay alguna casilla disponible.
    // 		El nuevo elemento se coloca al final del vector.
    // 		Si no hay espacio, no se hace nada.

    void Aniade (int nuevo);

    /***********************************************************************/
    // Devuelve el elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados

    int Elemento (int indice);

    /***********************************************************************/
    // Eliminar el carácter de la posición dada por "indice".
    // Realiza un borrado físico (desplazamiento y sustitución).
    // PRE: 0 <= indice < total_utilizados

    void Elimina (int indice);

    void Inserta(int indice, int valor);
 
    /*******************************************************/
    // Devuelve una ref. al elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados
    int & Valor (int indice);

    /*******************************************************/
    // Devuelve true si la secuencia implícita es igual a "otra"
    bool EsIgualA (const SecuenciaEnteros & otra);

    /***********************************************************************/
    // Compone un string con todos los valores que están
    // almacenados en la secuencia y lo devuelve.

    string ToString();

	/***********************************************************************/
};