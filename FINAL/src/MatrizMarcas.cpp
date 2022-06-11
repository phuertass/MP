/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Proyecto Gestion de marcas de atletismo
//
// Implementacion del tipo "MatrizMarcas"y de las funciones de gesti�n.
//
// Cabecera del fichero: MatrizMarcas.h
//
// Fichero: MatrizMarcas.cpp
//
/***************************************************************************/
/***************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>

#include "MatrizMarcas.h"

using namespace std;

/*************************************************************************/
/*************************************************************************/
// Constructores
/*************************************************************************/
/*************************************************************************/

/**
 * @brief Constructor sin parametros
 * Construye una matriz de marcas vacia
 */
MatrizMarcas ::MatrizMarcas()
{
    utilizados = 0;
    pruebas = nullptr;
    capacidad = 0;
}

/**
 * @brief Constructor con parametros
 * Construye una matriz de marcas con capacidad inicial n
 * @param n : capacidad inicial de la matriz
 */

MatrizMarcas::MatrizMarcas(int n)
{
    utilizados = 0;
    capacidad = n;
    ReservaMemoria(n);
}

/**
 * @brief Constructor de copia
 * Construye una matriz de marcas a partir de otra
 * @param m : matriz de marcas a copiar
 */
MatrizMarcas::MatrizMarcas(const MatrizMarcas &m)
{
    *this = m;
}

/**
 * @brief Constructor a partir de un fichero de marcas
 * Crea una matriz con las marcas del fichero
 * @param nombre_fichero : nombre del fichero de marcas
 */
MatrizMarcas ::MatrizMarcas(const string &nombre_fichero)
{
    utilizados = 0;
    pruebas = nullptr;
    capacidad = 0;
    if (!ExisteFichero(nombre_fichero))
    {
        cout << "No existe el fichero " << nombre_fichero << endl;
        exit(1);
    }

    if (EsFicheroBin(nombre_fichero))
    {
        cout << "El fichero " << nombre_fichero << " es binario" << endl;
        LeerMatrizMarcas(nombre_fichero, false);
    }
    else if (EsFicheroTxt(nombre_fichero))
    {
        cout << "El fichero " << nombre_fichero << " es texto" << endl;
        LeerMatrizMarcasTxt(nombre_fichero);
    }
}

/**
 * @brief Destroy the Matriz Marcas object
 * Elimina la matriz de marcas
 */

MatrizMarcas::~MatrizMarcas()
{
    LiberaMatrizMarcas();
}

/**
 * @brief Funcion inline que formatea la salida de los registros de forma
 * que sea legible por otras matrices
 *
 * @param os : flujo de salida
 * @param r : registro a formatear
 * @return ostream&
 */
inline ostream &SalidaFormatRegistro(ostream &os, const RegistroDeMarca &r)
{
    Fecha f = r.GetFecha();
    int dia = f.GetDia();
    int mes = f.GetMes();
    int anio = f.GetAnio();

    string diad = to_string(dia);
    string mesd = to_string(mes);
    string aniod = to_string(anio);

    os << setfill('0') << setw(2) << diad << "/";
    os << setfill('0') << setw(2) << mesd << "/";
    os << setfill('0') << setw(4) << aniod << "\t";

    os << r.GetLicencia() << "\t";
    Tiempo t = r.GetTiempo();
    os << t << endl;
    return os;
}

inline ostream &FormatFecha(ostream &os, const Fecha &f)
{
    int dia = f.GetDia();
    int mes = f.GetMes();
    int anio = f.GetAnio();

    string diad = to_string(dia);
    string mesd = to_string(mes);
    string aniod = to_string(anio);

    os << setfill('0') << setw(2) << diad << "/";
    os << setfill('0') << setw(2) << mesd << "/";
    os << setfill('0') << setw(4) << aniod << "\t";

    return os;
}

/**
 * @brief Guarda un dato MatrizMarcas en un fichero de texto llamado nombre. El
    fichero será un fichero de marcas.
    *
    * @param nombre_fichero : nombre del fichero a escribir
    * @cond La matriz no se modifica
    * @cond Si la matriz es vacia no se crea el fichero
    */

