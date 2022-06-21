#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
	const int TAM = 256; // M�xima longitud de la cadena empleada
	char cad[TAM];		 // para leer cada l�nea

	cin.getline(cad, TAM); // Lectura adelantada de una cadena

	while (!cin.eof())
	{

		if (cad[0] != '#')
		{				 // Si la longitud es mayor que cero,
			cout << cad; // no est� vac�a: enviarla a cout
			cout << endl;
		}

		cin.getline(cad, TAM); // Nueva lectura
	}

	return (0);
}