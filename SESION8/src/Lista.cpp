/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Implementación de las funciones mínimas que gestionan listas simples.
// Versión mínima de la biblioteca.
//
// Declaraciones en Lista.h
//
// Fichero: Lista.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "Lista.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/
// DECLARACIÓN DE FUNCIONES "PRIVADAS"
/***************************************************************************/
/***************************************************************************/
// Reserva memoria para "num_nodos" nodos.
// El contenido de los nodos queda INDEFINIDO.
// Parámetros:
//  	num_nodos, número de nodos que se van a crear. 
// Devuelve: un dato Lista (una lista enlazada con "num_nodos" nodos con 
//		valor indefinido. 
//
// PRE: num_nodos >= 0 
// NOTA: Si num_nodos==0 la lista queda vacía. 

Lista ReservaMemoria (int num_nodos=0);

/***************************************************************************/
// Libera la memoria ocupada por una lista. 
// Parámetros: 
//		l (referencia), la lista que va a "liberarse". 
// POST: La lista queda vacía.

void LiberaMemoria (Lista & l);

/***************************************************************************/
/***************************************************************************/
// FIN DECLARACIÓN DE FUNCIONES "PRIVADAS"
/***************************************************************************/
/***************************************************************************/


/***************************************************************************/
/***************************************************************************/
// Crea una lista enlazada con "num_nodos" nodos. Inicializa todos los nodos 
// a un valor común, el indicado en el parámetro "valor". 
// La funcionalidad sería similar a la de un constructor.
// Parámetros:
//  	num_nodos, número de nodos que se van a crear. 
//		valor, valor común que se copiará en las casillas. 
// Devuelve: un dato de tipo Lista.
//
// PRE: num_nodos >= 0 
// NOTA: Si num_nodos==0 la lista queda vacía. 

Lista CreaLista (int num_nodos, TipoBase valor)
{
	Lista l = ReservaMemoria (num_nodos); 

	if (num_nodos > 0) {

		PNodo p = l; // "p" apunta al primer nodo

		// Rellenar todos los nodos con "valor" 

		for (int i=0; i<num_nodos; i++) {

			p->info = valor; 
			p = p->sig; // Avanzar "p"
		}
	}

	return l; 
}


Lista CreaListaAleatoria(int num_valores, int min_aleat, int max_aleat)
{
	if(num_valores==0 or num_valores<0)
		exit(1);

	GeneradorAleatorioEnteros generador(min_aleat, max_aleat);

	Lista l = ReservaMemoria (num_valores);

	if (num_valores > 0) {

		PNodo p = l; // "p" apunta al primer nodo

		// Rellenar todos los nodos con "valor" 
		int valor;

		for (int i=0; i<num_valores; i++) {
			valor = generador.Siguiente();
			p->info = valor; 
			p = p->sig; // Avanzar "p"
		}
	}

	return l;

};

/***************************************************************************/
/***************************************************************************/
// "Destruye" una lista y la deja en un estado no útil (vacía). 
// La funcionalidad sería similar a la de un destructor.
// Parámetros: 
//		l (referencia), la lista que va a "destruirse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void DestruyeLista (Lista & l)
{
  	LiberaMemoria (l); 
}

/***************************************************************************/
/***************************************************************************/
//Ecualizar. Cambia todos los valores de la lista l y los fija todos iguales
//e iguales a valor.
void Ecualiza(Lista & l, TipoBase valor)
{
	PNodo p = l; // "p" apunta al primer nodo

	// Rellenar todos los nodos con "valor" 

	for (int i=0; i<NumElementos(l); i++) {

		p->info = valor; 
		p = p->sig; // Avanzar "p"
	}
}

/***************************************************************************/
/***************************************************************************/
// Devuelve el número de nodos de una lista
// Parámetros: 
//		l (referencia), la lista que va a procesar. 
// Devuelve: número de nodos de la lista

int NumElementos (const Lista & l)
{
	int contador = 0; 

	for (PNodo p=l; p!=0; contador++, p=p->sig);

	return contador;
}

/***************************************************************************/
/***************************************************************************/
// Consulta si una lista está vacía (sin nodos)
// Parámetros: 
//		l (referencia), la lista que va a procesarse. 
// Devuelve: true, si la lista está vacía
   
bool EstaVacia (const Lista & l)
{
	return (l==0);	
}
 
