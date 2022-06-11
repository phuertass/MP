/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Proyecto Gestion de marcas de atletismo
//
// Fichero: utils.cpp
//
/***************************************************************************/
/***************************************************************************/
#include "utils.h"
/***************************************************************************/
// Convierte el dato int "entero" a un string con "num_casillas" casillas
// que contiene el valor textual de "entero".
//
// Recibe: 	entero, el valor a transformar.
//			num_casillas, número total de casillas que tendrá el resultado.
//			relleno, el carácter que se emplea para rellenar los huecos.
// Devuelve: el string compuesto.
//
// NOTAS: Si el número de casillas solicitado es mayor que el que se necesita,
//	  	se completa al principio con "relleno" hasta alcanzar un tamaño de
//	  	"num_casillas". Si el valor tuviera "per se" más de "num_casillas"
//		se devuelve tal cual.

string ToString(int entero, int num_casillas, char relleno)
{
	// Inicialmente nos quedamos con el resultado de to_string
	string cadena = to_string(entero);

	int long_cadena = (int)cadena.length();

	// Si es preciso se completa (por la izquierda) con "relleno"

	if (long_cadena < num_casillas)
	{

		int num_casillas_faltan = num_casillas - long_cadena;

		for (int i = 0; i < num_casillas_faltan; i++)
			cadena = relleno + cadena;
	}

	return cadena;
}

/***************************************************************************/
// Convierte el dato string "la_cadena" a un string con "num_casillas"
// casillas rellenando con el caracter "relleno" por la izquierda.
//
// Recibe: 	la_cadena, el valor a transformar.
//			num_casillas, número total de casillas que tendrá el resultado.
//			relleno, el carácter que se emplea para rellenar los huecos.
// Devuelve: el string compuesto.
//
// NOTAS: Si el número de casillas solicitado es mayor que el que se necesita,
//	  	se completa al principio con "relleno" hasta alcanzar un tamaño de
//	  	"num_casillas". Si el valor tuviera "per se" más de "num_casillas"
//		se devuelve tal cual.

string ToString(string la_cadena, int num_casillas, char relleno)
{
	string cadena = la_cadena;

	string cad_relleno;
	cad_relleno.push_back(relleno);

	int long_cadena = (int)la_cadena.length();

	// Si es preciso se completa (por la izquierda) con "relleno"

	if (long_cadena < num_casillas)
	{

		int num_casillas_faltan = num_casillas - long_cadena;

		for (int i = 0; i < num_casillas_faltan; i++)
			cadena = cad_relleno + cadena;
	}

	return cadena;
}

/***************************************************************************/
// Devuelve true si el fichero "nombre_fichero" existe.
// False en caso contrario.
bool ExisteFichero(const string &nombre)
{

	ifstream fichero;

	fichero.open(nombre);

	bool problema = fichero.fail();
	if (!problema)
		fichero.close();

	return ((problema) ? false : true);
}

/***************************************************************************/
// Devuelve true si el fichero es de texto.
// Debe existir el fichero.
bool EsFicheroTxt(const string &nombre_fichero)
{
	string extension = nombre_fichero.substr(nombre_fichero.length() - 3, 3);
	return (extension == "txt");
}

/***************************************************************************/
// Devuelve true si el fichero es binario.
// Debe existir el fichero.
bool EsFicheroBin(const string &nombre_fichero)
{
	string extension = nombre_fichero.substr(nombre_fichero.length() - 3, 3);
	return (extension == "bin");
}
