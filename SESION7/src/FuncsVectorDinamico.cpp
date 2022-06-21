/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// RELACION DE PROBLEMAS 2
//
// Implementaci�n de las funciones de gesti�n del tipo "VectorDinamico".
// Declaraciones en FuncsVectorDinamico.h
//
// Versi�n completa.
//  
// Fichero: FuncsVectorDinamico.cpp
//
/***************************************************************************/
/***************************************************************************/

//#define DEBUG_FUNCS_VECTOR_DINAMICO

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>

#include "TipoBaseVector.h"
#include "FuncsVectorDinamico.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/
// Crear vector din�mico
// Par�metros: capacidad_inicial, n�mero de casillas con las que se crea el vector.
// 		   tipo, el tipo de redimensi�n que se va a aplicar. 
// Devuelve: el vector din�mico creado.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es "capacidad_inicial"
//       El n�mero tipo de redimensi�n es "tipo"

VectorDinamico CreaVectorDinamico (int capacidad_inicial, 
 					 			   TipoRedimension tipo)
{
	VectorDinamico nuevo;

	// Pedir memoria para el nuevo almacen 
	nuevo.datos = new TipoBaseVector[capacidad_inicial]; 

	// Iniciar capacidad y ocupaci�n
	nuevo.capacidad = capacidad_inicial;
	nuevo.usados = 0;

	// Iniciar tipo de redimensi�n
	nuevo.tipo_redimension = tipo;

	return (nuevo);
}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector din�mico
// Par�metros: v (referencia) El vector que se va liberar.
// POST: El n�mero de casillas usadas es 0
//       El n�mero de casillas reservadas es 0

void LiberaVectorDinamico (VectorDinamico & v) 
{
	if (v.datos)
		delete [] v.datos;

	// Modificar las propiedades de "v" para que quede "vac�o"
	v.datos = 0; // Puntero "nulo"
	
	v.usados = 0;
	v.capacidad = 0;
}

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas usadas de un vector din�mico.
// Par�metros: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas usadas de un vector din�mico

int  UsadosVectorDinamico (const VectorDinamico v) 
{
	return (v.usados);
}	

/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas reservadas de un vector din�mico.
// Par�metros: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas reservadas de un vector din�mico

 int CapacidadVectorDinamico (const VectorDinamico v) 
{
	return (v.capacidad);
}	

/***************************************************************************/
/***************************************************************************/
// Deja el vector din�mico vac�o
// Par�metros: v (referencia) El vector que se va "vaciar"
// POST: El n�mero de casillas usadas es 0

void EliminaTodosVectorDinamico (VectorDinamico & v) 
{
	v.usados = 0;
}

/***************************************************************************/
/***************************************************************************/
// Inicializa el vector din�mico copiando en todas las casillas "valor" 
// Par�metros: 	v (referencia) El vector que se va inicializar
//				valor, el valor que se va a copiar en todas las casillas.

void EcualizaVectorDinamico (VectorDinamico & v, const TipoBaseVector valor)
{
	for (int i=0; i<v.usados; i++) 
		v.datos[i] =  valor;
}

/***************************************************************************/
/***************************************************************************/
// Copia profunda. Hace una copia profunda de "origen" en "destino".
// Par�metros: destino (referencia), el vector que recibe la copia. 
//             origen (referencia), el vector del que se hace la copia. 

void Clona (VectorDinamico & destino, const VectorDinamico & origen)
{
	LiberaVectorDinamico (destino);

	destino.capacidad = origen.capacidad; 
	destino.usados = origen.usados;
	destino.tipo_redimension = origen.tipo_redimension;

	// Pedir memoria para el nuevo almacen la copia
	destino.datos = new TipoBaseVector[origen.capacidad]; 

	// Copiar los valores 
	memcpy (destino.datos, origen.datos, destino.usados*sizeof(TipoBaseVector));
}

/***************************************************************************/
/***************************************************************************/
// Serializa un dato de tipo "VectorDinamico"
// Par�metros: v, el vector que se va a serializar.