/***************************************************************************/
/***************************************************************************/
// Devuelve un string con el resultado de ``serializar'' una lista.
// Parámetros: 
//		l (referencia), la lista que va a procesar. 

string ToString (const Lista & l)
{
	int num_elementos = NumElementos(l);
	string cad; 
	cad = cad + "Num. nodos = " + to_string(num_elementos) + "\n";

	if (num_elementos > 0)  {

		cad = cad + "Valores almacenados en la lista: \n"; 
		cad = cad + "{ ";

		PNodo p; 
		int pos = 1;

		for (p=l, pos=1; pos<num_elementos; pos++, p=p->sig)
			cad = cad + to_string(p->info) + ", "; 
		
		cad = cad + to_string(p->info) + "}"; // Último nodo 
	}
	else 
		cad = cad + "Lista vacia";

	cad = cad + "\n\n";

	return cad;
}

/***************************************************************************/
/***************************************************************************/
// Consulta ó modifica el valor de un nodo dado por su posición. 
// Si se utiliza como rvalue se emplea para consulta. Si se utiliza como 
// lvalue se emplea para modificación.
//
// Parámetros: 
//		l (referencia), la lista que va a consultar/modificar. 
//		pos, posición de la lista a la que se accede.
//
// PRE: 1 <= pos <= NumElementos (l)

TipoBase & Valor (const Lista & l, int pos)
{
	int num_elementos = NumElementos(l);

	PNodo p = l; 
	for (int posic=1; posic<pos; posic++) p=p->sig;

	return p->info; 
}

/***************************************************************************/
/***************************************************************************/
// Elimina todos los valores. 
// Al finalizar, NumElementos(l)==0 EstaVacia(l)==true. 
// La lista, aunque vacía, sigue ``activa''.

void  EliminaTodos (Lista & l)
{
	LiberaMemoria (l); 
}

/***************************************************************************/
/***************************************************************************/
// Añade (al final de la lista) un nodo con el valor indicado en "valor". 
//
// Parámetros:
// 		l (referencia), lista resultante.
//		valor, el valor que se añade a la lista "l"

void Aniade (Lista & l, TipoBase valor)
{
	// Crear un nodo (será el último) y rellenarlo
	PNodo p_nodo_nuevo = new Nodo; 
	p_nodo_nuevo->info = valor; 	 
	p_nodo_nuevo->sig  = 0; 
 
	// Buscar el último nodo de la lista

	PNodo p = l; 

	if (l) { // lista no vacía 

		while (p->sig) p = p->sig; // Avanzar hasta llegar al último nodo
		p->sig = p_nodo_nuevo; 

	}
	else { // Lista vacía: el nuevo nodo será el primero

		l = p_nodo_nuevo; 
	}
}

/***************************************************************************/
/***************************************************************************/
//Copia profunda. Hace una copia profunda de origen en destino.

void Clona(Lista & destino, const Lista & origen)
{
	LiberaMemoria(destino);
	destino = ReservaMemoria(NumElementos(origen));

	for (PNodo p=origen, q=destino; p!=0; p=p->sig, q=q->sig)
		q->info = p->info;
}

/***************************************************************************/
/***************************************************************************/
//Comparación. Devuelve true si las listas una y otra son exactamente 
//iguales (dimensiones y contenidos).

bool SonIguales (const Lista & una, const Lista & otra){
	
	if (NumElementos(una) != NumElementos(otra)) return false;

	for (PNodo p=una, q=otra; p!=0; p=p->sig, q=q->sig)
		if (p->info != q->info) return false;

	return true;

}

/***************************************************************************/
/***************************************************************************/
//Sublista. Extrae una lista de original y la deja en resultado. La
//lista resultado es una copia de una parte de original formada por
//un máximo de num_nodos nodos, formada a partir del nodo que ocupa
//la posición pos_inic de original.
//Considere todos los posibles casos entre num_nodos, pos_inic y el
//número de nodos de original y resuélvalos de la mejor manera posi-
//ble. Por ejemplo,
//• Si la lista original tiene 5 nodos, y le pedimos una sublista de 8 nodos
//desde la posición 3 sólo disponemos de tres (posiciones 3, 4 y 5). La
//función construirá y rellenará una lista de 3 nodos.
//• Sobre la misma lista, si pedimos una sublista de 6 nodos desde la
//posición 8, no podremos porque la posición inicial no está dentro de
//la lista. La función construirá y “rellenará” una lista vacía. Lo mismo
//ocurre si la posición inicial fuera, por ejemplo,-1.

