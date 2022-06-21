#include "FuncionesErastotenes.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Funcion que rellena un vector booleano con los numeros primos a true
//Tambien modifica el vector primos y le introduce todos los numeros primos
//previamente calculados
int CalcularPrimos(bool es_primo[],int primos[],int MAX_PRIMO,int MAX_DATOS){
	// Inicialmente se considerarán todos primos y se irán "tachando" 
	// (fijándose a FALSE) los valores no-primos. 
	
	for (int i=0; i<=MAX_PRIMO; i++) 
		es_primo[i] = true;

	// Criba 
	
	for (int num=2; num*num <= MAX_PRIMO; num++) { // empezar por num=2 y 
										           // terminar si num^2>limite		
		if (es_primo[num]) {

			for (int k=2; k*num <= MAX_PRIMO; k++) { // marcar los múltiplos de   
				es_primo[k*num] = false;		  	 // "num" como no-primos
			}
		} // if (es_primo[num])

	} // for num


	int num_primos = 0; // Número de casillas ocupadas
	//PRE: 0 <= num_primos < MAX_DATOS
		
	// Ya están "tachados" los números no-primos en "es_primo".  
	// Ahora recorremos "es_primo" completamente y copiamos a 
	// "primos" únicamente los que permacenen a "true". 

	for (int i=1; i<=MAX_PRIMO; i++) { 
									
		if (es_primo[i]) {	
		
			if (num_primos<MAX_DATOS) {
				primos[num_primos] = i;  // Añadir "i" a "primos"
				num_primos++;  	// Actualizar "num_primos"
			}
		}
		
	} // for
	return num_primos;
};

//Funcion para mostrar los primeros num_primos numeros del vector primos
void MostrarPrimos(int primos[], int num_primos, int DATOS_POR_LINEA){
	cout << endl;
	cout << "Se han calculado " << num_primos << " primos." << endl;
	cout << endl;

	cout << "------------------------------------------------" << endl;
	cout << "Primos calculados: " << endl; 
	cout << endl; 


	for (int i=0; i<num_primos; i++) 
		cout <<setw(4) << primos[i] << (((i+1)%DATOS_POR_LINEA!=0)?" ":"\n");
	cout << endl;		

	cout << endl; 
	cout << "------------------------------------------------" << endl;
}