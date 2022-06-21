/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Programa de prueba de las funciones de la clase Cola
//
// Fichero: IV_Demo-Cola.cpp
//
/***************************************************************************/
#include "Cola.h"
#include <iostream>

using namespace std;


int main(){
    Cola cola;
    TipoBase dato;
    cout << "Cola vacia: " << cola.EstaVacia() << endl;

    cout<<"Añadiendo elementos a la cola del 1 al 10..."<<endl;
    for(int i=1;i<=10;i++){
        cola.Push(i);
    }

    cout<<"Cola vacia: "<<cola.EstaVacia()<<endl;

    cout<<"-----------------------------------"<<endl;

    cout<<"Prueba de extraer elementos de la cola"<<endl;
    for(int i=1;i<=10;i++){
        dato = cola.Pop();
        cout<<"Elemento extraido: "<<dato<<endl;
    }

    cout<<endl;

    cout<<"Cola vacia: "<<cola.EstaVacia()<<endl;

    cout<<"-----------------------------------"<<endl;

    cout<<"Añadiendo elementos a la cola del 1 al 10..."<<endl;
    for(int i=1;i<=10;i++){
        cola.Push(i);
    }

    cout<<"Cola vacia: "<<cola.EstaVacia()<<endl;

    cout<<"-----------------------------------"<<endl;

    cout<<"Consultando la cabecera de la cola..."<<endl;
    dato = cola.GetCabecera();
    cout<<"Elemento de la cabecera de la cola: "<<dato<<endl;

    cout<<"-----------------------------------"<<endl;

    cout<<"Sobrecarga de operadores " << endl;
    Cola cola2;
    cola2 = cola;
    cout<<"Prueba de extraer elementos de la cola"<<endl;
    for(int i=1;i<=10;i++){
        dato = --cola2;
        cout<<"Elemento extraido: "<<dato<<endl;
    }

    cola2 += 10;
    cout<<"-----------------------------------"<<endl;
    cout<< ~cola2 << endl;


    cout<<"Finalizando programa..."<<endl;

    return 0;
}