#include "ManipuladorString.h"

using namespace std;


/***********************************************************************/
// Modifica la cadena. Elimina los caracteres separadores finales de 
// "cadena". Los caracteres separadores son el espacio en blanco, 
// el tabulador y el salto de l�nea. 
// Usaremos la funci�n isspace() para simplificar el c�lculo. 

void ManipuladorString::EliminaUltimosSeparadores (void)
{
	while (cadena.length()>0 && isspace(cadena.back()))
		cadena.pop_back();
}

/***********************************************************************/
// Modifica la cadena. Elimina los caracteres separadores iniciales de 
// "cadena". Los caracteres separadores son el espacio en blanco, 
// el tabulador y el salto de l�nea. 
// Usaremos la funci�n isspace() para simplificar el c�lculo. 

void ManipuladorString::EliminaPrimerosSeparadores (void)
{	
	// Buscar el primer car�cter no espacio
	unsigned int pos = 0;
	while (pos <cadena.length() && isspace(cadena.at(pos))) pos++;

	cadena= cadena.substr(pos, cadena.length()-pos);
}

/***********************************************************************/
// Modifica la cadena. Elimina los caracteres separadores iniciales y 
// finales de "cadena". Los caracteres separadores son el espacio en 
// blanco, el tabulador y el salto de l�nea. 
// Usaremos la funci�n isspace() para simplificar el c�lculo. 

void ManipuladorString::EliminaPrimerosYUltimosSeparadores (void)
{	
	EliminaPrimerosSeparadores();
	EliminaUltimosSeparadores();
}

/***********************************************************************/
// Modifica la cadena. Elimina el exceso de caracteres separadores, 
// es decir, que sustituye todas las secuencias de separadores por un 
// s�lo espacio. 
// Por ejemplo, si la cadena original es " ah    K", que contiene una 
// secuencia de cuatro espacios consecutivos, el resultado debe ser la 
// cadena " ah K".  
// Los caracteres separadores son el espacio en blanco, el tabulador 
// y el salto de l�nea. 
// Usaremos la funci�n isspace() para simplificar el c�lculo. 

void ManipuladorString::EliminaExcesoSeparadores (void)
{	
	// �c�mo es el primer car�cter del vector?

	bool en_blanco;

	if (isspace(cadena.at(0)))
		en_blanco = true; // puede ser el primero de una secuencia 
	else 
		en_blanco = false;

	unsigned int long_cadena = cadena.length();

	int  pos_escritura = 1; // sea cual sea el primero, no cambiar�.
	int  pos_lectura   = 1;

	while (pos_lectura < long_cadena) {
	
		char leido; // caracter leido en cada iteraci�n del 
					// ciclo que recorre el vector  
		
		leido = cadena.at(pos_lectura);

		if (isspace(leido)) // Se ha leido un separador 

			if (en_blanco) // (isspace(leido) && en_blanco)
		
				pos_lectura++;	// segimos en secuencia de blancos.
								// saltarlo: no se guarda

			else // (isspace(leido) && !en_blanco)
			{
				en_blanco=true; // puede empezar una secuencia 
				cadena.at(pos_escritura) = ' '; // guardar el primer
				pos_lectura++;					// blanco y avanzar 
				pos_escritura++;		
			}

		else // NO se ha leido un separador 

			if (en_blanco) // (!isspace(leido) && en_blanco)
			{
				en_blanco=false; // termina la secuencia
				cadena.at(pos_escritura) = leido; // guardar y 
				pos_lectura++;				      // avanzar
				pos_escritura++;		
			}
			else  // (!isspace(leido) && !en_blanco)
			{
				cadena.at(pos_escritura) = leido; // guardar y 
				pos_lectura++;					  // avanzar
				pos_escritura++;		
			}
	} // while (pos_lectura < long_cadena)
			
	cadena = cadena.substr(0, pos_escritura);	
}
	
/***********************************************************************/
// Eliminar '.', ',' � ';' final	
// PRE: cadena.length() > 0

void ManipuladorString::EliminaPuntosyComasFinal (void)
{		
	char ultimo = cadena.at(cadena.length()-1);	
	if (ultimo == '.' || ultimo == ',' || ultimo == ';') 
		cadena = cadena.substr(0, cadena.length()-1); 
}
		
/***********************************************************************/
// Calcula y devuelve el n�emro de palabras en la cadena. 
// Los separadores delimitan las palabras.

