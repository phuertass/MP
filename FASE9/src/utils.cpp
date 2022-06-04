#include "utils.h"
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


bool ExisteFichero (const string & nombre)
{

	ifstream fichero;

	fichero.open (nombre);

	bool problema = fichero.fail();
	if (!problema) fichero.close();

	return ((problema) ? false : true);
}

bool EsFicheroTxt(const string &nombre_fichero)
{
    // Comprobamos si la primera cadena del fichero
    // es una cabecera de fichero de marcas de texto o binaria
    ifstream fi(nombre_fichero);

    string cabecera;
    getline(fi, cabecera);

    bool esTxt = false;

    if (cabecera == "MARCAS")
        esTxt = true;

    fi.close();

    return esTxt;
}

bool EsFicheroBin(const string &nombre_fichero)
{
    // Comprobamos si la primera cadena del fichero
    // es una cabecera de fichero de marcas de texto
    ifstream fi(nombre_fichero);

    string cabecera;
    getline(fi, cabecera);

    bool esBin = false;

    if (cabecera == "MARCAS_BIN")
        esBin = true;

    fi.close();

    return esBin;
}

