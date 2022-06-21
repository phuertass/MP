/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Implementación de las funciones de la clase Lista
//
// Declaraciones en Lista.h
//
// Fichero: Lista.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cassert>
#include <fstream>

#include "TipoBase_Lista.h"
#include "Lista.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructor unificado:
//	a) Constructor sin argumentos, que crea una lista vac�a.
//  b) Constructor con un argumento, que crea una lista con un n�mero de
//		nodos indicado en el argumento.
//	c) Constructor con dos argumentos, que crea una lista con un n�mero
//		de nodos indicado en el primer argumento. Inicia todos los nodos
//		de la lista al valor indicado en el segundo argumento.
//
// Crea una lista enlazada con "num_nodos" nodos. Inicializa todos
// los nodos a un valor com�n, el indicado en el par�metro "valor".
// Par�metros:
//  	num_nodos, n�mero de nodos que se van a crear.
//		valor, valor com�n que se copiar� en las casillas.
// Devuelve: un dato de tipo Lista.
//
// PRE:  num_nodos >= 0
// NOTA: Si num_nodos==0 la lista queda vac�a.

Lista ::Lista(int num_nodos, TipoBaseLista valor)
	: primero(0), tamanio(num_nodos)
{
	ReservarMemoria(tamanio);
	Ecualiza(valor);
}

Lista :: Lista(const char *nombre)
{
	ifstream f(nombre);
	if(!f){
		cerr << "Error al abrir el fichero " << nombre << endl;
		exit(1);
	}
	string cabecera;
	f >> cabecera;
	cout << cabecera;

	if(cabecera!="LISTA"){
		cerr << "Error en la cabecera del fichero " << nombre << endl;
		exit(1);
	}

	ReservarMemoria(0);

	TipoBaseLista s;

	while (f >> s){
		Aniadir(s);
		cout<<s<<" ";
	}
	
}

// Guarda en el fichero de texto nombre el contenido de la lista. Escribe un
// dato por línea. Si el fichero ya existiera, se reemplaza su contenido por
// el de la lista. La lista no se modifica.
void Lista::EscribirLista(const char * nombre)const
{
	ofstream f(nombre);
	if(!f){
		cerr << "Error al abrir el fichero " << nombre << endl;
		exit(1);
	}
	f << "LISTA" << endl;
	for(int i=0; i<tamanio; i++){
		f << (*this)[i] << endl;
	}
}

// Sustituye el contenido de la lista por los valores que están en el fichero
// de texto nombre.
void Lista::LeerLista(const char * nombre)
{
	ifstream f(nombre);
	if(!f){
		cerr << "Error al abrir el fichero " << nombre << endl;
		exit(1);
	}
	string cabecera;
	f >> cabecera;
	cout << cabecera;

	if(cabecera!="LISTA"){
		cerr << "Error en la cabecera del fichero " << nombre << endl;
		exit(1);
	}

	LiberarMemoria();
	ReservarMemoria(0);

	TipoBaseLista s;

	while (f >> s){
		Aniadir(s);
		cout<<s<<" ";
	}
}

/***************************************************************************/
// Constructor de copia

Lista ::Lista(const Lista &otro)
{
	// Reservar memoria para los nodos de la lista
	ReservarMemoria(otro.tamanio);

	// Copiar campos privados y los valores de la lista
	CopiarDatos(otro);
}

/***************************************************************************/
// Destructor

Lista ::~Lista(void)
{
	LiberarMemoria();
}

/***********************************************************************/
// Sobrecarga operador de asignacion

Lista &Lista::operator=(const Lista &otro)
{
	if (this != &otro)
	{
		// Liberar memoria de la lista actual
		LiberarMemoria();

		// Reservar memoria para los nodos de la lista
		ReservarMemoria(otro.tamanio);

		// Copiar campos privados y los valores de la lista
		CopiarDatos(otro);
	}
	return *this;
}

// Sobrecarga operador de asignacion
// Ecualiza todos los nodos de la lista con el valor indicado

