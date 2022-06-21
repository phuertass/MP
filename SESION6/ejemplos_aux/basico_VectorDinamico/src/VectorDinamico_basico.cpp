/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//
// Implementaci�n de las funciones b�sicas de gesti�n del tipo "VectorDinamico".
// Declaraciones en VectorDinamico_basico.h
//  
// Fichero: VectorDinamico_basico.cpp
//
/***************************************************************************/

#define DEBUG_FUNCS_VECTOR_DINAMICO_BASICO

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>

#include "VectorDinamico_basico.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/
// Crear vector din�mico
// Argumentos: capacidad_inicial, n�mero de casillas con las que se crea el vector.
// Devuelve: el vector din�mico creado.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es "capacidad_inicial"

VectorDinamico CreaVectorDinamico (int capacidad_inicial)
{
	VectorDinamico nuevo;

	// Pedir memoria para el nuevo almacen 
	nuevo.datos = new int[capacidad_inicial]; 

	// Iniciar capacidad y ocupaci�n
	nuevo.capacidad = capacidad_inicial;
	nuevo.usados = 0;

	return (nuevo);
}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector din�mico
// Argumentos: v (referencia) El vector que se va liberar.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es 0

void LiberaVectorDinamico (VectorDinamico & v) 
{
	if (v.datos)
		delete [] v.datos;

	// Modificar las propiedades de "v" para que quede "vac�o"
	v.datos = 0; // Puntero "nulo"
	
	v.usados = 0;
	v.capacidad = 0;
}

/***************************************************************************/
/***************************************************************************/
// Deja el vector din�mico vac�o
// Argumentos: v (referencia) El vector que se va "vaciar"
// POST: El n�mero de casillas usadas es 0

void EliminaTodosVectorDinamico (VectorDinamico & v) 
{
	v.usados = 0;
}

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas usadas de un vector din�mico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas usadas de un vector din�mico

int  UsadosVectorDinamico (const VectorDinamico v) 
{
	return (v.usados);
}	

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas reservadas de un vector din�mico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas reservadas de un vector din�mico

 int CapacidadVectorDinamico (const VectorDinamico v) 
{
	return (v.capacidad);
}	

/***************************************************************************/
/***************************************************************************/
// Serializa un dato de tipo "VectorDinamico"
// Argumentos: v (referencia), el vector que se va a serializar.

string ToString (const VectorDinamico & v)
{
	string cad; 
	cad = cad + "Capacidad = " + to_string(v.capacidad); 
	cad = cad + "  Ocupadas  = " + to_string(v.usados) + "\n";

	if (v.usados > 0)  {

		cad = cad + "Valores almacenados en el vector: \n"; 

		cad = cad + "[ ";

		for (int i=0; i<v.usados-1; i++) 
			cad = cad + to_string(ValorVectorDinamico (v, i)) + ", "; 

		cad = cad + to_string(ValorVectorDinamico (v, v.usados-1)); 
		cad = cad + " ]";
	}
	else 
		cad = cad + "Vector vacio";

	cad = cad + "\n\n";

	return (cad);
}

/***************************************************************************/
/***************************************************************************/
// A�ade un valor al vector din�mico
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a a�adir al vector. 
// NOTA: Si no hay espacio libre, la funci�n pide espacio adicional usando 
//		 la funci�n RedimensionaVectorDinamico. 

void AniadeVectorDinamico (VectorDinamico &v, const int valor)
{
	// Si no cabe --> redimensionar

	if (v.usados == v.capacidad) {

		// Redimensionar 
		RedimensionaVectorDinamico (v);
	}

	// Se haya redimensionado o no, en este punto hay sitio para la inserci�n

	v.datos[v.usados] = valor;
	v.usados++;
}

/***************************************************************************/
/***************************************************************************/
// Consulta � modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consultar el valor de la casilla "num_casilla". 
// Si se utiliza como lvalue se emplea para modificar el valor de la 
// casilla num_"casilla".
// 
// Argumentos: 	
//		v (referencia), referencia al vector. 
//		num_casilla, n�mero de casilla (�ndice) en la que estamos interesados.
//
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

int & ValorVectorDinamico (const VectorDinamico & v, int num_casilla) 
{
	return (v.datos[num_casilla]);
}	

/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector din�mico "v" de acuerdo al tipo de redimensi�n 
// registrado en "v". 
// Adem�s, copia todos los datos en el nuevo vector.  
// Argumentos: 	
//		v (referencia), referencia al vector que se va a redimensionar. 
			
void  RedimensionaVectorDinamico (VectorDinamico & v)
{
	int nueva_capacidad = v.capacidad + TAM_BLOQUE;

    #ifdef DEBUG_FUNCS_VECTOR_DINAMICO_BASICO
	cout << endl;
	cout << "REDIMENSIONADO HASTA --> "<<nueva_capacidad << " CASILLAS"<< endl;
	cout << endl;
	#endif

	// Pedir memoria para el nuevo almacen 
	int * tmp = new int[nueva_capacidad]; 

	// Copiar los datos 
	for (int i=0; i<v.usados; i++) 
		tmp[i] = v.datos[i]; 
		
	// Considerar esta copia eficiente:
	// memcpy (tmp, v.datos, v.usados*sizeof(TipoBase)); 
	
	// Liberar la memoria del antiguo almac�n
	delete [] v.datos; 

	// Actualizar vector din�mico redimensionado

	v.datos = tmp;
	v.capacidad = nueva_capacidad;
	// v.usados se mantiene como estaba
}

/***************************************************************************/
/***************************************************************************/
// Redimensiona un vector din�mico para que no haya espacio libre.
// Copia todos los datos en el nuevo vector.
// Argumentos: 	
//		v (referencia), referencia al vector que se va a reajustar. 
// POST: capacidad = usados

void  ReajustaVectorDinamico (VectorDinamico & v)
{
	int nueva_capacidad = v.usados;

	cout << endl;
	cout << "REAJUSTANDO HASTA --> "<<nueva_capacidad << " CASILLAS"<< endl;
	cout << endl;

	// Pedir memoria para el nuevo almacen 
	int * tmp = new int[nueva_capacidad]; 

	// Copiar los datos 
	for (int i=0; i<v.usados; i++) 
		tmp[i] = v.datos[i]; 
		
	// Considerar esta copia eficiente:
	// memcpy (tmp, v.datos, v.usados*sizeof(TipoBase)); 
	
	// Liberar la memoria del antiguo almac�n
	delete [] v.datos; 

	// Actualizar vector din�mico redimensionado

	v.datos = tmp;
	v.capacidad = nueva_capacidad;
	// v.usados se mantiene como estaba
}

/***************************************************************************/
/***************************************************************************/