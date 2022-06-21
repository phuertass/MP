#include <iostream>
#include <cstring>
#include "LecturaEnteros.h"
#include "ProcesamientoArrayInt.h"

using namespace std;


int LeeEntero (const char * titulo, bool & valido){
    int inicio = 0;
    int fin = longitud_cadena(titulo);

    return LeeEnteroEnRango(titulo, valido, fin, inicio);
}


int LeeEnteroEnRango(const char * titulo, bool & valido, int fin,
int inicio){

    if(fin<inicio){
        Intercambia(&fin, &inicio);
    }

    char copia[TOPE];
    int tamanio = longitud_cadena(titulo);

    if(tamanio>fin){
        memcpy(copia, titulo, sizeof(char)*fin);
    }else{
        copiar_cadena(copia, titulo);
    }

    
    eliminar_todos_blancos(copia, copia);

    int inicio_separador = inicio;
    if(copia[0]=='-' or copia[0]=='+'){
        inicio_separador++;
    }

    bool sigue=true;
    while(sigue && inicio_separador<tamanio){
        if(copia[inicio_separador] =='-' or
        copia[inicio_separador]=='+'){
            sigue=false;
        }else{
            inicio_separador++;
        }
    }

    valido = true;

    if(sigue)
    {
        for(int i=1; i<tamanio; i++){
             if(copia[i] !='0' && copia[i]!='1' &&
             copia[i] !='2' && copia[i]!='3' &&
             copia[i] !='4' && copia[i]!='5' &&
             copia[i] !='6' && copia[i]!='7' &&
             copia[i] !='8' && copia[i]!='9')
             {
                valido = false;
             }
        }
    }else{
        valido = false;
    }
    
    int ret = atoi(copia);
    return ret;
}

int LeeEnteroMayorOIgual (const char * titulo, int menor){
    
};