Lista &Lista::operator=(const TipoBaseLista &otro)
{
	Ecualiza(otro);
	return *this;
}

/***********************************************************************/
// Sobrecarga operador []

TipoBaseLista &Lista::operator[](int pos)
{
	assert(pos >= 0 && pos <= tamanio);
	return Valor(pos);
}

TipoBaseLista &Lista::operator[](int pos) const
{
	assert(pos > 0 || pos <= tamanio);
	return Valor(pos);
}

/***********************************************************************/
// Sobrecarga operadoradores de relacion <, >, ==, !=, <=, >=

bool Lista::operator<(const Lista &otro) const
{
	bool mayor = true;

	int tam1 = tamanio;
	int tam2 = otro.tamanio;
	int tam_min = tam1 < tam2 ? tam1 : tam2;
	for (int i = 0; i < tam_min && mayor; i++)
	{
		if (Valor(i) >= otro.Valor(i))
			mayor = false;
	}
	return mayor;
}

bool Lista::operator>(const Lista &otro) const
{
	return otro < *this;
}

bool Lista::operator==(const Lista &otro) const
{
	bool iguales = true;
	if (tamanio == otro.Tamanio())
	{
		for (int i = 0; i < tamanio && iguales; i++)
		{
			if (Valor(i) != otro.Valor(i))
				iguales = false;
		}
	}
	else
		iguales = false;

	return iguales;
}

bool Lista::operator!=(const Lista &otro) const
{
	return !(*this == otro);
}
bool Lista::operator<=(const Lista &otro) const
{
	return *this == otro || *this < otro;
}
bool Lista::operator>=(const Lista &otro) const
{
	return *this == otro || *this > otro;
}

ostream &operator<<(ostream &os, const Lista &otro)
{
	Lista l = otro;
	os << l.ToString("Lista");

	return os;
}

istream &operator>>(istream &is, Lista &otro)
{
	TipoBaseLista s;

	while (is >> s)
		otro.Aniadir(s);

	return is;
}

// Sobrecarga del operador binario +
// Suma dos listas y devuelve una lista con el resultado.

Lista operator+(const Lista &l1, const Lista &l2)
{
	Lista l3(l1);
	for (int i = 0; i < l2.tamanio; i++)
	{
		l3.Aniadir(l2.el_valor(i));
	}
	return l3;
}

// Sobrecarga del operador binario +
// Suma a todos los nodos de una lista el valor indicado.

Lista operator+(const Lista &l1, const TipoBaseLista &l2)
{
	Lista l3(l1);
	l3.Aniadir(l2);
	return l3;
}

// Sobrecarga del operador binario +
// Suma a todos los nodos de una lista el valor indicado.

Lista operator+(const TipoBaseLista &l1, const Lista &l2)
{
	Lista l3(l2);
	l3.Aniadir(l1);
	return l3;
}

// Sobrecarga del operador binario -
// Resta dos listas y devuelve una lista con el resultado.

Lista operator-(const Lista &l1, const Lista &l2)
{
	Lista l3 = l1 + l2;

	for (int i = 0; i < l2.tamanio; i++)
	{
		l3.Eliminar(l2.el_valor(i));
	}

	return l3;
}

// Sobrecarga del operador binario -
// Resta a todos los nodos de una lista el valor indicado.

Lista operator-(const Lista &l1, const TipoBaseLista &l2)
{
	Lista l3(l1);
	for (int i = 0; i < l3.tamanio; i++)
	{
		if (l3.el_valor(i) == l2)
			l3.Eliminar(i);
	}
	return l3;
}

// Sobrecarga del operador binario -
// Resta a todos los nodos de una lista el valor indicado.

Lista operator-(const TipoBaseLista &l1, const Lista &l2)
{
	Lista l3(l2);
	for (int i = 0; i < l3.tamanio; i++)
	{
		if (l3.el_valor(i) == l1)
			l3.Eliminar(i);
	}
	return l3;
}

// Sobrecarga del operador unario +=
// Añade un valor a la lista.

