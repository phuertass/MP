#include <iostream>
#include "ProcesamientoArrayInt.h"

using namespace std;


#define numeros_linea 10
#define TOPE 100

int main(){
    int vector [TOPE];

    //Numero de casillas que se van a usar del vector
    int num_cas;

    //Rango inferior en el que se va a calcular la mayor posicion del vector
    int pos_inic;
    //Rango superior en el que se va a calcular la mayor posicion del vector
    int pos_fin;


    //Control de errores de los datos de entrada
    cout<<"Introduzca el numero de casillas a rellenar"<<endl;
    cin>>num_cas;
    //Si se introduce un valor negativo o un valor superior al tamaño del
    //vector se pide de nuevo el dato  
    while(num_cas<=0 or num_cas>TOPE){
        cout<<"El numero debe estar comprendido entre 0 y "<<TOPE<<endl;
        cin>>num_cas;
    }

    //Rellenamos el vector con numeros aleatorios generados entre 0 y TOPE
    RellenaVector(&vector[0],num_cas, 0, TOPE);
    //Mostramos el contenido del vector
    MuestraVector("",&vector[0], num_cas, numeros_linea);

    //Control de errores de los datos de entrada
    cout<<"\nIntroduzca menor posicion"<<endl;
    cin>>pos_inic;
    //Si se introduce un valor negativo o el valor es superior al numero
    //de casillas usadas se pide de nuevo el dato
    while(pos_inic<0 or pos_inic>num_cas){  
        cout<<"\nLa posicion debe ser >=0 y <"<<num_cas<<endl;
        cin>>pos_inic;
    }

    //Control de errores de los datos de entrada
    cout<<"\nIntroduzca mayor posicion"<<endl;
    cin>>pos_fin;
    //Si se introduce un valor negativo,el valor es superior al numero de 
    //casillas usadas o el rango superior es menor que el inferior se pide 
    //de nuevo el dato
    while(pos_fin<=0 || pos_fin<=pos_inic || pos_fin>num_cas){
        cout<<"\nLa posicion debe ser >"<<pos_inic<<" y menor que "
        <<num_cas<<endl;
        cin>>pos_fin;
    }

    //Se calcula la posicion del mayor y menor elemento
    int maximo; int minimo;
    int pos_maximo; int pos_minimo;

    MaxMin_Array(maximo, pos_maximo, minimo, pos_minimo, vector,
    pos_inic, pos_fin);
    

    //Mostramos el valor del mayor elemento del vector
    cout<<"El mayor valor es el numero: "<<maximo<<" con posicion: "<<
    pos_maximo<<endl;

    //Mostramos el valor del menor elemento del vector
    cout<<"El menor valor es el numero: "<<minimo<<" con posicion: "<<
    pos_minimo<<endl;

    
};