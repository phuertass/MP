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
    //lista.Aniadir(info);
    utilizados++;
}
TipoBase Cola::Pop(){
    TipoBase info = lista[1];
    lista.Eliminar(1);
    utilizados--;
    return info;
}

TipoBase Cola::GetCabecera()const{
    return lista[0];
}

Cola & Cola::operator = (const Cola &otro){
    if(this != &otro){
        LiberaMemoria();
        CopiarDatos(otro);
    }
    return *this;
}

TipoBase Cola::operator ~ () const{
    return GetCabecera();
}

TipoBase Cola::operator -- (){
    return Pop();
}

Cola & Cola::operator += (const TipoBase &otro){
    Push(otro);
    return *this;
}


//////////////////////////////////////////////////////////////////////////////
// METODOS PRIVADOS
//////////////////////////////////////////////////////////////////////////////
void Cola::CopiarDatos(const Cola &otro){
    lista=(otro.lista);
    utilizados = otro.utilizados;
}

void Cola::LiberaMemoria(){
    utilizados = 0;
}