Lista &Lista::operator+=(const TipoBaseLista &v)
{
	Aniadir(v);
	return *this;
}

// Sobrecarga del operador unario -=
// Elimina la primera aparicion de un valor dado de la lista

Lista &Lista::operator-=(const TipoBaseLista &v)
{
	int pos = Buscar(v);
	if (pos >= 0)
		Eliminar(pos);
	return *this;
}

/***************************************************************************/
// Consulta si la lista esta vacia
// Devuelve: true si la lista esta vacia.

bool Lista ::EstaVacia(void) const
{
	return (tamanio == 0);
}

/***************************************************************************/
// Devuelve el n�mero de nodos de la lista

int Lista ::Tamanio(void) const
{
	return tamanio;
}

/***********************************************************************/
/***********************************************************************/
// Elimina todos los valores de la lista.
// POST: EstaVacia() == true

void Lista ::EliminaTodos(void)
{
	LiberarMemoria();
}

/***********************************************************************/
/***********************************************************************/
// Devuelve un string con el resultado de "serializar" una lista.
// Par�metros: msg, mensaje que precede al contenido de la lista.

string Lista ::ToString(const char *const msg)
{
	string cad = "--------------------------------------------------\n";
	cad = cad + msg + "\n";
	cad = cad + "Num. nodos = " + to_string(tamanio) + "\n";

	if (tamanio > 0)
	{

		cad = cad + "Valores almacenados en la lista: \n";
		cad = cad + "{ ";

		TipoNodo *p;
		int pos;

		// Se evita el �ltimo nodo

		for (p = primero, pos = 1; pos < tamanio; pos++, p = p->sig)
		{
#ifdef INT
			cad = cad + to_string(p->info);
#else
#ifdef CHAR
			cad = cad + p->info;
#else
#ifdef DOUBLE
			cad = cad + to_string(p->info);
#endif
#endif
#endif

			cad = cad + ", ";
		}

		// Ultimo nodo

#ifdef INT
		cad = cad + to_string(p->info);
#else
#ifdef CHAR
		cad = cad + p->info;
#else
#ifdef DOUBLE
		cad = cad + to_string(p->info);
#endif
#endif
#endif

		cad = cad + "}\n";
	}
	else
		cad = cad + "Lista vacia\n";

	cad = cad + "--------------------------------------------------\n\n";

	return cad;
}

/***************************************************************************/
/***************************************************************************/
// Busca la posici�n de un nodo dado un valor especificado.
// Par�metros: valor, el valor buscado.
// Devuelve la posici�n del primer nodo coincidente,
// 		o -1 si no se encuentra.

int Lista ::Buscar(TipoBaseLista valor) const
{
	TipoNodo *p = primero;

	bool sigo = true;
	bool encontrado = false;

	int pos = 0;

	while ((p != 0) && sigo)
	{

		pos++; // Actualizar posici�n

		if (p->info == valor)
		{
			sigo = false;
			encontrado = true;
		}
		else
			p = p->sig;
	}

	return (encontrado ? (pos) : -1);
}

/***************************************************************************/
/***************************************************************************/
// Inserta un nuevo elemento en la posici�n "pos_insertar"
// PRE: 1 <= pos_insertar <= tamanio+1
// El criterio seguido para especificar una posicion ser� :
// 1 -> primero, 2 -> segundo,...
// Nota: Si pos_insertar == tamanio+1, el resultado es id�ntico a la
// 		 ejecuci�n del m�todo Aniadir()

void Lista ::Insertar(TipoBaseLista valor, int pos_insertar)
{
	TipoNodo *ant = primero;
	TipoNodo *resto = primero;

	// Crear el nodo que se va a insertar e iniciarlo
	TipoNodo *nuevo = new TipoNodo;
	nuevo->info = valor;

	// Buscar el sitio que le corresponde
	for (int i = 1; i < pos_insertar; i++)
	{
		ant = resto;
		resto = resto->sig;
	}

	if (pos_insertar == 1) // El nuevo nodo sera el primero
		primero = nuevo;
	else // Enlazar el nuevo con el anterior
		ant->sig = nuevo;

	nuevo->sig = resto; // Enlazar el nuevo nodo con el resto

	tamanio++; // Actualizar tamanio
}

