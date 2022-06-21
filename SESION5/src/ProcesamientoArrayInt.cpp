/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Fichero: ProcesamientoArrayInt.cpp
//
/***************************************************************************/
 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

#include "GeneradorAleatorioEnteros.h"
#include "ProcesamientoArrayInt.h"
#include <cstring>

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Muestra el contenido de un vector de datos int con los datos alineados.   
// Con más precisión, muestra la parte comprendida desde el elemento cuya 
// dirección es "p" que tiene "n_datos" elementos). 
// Se muestra con el encabezamiento dado por "msg" y en cada línea se 
// imprimen, alineados, "datos_linea" datos. 
//
// Parámetros:
//		mensaje, "título" que encabeza la presentación
// 		p, n_datos de memoria del inicio el vector  
//		n_datos, número de casillas ocupadas del vector
//		datos_linea, número de valores que se muestran en  cada línea

void MuestraVector (string mensaje, int *p, int n_datos, int datos_linea)
{
	cout << mensaje << endl;

	for (int i=0; i<n_datos; i++) 
		cout <<setw(4)<< *(p+i) << ((((i+1)%datos_linea)==0)?"\n":" ");

	cout << endl << endl;
}

/***************************************************************************/
/***************************************************************************/
// Rellena un vector de datos int con "n_datos" números aleatorios.  
// Se rellenarán las primeras "n_datos" casillas a partir de la dirección 
// dada en "p". 
// Los valores están comprendidos entre "min_aleat" y "max_aleat". 
// Parámetros:
//		p, dirección de memoria donde se empieza a rellenar. 
//		num_datos, número de casillas a rellenar.
//		min_aleat y max_aleat, mínimo y máximo valor aleatorio.  
// PRE: num_datos >= 0
// PRE: min_aleat <= max_aleat

void RellenaVector (int *p, int num_datos,  const int min_aleat, 
	                 const int max_aleat)
{
	// Rellenar el vector con valores aleatorios entre "min" y "max" 
	GeneradorAleatorioEnteros generador (min_aleat, max_aleat);

	for (int i=0; i<num_datos; i++) 
      *(p+i) = generador.Siguiente();
}

/***************************************************************************/
/***************************************************************************/
// Ordenación por selección
// 
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		pos_inic, pos_fin, posiciones entre las que ordenar.
// PRE: pos_inic <= pos_fin
// PRE: pos_inic y pos_fin son correctas

void OrdenaSeleccion (int *v, int pos_inic, int pos_fin)
{
	OrdenaSeleccion (v+pos_inic, pos_fin-pos_inic+1);
}

/***************************************************************************/
/***************************************************************************/
// Ordenación por inserción
// 
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		pos_inic, pos_fin, posiciones entre las que ordenar.
// PRE: pos_inic <= pos_fin
// PRE: pos_inic y pos_fin son correctas

void OrdenaInsercion (int *v, int pos_inic, int pos_fin)
{
	OrdenaInsercion (v+pos_inic, pos_fin-pos_inic+1);
}

/***************************************************************************/
/***************************************************************************/
// Ordenación por intercambio
// 
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		pos_inic, pos_fin, posiciones entre las que ordenar.
// PRE: pos_inic <= pos_fin
// PRE: pos_inic y pos_fin son correctas

void OrdenaIntercambio (int *v, int pos_inic, int pos_fin)
{
	OrdenaIntercambio (v+pos_inic, pos_fin-pos_inic+1);
}

/***************************************************************************/
/***************************************************************************/
// Ordenación por intercambio mejorado
// 
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		pos_inic, pos_fin, posiciones entre las que ordenar.
// PRE: pos_inic <= pos_fin
// PRE: pos_inic y pos_fin son correctas

void OrdenaIntercambioMejorado (int *v, int pos_inic, int pos_fin)
{
	OrdenaIntercambioMejorado (v+pos_inic, pos_fin-pos_inic+1);
}

/***************************************************************************/
/***************************************************************************/
// Ordenación por selección
// 
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		tamanio, número de elementos del subvector a ordenar. 
// PRE: tamanio >= 0

void OrdenaSeleccion (int *v, int tamanio) 
{
	for (int izda = 0; izda < tamanio; izda++) {

		// Calcular el mínimo entre "izda" y "total_utilizados"-1

		int minimo = v[izda]; // Valor del mínimo
		int pos_min = izda;   // Posición del mínimo

		for (int i = izda + 1; i < tamanio; i++)

			if (v[i] < minimo){ // Nuevo mínimo
			    minimo = v[i];
			    pos_min = i;
			 }

		// Intercambiar los valores guardados en "izda" y "pos_min"  

		Intercambia (&v[izda], &v[pos_min]);
   }
}

/***************************************************************************/
/***************************************************************************/
// Ordenación por inserción
//
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		tamanio, número de elementos del subvector a ordenar. 
// PRE: tamanio >= 0