void SubLista (Lista & resultado, const Lista & original,
int pos_inic, int num_nodos){
	
	if(pos_inic<0 or pos_inic+num_nodos>NumElementos(original) or 
	num_nodos<=0)
		exit(1);

	LiberaMemoria(resultado);
	resultado = ReservaMemoria(num_nodos);

	PNodo p = original;
	for(int i=0; i<pos_inic; i++,p=p->sig);

	PNodo q = resultado;
	for(int i=0; i<num_nodos; i++,p=p->sig,q=q->sig)
		q->info = p->info;
}

/***************************************************************************/
/***************************************************************************/



/***************************************************************************/
/***************************************************************************/
//
// FUNCIONES DE ORDENACIÓN
//
/***************************************************************************/
/***************************************************************************/
// Comprueba si una lista está ordenada.
// Parámetros: 
//	l (referencia) lista a comprobar
// Devuelve: true, si la lista está ordenada

bool EstaOrdenada (const Lista l)
{
	PNodo p = l; 
	TipoBase anterior; 

	if (p) { // si hay al menos un nodo
		anterior = p->info; //  valor del primer nodo
		p = p->sig;		    //  apuntar al segundo
	}
	
	bool ordenada = true; // por defecto, una lista vacia esta ordenada

	while (p && ordenada) {
		
		if (p->info >= anterior) {
			anterior = p->info;
			p = p->sig;			 //  apuntar al segundo
		}
		else ordenada = false; 
	}
	
	return (ordenada);
}

/***************************************************************************/
/***************************************************************************/
// Ordena una lista (algoritmo de seleccion).
// Parámetros: 
//	l (referencia) lista a ordenar.

void OrdenaSeleccion (Lista & l)
{
	if (l) { // Lista no vacía --> si la lista esta vacia, no se hace nada

		PNodo primero = l; // marca el inicio de la parte NO ordenada
		
		while (primero->sig != 0) {

			// El primer menor es el primer elemento de la parte no ordenada

			TipoBase val_min = primero->info; 
			PNodo    pos_min = primero;           

			// Para buscar el menor de la parte no ordenada

			PNodo p = primero->sig;  

			while (p!=0) {

				if (p->info < val_min) {   // se encuentra un nuevo menor
					val_min = p->info;
					pos_min = p;
				}
				p = p->sig;  // se sigue avanzando
			}

			// Intercambio: el menor pasa a ocupar la posicion marcada 
			// por el puntero "primero"
			  
			//TipoBase tmp = primero->info; 
			//primero->info = pos_min->info;
			//pos_min->info = tmp; 

			Intercambia(primero, pos_min); // intercambia los nodos

			primero = primero->sig; // avanza la parte no ordenada
		
		} // while (primero->sig != 0)
		
	} // if (l!=0)
	
}

void OrdenaInsercion(Lista & l)
{
	if (l) { // Lista no vacía --> si la lista esta vacia, no se hace nada

		PNodo p = l; 
		PNodo q = p->sig; 

		for(int izda=1; izda<NumElementos(l); izda++){
			TipoBase valor = Valor(l,izda);

			int i=izda;
			while(i>0 and valor<Valor(l,i-1)){
				Valor(l,i)=Valor(l,i-1);
				i--;
			}
			Valor(l,i)=valor;
		}
		
	}
}

void OrdenaIntercambio(Lista & l)
{
	for (int izda = 0; izda < NumElementos(l); izda++)

		for (int i = NumElementos(l)-1 ; i > izda; i--)

			if (Valor(l,i) < Valor(l, i-1) ) // Intercambiar 

				Intercambia(l, i, i-1);
}

void OrdenaIntercambioMejorado(Lista & l)
{
	bool cambio = true; // Para entrar

	int izda = 0; 

	int tamanio=NumElementos(l);

	while (izda < tamanio && cambio) {

		// En cada pasada iniciamos "cambio" a false. 
		// Se pondrá true si y solo si hay algún intercambio

		cambio = false;

		for (int i = tamanio-1; i > izda; i--)

			if (Valor(l,i) < Valor(l,i-1)) { // Intercambiar 

				Intercambia (l, i , i-1);

				cambio = true; // Se ha hecho un intercambio
			}

		izda++;
	}
}