/***************************************************************************/
/***************************************************************************/
// Borra el elemento de la posici�n "pos_borrar"
// PRE: 1 <= pos_borrar <= tamanio
// El criterio seguido para especificar una posicion ser� :
// 1 -> primero, 2 -> segundo,...

void Lista ::Eliminar(int pos_borrar)
{
	TipoNodo *ant = primero;
	TipoNodo *pos = primero;

	// Colocar "ant" y "act"
	for (int i = 1; i < pos_borrar; i++)
	{
		ant = pos;
		pos = pos->sig;
	}

	// "pos" apunta al nodo que se va a borrar
	// "ant" apunta al nodo anterior

	if (pos_borrar == 1) // Saltar el primero
		primero = primero->sig;
	else
		ant->sig = pos->sig;
	// Enlazar el anterior con el siguiente

	delete pos; // Borrar nodo

	tamanio--; // Actualizar tamanio
}

/***************************************************************************/
/***************************************************************************/
// M�TODOS QUE RECIBEN/DEVUELVEN LISTAS
/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
/***************************************************************************/
// Construye y devuelve sublista de lista impl�cita.
// La sublista devuelta es una copia de una parte de "original" formada
// por un m�ximo de "num_nodos" nodos, formada a partir del nodo que
// ocupa la posici�n "pos_inic" de "original".
//
// Par�metros:
//		pos_inic, posici�n de "original" a partir d ela que se va a
//			realizar la copia.
//		num_nodos, n�mero (m�ximo) de nodos a extraer.
//
// PRE: 1 <= pos_inic < NumElementos(original)
// PRE: 0 <= num_nodos
// 		Si no se cumplen, la lista devuelta es una lista vac�a.

Lista Lista ::SubLista(int pos_inic, int num_nodos)
{
	Lista sublista; // Vac�a

	// Comprobar que no sean casos erroneos (se cumplen las precondiciones)

	if (1 <= pos_inic && pos_inic <= tamanio && 0 <= num_nodos)
	{

		int pos_fin = ((pos_inic + num_nodos - 1) <= tamanio) ? pos_inic + num_nodos - 1 : tamanio;

		// N�mero de nodos de la sublista que se va a crear.
		int num_nodos_res = pos_fin - pos_inic + 1;

		// Reserva memoria para la lista resultado.
		Lista resultado(num_nodos_res);

		// Posicionar un puntero en la casilla "pos_inic" de "orig"

		TipoNodo *p_original = primero;
		for (int pos = 1; pos < pos_inic; pos++)
			p_original = p_original->sig;

		// Copia, valor a valor, desde "original" a "resultado".

		TipoNodo *p_resultado = resultado.primero;
		for (int pos = pos_inic; pos <= pos_fin; pos++)
		{

			p_resultado->info = p_original->info; // Copiar valor

			p_original = p_original->sig;	// Adelantar
			p_resultado = p_resultado->sig; // punteros
		}

		// Copiar la matriz "resultado" en "submatriz"
		sublista.Clona(resultado);

	} // if (1<=pos_inic && pos_inic<=NumElementos(original) &&  0<=num_nodos)

	return (sublista);
}

void PintaLista(const Lista &l, const char *const msg)
{
	Lista l1 = l;
	cout << l1.ToString(msg) << endl;
}

/***************************************************************************/
/***************************************************************************/
// METODOS PRIVADOS
/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
/***************************************************************************/
// Pide memoria para "num_elementos" nodos
// PRE: num_elementos > 0