void MatrizMarcas::EscribirMatrizMarcas(const string &nombre_fichero, bool txt) const
{
    if (txt)
        EscribirMatrizMarcasTxt(nombre_fichero);
    else if (!txt)
        EscribirMatrizMarcasBin(nombre_fichero);
}

/**
 * @brief Guarda un dato MatrizMarcas en un fichero binario llamado nombre. El
    fichero será un fichero de marcas binario.
 *
 * @param nombre : nombre del fichero a escribir
 * @cond La matriz no se modifica
 * @cond Si la matriz es vacia no se crea el fichero
 */
void MatrizMarcas::EscribirMatrizMarcasBin(const string &nombre) const
{
    cout << "\nESCRITURA BINARIA" << endl;

    ofstream fo;
    fo.open(nombre, ios::binary);
    if (!fo)
    {
        cout << "No se puede abrir el fichero " << nombre << endl;
        exit(1);
    }

    char *cad = (char*)"MARCAS_BIN\n";
    fo.write(cad, strlen(cad));

    // cad = "# Comentario escrito desde la clase MatrizMarcas\n";
    // fo.write(cad, strlen(cad));
    int num_marcas = this->getNumPruebas();
    fo.write((char *)&num_marcas, sizeof(int));

    for (int i = 0; i < getNumPruebas(); i++)
    {
        string nombre_prueba = pruebas[i].GetNombre();
        int tam_prueba = nombre_prueba.size();
        fo.write((char *)&tam_prueba, sizeof(int));
        fo.write((const char *)nombre_prueba.c_str(), nombre_prueba.length());
    }

    for (int i = 0; i < getNumPruebas(); i++)
    {
        for (int j = 1; j <= this->pruebas[i].GetNum_marcas(); j++)
        {
            string nombre_prueba = pruebas[i].GetNombre();
            int tam_prueba = nombre_prueba.size();
            fo.write((char *)&tam_prueba, sizeof(int));
            // cout << "Nombre de marca es " << nombre_prueba << endl;
            fo.write((const char *)nombre_prueba.c_str(), nombre_prueba.length());

            RegistroDeMarca r = this->pruebas[i][j];
            Fecha f = r.GetFecha();
            string licencia = r.GetLicencia();
            int sizelicencia = licencia.size();
            // cout << licencia << " SIZE " << sizelicencia << endl;

            const char *licenciac = licencia.c_str();
            // cout << licenciac << " " << strlen(licenciac) << endl;
            Tiempo t = r.GetTiempo();

            // Debemos escribir la fecha con el formato de dia/mes/anio
            // std::stringstream ss;
            // FormatFecha(ss, f);
            // string fecha = ss.str();

            // Escribo la fecha
            fo.write((char *)&f, sizeof(Fecha));
            fo.write((char *)&sizelicencia, sizeof(int));
            fo.write(licenciac, sizelicencia);
            // fo.write((char *)&licencia, sizeof(string));
            fo.write((char *)&t, sizeof(Tiempo));
        }
    }

    fo.close();
};

/**
 * @brief Guarda un dato MatrizMarcas en un fichero de texto llamado nombre. El
    fichero será un fichero de marcas.
 *
 * @param nombre_fichero : nombre del fichero a escribir
 * @cond La matriz no se modifica
 * @cond Si la matriz es vacia no se crea el fichero
 */
void MatrizMarcas::EscribirMatrizMarcasTxt(const string &nombre) const
{
    ofstream fo;
    fo.open(nombre);
    if (!fo)
    {
        cout << "No se puede abrir el fichero " << nombre << endl;
        exit(1);
    }
    fo << *this;

    fo.close();
};

/**
* @brief Lee una matriz de marcas desde un fichero de texto llamado nombre. El
fichero será un fichero de marcas.
*
* @param nombre_fichero
* @cond La matriz siempre se modifica
* @cond Si el fichero no existe o no es de marcas se crea una matriz vacia
*/
void MatrizMarcas::LeerMatrizMarcas(const string &nombre_fichero, bool txt)
{
    // Para el fichero proporcionado debe comprobar si es un fichero de tipo
    // binario o de formato txt

    // Si es de tipo txt llamamos a la funcion que lee la matriz marcas desde
    // un fichero de texto
    if (EsFicheroTxt(nombre_fichero))
        LeerMatrizMarcasTxt(nombre_fichero);
    // Si no, llamamos a la funcion que lee la matriz marcas desde un fichero
    // binario
    else if (EsFicheroBin(nombre_fichero))
        LeerMatrizMarcasBin(nombre_fichero);
}

