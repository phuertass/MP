/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
//
// RELACION DE PROBLEMAS 2
//
// Fichero: II_Demo-VectorDinamico.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#include "FuncsVectorDinamico.h"
#include "GeneradorAleatorioEnteros.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (int argc, char ** argv)
{
	// Establecer tipo de redimensi�n por defecto
	TipoRedimension el_tipo = TipoRedimension::DeUnoEnUno; 

	// ......................................................................
	// Comprobar validez de argumentos 


	if(argc>2)
	{
		cerr << "Error: demasiados argumentos" << endl;
        cerr << "Uso: " << argv[0] << "1=Redimension uno a uno "<<endl;
        cerr << "2=Redimension en bloques de tamaño fijo"<<endl;
		cerr << "3=Redimension duplicando el tamaño"<<endl<<endl;
        exit(1);

	}

	if(argc==2 && atoi(argv[1])!=1)
	{
		if(atoi(argv[1])==2)	el_tipo = TipoRedimension::EnBloques;
		else	el_tipo = TipoRedimension::Duplicando;
	}

	string salida_tipo="";
	
	if(el_tipo == TipoRedimension::DeUnoEnUno)	salida_tipo="De uno en uno";
	else if(el_tipo == TipoRedimension::EnBloques) salida_tipo="En bloques";
	else if(el_tipo == TipoRedimension::Duplicando) salida_tipo="Duplicando";
	
	cout<<"TIPO REDIMENSION ELEGIDO->"<<salida_tipo<<endl;

	// ......................................................................
	// Crear un vector din�mico
	

	VectorDinamico v = CreaVectorDinamico (TAM_INICIAL, el_tipo); 

	// Se han reservado TAM casillas y actualmente se est�n usando 0.

	// ......................................................................
	

	// ......................................................................
	// Leer valores y guardarlos en el vector din�mico. 
	// Se redimensiona cuando no hay espacio para un nuevo dato. 
	
	const int TAM_CAD = 20;
	char  valor[TAM_CAD];

	// Primera lectura - lectura adelantada
	cout << "Introducir un valor (FIN para finalizar): "; 
	cin.getline (valor, TAM_CAD);

	while (strcmp(valor, "FIN")) {

		int el_valor = atoi (valor); 

		// A�adir "valor". Si no cabe se redimensiona 

		AniadeVectorDinamico (v, el_valor);

		// Nueva lectura
		cout << "Introducir un valor (FIN para finalizar): "; 
		cin.getline (valor, TAM_CAD);
	}

	// ......................................................................
	// Muestra el vector

	cout << endl;
	cout << ToString (v);
	cout << endl;


	// ......................................................................
	// Reajusta y muestra el vector

	ReajustaVectorDinamico (v);

	cout << endl;
	cout << ToString (v);
	cout << endl;


	// ......................................................................
	// Insertar en casilla 1 y penultima y mostrar el vector

	cout << "Insertando -1 en casilla 1: "; 

	InsertaVectorDinamico (v, -1, 1);

	cout << endl;
	cout << ToString (v);
	cout << endl;

	cout << "Insertando -2 en casilla penultima: "; 

	InsertaVectorDinamico (v, -2, UsadosVectorDinamico(v)-1);

	cout << endl;
	cout << ToString (v);
	cout << endl;

	// ......................................................................
	// Eliminar las casilla insertadas 
	
	cout << "Eliminando los valores insertados: "; 

	EliminaVectorDinamico (v, 1);

	cout << endl;
	cout << ToString (v);
	cout << endl;

	EliminaVectorDinamico (v, UsadosVectorDinamico(v)-2);

	cout << endl;
	cout << ToString (v);
	cout << endl;
	
	// ......................................................................
	// Reajusta y muestra el vector

	ReajustaVectorDinamico (v);

	cout << endl;
	cout << ToString (v);
	cout << endl;


	// ......................................................................
	// Prueba de valor (como rvalue) e inserci�n --> Hacer espejo

	cout << "Construyendo array espejo: ";

	for (int i=v.usados-1; i>=0; i--)
		AniadeVectorDinamico (v, ValorVectorDinamico (v, i)); 

	cout << endl;
	cout << ToString (v);
	cout << endl;


	// ......................................................................
	// Prueba de valor como lvalue --> invertir 
	
	cout << "Invertir los valores: "; 

	for (int i=0; i<v.usados; i++) 
		ValorVectorDinamico (v, i) *= -1; 

	cout << endl;
	cout << ToString (v);
	cout << endl;



	// ......................................................................
	// Prueba de valor (como rvalue) --> Mostrar las posiciones pares 

	cout << "Valores en posiciones pares: ";

	cout << endl;
	for (int i=0; i<v.usados; i+=2) 
		cout << "Pos " << i << " = " << ValorVectorDinamico (v, i) << endl; 
	cout << endl;

	cout << endl;
	cout << ToString (v);
	cout << endl;


	// ......................................................................
	// "Vaciar" vector din�mico
	
	cout << "Vaciando: ";

	EliminaTodosVectorDinamico (v);
	
	cout << endl;
	cout << ToString (v);
	cout << endl;


	// ......................................................................
	// "Alimentar" el vector din�mico

	AniadeVectorDinamico (v, 1);
	AniadeVectorDinamico (v, 3);
	AniadeVectorDinamico (v, 5);

	cout << endl;
	cout << ToString (v);
	cout << endl;

	
	//Probar metodo clona
	VectorDinamico v2 = CreaVectorDinamico(TAM_BLOQUE);
	Clona(v2, v);
	
	cout<<"CLONANDO EL VECTOR A OTRO----->";
	cout << endl;
	cout << ToString (v2);
	cout << endl;

	//PROBAR METODO ECUALIZA
	EcualizaVectorDinamico(v2, 0);

	cout<<"ECUALIZANDO EL VECTOR A 0----->";
	cout << endl;
	cout << ToString (v2);
	cout << endl;
	
	VectorDinamico v3 = CreaVectorDinamico(TAM_BLOQUE);
	
	GeneradorAleatorioEnteros generador(1,9);
	for(int i=0; i<10; i++){
		AniadeVectorDinamico(v3, generador.Siguiente());
	}

	VectorDinamico v4 = CreaVectorDinamico(TAM_BLOQUE);
	Clona(v4,v3);

	cout << endl;
	cout << ToString (v3);
	cout << endl;
	cout << endl;
	cout << ToString (v4);
	cout << endl;

	EliminaRepetidosApuntadores(v3);
	EliminaRepetidosFisico(v4);
	cout << endl;
	cout<<"ELIMINADOS REPETIDOS METODO DE APUNTADORES"<<endl;
	cout << ToString (v3);
	cout << endl;
	cout << endl;
	cout<<"ELIMINADOS REPETIDOS METODO FISICO"<<endl;
	cout << ToString (v4);
	cout << endl;





	// ......................................................................
	// Liberar memoria
	
	cout << "Liberando memoria y finalizando" << endl;
	cout << endl;

	LiberaVectorDinamico (v);
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
