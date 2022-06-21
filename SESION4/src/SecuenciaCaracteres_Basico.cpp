#include "SecuenciaCaracteres_Basico.h"

using namespace std;

// Constructor con argumento string.
// "Copia" el contenido del string en la secuencia 

SecuenciaCaracteres::SecuenciaCaracteres (string cad) 
{
    int num_caracteres;
    
    int long_cad = cad.length();
    
    if (long_cad > TAMANIO) num_caracteres = TAMANIO;
    else num_caracteres = long_cad;
    
    for (int pos=0; pos<num_caracteres; pos++) 
        vector_privado[pos] = cad.at(pos);
        
    total_utilizados = num_caracteres;	
}

/***********************************************************************/
// Constructor con char e int.
// Rellena la secuencia con "n" caracteres "c".

SecuenciaCaracteres::SecuenciaCaracteres (char c, int n)
{
    int num_caracteres;

    if (n > TAMANIO) num_caracteres = TAMANIO;
    else num_caracteres = n;
        
    for (int pos=0; pos<num_caracteres; pos++) 
        vector_privado[pos] = c;		

    total_utilizados = num_caracteres;		
}

/***********************************************************************/
// A�ade un elemento ("nuevo") al vector.
// PRE: total_utilizados < TAMANIO
// 		La adici�n se realiza si hay alguna casilla disponible.
// 		El nuevo elemento se coloca al final del vector.
// 		Si no hay espacio, no se hace nada.

void SecuenciaCaracteres::Aniade (char nuevo)
{
    if (total_utilizados < TAMANIO){
        vector_privado[total_utilizados] = nuevo;
        total_utilizados++;
    }
}

/***********************************************************************/
// Cambia el contenido de la casilla "indice" por el valor "nuevo"
// PRE: 0 <= indice < total_utilizados

void SecuenciaCaracteres::Modifica (int indice, char nuevo)
{
    if ((indice >= 0) && (indice < total_utilizados))
        vector_privado[indice] = nuevo;
}


/***********************************************************************/
// Eliminar el car�cter de la posici�n dada por "indice".
// Realiza un borrado f�sico (desplazamiento y sustituci�n).
// PRE: 0 <= indice < total_utilizados

void SecuenciaCaracteres::Elimina (int indice)
{
    if ((indice >= 0) && (indice < total_utilizados)) {

        int tope = total_utilizados-1; // posic. del �ltimo

        for (int i = indice ; i < tope ; i++)
            vector_privado[i] = vector_privado[i+1];

        total_utilizados--;
    }
}


/***********************************************************************/
// Inserta el car�cter "nuevo" en la posici�n dada por "indice".
// Desplaza todos los caracteres una posici�n a la derecha antes de 
// copiar en "indice" en valor "nuevo".
// PRE: 0 <= indice < total_utilizados
// PRE: total_utilizados < TAMANIO
// 		La inseerci�n se realiza si hay alguna casilla disponible.
// 		Si no hay espacio, no se hace nada.

void SecuenciaCaracteres::Inserta (int indice, char valor_nuevo)
{
    if ((indice >= 0) && (indice < total_utilizados) 
        && (total_utilizados < TAMANIO)) {
    
        for (int i = total_utilizados ; i > indice ; i--)
            vector_privado[i] = vector_privado[i-1];
        
        vector_privado[indice] = valor_nuevo;
        total_utilizados++;		
    }
}

/***********************************************************************/
// Compone un string con todos los caracteres que est�n
// almacenados en la secuencia y lo devuelve.

string SecuenciaCaracteres::ToString()
{
    string cadena;

    for (int i=0; i<total_utilizados; i++)
        cadena = cadena + vector_privado[i];

    return (cadena);
}

/*****************************************************************/

