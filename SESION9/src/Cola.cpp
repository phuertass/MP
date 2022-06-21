/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Implementación de las funciones de la clase Cola
//
// Declaraciones en Cola.h
//
// Fichero: Cola.cpp
//
/***************************************************************************/
#include "Cola.h"
#include <iostream>

using namespace std;

Cola::Cola(){
    lista = Lista();
    utilizados = 0;
}

Cola::Cola(const Cola &otro){
    CopiarDatos(otro);
}

Cola::~Cola(){
    LiberaMemoria();
}

bool Cola::EstaVacia()const{
    return utilizados == 0;
}

void Cola::Push(TipoBase info){
    lista.Aniadir(info);
    utilizados++;
}
TipoBase Cola::Pop(){
    TipoBase info = lista.Valor(1);
    lista.Eliminar(1);
    utilizados--;
    return info;
}

TipoBase Cola::GetCabecera()const{
    return lista.Valor(0);
}

//////////////////////////////////////////////////////////////////////////////
// METODOS PRIVADOS
//////////////////////////////////////////////////////////////////////////////
void Cola::CopiarDatos(const Cola &otro){
    lista.Clona(otro.lista);
    utilizados = otro.utilizados;
}

void Cola::LiberaMemoria(){
    utilizados = 0;
}