string ToString (const VectorDinamico v)
{
	string cad; 
	cad = cad + "Capacidad = " + to_string(v.capacidad); 
	cad = cad + "  Ocupadas  = " + to_string(v.usados) + "\n";

	if (v.usados > 0)  {

		cad = cad + "Valores almacenados en el vector: \n"; 

		cad = cad + "[ ";

		for (int i=0; i<v.usados-1; i++) 
			//cad = cad + to_string(ValorVectorDinamico (v, i)) + ", "; 

		//cad = cad + to_string(ValorVectorDinamico (v, v.usados-1)); 
		cad = cad + " ]";
	}
	else 
		cad = cad + "Vector vacio";

	cad = cad + "\n\n";

	return (cad);
}

/***************************************************************************/
/***************************************************************************/
// A�ade un valor al vector din�mico
// Par�metros: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a a�adir al vector. 
// NOTA: Si no hay espacio libre, la funci�n pide espacio adicional usando 
//		 la funci�n RedimensionaVectorDinamico. 

void AniadeVectorDinamico (VectorDinamico &v, const TipoBaseVector valor)
{
	// Si no cabe --> redimensionar

	if (v.usados == v.capacidad) {

		// Redimensionar 
		RedimensionaVectorDinamico (v);
	}

	// Se haya redimensionado o no, en este punto hay sitio para la inserci�n

	v.datos[v.usados] = valor;
	v.usados++;
}

/***************************************************************************/
/***************************************************************************/
// Consulta � modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consultar el valor de la casilla "num_casilla". 
// Si se utiliza como lvalue se emplea para modificar el valor de la 
// casilla num_"casilla".
// 
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

 TipoBaseVector & ValorVectorDinamico (const VectorDinamico v, int num_casilla) 
{
	return (v.datos[num_casilla]);
}	

/***************************************************************************/
/***************************************************************************/
// Inserci�n. Inserta un valor en una posici�n dada. Los valores que est�n 
// desde esa posici�n (incluida) hasta la �ltima se �desplazan� una posici�n 
// hacia �ndices mayores.
// Si el vector din�mico estuviera lleno se tiene que redimensionar (de 
// acuerdo al tipo de redimensi�n establecido) para poder acoger a "valor". 

void InsertaVectorDinamico (VectorDinamico & v, const TipoBaseVector valor, 
	                        const int num_casilla)
{
	// Si no cabe --> redimensionar

	if (v.usados == v.capacidad) {

		// Redimensionar 
		RedimensionaVectorDinamico (v);
	}

	// Desplazar los valores de las casillas "num_casilla", "num_casilla"+1, 
	// ... "usados" una posici�n (hacia posiciones mayores)  
    TipoBaseVector * pos_inic_bloque = &v.datos[num_casilla];
    memmove (pos_inic_bloque+1, pos_inic_bloque, 
                          (v.usados-num_casilla)*sizeof(TipoBaseVector)); 

	*pos_inic_bloque = valor; // Escribir "valor" en la casilla "num_casilla"
	(v.usados)++; // Actualizar "usados"
}

/***************************************************************************/
/***************************************************************************/
// Borrado. Elimina un valor en una posici�n dada. Los valores que est�n 
// desde la posici�n siguiente a la dada hasta la �ltima se �desplazan� una 
// posici�n hacia �ndices menores. 
//
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

void EliminaVectorDinamico (VectorDinamico & v, const int num_casilla)
{
    if ((num_casilla >= 0) && (num_casilla < v.usados)) {

		// Desplazar los valores de las casillas "num_casilla+1", 
		// "num_casilla"+2,..."usados" una posici�n (hacia posiciones menores)  
        TipoBaseVector * pos_inic_bloque = &(v.datos[num_casilla+1]);
        memmove (pos_inic_bloque-1, pos_inic_bloque, 
                              (v.usados-num_casilla-1)*sizeof(TipoBaseVector)); 
		(v.usados)--; // Actualizar "usados"
    }
}

/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector din�mico "v" de acuerdo al tipo de redimensi�n 
// registrado en "v". 
// Adem�s, copia todos los datos en el nuevo vector.  
// Par�metros: 	
//		v (referencia), referencia al vector que se va a redimensionar. 
			
