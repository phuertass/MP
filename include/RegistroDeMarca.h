/***************************************************************************/
/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// PABLO HUERTAS ARROYO
//
// Fichero: ClasesRankingMarcas.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef CLASES_RANKING_MARCAS
#define CLASES_RANKING_MARCAS

#include <string>
#include "Tiempo.h"
#include "Fecha.h"
#include "utils.h"
using namespace std;

// Registro de marca

class RegistroDeMarca
{

private:
	Fecha fecha_marca;	 // Fecha de la marca
	string licencia;	 // Licencia del atleta
	Tiempo tiempo_marca; // Tiempo registrado

public:
	/***********************************************************************/
	// Constructor sin argumentos.
	// Necesario para crear arrays o matrices.

	RegistroDeMarca(void);

	/***********************************************************************/
	// Constructor directo.
	// Parámetros: trivial.

	RegistroDeMarca(Fecha la_fecha_marca, string la_licencia,
					Tiempo el_tiempo_marca);

	/***********************************************************************/
	// Constructor de copia.
	// Parámetros: triviales.
	RegistroDeMarca(const RegistroDeMarca &otro);

	/***********************************************************************/
	// Métodos Get

	Fecha GetFecha(void) const;
	string GetLicencia(void) const;
	Tiempo GetTiempo(void) const;

	/***********************************************************************/
	// Serializa un dato RegistroDeMarca.

	string ToString(void) const;

	RegistroDeMarca &operator=(const RegistroDeMarca &otro);

	/***********************************************************************/

	bool operator==(const RegistroDeMarca &r) const;
	bool operator!=(const RegistroDeMarca &r) const;
	bool operator<(const RegistroDeMarca &r) const;
	bool operator<=(const RegistroDeMarca &r) const;
	bool operator>(const RegistroDeMarca &r) const;
	bool operator>=(const RegistroDeMarca &r) const;

	/***********************************************************************/
	// Sobrecarga del operador de salida
	friend ostream &operator<<(ostream &os, const RegistroDeMarca &r);
	friend istream &operator>>(istream &is, RegistroDeMarca &r);
};

/////////////////////////////////////////////////////////////////////////////

#endif
