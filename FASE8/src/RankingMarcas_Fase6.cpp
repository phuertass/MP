/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// Proyecto Gestion de marcas de atletismo
//
// Programa main del proyecto
//
// Fichero: main.cpp
//
/***************************************************************************/
/***************************************************************************/
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "RegistroDeMarca.h"
#include "VectorMarcas.h"
#include "MatrizMarcas.h"

using namespace std;

int main()
{
    // Variables para lectura de datos
    const int TAM_CAD = 100;
    char valor[TAM_CAD];

    // Numero de pruebas
    int n_pruebas;
    cin >> n_pruebas;

    // Vector de string para almacenar los nombres de las pruebas
    string pruebas[n_pruebas];

    for (int i = 0; i < n_pruebas; i++)
    {
        cin >> pruebas[i];
        cout << pruebas[i] << endl;
    }

    // Creamos el objeto MatrizMarcas
    // MatrizMarcas m = CreaMatrizMarcas(n_pruebas);
    MatrizMarcas m(n_pruebas);

    // Creamos tantos Vectores de Marcas como pruebas
    // y los almacenamos en el objeto MatrizMarcas
    // Ademas, le asignamos el nombre de la prueba correspondiente
    for (int i = 1; i <= n_pruebas; i++)
    {
        m += (VectorMarcas(n_pruebas, pruebas[i - 1]));
    }

    for (int i = 1; i <= n_pruebas; i++)
    {
        cout << m(i).GetNombre() << endl;
    }

    cout << "Inicio de la lectura de marcas" << endl;
    // while (strcmp(valor, "FIN")) {
    while (!cin.eof())
    {
        // Lectura de datos y creacion de objetos de RegistroDeMarca
        // Cada vez que creamos un objeto lo añadimos al vector de marcas de la prueba
        // que le corresponde
        cin >> valor;

        string tipo_prueba = valor;

        cin >> valor;
        Fecha fecha = Fecha(valor);

        cin >> valor;
        string licencia = valor;

        cin >> valor;
        Tiempo tiempo = Tiempo(valor);

        RegistroDeMarca registro(fecha, licencia, tiempo);

        for (int i = 1; i <= n_pruebas; i++)
            if (tipo_prueba == m[i].GetNombre())
            {
                // AniadeVectorMarcas(m[i], registro);
                m[i] += registro;
            }
    }

    cout << "Fin bucle" << endl;

    // Muestra del numero de prueba
    cout << "Numero de pruebas " << m.getNumPruebas() << endl
         << endl;

    // Muestra de los nombres de las pruebas
    cout << "Pruebas consideradas:" << endl;
    for (int i = 0; i < m.getNumPruebas(); i++)
    {
        cout << setw(4) << pruebas[i] << endl;
    }

    // Muestra del numero de marcas por prueba
    cout << "\nNumero de marcas por prueba:" << endl
         << endl;
    for (int i = 1; i <= m.getNumPruebas(); i++)
        cout << m[i].GetNombre() << "-->" << m[i].GetNum_marcas() << endl;

    cout << endl;

    // Muestra de las marcas ordenadas por tipo de prueba
    cout << "............................................" << endl;
    for (int i = 1; i <= m.getNumPruebas(); i++)
    {
        cout << endl
             << m[i].GetNombre() << ":" << endl;
        // ReajustaVectorMarcas(m[i]);
        // m[i].ReajustaVectorMarcas();
        for (int j = 1; j <= m[i].GetNum_marcas(); j++)
            cout << j + 1 << m[i](j).ToString() << endl;
    }
    cout << "............................................" << endl;

    /*
    cout<<"Ordenando por fecha...."<<endl;
    m.OrdenarPorFecha();
    //Muestra de las marcas ordenadas por tipo de prueba
    cout<<"............................................"<<endl;
    for(int i=0; i<m.getNumPruebas(); i++){
        cout<<endl<<m[i].GetNombre()<<":"<<endl;
        //ReajustaVectorMarcas(m[i]);
        //m[i].ReajustaVectorMarcas();
        for(int j=0; j<m[i].GetNum_marcas(); j++)
            cout<<j+1<<m[i].GetMarca(j).ToString()<<endl;
    }
    cout<<"............................................"<<endl;

    cout<<"Ordenando por tiempo...."<<endl;
    m.OrdenarPorTiempos();
    //Muestra de las marcas ordenadas por tipo de prueba
    cout<<"............................................"<<endl;
    for(int i=0; i<m.getNumPruebas(); i++){
        cout<<endl<<m[i].GetNombre()<<":"<<endl;
        //ReajustaVectorMarcas(m[i]);
        //m[i].ReajustaVectorMarcas();
        for(int j=0; j<m[i].GetNum_marcas(); j++)
            cout<<j+1<<m[i].GetMarca(j).ToString()<<endl;
    }
    cout<<"............................................"<<endl;

    cout<<"Ordenando por nombre...."<<endl;
    m.OrdenarPorNombre();
    //Muestra de las marcas ordenadas por tipo de prueba
    cout<<"............................................"<<endl;
    for(int i=0; i<m.getNumPruebas(); i++){
        cout<<endl<<m[i].GetNombre()<<":"<<endl;
        //ReajustaVectorMarcas(m[i]);
        //m[i].ReajustaVectorMarcas();
        for(int j=0; j<m[i].GetNum_marcas(); j++)
            cout<<j+1<<m[i].GetMarca(j).ToString()<<endl;
    }
    cout<<"............................................"<<endl;
    */

    cout << "\nTerminando programa y iberando memoria..." << endl;

    return 0;
}