void  RedimensionaVectorDinamico (VectorDinamico & v)
{
	int nueva_capacidad;
	
    switch (v.tipo_redimension) {

        case (TipoRedimension::DeUnoEnUno): // 1 casilla m�s
            nueva_capacidad = v.capacidad+1;
            break;

        case (TipoRedimension::EnBloques): // TAM_BLOQUE casillas m�s
            nueva_capacidad = v.capacidad+TAM_BLOQUE;
            break;

        case (TipoRedimension::Duplicando): // Duplicar tama�o
            nueva_capacidad = v.capacidad*2;
            break;
    }

    #ifdef DEBUG_FUNCS_VECTOR_DINAMICO
	cout << endl;
	cout << "REDIMENSIONADO HASTA --> "<<nueva_capacidad << " CASILLAS"<< endl;
	cout << endl;
	#endif

	// Pedir memoria para el nuevo almacen 
	TipoBaseVector * tmp = new TipoBaseVector[nueva_capacidad]; 

	// Copiar los datos 
	for (int i=0; i<v.usados; i++) 
		tmp[i] = v.datos[i]; 
		
	// Considerar esta copia eficiente:
	// memcpy (tmp, v.datos, v.usados*sizeof(TipoBaseVector)); 
	
	// Liberar la memoria del antiguo almac�n
	delete [] v.datos; 

	// Actualizar vector din�mico redimensionado

	v.datos = tmp;
	v.capacidad = nueva_capacidad;
	// v.usados se mantiene como estaba
}

/***************************************************************************/
/***************************************************************************/
// Redimensiona un vector din�mico para que no haya espacio libre.
// Copia todos los datos en el nuevo vector.
// Par�metros: 	
//		v (referencia), referencia al vector que se va a reajustar. 
// POST: capacidad = usados

void  ReajustaVectorDinamico (VectorDinamico & v)
{
	int nueva_capacidad = v.usados;

	cout << endl;
	cout << "REAJUSTANDO HASTA --> "<<nueva_capacidad << " CASILLAS"<< endl;
	cout << endl;

	// Pedir memoria para el nuevo almacen 
	TipoBaseVector * tmp = new TipoBaseVector[nueva_capacidad]; 

	// Copiar los datos 
	for (int i=0; i<v.usados; i++) 
		tmp[i] = v.datos[i]; 
		
	// Considerar esta copia eficiente:
	// memcpy (tmp, v.datos, v.usados*sizeof(TipoBaseVector)); 
	
	// Liberar la memoria del antiguo almac�n
	delete [] v.datos; 

	// Actualizar vector din�mico redimensionado

	v.datos = tmp;
	v.capacidad = nueva_capacidad;
	// v.usados se mantiene como estaba
}

/***************************************************************************/
/***************************************************************************/
// Transforma "valor_cad" a TipoBaseVector

TipoBaseVector TransformaATipoBaseVector (char * valor_cad)
{
	TipoBaseVector el_valor; 

	#ifdef INT
	el_valor = atoi(valor_cad);
	#else 
		#ifdef DOUBLE
		el_valor = atof(valor_cad);
		#else 
			#ifdef CHAR
			el_valor = valor_cad[0];
			#endif
		#endif
	#endif

	return (el_valor);
}

/***************************************************************************/
/***************************************************************************/
// Muestra el tipo de redimensionamiento que se emplear�
// Recibe: el valor del tipo enumerado asociado al tipo de redimensi�n.
	
void MuestraTipoRedimension (TipoRedimension tipo)
{
	cout << endl;
	cout << "TIPO DE REDIMENSION --> ";

	switch (tipo) { 
	
		case (TipoRedimension::DeUnoEnUno):	
					cout << "de uno en uno";
					break;
		case (TipoRedimension::EnBloques):	
					cout << "en bloques";
					break;
		case (TipoRedimension::Duplicando):	
					cout << "duplicando";
					break; 
	}
	cout << endl << endl;
}

/***************************************************************************/
/***************************************************************************/
// Lee y devuelve el tipo de redimensionamiento que se emplear�.
// Devuelve: el valor del tipo enumerado apropiado al valor leido.

