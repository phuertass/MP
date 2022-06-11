/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Proyecto Gestion de marcas de atletismo
//
// Fichero: utils.h
//
/***************************************************************************/
/***************************************************************************/
#ifndef UTILS_H
#define UTILS_H

using namespace std;

#include <string>
#include <fstream>
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

string ToString (int entero, int num_casillas, char relleno); 

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

string ToString (string la_cadena, int num_casillas, char relleno=' '); 

/***************************************************************************/
// Devuelve true si el fichero "nombre_fichero" existe.
// False en caso contrario.
bool ExisteFichero (const string & nombre);

/***************************************************************************/
// Devuelve true si el fichero es de texto.
// Debe existir el fichero.
bool EsFicheroTxt (const string & nombre);

/***************************************************************************/
// Devuelve true si el fichero es binario.
// Debe existir el fichero.
bool EsFicheroBin (const string & nombre);


#endif