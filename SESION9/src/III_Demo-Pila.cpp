/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Programa de prueba de las funciones de la clase Pila
//
// Fichero: III_Demo-Pila.cpp
//
/***************************************************************************/
#include "Pila.h"
#include <iostream>

using namespace std;

int main(){
    Pila pila;
    TipoBase dato;
    cout << "Pila vacia: " << pila.EstaVacia() << endl;

    cout<<"Añadiendo elementos a la pila del 1 al 10..."<<endl;
    for(int i=1;i<=10;i++){
        pila.Push(i);
    }

    cout<<"Pila vacia: "<<pila.EstaVacia()<<endl;

    cout<<"-----------------------------------"<<endl;

    cout<<"Prueba de extraer elementos de la pila"<<endl;
    for(int i=1;i<=10;i++){
        dato = pila.Pop();
        cout<<"Elemento extraido: "<<dato<<endl;
    }

    cout<<"Pila vacia: "<<pila.EstaVacia()<<endl;

    cout<<"-----------------------------------"<<endl;

    cout<<"Añadiendo elementos a la pila del 1 al 10..."<<endl;
    for(int i=1;i<=10;i++){
        pila.Push(i);
    }

    cout<<"Pila vacia: "<<pila.EstaVacia()<<endl;

    cout<<"-----------------------------------"<<endl;


    cout<<"Consultando el tope de la pila..."<<endl;
    dato = pila.GetTope();
    cout<<"Elemento del tope de la pila: "<<dato<<endl;

     cout<<"-----------------------------------"<<endl;

    cout<<"Finalizando programa..."<<endl;
    return 0;
    
}