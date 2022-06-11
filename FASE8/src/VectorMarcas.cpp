/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Proyecto Gestion de marcas de atletismo
//
// Implementacion del tipo "VectorMarcas"y de las funciones de gesti�n.
//
// Cabecera del fichero: VectorMarcas.h
//
// Fichero: VectorMarcas.cpp
//
/***************************************************************************/
/***************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include "utils.h"

#include "VectorMarcas.h"
#define DEBUG_FUNCS_VECTOR_DINAMICO

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructores
/***************************************************************************/
/***************************************************************************/
// Crear vector din�mico
// Par�metros: capacidad_inicial, n�mero de casillas con las que se crea el
// vector.
// 		   tipo, el tipo de redimensi�n que se va a aplicar.
// Devuelve: el vector din�mico creado.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es "capacidad_inicial"
//       El n�mero tipo de redimensi�n es "tipo"

VectorMarcas::VectorMarcas(int capacidad_inicial, string n)
	: nombre(n),
	  num_marcas(0),
	  capacidad(capacidad_inicial)
{
	ReservaMemoria(capacidad);
}

/**
 * @brief Constructor de copia
 * @param v VectorMarcas a copiar
 */

VectorMarcas::VectorMarcas(const VectorMarcas &v)
{
	ReservaMemoria(v.capacidad);
	CopiarDatos(v);
}

/**
 * @brief Constructor a partir de un fichero
 *
 * @param nombre : ficHero de tipo PRUEBA
 * @param nombre_prueba (opcional) : nombre de la prueba
 * @return VectorMarcas
 */

VectorMarcas ::VectorMarcas(const string &nombre)
{
	ifstream fi(nombre);
	string cabecera;
	fi >> cabecera;

	if (cabecera != "PRUEBA")
	{
		cerr << "Error en la cabecera del fichero " << nombre << endl;
		exit(1);
	}
	fi.ignore();

	// cout << "-----------------------------------------------------" << endl;
	char c;
	c = fi.peek();
	// cout << c << endl;
	while (c == '#' or c == ' ')
	{
		fi.ignore(1000, '\n');
		c = fi.peek();
		// cout << c << endl;
	}

	c = fi.peek();
	fi.ignore(1000, '\n');

	string nombre_prueba;
	fi >> nombre_prueba;
	// cout << "Nombre de prueba-->" << nombre_prueba << endl;

	char nm;
	fi >> nm;
	int num_marcas = atoi(&nm);
	// cout << "Numero de marcas-->" << num_marcas << endl;

	ReservaMemoria(TAM_INICIAL);
	this->nombre = nombre_prueba;
	this->capacidad = TAM_INICIAL;
	this->num_marcas = 0;

	string valor;

	char cad[100];

	int veces = 0;
	while (!fi.eof() && veces < num_marcas)
	{
		// Lectura de datos y creacion de objetos de RegistroDeMarca
		// Cada vez que creamos un objeto lo añadimos al vector de marcas de la prueba
		// que le corresponde
		fi >> valor;
		Fecha fecha(valor);

		fi >> valor;
		string licencia = valor;

		fi >> valor;
		Tiempo tiempo = Tiempo(valor);

		RegistroDeMarca registro(fecha, licencia, tiempo);

		AniadeVectorMarcas(registro);

		veces++;
	}

	cout << "Fin de la lectura" << endl;
	fi.close();
}

VectorMarcas::VectorMarcas(const string &nombre_fichero_marcas,
						   const string &nombre_prueba)
{
	ReservaMemoria(0);
	nombre = nombre_prueba;
}

/**
 * @brief Destroy the Vector Marcas object
 *
 */
VectorMarcas::~VectorMarcas()
{
	LiberaVectorMarcas();
}

/**
 * @brief Sobrecarga del operador =
 *
 * @param v : VectorMarcas a copiar
 * @return VectorMarcas&
 */

VectorMarcas &VectorMarcas::operator=(const VectorMarcas &v)
{
	if (this != &v)
	{
		LiberaVectorMarcas();
		ReservaMemoria(v.capacidad);
		CopiarDatos(v);
	}
	return *this;
}

