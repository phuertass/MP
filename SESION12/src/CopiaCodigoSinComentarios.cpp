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

		for (int i = strlen(cad) - 1; i >= 0; i--)
		{
			if (cad[i] == ' ' and cad[i + 1] == ' ')
			{
				for (int j = i; j < 100; j++)
				{
					cad[j] = cad[j + 1];
				}
			}
		}
		cout << cad << endl;
		
		cin.getline(cad, TAM); // Nueva lectura
	}

	return (0);
}