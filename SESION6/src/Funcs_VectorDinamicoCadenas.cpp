#include <iostream>
#include <iomanip>
#include <cstring>

#include "Funcs_VectorDinamicoCadenas.h"

using namespace std;

void Redimensiona (char ** & lineas, TipoRedimension tipo, int & capacidad)
{
    int lineas_ocupadas = capacidad;

    switch (tipo)
    {
        case(TipoRedimension::DeUnoEnUno):
            capacidad++;
            break;
        
        case(TipoRedimension::EnBloques):
            capacidad+=TAM_BLOQUE;
            break;
        
        case (TipoRedimension::Duplicando):
            capacidad*=2;
            break;
    }

    char ** tmp = new char * [capacidad];

    for(int l=0; l<lineas_ocupadas; l++)
    {
        tmp[l] = lineas[l];
    }

    delete[] lineas;

    lineas = tmp;
}

void Reajusta (char ** & lineas, int num_lineas, int & capacidad_lineas)
{
    if(num_lineas != capacidad_lineas)
    {
        char ** tmp = new char * [num_lineas];

        for(int l=0; l<num_lineas; l++)
        {
            tmp[l] = new char[strlen(lineas[l])+1];
            strcpy(tmp[l], lineas[l]);

            delete [] lineas[l];
        }

        delete [] lineas;

        lineas = tmp;

        capacidad_lineas = num_lineas;
    }
}


void LiberaMemoria(char ** & lineas, int &num_lineas)
{
    for(int l=0; l<num_lineas; l++)
    {
        delete [] lineas[l];
    }

    delete [] lineas;
}

void Calculos_lineas(char ** lineas, int num_lineas, int & cv, int & cp)
{
    cv=0;
    cp=0;

    bool en_parrafo = false;
    for(int i=0; i<num_lineas; i++)
    {
        int longitud = strlen(lineas[i]);

        if(longitud==0) cv++;

        if (longitud==0 && en_parrafo) // fin de párrafo
			en_parrafo = false;	
        if (longitud!=0 && !en_parrafo) { // nuevo párrafo
			en_parrafo = true;
			cp++;
		}

    }
};