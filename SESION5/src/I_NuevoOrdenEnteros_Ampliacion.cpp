
#include <iostream>
#include <iomanip>
#include <cstring>

#include "ProcesamientoArrayInt.h"

using namespace std;

/***************************************************************************/
// Calcula cuántas veces aparece el dígito "digito" en "num" 
int  Veces (int digito, int num);

/***************************************************************************/
/***************************************************************************/
// Un valor entero "a" será menor que otro "b" si el número de dígitos '9' es 
// menor en "a" que en "b". Si el número de '9' es igual en los dos, el menor  
// será el que tiene menos '8'. Si hay empate también con este dígito, se 
// considera el '7'. Así hasta llegar al '0', si fuese necesario. 
// Si la frecuencia de todos los dígitos es igual en ambos valores 
// -independientemente de su orden-, se les considera iguales.


bool MenorNuevoOrdenEnteros (int a, int b);

void OrdenaSeleccionNuevoOrdenEnteros (int *v, int tamanio);
void OrdenaInsercionNuevoOrdenEnteros (int *v, int tamanio);
void OrdenaIntercambioNuevoOrdenEnteros (int *v, int tamanio);

int main(int argc, char **argv)
{
	const int TOPE = 10;			// Num. de casillas del vector 
	int v[TOPE];
	int v2[TOPE];
	int v3[TOPE];

	const int MIN_ALEAT = 0;    // Mínimo valor aleatorio permitido
	const int MAX_ALEAT = 999;	// Máximo valor aleatorio permitido

	const int NUM_DATOS_LINEA = 10;		// Num. maximo de enteros por linea

	//.......................................................................
	// Comprobación argumentos 

	if (argc>4) {
		cerr << "Error: demasiados argumentos" << endl << endl;
		exit(1);
	}
	
	// Valores por defecto

	int usados = TOPE;
	int min_aleat = MIN_ALEAT;
	int max_aleat = MAX_ALEAT;


	// Otros valores 

	if (argc > 1) {

		usados = atoi(argv[1]); // "usados" será argv[1] 
	
		if (argc > 2) {

			max_aleat = atoi(argv[2]); // actualizar "max_aleat". 
									   // "min_aleat" es MIN_ALEAT
			if (argc > 3) {	

				max_aleat = atoi(argv[2]); // actualizar "max_aleat" y 
				min_aleat = atoi(argv[3]); // "min_aleat"

				// Intercambiar los valores de "max_aleat" y "min_aleat"
				// si fuera necesario

				if (min_aleat > max_aleat) 
					Intercambia(&min_aleat, &max_aleat);
			}
		}
	}

	// Comprobar la validez de "usados"
	if (usados <= 0 || usados > TOPE)  {
		cerr << "Error: numero de casillas (" << usados << ") incorrecto. "; 
		cerr << "Debe ser 0 < casillas <= " << TOPE << endl << endl;
		exit(2);
	}

	cout << endl; 
	cout << "Se va a crear un array de " << usados << " datos." << endl;
	cout << "Los datos estarán comprendidos entre "<< min_aleat << " y " 
         << max_aleat << " (incluidos)" << endl; 
	cout << endl; 

	// Fin comprobación argumentos
	//.......................................................................

	// Rellenar el vector con numeros aleatorios 

	RellenaVector (v, usados, min_aleat, max_aleat);

	// Mostrar el vector original
	MuestraVector ("Vector original: ", v, usados, NUM_DATOS_LINEA);
	cout<<"--------------------------------------------------------------\n\n";

	// Antes de ordenar, hacer una copia para mantener los datos originales 
	int copia_v [TOPE]; 
	memcpy (copia_v, v, usados*sizeof(int));
	memcpy (v2, v, usados*sizeof(int));
	memcpy (v3, v, usados*sizeof(int));


	//.............................................................
	// SELECCION
	//-------------------------------------------------------------------------

	//Clasico
	OrdenaSeleccion (v, usados);

	// Mostrar el vector ordenado
	MuestraVector ("Vector ordenado (selección clasico): ",
	v,usados,NUM_DATOS_LINEA);  


	//.............................................................
	// Antes de volver a ordenar, recuperar la copia para ordenar 
	// sobre los datos originales 
	memcpy (v, copia_v, usados*sizeof(int));


	//.............................................................
	// Ordenacion por seleccion (nuevo orden)
	OrdenaSeleccionNuevoOrdenEnteros (v, usados);

	// Mostrar el vector ordenado
	MuestraVector ("Vector ordenado (selección nuevo orden): ", 
		           v, usados,NUM_DATOS_LINEA);

	//.............................................................
	// Antes de volver a ordenar, recuperar la copia para ordenar 
	// sobre los datos originales 
	memcpy (v, copia_v, usados*sizeof(int));


	//.............................................................
	// Ordenacion por seleccion (primera cifra)
	OrdenaSeleccionPrimeraCifra (v, usados);

	// Mostrar el vector ordenado
	MuestraVector ("Vector ordenado (seleccion primera cifra): ", 
		           v, usados,NUM_DATOS_LINEA); 
	
	cout<<"--------------------------------------------------------------\n\n";


	//-------------------------------------------------------------------------
	//INSERCION
	//-------------------------------------------------------------------------
	//Clasico
	OrdenaInsercion (v2, usados);

	// Mostrar el vector ordenado
	MuestraVector ("Vector ordenado (insercion clasico): ", 
	v2,usados,NUM_DATOS_LINEA);  


	//.............................................................
	// Antes de volver a ordenar, recuperar la copia para ordenar 
	// sobre los datos originales 
	memcpy (v2, copia_v, usados*sizeof(int));


	//.............................................................
	// Ordenacion por insercion (nuevo orden)
	OrdenaInsercionNuevoOrdenEnteros (v2, usados);

	// Mostrar el vector ordenado
	MuestraVector ("Vector ordenado (insercion nuevo orden): ", 
		           v2, usados,NUM_DATOS_LINEA);

	//.............................................................
	// Antes de volver a ordenar, recuperar la copia para ordenar 
	// sobre los datos originales 
	memcpy (v2, copia_v, usados*sizeof(int));


	//.............................................................
	// Ordenacion por seleccion (primera cifra)
	OrdenaInsercionPrimeraCifra (v2, usados);

	// Mostrar el vector ordenado
	MuestraVector ("Vector ordenado (insercion primera cifra): ", 
		           v2, usados,NUM_DATOS_LINEA); 

	cout<<"--------------------------------------------------------------\n\n";


	//-------------------------------------------------------------------------
	//INTERCAMBIO
	//-------------------------------------------------------------------------
	//Clasico
	OrdenaIntercambio (v3, usados);

	// Mostrar el vector ordenado
	MuestraVector ("Vector ordenado (intercambio clasico): ",
	v3,usados,NUM_DATOS_LINEA);  


	//.............................................................
	// Antes de volver a ordenar, recuperar la copia para ordenar 
	// sobre los datos originales 
	memcpy (v3, copia_v, usados*sizeof(int));


	//.............................................................
	// Ordenacion por intercambio (nuevo orden)
	OrdenaIntercambioNuevoOrdenEnteros (v3, usados);

	// Mostrar el vector ordenado
	MuestraVector ("Vector ordenado (intercambio nuevo orden): ", 
		           v3, usados,NUM_DATOS_LINEA);

	//.............................................................
	// Antes de volver a ordenar, recuperar la copia para ordenar 
	// sobre los datos originales 
	memcpy (v3, copia_v, usados*sizeof(int));


	//.............................................................
	// Ordenacion por intercambio (primera cifra)
	OrdenaSeleccionPrimeraCifra (v3, usados);

	// Mostrar el vector ordenado
	MuestraVector ("Vector ordenado (primera cifra): ", 
		           v3, usados,NUM_DATOS_LINEA); 

	cout<<"--------------------------------------------------------------\n\n"; 
	return 0;
}