// Metodos Get y Set
void VectorMarcas::SetNombre(string n)
{
	nombre = n;
}

string VectorMarcas::GetNombre()
{
	return nombre;
}

int VectorMarcas::GetNum_marcas()
{
	return num_marcas;
}

void VectorMarcas::setNum_marcas(int n)
{
	num_marcas = n;
}

int VectorMarcas::GetCapacidad()
{
	return capacidad;
}

// Sobrecarga del operador()
// Devuelve el elemento en la posicion pasada por parametro

TipoBaseVector VectorMarcas::operator()(int n)
{
	return GetMarca(n - 1);
}

// Sobrecarga del operador[]
// Devuelve el elemento en la posicion pasada por parametro

TipoBaseVector VectorMarcas::operator[](int n)
{
	return GetMarca(n - 1);
}

/**
 * @brief Suma binaria de dos vectores
 * Se concatenan los valores de ambos
 * @param v : vector a sumar
 * @param v2 : vector a sumar
 * @return VectorMarcas
 */
VectorMarcas operator+(const VectorMarcas &v, const VectorMarcas &v2)
{
	int capacidad = v.capacidad + v2.capacidad;
	VectorMarcas v3(capacidad);
	for (int i = 0; i < v.num_marcas; i++)
	{
		v3.AniadeVectorMarcas(v.las_marcas[i]);
	}
	for (int i = 0; i < v2.num_marcas; i++)
	{
		v3.AniadeVectorMarcas(v2.las_marcas[i]);
	}
	return v3;
}

// Operador binario + de VectorMarcas + RegistroDeMarca
/**
 * @brief Suma binaria de VectorMarcas + RegistroDeMarca
 *
 * @param v : VectorMarcas
 * @param r : RegistroDeMarca
 * @return VectorMarcas
 */
VectorMarcas operator+(const VectorMarcas &v, const RegistroDeMarca &r)
{
	VectorMarcas v2(v.capacidad);
	v2.AniadeVectorMarcas(r);
	return v2;
}
VectorMarcas operator+(const RegistroDeMarca &r, const VectorMarcas &v)
{
	VectorMarcas v2(v.capacidad);
	v2.AniadeVectorMarcas(r);
	return v2;
}

/**
 * @brief Resta binaria de un vector y una licencia
 * Se devuelve un nuevo vector sin los registros con licencia == n
 *
 * @param v : VectorMarcas
 * @param n : string
 * @return VectorMarcas
 */

VectorMarcas operator-(const VectorMarcas &v, const string &n)
{
	VectorMarcas v2(v.capacidad);
	for (int i = 0; i < v.num_marcas; i++)
	{
		if (v.las_marcas[i].GetLicencia() != n)
		{
			v2.AniadeVectorMarcas(v.las_marcas[i]);
		}
	}
	return v2;
}

/**
 * @brief Sobrecarga del operador +=
 * Se añaden todos los registros del segundo en el primero
 * @param v : VectorMarcas a sumar
 * @return VectorMarcas&
 */
VectorMarcas &VectorMarcas::operator+=(const VectorMarcas &v)
{
	for (int i = 0; i < v.num_marcas; i++)
	{
		AniadeVectorMarcas(v.las_marcas[i]);
	}
	return *this;
}

/**
 * @brief Sobrecarga del operador +=
 * Se añade el registro al vector
 * @param r : RegistroDeMarca a sumar
 * @return VectorMarcas&
 */
VectorMarcas &VectorMarcas::operator+=(const RegistroDeMarca &r)
{
	AniadeVectorMarcas(r);
	return *this;
}

/**
 * @brief Sobrecarga del operador -=
 * Elimina todos los registros con licencia == n
 * @param n : string
 * @return VectorMarcas&
 */
VectorMarcas &VectorMarcas::operator-=(const string &n)
{
	for (int i = 0; i < num_marcas; i++)
	{
		if (las_marcas[i].GetLicencia() == n)
			EliminaVectorMarcas(i);
	}
	return *this;
}

/**
 * @brief Sobrecarga del operador <<
 *
 * @param os : flujo de salida
 * @param v : VectorMarcas
 * @return ostream&
 */
