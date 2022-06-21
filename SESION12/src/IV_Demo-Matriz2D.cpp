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
    // Prueba de operador de asignacion
    Matriz2D m1(3, 3);
    for (int i = 0; i < m1.NumFilas(); i++)
    {
        for (int j = 0; j < m1.NumColumnas(); j++)
        {
            m1(i, j) = i + j * 11;
        }
    }

    Matriz2D m2(3, 3);
    m2 = m1;

    Matriz2D m;
    cin >> m;
    cout << m;

    return (0);
}