/***************************************************************************/
/***************************************************************************/
// Ordenación por intercambio (nuevo orden enteros)
//
// Recibe:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		tamanio, número de elementos del subvector a ordenar. 

void OrdenaIntercambioNuevoOrdenEnteros (int *v, int tamanio) 
{
    for(int izquierda=0; izquierda<tamanio; izquierda++){
        for(int i=tamanio-1; i>izquierda; i--){
			if(MenorNuevoOrdenEnteros(v[i], v[i-1])){
				Intercambia((v+i), (v+i-1));
            }
        }
    }

}
/***************************************************************************/
/***************************************************************************/
// Ordenación por insercion (nuevo orden enteros)
//
// Recibe:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		tamanio, número de elementos del subvector a ordenar. 

void OrdenaInsercionNuevoOrdenEnteros (int *v, int tamanio) 
{
    for(int izda=1; izda<tamanio; izda++){
        int a_insertar=*(v+izda);
        int i=izda;
        while( (i>0) && 
		MenorNuevoOrdenEnteros(a_insertar,*(v+i-1) ))
		{
            *(v+i) = *(v+i-1);
            i--;
        }
        *(v+i) = a_insertar;
    }

}

/***************************************************************************/
/***************************************************************************/
// Ordenación por selección (nuevo orden enteros)
//
// Recibe:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		tamanio, número de elementos del subvector a ordenar. 

