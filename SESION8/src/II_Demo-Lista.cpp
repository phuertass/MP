/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Programa de prueba de las funciones declaradas en el fichero 
// Lista.h
//
// Fichero: LII_Demo-Lista.cpp
//
/***************************************************************************/
#include <iostream>
#include <cstdlib>

#include "Lista.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

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
    //Creamos 4 listas para probar los 4 algoritmos de ordenacion
    //diferentes y las mostramos
    cout<<"\n----------------------------------------------------"<<endl;
    cout<<"\nCreando listas para probar los 4 algoritmos de ordenacion...\n";
    Lista lSeleccion = CreaLista();
    Lista lInsercion = CreaLista();
    Lista lIntercambio = CreaLista();
    Lista lIntercambioMejorado = CreaLista();
    
    
    cout<<"Clonando listas..."<<endl;
    Clona(lSeleccion, l);
    Clona(lInsercion, l);
    Clona(lIntercambio, l);
    Clona(lIntercambioMejorado, l);

    OrdenaInsercion(lInsercion);
    OrdenaSeleccion(lSeleccion);
    OrdenaIntercambio(lIntercambio);
    OrdenaIntercambioMejorado(lIntercambioMejorado);
    
    cout<<"\nLista seleccion: ";
    cout<<ToString(lSeleccion)<<endl;
    cout<<"\nLista insercion: ";
    cout<<ToString(lInsercion)<<endl;
    cout<<"\nLista intercambio: ";
    cout<<ToString(lIntercambio)<<endl;
    cout<<"\nLista intercambio mejorado: ";
    cout<<ToString(lIntercambioMejorado)<<endl;
    
    DestruyeLista(lSeleccion);
    DestruyeLista(lInsercion);
    DestruyeLista(lIntercambio);
    DestruyeLista(lIntercambioMejorado);

    //Prueba de Metodo Ecualiza
    cout<<"\n----------------------------------------------------"<<endl;
    cout<<"\nPrueba de Metodo Ecualiza"<<endl;

    Lista l1 = CreaListaAleatoria(10, 0, 100);
    Ecualiza(l1, 10);

    cout<<"\nLista l1: ";
    cout<<ToString(l1)<<endl;

    DestruyeLista(l1);

    //Prueba del metodo SonIguales
    cout<<"\n----------------------------------------------------"<<endl;
    cout<<"\nPrueba del metodo SonIguales"<<endl;

    Lista l2 = CreaListaAleatoria(10, 0, 100);
    Lista l3 = CreaLista();
    Clona(l3, l2);

    cout<<"\nLista l2: ";
    cout<<ToString(l2)<<endl;
    cout<<"\nLista l3: ";
    cout<<ToString(l3)<<endl;

    bool iguales = SonIguales(l2, l3);
    cout<<"\nSon iguales?: "<<iguales<<endl;

    DestruyeLista(l2);
    DestruyeLista(l3);

    //Prueba del metodo SubLista
    cout<<"\n----------------------------------------------------"<<endl;
    cout<<"\nPrueba del metodo SubLista"<<endl;

    cout<<"\nLista l: ";
    cout<<ToString(l)<<endl;

    Lista l4 = CreaLista();
    
    int pos_inicial;
    int num_nodos;
    //Lectura de datos para la creacion de la submatriz con filtro de enterada
    do{
        cout<<"\nIntroduzca la posicion inicial: ";
        cin>>pos_inicial;
    }while(pos_inicial<0 or pos_inicial>num_valores);

    do{
        cout<<"\nIntroduzca el numero de nodos: ";
        cin>>num_nodos;
    }while(num_nodos<0 or pos_inicial+num_nodos>num_valores);

    cout<<"\nCreando sublista de l desde la posicion "<<pos_inicial<<" con "
    <<num_nodos<<" nodos..."<<endl;

    SubLista(l4, l, pos_inicial, num_nodos);
    //Mostramos la sublista obtenida
    cout<<"\nSublista: ";
    cout<<ToString(l4)<<endl;

    DestruyeLista(l4);
    DestruyeLista(l);

    return 0;
}