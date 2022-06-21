#include "FuncionesErastotenes.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Funcion que rellena un vector booleano con los numeros primos a true
//Tambien modifica el vector primos y le introduce todos los numeros primos
//previamente calculados
int CalcularPrimos(bool es_primo[], VectorDinamico & primos, int maximo_primos)
{
    for (int i=0; i<=maximo_primos; i++) 
		es_primo[i] = true;    
    
    // Criba
	for (int num=2; num*num <= maximo_primos; num++) { // empezar por num=2 y 
										           // terminar si num^2>limite		
		if (es_primo[num]) {

			for (int k=2; k*num <= maximo_primos; k++) { // marcar los múltiplos de   
				es_primo[k*num] = false;		  	 // "num" como no-primos
			}
		} // if (es_primo[num])

	} // for num

    int num_primos = 0; // Número de casillas ocupadas
	//PRE: 0 <= num_primos < MAX_DATOS
		
	// Ya están "tachados" los números no-primos en "es_primo".  
	// Ahora recorremos "es_primo" completamente y copiamos a 
	// "primos" únicamente los que permacenen a "true". 

	for (int i=1; i<=maximo_primos; i++) { 
									
		if (es_primo[i]) {	
		
			if (num_primos<maximo_primos) {
				AniadeVectorDinamico(primos, i);  // Añadir "i" a "primos"
				num_primos++;  	// Actualizar "num_primos"
			}
		}
		
	} // for
	return num_primos;


};

void MostrarPrimos(VectorDinamico primos, int num_primos)
{
    cout << ToString(primos);
};