#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main(int argc, char **argv)
{
    if (argc == 1 or argc > 2)
    {
        cerr << "Uso: " << argv[0] << " [Longitud exacta] ";
        cerr << endl
             << endl;
        exit(1);
    }

    int longitud = atoi(argv[1]);

    string cadena;

    cin >> cadena;

    int contador = 0;

    while (!cin.eof())
    {

        if (cadena.length() == longitud)
        {
            contador++;
            cout << cadena << endl;
        }

        cin >> cadena; // Nueva lectura
    }

    cout << "El numero de lineas con longitud " << longitud << " es "
         << contador << endl;

    return (0);
}

/***************************************************************************/
/***************************************************************************/