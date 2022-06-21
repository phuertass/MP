#include <iostream>
#include <iomanip>
#include <cstring>
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

int main(int argc, char **argv)
{
    int numero_lineas;
    cin >> numero_lineas;
    if (numero_lineas <= 0)
    {
        cout << "0" << endl;
        exit(1);
    }

    cout << "El numero leido es " << numero_lineas << endl;

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

    for (int i = 0; i < numero_lineas; i++)
    {
        cout << pruebas[i] << endl;
    }

    cout << "\n\n";

    char c;

    c = cin.get(); // lectura adelantada
    int contador = 0;
    string cadena = "";

    while (!cin.eof())
    {

        // Si el car�cter no es un separador, escribirlo.
        // Excepci�n: el car�cter '\n' tambi�n se escribe

        if (c != '\t' && c != '\v' && c != '\f' && c != '\r')
        {
            cout << c << ",";
            if (c == '\n')
            {
                contador++;
                cadena += "\n";
                cout << "Cadena formada: " << cadena << endl;
                if (cadena.length() > 1)
                    cout << "Numero de palabras en cadena " << CuentaPalabras(cadena) << endl;
                cadena = "";
            }
            else
                cadena += c;
        }

        c = cin.get(); // lectura adelantada

    } // while (!cin.eof())

    cout << "Contador de lineas: " << contador << endl;

    return (0);
}

/***************************************************************************/
/***************************************************************************/