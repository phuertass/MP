/***************************************************************************/
// METODOLOG�A DE LA PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//
// Fichero: II_RLE.cpp
//
/*	
	Codificaci�n/descodificaci�n RLE (por l�neas) de una serie de caracteres 
	que finaliza con EOF.  
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "Funcs_VectorDinamicoCadenas.h"
#include "Matriz2D_char_RLE.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main()
{

	//======================================================================
	// PASO 1: Leer cadenas y guardarlas en un dato VectorDinamicoCadenas

	/* 
	   Las l�neas le�das se guardan en el Heap. Se accede a ellas a trav�s 
	   de un vector din�mico de datos char * al que se accede a trav�s de  
	   un dato de tipo VectorDinamicoCadenas.

	   El vector din�mico se redimensionar� cuando haga falta, y finalmente se  
	   ajustar� para que tenga tantas casillas como l�neas se hayan le�do. 

	   Se crea con los valores por defecto: capacidad_inicial=TAM_INICIAL y  
	   tipo_redimension = EnBloques (ver Funcs_VectorDinamicoCadenas.h)
	*/

	//.......................................................................
	// Crear y rellenar el dato VectorDinamicoCadenas

	VectorDinamicoCadenas v = CreaVectorDinamico ();


	string cadena; // Para leer cada una de las cadenas 

	int max_long_cadena = 0; // Longitud de la mayor cadena
	int min_long_cadena = 512; // Longitud de la mayor cadena


	while (getline (cin, cadena)) {

		// Reservar memoria para la cadena cl�sica. 
		// Se necesita un car�cter m�s que la longitud de "cadena". 
		// La longitud de "cadena" se calcula con el m�todo "length" de string

		int long_cadena = cadena.length();
		char * cadena_nueva = new char [long_cadena+1];

		// Copiar desde "cadena" a "nueva_cadena"

		strcpy(cadena_nueva, cadena.c_str());	

		// "cadena_nueva" nos lleva a una zona del Heap reservada e 
		// inicializada correctamente. Pasamos esa direcci�n a la funci�n 
		// "AniadeVectorDinamico" para que asocie el puntero adecuado de 
		// "v" con esta direcci�n.

		AniadeVectorDinamico (v, cadena_nueva); 

		// cerr << "<"<< cadena_nueva<<"> " << long_cadena << endl; 

		// Calcular la longitud de la mayor cadena. Es importante para poder 
		// dimensionar la matriz din�mica posteriormente --> Tendr� tantas 
		// columnas como la longitud de la mayor cadena leida.
		// La longitud de la menor cadena no tiene relevancia.   

		if (long_cadena > max_long_cadena) 
			max_long_cadena = long_cadena;
		if (long_cadena < min_long_cadena) 
			min_long_cadena = long_cadena;

	} // while

	//.......................................................................
	// Mostrar ocupaci�n de "v" antes y despu�s de ajustar

	// Una vez que se han leido todas las l�neas hay que reajustar el 
	// vector "v" para dejarlo con el tama�o exacto. Debe tener tantas 
	// casillas reservadas (capacidad) como usadas.

	cerr << endl; 
	cerr << "ANTES DE AJUSTAR" << endl; 
	cerr << endl;

	cerr << "Casillas usadas = " << UsadosVectorDinamico(v) << endl;  
	cerr << "Casillas reservadas = " << CapacidadVectorDinamico(v) << endl;  
	cerr << endl; 

	Reajusta (v);

	cerr << endl; 
	cerr << "DESPUES DE AJUSTAR" << endl; 
	cerr << endl;

	cerr << "Casillas usadas = " << UsadosVectorDinamico(v) << endl;  
	cerr << "Casillas reservadas = " << CapacidadVectorDinamico(v) << endl;  
	cerr << endl; 

	cerr << "La cadena mas corta mide = " << min_long_cadena << endl;  
	cerr << "La cadena mas larga mide = " << max_long_cadena << endl;  
	cerr << endl; 



	//======================================================================
	// PASO 2: Crear un dato Matriz2D a partir del VectorDinamicoCadenas

	//.......................................................................
	// Crear "original" y copiar el contenido desde de "v" 

	Matriz2D original = CreaMatriz (UsadosVectorDinamico(v), max_long_cadena);


	cerr << "Se ha creado la matriz \"original\" de dimensiones: " 
	     << NumFilas (original) << " x " << NumColumnas (original) << endl;
	cerr << "Vacia = " << (EstaVacia(original) ? "SI": "NO") << endl;	
	cerr << endl;	


	for (int f=0; f<UsadosVectorDinamico(v); f++) {

		char * linea_f = LineaVectorDinamicoCadenas (v, f);
		int long_cadena = strlen (linea_f);

		// Copiar en la fila "f" de "original" el contenido de linea_f 
			
		for (int c=0; c<long_cadena; c++) 
			Valor (original, f, c) = linea_f[c];

		delete [] linea_f;

	} // for f


	// El vector din�mico de cadenas ya no es �til

	LiberaMemoria (v);

	//.......................................................................
	// Opcional: Mostrar matriz din�mica "original"

	cerr << "............................................" << endl;
	cerr << "original: ";
	cerr << endl;
	cerr << ToString (original) << endl; 
	cerr << "............................................" << endl;
	cerr << endl;

	//======================================================================
	// PASO 3: Codificar cada l�nea (fila) de "original". 

	/* 
		El resultrado se guardar� en una estructura de datos din�mica en la 
		que fundamentalmente tendremos una matriz 2D de parejas (valor, veces)  
		para guardar el n�mero de veces ("veces") que aparece un car�cter 
		("valor") de manera consecutiva. El tipo Pareja es un struct;  

			int  veces; // veces que se repite
			char valor; // valor

		La estructura de datos que da acceso a toda la informaci�n es de tipo 
		RLE, un struct: 

			// Los siguientes tres campos representabn una matriz 2D de datos 
			// de tipo "Pareja"

			Pareja ** parejas; // Acceso a los VD de parejas 
			int filas;         // Numero de lineas de datos Pareja
			int columnas;      // Numero m�ximo de columnas de datos Pareja
			
			// Realmente se trata de una tabla dentada. Necesitamos saber 
			// cu�nmtas columnas tiene cada fila: 

			int * usados;	   // N�mero de parejas que habr� asociadas a cada 
							   // fila tras codificar
	*/

	// Pareja: Para guardar cada valor y las veces que se repite

	typedef struct {
		int  veces; // veces que se repite
		char valor; // valor
	} Pareja;


	// RLE: acceso a toda la informaci�n de la codificaci�n. 

	typedef struct {
		
		// Los siguientes tres campos representabn una matriz 2D de datos 
		// de tipo "Pareja"

		Pareja ** parejas; // Acceso a los VD de parejas 
		int filas;         // Numero de lineas de datos Pareja
		int columnas;      // Numero de columnas (m�ximo) de datos Pareja

		// Realmente se trata de una tabla dentada. Necesitamos saber 
		// cu�nmtas columnas tiene cada fila: 

		int * usados;	   // N�mero de parejas que habr� asociadas a cada 
						   // fila tras codificar 
	} RLE;


	// Crear e inicializar estructura de datos RLE
 
	RLE miRLE;

	miRLE.filas    = NumFilas(original);
	miRLE.columnas = NumColumnas (original); 

	// La codificaci�n se realiza por filas y en cada fila habr� un n�mero 
	// indeterminado de datos "Pareja" tras la codificaci�n RLE. 
	// Inicialmente reservamos espacio para cada vector din�mico de datos 
	// "Pareja" con la previsi�n de encontrar el peor caso: tantas parejas 
	// como columnas tenga "original" (recuerde que ese valor es la longitud 
	// de la mayor l�nea leida)

	// Vector din�mico de punteros a datos "Pareja". Habr� tantos punteros 
	// como filas. El� n�mero de filas no cambiar�.

	miRLE.parejas = new Pareja * [miRLE.filas]; 

	
	// El resultado de la codificaci�n RLE ser� una tabla dentada de datos 
	// "Pareja". Necesitamos saber cu�ntas columnas tiene cada fila. 
	// Esos contadores se calculan en el vector din�mico accesible desde el 
	// puntero "miRLE.usados". 
	// Creamos el vector din�mico y lo inicalizamos a 0. 

	miRLE.usados = new int [miRLE.filas];  

	for (int f=0; f<miRLE.filas; f++) {
		miRLE.usados[f] = 0;
	}

	// Las parejas se guardan en una matriz din�mica. El n�mero de filas no 
	// cambia, aunque s� las columnas de cada fila. 
	// Inicialmente se reserva espacio en cada fila (vector din�mico de datos 
	// "Pareja") para la peor situaci�n posible: "miRLE.columnas" columnas. 
	// 
	// Al finalizar la codificaci�n RLE se reajustar�n las filas de acuerdo al 
	// n�mero de parejas resultantes en cada fila: los valorers del vector 
	// din�mico de contadores accesible desde "miRLE.usados"

	for (int f=0; f<miRLE.filas; f++) {
		miRLE.parejas[f]  = new Pareja [miRLE.columnas];
	}


	// Empieza la codificaci�n RLE. Se procesa "original" por l�neas. 
	// Recuerde que miRLE.filas == NumFilas(original)

	for (int f=0; f<miRLE.filas; f++) {
		
		char referencia;   	// caracter de referencia: �se repite?
		char leido; 	    // caracter procesado en cada iteraci�n
		int  iguales_hasta_ahora;  // n�mero de valores iguales
	
		referencia = Valor(original, f, 0); // primer car�cter de fila "f"
		iguales_hasta_ahora = 1;            // veces que se repite

		// Resto de caracteres de la fila "f"

		for (int pos=1; pos<miRLE.columnas; pos++) {
			
			leido = Valor(original, f, pos); // car�cter "pos"
	
			if (referencia == leido) // Continua la serie
	      
				iguales_hasta_ahora++; 	
										
			else { // Se acab� la serie

				// Formar la pareja
				
				Pareja una_pareja;
				una_pareja.valor = referencia; // car�cter
				una_pareja.veces = iguales_hasta_ahora; // veces que se repite
			
		
				// Guardar la pareja ��siempre hay sitio disponible!!

				miRLE.parejas[f][miRLE.usados[f]] = una_pareja;	
				miRLE.usados[f]++; // Actualizar el contador de parejas  

				// Prepararse para una nueva serie
				referencia = leido; 		
				iguales_hasta_ahora = 1;
			} 

		} // for pos
		
		// Formar y guardar la �ltima pareja de la fila 
					
		
		Pareja una_pareja;
		una_pareja.valor = referencia; // car�cter
		una_pareja.veces = iguales_hasta_ahora; // veces que se repite
		
		miRLE.parejas[f][miRLE.usados[f]] = una_pareja;	
		miRLE.usados[f]++; // Actualizar el contador de parejas  
		

	} // for f

	
	// Reajustar matriz de datos "Pareja": formar una tabla dentada real.

	// Despu�s de la cofificaci�n RLE cada l�nea tiene un n�mero real de 
	// parejas que no tiene porqu� ser igual al de las dem�s l�neas. 
	// Ahora se reajustan los vectores din�micos de datos "Pareja" para que la 
	// memoria ocupada sea la estrictamente necesaria.  

	for (int f=0; f<miRLE.filas; f++) {

		if (miRLE.usados[f] != miRLE.columnas) { // Sobran casillas 

			// Reservar las casillas estrictamente necesarias
			Pareja * tmp = new Pareja [miRLE.usados[f]];
				
			// Copiar a "tmp" las casillas usadas en la fila "f"
			memcpy (tmp, miRLE.parejas[f], miRLE.usados[f]*sizeof(Pareja));
				
			// Liberar el vector de datos "Pareja" de la antigua fila
			delete [] miRLE.parejas[f];

			// Reajustar el puntero para referenciar a la nueva fila
			miRLE.parejas[f] = tmp;
		}

	} // for f



	// Opcional: Mostrar parejas resultantes de la codificaci�n RLE 

	cerr << endl;
	cerr << "............................................" << endl;

	for (int f=0; f<miRLE.filas; f++) {

		cerr << "Fila " << f << ": " << miRLE.usados[f] << "-- > "; 
			
		for (int c=0; c<miRLE.usados[f]; c++) {
	
			char el_valor = (miRLE.parejas[f][c]).valor; // Valor a repetir
			int num_veces = (miRLE.parejas[f][c]).veces; // Veces a repetir
		
			cerr << el_valor << num_veces << " ";
		}
		
		cerr << endl;

	} // for f

	cerr << "............................................" << endl;
	cerr << endl;


	//======================================================================
	// PASO 4: Descodificar cada l�nea para formar un nuevo dato Matriz2D 
	//         de datos char: "descodificada". 


	// Crear "descodificada": sus dimensiones ser�n las mismas que las de 
	// "original". Aunque en el c�digo vea que se crea con "miRLE.filas" filas 
	// y "miRLE.columnas" recujerde que  miRLE.filas == NumFilas(original) y 
	// miRLE.columnas == NumColumnas (original) 

	Matriz2D descodificada = CreaMatriz (miRLE.filas, miRLE.columnas);

	cerr << endl;	
	cerr << "Se ha creado la matriz \"descodificada\" de dimensiones: " 
	     << NumFilas (descodificada) << " x " 
	     << NumColumnas (descodificada) << endl;
	cerr << "Vacia = " << (EstaVacia(descodificada) ? "SI": "NO") << endl;	
	cerr << endl;	


	// Calcular contenido de "descodificada" desde "mi_RLE" (trivial)

	for (int f=0; f<miRLE.filas; f++) {
			
		int col_descodificada = 0; // Columna de "descodificada"

		for (int c=0; c<miRLE.usados[f]; c++) {
	
			char el_valor = (miRLE.parejas[f][c]).valor; // Valor a repetir
			int num_veces = (miRLE.parejas[f][c]).veces; // Veces a repetir
		
			for (int n=1; n<=num_veces; n++) {

				Valor (descodificada, f, col_descodificada) = el_valor;
				col_descodificada++;
			}

		} // for c
			
	} // for f


	//======================================================================
	// PASO 5: Comparar "original" y "descodificada"

	cerr << endl; 
	cerr << "=======================================================" << endl; 

	if (SonIguales (original, descodificada)) 
		cerr << "Codificacion - descodificacion realizada con exito." << endl;
	else 
		cerr << "Error en codificacion - descodificacion." << endl;	

	cerr << "=======================================================" << endl; 
	cerr << endl; 

	
	//.......................................................................
	// Opcional: Mostrar matriz din�mica "descodificada"


	cerr << "............................................" << endl;
	cerr << "descodificada: ";
	cerr << endl;
	cerr << ToString (descodificada); 
	cerr << "............................................" << endl;
	cerr << endl;

	//.......................................................................
	// Antes de terminar, "limpiamos" los caracteres por defecto para que el 
	// resultado (lo enviado a cout) coincida con lo leido de cin

	for (int f=0; f<NumFilas(descodificada); f++) {
			
		int fin_fila_f = NumColumnas(descodificada)-1;

		while (Valor(descodificada, f,fin_fila_f)==VALOR_DEF) fin_fila_f--;

		for (int c=0; c<=fin_fila_f; c++) 
			cout << Valor(descodificada, f,c);

		cout << endl; 
	}


	//======================================================================
	// PASO 6:  Liberar memoria din�mica


	// Las "miRLE.filas" filas de "miRLE" (vectores dinamicos de "Pareja")

	for (int f=0; f<miRLE.filas; f++) 
		delete [] miRLE.parejas[f];

	// El vector din�mico de punteros a las filas (ya liberadas) de "miRLE" 

	delete [] miRLE.parejas; 


	// Matrices 2D de datos char con los datos originales y reconstruidos

	DestruyeMatriz (original); 
	DestruyeMatriz (descodificada); 

	//.......................................................................

	return 0;
}

/***************************************************************************/
/***************************************************************************/