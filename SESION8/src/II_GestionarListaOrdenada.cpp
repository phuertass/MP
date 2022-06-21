/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Programa de prueba de funciones de la clase Lista
// (Insertar y Eliminar en una lista Ordenada)
// Fichero: II_GestionarListaOrdenada.cpp
//
/***************************************************************************/
#include <iostream>
#include <cstdlib>

#include "Lista.h"

using namespace std; 

int main (int argc, char ** argv)
{
	const int MIN_ALEAT =   1;  // M�nimo valor aleatorio permitido
	const int MAX_ALEAT = 100;	// M�ximo valor aleatorio permitido

    //Crear lista aleatoria con 10 valores
    Lista l = CreaListaAleatoria(10, MIN_ALEAT, MAX_ALEAT);
    //cout<<"\nLista aleatoria: ";
    //cout<<ToString(l)<<endl;

    //Ordenar la lista aleatoria
    OrdenaSeleccion(l);
    cout<<"\nLista 1 ordenada: \n";
    cout<<ToString(l)<<endl;

    //Crear una segunda lista con 5 valores
    Lista l2 = CreaListaAleatoria(5, MIN_ALEAT, MAX_ALEAT);
    //cout<<"\nLista aleatoria: ";
    //cout<<ToString(l2)<<endl;

    //Ordenar la lista aleatoria
    OrdenaSeleccion(l2);
    cout<<"\nLista 2 ordenada: \n";
    cout<<ToString(l2)<<endl;

    //Insertar la lista l2 en la lista l
    //Recorremos la lista l2
    for(int i=1; i<=NumElementos(l2); i++){
        //Insertamos el elemento en la posicion i+1
        InsertaValorListaOrdenada(l, Valor(l2, i));
    }

    

    //Mostramos la lista l
    cout<<"\nLista 1 tras insertar ordenadamente Lista 2: \n";
    cout<<ToString(l)<<endl;

    //Eliminamos los elementos de la lista l que esten en la lista l2
    for(int i=1; i<=NumElementos(l2); i++){
        //Eliminamos el elemento en la posicion i+1
        EliminaValorListaOrdenada(l, Valor(l2, i));
    }

    //Mostramos la lista l
    cout<<"\nLista 1 tras eliminar los elementos de Lista 2: \n";
    cout<<ToString(l)<<endl;


    //Destruir las listas
    DestruyeLista(l);
    DestruyeLista(l2);

    return 0;
}