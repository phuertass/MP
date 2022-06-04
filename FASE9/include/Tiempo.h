#ifndef TIEMPO_H
#define TIEMPO_H
#include <string>
#include "utils.h"
using namespace std;


/***************************************************************************/
/***************************************************************************/

// Tipo para seleccionar el tipo de presentación de los datos "Tiempo" 
// Si "segundos": nos interesa segundos:milesimas
// Si "minutos": nos interesa minutos:segundos:milesimas
// Si "horas": nos interesa horas:minutos:segundos:milesimas
enum class CategoriaTiempo {segundos, minutos, horas};

const int SEGS_MIN = 60; 
const int MINS_HORA = 60; 
const int MILISEGS_SEG = 1000; 
const int MILISEGS_MIN = MILISEGS_SEG*SEGS_MIN;
const int MILISEGS_HORA = MILISEGS_MIN*MINS_HORA;

class Tiempo {
private: 

	int horas;		// 0 <= horas <= 24 
	int minutos; 	// 0 <= minutos < 60
	int segundos; 	// 0 <= segundos < 60	
	int milesimas; 	// 0 <= milesimas < 1000	

public : 

	/***********************************************************************/
	// Constructor sin argumentos. 
	// Necesario para crear arrays o matrices u objetos RegistroDemarca.

	Tiempo (void); 

	/***********************************************************************/
	// Constructor directo. 
	// Parámetros: trivial. 
	// PRE: 0 <= la_hora <= 24 
	// PRE: 0 <= los_minutos <= 60
	// PRE: 0 <= los_segundos <= 60
	// PRE: 0 <= las_milesimas <= 1000

	Tiempo (int la_hora, int los_minutos, int los_segundos, int las_milesimas);

	/***********************************************************************/
	// Constructor desde un string.
	// Parámetros: cad, string con la fecha. 
	// PRE: cad contiene un tiempo CORRECTO en formato hh:mm:ss:mmm 
	// PRE: cad.length() == 12	

	Tiempo (string cad);

	/***********************************************************************/
	// Constructor de copia
	Tiempo (const Tiempo &otro);

	/***********************************************************************/
	// Sobrecarga del operador =.
	// Parámetros: otro, objeto de la clase Tiempo.
	// Devuelve: el objeto actual.
	Tiempo & operator = (const Tiempo &otro);

	/***********************************************************************/
	// Métodos Get

	int GetHoras     (void) const;
	int GetMinutos   (void) const;
	int GetSegundos  (void) const;
	int GetMilesimas (void) const;

	long GetTiempoMilisegundos (void) const;

	/***********************************************************************/
	// Compara dos datos "Tiempo"
	// Parámetros: otro, objeto explícito. 

	bool EsMayor (const Tiempo & otro) const;

	/***********************************************************************/
	// Serializa un dato "Tiempo"

	string  ToString (CategoriaTiempo tipo_tiempo) const;

	/***********************************************************************/

	bool operator == (const Tiempo &t) const;
	bool operator != (const Tiempo &t) const;
	bool operator <  (const Tiempo &t) const;
	bool operator <= (const Tiempo &t) const;
	bool operator >  (const Tiempo &t) const;
	bool operator >= (const Tiempo &t) const;

	/***********************************************************************/
	// Sobrecarga del operador <<
	friend ostream & operator << (ostream &os, const Tiempo &t);
	friend istream & operator >> (istream &is, Tiempo &t);

	
};

#endif