ostream &operator<<(ostream &os, const VectorMarcas &v)
{
	VectorMarcas aux = v;

	os << "Nombre del vector: " << aux.nombre << endl;
	os << "Numero de marcas: " << aux.num_marcas << endl;
	os << "Capacidad: " << aux.capacidad << endl;
	os << "Listado de marcas: " << endl;
	for (int i = 1; i <= aux.num_marcas; i++)
	{
		os << aux(i).ToString() << endl;
	}
	return os;
}

/**
 * @brief Sobrecarga del operador >>
 *
 * @param is : flujo de entrada
 * @param v : VectorMarcas
 * @return istream&
 */
istream &operator>>(istream &is, VectorMarcas &v)
{
	string nombre;
	is >> nombre;

	char c;
	is >> c;
	int capacidad = atoi(&c);

	v.nombre = nombre;

	string valor;

	int veces = 0;
	while (!is.eof() && veces < capacidad)
	{
		// Lectura de datos y creacion de objetos de RegistroDeMarca
		// Cada vez que creamos un objeto lo añadimos al vector de marcas de la prueba
		// que le corresponde
		is >> valor;
		Fecha fecha = Fecha(valor);

		is >> valor;
		string licencia = valor;

		is >> valor;
		Tiempo tiempo = Tiempo(valor);

		RegistroDeMarca registro(fecha, licencia, tiempo);

		v += registro;
		veces++;
	}

	return is;
}

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas reservadas de un vector din�mico.
// Par�metros: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas reservadas de un vector din�mico

int VectorMarcas::CapacidadVectorMarcas()
{
	return (capacidad);
}

bool VectorMarcas::EstaVacio()
{
	return (num_marcas == 0);
}

/***************************************************************************/
/***************************************************************************/
// Deja el vector din�mico vac�o
// Par�metros: v (referencia) El vector que se va "vaciar"
// POST: El n�mero de casillas usadas es 0

void VectorMarcas::EliminaTodosVectorMarcas()
{
	LiberaVectorMarcas();
}

/***************************************************************************/
/***************************************************************************/
// Inicializa el vector din�mico copiando en todas las casillas "valor"
// Par�metros: 	v (referencia) El vector que se va inicializar
//				valor, el valor que se va a copiar en todas las casillas.

void VectorMarcas::EcualizaVectorMarcas(const TipoBaseVector valor)
{
	for (int i = 0; i < num_marcas; i++)
	{
		las_marcas[i] = valor;
	}
}

/***************************************************************************/
/***************************************************************************/
// Copia profunda. Hace una copia profunda de "origen" en "destino".
// Par�metros: destino (referencia), el vector que recibe la copia.
//             origen (referencia), el vector del que se hace la copia.

void VectorMarcas::Clona(const VectorMarcas &origen)
{
	LiberaVectorMarcas();

	capacidad = origen.capacidad;
	num_marcas = origen.num_marcas;
	nombre = origen.nombre;

	// Pedir memoria para el nuevo almacen la copia
	las_marcas = new RegistroDeMarca[origen.capacidad];

	// Copiar los valores
	memcpy(las_marcas, origen.las_marcas, num_marcas * sizeof(RegistroDeMarca));
}

/***************************************************************************/
/***************************************************************************/
// A�ade un valor al vector din�mico
// Par�metros:
//		v (referencia), referencia al vector que se va a modificar.
//		valor, valor que se va a a�adir al vector.
// NOTA: Si no hay espacio libre, la funci�n pide espacio adicional usando
//		 la funci�n RedimensionaVectorMarcas.

void VectorMarcas::AniadeVectorMarcas(const TipoBaseVector valor)
{
	// Si no cabe --> redimensionar

	if (num_marcas == capacidad)
	{
		cout << "Redimensionando vector" << endl;
		// Redimensionar
		RedimensionaVectorMarcas();
	}

	// Se haya redimensionado o no, en este punto hay sitio para la inserci�n

	las_marcas[num_marcas] = valor;
	num_marcas++;
}

