/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// 
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Definiciones de funciones que gestionan cadenas cl�sicas de manera similar 
// a las funciones de cstring.  
// Declaraciones en: MiCadenaClasica.h	
//
// Fichero: MiCadenaClasica.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <cctype>

#include "MiCadenaClasica.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Longitud de una cadena. 
// Par�metros: 
//		cadena, puntero a la cadena (direcci�n del primer car�cter)
// Devuelve:
//		N�mero de caracteres de la cadena 

int longitud_cadena (const char *cadena)
{
	const char *p;
	for (p=cadena; *p != '\0'; p++); // Buuscar el car�cter '\0'
	
	return (p-cadena);
}

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

int comparar_cadenas (const char *cad1, const char *cad2)
{
	bool sigo = true; 

	while ((sigo) && (*cad1 != '\0') && (*cad2 != '\0')) 
		if (*cad1 == *cad2) {
			cad1++;
			cad2++;
		} 
		else sigo = false; 

	return (*cad1 - *cad2); 
}

/***************************************************************************/
/***************************************************************************/
// Devuelve una copia de una cadena.
// Par�metros: 
//		original, puntero a la cadena original (direcci�n del 
//			  primer car�cter)
//		copia, puntero a la cadena que contendr� la copia  
//			(direcci�n del primer car�cter)
// Devuelve:
//		Puntero al inicio de la cadena copia.
// PRE: El puntero "copia" referencia a una zona de memoria reservada.  
//		Hay suficiente espacio reservado para albergar la copia

char * copiar_cadena (char *copia, const char *original)
{
	// Apuntar al inicio de la zona a copiar ("original") con "p_original"
	const char * p_original = original;
	
	// Apuntar a la zona que recibe la copia ("copia") con "copia" 	
	char *p_copia = copia;

	while (*p_original != '\0') {
		
		*p_copia = *p_original;   // Copia
		
		p_copia++; 		// Adelantar punteros 
		p_original++;
	}
	
	*p_copia = '\0'; // importante!!

	return (copia);
}



//Funcion que elimina los blancos al inicio de una cadena
//Recibe la cadena original y devuelve otra sin los blancos iniciales 
//La cadena original no se modifica
char * eliminar_blancos_iniciales (char *cad_nueva, const char * cadena)
{
	
	char * p_cad_nueva = cad_nueva;
	const char * p_cadena = cadena;
	
	//Mientras en la cadena recibida haya espacios en blanco, avanzamos el
	//puntero
	while ( (*p_cadena == ' ') ){
		p_cadena++;	
	}

	//Cuando el puntero se encuentra ya en el primer caracter que no es un
	//espacio en blanco, copiamos desde esa posicion a la cadena nueva a
	//devolver
	return copiar_cadena(cad_nueva, p_cadena);
};


//Funcion que elimina los blancos al final de una cadena
//Recibe la cadena original y devuelve otra sin los blancos finales 
//La cadena original no se modifica
char * eliminar_blancos_finales (char *cad_nueva, const char * cadena)
{
	char * p_cad_nueva = cad_nueva;
	const char * p_cadena = cadena;
	

	int tamanio = longitud_cadena(p_cadena);
	int tope = tamanio;
	const char * p_cadena_final = p_cadena+tamanio-1;

	//Colocamos el puntero al final de la cadena original, y vamos
	//retrasando el vector mientras encuentre espacios en blanco y haya
	//algun caracter
	while ( (*p_cadena_final == ' ') && (*p_cadena_final) )
	{
		p_cadena_final--;
		tope--;
	}

	//Cuando tenemos el tope, que es la posicion desde la cual en adelante
	//solo hay espacios en blanco, rellenamos la cadena a devolver con
	//caracteres nulos
	for(int i=tope; i<tamanio; i++)
	{
		*(cad_nueva+i) = '\0'; 
	}
	
	return cad_nueva;
	
};

//Funcion que elimina los blancos al inicio y fin de una cadena
//Recibe la cadena original y devuelve otra sin los blancos de los extremos 
//La cadena original no se modifica
char * eliminar_blancos_extremos (char *cad_nueva, const char * cadena)
{
	//Combinamos la funcion que elimina blancos al inicio con la que
	//elimina blancos al final
	cad_nueva = eliminar_blancos_iniciales(cad_nueva, cadena);
	return eliminar_blancos_finales(cad_nueva, cad_nueva);
}