void OrdenaSeleccionNuevoOrdenEnteros (int *v, int tamanio) 
{
	for (int izda = 0 ; izda < tamanio ; izda++){

	// Calcular el mÃ­nimo entre "izda" y "total_utilizados"-1

	int minimo = v[izda]; // Valor del mínimo
	int pos_min = izda;   // Posición del mínimo

	for (int i = izda + 1; i < tamanio ; i++)

		if (MenorNuevoOrdenEnteros(v[i],minimo)){ // Nuevo mínimo
		    minimo = v[i];
		    pos_min = i;
		 }

		// Intercambiar los valores guardados en "izda" y "pos_min"  

		Intercambia (&v[izda], &v[pos_min]);
   }
}

/***************************************************************************/
/***************************************************************************/
// Un valor entero "a" será menor que otro "b" si el número de dígitos '9' es 
// menor en "a" que en "b". Si el número de '9' es igual en los dos, el menor  
// será el que tiene menos '8'. Si hay empate también con este dígito, se 
// considera el '7'. Así hasta llegar al '0', si fuese necesario. 
// Si la frecuencia de todos los dígitos es igual en ambos valores 
// -independientemente de su orden-, se les considera iguales.

bool MenorNuevoOrdenEnteros (int a, int b)
{
	int digito_ref = 9;

	/* Estilo clasico 

	int ref_a = Veces(digito_ref, a);
 	int ref_b = Veces(digito_ref, b);

	while ((ref_a == ref_b) && (digito_ref >= 0)) {

		digito_ref--;

		ref_a = Veces(digito_ref, a);
 		ref_b = Veces(digito_ref, b);
	}
	*/

	int ref_a, ref_b;

	while (((ref_a=Veces(digito_ref,a)) == (ref_b=Veces(digito_ref,b))) 
            && (digito_ref >= 0))

		digito_ref--;

	return (ref_a < ref_b); 
}

/***************************************************************************/
/***************************************************************************/
// Calcula cuántas veces aparece el dígito "digito" en "num" 

int Veces(int digito, int num) 
{
	int cont=0; 

	while (num > 0) {

		if (num % 10 == digito) 
			cont++;

		num = num / 10; 
	}

	return (cont); 
}

/***************************************************************************/
/***************************************************************************/
