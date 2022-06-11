/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Proyecto Gestion de marcas de atletismo
//
// Fichero: RegistroDeMarca.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "RegistroDeMarca.h"

using namespace std;

/***********************************************************************/
// Constructor sin argumentos.
// Necesario para crear arrays o matrices.

RegistroDeMarca ::RegistroDeMarca(void){};

/***********************************************************************/
// Constructor con argumentos.
// Parámetros: triviales.

RegistroDeMarca ::RegistroDeMarca(Fecha la_fecha_marca,
								  Licencia la_licencia,
								  Tiempo el_tiempo_marca)
	: fecha_marca(la_fecha_marca),
	  licencia(la_licencia),
	  tiempo_marca(el_tiempo_marca)
{
}

/***********************************************************************/
// Constructor de copia.
// Parámetros: triviales.
RegistroDeMarca ::RegistroDeMarca(const RegistroDeMarca &otro)
{
	*this = otro;
}

RegistroDeMarca &RegistroDeMarca::operator=(const RegistroDeMarca &otro)
{
	if (this != &otro)
	{
		fecha_marca = otro.fecha_marca;
		licencia = otro.licencia;
		tiempo_marca = otro.tiempo_marca;
	}
	return *this;
}

/***********************************************************************/
// Métodos Get

Fecha RegistroDeMarca ::GetFecha(void) const
{
	return fecha_marca;
}

Licencia RegistroDeMarca ::GetLicencia(void) const
{
	return licencia;
}

Tiempo RegistroDeMarca ::GetTiempo(void) const
{
	return tiempo_marca;
}

/***************************************************************************/
// Serializa un dato RegistroDeMarca.

string RegistroDeMarca ::ToString(void) const
{
	string cad = ::ToString(GetLicencia().GetNombre(), 12) + "   " +
				 GetFecha().ToString() + "  " +
				 GetTiempo().ToString(CategoriaTiempo::minutos);
	return cad;
}

/***********************************************************************/

bool RegistroDeMarca ::operator==(const RegistroDeMarca &otro) const
{
	return (GetFecha() == otro.GetFecha() &&
			GetLicencia() == otro.GetLicencia() &&
			GetTiempo() == otro.GetTiempo());
}

bool RegistroDeMarca ::operator!=(const RegistroDeMarca &otro) const
{
	return !(*this == otro);
}

bool RegistroDeMarca ::operator<(const RegistroDeMarca &otro) const
{
	return GetTiempo() < otro.GetTiempo();
}

bool RegistroDeMarca ::operator<=(const RegistroDeMarca &otro) const
{
	return (*this < otro || *this == otro);
}

bool RegistroDeMarca ::operator>(const RegistroDeMarca &otro) const
{
	return !(*this <= otro);
}

bool RegistroDeMarca ::operator>=(const RegistroDeMarca &otro) const
{
	return !(*this < otro);
}

ostream &operator<<(ostream &os, const RegistroDeMarca &r)
{
	os.setf(ios::fixed);
	os.setf(ios::showpoint);
	os << r.fecha_marca << " ";
	// Operador << de "Fecha"
	os << r.licencia << " "; // Operador << de "Licencia"
	os << r.tiempo_marca << " ";
	// Operador << de "Tiempo"
	return (os);
}

istream &operator>>(istream &is, RegistroDeMarca &r)
{
	is >> r.fecha_marca;
	// Operador >> de "Fecha"
	is >> r.licencia; // Operador >> de "Licencia"
	is >> r.tiempo_marca;
	// Operador >> de "Tiempo"
	return (is);
}