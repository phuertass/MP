#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "Funcs_VectorDinamicoCadenas.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main()
{
	TipoRedimension tipo = TipoRedimension::DeUnoEnUno;

	const int TAM_INIT = 10;
	char ** lineas;
	
	lineas = new char * [TAM_INIT];

	int capacidad_lineas = TAM_INIT;
	int lineas_ocupadas=0;



	//.......................................................................
	// Rellenar "v": se termina al encontrar EOF en cin 

	string cadena; // Para leer cada una de las cadenas 

	while (getline (cin, cadena)) {

		if(lineas_ocupadas == capacidad_lineas)
			Redimensiona(lineas, tipo, capacidad_lineas);
		// Reservar memoria para la cadena cl�sica. 
		// Se necesita un car�cter m�s que la longitud de "cadena". 
		// La longitud de "cadena" se calcula con el m�todo "length" de string

		int long_cadena = cadena.length();
		lineas[lineas_ocupadas] = new char [long_cadena+1];	

		// VERSI�N 2 (nivel: experto)
		
			//Usar el m�todo c_str() de la clase string para obtener una 
			//cadena cl�sica desde un dato string (por supuesto con el '\0')

			//Por ejemplo, la l�nea 
			//cout << "|" << cadena.c_str() << "|" << endl; 
			//env�a a cout el resultado de la conversi�n (entre barras)
		
			//En este problema bastar�a con escribir la instrucci�n: 
			strcpy(lineas[lineas_ocupadas], cadena.c_str());

			

		lineas_ocupadas++;

	} // while



	Reajusta(lineas, lineas_ocupadas, capacidad_lineas);

	int n_vacias, n_parrafos;


	Calculos_lineas(lineas, lineas_ocupadas, n_vacias, n_parrafos);
	//.......................................................................
	// Mostrar resultados

	cout << endl; 
	cout << "CALCULOS SOBRE LAS LINEAS LEIDAS" << endl; 
	cout << endl;

	cout << "Num. total lineas  = " << setw(3) << lineas_ocupadas << endl;
	cout << "Num. lineas vacias = " << setw(3) << n_vacias << endl;
	cout << "Num. parrafos      = " << setw(3) << n_parrafos << endl;
	cout << endl;

	for(int l=0; l<lineas_ocupadas; l++)
	{
		cout<<"|"<<setw(4)<<l<<"|"<<lineas[l]<<endl;
	}

	//LIBERAR MEMORIA
	LiberaMemoria(lineas, lineas_ocupadas);
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/