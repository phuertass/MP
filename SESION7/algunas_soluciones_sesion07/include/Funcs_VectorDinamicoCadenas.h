/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//	
// Declaración del tipo de dato "VectorDinamicoCadenas" y de las funciones
// sobre vectores dinámicos de cadenas. 
// Definiciones en Funcs_VectorDinamicoCadenas.cpp
//
// Fichero: Funcs_VectorDinamicoCadenas.h
//
/***************************************************************************/

#ifndef FUNCS_VECTORDINAMICOCADENAS
#define FUNCS_VECTORDINAMICOCADENAS

/***************************************************************************/
/***************************************************************************/
// Tipo enumerado para representar los tipos de redimensionamiento permitidos

enum TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};

// Capacidad inicial 
const int TAM_INICIAL = 10; 

// Tamanio del bloque para redimensionar
const int TAM_BLOQUE = 5;


typedef struct {

	char ** lineas; 	// Puntero para acceder a los datos
	int usados;			// Num. casillas usadas
	int capacidad;		// Num. casillas reservadas

	// PRE: 0 <= usados <= capacidad 
	// Inicialmente, capacidad = TAM_INICIAL

	TipoRedimension tipo_redimension; // Método de redimensión.

} VectorDinamicoCadenas;

/***************************************************************************/
/***************************************************************************/
// Crear vector dinámico de cadenas.
// Argumentos: 
// 		capacidad_inicial, número de casillas con las que se crea el vector.
//		el_tipo_redimension, método de redimensión.
// Devuelve: el vector dinámico creado.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es "capacidad_inicial"

VectorDinamicoCadenas CreaVectorDinamico (int capacidad_inicial=TAM_INICIAL, 
	                        TipoRedimension el_tipo_redimension = EnBloques);
	
/***************************************************************************/
/***************************************************************************/
// Inicializar vector dinámico de cadenas.
// Parámetros: 
// 		v (referencia), el vector que se va a Inicializar. 
// 		capacidad_inicial, número de casillas con las que se crea el vector.
// Devuelve: el vector dinámico creado.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es "capacidad_inicial"

void InicializaVectorDinamico (VectorDinamicoCadenas & v, 
	                     		int capacidad_inicial=TAM_INICIAL);

/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas usadas de un vector dinámico.
// Recibe: v, el vector que se va a consultar.
// Devuelve: el número de casillas usadas de un vector dinámico

int UsadosVectorDinamico (const VectorDinamicoCadenas v);

/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas reservadas de un vector dinámico.
// Recibe: v, el vector que se va a consultar.
// Devuelve: el número de casillas reservadas de un vector dinámico

 int CapacidadVectorDinamico (const VectorDinamicoCadenas v); 
 
/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector dinámico de acuerdo al tipo de redimensión indicado. 
// Parámetros: 	
//		v (referencia), Vector dinámico de cadenas.  
//		tipo, tipo de redimensión que se va a emplear 

void Redimensiona (VectorDinamicoCadenas & v, TipoRedimension tipo);

/***************************************************************************/
/***************************************************************************/
// Reajusta el vector dinámico para que no hayan casillas vacías.
// Recibe: 	
//		v (referencia), Vector dinámico de cadenas.  

void Reajusta (VectorDinamicoCadenas & v);

/***************************************************************************/
/***************************************************************************/
// Añade un valor al vector dinámico
// Recibe: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		cadena, cadena que se va a añadir al vector dinámico. 
// PRE: hay espacio disponible en el vector dinámico

void AniadeVectorDinamico (VectorDinamicoCadenas & v, char * cadena);

/***************************************************************************/
/***************************************************************************/
// Calcula el número de líneas totales y vacías, además del número de 
// párrafos en "lineas".
// Recibe: 	
//		v (referencia), Vector dinámico de cadenas.  
//		cl (referencia), número de líneas. 
//		cv (referencia), número de líneas vacías.
//		cp (referencia), número de párrafos.

void Calculos_lineas (const VectorDinamicoCadenas & v, 
	                  int & cl, int & cv, int & cp);

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por "lineas".
// Recibe: 	
//		v (referencia), Vector dinámico de cadenas.  
// POST: lineas = 0 Y num_lineas = 0

void LiberaMemoria (VectorDinamicoCadenas & v);

/***************************************************************************/
/***************************************************************************/
// Mostrar contenido de "lineas"

void MostrarVectorDinamicoCadenas (const VectorDinamicoCadenas & v);

/***************************************************************************/
/***************************************************************************/
// Devuelve una copia de una línea del vector dinámico   
// PRE: 0 <= num_linea < UsadosVectorDinamico(v)

char * LineaVectorDinamicoCadenas (const VectorDinamicoCadenas & v, 
	                               const int num_linea);

/***************************************************************************/
/***************************************************************************/

#endif
