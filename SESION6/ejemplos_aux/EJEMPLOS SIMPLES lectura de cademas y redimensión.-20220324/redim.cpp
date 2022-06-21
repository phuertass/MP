/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Ejercicio preparatorio de reminensión de array dinámico. 
//
// Fichero: redim.cpp 
//
/***************************************************************************/
/***************************************************************************/

#include<iostream>
#include<iomanip>
		
using namespace std;

/***************************************************************************/

void Muestra (int * array, int reservados, int usados)
{
	cout << endl;
	cout << "CAPACIDAD = " << reservados << endl; 
	cout << "USADOS = " << usados << endl; 	
	cout << "VALORES = "; 
	
	for (int i=0; i<usados; i++) 
		cout << setw(4) << array[i];
		
	for (int i=usados; i<reservados; i++) 
		cout << "   X";
		

	cout << endl << endl;	
}

/***************************************************************************/

void Remidensiona (int * & r, int adicional, int & capacidad)
{
	int nueva_capacidad = capacidad+adicional;
	int *tmp = new int [nueva_capacidad];
	
	for (int i=0; i<capacidad; i++) tmp[i]=r[i];
	
	delete [] r;
	r = tmp;	
	
	capacidad = nueva_capacidad;
}

/***************************************************************************/

void Aniade (int * r, int valor_nuevo, int & ocupados)
{
	r[ocupados] = valor_nuevo; 
	ocupados++;
}

/***************************************************************************/

void Libera (int * & r, int & capacidad, int & utils)
{
	delete [] r;
	r = nullptr;	
	
	capacidad = utils = 0;
}

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	const int TAM_INIT = 5;
	const int TAM_BLOQUE = 3;
		
	// Estado inicial del array dinámico
	int * v = new int[TAM_INIT];
	int capacidad = TAM_INIT;
	int utils = 0;
	
	// Lectura de datos (finaliza con negativo)

	int valor;
	
	cout << "Nuevo valor : "; 
	cin >> valor; 

	while (valor >= 0) {
		
		if (utils == capacidad) { // Lleno
	
			cout << endl;
			cout << "Redimensionando..." << endl;	
			
			Remidensiona (v, TAM_BLOQUE, capacidad);

			Muestra (v, capacidad, utils);
			
			cout << "...Terminado" << endl;	
		}
		
		Aniade (v, valor, utils); 

		Muestra (v, capacidad, utils);

		cout << "Nuevo valor : "; 
		cin >> valor; 
	}
	
	cout << "--------------------" << endl;
			
	Muestra (v, capacidad, utils);	


	cout << "Finalizando..." << endl;
	
	Libera  (v, capacidad, utils); 
	Muestra (v, capacidad, utils);

	cout << "...Fin" << endl;


	return (0);
}

/***************************************************************************/
/***************************************************************************/