/**
 * @brief Lee una matriz de marcas desde un fichero binario llamado nombre. El
    fichero será un fichero de marcas binario.
 *
 * @param nombre : nombre del fichero a leer
 * @cond La matriz siempre se modifica
 * @cond Si el fichero no existe o no es de marcas se crea una matriz vacia
 */
void MatrizMarcas::LeerMatrizMarcasBin(const string &nombre)
{
    // Buffer donde se van a almacenar los datos leidos del fichero
    const int TAM_BUFFER = 1024;
    char buffer[TAM_BUFFER];

    LiberaMatrizMarcas();

    // Apertura del fichero de marcas binario
    ifstream fi;
    fi.open(nombre, ios::binary);

    cout.setf(ios::fixed, ios::showpoint);

    // cout << "Iniciando lectura de fichero binario " << nombre << endl;

    // Lectura de la cabecera del fichero de marcas binario
    string cabecera;
    getline(fi, cabecera);
    // cout << "Cabecera: " << cabecera << endl;
    //  Ignoramos los comentarios que pueda tener el fichero
    while (fi.peek() == '#')
        fi.ignore();
    // Lectura del numero de pruebas del fichero
    int num_pruebas;
    fi.read(buffer, sizeof(int));
    num_pruebas = *(int *)buffer;

    cout << "Numero de pruebas: " << num_pruebas << endl;
    cout << "-----------------------------------------------------" << endl;

    // Reservamos memoria para la matriz de marcas
    capacidad = num_pruebas;
    ReservaMemoria(capacidad);

    //  Leemos los nombres de cada una de las pruebas
    string nombre_pruebas[num_pruebas];

    for (int i = 0, numero = 0; i < num_pruebas; i++)
    {
        // Leemos la cantidad de char que contiene el nombre de la prueba para
        // su posterior lectura
        fi.read(buffer, sizeof(int));
        numero = *(int *)buffer;
        // Leemos el nombre de la prueba que tiene una cantidad de bytes
        // de numero*sizeof(char)
        fi.read(buffer, sizeof(char) * numero);
        buffer[numero] = '\0';
        string buffereado = string(buffer);
        // cout << "TAMAÑO ESPERADO: " << numero << endl;
        // cout << "SIZE BUFFEREADO: " << buffereado.size() << endl;

        // while (buffereado.size() > numero)
        //     buffereado.pop_back();

        // cout << "SIZE BUFFEREADO: " << buffereado.size() << endl;
        nombre_pruebas[i] = buffereado;
        // nombre_pruebas[i] = string(buffer);
        cout << "Nombre de la prueba " << i + 1 << ": " << nombre_pruebas[i] << endl;

        *this += (VectorMarcas(0, nombre_pruebas[i]));
    }

    cout << "-----------------------------------------------------" << endl;

    // Mientras el elemento que se vaya a leer no sea el final de fichero
    // leemos la marca
    while (fi.peek() != EOF)
    {
        // Lectura del numero de marcas de la prueba
        int tamanio;
        // Lectura del tamano del nombre de la prueba
        fi.read(buffer, sizeof(int));
        tamanio = *(int *)buffer;
        // cout << "\nTamano del nombre de la prueba: " << tamanio << endl;

        // Lectura del nombre de la prueba
        fi.read(buffer, sizeof(char) * (tamanio));
        buffer[tamanio] = '\0';
        string nombre_prueba = string(buffer);
        // while (nombre_prueba.size() > tamanio)
        //     nombre_prueba.pop_back();

        // cout << "Nombre de la prueba arreglado: " << nombre_prueba << endl;

        Fecha f;
        fi.read(reinterpret_cast<char *>(&f), sizeof(Fecha));
        // cout << "Fecha: " << f << endl;

        // Lectura del tamaño de la licencia a leer
        fi.read(buffer, sizeof(int));
        tamanio = *(int *)buffer;
        // cout << "Tamano de la licencia: " << tamanio << endl;
        //   Lectura de la licencia
        fi.read(buffer, sizeof(char) * tamanio);
        buffer[tamanio] = '\0';
        string licencia = string(buffer);
        // cout << "Licencia: " << licencia << endl;
        // while (licencia.size() > tamanio)
        //    licencia.pop_back();
        // cout << "Licencia leida arreglada: " << licencia << endl;

        // Lectura del tiempo
        Tiempo t;
        fi.read(reinterpret_cast<char *>(&t), sizeof(Tiempo));
        // cout << "Tiempo: " << t << endl;

        RegistroDeMarca r(f, licencia, t);
        // cout << "Registro de marca leido: " << r << endl;

        for (int i = 0; i < num_pruebas; i++)
            if (nombre_prueba == this->pruebas[i].GetNombre())
                this->pruebas[i] += r;

        // cout << "-----------------------------------------------------" << endl;
    }

    fi.close();
};

