/***************************************************************************/
/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Fichero: ClasesRankingMarcas.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef CLASES_RANKING_MARCAS
#define CLASES_RANKING_MARCAS

#include <string>
using namespace std;

/***************************************************************************/
// Convierte el dato int "entero" a un string con "num_casillas" casillas 
// que contiene el valor textual de "entero".
// 
// Recibe: 	entero, el valor a transformar.
//			num_casillas, número total de casillas que tendrá el resultado.
//			relleno, el carácter que se emplea para rellenar los huecos. 
// Devuelve: el string compuesto.  
//
// NOTAS: Si el número de casillas solicitado es mayor que el que se necesita, 
//	  	se completa al principio con "relleno" hasta alcanzar un tamaño de 
//	  	"num_casillas". Si el valor tuviera "per se" más de "num_casillas" 
//		se devuelve tal cual.  

string ToString (int entero, int num_casillas, char relleno); 

/***************************************************************************/
// Convierte el dato string "la_cadena" a un string con "num_casillas" 
// casillas rellenando con el caracter "relleno" por la izquierda.
// 
// Recibe: 	la_cadena, el valor a transformar.
//			num_casillas, número total de casillas que tendrá el resultado.
//			relleno, el carácter que se emplea para rellenar los huecos. 
// Devuelve: el string compuesto.  
//
// NOTAS: Si el número de casillas solicitado es mayor que el que se necesita, 
//	  	se completa al principio con "relleno" hasta alcanzar un tamaño de 
//	  	"num_casillas". Si el valor tuviera "per se" más de "num_casillas" 
//		se devuelve tal cual.  

string ToString (string la_cadena, int num_casillas, char relleno=' '); 

/////////////////////////////////////////////////////////////////////////////
// Registro de fecha (¡¡sin filtros rigurosos!!)

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
	
};

/////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////
// Registro de tiempo (¡¡sin filtros rigurosos!!)

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

	
};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// Registro de marca 

class RegistroDeMarca {

private: 
	Fecha fecha_marca;		// Fecha de la marca 
	string licencia;		// Licencia del atleta
	Tiempo tiempo_marca;	// Tiempo registrado

public : 

	/***********************************************************************/
	// Constructor sin argumentos. 
	// Necesario para crear arrays o matrices.

	RegistroDeMarca (void); 

	/***********************************************************************/
	// Constructor directo. 
	// Parámetros: trivial. 

	RegistroDeMarca (Fecha la_fecha_marca, string la_licencia, 
		             Tiempo el_tiempo_marca);

	
	/***********************************************************************/
	// Constructor de copia. 
	// Parámetros: triviales.
	RegistroDeMarca (const RegistroDeMarca &otro);


	/***********************************************************************/
	// Métodos Get

	Fecha  GetFecha    (void) const;
	string GetLicencia (void) const;
	Tiempo GetTiempo   (void) const;

	/***********************************************************************/
	// Serializa un dato RegistroDeMarca.

	string  ToString (void) const;

	RegistroDeMarca & operator = (const RegistroDeMarca &otro);

	/***********************************************************************/

	bool operator == (const RegistroDeMarca &r) const;
	bool operator != (const RegistroDeMarca &r) const;
	bool operator <  (const RegistroDeMarca &r) const;
	bool operator <= (const RegistroDeMarca &r) const;
	bool operator >  (const RegistroDeMarca &r) const;
	bool operator >= (const RegistroDeMarca &r) const;

};

/////////////////////////////////////////////////////////////////////////////

#endif
