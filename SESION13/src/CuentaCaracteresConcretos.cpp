#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
	if (argc == 1 or argc > 2)
	{
		cerr << "Uso: " << argv[0] << " [CaracterABuscar] ";
		cerr << endl
			 << endl;
		exit(1);
	}
	const char a_buscar = *argv[1];
	char c;
	int contador = 0;
	c = cin.get();

	while (!cin.eof())
	{

		if (c == a_buscar)
		{
			contador++;
		}

		c = cin.get();
	}

	cout << "Caracteres " << a_buscar << " leidos = " << contador << endl;

	return 0;
}