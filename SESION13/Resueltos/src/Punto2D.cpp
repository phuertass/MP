/***************************************************************************/
// METODOLOG�A DE LA PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// Definici�n de la clase Punto2D
// Declaraciones en: Punto2D.h 
//
// Fichero: Punto2D.cpp
//
/***************************************************************************/

#include <cctype>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

#include "Punto2D.h"
#include "Utils.h"

using namespace std;


/***************************************************************************/
/***************************************************************************/
// Constructor sin argumentos.
//
// MUY IMPORTANTE: Nos vemos obligados a escribir este constructor por la
// clase "ColeccionPuntos2D": cuando act�a el constructor sin argumentos 
// de esa clase crea un vector de objetos "Punto2D" y cada elemento del  
// vector se crea usando este constructor. 
// No hace nada �til, pero debe estar.

Punto2D :: Punto2D (void) { }

/***************************************************************************/
/***************************************************************************/
// Constructor con argumentos.
//
// Par�metros: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
// 		respectivamente del punto que se est� creando.

Punto2D :: Punto2D (int abscisaPunto, int ordenadaPunto)
{
	SetCoordenadas (abscisaPunto, ordenadaPunto);
}

/***********************************************************************/
/***********************************************************************/
// Constructor con argumentos.
//
// Par�metros: cad, cadena que representa a un punto. 

Punto2D :: Punto2D (string cad)
{
	x = stoi(cad.substr(1,2));	 
	y = stoi(cad.substr(4,2));	 
}

/***************************************************************************/
/***************************************************************************/
// M�todos Get: Devuelven las coordenadas x e y, repectivamente. 

int Punto2D :: GetX (void) const
{
	return (x);
}
int Punto2D :: GetY (void) const
{
	return (y);
}

/***************************************************************************/
/***************************************************************************/
// M�todos Set: Fijan las coordenadas. 
//
// Par�metros: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
// 		respectivamente del punto que se est� modificando.

void Punto2D :: SetX (int abscisaPunto)
{
	x = abscisaPunto;
}
void Punto2D :: SetY (int ordenadaPunto)
{
	y = ordenadaPunto;
}
void Punto2D :: SetCoordenadas (int abscisaPunto, int ordenadaPunto)
{
	SetX (abscisaPunto);
	SetY (ordenadaPunto);
}

/***************************************************************************/
/***************************************************************************/
// Calcula si dos puntos son iguales 
//
// Par�metros: otro (referencia), el punto que se quiere comparar con el 
//		objeto impl�cito. 
// Devuelve: true, si se consideran iguales los dos objetos. 

bool Punto2D :: operator == (const Punto2D & otro) const
{
	return ((x==otro.x) && (y==otro.y));
}

/***************************************************************************/
/***************************************************************************/
// Calcula si dos puntos son distintos 
//
// Par�metros: otro (referencia), el punto que se quiere comparar con el 
//		objeto impl�cito. 
// Devuelve: true, si se consideran distintos los dos objetos. 

bool Punto2D :: operator != (const Punto2D & otro) const
{
	return (!(*this == otro));
}

/***************************************************************************/
/***************************************************************************/
// Calcula la distancia Eucl�dea del punto (objeto impl�cito) a otro que 
// se recibe como argumento. 
//
// Par�metros: otro(referencia), el punto respecto al cual que se quiere 
//		calcular la distancia eucl�dea.
// Devuelve: la distancia entre los dos puntos. 

double Punto2D :: DistanciaEuclidea (const Punto2D & otro) const
{
	double dif_x = pow (x - otro.x, 2);
	double dif_y = pow (y - otro.y, 2);

	return (sqrt(dif_x + dif_y));
}

/***************************************************************************/
/***************************************************************************/
// Serializa un dato "Punto2D".

string Punto2D :: ToString (void) const 
{
	return ("["+FormatInt(x,2) + "," + FormatInt(y,2)+"]");	
}

/***************************************************************************/
/***************************************************************************/
// Sobrecarga de los operadores >> y << 

istream & operator >> (istream & in,  Punto2D & el_punto)
{

	string cad;
	in >> cad; 

	if (!in.eof()) {
		Punto2D punto_leido (cad);
		el_punto = punto_leido;
	}

	return in; 
}

ostream & operator << (ostream & out, const Punto2D & el_punto)
{
	out << el_punto.ToString();
	return out; 
}

/***************************************************************************/
/***************************************************************************/


