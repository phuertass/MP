/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Fichero de cabecera asociado al tipo base de las estructuras dinámicas
//
// Fichero: TipoBaseVector.h
//
/***************************************************************************/
/***************************************************************************/
#ifndef TIPOBASE_VECTOR
#define TIPOBASE_VECTOR

enum class TipoMovimiento {I,D,A,B};

typedef struct{
    TipoMovimiento tipo;
    int salto;
} Orden;

//typedef Orden TipoBaseVector;
typedef Orden TipoBaseVector;	// Tipo de los elementos de la estructura dinámica
#define ORDEN			// Para usarlo con #ifdef

#endif
