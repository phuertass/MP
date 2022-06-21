/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// RELACION DE PROBLEMAS 2
//
// Resolucion del problema de asignacion
//  
// Fichero: II_ProblemaAsignacion.cpp
//
/***************************************************************************/
#include <iostream>
#include "Matriz2D.h"
#include "FuncsVectorDinamico.h"
#include <vector>

using namespace std;

bool Esta(int a, const vector<int> & v)
{
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] == a)
            return true;
    }
    return false;
}


int main(){
    int pedidos;
    
    cout<<"\nNumero de pedidos/tecnicos-->";
    cin>>pedidos;

    Matriz2D B = CreaMatriz(pedidos, pedidos);

    cout<<"\nVaya introduciendo datos de la matriz B"<<endl;
    for(int i=0; i<pedidos; i++){
        for(int j=0; j<pedidos; j++){
            cout<<"\nB["<<i<<"]["<<j<<"]-->";
            cin>>B.datos[i][j];
        }
    }

    cout<<ToString(B)<<endl;

    cout<<"\nCalculando asignaciones..."<<endl;
    Matriz2D X = CreaMatriz(pedidos, pedidos);
    vector<int> cols_usadas;

    int num_fila = 0;
    int posicion;
    int minimo=B.datos[0][0];
    for(int i=0; i<pedidos; i++){
        for(int j=0; j<pedidos; j++){
            if(minimo>B.datos[i][j] && !Esta(j, cols_usadas)){
                minimo=B.datos[i][j];
                posicion=j;
            }
        }
        cout<<"Posicion de la fila"<<i<<" a coger es "<<posicion<<endl;
        X.datos[i][posicion]=1;
        cols_usadas.push_back(posicion);
        minimo=INT32_MAX;
    }

    return 0;
}