#include "Fecha.h"
#include "Tiempo.h"
#include <iostream>
#include <iomanip>
using namespace std;

/***************************************************************************/
// Constructor sin argumentos. 
// Necesario para crear arrays o matrices u objetos RegistroDemarca.
// Inicializa los datos con la fecha actual

Fecha :: Fecha (void) {
	auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
	dia = tm.tm_mday;
	mes = tm.tm_mon + 1;
	anio = tm.tm_year + 1900;
}

/***************************************************************************/
// Constructor directo. 
// Parámetros: trivial. 
// PRE: 1 <= el_dia <= 31 
// PRE: 1 <= el_mes <= 12
// PRE: 1900 <= el_anio	

Fecha :: Fecha (int el_dia, int el_mes, int el_anio)
		        : dia (el_dia), mes (el_mes), anio (el_anio)
{ }

/***************************************************************************/
// Constructor desde un string.
// Parámetros: cad, string con la fecha. 
// PRE: cad contiene una fecha CORRECTA en formato dd/mm/aaaa 
// PRE: cad.length() == 10	

Fecha :: Fecha (string cad)
{
	dia  = stoi(cad.substr(0,2));	 
	mes  = stoi(cad.substr(3,2));	  	
	anio = stoi(cad.substr(6,4));	 
}

/***********************************************************************/
// Constructor de copia

Fecha::Fecha (const Fecha &f)
{
	*this = f;
}

/***************************************************************************/
// Sobrecarga del operador de asignación.
// Parámetros: f, objeto de la clase Fecha.
// Devuelve: referencia a la propia clase.

Fecha & Fecha :: operator= (const Fecha &f)
{
	if (this != &f)
	{
		dia  = f.dia;
		mes  = f.mes;
		anio = f.anio;
	}
	
	return *this;
}

/***********************************************************************/
// Métodos Get

int Fecha :: GetDia (void) const
{
	return dia; 
}

int Fecha :: GetMes (void) const
{
	return mes; 
}

int Fecha :: GetAnio (void) const
{
	return anio; 
}

/***************************************************************************/
// Serializa un dato Fecha.

string Fecha :: ToString (void) const
{
	const string MESES[] = {"Enero     ", "Febrero   ", "Marzo     ", 
							"Abril     ", "Mayo      ", "Junio     ", 
							"Julio     ", "Agosto    ", "Septiembre", 
							"Octubre   ", "Noviembre ", "Diciembre "};
	string cad; 
	
	cad = cad + ::ToString(dia,  2, ' ') + " " +  MESES[mes-1] + " " + 
		        ::ToString(anio, 4, ' ');
	
	return cad; 
}

/***************************************************************************/
// Sobrecargaa del operador ==
// Devuelve true si las fechas a comparar tienen el mismo dia, mes y año

bool Fecha :: operator== (const Fecha &otra) const
{
	return (dia == otra.dia && mes == otra.mes && anio == otra.anio); 
}

/***************************************************************************/
// Sobrecargaa del operador !=
// Devuelve true si las fechas a comparar no tienen el mismo dia, mes o año

bool Fecha :: operator!= (const Fecha &otra) const
{
	return !(*this == otra); 
}

bool Fecha :: operator< (const Fecha &otra) const
{
	int dia1 = GetDia();
	int dia2 = otra.GetDia();
	int mes1 = GetMes();
	int mes2 = otra.GetMes();
	int anio1 = GetAnio();
	int anio2 = otra.GetAnio();

	bool esmayor=true;
	if(anio1>anio2){
		esmayor=true;
	}else if(anio1==anio2 && mes1>mes2){
		esmayor=true;
	}else if(anio1==anio2 && mes1==mes2 && dia1>dia2){
		esmayor=true;
	}else{
		esmayor=false;
	}
	return esmayor;
}

bool Fecha :: operator<= (const Fecha &otra) const
{
	return (*this < otra || *this == otra); 
}

bool Fecha :: operator> (const Fecha &otra) const
{
	return !(*this <= otra); 
}

bool Fecha :: operator>= (const Fecha &otra) const
{
	return !(*this < otra); 
}

ostream & operator<< (ostream &os, const Fecha &f)
{
	os << f.ToString(); 
	return os; 
}

istream & operator>> (istream &is, Fecha &f)
{
	string cad; 
	
	is >> cad; 
	f = Fecha(cad); 
	
	return is; 
}