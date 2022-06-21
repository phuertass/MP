/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Programa de prueba de la funcion Invierte, además de elimina e 
// inserta en una lista
//
// Fichero: II_Invierte_Lista.cpp
//
/***************************************************************************/
#include <iostream>
#include <cstdlib>

#include "Lista.h"

using namespace std; 

int main (int argc, char ** argv)
{
	const int MIN_ALEAT =   0;  // M�nimo valor aleatorio permitido
	const int MAX_ALEAT = 100;	// M�ximo valor aleatorio permitido

    //Pedir datos para tamaño de la lista
    int num_valores;
    do{
        cout << "Introduzca el numero de valores que "
             << "quiere introducir en la lista: ";
        cin >> num_valores;
    }while(num_valores <= 0);

    int min_aleat;
    int max_aleat;

    //Pedir datos para los min y max aleat

    do{
        cout<<"\nIntroduzca el primer rango de valor aleatorio: ";
        cin>>min_aleat;
    }while(min_aleat<0 or min_aleat>MAX_ALEAT);
    
    do{
        cout<<"\nIntroduzca segundo rango de valor aleatorio: ";
        cin>>max_aleat;
    }while(max_aleat<0 or  max_aleat>MAX_ALEAT);

    //Si min_aleat es mayor que max_aleat, cambiar el valor de min_aleat
    if(min_aleat>max_aleat){
        int aux = min_aleat;
        min_aleat = max_aleat;
        max_aleat = aux;
    }

    //.............................................................
    //Creamos una lista aleatoria y la mostramos
    cout<<"\n----------------------------------------------------"<<endl;
    cout<<"\nCreando lista aleatoria con numero de valores: "
    <<num_valores<<" entre los rangos "<<min_aleat<<" y "<<
    max_aleat<<endl;
    Lista l = CreaListaAleatoria(num_valores, min_aleat, max_aleat);
    cout<<"\nLista aleatoria: ";
    cout<<ToString(l)<<endl;

    //.............................................................
    //Prueba del metodo elimina 
    cout<<"\n----------------------------------------------------"<<endl;
    int pos_a_eliminar;

    do{
        cout<<"\nIntroduzca la posicion a eliminar: ";
        cin>>pos_a_eliminar;
    }while(pos_a_eliminar<0 or pos_a_eliminar>NumElementos(l));

    cout<<"\nEliminando elemento de la posicion "<<pos_a_eliminar<<endl;
    Elimina(l, pos_a_eliminar);
    cout<<"\nLista despues de eliminar: ";
    cout<<ToString(l)<<endl;

    //.............................................................
    //Prueba del metodo inserta
    cout<<"\n----------------------------------------------------"<<endl;
    int pos_a_insertar;
    int valor_a_insertar;

    do{
        cout<<"\nIntroduzca la posicion a insertar: ";
        cin>>pos_a_insertar;
    }while(pos_a_insertar<0 or pos_a_insertar>NumElementos(l));

    do{
        cout<<"\nIntroduzca el valor a insertar: ";
        cin>>valor_a_insertar;
    }while(valor_a_insertar<0);

    cout<<"\nInsertando elemento "<<valor_a_insertar<<" en la posicion "
    <<pos_a_insertar<<endl;
    Inserta(l, valor_a_insertar, pos_a_insertar);
    cout<<"\nLista despues de insertar: ";
    cout<<ToString(l)<<endl;

    //.............................................................
    //Prueba del metodo invierte
    cout<<"\n----------------------------------------------------"<<endl;
    cout<<"\nInviertiendo lista"<<endl;
    InvertirLista(l);
    cout<<"\nLista inviertida: ";
    cout<<ToString(l)<<endl;



    DestruyeLista(l);


}