#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{

    // Control de errores

    if (argc == 1 || argc > 3)
    {

        cerr << "Error: numero de argumentos incorrecto." << endl;
        cerr << "Uso: " << argv[0] << " <fich1> <fich2>" << endl;
        exit(1);
    }


    ifstream fi(argv[2]);

    istringstream iss;

    int pos_linea, pos_columna;
    string linea, palabra;

    while (fi >> pos_linea)
    {

        fi >> pos_columna;

        // Apertura del fichero de texto

        ifstream fi(argv[1]);

        // Avanzo en filas hasta la linea que quiero

        for (int i = 0; i < pos_linea; i++)
        {

            getline(fi, linea);
        }

        fi.close();

        iss.str(linea);

        // Avanzo hasta la posicion de la palabra oculta
        
        for (int j = 0; j < pos_columna; j++)
        {

            iss >> palabra;
        }

        cout << palabra << " ";
    }

    cout << endl;

    fi.close();

    return 0;
}
