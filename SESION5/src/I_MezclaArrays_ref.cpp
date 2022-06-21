#include <iostream>
#include "ProcesamientoArrayInt.h"

using namespace std; 

#define numeros_linea 20
#define TAM 100
#define min_aleat 1
#define max_aleat 200

int main(int argc, char **argv){


/*Si el programa se ejecuta sin argumentos, los dos vectores de entrada se 
ocuparán completamente (TAM casillas) y se rellenarán, con valores aleatorios 
entre 1 y 200 (ambos incluidos).
• Si el programa se ejecuta con un argumento, los dos vectores de entrada se
ocuparán se ocuparán parcialmente. El número de casillas ocupadas en am-
bos vectores será el valor que indiquemos con el único parámetro. Se generarán
valores aleatorios entre 1 y 200 (ambos incluidos).
• Si se ejecuta con dos argumentos, los dos vectores de entrada se ocuparán 
parcialmente. El número de casillas ocupadas en ambos vectores será el valor 
que indiquemos en el primer argumento. El segundo argumento indica el mayor 
valor aleatorio permitido, por lo que se generarán valores aleatorios entre 1 
y ese valor.
Si se ejecuta con tres argumentos, los dos vectores de entrada se ocuparán par-
cialmente. El número de casillas ocupadas en ambos vectores será el valor que
indiquemos en el primer argumento. Los otros dos argumentos indican el menor
y mayor valor aleatorio permitido (no necesariamente en este orden).*/

    int v1 [TAM]; int v2 [TAM]; 

    //.......................................................................
	// Comprobaci�n argumentos 

	if (argc>4) {
		cerr << "Error: demasiados argumentos" << endl;
		cerr << "Uso: " << argv[0] << " [casillas_a_rellenar] [max_aleatorio] "
        <<"[min_aelatorio]";
		cerr << endl << endl;
		exit(1);
	}
	
	// Valores por defecto

	int usados = TAM;
	int maximo_aleatorio = max_aleat;
	int minimo_aleatorio = min_aleat;;

	// Otros valores 

	if (argc > 1) { // Al menos 1 arg. real

		usados = atoi(argv[1]); // actualizar "usados" con argv[1] 

		if (argc > 2) { // Al menos 2 args. reales

			maximo_aleatorio = atoi(argv[2]); // actualizar "max_aleat"
                            //con argv[2]. "min_aleat" es 1 (valor por defecto)
	
			if (argc > 3) {	// 3 args. reales
				minimo_aleatorio = atoi(argv[3]); 
			}
		}
	}

    //Si a introducido los valores al reves, los corregimos
    if(maximo_aleatorio<minimo_aleatorio)
        Intercambia(&maximo_aleatorio, &minimo_aleatorio);

    //Rellenamos los dos vectores con valores aleatorios
    RellenaVector(v1, usados, minimo_aleatorio, maximo_aleatorio);
    RellenaVector(v2, usados, minimo_aleatorio, maximo_aleatorio);

    //Los ordenamos y los mostramos posteriormente
    OrdenaIntercambioMejorado(v1, usados);
    OrdenaIntercambioMejorado(v2, usados);

    MuestraVector("Vector 1->\n", v1, usados, numeros_linea);
    MuestraVector("Vector 2->\n", v2, usados, numeros_linea);

    int res [2*TAM];
    int usados_res=0;
    int res2 [2*TAM];
    int usados_res2=0;

    //Mezclamos los vectores de la forma selectiva(sin repetidos)
    MezclaVectores(res, usados_res, v1, usados, v2, usados, "si");
    MuestraVector("Vector mezclado selectivamente->\n",res, usados_res,
    numeros_linea);
    
    //Mezclamos los vectores de la forma clasica
    MezclaVectores(res2, usados_res2, v1, usados, v2, usados);
    MuestraVector("Vector mezclado no selectivamente->\n",res2, usados_res2,
    numeros_linea);

    return 0;
}
