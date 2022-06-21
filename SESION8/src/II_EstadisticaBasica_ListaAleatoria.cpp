/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Programa que genera una lista aleatoria de n elementos y le 
// calcula la media y la varianza
//
// Fichero: II_EstadisticaBasica_ListaAleatoria.cpp
//
/***************************************************************************/
#include <iostream>
#include <cstdlib>

#include "Lista.h"

using namespace std; 


/***************************************************************************/
/***************************************************************************/
// DECLARACIÓN DE FUNCIONES ESPECÍFICAS DEL EJERCICIO
/***************************************************************************/
/***************************************************************************/
// Calcula el valor medio de los valores almacenados en una lista 
// Parámetros: l, la lista que se va a procesar. 
// Devuelve: el valor medio de los valores guardados en la lista

double Media (const Lista & l);

/***************************************************************************/
// Calcula la varianza de los valores almacenados en una lista 
// Parámetros: l, la lista que se va a procesar. 
// Devuelve: la varianza de los valores guardados en la lista

double Varianza (const Lista & l);

/***************************************************************************/
/***************************************************************************/
// FIN DECLARACIÓN DE FUNCIONES ESPECÍFICAS DEL EJERCICIO
/***************************************************************************/
/***************************************************************************/

int main (int argc, char ** argv)
{
	const int MIN_ALEAT =   0;  // M�nimo valor aleatorio permitido
	const int MAX_ALEAT = 100;	// M�ximo valor aleatorio permitido

    //Pedir datos para tamaño de la lista
    int num_valores=0;

    int min_aleat=MIN_ALEAT;
    int max_aleat=MAX_ALEAT;

    if(argc == 1){
        cout<<"\nUso del programa: "<<argv[0]<<" <num_valores> <min_aleat>"
        <<" <max_aleat>"<<endl;
        exit(EXIT_FAILURE);
    }

    if(argc > 1){
        num_valores = atoi(argv[1]);
        if(argc > 2){
            max_aleat = atoi(argv[2]);
            if(argc > 3){
                min_aleat = atoi(argv[3]);
            }
        }
    }

    //Pedir datos para los min y max aleat

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

    //Calculamos la media y la varianza de la lista aleatoria
    double media = Media(l);
    double varianza = Varianza(l);

    //Mostramos los resultados
    cout<<"\n----------------------------------------------------"<<endl;
    cout<<"\nMedia de la lista aleatoria: "<<media<<endl;
    cout<<"\nVarianza de la lista aleatoria: "<<varianza<<endl;

    //.............................................................
    //Probamos funcion RellenaAleatoriamente
    cout<<"\n----------------------------------------------------"<<endl;
    cout<<"\nProbando RellenaAleatoriamente"<<endl;
    RellenaAleatoriamente(l, min_aleat, max_aleat);
    cout<<"\nLista aleatoria: ";
    cout<<ToString(l)<<endl;

    //Calculamos de nuevo la media y varianza
    media = Media(l);
    varianza = Varianza(l);

    //Mostramos los resultados
    cout<<"\n----------------------------------------------------"<<endl;
    cout<<"\nMedia de la lista aleatoria: "<<media<<endl;
    cout<<"\nVarianza de la lista aleatoria: "<<varianza<<endl;

    DestruyeLista(l);

    return 0;

}

/***************************************************************************/
/***************************************************************************/
// Calcula el valor medio de los valores almacenados en la lista 
// Recibe: un puntero al primer nodo de la lista
// Devuelve: el valor medio de los valores guardados en la lista

double Media (const Lista & l)
{
	double suma = 0.0; 
	int num_elementos = NumElementos(l);

	for (PNodo p=l; p!=0; suma+=p->info, p=p->sig);

	/*
	PNodo p=l;

	while (p != 0) {
		suma+=p->info;
		p=p->sig;
	}
	*/

	return (suma/num_elementos);
}

/***************************************************************************/
/***************************************************************************/
// Calcula la varianza de los valores almacenados en la lista 
// Recibe: un puntero al primer nodo de la lista
// Devuelve: la varianza de los valores guardados en la lista

double Varianza (const Lista & l)
{
	PNodo p = l; 
	double suma = 0.0; 
	int num_elementos = NumElementos(l);
	double media = Media (l);

	while (p!=0) {
		double dif = p->info-media;
		double sqrdif = dif*dif;
		suma+=sqrdif;
		p=p->sig;
	}
	return (suma/num_elementos);
}

/***************************************************************************/
/***************************************************************************/