void OrdenaInsercion (int *v, int tamanio) 
{
	for (int izda = 1; izda < tamanio; izda++){

		// "a_insertar" es el valor que se va a insertar en el 
		// subvector izquierdo. Este subvector está ordenado y 
		// comprende las posiciones entre 0 e "izda"-1

		int a_insertar = v[izda]; 

		// Se busca la posición en la zona ordenada


		int i = izda; 
		while (i > 0 && a_insertar < v[i-1]) {

			v[i] = v[i-1]; // Desplazar a la derecha los 
						    // valores mayores que "a_insertar"
			i--;
		}

		v[i] = a_insertar; // Copiar -insertar- en el hueco
	}
}


/***************************************************************************/
/***************************************************************************/
// Ordenación por intercambio
//
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		tamanio, número de elementos del subvector a ordenar. 
// PRE: tamanio >= 0

void OrdenaIntercambio (int *v, int tamanio) 
{
	for (int izda = 0; izda < tamanio; izda++)

		for (int i = tamanio-1 ; i > izda; i--)

			if (v[i] < v[i-1]) // Intercambiar 

				Intercambia (&v[i], &v[i-1]);
}


/***************************************************************************/
/***************************************************************************/
// Ordenación por intercambio mejorado
//
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		tamanio, número de elementos del subvector a ordenar. 
// PRE: tamanio >= 0

void OrdenaIntercambioMejorado (int *v, int tamanio) 
{
	bool cambio = true; // Para entrar

	int izda = 0; 

	while (izda < tamanio && cambio) {

		// En cada pasada iniciamos "cambio" a false. 
		// Se pondrá true si y solo si hay algún intercambio

		cambio = false;

		for (int i = tamanio-1; i > izda; i--)

			if (v[i] < v[i-1]) { // Intercambiar 

				Intercambia (&v[i], &v[i-1]);

				cambio = true; // Se ha hecho un intercambio
			}

		izda++;
	}
}

/***************************************************************************/
/***************************************************************************/
// Mezcla dos vectores.
// Parámetros:
//		mezcla, dirección de memoria del inicio el vector resultado  
//		v1, dirección de memoria del inicio del primer vector a mezclar  
//		util_v1, número de casillas ocupadas en "v1"
//		v2, dirección de memoria del inicio del segundo vector a mezclar  
//		util_v2, número de casillas ocupadas en "v2"
// PRE: "v1" y "v2" están ordenados
// PRE: "mezcla" tiene suficiente memoria asignada
// PRE: util_v1, util_v2 >= 0

void MezclaVectoresSimple (int *mezcla, int *v1, int util_v1, int *v2, 
	int util_v2)
{
	// Colocar punteros al inicio de los vectores
	int * p1 = v1;
	int * p2 = v2;
	int * p3 = mezcla;

	// Marcar el final de los vectores a mezclar
	int * end1 = v1+util_v1;
	int * end2 = v2+util_v2;

	// mientras queden en los dos vectores

	while ((p1<end1) && (p2<end2)) {
		
		if (*p1 < *p2) {
			*p3 = *p1;   // copiar de v1
			p1++;
			
		}
		else {
			*p3 = *p2;   // copiar de v2
			p2++;
		}

		p3++;
	}

	// copiar lo que quede en v1

	while (p1<end1){

		*p3 = *p1;
		p1++;

		p3++;
	} 
	
	// copiar lo que quede en v2

	while (p2<end2){

		*p3 = *p2;
		p2++;

		p3++;
	}
}



/***************************************************************************/
/***************************************************************************/
// Intercambia los valores cuyas direcciones están en "p1" y "p2"

