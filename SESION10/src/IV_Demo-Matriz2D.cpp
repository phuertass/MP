/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Programa de prueba de las funciones de la clase Matriz2D
//
// Fichero: III_Demo-Matriz2D.cpp
//
/***************************************************************************/
#include <iostream>
#include <iomanip>

#include "TipoBaseMatriz.h"
#include "Matriz2D.h"

using namespace std; 

/***********************************************************************/
/***********************************************************************/

int main (void)
{
    // Prueba de operador de asignacion
    Matriz2D m1(3,3);
    for (int i=0; i<m1.NumFilas(); i++)
    {
        for (int j=0; j<m1.NumColumnas(); j++)
        {
            m1(i,j) = i+j*11;
        }
    }
    
    Matriz2D m2(3,3);
    m2 = m1;

    cout<<"m1 "<<endl;
    cout<<m1.ToString()<<endl;
    cout<<"m2 = m1"<<endl;
    cout<<m2.ToString()<<endl;

    cout<<"--------------------------------------------"<<endl;
    m2 = 5;
    cout<<"m2 = 5"<<endl;
    cout<<m2.ToString()<<endl;

    cout<<"--------------------------------------------"<<endl;
    cout<<"Prueba de los operadores == y != "<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"m1 == m2: "<<(m1 == m2)<<endl;
    cout<<"m1 != m2: "<<(m1 != m2)<<endl;

    m2 = m1;
    cout<<"--------------------------------------------"<<endl;
    cout<<"m2 = m1"<<endl;
    cout<<"m1 == m2: "<<(m1 == m2)<<endl;
    cout<<"m1 != m2: "<<(m1 != m2)<<endl;

    return (0);
}