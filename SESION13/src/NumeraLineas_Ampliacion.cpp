#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{

    int num_linea = 1;
    string cadena;

    // Si el numero de argumentos es superior a 3 se muestra un mensaje de error
    if (argc > 3)
    {
        cerr << "Error: numero de argumentos incorrecto." << endl;
        exit(1);
    }

    // Si el numero de argumentos es solo el nombre del programa se lee desde 
    // el teclado y se muestra por pantalla las lineas
    if (argc == 1)
    {

        while (getline(cin, cadena))
        {

            cout << num_linea << " | " << cadena << endl;

            num_linea++;
        }
    }

    // Si el numero de argumentos es 2 se lee desde el fichero y se muestra por
    // pantalla las lineas
    if (argc == 2)
    {

        ifstream fi(argv[1]);
        if (!fi)
        {
            cerr << "Error: No se puede abrir " << argv[1] << endl;
            exit(1);
        }

        while (getline(fi, cadena))
        {

            cout << num_linea << " | " << cadena << endl;

            num_linea++;
        }

        fi.close();
    }

    // Si el numero de argumentos es 3 se lee desde el fichero y se escribe la salida 
    // en el fichero indicado
    if (argc == 3)
    {

        ifstream fi(argv[1]);
        if (!fi)
        {
            cerr << "Error: No se puede abrir " << argv[1] << endl;
            exit(2);
        }

        ofstream fo(argv[2]);

        while (getline(fi, cadena))
        {

            fo << num_linea << " | " << cadena << endl;

            num_linea++;
        }

        fi.close();
        fo.close();
    }

    return (0);
}
