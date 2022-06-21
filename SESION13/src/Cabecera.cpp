#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main(int argc, char **argv)
{
    if (argc == 1 or argc > 2)
    {
        cerr << "Uso: " << argv[0] << " [Head del programa] ";
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
    char cad[TAM];       // para leer cada l�nea

    cin.getline(cad, TAM); // Lectura adelantada de una cadena

    int i = 0;
    while (!cin.eof() && i < numero)
    {
        // Si la longitud es mayor que cero,
        cout << cad; // no est� vac�a: enviarla a cout
        cout << endl;

        cin.getline(cad, TAM); // Nueva lectura
        i++;
    }

    return (0);
}