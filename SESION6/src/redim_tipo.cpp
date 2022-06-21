/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Ejercicio preparatorio de reminensión de array dinámico. 
//
// Se usa un struct para crear el tipo "ArrayDinamico"
//
// Fichero: redim_tipo.cpp 
//
/***************************************************************************/
/***************************************************************************/

#include<iostream>
#include<iomanip>
		
using namespace std;

typedef struct {
	int * datos;
	int capacidad;
	int utils;
} ArrayDinamico;

const int TAM_INIT = 5;
const int TAM_BLOQUE = 3;
	
/***************************************************************************/

void Muestra (ArrayDinamico array)
{
	cout << endl;
	cout << "CAPACIDAD = " << array.capacidad << endl; 
	cout << "USADOS = " << array.utils << endl; 	
	cout << "VALORES = "; 
	
	for (int i=0; i<array.utils ; i++) 
		cout << setw(4) << array.datos[i];
		
	for (int i=array.utils; i<array.capacidad ; i++) 
		cout << "   X";
		
	cout << endl << endl;	
}

/***************************************************************************/

void Remidensiona (ArrayDinamico & array, int adicional)
{
	int nueva_capacidad = array.capacidad+adicional;
	int *tmp = new int [nueva_capacidad];
	
	for (int i=0; i<array.capacidad; i++) tmp[i]=array.datos[i];
	
	delete [] array.datos;
	array.datos = tmp;	
	
	array.capacidad = nueva_capacidad;
}

/***************************************************************************/

void CreaArrayDinamico (ArrayDinamico & array)
{
	array.datos =  new int [TAM_INIT];	
	array.capacidad = TAM_INIT;
	array.utils = 0;
}

/***************************************************************************/

void LiberaArrayDinamico (ArrayDinamico & array)
{
	if (array.datos)
		delete [] array.datos;
	
	array.datos = 0;
	array.capacidad = 0;	
	array.utils = 0;
}

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// Estado inicial del array dinámico
	
	ArrayDinamico v;
	
	CreaArrayDinamico (v);
	
	// Lectura de datos (finaliza con negativo)

	int valor;
	
	cout << "Nuevo valor : "; 
	cin >> valor; 

	while (valor >= 0) {
		
		if (v.utils == v.capacidad) { // Lleno
	
			cout << endl;
			cout << "Redimensionando..." << endl;	
			
			Remidensiona (v, TAM_BLOQUE);

			Muestra (v);
			
			cout << "...Terminado" << endl;	
		}
		
		v.datos[v.utils] = valor;
		v.utils++;

		Muestra (v);

		cout << "Nuevo valor : "; 
		cin >> valor; 
	}
	
	cout << "--------------------" << endl;
			
	Muestra (v);	


	cout << "Finalizando..." << endl;
	
	LiberaArrayDinamico (v); 
	Muestra (v);	

	cout << "...Fin" << endl;
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