/**
 * @brief Lee una matriz de marcas desde un fichero de texto llamado nombre. El
    fichero será un fichero de marcas.
 *
 * @param nombre_fichero : nombre del fichero a leer
 * @cond La matriz siempre se modifica
 * @cond Si el fichero no existe o no es de marcas se crea una matriz vacia
 */
void MatrizMarcas::LeerMatrizMarcasTxt(const string &nombre_fichero)
{

    ifstream fi(nombre_fichero);
    if (!ExisteFichero(nombre_fichero))
    {
        cout << "No existe el fichero " << nombre_fichero << endl;
        exit(1);
    }

    if (fi.peek() != 'M')
    {
        cout << "El fichero no es de marcas" << endl;
        exit(1);
    }

    string cabecera;
    // Lee fichero de marcas
    fi >> cabecera;
    fi.ignore(1000, '\n');

    //cabecera = "";
    //while (cabecera[0] == '#' or cabecera.length() == 0)
    //{
    //    getline(fi, cabecera);
    //    if (cabecera[0] != '#')
    //        break;
    //}

    while(fi.peek() == '#' or fi.peek() == '\n' or fi.peek() == ' ')
        fi.ignore(1000, '\n');

    // fi >> *this;

    int n;
    fi >> n;
    //  Vector de string para almacenar los nombres de las pruebas
    string pruebas[n];

    for (int i = 0; i < n; i++)
    {
        fi >> pruebas[i];
    }

    LiberaMatrizMarcas();
    ReservaMemoria(n);
    capacidad = n;
    utilizados = 0;

    for (int i = 1; i <= n; i++)
        *this += (VectorMarcas(n, pruebas[i - 1]));

    int TAM_CAD = 100;
    char valor[TAM_CAD];

    while (!fi.eof())
    {

        // Lectura de datos y creacion de objetos de RegistroDeMarca
        // Cada vez que creamos un objeto lo añadimos al vector de marcas de la prueba
        // que le corresponde
        fi >> valor;

        string tipo_prueba = valor;

        // Si el ultimo elemento leido no es un tiempo
        if (tipo_prueba.length() < 7)
        {
            fi >> valor;
            Fecha fecha = Fecha(valor);

            fi >> valor;
            string licencia = valor;

            fi >> valor;
            Tiempo tiempo = Tiempo(valor);

            RegistroDeMarca registro(fecha, licencia, tiempo);

            for (int i = 1; i <= n; i++)
            {
                if (tipo_prueba == this->pruebas[i - 1].GetNombre())
                {
                    this->pruebas[i - 1] += registro;
                }
            }
        }
    }

    return;
};

// Funciones de ordenacion

/**
 * @brief Ordena las marcas de la matriz por tiempos
 */
void MatrizMarcas::OrdenarPorTiempos(const bool asc, int inicio, int fin)
{
    if(inicio<0 or inicio>utilizados or fin<0 or fin>utilizados or inicio>fin)
    {
        cout << "NUMERO DE PRUEBAS: " << num_pruebas << endl;
        cout << "Error en la ordenacion" << endl;
        exit(1);
    }
    // Swap
    if(inicio > fin)
    {
        int aux = inicio;
        inicio = fin;
        fin = aux;
    }
    for (int i = inicio; i < fin; i++)
    {
        pruebas[i].OrdenarPorTiempos(asc);
    }
}

