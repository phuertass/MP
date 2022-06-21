/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Fichero de cabecera de la clase Cola
//
// Implementaci�n en Cola.cpp
//
// Fichero: Cola.h
//
/***************************************************************************/
#ifndef COLA_H
#define COLA_H
#include "Lista.h"
using namespace std;
typedef int TipoBase;


class Cola {
    private:
        Lista lista;
        int utilizados;

    public:
        ////////////////////////////////////////////////////////////////////////
        // Constructores
        ////////////////////////////////////////////////////////////////////////
        //Constructor sin argmuentos
        Cola();

        //Constructor de copia
        Cola(const Cola &otro);

        //Destructor
        ~Cola();

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

        TipoBase GetCabecera()const;

        Cola & operator = (const Cola &otro);

        TipoBase operator ~ () const;

        TipoBase operator -- ();

        Cola & operator += (const TipoBase &otro);

    private: 
        ////////////////////////////////////////////////////////////////////////
        // Metodos de ayuda
        ////////////////////////////////////////////////////////////////////////
        //Metodo para copiar una pila
        void CopiarDatos(const Cola &otro);

        //Metodo para liberar la memoria de la pila
        void LiberaMemoria();

};

#endif