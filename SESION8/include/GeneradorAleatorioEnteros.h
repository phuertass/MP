/***************************************************************************/
// Clase: GeneradorAleatorioEnteros
// 
// Declaraci�n de la clase "GeneradorAleatorioEnteros"
//
// Fichero: GeneradorAleatorioEnteros.h
/*
	Sirve para generar n�meros aleatorios enteros en un rango de valores.
	
	Hay crear un objeto de esta clase. Se dispone de dos constructores: 
	1) GeneradorAleatorioEnteros()
	   		El primero no tiene par�metros y establece que �nicamente se 
			van a generar ceros y unos (este constructor llama al segundo). 
	2) GeneradorAleatorioEnteros(int min, int max)
		El segundo tiene dos par�metros, "min" y "max" que delimitan el 
		rango correspondiente. 

	Finalmente, el m�todo 
	
		int Siguiente()
	
	devolver� un valor aleatorio en el rango especificado en el constructor.
*/
/***************************************************************************/

#ifndef GENERADOR_ALEATORIO_ENTEROS
#define GENERADOR_ALEATORIO_ENTEROS

#include<cstdlib>
#include<cctype>

#include <random>  
#include <chrono>  

using namespace std;

/////////////////////////////////////////////////////////////////////////////
class GeneradorAleatorioEnteros
{  
private:
	
   mt19937 generador_mersenne;    // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;
   
public:
	
	/************************************************************************/	
	// Constructor sin argumentos: 
	// Inicializa el generador para proporcionar nums. aleatorios entre 0 y 1

	GeneradorAleatorioEnteros();
   
  	/************************************************************************/  
	// Constructor con argumentos: 
	// Inicializa el generador para proporcionar nums. aleatorios entre "min" 
	// y "max"
	
	GeneradorAleatorioEnteros(int min, int max);
   
	/************************************************************************/
	// Devuelve un nuevo n�mero aleatorio

	int Siguiente();

	/************************************************************************/

private: 

    /************************************************************************/
	// M�todos privados de la clase
    /************************************************************************/

	long long Nanosec();

   /************************************************************************/ 

};

/////////////////////////////////////////////////////////////////////////////

#endif
