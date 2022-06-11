#include "Tiempo.h"
using namespace std;
/***************************************************************************/
// Constructor sin argumentos. 
// Necesario para crear arrays o matrices u objetos RegistroDemarca.

Tiempo :: Tiempo (void) {
	horas = 0;
	minutos = 0;
	segundos = 0;
	milesimas = 0;
}

/***************************************************************************/
// Constructor directo. 
// Parámetros: trivial. 
// PRE: 0 <= la_hora <= 24 
// PRE: 0 <= los_minutos <= 60
// PRE: 0 <= los_segundos <= 60
// PRE: 0 <= las_milesimas <= 1000

Tiempo :: Tiempo (int la_hora, int los_minutos, 
				  int los_segundos, int las_milesimas) 
		          : horas (la_hora), minutos (los_minutos), 
		            segundos (los_segundos), milesimas (las_milesimas) 
{} 

/***************************************************************************/
// Constructor desde un string.
// Parámetros: cad, string con la fecha. 
// PRE: cad contiene un tiempo CORRECTO en formato hh:mm:ss:mmm 
// PRE: cad.length() == 12	

Tiempo :: Tiempo (string cad)
{
	horas     = stoi(cad.substr(0,2));	 
	minutos   = stoi(cad.substr(3,2));	 
	segundos  = stoi(cad.substr(6,2));	 	
	milesimas = stoi(cad.substr(9,3));	 
}

/***********************************************************************/
// Constructor de copia
Tiempo::Tiempo (const Tiempo &otro)
{
	*this = otro;
}


/***************************************************************************/
// Sobrecarga del operador de asignación.
// Parámetros: otro, objeto de la clase Tiempo.
// Devuelve: referencia a la propia clase.
Tiempo & Tiempo :: operator= (const Tiempo &otro)
{
	if (this != &otro)
	{
		horas = otro.horas;
		minutos = otro.minutos;
		segundos = otro.segundos;
		milesimas = otro.milesimas;
	}
	
	return *this;
}

/***********************************************************************/
// Métodos Get

int Tiempo :: GetHoras (void) const
{
	return horas; 
}

int Tiempo :: GetMinutos (void) const
{
	return minutos; 
}

int Tiempo :: GetSegundos (void) const
{
	return segundos; 
}

int Tiempo :: GetMilesimas (void) const
{
	return milesimas; 
}

long Tiempo :: GetTiempoMilisegundos (void) const
{
	return (horas*MILISEGS_HORA + minutos*MILISEGS_MIN + 
			segundos*MILISEGS_SEG + milesimas);	
}

/***************************************************************************/
/***************************************************************************/

bool Tiempo :: EsMayor (const Tiempo & otro) const
{
	long int milisegs_1, milisegs_2;
	
	milisegs_1 = GetTiempoMilisegundos(); 
	milisegs_2 = otro.GetTiempoMilisegundos(); 
				 
	return (milisegs_1 > milisegs_2);
}

/***************************************************************************/
// Serializa un dato Tiempo.

string Tiempo :: ToString (CategoriaTiempo tipo_tiempo) const
{
	string cad; 
	
	switch (tipo_tiempo) {
		
		case (CategoriaTiempo::horas) : {
			cad = cad + ::ToString(GetHoras(), 2, '0') + ":"; 
		}
		case (CategoriaTiempo::minutos) : {
			cad = cad + ::ToString(GetMinutos(), 2, '0') + ":"; 
		}		
		default: {
			cad = cad + ::ToString(GetSegundos(), 2, '0') + ":" + 
		  		        ::ToString(GetMilesimas(), 3, '0');
			break;
		} 
	}

	return cad; 
}

bool Tiempo::operator== (const Tiempo &otro) const
{
	return (GetHoras() == otro.GetHoras() && 
			GetMinutos() == otro.GetMinutos() && 
			GetSegundos() == otro.GetSegundos() && 
			GetMilesimas() == otro.GetMilesimas()); 
}

bool Tiempo::operator!= (const Tiempo &otro) const
{
	return !(*this == otro); 
}

bool Tiempo::operator< (const Tiempo &otro) const
{
	return !EsMayor(otro);
}

bool Tiempo::operator<= (const Tiempo &otro) const
{
	return (*this < otro || *this == otro); 
}

bool Tiempo::operator> (const Tiempo &otro) const
{
	return !(*this <= otro); 
}

bool Tiempo::operator>= (const Tiempo &otro) const
{
	return !(*this < otro); 
}

// Sobrecarha operador <<
ostream & operator << (ostream &os, const Tiempo &t)
{
	os << t.ToString(CategoriaTiempo::horas);
	//os << t.ToString(CategoriaTiempo::minutos);  
	//os << t.ToString(CategoriaTiempo::segundos);
	return os; 
}


istream & operator >> (istream &is, Tiempo &t)
{
	string cad; 
	
	is >> cad; 
	t = Tiempo(cad); 
	
	return is; 
}