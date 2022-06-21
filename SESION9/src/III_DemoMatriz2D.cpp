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
    cout<<"Prueba de constructores de la clase Matriz2D"<<endl;
    cout<<"--------------------------------------------"<<endl;
    Matriz2D m1;
    cout<<"Matriz vacia: "<<endl;
    cout<<m1.ToString()<<endl;
    cout<<"--------------------------------------------"<<endl;
    Matriz2D m2(3);
    cout<<"Matriz 3x3: "<<endl;
    cout<<m2.ToString()<<endl;
    cout<<"--------------------------------------------"<<endl;
    Matriz2D m3(3,4);
    cout<<"Matriz 3x4: "<<endl;
    cout<<m3.ToString()<<endl;
    cout<<"--------------------------------------------"<<endl;
    Matriz2D m4(3,4,5);
    cout<<"Matriz 3x4 inicializada con 5: "<<endl;
    cout<<m4.ToString()<<endl;
    cout<<"--------------------------------------------"<<endl;

    Matriz2D m5(m4);
    cout<<"Matriz copia de m4: "<<endl;
    cout<<m5.ToString()<<endl;
    cout<<"--------------------------------------------"<<endl;


    cout<<"Prueba de metodos de consulta de dimensiones"<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"Numero de filas: "<<m5.NumFilas()<<endl;
    cout<<"Numero de columnas: "<<m5.NumColumnas()<<endl;
    cout<<"--------------------------------------------"<<endl;

    cout<<"Check si esta vacia m5: "<<m5.EsVacia()<<endl;
    cout<<"--------------------------------------------"<<endl;

    cout<<"Check de Metodo EsIgual: "<<endl;
    cout<<"m4 == m5: "<<m4.EsIgualA(m5)<<endl;
    cout<<"--------------------------------------------"<<endl;

    cout<<"Prueba de metodos de modificacion"<<endl;
    cout<<"--------------------------------------------"<<endl;
    m5.Ecualiza(0);
    cout<<"Matriz 4 ecualizada con 0: "<<endl;
    cout<<m5.ToString()<<endl;
    
    cout<<"--------------------------------------------"<<endl;
    cout<<"Prueba de metodos de consulta de valores"<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"Valor de la casilla (1,1)lvalue: "<<m5.Valor(1,1)<<endl;

    m5.Valor(1,1) = 10;
    cout<<"Modificando la casilla 1,1 a 10 "<<endl;
    cout<<m5.ToString()<<endl;
    
    cout<<"--------------------------------------------"<<endl;
    cout<<"Prueba de metodos de eliminacion de filas y columnas"<<endl;

    cout<<"Eliminando la fila 1: "<<endl;
    m5.EliminaFila(1);
    cout<<m5.ToString()<<endl;

    cout<<"Eliminando la columna 1: "<<endl;
    m5.EliminaColumna(1);
    cout<<m5.ToString()<<endl;

    cout<<"--------------------------------------------"<<endl;
    cout<<"Eliminando todos los elementos de la matriz"<<endl;
    m5.EliminaTodos();
    cout<<"Eliminados"<<endl;

    cout<<"Metodo clonar"<<endl;
    m5.Clona(m4);
    cout<<m5.ToString()<<endl;

    Secuencia sec;
    sec.Aniade(1);
    sec.Aniade(2);
    sec.Aniade(3);
    sec.Aniade(4);
    cout<<"Secuencia: "<<sec.ToString()<<endl;

    cout<<"--------------------------------------------"<<endl;
    cout<<"Añadimos la secuencia a la matriz"<<endl;
    m5.Aniade(sec);
    cout<<m5.ToString()<<endl;

    cout<<"--------------------------------------------"<<endl;
    cout<<"Insertamos la secuencia a la matriz en la fila 1"<<endl;
    m5.Inserta(1,sec);
    cout<<m5.ToString()<<endl;

    cout<<"--------------------------------------------"<<endl;
    cout<<"Prueba de submatriz"<<endl;
    cout<<"Submatriz de la matriz m5 de filas 1 y 2 y columnas 1 y 2: "<<endl;
    cout<<m5.SubMatriz(1,2,1,2).ToString()<<endl;

    cout<<"Prueba del metodo Fila que devuelve una Secuencia"<<endl;
    cout<<"Fila 1 de la matriz m5: "<<endl;
    cout<<m5.Fila(1).ToString()<<endl<<endl;


    cout<<"Prueba del metodo Columna que devuelve una Secuencia"<<endl;
    cout<<"Columna 1 de la matriz m5: "<<endl;
    cout<<m5.Columna(1).ToString()<<endl<<endl;

    cout<<"Espejo horizontal de la matriz m5: "<<endl;
    m5.EspejoHorizontal();
    cout<<m5.ToString()<<endl;

    cout<<"Espejo vertical de la matriz m5: "<<endl;
    m5.EspejoVertical();
    cout<<m5.ToString()<<endl;


    return (0);
}