/***************************************************************************/
/***************************************************************************/
//Cambia todos los valores de una lista existente con numeros aleatorios
//comprendidos entre los valores indicados.

void RellenaAleatoriamente(Lista & l, int minimo_aleatorio , 
int max_aleatorio)
{
	if(l)
	{
		GeneradorAleatorioEnteros generador(minimo_aleatorio, max_aleatorio);
		PNodo p = l;
		while(p)
		{
			p->info = generador.Siguiente();
			p = p->sig;
		}
	}
	
};

/***************************************************************************/
/***************************************************************************/
//Eliminar. Elimina el nodo que ocupa la posición pos.

void Elimina (Lista & l, int pos)
{
	if(l && pos>0 && pos<=NumElementos(l))
	{
		PNodo p = l;
		if(pos==1){
			p = p->sig;   // Adelantar "p"
            delete l;     // Borrar el primero
            l = p;        // Actualizar "l"
		}else{ 
			for (int posic=1; posic<pos-1; posic++) p=p->sig;
			PNodo q = p->sig;
			p->sig = q->sig;
			delete q;
		}
		
	}
}

/***************************************************************************/
/***************************************************************************/
//Insertar. Inserta en la posición pos un nodo con el valor indicado en valor.
//El nuevo nodo ocupará la posición pos.

void Inserta (Lista & l, TipoBase valor, int pos){

	if(l && pos>0 && pos<=NumElementos(l)){

		PNodo p_nodo_nuevo = new Nodo; 
		p_nodo_nuevo->info = valor; 	 
		p_nodo_nuevo->sig  = 0; 

		PNodo p = l;
		if(pos==1){
			p_nodo_nuevo->sig = p;
			l = p_nodo_nuevo;
		}
		else{
			for(int i=1; i<pos-1; i++)
				p = p->sig;
			p_nodo_nuevo->sig = p->sig;
			p->sig = p_nodo_nuevo;
		}
	}
}

/***************************************************************************/
/***************************************************************************/
//Invertir lista

void InvertirLista (Lista & l){
	if(l){
		int num_elementos = NumElementos(l);
		int inicio=1;
		int fin=num_elementos;
		while(inicio<fin){
			Intercambia(l, inicio, fin);
			inicio++;
			fin--;
		}
	}
}

/***************************************************************************/
/***************************************************************************/
//Funcion para insertar un nuevo dato en su posición correcta. En
//el caso que la lista ya tuviera ese valor, se insertará el nuevo delante de
//la primera aparición.

void InsertaValorListaOrdenada (Lista & l, TipoBase v){
	if(l){
		PNodo p = l;
		PNodo anterior = l;

		PNodo p_nodo_nuevo = new Nodo;
		p_nodo_nuevo->info = v;

		bool continua=true;

		//Colocamos p donde se tiene que insertar
		while(continua){
			if(p){
				if(p->info < v){
					anterior = p;
					p = p->sig;
			}else{
				continua=false;
			}
			}else{
				continua=false;
			}
		}

		//Si es el primero de la lista
		if(p==l){
			p_nodo_nuevo->sig = l;
			l = p_nodo_nuevo;
		}
		else{
			anterior->sig = p_nodo_nuevo;

			if(p) p_nodo_nuevo->sig = p;
			else p_nodo_nuevo->sig = 0;
		}
		
	}
}

void EliminaValorListaOrdenada (Lista &l, TipoBase v){
	if(l){
		PNodo p = l;
		PNodo anterior = l;

		//Avanzo hasta la posición del valor que quiero eliminar
		while( (p->sig) and (p->info < v) ){
			anterior = p;
			p = p->sig;
		}

		if(p->info == v){
			if(p==l){
				//Si es el primero de la lista lo elimino y actualizo l
				l = l->sig;
				delete p;
			}else{
				//Si no es el primero lo elimino y actualizo el anterior para 
				//que apunte al siguiente
				anterior->sig = p->sig;
				delete p;
			}
		}
	}
};

int PosicionListaOrdenada (const Lista &l, TipoBase v){
   int num_nodos = NumElementos(l);
   bool encontrado = false;
   bool sigo_buscando = true;

   PNodo p = l;
   PNodo anterior = l;

   int pos_actual = 1;

   while(p && sigo_buscando){
      if(p->info == v){
         encontrado = true;
         sigo_buscando = false;
      }
      else{
         if(p->info < v){
            p = p->sig;
            pos_actual++;
         }
         else{
            sigo_buscando=false;
         }
      }
   }

   return (encontrado)? pos_actual : -1;
}