/***************************************************************************/
/***************************************************************************/
// Consulta � modifica el valor de una casilla dada. Si se utiliza como
// rvalue se emplea para consultar el valor de la casilla "num_casilla".
// Si se utiliza como lvalue se emplea para modificar el valor de la
// casilla num_"casilla".
//
// PRE: 0<=num_casilla<num_marcasVectorMarcas(v)

RegistroDeMarca &VectorMarcas::ValorVectorMarcas(int num_casilla)
{
	return (las_marcas[num_casilla]);
}

/***************************************************************************/
/***************************************************************************/
// Inserci�n. Inserta un valor en una posici�n dada. Los valores que est�n
// desde esa posici�n (incluida) hasta la �ltima se �desplazan� una posici�n
// hacia �ndices mayores.
// Si el vector din�mico estuviera lleno se tiene que redimensionar (de
// acuerdo al tipo de redimensi�n establecido) para poder acoger a "valor".

void VectorMarcas::InsertaVectorMarcas(const TipoBaseVector valor,
									   const int num_casilla)
{
	// Si no cabe --> redimensionar

	if (num_marcas == capacidad)
	{

		// Redimensionar
		RedimensionaVectorMarcas();
	}

	// Desplazar los valores de las casillas "num_casilla", "num_casilla"+1,
	// ... "num_marcas" una posici�n (hacia posiciones mayores)
	RegistroDeMarca *pos_inic_bloque = &las_marcas[num_casilla];
	memmove(pos_inic_bloque + 1, pos_inic_bloque,
			(num_marcas - num_casilla) * sizeof(RegistroDeMarca));

	*pos_inic_bloque = valor; // Escribir "valor" en la casilla "num_casilla"
	(num_marcas)++;			  // Actualizar "num_marcas"
}

/***************************************************************************/
/***************************************************************************/
// Borrado. Elimina un valor en una posici�n dada. Los valores que est�n
// desde la posici�n siguiente a la dada hasta la �ltima se �desplazan� una
// posici�n hacia �ndices menores.
//
// PRE: 0<=num_casilla<num_marcasVectorMarcas(v)

void VectorMarcas::EliminaVectorMarcas(const int num_casilla)
{
	if ((num_casilla >= 0) && (num_casilla < num_marcas))
	{

		// Desplazar los valores de las casillas "num_casilla+1",
		// "num_casilla"+2,..."num_marcas" una posici�n (hacia posiciones menores)
		RegistroDeMarca *pos_inic_bloque = &(las_marcas[num_casilla + 1]);
		memmove(pos_inic_bloque - 1, pos_inic_bloque,
				(num_marcas - num_casilla - 1) *
					sizeof(TipoBaseVector));
		(num_marcas)--; // Actualizar "num_marcas"
	}
}

// FUNCIONES DE ORDENACION
void VectorMarcas::OrdenarPorTiempos()
{
	for (int i = 0; i < num_marcas; i++)
	{
		for (int j = i + 1; j < num_marcas; j++)
		{
			Tiempo t1 = las_marcas[i].GetTiempo();
			Tiempo t2 = las_marcas[j].GetTiempo();
			// if(EsMayorTiempo(t1, t2)){
			//	Intercambia(i, j);
			// }
			if (t1 > t2)
			{
				Intercambia(i, j);
			}
		}
	}
}

bool VectorMarcas::EsMayorTiempo(Tiempo t1, Tiempo t2)
{
	int horas1 = t1.GetHoras();
	int horas2 = t2.GetHoras();
	int minutos1 = t1.GetMinutos();
	int minutos2 = t2.GetMinutos();
	int segundos1 = t1.GetSegundos();
	int segundos2 = t2.GetSegundos();
	int milesimas1 = t1.GetMilesimas();
	int milesimas2 = t2.GetMilesimas();

	bool esmayor = true;
	if (horas1 > horas2)
	{
		esmayor = true;
	}
	else if (horas1 == horas2 && minutos1 > minutos2)
	{
		esmayor = true;
	}
	else if (horas1 == horas2 && minutos1 == minutos2 && segundos1 > segundos2)
	{
		esmayor = true;
	}
	else if (horas1 == horas2 && minutos1 == minutos2 && segundos1 == segundos2 && milesimas1 > milesimas2)
	{
		esmayor = true;
	}
	else
	{
		esmayor = false;
	}
	return esmayor;
}

