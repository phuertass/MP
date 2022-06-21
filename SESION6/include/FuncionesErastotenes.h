#ifndef FUNCIONES_ERASTOTENES
#define FUNCIONES_ERASTOTENES

#include "FuncsVectorDinamico.h"

// struct para guardar las parejas primo-potencia
struct Pareja {
		int primo;		// Número primo (factor primo)
		int potencia;	// Veces que aparece en la descomposición 
};

//Funcion que rellena un vector booleano con los numeros primos a true
//Tambien modifica el vector primos y le introduce todos los numeros primos
//previamente calculados
//int CalcularPrimos(bool es_primo[],int primos[],int MAX_PRIMO,int MAX_DATOS);
int CalcularPrimos(bool es_primo[], VectorDinamico & primos, int maximo_primos);

//Funcion para mostrar los primeros num_primos numeros del vector primos

void MostrarPrimos(VectorDinamico primos, int num_primos);
#endif