#include "MiCadenaClasica.h"
#include <iostream>
#include <cctype>

using namespace std;
/*
Escriba un programa que lea una serie indeterminada de líneas (finaliza cuando lee
una línea que contiene únicamente FIN). Mostrará cada línea leida y el resultado de
aplicar las funciones indicadas anteriormente.
Finalmente indicará el porcentaje de separadores presentes en el texto original com-
pleto. Realice este cálculo en la función main sin recorrer, casilla a casilla, las cadenas
leidas.
*/
int main(){
    const int TOPE = 100; 
	char cad[TOPE];
    char * DELIMITADOR = (char *)"FIN";
    char * cad_auxiliar;
    int contador_de_separadores = 0;
    int tamanio_total_texto = 0;

    int tam_cad_original=0;
    int tam_cad_auxiliar=0;
    int saltos_de_linea = 0;
    //Vamos leyendo cadenas hasta que se lea la cadena "FIN"
    while( (comparar_cadenas(cad, DELIMITADOR)) != 0 ){
        cin.getline(cad, TOPE);
        if( comparar_cadenas(cad, DELIMITADOR)!=0){
        
        //Vamos usando las diferente funciones implementadas para ver su
        //funcionamiento
        cout<<"\n----------------------------------------------------\n\n";
        cout<<"La cadena leida es: "<<endl;
        cout<<"|"<<cad<<"|"<<endl;
        cad_auxiliar = copiar_cadena(cad_auxiliar, cad);

        cout<<"\n----------------------------------------------------\n\n";
        cout<<"ELIMINANDO BLANCOS INICIALES..."<<endl;
        cad_auxiliar =eliminar_blancos_iniciales(cad_auxiliar, cad);
        cout<<"|"<<cad_auxiliar<<"|"<<endl;

        cad_auxiliar = copiar_cadena(cad_auxiliar, cad);
        cout<<"\n----------------------------------------------------\n\n";
        cout<<"ELIMINANDO BLANCOS FINALES..."<<endl;
        cad_auxiliar=eliminar_blancos_finales(cad_auxiliar, cad);
        cout<<"|"<<cad_auxiliar<<"|"<<endl;

        cad_auxiliar = copiar_cadena(cad_auxiliar, cad);
        cout<<"\n----------------------------------------------------\n\n";
        cout<<"ELIMINANDO BLANCOS EXTREMOS..."<<endl;
        cad_auxiliar = eliminar_blancos_extremos(cad_auxiliar, cad);
        cout<<"|"<<cad_auxiliar<<"|"<<endl;

        cad_auxiliar = copiar_cadena(cad_auxiliar, cad);
        cout<<"\n----------------------------------------------------\n\n";
        cout<<"ELIMINANDO BLANCOS INTERMEDIOS..."<<endl;
        cad_auxiliar=eliminar_blancos_intermedios(cad_auxiliar, cad);
        cout<<"|"<<cad_auxiliar<<"|"<<endl;

        cad_auxiliar = copiar_cadena(cad_auxiliar, cad);
        cout<<"\n----------------------------------------------------\n\n";
        cout<<"ELIMINANDO TODOS LOS BLANCOS..."<<endl;
        cad_auxiliar=eliminar_todos_blancos(cad_auxiliar, cad);
        cout<<"|"<<cad_auxiliar<<"|"<<endl;

        //La cantidad de separadores sera la diferencia de longitud de la
        //cadena leida y la cadena sin espacios en blanco
        tam_cad_original = longitud_cadena(cad);
        tam_cad_auxiliar = longitud_cadena(cad_auxiliar);
        //Las variables contador de separadores y tamanio total texto
        //almacenaran valores que luego seran necesarios
        contador_de_separadores+=(tam_cad_original-tam_cad_auxiliar);
        tamanio_total_texto+=tam_cad_original;
        saltos_de_linea++;
        }

    }

    //Para calcular el porcentaje de separadores en el texto calcularemos
    //el cociente del numero total de separadores de este y la longitud 
    //total del texto introducido
    cout<<"\nCANTIDAD TOTAL DE SEPARADORES-> "<<contador_de_separadores
    +saltos_de_linea<<endl;
    cout<<"TAMANIO TOTAL DEL TEXTO-> "<<tamanio_total_texto<<endl;
    cout<<"EL PORCENTAJE DE SEPARADORES EN EL TEXTO ES-> ";
    
    cout<<(double)(contador_de_separadores+saltos_de_linea)
    /tamanio_total_texto*100<<"%\n";

    return 0;

}