/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Programa de prueba de las funciones de la clase Matriz2D
//
// Fichero: IV_Demo-Matriz2D.cpp
//
/***************************************************************************/
#include <iostream>
#include <iomanip>

#include "TipoBaseMatriz2D.h"
#include "Matriz2D.h"

using namespace std;

/***********************************************************************/
/***********************************************************************/

int main(void)
{
    Matriz2D m("/home/phuertas/UNIVERSIDAD/MP/SESION13/ficheros/datos_5x4.txt");
    cout << m << endl;

    Matriz2D m2(5,5);
    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
            m2(i,j) = i*j + 1;

    m2.EscribirMatriz2D("/home/phuertas/UNIVERSIDAD/MP/SESION13/ficheros/datos_5x4_escribir.txt");


    m.LeerMatriz2D("/home/phuertas/UNIVERSIDAD/MP/SESION13/ficheros/datos_5x4_escribir.txt");
    cout << m << endl;



    return (0);
}