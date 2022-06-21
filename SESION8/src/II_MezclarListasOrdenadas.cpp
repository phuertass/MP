/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Programa de prueba de funciones de la clase Lista(Mezclar Listas Ordenadas)
//
// Fichero: II_MezclarListasOrdenadas.cpp
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

    cout<<"\nLista aleatoria: ";
    cout<<ToString(l)<<endl;

    //Ordenar la lista aleatoria
    OrdenaSeleccion(l);
    cout<<"\nLista 1 ordenada: \n";
    cout<<ToString(l)<<endl;

    //Crear una segunda lista con 5 valores
    Lista l2 = CreaListaAleatoria(5, MIN_ALEAT, MAX_ALEAT);
    cout<<"\nLista aleatoria: ";
    cout<<ToString(l2)<<endl;

    //Ordenar la lista aleatoria
    OrdenaSeleccion(l2);
    cout<<"\nLista 2 ordenada: \n";
    cout<<ToString(l2)<<endl;


    Lista l3 = CreaLista();

    //Mezclar las dos listas
    MezclaListasClasico(l3, l2 ,l);

    cout<<"\nLista mezclada metodo clasico: \n";
    cout<<ToString(l3)<<endl;

    Lista l4 = CreaLista();
    MezclaListas(l4, l2 ,l);

    cout<<"\nLista mezclada: \n";
    cout<<ToString(l4)<<endl;


    //Destruimos las listas
    DestruyeLista(l);
    DestruyeLista(l2);
    DestruyeLista(l3);
    DestruyeLista(l4);
}