void MezclaListasClasico (Lista &l,
const Lista &l1, const Lista &l2){
	PNodo p1 = l1;
    PNodo p2 = l2;

	LiberaMemoria(l);

	while(p1 && p2){
		//Mientras no sea el final de las dos listas
		if(p1->info <= p2->info){
			Aniade (l, p1->info);
			p1 = p1->sig;
		}
		else{
			Aniade(l, p2->info);
			p2 = p2->sig;
		}
	}

	while(p1){
		Aniade(l, p1->info);
		p1 = p1->sig;
	}
	
	while(p2){
		Aniade(l, p2->info);
		p2 = p2->sig;
		
	}

}

void MezclaListas (Lista &l, Lista &l1, Lista &l2){
	PNodo p1 = l1;
	PNodo p2 = l2;


	//Primer nodo de la lista
	if(p1->info <= p2->info){
		l=p1;
		p1 = p1->sig;
	}
	else{
		l=p2;
		p2 = p2->sig;
	}

	PNodo p_nuevo = l;

	while(p1 && p2){
		if(p1->info < p2->info){
			p_nuevo->sig = p1;
			p1 = p1->sig;
			p_nuevo = p_nuevo->sig;
		}
		else{
			p_nuevo->sig = p2;
			p2 = p2->sig;
			p_nuevo = p_nuevo->sig;
		}
	}


	if(p1) p_nuevo->sig = p1;
	if(p2) p_nuevo->sig = p2;

	l1=0;
	l2=0;
}

void Intercambia(Lista &l, int pos1, int pos2)
{
	if(l && pos1>0 && pos1<=NumElementos(l) && pos2>0 && pos2<=NumElementos(l)){
		PNodo p1 = l;
		for(int i=1; i<pos1; i++)
			p1 = p1->sig;
		PNodo p2 = l;
		for(int i=1; i<pos2; i++)
			p2 = p2->sig;
		TipoBase tmp = p1->info;
		p1->info = p2->info;
		p2->info = tmp;
	}	
}

void Intercambia(Nodo * & a, Nodo * & b){
	TipoBase tmp = a->info; 
	a->info = b->info;
	b->info = tmp; 
};
/***************************************************************************/
/***************************************************************************/



/***************************************************************************/
/***************************************************************************/
//
// FUNCIONES "PRIVADAS"
//
/***************************************************************************/
/***************************************************************************/
// Reserva memoria para "num_nodos" nodos.
// El contenido de los nodos queda INDEFINIDO.
// Parámetros:
//  	num_nodos, número de nodos que se van a crear. 
// Devuelve: un dato Lista (una lista enlazada con "num_nodos" nodos con 
//		valor indefinido. 
//
// PRE: num_nodos >= 0 
// NOTA: Si num_nodos==0 la lista queda vacía. 

Lista ReservaMemoria (int num_nodos)
{
	Lista l = 0; // Lista vacía 

	if (num_nodos > 0) {

		l = new Nodo;  // Pedir memoria para el primer nodo 

		PNodo p = l; // "p" apunta al primer nodo

		// Pedir memoria para el resto de los nodos 

		for (int i=1; i<num_nodos; i++) {

			p->sig = new Nodo;  // Pedir memoria para un nuevo nodo 
			p = p->sig; // Avanzar "p"
		}

		p->sig = 0;
	}

	return l; 
}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por una lista. 
// Parámetros: 
//		l (referencia), la lista que va a "liberarse". 
// POST: La lista queda vacía.

void LiberaMemoria (Lista & l)
{
 	if (l != 0) { // Importante: prevenir de la lista vacía

        PNodo p = l; // Colocar "p" al principio

        while (p->sig != 0) {
            p = p->sig;   // Adelantar "p"
            delete l;     // Borrar el primero
            l = p;        // Actualizar "l"
        }
        
        delete l; // Borrar el único nodo que queda
    }

    l = 0; // El puntero que da acceso a la lista queda con valor 0
}

/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
/***************************************************************************/
// FIN FUNCIONES "PRIVADAS"
/***************************************************************************/
/***************************************************************************/