/**
 * @brief Ordena las marcas de la matriz por nombre
 * Parametros: int inicio, int fin : intervalo de ordenacion
 * asc = true se ordena ascendentemente, false descendentemente
 * Por defecto se ordena ascendentemente
 */

void MatrizMarcas::OrdenarPorNombre(const bool asc, int inicio, int fin)
{
    if(inicio<0 or inicio>utilizados or fin<0 or fin>utilizados or inicio>fin)
    {
        cout << "NUMERO DE PRUEBAS: " << num_pruebas << endl;
        cout << "Error en la ordenacion" << endl;
        exit(1);
    }
    // Swap
    if(inicio > fin)
    {
        int aux = inicio;
        inicio = fin;
        fin = aux;
    }
    for (int i = inicio; i < fin; i++)
    {
        pruebas[i].OrdenarPorNombre(asc);
    }
    

}

/**
 * @brief Ordena las marcas de la matriz por fecha
 */

void MatrizMarcas::OrdenarPorFecha(const bool asc, int inicio, int fin)
{
    if(inicio<0 or inicio>utilizados or fin<0 or fin>utilizados or inicio>fin)
    {
        cout << "NUMERO DE PRUEBAS: " << num_pruebas << endl;
        cout << "Error en la ordenacion" << endl;
        exit(1);
    }
    // Swap
    if(inicio > fin)
    {
        int aux = inicio;
        inicio = fin;
        fin = aux;
    }
    for (int i = inicio; i < fin; i++)
    {
        pruebas[i].OrdenarPorFecha(asc);
    }
}

/**
 * @brief Elimina todos los datos de la matriz
 *
 */

void MatrizMarcas::EliminaTodos()
{
    this->utilizados = 0;
}

/*********************************************************************/
/*********************************************************************/
// Metodos de acceso Get y Set

int MatrizMarcas::getNumPruebas() const
{
    return utilizados;
}

void MatrizMarcas::setNumPruebas(int n)
{
    utilizados = n;
}

int MatrizMarcas::getCapacidad() const
{
    return capacidad;
}

int MatrizMarcas::NumFilas() const
{
    return utilizados;
}



/**
 * @brief Devuelve true si no tiene datos o false si tiene
 *
 * @return true
 * @return false
 */

bool MatrizMarcas::EstaVacia() const
{
    return (utilizados == 0);
}

/***************************************************************************/
/***************************************************************************/
// Sobrecarga de operadores
/***************************************************************************/
/***************************************************************************/

/**
 * @brief Sobrecarga del operador asignacion
 *
 * @param m : matriz de marcas a copiar
 * @return MatrizMarcas&
 */

MatrizMarcas &MatrizMarcas::operator=(const MatrizMarcas &m)
{
    if (this != &m)
    {
        utilizados = m.utilizados;
        capacidad = m.capacidad;
        ReservaMemoria(capacidad);
        for (int i = 0; i < utilizados; i++)
            pruebas[i] = m.pruebas[i];
    }
    return *this;
}

/**
 * @brief Suma binaria de dos matrices
 *
 * @param m1 : matriz de marcas a sumar
 * @param m2 : matriz de marcas a sumar
 * @return MatrizMarcas
 */
MatrizMarcas operator+(const MatrizMarcas &m1, const MatrizMarcas &m2)
{
    MatrizMarcas m3(m1);
    for (int i = 0; i < m3.utilizados; i++)
    {
        for (int j = 0; j < m2.utilizados; j++)
        {

            string nombre1 = m3.pruebas[i].GetNombre();
            string nombre2 = m2.pruebas[j].GetNombre();

            // cout << "nombre1: " << nombre1 << endl;
            // cout << "nombre2: " << nombre2 << endl;

            bool iguales = nombre1 == nombre2;
            //(iguales) ? cout << "son iguales" << endl : cout << "no son iguales" << endl;

            if (iguales)
            {

                VectorMarcas v1 = m3.pruebas[i];
                VectorMarcas v2 = m2.pruebas[j];

                // cout << "v1: " << v1 << endl;
                // cout << "v2: " << v2 << endl;

                VectorMarcas v3 = v1 + v2;
                // cout << "v3: " << v3 << endl;

                v3.SetNombre(nombre1);
                m3.pruebas[i] = v3;

                // cout << "MATRIZ AFTER: " << m3 << endl;
            }
        }
    }
    return m3;
}

