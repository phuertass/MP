/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Fichero de cabecera de la clase Pila
//
// Implementaci�n en Pila.cpp
//
// Fichero: Pila.h
//
/***************************************************************************/
#ifndef PILA_H
#define PILA_H
#include "Lista.h"
using namespace std;

typedef int TipoBase;
class Pila {
    private:

        Lista lista;
        int utilizados;

    public:
        ////////////////////////////////////////////////////////////////////////
        // Constructores
        ////////////////////////////////////////////////////////////////////////
        //Constructor sin argmuentos
        Pila();

        //Constructor de copia
        Pila(const Pila &otro);

        //Destructor
        ~Pila();

        // Devuelve true si la pila está vacía
        bool EstaVacia()const;

        //Añade un elemento al tope de la pila
        void Push(TipoBase info);

        ////////////////////////////////////////////////////////////////////////
        // Metodos de acceso
        ////////////////////////////////////////////////////////////////////////
        //Método para sacar un valor. Obtiene (devuelve) el elemento extraído. La pila se
        //modifica
        TipoBase Pop();

        TipoBase GetTope()const;

    private: 
        ////////////////////////////////////////////////////////////////////////
        // Metodos de ayuda
        ////////////////////////////////////////////////////////////////////////
        //Metodo para copiar una pila
        void CopiarDatos(const Pila &otro);

        //Metodo para liberar la memoria de la pila
        void LiberaMemoria();
};

#endif