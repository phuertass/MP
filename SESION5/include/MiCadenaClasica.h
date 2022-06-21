/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
// 
//
// RELACION DE PROBLEMAS 1
// 
//  
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

//Funcion que extrae desde la posicion p de la cadena origen hasta la
//posicion p+l y la copia en la cadena resultado desde su inicio
char * extraer_subcadena (char * resultado, const char * origen,
int p, int l);

//Funcion intercambia para char
void Intercambia (char * p1, char * p2);

//Funcion que ordena una cadena por orden alfabetico
void OrdenarPorCaracteres(char * v);

//Funcion que recibe una cadena de caracteres, y dos auxiliares y devuelve
//true o false si la cadena es seudosimetrica o no
bool es_seudosimetrica (const char * cadena,char * c1, char * c2);
/***************************************************************************/
/***************************************************************************/

#endif