void Lista ::ReservarMemoria(int num_elementos)
{
	if (num_elementos > 0)
	{

		primero = new TipoNodo; // Crear primer nodo.

		TipoNodo *ultimo = primero; // Apuntar al �ltimo.
		TipoNodo *p;

		for (int i = 1; i < num_elementos; i++)
		{

			p = new TipoNodo; // Crear un nodo.
			ultimo->sig = p;  // Enlazar el nuevo nodo.
			ultimo = p;		  // Pasa a ser el �ltimo.
		}

		ultimo->sig = 0; // Finalizar la lista

		tamanio = num_elementos;
	}
	else
	{ // Lista vac�a

		primero = 0; // MUY IMPORTANTE
		tamanio = 0;
	}
}

/***************************************************************************/
/***************************************************************************/
// Liberar memoria

void Lista ::LiberarMemoria(void)
{
	if (primero != 0)
	{

		TipoNodo *p = primero; // Colocar "p" al principio

		while (primero->sig != 0)
		{

			primero = primero->sig; // Nuevo "primero"
			delete p;				// Borrar el antiguo primero
			p = primero;			// Actualizar "p"
		}

		delete primero; // Borrar el �nico que queda

		// Lista vac�a

		primero = 0; // MUY IMPORTANTE
		tamanio = 0;
	}
}

/***************************************************************************/
/***************************************************************************/
// Copiar datos desde otro objeto de la clase
// PRE: Se ha reservado memoria para los datos

void Lista ::CopiarDatos(const Lista &otro)
{
	// Copia los campos privados

	tamanio = otro.tamanio; // Copia el n�m. de nodos

	// Copia el contenido de los nodos

	TipoNodo *p_este = primero;
	TipoNodo *p_otro = otro.primero;

	for (int i = 0; i < tamanio; i++)
	{

		// Copiar valor
		p_este->info = p_otro->info;

		// Adelantar punteros
		p_este = p_este->sig;
		p_otro = p_otro->sig;
	}
}

/***************************************************************************/
/***************************************************************************/
// M�todo PRIVADO compartido por:
// 		TipoBaseLista & Valor (int pos);
// 		TipoBaseLista & Valor (int pos) const;
// para evitar la duplicidad de c�digo.
//
// Devuelve una referencia al campo info de un nodo, dado por su posici�n.
//
// Par�metros: pos, la posici�n (n�mero de nodo) a la que se accede.
// 		El criterio seguido para especificar una posicion ser� :
// 		1 -> primero, 2 -> segundo,...

TipoBaseLista &Lista ::el_valor(int pos) const
{
	int num_elementos = tamanio;

	TipoNodo *p;
	int posic;

	for (p = primero, posic = 1; posic < pos; posic++)
		p = p->sig;

	return p->info;
}

/***********************************************************************/
/***********************************************************************/
// Consulta � modifica el valor de un nodo dado por su posici�n.
// Si se utiliza como rvalue se emplea para consulta. Si se utiliza
// como lvalue se emplea para modificaci�n.
//
// Par�metros: pos, la posici�n (n�mero de nodo) a la que se accede.
// 		El criterio seguido para especificar una posicion ser� :
// 		1 -> primero, 2 -> segundo,...
//
// PRE: 1 <= pos <= l.Tamanio()

TipoBaseLista &Lista ::Valor(int pos)
{
	return el_valor(pos);
}

TipoBaseLista &Lista ::Valor(int pos) const
{
	return el_valor(pos);
}

/***************************************************************************/
/***************************************************************************/
// M�todo para comparar dos listas. Devuelve true si las listas
// impl�cita y "otra" son exactamente iguales (dimensiones y contenidos).
// Par�metros: otra (referencia), referencia al objeto expl�cito
// Devuelve "true" i las listas impl�cita y "otra" son exactamente
// iguales (dimensiones y contenidos).

