/***************************************************************************/
// METODOLOG�A DE LA PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//	
//	Declaraci�n de la clase Punto2D
//  Definiciones en: Punto2D.cpp 
//
//	Fichero: Punto2D.h
//
/***************************************************************************/

#ifndef PUNTO2D
#define PUNTO2D

#include <iostream>
#include <string>

#include "Utils.h"

using namespace std;
 
 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Punto2D {
	
private:
	
	// La pareja (x,y) son las coordenadas de un punto en un espacio 2D

	int x;
	int y;

public:
	
	/***********************************************************************/
	/***********************************************************************/
	// Constructor sin argumentos.
	//
	// MUY IMPORTANTE: Nos vemos obligados a escribir este constructor por la
	// clase "ColeccionPuntos2D": cuando act�a el constructor sin argumentos 
	// de esa clase crea un vector de objetos "Punto2D" y cada elemento del  
	// vector se crea usando este constructor. 
	// No hace nada �til, pero debe estar.
		
	Punto2D (void);

	/***********************************************************************/
	/***********************************************************************/
	// Constructor con argumentos.
	//
	// Par�metros: cad, cadena que representa a un punto. 
	
	Punto2D (string cad);

	/***********************************************************************/
	/***********************************************************************/
	// Constructor con argumentos.
	//
	// Par�metros: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// 		respectivamente del punto que se est� creando.
	
	Punto2D (int abscisaPunto, int ordenadaPunto);

	/***********************************************************************/
	/***********************************************************************/
	// M�todos Get: Devuelven las coordenadas x e y, repectivamente. 

	int GetX (void) const;
	int GetY (void) const;

	/***********************************************************************/
	/***********************************************************************/
	// M�todos Set: Fijan las coordenadas. 
	//
	// Par�metros: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// 		respectivamente del punto que se est� modificando.

	void SetX (int abscisaPunto);
	void SetY (int abscisaPunto);
	void SetCoordenadas (int abscisaPunto, int ordenadaPunto);
	
	/***********************************************************************/
	/***********************************************************************/
	// M�todos que calculan si dos datos Punto2D son iguales o distintos

	bool operator == (const Punto2D & otro) const;
	bool operator != (const Punto2D & otro) const;

	/***********************************************************************/
	/***********************************************************************/
	// Calcula la distancia Eucl�dea del punto (objeto impl�cito) a otro que 
	// se recibe como argumento. 
	//
	// Par�metros: otro(referencia), el punto respecto al cual que se quiere 
	//		calcular la distancia eucl�dea.
	// Devuelve: la distancia entre los dos puntos.

	double DistanciaEuclidea (const Punto2D & otro) const;

	/***********************************************************************/
	/***********************************************************************/
	// Devuelve la representaci�n en una cadena de un dato "Punto2D"
	
	string ToString (void) const;

	/***********************************************************************/
	/***********************************************************************/
	// Sobrecarga de los operadores >> y << 

	friend istream & operator >> (istream & in,  Punto2D & el_punto); 
	friend ostream & operator << (ostream & out, const Punto2D & el_punto);  

	/***********************************************************************/
	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#endif
