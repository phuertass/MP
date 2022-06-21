/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Declaraciones de funciones que gestionan cadenas cl�sicas de manera similar 
// a las funciones de cstring 
// Definiciones en: MiCadenaClasica.cpp	
//
// Fichero: MiCadenaClasica.h
// 
/***************************************************************************/
/***************************************************************************/

#ifndef MI_CADENA_CLASICA
#define MI_CADENA_CLASICA
#include <iostream>

struct info_palabra {
    char * inicio;
    char * fin;
};

//Funcion que recibe una cadena de caracteres y modifica el array
//recibido del tipo info_palabra, donde almacena en cada posicion un puntero
//al inicio y final de cada respectiva palabra
//Devuelve el numero de palabras encontradas
int encuentra_palabras (info_palabra * palabras, char * cadena);

//Funcion que recibe un array del tipo info_palabra y el numero de palabras
//a mostrar, y lo muestra por pantalla
void MuestraPalabras( int num_palabras, info_palabra * las_palabras);

/***************************************************************************/
/***************************************************************************/
// Longitud de una cadena. 
// Par�metros: 
//		cadena, puntero a la cadena (direcci�n del primer car�cter)
// Devuelve:
//		N�mero de caracteres de la cadena 

int longitud_cadena (const char *cadena);

/***************************************************************************/
/***************************************************************************/
// Compara dos cadenas.
// Par�metros: 
//		cad1 y cad2, punteros a las cadenas que se van a comparar
//			(direcci�n del primer car�cter de cada una de ellas)
// Devuelve:
//		0, si las dos cadenas son iguales
//		un valor positivo, si cad1 > cad2
//		un valor negativo, si cad1 < cad2

int comparar_cadenas (const char *cad1, const char *cad2);

/***************************************************************************/
/***************************************************************************/
// Devuelve una copia de una cadena.
// Par�metros: 
//		original, puntero a la cadena original (direcci�n del primer 
//			  car�cter)
//		copia, puntero a la cadena que contendr� la copia  
//			(direcci�n del primer car�cter)
// Devuelve:
//		Puntero al inicio de la cadena copia.
// PRE: El puntero "copia" referencia a una zona de memoria reservada.  
//		Hay suficiente espacio reservado para albergar la copia

char * copiar_cadena (char *copia, const char *original);



//Funcion que elimina los blancos al inicio de una cadena
//Recibe la cadena original y devuelve otra sin los blancos iniciales 
//La cadena original no se modifica
char * eliminar_blancos_iniciales (char *cad_nueva, const char * cadena);

//Funcion que elimina los blancos al final de una cadena
//Recibe la cadena original y devuelve otra sin los blancos finales 
//La cadena original no se modifica
char * eliminar_blancos_finales (char *cad_nueva, const char * cadena);

//Funcion que elimina los blancos al inicio y fin de una cadena
//Recibe la cadena original y devuelve otra sin los blancos de los extremos 
//La cadena original no se modifica
char * eliminar_blancos_extremos (char *cad_nueva, const char * cadena);

//Funcion que elimina los blancos en mitad de una cadena
//Recibe la cadena original y devuelve otra sin los blancos intermedios
//NO elimina los blancos iniciales ni finales 
//La cadena original no se modifica
char * eliminar_blancos_intermedios (char *cad_nueva, const char * cadena);

//Funcion que elimina los blancos al inicio,mitad y final de una cadena
//Recibe la cadena original y devuelve otra sin ningun espacio en blanco 
//La cadena original no se modifica
char * eliminar_todos_blancos (char *cad_nueva, const char * cadena);

/***************************************************************************/
/***************************************************************************/

#endif