TipoRedimension LeeTipoRedimension (void)
{
	TipoRedimension tipo; 
	int opcion; 

	do {
		cout << "Introducir tipo de redimensionamiento:"<< endl;
		cout << "   1.- De uno en uno" << endl;
		cout << "   2.- En bloques de tamano " << TAM_BLOQUE << endl;
		cout << "   3.- Duplicando" << endl;
		cout << "Opcion: "; 
		cin >> opcion;
	}
	while ((opcion <1) || (opcion > 3));

	switch (opcion) { 
		case (1):	tipo = TipoRedimension::DeUnoEnUno;
					break;
		case (2):	tipo = TipoRedimension::EnBloques;
					break;
		case (3):	tipo = TipoRedimension::Duplicando;
					break; 
	}
	return (tipo); 
}

/***************************************************************************/
/***************************************************************************/
// Ordena el vector din�mico v y devuelve un nuevo vector din�mico que 
// contiene los datos de v ordenados.  
// Los datos resultantes est�n en orden creciente (por defecto). 
// Si desea un orden decreciente deber� indicarlo de manera expl�cita 
// escribiendo como segundo argumento no, NO, No � incluso nO.
//
// POST: El vector v no se modifica. 
/*
VectorDinamico ObtenerCopiaVectorDinamicoOrdenado (const VectorDinamico & v, 
	                                               const char * creciente)
{
	// Creqar e inicializar el vector din�mico resultado

	VectorDinamico tmp = CreaVectorDinamico();

	Clona (tmp, v); 

	OrdenaVectorDinamico (tmp, creciente); 

	return (tmp);
}
*/
/***************************************************************************/
/***************************************************************************/
// Ordena el vector din�mico v, modific�ndose su contenido (la ordenaci�n se 
// hace sobre el propio vector v). El segundo argumento sigue las mismas 
// normas que la versi�n anterior.
//
// POST: El contenido original de "v" se pierde (se sustituye por los mismos 
//       valores, pero ordenados)
/*
void OrdenaVectorDinamico (VectorDinamico & v, const char * creciente)
{
	// Analizar segundo argumento

	char si_no[3];

	if (strlen(creciente) != 2) 
	
		strcpy(si_no, "SI"); 
	
	else { // "creciente" tiene longitud 2
		
		// Pasar a may�culas "creciente"

		si_no[0]=toupper(creciente[0]);
		si_no[1]=toupper(creciente[1]);
		si_no[2]= '\0';
	}
	
	// Comparar el valor de "creciente" con "NO"

	if (!strcmp(si_no, "NO")) { // Decreciente

		OrdenaVectorDinamicoDecreciente (v);
	}
	else { // Creciente

		OrdenaVectorDinamicoCreciente (v); 
	}
}
/
/***************************************************************************/
/***************************************************************************/
// Ordena (sentido creciente) el vector din�mico v. 
// Se modifica su contenido (la ordenaci�n se hace sobre el propio vector v). 
// Par�etros:
//		v (referencia), referencia al vector din�mico que se ordena. 

/*
void OrdenaVectorDinamicoCreciente (VectorDinamico & v)
{
	for (int izda = 0; izda < v.usados; izda++) {

		// Calcular el m�nimo entre "izda" y "total_utilizados"-1

		int minimo = v.datos[izda]; // Valor del m�nimo
		int pos_min = izda;   // Posici�n del m�nimo

		for (int i = izda + 1; i < v.usados; i++)

			if (v.datos[i] < minimo){ // Nuevo m�nimo
			    minimo = v.datos[i];
			    pos_min = i;
			 }

		// Intercambiar los valores guardados en "izda" y "pos_min"  

		Intercambia (v.datos[izda], v.datos[pos_min]);
   }
}
/
/***************************************************************************/
/***************************************************************************/
// Ordena (sentido creciente) el vector din�mico v. 
// Se modifica su contenido (la ordenaci�n se hace sobre el propio vector v). 
// Par�etros:
//		v (referencia), referencia al vector din�mico que se ordena. 