/**
 * @brief Suma binaria de una matriz con un vector
 *
 * @param m1 : matriz de marcas a sumar
 * @param v : vector de marcas a sumar
 * @return MatrizMarcas
 */
MatrizMarcas operator+(const MatrizMarcas &m, const VectorMarcas &v)
{
    MatrizMarcas m2(m);
    m2.AniadeVectorMarcas(v);
    return m2;
}
MatrizMarcas operator+(const VectorMarcas &v, const MatrizMarcas &m)
{
    MatrizMarcas m2(m);
    m2.AniadeVectorMarcas(v);
    return m2;
}

/**
 * @brief Resta binaria de matriz con un string
 *
 * Elimina de la matriz todas las marcas cuyo campo licencia sea igual al valor dado.
 *
 * @param m : matriz de marcas a modificar
 * @param n : licencia a eliminar
 * @return MatrizMarcas
 */
MatrizMarcas operator-(const MatrizMarcas &m, const string &n)
{
    MatrizMarcas m2(m.utilizados - 1);
    // Recorrer todos los vectores para eliminar la licencia que coincide
    for (int i = 0; i < m.utilizados; i++)
    {
        VectorMarcas v = m.pruebas[i];
        v -= n;
        m2.AniadeVectorMarcas(v);
    }
    return m2;
}

/**
 * @brief Sobrecarga del operador +=
 *
 * Suma a la matriz actual los datos de la matriz dada
 *
 * @param m : matriz de marcas a sumar
 * @return MatrizMarcas&
 */
MatrizMarcas &MatrizMarcas::operator+=(const MatrizMarcas &m)
{
    for (int i = 0; i < m.utilizados; i++)
    {
        AniadeVectorMarcas(m.pruebas[i]);
    }
    return *this;
}

/**
 * @brief Sobrecarga del operador +=
 *
 * Añade a la matriz actual el vector dado
 *
 * @param v : vector de marcas a sumar
 * @return MatrizMarcas&
 */

MatrizMarcas &MatrizMarcas::operator+=(const VectorMarcas &v)
{
    AniadeVectorMarcas(v);
    return *this;
}

/**
 * @brief Sobrecarga del operador -=
 *
 * Elimina de una copia del dato VectorMarca todas las marcas cuyo campo
 * licencia sea igual al valor dado.
 *
 * @param n : licencia a eliminar
 * @return MatrizMarcas&
 */

MatrizMarcas &MatrizMarcas::operator-=(const string &n)
{
    for (int i = 0; i < utilizados; i++)
    {
        pruebas[i] -= n;
    }
    return *this;
}

/**
 * @brief Devuelve el vector marcas en la posicion i
 *
 * @param i : posicion del vector marcas a devolver
 * @return VectorMarcas
 */
VectorMarcas &MatrizMarcas::operator()(int i)
{
    return pruebas[i - 1];
}

VectorMarcas &MatrizMarcas::operator[](int i)
{
    return pruebas[i - 1];
}

VectorMarcas MatrizMarcas::operator()(int i) const
{
    return pruebas[i - 1];
}

VectorMarcas MatrizMarcas::operator[](int i) const
{
    return pruebas[i - 1];
}

/**
 * @brief Sobrecarga del operador <<
 *
 * @param os : flujo de salida
 * @param m : matriz de marcas a escribir
 * @return ostream&
 */
