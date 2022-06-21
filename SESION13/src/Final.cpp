#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
	if (argc == 1 or argc > 2)
	{
		cerr << "Uso: " << argv[0] << " [Tail del programa] ";
		cerr << endl
			 << endl;
		exit(1);
	}

	int numero = atoi(argv[1]);
	if(numero<=0)
	{
		cerr << "Error: El n�mero de lineas debe ser >=0\n";
		exit(2);
	}

	const int TAM = 256; // M�xima longitud de la cadena empleada
	char cad[TAM];		 // para leer cada l�nea

	cin.getline(cad, TAM); // Lectura adelantada de una cadena

	int contador_lineas = 1;
	vector<string> texto_guardado;

	while (!cin.eof())
	{
		texto_guardado.push_back(cad);
		cin.getline(cad, TAM); // Nueva lectura
		contador_lineas++;
	}

	for (int i = 0; i < numero; i++)
	{
		cout << texto_guardado[contador_lineas - numero + i - 1] << endl;
	}

	return (0);
}