/*
void OrdenaVectorDinamicoDecreciente (VectorDinamico & v)
{
	for (int izda = 0; izda < v.usados; izda++) {

		// Calcular el m�ximo entre "izda" y "total_utilizados"-1

		int maximo = v.datos[izda]; // Valor del m�ximo
		int pos_max= izda;   // Posici�n del m�ximo

		for (int i = izda + 1; i < v.usados; i++)

			if (v.datos[i] > maximo){ // Nuevo m�ximo
			    maximo = v.datos[i];
			    pos_max = i;
			 }

		// Intercambiar los valores guardados en "izda" y "pos_min"  

		Intercambia (v.datos[izda], v.datos[pos_max]);
   }
}
*/
/***************************************************************************/
/***************************************************************************/
// Mezcla dos vectores din�micos ordenados y devuelve un nuevo vector 
// din�mico con el resultado de la mezcla. 
// La mezcla puede ser selectiva (sin valores repetidos) -por defecto- o no 
// (sin valores repetidos, solo se selecciona uno).  
// Par�metros: 	
//		v1 (referencia), referencia al primer vector din�mico. 
//		v2 (referencia), referencia al segundo vector din�mico. 
//      selectiva (referencia, par�metro OPCIONAL). Si su valor es "si", "SI", 
//             "Si" � "sI" la mezcla ser� selectiva (sin valores repetidos). 
//              La mezcla ser� completa (puede tener valores repetidos) si se 
//              llama con cualquier otro valor (o ninguno).
//
// PRE: "v1" y "v2" est�n ordenados
// POST: Los vectores v1 y v2 NO se modifican.

/*
VectorDinamico ObtenerCopiaMezclaVectoresDinamicos (const VectorDinamico & v1, 
                            const VectorDinamico & v2, const char * selectiva)
{
	VectorDinamico mezcla = CreaVectorDinamico();

	MezclaVectoresDinamicos (mezcla, v1, v2, selectiva); 

	return (mezcla);
}
*/
/***************************************************************************/
/***************************************************************************/
// Mezcla dos vectores din�micos ordenados y devuelve el resultado de la 
// mezcla en otro vector din�mico que ya existe. 
// La mezcla puede ser selectiva (sin valores repetidos, solo se selecciona 
// uno de ellos) o no selectiva -por defecto- (puede contener repetidos).  
// Par�metros: 	
//		mezcla (referencia), referencia al vector din�mico con el resultado. 
//		v1 (referencia), referencia al primer vector din�mico que se mezcla. 
//		v2 (referencia), referencia al segundo vector din�mico que se mezcla.  
//      selectiva (referencia, par�metro OPCIONAL). Si su valor es "si", "SI", 
//             "Si" � "sI" la mezcla ser� selectiva (sin valores repetidos). 
//              La mezcla ser� completa (puede tener valores repetidos) si se 
//              llama con cualquier otro valor (o ninguno).
//
// PRE: "v1" y "v2" est�n ordenados
// POST: El contenido original de "mezcla" se pierde. Se sustituye por la 
//       mezcla de "v1" y "v2".  
// POST: Los vectores "v1" y "v2" NO se modifican.

/*
void MezclaVectoresDinamicos (VectorDinamico &mezcla,const VectorDinamico &v1, 
                           const VectorDinamico & v2,  const char * selectiva)
{
	char si_no[3];

	if (strlen(selectiva) != 2) 
	
		strcpy(si_no, "no"); 
	
	else { // "selectiva" tiene longitud 2
		
		// Pasar a may�culas "selectiva"

		si_no[0]=toupper(selectiva[0]);
		si_no[1]=toupper(selectiva[1]);
		si_no[2]= '\0';

		// Comparar el valor de "selectiva" con "SI"

		if (!strcmp(si_no, "SI")) // Mezcla selectiva

			MezclaVectoresDinamicosSelectiva (mezcla, v1, v2);

		else // Mezcla NO selectiva

			MezclaVectoresDinamicosTotal (mezcla, v1, v2); 
	}
}
*/
/***************************************************************************/
/***************************************************************************/
// Mezcla no selectiva de dos vectores din�micos.
// La mezcla puede contener valores repetidos. 
// Par�metros: 	
//		v3 (referencia), referencia al vector din�mico con el resultado. 
//		v1 (referencia), referencia al primer vector din�mico que se mezcla. 
//		v2 (referencia), referencia al segundo vector din�mico que se mezcla. 
// 
// PRE: "v1" y "v2" est�n ordenados
// POST: El contenido original de "v3" se pierde. Se sustituye por la 
//       mezcla de "v1" y "v2".  
// POST: Los vectores "v1" y "v2" NO se modifican.