//Funcion que elimina los blancos en mitad de una cadena
//Recibe la cadena original y devuelve otra sin los blancos intermedios
//NO elimina los blancos iniciales ni finales 
//La cadena original no se modifica
char * eliminar_blancos_intermedios (char *cad_nueva, const char * cadena)
{
	char * p_cad_nueva = cad_nueva;
	const char * p_cadena_inicio = cadena;
	int tamanio = longitud_cadena(p_cadena_inicio);
	const char * p_cad_final = cadena+tamanio-1;
	int i=0;
	
	//Calculamos las posiciones entre los que tenemos que eliminar los blancos
	//Este rango viene determinado por el primer caracter que no es blanco y 
	//el ultimo que no es blanco
	while ((*p_cadena_inicio == ' ') && (*p_cadena_inicio))
	{
		p_cadena_inicio++;
		*(cad_nueva+i) = ' ';
		i++;
	}

	int tope = tamanio;
	while ( (*p_cad_final == ' ') && (*p_cad_final) ){
		p_cad_final--;
		tope--;
	}

	//Para cada blanco que encontremos, atrasamos en una posicion cada
	//elemento de la cadena, para asi sobreescribir los blancos
	for(int a=i; a<tope; a++)
	{
		if( *(cad_nueva+a) == ' ')
		{
			for(int m=a; m<tope; m++)
			{
				*(cad_nueva+m) = *(cad_nueva+m+1);
			}
			a--;
			tope--;
		}
	};





	return (cad_nueva);

}

//Funcion que elimina los blancos al inicio,mitad y final de una cadena
//Recibe la cadena original y devuelve otra sin ningun espacio en blanco 
//La cadena original no se modifica
char * eliminar_todos_blancos (char *cad_nueva, const char * cadena)
{	
	//Combinamos eliminar los blancos intermedios y los extremos
	cad_nueva = eliminar_blancos_intermedios(cad_nueva, cadena);
	return(eliminar_blancos_extremos(cad_nueva, cad_nueva) );
}
/***************************************************************************/
/***************************************************************************/

//Funcion que recibe una cadena de caracteres y modifica el array
//recibido del tipo info_palabra, donde almacena en cada posicion un puntero
//al inicio y final de cada respectiva palabra
//Devuelve el numero de palabras encontradas
int encuentra_palabras(info_palabra * palabras, char * cadena)
{
    int contador = 0;
    char * iniciocontador = cadena;
    int tamanio = longitud_cadena(cadena);
    char * fincontador = cadena+tamanio-1;

    while( *iniciocontador != '\0' && iniciocontador<fincontador)
    {
        if( *iniciocontador!=' ' )
        {
            (*(palabras+contador)).inicio = iniciocontador;
            char * pfinpalabra = iniciocontador;
            for(;*pfinpalabra!=' ' && *pfinpalabra!='\0';pfinpalabra++){}

            (*(palabras+contador)).fin = pfinpalabra;
            contador++;
            iniciocontador = pfinpalabra;
        }
        iniciocontador++;
    }

    return contador;
}

//Funcion que recibe un array del tipo info_palabra y el numero de palabras
//a mostrar, y lo muestra por pantalla
void MuestraPalabras( int num_palabras, info_palabra * las_palabras){
    info_palabra * p = las_palabras;
    char * pinicio;
    char * pfin;
    int contador=0;
    while(contador<num_palabras){
        int i=0;
        pinicio = p->inicio;
        pfin=p->fin;
        while(pinicio<pfin)
        {
            cout<<*pinicio;
            i++;
            pinicio++;
        }
        cout<<endl;
        p++;
        contador++;
    }
};

//Funcion que extrae desde la posicion p de la cadena origen hasta la
//posicion p+l y la copia en la cadena resultado desde su inicio
char * extraer_subcadena(char * resultado, const char * origen,
int p, int l)
{
	const char * inicio = origen+p;
	const char * fin = inicio + l;
	char * p_res = resultado;

	while(inicio<fin){
		*p_res = *inicio;
		inicio++;
		p_res++;
	}
	*p_res = '\0';

	return resultado;
	
};

//Funcion intercambia para char
void Intercambia (char * p1, char * p2){
{
	char tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
    return;
}
};

//Funcion que ordena una cadena por orden alfabetico
void OrdenarPorCaracteres(char * v){
    char * p_cadena = v;
    int tamanio = longitud_cadena(v);

    for (int izda = 0; izda < tamanio; izda++) {

		// Calcular el mínimo entre "izda" y "total_utilizados"-1

		int minimo = v[izda]; // Valor del mínimo
		int pos_min = izda;   // Posición del mínimo

		for (int i = izda + 1; i < tamanio; i++)

			if (v[i] < minimo){ // Nuevo mínimo
			    minimo = v[i];
			    pos_min = i;
			 }

		// Intercambiar los valores guardados en "izda" y "pos_min"  

		Intercambia (&v[izda], &v[pos_min]);
   }
}


bool es_seudosimetrica (const char * cadena,char * c1, char * c2){
    int longitud = longitud_cadena(cadena);
    int centro = 0;
    bool ret = false;

    
    if( (longitud%2)==0)
    {
        centro = longitud/2;
        c1 = extraer_subcadena(c1, cadena, 0, centro);
        c2 = extraer_subcadena(c2, cadena, centro, longitud);
        
    }
    else
    {
        centro = longitud/2;
        c1 = extraer_subcadena(c1, cadena, 0, centro);
        c2 = extraer_subcadena(c2, cadena, centro+1, longitud);       
    }

    OrdenarPorCaracteres(c1);
    OrdenarPorCaracteres(c2);
        
    if(comparar_cadenas(c1,c2)==0){
        ret = true;
    }

    return ret;
};