bool Lista ::EsIgualA(const Lista &otra) const
{
	int num_nodos_una = tamanio;
	int num_nodos_otra = otra.tamanio;

	bool dimensiones_iguales = (num_nodos_una == num_nodos_otra);

	bool iguales = false;

	// Si las dimensiones coinciden podemos seguir. Si no coinciden entonces
	// son diferentes (en ese caso no entra al if pero nos hemos asegurado
	// que "iguales" vale false).

	if (dimensiones_iguales)
	{

		// La comprobaci�n se har� con un ciclo while para salir cuando se
		// encuentre una discrepancia entre "una" y "otra".

		TipoNodo *p_una = primero;		 // Al primer nodo de la lista impl�cita
		TipoNodo *p_otra = otra.primero; // Al primer nodo de "otra"

		bool sigo = true;

		while (p_una && sigo)
		{

			if (p_una->info != p_otra->info)
				sigo = false;
			else
			{
				p_una = p_una->sig;	  // Adelantar
				p_otra = p_otra->sig; // punteros
			}

		} // while

		// En este punto, si "sigo" no ha cambiado de valor (inicialmente
		// true) es porque no ha encontrado diferencias, por lo que cambiamos
		// el valor de "iguales" para hacerlo true (estaba fijado a false).
		// Si "sigo" es false (se encontr� alguna diferencia) el valor de
		// "iguales" no se cambia y sigue a false.

		if (sigo)
			iguales = true;
	}

	return iguales;
}

/***************************************************************************/
/***************************************************************************/
// A�ade (al final de la lista) un nodo con el valor indicado en "valor".
//
// Par�metros:
//		valor, el valor que se a�ade a la lista

void Lista ::Aniadir(TipoBaseLista valor)
{
	// Crear un nuevo (�ltimo) nodo y rellenar sus campos
	TipoNodo *nuevo = new TipoNodo;
	nuevo->info = valor;
	nuevo->sig = 0;

	if (primero != 0)
	{ // La lista no est� vac�a

		// Buscar el �ltimo nodo
		TipoNodo *p = primero;

		for (int i = 1; i < tamanio; i++)
			p = p->sig;

		// "p" apunta al �ltimo nodo

		p->sig = nuevo;
	}
	else
	{ // La lista estaba vac�a
		primero = nuevo;
	}

	tamanio++;
}

/***************************************************************************/
/***************************************************************************/
// M�todo para hacer una copia profunda desde la lista expl�cita
// "otra" en la lista impl�cita.
// Par�metros: otra (referencia), referencia al objeto expl�cito
// El contenido de la lista impl�cita se pierde, se sustituye por una
// copia del contenido de "origen".

void Lista ::Clona(const Lista &otra)
{

	// Limpiar la lista impl�cita
	LiberarMemoria();

	int num_nodos = otra.tamanio;

	// Pedir memoria para poder recibir los datos de "origen"
	ReservarMemoria(num_nodos);

	// Copiar valor a valor

	TipoNodo *p_origen = otra.primero; // Apunta al primer nodo de "otra"
	TipoNodo *p_destino = primero;	   // Apunta al primer nodo de la lista impl�cita

	for (int pos = 1; pos <= num_nodos; pos++)
	{

		p_destino->info = p_origen->info; // Copiar valor

		p_origen = p_origen->sig;	// Adelantar
		p_destino = p_destino->sig; // punteros
	}
}

/***************************************************************************/
/***************************************************************************/
// Ecualizar una lista: cambia todos los todos valores de la lista y los
// fija todos iguales e iguales a "valor".
// Par�metros: valor, el valor com�n  que se escribir� en todos
//					los nodos (por defecto, VALOR_DEF_LISTA)

void Lista ::Ecualiza(const TipoBaseLista valor)
{
	TipoNodo *p = primero; // Apuntar al primero.

	for (int i = 0; i < tamanio; i++)
	{
		p->info = valor; // Inicializar nodo.
		p = p->sig;		 // Adelantar "p".
	}
}

/***************************************************************************/
/***************************************************************************/
// Borra el primer nodo que contiene el valor elemento de "pos"
//
// PRE: 1 <= pos <= NumElementos(l)
// El criterio seguido para especificar una posicion ser�:
// 1 -> primero, 2 -> segundo,...

void Lista ::EliminarValor(TipoBaseLista valor)
{
	int pos = Buscar(valor);

	// Si pos > 0 se encontr� el alumno buscado: eliminarlo
	if (pos > 0)
		Eliminar(pos);
}

/***************************************************************************/
/***************************************************************************/