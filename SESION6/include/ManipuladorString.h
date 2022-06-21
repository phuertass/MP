#ifndef MANIPULADOR_STRING
#define MANIPULADOR_STRING

#include <cctype>
#include <string>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/*
	Clase que permite modificar un string con operaciones que son habituales 
	sobre estos datos como eliminar separadores, contar palabras, ...
	Funcionamiento: Si se quiere procesar la cadena "s" bastar� con usar el 
	constructor con argumentos ManipulardorString (s) y usar los m�todos 
	ofertados. Si se desea utilizar la cadena resultante se puede recuperar 
	usando el m�todo GetCadena() que devuelve una copia de la cadena procesada.
*/

class ManipuladorString 
{	
private:

	string cadena;	
	
public:

	/***********************************************************************/
	// Constructores

	// Constructor sin argumentos
	ManipuladorString (void) : cadena("") 
	{ }

	// Constructor con un argumento
	
	ManipuladorString (string la_cadena) : cadena(la_cadena) 
	{ }
	
	/***********************************************************************/
	// Modifica el valor del campo cadena 
	
	void SetCadena (string cad)
	{
		cadena = cad;
	}

	/***********************************************************************/
	// Consulta el contenido de "cadena"
	
	string GetCadena (void)
	{
		return (cadena);
	}
	
	/***********************************************************************/
	// Modifica la cadena. Elimina los caracteres separadores finales de 
	// "cadena". Los caracteres separadores son el espacio en blanco, 
	// el tabulador y el salto de l�nea. 
	// Usaremos la funci�n isspace() para simplificar el c�lculo. 
	
	void EliminaUltimosSeparadores (void);
	/***********************************************************************/
	// Modifica la cadena. Elimina los caracteres separadores iniciales de 
	// "cadena". Los caracteres separadores son el espacio en blanco, 
	// el tabulador y el salto de l�nea. 
	// Usaremos la funci�n isspace() para simplificar el c�lculo. 
	
	void EliminaPrimerosSeparadores (void);
	
	/***********************************************************************/
	// Modifica la cadena. Elimina los caracteres separadores iniciales y 
	// finales de "cadena". Los caracteres separadores son el espacio en 
	// blanco, el tabulador y el salto de l�nea. 
	// Usaremos la funci�n isspace() para simplificar el c�lculo. 
	
	void EliminaPrimerosYUltimosSeparadores (void);
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
	
	void EliminaExcesoSeparadores (void);
		
	/***********************************************************************/
	// Eliminar '.', ',' � ';' final	
	// PRE: cadena.length() > 0
	
	void EliminaPuntosyComasFinal (void);
			
	/***********************************************************************/
	// Calcula y devuelve el n�emro de palabras en la cadena. 
	// Los separadores delimitan las palabras.
	
	int CuentaPalabras (void);

	/***********************************************************************/
	// Modifica la cadena transformando todos los caracteres a may�sculas. 
	
	void ConvierteAMayusculas (void);
	
	/***********************************************************************/
	// Modifica la cadena transformando todos los caracteres a min�sculas. 
	
	void ConvierteAMinusculas (void);
	
	/************************************************************************/
	// Devuelve "true" si "cadena" es la representaci�n textual de un int 

	bool EsEntero (void);
		
	/************************************************************************/
	// Devuelve "true" si "cadena" es la representaci�n textual de un double 
	
	bool EsReal (void);
			
	/************************************************************************/		
	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#endif