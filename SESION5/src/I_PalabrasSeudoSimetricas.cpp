#include <iostream>
#include <cstring>
#include "MiCadenaClasica.h"
using namespace std;

int main(){

    const int TOPE = 100; 
	char cad[TOPE];
    char * DELIMITADOR = (char *)"FIN";
    char cad_auxiliar1[TOPE];
    char cad_auxiliar2[TOPE];

    cout<<"INTRODUZCA TANTAS PALABRAS COMO DESEE SABER SI SON SEUDOSIMETRICAS";
    cout<<"\nPARA TERMINAR EL PROGRAMA INTRODUZCA LA PALABRA 'FIN' \n";

    while( (comparar_cadenas(cad, DELIMITADOR)) != 0 ){
        cin.getline(cad, TOPE);
        if( comparar_cadenas(cad, DELIMITADOR)!=0){
        
            cout<<"\n----------------------------------------------------\n\n";
            cout<<"La cadena leida es: "<<endl;
            cout<<"|"<<cad<<"|"<<endl;
            int tamanio = longitud_cadena(cad);
   
            memcpy(cad_auxiliar1, cad, sizeof(int)*(tamanio+1));
            memcpy(cad_auxiliar2, cad, sizeof(int)*(tamanio+1));

            cout<<"Calculando si es seudosimetrica...\n";
            bool seudosimetrica = es_seudosimetrica(cad, cad_auxiliar1,
            cad_auxiliar2);
            if(seudosimetrica){
                cout<<"ES SEUDOSIMETRICA"<<endl;
            }else{
                cout<<"NO ES SEUDOSIMETRICA"<<endl;
            }
        }
    }

    return 0;
};