void VectorMarcas::OrdenarPorFecha()
{
	for (int i = 0; i < num_marcas; i++)
	{
		for (int j = i + 1; j < num_marcas; j++)
		{
			Fecha f1 = las_marcas[i].GetFecha();
			Fecha f2 = las_marcas[j].GetFecha();
			// if(EsMayorFecha(f1, f2)){
			//	Intercambia(i, j);
			// }

			if (f1 < f2)
				Intercambia(i, j);
		}
	}
}

bool VectorMarcas::EsMayorFecha(Fecha f1, Fecha f2)
{
	int dia1 = f1.GetDia();
	int dia2 = f2.GetDia();
	int mes1 = f1.GetMes();
	int mes2 = f2.GetMes();
	int anio1 = f1.GetAnio();
	int anio2 = f2.GetAnio();

	bool esmayor = true;
	if (anio1 > anio2)
	{
		esmayor = true;
	}
	else if (anio1 == anio2 && mes1 > mes2)
	{
		esmayor = true;
	}
	else if (anio1 == anio2 && mes1 == mes2 && dia1 > dia2)
	{
		esmayor = true;
	}
	else
	{
		esmayor = false;
	}
	return esmayor;
}

void VectorMarcas::OrdenarPorNombre()
{
	for (int i = 0; i < num_marcas; i++)
	{
		for (int j = i + 1; j < num_marcas; j++)
		{
			string n1 = las_marcas[i].GetLicencia();
			string n2 = las_marcas[j].GetLicencia();
			if (n1 > n2)
			{
				Intercambia(i, j);
			}
		}
	}
}

/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector din�mico "v" de acuerdo al tipo de redimensi�n
// registrado en "v".
// Adem�s, copia todos los las_marcas en el nuevo vector.
// Par�metros:
//		v (referencia), referencia al vector que se va a redimensionar.

void VectorMarcas::RedimensionaVectorMarcas()
{
	int nueva_capacidad;

	nueva_capacidad = capacidad + TAM_BLOQUE;

#ifdef DEBUG_FUNCS_VECTOR_DINAMICO
	cout << endl;
	cout << "REDIMENSIONADO HASTA --> " << nueva_capacidad << " CASILLAS" << endl;
	cout << endl;
#endif

	// Pedir memoria para el nuevo almacen
	TipoBaseVector *tmp = new TipoBaseVector[nueva_capacidad];

	// Copiar los las_marcas
	for (int i = 0; i < num_marcas; i++)
		tmp[i] = las_marcas[i];

	// Considerar esta copia eficiente:
	// memcpy(tmp, las_marcas, num_marcas * sizeof(TipoBaseVector));

	// Liberar la memoria del antiguo almac�n
	delete[] las_marcas;
	// ReservaMemoria(nueva_capacidad);

	// Actualizar vector din�mico redimensionado

	las_marcas = tmp;
	capacidad = nueva_capacidad;
	// v.num_marcas se mantiene como estaba
}

/***************************************************************************/
/***************************************************************************/
// Redimensiona un vector din�mico para que no haya espacio libre.
// Copia todos los las_marcas en el nuevo vector.
// Par�metros:
//		v (referencia), referencia al vector que se va a reajustar.
// POST: capacidad = num_marcas

void VectorMarcas::ReajustaVectorMarcas()
{
	int nueva_capacidad = num_marcas;

	// cout << endl;
	// cout << "REAJUSTANDO HASTA --> "<<nueva_capacidad << " CASILLAS"<< endl;
	// cout << endl;

	// Pedir memoria para el nuevo almacen
	TipoBaseVector *tmp = new TipoBaseVector[nueva_capacidad];

	// Copiar los las_marcas
	// for (int i=0; i<num_marcas; i++)
	//	tmp[i] = las_marcas[i];

	// Considerar esta copia eficiente:
	memcpy(tmp, las_marcas, num_marcas * sizeof(RegistroDeMarca));

	// Liberar la memoria del antiguo almac�n
	delete[] las_marcas;
	// ReservaMemoria(nueva_capacidad);

	// Actualizar vector din�mico redimensionado

	las_marcas = tmp;
	capacidad = nueva_capacidad;
	// v.num_marcas se mantiene como estaba
}