/*
void MezclaVectoresDinamicosTotal (VectorDinamico &v3,const VectorDinamico &v1, 
                                   const VectorDinamico & v2)
{
	EliminaTodosVectorDinamico (v3);

	// Colocar punteros al inicio de los datos de los tres vectores
	const TipoBaseVector * p1 = v1.datos;
	const TipoBaseVector * p2 = v2.datos;

	// Marcar el final de los vectores a mezclar
	const TipoBaseVector * end1 = v1.datos+v1.usados;
	const TipoBaseVector * end2 = v2.datos+v2.usados;


	// mientras queden datos por examinar en los dos vectores

	while ((p1<end1) && (p2<end2)) {
		
		if (*p1 < *p2) {
			AniadeVectorDinamico (v3, *p1); // copiar de v1
			p1++;
			
		}
		else {
			AniadeVectorDinamico (v3, *p2); // copiar de v2
			p2++;
		}
	}

	// copiar lo que quede en v1

	while (p1<end1){

		AniadeVectorDinamico (v3, *p1); // copiar de v1
		p1++;
	} 
	
	// copiar lo que quede en v2

	while (p2<end2){

		AniadeVectorDinamico (v3, *p2); // copiar de v2
		p2++;
	}
}
/
/***************************************************************************/
/***************************************************************************/
// Mezcla selectiva de dos vectores din�micos.
// En el caso de encontrar valores repetidos solo selecciona uno de ellos.
// Par�metros: 	
//		v3 (referencia), referencia al vector din�mico con el resultado. 
//		v1 (referencia), referencia al primer vector din�mico que se mezcla. 
//		v2 (referencia), referencia al segundo vector din�mico que se mezcla. 
// 
// PRE: "v1" y "v2" est�n ordenados
// POST: El contenido original de "v3" se pierde. Se sustituye por la 
//       mezcla de "v1" y "v2".  
// POST: Los vectores "v1" y "v2" NO se modifican.

/*
void MezclaVectoresDinamicosSelectiva (VectorDinamico & v3, 
	            const VectorDinamico & v1, const VectorDinamico & v2)
{
	EliminaTodosVectorDinamico (v3);

	// El primer paso consiste en calcular la mezcla t�pica (que puede 
	// incluir valores repetidos) con la funci�n "MezclaVectoresTodo" 

	MezclaVectoresDinamicosTotal (v3, v1, v2);

	// Empleando la t�cnica de los dos apuntadores (lectura/escritura) 
	// eliminamos los valores repetidos.

	TipoBaseVector * fin_v3 = v3.datos+v3.usados; // Delimitar el final de "v3" 

	TipoBaseVector * pos_escritura = v3.datos+1; // La primera casilla se mantiene 
	TipoBaseVector * pos_lectura   = v3.datos+1; // siempre en el resultado 

	// Cuando "pos_lectura" se iguale a "fin_mezcla" se termina el c�lculo.

	while (pos_lectura != fin_v3) {

		if (*pos_lectura != *(pos_escritura-1)) { // Mantener el contenido 
			*pos_escritura = *pos_lectura;        // de "pos_lectura" --> 
			pos_escritura++;                      // adelantar "pos_escritura"
		}
		pos_lectura++;  // En cualquier caso, adelantar "pos_lectura"
	}

	v3.usados = pos_escritura-v3.datos; // OBSERVE: El valor m�nimo es 1 
}
*/
/***************************************************************************/
/***************************************************************************/
// Intercambia los valores de los datos referenciados por "r1" y "r2"

void Intercambia (TipoBaseVector & r1, TipoBaseVector & r2)
{
	TipoBaseVector tmp = r1;
	r1 = r2;
	r2 = tmp;
}

/***************************************************************************/
/***************************************************************************/