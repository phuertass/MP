#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int CuentaPalabras(const string &s)
{
    int contador = 0;
    int i = 0;
    while (i < s.length())
    {
        while (i < s.length() && s[i] == ' ')
            i++;
        if (i < s.length())
        {
            contador++;
            while (i < s.length() && s[i] != ' ')
                i++;
        }
    }
    return contador;
}

bool ExisteFichero(const string &nombre)
{

    ifstream fichero;

    fichero.open(nombre);

    bool problema = fichero.fail();
    if (!problema)
        fichero.close();

    return ((problema) ? false : true);
}

void SaltaComentarios(ifstream &fichero)
{
    string linea;
    while (getline(fichero, linea))
    {
        cout << linea << endl;
        if(linea[0] == '#')
            cout << "Es comentario" << endl;
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cerr << "Error: numero de argumentos incorrecto." << endl;
        cerr << "Uso: " << argv[0] << " <fich1> ... <fichn>" << endl;
        exit(1);
    }

    for (int i = 1; i < argc; i++)
    {
        if (ExisteFichero(argv[i]))
        {
            ifstream fi(argv[i]);

            string linea;
            fi >> linea;
            cout << "Fichero " << argv[i] << ": " << linea << endl;
        
            int numero_lineas = 0;
            cin >> numero_lineas;
            cout << "El numero leido es " << numero_lineas << endl;

            // Ignoro las lineas que empiezan por #
            bool correctolineas = true;
            string pruebas[numero_lineas];
            for (int i = 0; i < numero_lineas; i++)
            {
                string cadena;
                cin >> cadena;
                pruebas[i] = cadena;
                // cout<<"Iteracion "<<i+1<<" "<<cadena<<endl;
                if (cadena.length() <= 0)
                {
                    correctolineas = false;
                    break;
                }
                if (i == numero_lineas)
                {
                    correctolineas = true;
                }
            }

            correctolineas ? cout << "correcto" << endl : cout << "no correcto" << endl;
            fi.close();
        }
        else
        {
            cerr << "Error: No pudo abrirse " << argv[i] << endl;
        }
    }

    return 0;
}

/***************************************************************************/
/***************************************************************************/