/**
 * @brief Metodo de escritura en fichero
 * Guarda un dato VectorMarcas en un fichero de texto llamado nombre. El
	fichero será un fichero de prueba.
 *
 * @param nombre : nomre del fichero
 *
 * @cond Si el vector esta vacio no se crea el fichero
 * @cond El vector no se modifica
 */
void VectorMarcas::EscribirVectorMarcas(const string &nombre) const
{
	ofstream fichero;
	fichero.open(nombre.c_str());
	fichero << "PRUEBA" << endl;
	fichero << "# Comentario desde clase VectorMarcas" << endl;
	fichero << "#" << endl;
	fichero << endl;

	fichero << this->nombre << endl;
	fichero << num_marcas << endl;
	for (int i = 0; i < num_marcas; i++)
	{

		Fecha f = las_marcas[i].GetFecha();
		int dia = f.GetDia();
		int mes = f.GetMes();
		int anio = f.GetAnio();

		string diad = to_string(dia);
		string mesd = to_string(mes);
		string aniod = to_string(anio);

		fichero << setfill('0') << setw(2) << diad << "/";
		fichero << setfill('0') << setw(2) << mesd << "/";
		fichero << setfill('0') << setw(4) << aniod << "\t";

		fichero << las_marcas[i].GetLicencia() << "\t";
		Tiempo t = las_marcas[i].GetTiempo();
		fichero << t << endl;
	}
}

/**
 * @brief Metodo de lectura de fichero
 * Lee un dato VectorMarcas de un fichero de texto llamado nombre. El
 * fichero será un fichero de prueba.
 * @param nombre : nombre del fichero
 */
void VectorMarcas::LeerVectorMarcas(const string &nombre)
{
	VectorMarcas v(nombre);
	*this = v;
}

/***************************************************************************/
/***************************************************************************/
// METODOS PRIVADOS
/***************************************************************************/
/***************************************************************************/
/**
 * @brief Reserva memoria para una capacidad dada
 *
 * @param capacidad_inicial : tamaño inicial del vector
 */

void VectorMarcas::ReservaMemoria(int n)
{
	// las_marcas = new RegistroDeMarca[n];
	las_marcas = new TipoBaseVector[n];
	capacidad = n;
}
/**
 * @brief Copia los datos desde un vector explicito origen al implicito
 *
 * @param origen : vector explicito a copiar
 */
void VectorMarcas::CopiarDatos(const VectorMarcas &origen)
{
	capacidad = origen.capacidad;
	num_marcas = origen.num_marcas;
	nombre = origen.nombre;

	// Pedir memoria para el nuevo almacen la copia
	las_marcas = new RegistroDeMarca[origen.capacidad];

	// Copiar los valores
	memcpy(las_marcas, origen.las_marcas, num_marcas * sizeof(RegistroDeMarca));
}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector din�mico
// Par�metros: v (referencia) El vector que se va liberar.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es 0

void VectorMarcas::LiberaVectorMarcas()
{
	if (las_marcas)
	{
		// delete [] las_marcas;
		las_marcas = NULL;
		num_marcas = 0;
		capacidad = 0;
	}
}

/**
 * @brief Devuelve un objeto RegistroDeMarca a partir de una posicion
 *
 * @param n : posicion del vector
 * @return TipoBaseVector
 */
TipoBaseVector VectorMarcas::GetMarca(int pos)
{
	return las_marcas[pos];
}

/**
 * @brief Intercambia los elementos de dos posiciones
 *
 * @param i : posicion 1
 * @param j : posicion 2
 */
void VectorMarcas::Intercambia(int i, int j)
{
	TipoBaseVector aux = las_marcas[i];
	las_marcas[i] = las_marcas[j];
	las_marcas[j] = aux;
}