int ManipuladorString::CuentaPalabras (void)
{	
	// Trabajaremos con una cadena sin espacios iniciales ni finales
	// por lo que usaremos una copia del campo "cadena" para no modificar 
	// el original. La copia sin espacios de "cadena" es  "cadena_limpia"  
		
	// 1. Crear objeto manipulador con una copia del campo "cadena"
	ManipuladorString manip_local(cadena);
	// 2. Eliminar separadores iniciales y finales
	manip_local.EliminaPrimerosYUltimosSeparadores();
	// 3. Obtener una copia de la cadena "limpia"
	string cadena_limpia = manip_local.GetCadena();


	int cont_palabras = 0;
	int long_cadena = cadena_limpia.length(); 
	
	if (long_cadena>0) {
		
		// Si hemos llegado aqu� es porque: 1) no hay espacios iniciales 
		// en "cadena" y 2) hay algo en "cadena", por lo que necesariamente 
		// el primer car�cter no es separador y eso significa que al menos 
		// hay una palabra. 
		bool en_palabra = true; 
		
		for (int pos_lectura=0; pos_lectura<long_cadena; pos_lectura++) {
		
			if (isspace(cadena_limpia.at(pos_lectura))) {
				
				if (en_palabra)	// Se termin� la palabra --> una m�s
					cont_palabras++; 
				
				en_palabra = false; // Estamos en zona de separadores 
			}
			
			else en_palabra = true; // Estamoos en zona de palabra
		}
		
		cont_palabras++; // La �ltima palabra			
	} 
				
	return (cont_palabras);
	
}

/***********************************************************************/
// Modifica la cadena transformando todos los caracteres a may�sculas. 

void ManipuladorString::ConvierteAMayusculas (void)
{	
	unsigned int long_cad = cadena.length();
	
	for (int pos=0; pos < long_cad; pos++)	
		cadena.at(pos) = toupper(cadena.at(pos));
}

/***********************************************************************/
// Modifica la cadena transformando todos los caracteres a min�sculas. 

void ManipuladorString::ConvierteAMinusculas (void)
{	
	unsigned int long_cad = cadena.length();
	
	for (int pos=0; pos < long_cad; pos++)	
		cadena.at(pos) = tolower(cadena.at(pos));
}

/************************************************************************/
// Devuelve "true" si "cadena" es la representaci�n textual de un int 

bool ManipuladorString::EsEntero (void) 
{
	EliminaPrimerosYUltimosSeparadores();

	bool es_entero = true;
	unsigned int long_cadena = cadena.length();
			
	if (long_cadena == 0) es_entero = false;
	else {	// long_cadena > 0 
			
		// Si el primer car�cter es '+' � '-', perfecto. En ese caso 
		// se pasa al siguiente car�cter (posici�n 1).
				
		unsigned int pos;
		if (cadena.at(0)=='-'|| cadena.at(0) == '+') pos=1;
		else pos=0;

		while ((pos < long_cadena) && es_entero) {
			if (!isdigit(cadena.at(pos))) es_entero = false;
			else pos++;
		}	
	}
	
	return (es_entero);
}
	
/************************************************************************/
// Devuelve "true" si "cadena" es la representaci�n textual de un double 

bool ManipuladorString::EsReal (void) 
{
	EliminaPrimerosYUltimosSeparadores();
	
	bool es_real = true;		 
	unsigned int long_cadena = cadena.length();
			
	if (long_cadena == 0)  es_real = false; // No hay nada
	else {	// long_cadena > 0 

		// Si el primer car�cter es '+' � '-', perfecto. En ese  
		// caso se pasa al siguiente car�cter (posici�n 1).
	
		unsigned int pos;
		if (cadena.at(0)=='-'|| cadena.at(0) == '+') pos=1;
		else pos=0;
		
		// Bandera que se activa al encontrar un punto
		bool encontrado_un_punto = false;
		
		while ((pos < long_cadena) && es_real) {
				
			char c = cadena.at(pos);

			if (!isdigit(c)) {
		
				// Solo puede haber un punto. 
				// Si se ha encontrado un punto y ya se hab�a 
				// encontrado otro, error. Si no, activar la bandera 
				// "encontrado_un_punto" (ya no puede haber m�s).
				
				if (c=='.') {
					if (encontrado_un_punto) es_real= false; 
					else encontrado_un_punto = true; 
				}
				// Si no es un punto ni un d�gito --> error
				else es_real= false; 
			}
						
			pos++; 		
				
		}	// while ((pos < long_cadena) && es_real)
						
	} // else de if (long_cadena == 0)
	
	return (es_real);
}
		


