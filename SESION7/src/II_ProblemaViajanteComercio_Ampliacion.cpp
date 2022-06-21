/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// RELACION DE PROBLEMAS 2
//
// Ampliacion del problema del viajante de comercio
//  
// Fichero: II_ProblemaViajanteComercio_Ampliacion.cpp
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

int GetMinimoFila(const Matriz2D & m, int fila, int & minimo,const vector<int> & v, const int origen)
{   
    minimo=INT32_MAX;
    int pos_min;
    for(int i=0; i<m.cols; i++)
    {
        if(minimo>m.datos[fila][i] && m.datos[fila][i]!=0 && !Esta(i, v))
        {
            minimo=m.datos[fila][i];
            pos_min=i;
        }
    }
    if(minimo==INT32_MAX)
    {
        minimo=m.datos[fila][origen];
        return origen;
    }
    return pos_min;
}

int Sumatoria(vector<int> & v)
{
    int suma=0;
    for(int i=0; i<v.size(); i++)
    {
        suma+=v[i];
    }
    return suma;
}



int main(){
    int n;
    
    cout<<"\nNumero de ciudades-->";
    cin>>n;

    Matriz2D B = CreaMatriz(n, n);

    cout<<"\nVaya introduciendo datos de la matriz de costes"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"\nB["<<i<<"]["<<j<<"]-->";
            cin>>B.datos[i][j];
        }
    }

    cout<<ToString(B)<<endl;


    //Calculamos la ruta con origen todas las ciudades y nos quedamos con 
    //la ruta de menor coste
    int menor_coste=INT32_MAX;
    vector<int> mejor_ruta;
    vector<int> coste_mejor_ruta;
    for(int i=0; i<n; i++)
    {
    int origen=i;
    cout<<"\nCiudad de origen-->"<<origen<<endl;
    //cin>>origen;

    vector<int> costes;
    int minimo=INT32_MAX;
    int pos_min;
    vector<int> recorrido;
    int fila_actual=origen;
    for(int i=0; i<B.fils; i++){
        recorrido.push_back(fila_actual);
        pos_min=GetMinimoFila(B, fila_actual, minimo, recorrido, origen);
        //cout<<"El minimo de la fila "<<fila_actual<<" es "<<minimo<<" y la posicion es "<<pos_min<<endl;
        fila_actual=pos_min;  
    }
    
    int a_introducir;

    recorrido.push_back(origen);
    for(int i=0; i<recorrido.size()-1; i++){ 
        a_introducir = B.datos[recorrido[i]][recorrido[i+1]];
        //cout<<"a introducir "<<a_introducir<<endl;
        //cout<<"B.datos["<<recorrido[i]<<"]["<<recorrido[i+1]<<"]="<<B.datos[recorrido[i]][recorrido[i+1]]<<endl;
        costes.push_back(a_introducir);
    }

    recorrido.pop_back();

    //Mostrar vector recorrido
    cout<<"\nRecorrido:"<<endl;
    for(int i=0; i<recorrido.size(); i++){
        cout<<recorrido[i]<<" ";
    }

    //Mostrar vector costes
    cout<<"\nCostes:"<<endl;
    for(int i=0; i<costes.size(); i++){
        cout<<costes[i];
        if(i!=costes.size()-1)
            cout<<"+";
    }

    cout<<"=";
    cout<<Sumatoria(costes);

    if(Sumatoria(costes)<menor_coste)
    {
        menor_coste=Sumatoria(costes);
        mejor_ruta=recorrido;
        coste_mejor_ruta=costes;
    }

    cout<<endl;

    }

    cout<<"\n-------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------------"<<endl;
    cout<<"\nLa mejor ruta es: "<<endl;
    for(int i=0; i<mejor_ruta.size(); i++){
        cout<<mejor_ruta[i]<<" ";
    }

    cout<<"\nCoste de la mejor ruta: "<<menor_coste<<endl;    

    return 0;
}