void Intercambia (int * p1, int * p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


/***************************************************************************/
/***************************************************************************/
// Mezcla dos vectores.
// Parámetros:
//		mezcla, dirección de memoria del inicio el vector resultado  
//		v1, dirección de memoria del inicio del primer vector a mezclar  
//		util_v1, número de casillas ocupadas en "v1"
//		v2, dirección de memoria del inicio del segundo vector a mezclar  
//		util_v2, número de casillas ocupadas en "v2"
//		selectiva = "SI" si desea mezcla selectiva
// PRE: "v1" y "v2" están ordenados
// PRE: "mezcla" tiene suficiente memoria asignada
// PRE: util_v1, util_v2 >= 0
void MezclaVectores (int mezcla[], int &util_mezcla,
int v1[], int util_v1, int v2[], int util_v2,
const char * selectiva )
{
	
	bool decision = ( strlen(selectiva)==2 &&
					(selectiva[0] == 'S' or selectiva[0] == 's')
					&&
					(selectiva[1] == 'I' or selectiva[1] == 'i')
					);
	
	// Colocar punteros al inicio de los vectores
	int * p1 = v1;
	int * p2 = v2;
	int * p3 = mezcla;

	// Marcar el final de los vectores a mezclar
	int * end1 = v1+util_v1;
	int * end2 = v2+util_v2;

	// mientras queden en los dos vectores
	util_mezcla=0;

	while ((p1<end1) && (p2<end2)) {
		
		if (*p1 < *p2) {
			*p3 = *p1;   // copiar de v1
			p1++;
			
		}
		else {
			*p3 = *p2;   // copiar de v2
			p2++;
		}

		p3++;
		util_mezcla++;
	}

	// copiar lo que quede en v1

	while (p1<end1){

		*p3 = *p1;
		p1++;

		p3++;
		util_mezcla++;
	} 
	
	// copiar lo que quede en v2

	while (p2<end2){

		*p3 = *p2;
		p2++;

		p3++;
		util_mezcla++;
	}


	if(decision==true){
		//Ahora eliminamos los repetidos


		int * tope = mezcla+util_mezcla; 

		int * escribe = mezcla+1; 
		int * lee   = mezcla+1; 


		while (lee != tope){
			if (*lee != *(escribe-1))
			{ 
				*escribe = *lee;       
				escribe++;                  
			}
			lee++; 
		}

		int nuevo_util=0;
		bool sigue = true;
		for(int i=0; i<util_mezcla && sigue; i++){
			if(mezcla[i]>=mezcla[i+1]){
				nuevo_util =i;
				sigue=false;
			}
		}

		util_mezcla = nuevo_util+1;
	}

	
}






/***************************************************************************/
/***************************************************************************/
// Ordenación por selección (primera cifra)
//
// Recibe:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		tamanio, número de elementos del subvector a ordenar. 

void OrdenaSeleccionPrimeraCifra (int *v, int tamanio) 
{
	for (int izda = 0 ; izda < tamanio ; izda++){

	// Calcular el mÃ­nimo entre "izda" y "total_utilizados"-1

	int minimo = v[izda]; // Valor del mínimo
	int pos_min = izda;   // Posición del mínimo

	for (int i = izda + 1; i < tamanio ; i++)

		if (MenorPrimeraCifra(v[i],minimo)){ // Nuevo mínimo
		    minimo = v[i];
		    pos_min = i;
		 }

		// Intercambiar los valores guardados en "izda" y "pos_min"  

		Intercambia (&v[izda], &v[pos_min]);
   }
}



/***************************************************************************/
/***************************************************************************/
// Ordenación por insercion (primera cifra)
//
// Recibe:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		tamanio, número de elementos del subvector a ordenar. 

void OrdenaInsercionPrimeraCifra (int *v, int tamanio) 
{
    for(int izda=1; izda<tamanio; izda++){
        int a_insertar=*(v+izda);
        int i=izda;
        while( (i>0) && 
		MenorPrimeraCifra(a_insertar,*(v+i-1) ))
		{
            *(v+i) = *(v+i-1);
            i--;
        }
        *(v+i) = a_insertar;
    }

}




/***************************************************************************/
/***************************************************************************/
// Ordenación por intercambio (menor primera cifra)
//
// Recibe:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		tamanio, número de elementos del subvector a ordenar. 

void OrdenaIntercambioPrimeraCifra (int *v, int tamanio) 
{
    for(int izquierda=0; izquierda<tamanio; izquierda++){
        for(int i=tamanio-1; i>izquierda; i--){
			if(MenorPrimeraCifra(v[i], v[i-1])){
				Intercambia((v+i), (v+i-1));
            }
        }
    }

}

/***************************************************************************/
/***************************************************************************/
// Comparacion de dos enteros por su primera cifra
//
// Recibe:
//		a entero, b entero
bool MenorPrimeraCifra (int a, int b){
	int primera_a=a;
	int primera_b=b;

	//Bucles que dejan los numeros enteros de las variables solo con la
	//primera cifra
	while(primera_a>10){
		primera_a/=10;
	}
	while(primera_b>10){
		primera_b/=10;
	}

	//Devuelve true si la primera cifra del entero a es menor que la del
	//entero b, en caso contrario devuelve false
	return (primera_a<primera_b) ? true : false;
};


/***************************************************************************/
/***************************************************************************/
// Calculo del maximo y minimo valor de un array, y sus respectivas 
// posiiones
//
// Recibe:
//		maximo, minimo, pos_maximo, pos_minimo (por referencia todos los 
//		anteriores)
//		vector, inicio y fin
void MaxMin_Array(int & maximo, int & pos_maximo, int & minimo, 
int & pos_minimo, int * v, int inicio, int final)
{
	maximo = -1;
	minimo = 999999999;
	int valor;
	//Se recorre el vector entero y si el valor de la posicion i-esima del
	//vector es menor que el minimo o el maximo se actualiza, ademas de
	//su correspondiente posicion
	for(int i=inicio; i<final; i++){
		valor = *(v+i);
		if(valor>maximo){
			maximo = valor;
			pos_maximo = i;
		}
		if(valor<minimo){
			minimo = valor;
			pos_minimo = i;
		}
	}
};