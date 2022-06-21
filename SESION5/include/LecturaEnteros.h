#ifndef LECTURA_ENTEROS
#define LECTURA_ENTEROS

#include "MiCadenaClasica.h"

#define TOPE 100

int LeeEnteroMayorOIgual (const char * titulo, int menor);

int LeeEnteroEnRango(const char * titulo, bool & valido, int fin,
int inicio=0);

int LeeEntero (const char * titulo, bool & valido);







#endif