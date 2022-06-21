/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// RELACION DE PROBLEMAS 2
//
// Implementaci�n de las funciones b�sicas de gesti�n del tipo "VectorDinamico".
// Declaraciones en VectorDinamico_basico.h
//  
// Fichero: VectorDinamico_basico.cpp
//
/***************************************************************************/

//#define DEBUG_FUNCS_VECTOR_DINAMICO_BASICO

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>

#include "FuncsVectorDinamico.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/
// Crear vector din�mico
// Argumentos: capacidad_inicial, n�mero de casillas con las que se crea el vector.
// Devuelve: el vector din�mico creado.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es "capacidad_inicial"

VectorDinamico CreaVectorDinamico (int capacidad_inicial, TipoRedimension tipo)
{
	VectorDinamico nuevo;

	// Pedir memoria para el nuevo almacen 
	nuevo.datos = new int[capacidad_inicial]; 

	// Iniciar capacidad y ocupaci�n
	nuevo.capacidad = capacidad_inicial;
	nuevo.usados = 0;
	nuevo.tipo_redim = tipo;

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

void AniadeVectorDinamico (VectorDinamico &v, const TipoBase valor)
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

TipoBase & ValorVectorDinamico (const VectorDinamico & v, int num_casilla) 
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



//Copia profunda. Hace una copia profunda de origen en destino.
void Clona (VectorDinamico & destino,
const VectorDinamico & origen)
{
	LiberaVectorDinamico(destino);
	VectorDinamico nuevo = CreaVectorDinamico(origen.capacidad, 
	origen.tipo_redim);

	nuevo.usados = origen.usados;
	memcpy(nuevo.datos, origen.datos, sizeof(TipoBase)*(origen.usados));

	destino = nuevo;
};

//Ecualización.Inicializa el vector dinámico, sustituyendo el contenido de to-
//das las casillas por el valor valor.
void EcualizaVectorDinamico (VectorDinamico & v,
const TipoBase valor)
{
	for(int i=0; i<v.usados; i++){
		v.datos[i] = valor;
	}
};

//Inserción. Inserta un valor en una posición dada. Los valores que es-
//tán desde esa posición (incluida) hasta la última se “desplazan” una po-
//sición hacia índices mayores. Si el vector dinámico estuviera lleno se
//tiene que redimensionar (de acuerdo al tipo de redimensión estableci-
//do) para poder acoger al nuevo valor. Se establece la precondición:
//PRE: 0<=num_casilla<UsadosVectorDinamico(v)
void InsertaVectorDinamico (VectorDinamico &v,
const TipoBase valor, const int num_casilla)
{
	if(num_casilla<0 or num_casilla>=v.usados)
		return;
	
	if (v.usados == v.capacidad) {

		// Redimensionar 
		RedimensionaVectorDinamico (v);
	}

	memmove(v.datos+num_casilla+1, v.datos+num_casilla,
	sizeof(TipoBase)*(v.usados-num_casilla) );

	v.datos[num_casilla] = valor;
	v.usados++;

};

//Borrado. Elimina un valor en una posición dada. Los valo-
//res que están desde la posición siguiente a la dada hasta
//la última se “desplazan” una posición hacia índices menores.
//PRE: 0<=num_casilla<UsadosVectorDinamico(v)
void EliminaVectorDinamico (VectorDinamico & v,
const int num_casilla)
{
	if(num_casilla<0 or num_casilla>=v.usados)
		return;
	
	memmove(v.datos+num_casilla, v.datos+num_casilla+1,
	sizeof(TipoBase)*(v.usados-num_casilla));

	v.usados--;
};
/*
void EliminaRepetidosFisico(VectorDinamico & v)
{
	for(int i=0; i<v.usados; i++){
		if(v.datos[i] == v.datos[i+1]){
			memmove(v.datos+i, v.datos+i+1,
			sizeof(TipoBase)*(v.usados-i));
			v.usados--;
		}
	}
};
*/

//Borrado. Elimina los elementos repetidos
void EliminaRepetidosFisico(VectorDinamico & v)
{
	int nuevo_usados = v.usados;
	for(int i=0; i<v.usados; i++){
		for(int j=i+1; j<v.usados; j++){
			if(v.datos[i] == v.datos[j]){
				memmove(v.datos+j, v.datos+j+1,
				sizeof(TipoBase)*(v.usados-j));
				v.usados--;
				i--;
				j--;
			}
		}
	}

	v.usados;
};
/*
void EliminaRepetidosApuntadores(VectorDinamico & v)
{
	TipoBase * posicion_lectura = v.datos+1;
	TipoBase * posicion_escritura = v.datos+1;

	TipoBase * tope = v.datos+v.usados-1;

	int contador = 0;

	if(v.datos[0]==v.datos[1])
		contador = 1;
	

	while(posicion_lectura!=tope)
	{
		if(*posicion_lectura!=*(posicion_escritura-1))
		{
			*posicion_escritura = *posicion_lectura;
			posicion_escritura++;
			
		}else
		{
			contador++;
		}
		posicion_lectura++;
	}

	v.usados -= contador;
};
*/

//Borrado. Elimina los elementos repetidos con el metodo
//de los apuntadores
void EliminaRepetidosApuntadores(VectorDinamico & v)
{
	TipoBase * posicion_lectura = v.datos;
	TipoBase * posicion_escritura = v.datos;

	TipoBase * tope = v.datos+v.usados;

	int contador = 0;
	
	int nuevos_usados=0;
	bool inserta;
	while(posicion_lectura!=tope)
	{
		inserta=true;
		for(TipoBase * i=v.datos; i<posicion_escritura; i++)
		{
			if(*posicion_lectura==*i)
				inserta=false;
		}
		if(inserta){
			*posicion_escritura = *posicion_lectura;
			posicion_escritura++;
			nuevos_usados++;
		}
		posicion_lectura++;
	
	}

	
	v.usados = nuevos_usados;
};

//Funcion que devuelve true si valor se encuentra en v entre los extremos
//ext1 y ext2
bool Esta(const VectorDinamico & v, TipoBase valor, int ext1, int ext2){
	int menor=ext1;
	int mayor=ext2;
	if(ext1>ext2)
	{
		menor=ext2;
		mayor=ext1;
	}
	
		
	bool esta=false;

	bool sigue=true;
	for(int i=menor; i<mayor && sigue; i++){
		if(ValorVectorDinamico(v,i) == valor){
			sigue = false;
			esta=true;
		}
	}

	return esta;
};

//Funcion de ordenacion con el criterio pasado por el tercer argumento
VectorDinamico OrdenaIntercambio (VectorDinamico & v, bool (*f) (TipoBase a,
TipoBase b)) 
{
	for (int izda = 0; izda < v.usados; izda++)

		for (int i = v.usados-1 ; i > izda; i--)

			if(f(ValorVectorDinamico(v,i), ValorVectorDinamico(v,i-1)))

				Intercambia (v, i, i-1);
	
	return v;

			
};

void Intercambia(VectorDinamico & v, int a, int b)
{
	TipoBase tmp = v.datos[a];
	v.datos[a] = v.datos[b];
	v.datos[b] = tmp;
	   
}

bool MenorPrimero(TipoBase a, TipoBase b)
{
	return a<b;
}

bool MayorPrimero(TipoBase a, TipoBase b)
{
	return a>b;
}

//Metodo que mezcla los vectores y devuelve el vector de copia
VectorDinamico ObtenerCopiaMezclaVectores
(const VectorDinamico & v1, const VectorDinamico & v2,
const char * selectiva)
{
	VectorDinamico v = CreaVectorDinamico();
	MezclaVectores(v, v1 , v2, selectiva);

	return v;
};

//Metodo para mezclar los vectores de forma selectiva si queremos
//eliminar los repetidos o de forma estandar si no
void MezclaVectores (VectorDinamico & mezcla,
const VectorDinamico & v1, const VectorDinamico & v2,
const char * selectiva)
{
	bool decision = ( strlen(selectiva)==2 &&
					(selectiva[0] == 'S' or selectiva[0] == 's')
					&&
					(selectiva[1] == 'I' or selectiva[1] == 'i')
					);
	// Colocar punteros al inicio de los vectores
	const TipoBase * p1 = v1.datos;
	const TipoBase * p2 = v2.datos;
	TipoBase * p3 = mezcla.datos;

	// Marcar el final de los vectores a mezclar
	const TipoBase * end1 = v1.datos+v1.usados;
	const TipoBase * end2 = v2.datos+v2.usados;


	while ((p1<end1) && (p2<end2)) {
		
		if (*p1 < *p2) {
			AniadeVectorDinamico(mezcla, *p1);
			//*p3 = *p1;   // copiar de v1
			p1++;
			
		}
		else {
			AniadeVectorDinamico(mezcla, *p2);
			//*p3 = *p2;   // copiar de v2
			p2++;
		}

		p3++;
	}

	// copiar lo que quede en v1

	while (p1<end1){
		AniadeVectorDinamico(mezcla, *p1);
		p1++;

		p3++;
	} 
	
	// copiar lo que quede en v2

	while (p2<end2){

		AniadeVectorDinamico(mezcla, *p2);
		p2++;

		p3++;
	}

	if(decision==true){
		//Ahora eliminamos los repetidos
		EliminaRepetidosFisico(mezcla);
	}

};
/***************************************************************************/
/***************************************************************************/