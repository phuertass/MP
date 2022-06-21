#include <iostream>
#include "MiCadenaClasica.h"
using namespace std;



int main()
{
    const int MAX_CARACTERES = 100;
    const int MAX_PALABRAS = 20;
    char la_cadena[MAX_CARACTERES];
    info_palabra las_palabras[MAX_PALABRAS];
    int num_palabras;

    char * DELIMITADOR = (char *)"FIN";

    cout<<"\n--------------------------------------------------------\n\n";

    while( (comparar_cadenas(la_cadena, DELIMITADOR)) != 0 ){
        cin.getline(la_cadena, MAX_CARACTERES);
        if( comparar_cadenas(la_cadena, DELIMITADOR)!=0){
            cout<<"\n----------------------------------------------------\n\n";

        //Llamamos a la funcion encuentra_palabras qque guardara en el array
        //las_palabras los punteros al inicio y final de todas las palabras 
        //encontradas, ademas de devolver el numero de palabras encontradas
            num_palabras = encuentra_palabras(las_palabras, la_cadena);
            cout<<"El numero de palabras encontradas es "<<num_palabras<<endl;

            cout<<"\n----------------------------------------------------\n\n";

        //Mostramos las palabras que han sido encontradas anteriormente 
        //con la funcion muestrapalabras
            cout<<"LAS PALABRAS SON :\n"<<endl;
            MuestraPalabras(num_palabras, las_palabras);
            cout<<"\n----------------------------------------------------\n\n";
        }
    }

    return 0;
}

