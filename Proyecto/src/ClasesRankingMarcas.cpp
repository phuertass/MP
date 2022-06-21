/***************************************************************************/
/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Fichero: ClasesRankingMarcas.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "ClasesRankingMarcas.h"

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

string ToString (int entero, int num_casillas, char relleno)
{
	// Inicialmente nos quedamos con el resultado de to_string
	string cadena = to_string(entero);

	int long_cadena = (int) cadena.length(); 
	
	// Si es preciso se completa (por la izquierda) con "relleno"
	
	if (long_cadena < num_casillas) {
		
		int num_casillas_faltan = num_casillas-long_cadena; 
		
		for (int i=0; i<num_casillas_faltan; i++) 
			cadena = relleno + cadena; 
	}

	return cadena;
}

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

string ToString (string la_cadena, int num_casillas, char relleno)
{
	string cadena = la_cadena;

	string cad_relleno; 
	cad_relleno.push_back(relleno); 

	int long_cadena = (int) la_cadena.length(); 
	
	// Si es preciso se completa (por la izquierda) con "relleno"
	
	if (long_cadena < num_casillas) {
		
		int num_casillas_faltan = num_casillas-long_cadena; 
		
		for (int i=0; i<num_casillas_faltan; i++) 
			cadena = cad_relleno + cadena; 
	}

	return cadena;
}

/***************************************************************************/
// Constructor sin argumentos. 
// Necesario para crear arrays o matrices u objetos RegistroDemarca.

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
// Constructor de copia.
Fecha::Fecha (const Fecha &f)
{
	dia  = f.dia;
	mes  = f.mes;
	anio = f.anio;
}

/***************************************************************************/
// Sobrecarga del operador de asignación.
// Parámetros: f, objeto de la clase Fecha.
// Devuelve: referencia a la propia clase.
Fecha & Fecha :: operator= (const Fecha &f)
{
	dia  = f.dia;
	mes  = f.mes;
	anio = f.anio;
	
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

bool Fecha :: operator== (const Fecha &otra) const
{
	return (dia == otra.dia && mes == otra.mes && anio == otra.anio); 
}

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
	horas = otro.horas;
	minutos = otro.minutos;
	segundos = otro.segundos;
	milesimas = otro.milesimas;
}


/***************************************************************************/
// Sobrecarga del operador de asignación.
// Parámetros: otro, objeto de la clase Tiempo.
// Devuelve: referencia a la propia clase.
Tiempo & Tiempo :: operator= (const Tiempo &otro)
{
	horas = otro.horas;
	minutos = otro.minutos;
	segundos = otro.segundos;
	milesimas = otro.milesimas;
	
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
/***********************************************************************/
// Constructor sin argumentos. 
// Necesario para crear arrays o matrices.

RegistroDeMarca :: RegistroDeMarca (void) {};

/***********************************************************************/
// Constructor con argumentos. 
// Parámetros: triviales. 

RegistroDeMarca :: RegistroDeMarca (Fecha la_fecha_marca, 
	                                string la_licencia, 
	             				    Tiempo el_tiempo_marca) 
				: fecha_marca (la_fecha_marca), 
	              licencia (la_licencia), 
	       		  tiempo_marca (el_tiempo_marca)
{}

/***********************************************************************/
// Constructor de copia. 
// Parámetros: triviales. 
RegistroDeMarca :: RegistroDeMarca (const RegistroDeMarca &otro) 
				: fecha_marca (otro.fecha_marca), 
	              licencia (otro.licencia), 
	       		  tiempo_marca (otro.tiempo_marca)
{}

RegistroDeMarca & RegistroDeMarca::operator= (const RegistroDeMarca &otro)
{
	if (this != &otro) {
		fecha_marca = otro.fecha_marca; 
		licencia = otro.licencia; 
		tiempo_marca = otro.tiempo_marca; 
	}
	return *this; 
}

/***********************************************************************/
// Métodos Get

Fecha  RegistroDeMarca :: GetFecha (void) const
{
	return fecha_marca;
}

string RegistroDeMarca :: GetLicencia (void) const
{
	return licencia;
}

Tiempo RegistroDeMarca :: GetTiempo (void) const
{
	return tiempo_marca;
}

/***************************************************************************/
// Serializa un dato RegistroDeMarca.

string RegistroDeMarca :: ToString (void) const
{
	string cad = ::ToString(GetLicencia(),12) + "   " + 
	               GetFecha().ToString() + "  " + 
	               GetTiempo().ToString(CategoriaTiempo::minutos);
	return cad;
}

/***********************************************************************/

bool RegistroDeMarca :: operator== (const RegistroDeMarca &otro) const
{
	return (GetFecha() == otro.GetFecha() && 
			GetLicencia() == otro.GetLicencia() && 
			GetTiempo() == otro.GetTiempo()); 
}

bool RegistroDeMarca :: operator!= (const RegistroDeMarca &otro) const
{
	return !(*this == otro); 
}

bool RegistroDeMarca :: operator< (const RegistroDeMarca &otro) const
{
	return GetTiempo() < otro.GetTiempo();
}

bool RegistroDeMarca :: operator<= (const RegistroDeMarca &otro) const
{
	return (*this < otro || *this == otro); 
}

bool RegistroDeMarca :: operator> (const RegistroDeMarca &otro) const
{
	return !(*this <= otro); 
}

bool RegistroDeMarca :: operator>= (const RegistroDeMarca &otro) const
{
	return !(*this < otro); 
}
