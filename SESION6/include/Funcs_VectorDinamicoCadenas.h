#ifndef VECTOR_DINAMICO_CADENAS
#define VECTOR_DINAMICO_CADENAS

#include <string>
using namespace std; 

/***************************************************************************/
/***************************************************************************/

// Capacidad inicial 
const int TAM_INICIAL = 10; 

// Tamanio del bloque para redimensionar
const int TAM_BLOQUE = 1;

// Valor por defecto para los valores del vector
const int VALOR_DEF = 0;

// Tipo enumerado para representar tipos de redimensionamiento
enum class TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};

typedef char TipoBase; // Tipo de los datos almacenados

void Redimensiona (char ** & lineas, TipoRedimension tipo, int & capacidad);

void Reajusta (char ** & lineas, int num_lineas, int & capacidad_lineas);

void LiberaMemoria(char ** & lineas, int &num_lineas);

void Calculos_lineas(char ** lineas, int num_lineas, int & cv, int & cp);

#endif