#include <iostream>
#include <iomanip>
#include <cstring>
#include "MiCadenaClasica.h"
using namespace std;

#define TOPE_LINEAS_FORMAT 100
#define TOPE_COLUMNAS_FORMAT 100
/***************************************************************************/
/***************************************************************************/

int main(void)
{
    char resultado[TOPE_LINEAS_FORMAT][TOPE_COLUMNAS_FORMAT+1];
    const int TOPE = 100; 
	char cad[TOPE];
    char * DELIMITADOR = (char *)"FIN";


	int cont = 0;
    while( (comparar_cadenas(cad, DELIMITADOR)) != 0 ){
        cin.getline(cad, TOPE);
        if( comparar_cadenas(cad, DELIMITADOR)!=0 ){
			cout<<cad<<endl;
			memcpy(resultado[cont], cad, sizeof(char)*longitud_cadena(cad));
			resultado[cont][TOPE_COLUMNAS_FORMAT] = '\0';
			cont++;
        }
    }
	cout<<"-------------------------------------------------------------\n";
	cout<<"MATRIZ"<<endl;
	cout<<"-------------------------------------------------------------\n";

	//for(int i=0; i<cont; i++){
	//	cout<<resultado[i]<<endl;
	//}
	
	//Rellenar finales con !
	int num_l = TOPE_LINEAS_FORMAT;
	int num_c = TOPE_COLUMNAS_FORMAT-1;
	int contador_lineas=0;
	while(contador_lineas<num_l){
		for(int i=num_c; i>0; i--){
			if(resultado[contador_lineas][i]==' '){
				resultado[contador_lineas][i] = '!';
			}
		}
		contador_lineas++;
	}

	for(int i=0; i<cont; i++){
		cout<<resultado[i]<<endl;
	}

    return 0;
}

/***************************************************************************/
/***************************************************************************/
