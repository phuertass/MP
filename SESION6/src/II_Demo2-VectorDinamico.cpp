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

    VectorDinamico v2 = CreaVectorDinamico (TAM_INICIAL, el_tipo); 

	// Se han reservado TAM casillas y actualmente se est�n usando 0.

	// ......................................................................
	

	// ......................................................................
	// Leer valores y guardarlos en el vector din�mico. 
	// Se redimensiona cuando no hay espacio para un nuevo dato.

	// Primera lectura - lectura adelantada
	cout << "Introducir un valor (FIN para finalizar): "; 
	cin.getline (valor, TAM_CAD);

	while (strcmp(valor, "FIN")) {

		int el_valor = atoi (valor); 

		// A�adir "valor". Si no cabe se redimensiona 

		AniadeVectorDinamico (v2, el_valor);

		// Nueva lectura
		cout << "Introducir un valor (FIN para finalizar): "; 
		cin.getline (valor, TAM_CAD);
	}

	// ......................................................................
	// Muestra el vector

	cout << endl;
	cout << ToString (v);
	cout << endl;

    cout << endl;
	cout << ToString (v2);
	cout << endl;

	// ......................................................................
	// Reajusta y muestra el vector

	ReajustaVectorDinamico (v);

	cout << endl;
	cout << ToString (v);
	cout << endl;

    ReajustaVectorDinamico (v2);

	cout << endl;
	cout << ToString (v2);
	cout << endl;

    VectorDinamico mezcla_no_sel = CreaVectorDinamico(TAM_INICIAL, el_tipo);
    VectorDinamico mezcla_sel = CreaVectorDinamico(TAM_INICIAL, el_tipo);


    VectorDinamico mezcla_devuelta = ObtenerCopiaMezclaVectores(v, v2, "si");

    ReajustaVectorDinamico (mezcla_devuelta);

    cout<<"Prueba de obtener mezcla"<<endl;
	cout << endl;
	cout << ToString (mezcla_devuelta);
	cout << endl;


    MezclaVectores(mezcla_no_sel, v, v2);
    MezclaVectores(mezcla_sel, v, v2, "si");

    ReajustaVectorDinamico (mezcla_no_sel);

	cout << endl;
	cout << ToString (mezcla_no_sel);
	cout << endl;

    ReajustaVectorDinamico (mezcla_sel);

	cout << endl;
	cout << ToString (mezcla_sel);
	cout << endl;

    OrdenaIntercambio(mezcla_sel, MenorPrimero);

    cout << endl;
	cout << ToString (mezcla_sel);
	cout << endl;

    OrdenaIntercambio(mezcla_sel, MayorPrimero);

    cout << endl;
	cout << ToString (mezcla_sel);
	cout << endl;

}