ostream &operator<<(ostream &os, const MatrizMarcas &m)
{
    os << "MARCAS" << endl;

    os << "# SALIDA DESDE LA CLASE MATRIZ MARCAS " << endl
       << endl;

    os << m.getNumPruebas() << " ";

    for (int i = 1; i <= m.getNumPruebas(); i++)
    {
        os << m(i).GetNombre() << " ";
    }

    os << endl
       << endl;

    for (int i = 1; i <= m.getNumPruebas(); i++)
    {
        for (int j = 1; j <= m(i).GetNum_marcas(); j++)
        {
            os << m(i).GetNombre() << " ";
            RegistroDeMarca r = m(i)(j);
            SalidaFormatRegistro(os, r);
        }
    }

    return os;
}

/**
 * @brief Sobrecarga del operador >>
 *
 * @param is : flujo de entrada
 * @param m : matriz de marcas a modificar
 * @return istream&
 */
istream &operator>>(istream &is, MatrizMarcas &m)
{
    int n;
    is >> n;
    // cout << "n es " << n << endl;
    //  Vector de string para almacenar los nombres de las pruebas
    string pruebas[n];

    for (int i = 0; i < n; i++)
    {
        is >> pruebas[i];
    }

    m.EliminaTodos();
    m.ReservaMemoria();
    m.utilizados = 0;

    for (int i = 1; i <= n; i++)
        m += (VectorMarcas(n, pruebas[i - 1]));

    int TAM_CAD = 100;
    char valor[TAM_CAD];

    while (!is.eof())
    {

        // Lectura de datos y creacion de objetos de RegistroDeMarca
        // Cada vez que creamos un objeto lo añadimos al vector de marcas de la prueba
        // que le corresponde
        is >> valor;

        string tipo_prueba = valor;

        // Si el ultimo elemento leido no es un tiempo
        if (tipo_prueba.length() < 7)
        {
            is >> valor;
            Fecha fecha = Fecha(valor);

            is >> valor;
            string licencia = valor;

            is >> valor;
            Tiempo tiempo = Tiempo(valor);

            RegistroDeMarca registro(fecha, licencia, tiempo);

            for (int i = 1; i <= n; i++)
            {
                if (tipo_prueba == m[i].GetNombre())
                {
                    m[i] += registro;
                }
            }
        }
    }
    return is;
}

/***************************************************************************/
/***************************************************************************/
// METODOS PRIVADOS
/***************************************************************************/
/***************************************************************************/

/**
 * @brief Elimina todos los datos de la matriz
 *
 */
void MatrizMarcas::LiberaMatrizMarcas()
{
    if (pruebas != nullptr)
    {
        delete[] pruebas;
        pruebas = NULL;
        utilizados = 0;
        capacidad = 0;
        num_pruebas = 0;
    }
}
/**
 * @brief Reserva memoria para la matriz
 *
 * @param n : tamano de la matriz
 */

void MatrizMarcas::ReservaMemoria(int n)
{
    capacidad = n;
    pruebas = new VectorMarcas[n];
}

// Devuelve el vector marcas en la posicion i
/**
 * @brief Devuelve el vector marcas en la posicion i
 *
 * @param i : posicion del vector marcas a devolver
 * @return VectorMarcas&
 */
VectorMarcas &MatrizMarcas::Marcas(int i)
{
    return pruebas[i];
}

/**
 * @brief Añade un vector de marcas a la matriz
 *
 * @param v : vector de marcas a añadir
 */
void MatrizMarcas ::AniadeVectorMarcas(const VectorMarcas v)
{
    // cout << "Utilizados: " << utilizados << endl;
    // cout << "Capacidad: " << capacidad << endl;
    if (utilizados == capacidad)
    {
        // cout << "Redimensionando Matriz" << endl;
        //  Redimensionar
        RedimensionaMatrizMarcas();
    }
    pruebas[utilizados] = v;
    utilizados++;
}

/**
 * @brief Aumenta el tamano y capacidad de la matriz
 *
 */
void MatrizMarcas::RedimensionaMatrizMarcas()
{
    int nueva_capacidad = capacidad * 2;

    // cout << "Redimensionando matriz marcas hasta " << nueva_capacidad << endl;

    VectorMarcas *tmp = new VectorMarcas[nueva_capacidad];

    for (int i = 0; i < utilizados; i++)
    {
        tmp[i] = pruebas[i];
    }

    delete[] pruebas;

    pruebas = tmp;
    capacidad = nueva_capacidad;
}
