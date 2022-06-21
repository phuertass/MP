#include <iostream>
#include <cstring>
#include "MiCadenaClasica.h"
#include "LecturaEnteros.h"
using namespace std;

#define TOPE 100



int main(){
    char cad[TOPE];
    char * DELIMITADOR = (char *)"FIN";
    bool valido = true;
    cout<<"INTRODUZCA TANTAS CADENAS COMO DESEE PARA PASARLAS A ENTERO";
    cout<<"\nPARA TERMINAR EL PROGRAMA INTRODUZCA LA PALABRA 'FIN'";
    cout<<"\nSI ESCRIBE UN NUMERO NO VALIDO EL PROGRAMA FINALIZARA \n\n";

    while( (comparar_cadenas(cad, DELIMITADOR)) != 0 ){
        cin.getline(cad, TOPE);
        if( comparar_cadenas(cad, DELIMITADOR)!=0){
        
            cout<<"\n----------------------------------------------------\n\n";
            cout<<"La cadena leida es: "<<endl;
            cout<<"|"<<cad<<"|"<<endl;

            cout<<"--------------------------------------------------------\n";
            int ret = LeeEntero(cad,valido);

            if(valido){
                cout<<"El numero es-> "<<ret<<endl;
                cout<<"----------------------------------------------------\n"; 
            }else{
                cout<<"CADENA NO VALIDA"<<endl;
                cout<<"----------------------------------------------------\n";
            }
            cout<<"INTRODUZCA UNA NUEVA CADENA ->";


        }
    }

    cout<<"INTRODUZCA TANTAS CADENAS COMO DESEE PARA PASARLAS A ENTERO EN ";
    cout<<"UN RANGO";
    cout<<"\nPARA TERMINAR EL PROGRAMA INTRODUZCA LA PALABRA 'FIN'";
    cout<<"\nSI ESCRIBE UN NUMERO NO VALIDO EL PROGRAMA FINALIZARA \n\n";

    int extremorango1;
    char cad2[TOPE];
    bool valido2=true;

    while( (comparar_cadenas(cad2, DELIMITADOR)) != 0 ){
        cin.getline(cad2, TOPE);
        while(longitud_cadena(cad2)==0){
            cin.getline(cad2,TOPE);
        }
        if( comparar_cadenas(cad2, DELIMITADOR)!=0){

            cout<<"\n----------------------------------------------------\n\n";
            cout<<"La cadena leida es: "<<endl;
            cout<<"|"<<cad2<<"|"<<endl;

            cout<<"--------------------------------------------------------\n";
            cout<<"Introduzca un extremo del rango-->";
            cin>>extremorango1;
            

            
            int ret2= LeeEnteroEnRango(cad2,valido2,extremorango1,0);
            cout<<"El numero es-> "<<ret2<<endl;
            cout<<"INTRODUZCA UNA NUEVA CADENA ->";
        }
    }

    return 0;
}


