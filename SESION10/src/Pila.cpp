/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Implementación de las funciones de la clase Pila
//
// Declaraciones en Pila.h
//
// Fichero: Pila.cpp
//
/***************************************************************************/
#include "Pila.h"
#include <iostream>

using namespace std;

Pila::Pila(){
    lista = Lista();
    utilizados = 0;
}

Pila::Pila(const Pila &otro){
    CopiarDatos(otro);
}

Pila::~Pila(){
    LiberaMemoria();
}

bool Pila::EstaVacia()const{
    return utilizados == 0;
}

void Pila::Push(TipoBase info){
    //lista.Aniadir(info);
    //lista+=info;
    utilizados++;
}

TipoBase Pila::Pop(){
    TipoBase info = lista[utilizados];
    lista.Eliminar(utilizados);
    utilizados--;
    return info;
}

TipoBase Pila::GetTope()const{
    return lista[utilizados];
}

Pila & Pila::operator = (const Pila &otro){
    if(this != &otro){
        LiberaMemoria();
        CopiarDatos(otro);
    }
    return *this;
}

TipoBase Pila::operator ~ () const
{
    return GetTope();
}

TipoBase Pila::operator -- ()
{
    return Pop();
}

Pila & Pila::operator += (const TipoBase &otro)
{
    Push(otro);
    return *this;
}
//////////////////////////////////////////////////////////////////////////////
// METODOS PRIVADOS
//////////////////////////////////////////////////////////////////////////////

void Pila::CopiarDatos(const Pila &otro){
    lista = otro.lista;
    utilizados = otro.utilizados;
}

void Pila::LiberaMemoria(){
    utilizados = 0;
}