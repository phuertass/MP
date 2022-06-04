#ifndef FECHA_H
#define FECHA_H

#include "utils.h"
#include <string>

using namespace std;

class Fecha {

private: 

	int dia;	// 1 <= dia <= 31 
	int mes; 	// 1 <= mes <= 12
	int anio; 	// 1900 <= anio	

public : 

	/***********************************************************************/
	// Constructor sin argumentos. 
	// Necesario para crear arrays o matrices u objetos RegistroDemarca.

	Fecha (void);

	/***********************************************************************/
	// Constructor directo. 
	// Parámetros: trivial. 
	// PRE: 1 <= el_dia <= 31 
	// PRE: 1 <= el_mes <= 12
	// PRE: 1900 <= el_anio	

	Fecha (int el_dia, int el_mes, int el_anio);

	/***********************************************************************/
	// Constructor desde un string.
	// Parámetros: cad, string con la fecha. 
	// PRE: cad contiene una fecha CORRECTA en formato dd/mm/aaaa 
	// PRE: cad.length() == 10	

	Fecha (string cad);

	/***********************************************************************/
	// Constructor de copia.
	Fecha (const Fecha &f);

	/***********************************************************************/
	// Sobrecarga del operador =.
	// Parámetros: f, objeto de la clase Fecha.
	// Devuelve: el objeto actual.
	Fecha & operator = (const Fecha &f);

	/***********************************************************************/
	// Métodos Get

	int GetDia  (void) const;
	int GetMes  (void) const;
	int GetAnio (void) const;

	/***********************************************************************/
	// Serializa un dato Fecha.

	string ToString (void) const; 

	bool operator == (const Fecha &f) const;
	bool operator != (const Fecha &f) const;
	bool operator <  (const Fecha &f) const;
	bool operator <= (const Fecha &f) const;
	bool operator >  (const Fecha &f) const;
	bool operator >= (const Fecha &f) const;


	/***********************************************************************/
	//Sobrecarga del operador de salida
	friend ostream & operator << (ostream &os, const Fecha &f);
	friend istream & operator >> (istream &is, Fecha &f);
	
};



#endif