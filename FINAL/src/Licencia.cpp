#include "Licencia.h"
#include <iostream>
#include <iomanip>
using namespace std;

/***********************************************************************/
// Constructor sin argumentos.
Licencia::Licencia()
{
    nombre = "";
}
/***********************************************************************/
// Constructor con un string.
Licencia::Licencia(const string nombre)
{
    this->nombre = nombre;
}
/***********************************************************************/
// Constructor con un char*.
Licencia::Licencia(const char *nombre)
{
    this->nombre = nombre;
}
/***********************************************************************/
// Constructor de copia.
Licencia::Licencia(const Licencia &l)
{
    *this = l;
}
/***********************************************************************/
// Destructor.
Licencia::~Licencia()
{
    // dtor
}
/***********************************************************************/
// Getters y Setters
string Licencia::GetNombre()
{
    return nombre;
}

void Licencia::SetNombre(string nombre)
{
    this->nombre = nombre;
}

int Licencia::size()
{
    return nombre.size();
}
/***********************************************************************/
// Devuelve el dato nombre en formato char*.
char *Licencia::ToChar() const
{
    return (char *)nombre.c_str();
}
/***********************************************************************/
// Sobrecarga del operador <<.
ostream &operator<<(ostream &os, const Licencia &l)
{
    os << l.nombre;
    return os;
}
/***********************************************************************/
// Sobrecarga del operador >>.
istream &operator>>(istream &is, Licencia &l)
{
    is >> l.nombre;
    return is;
}

/***********************************************************************/
// Sobrecarga del operador =.
Licencia &Licencia::operator=(const Licencia &l)
{
    this->nombre = l.nombre;
    return *this;
}
/***********************************************************************/
// Sobrecarga del operador ==.
bool Licencia::operator==(const Licencia &l)
{
    return (this->nombre == l.nombre);
}
/***********************************************************************/
// Sobrecarga del operador !=.
bool Licencia::operator!=(const Licencia &l)
{
    return !(*this == l);
}
/***********************************************************************/
// Sobrecarga del operador <.
bool Licencia::operator<(const Licencia &l)
{
    return (this->nombre < l.nombre);
}
/***********************************************************************/
// Sobrecarga del operador >.
bool Licencia::operator>(const Licencia &l)
{
    return (this->nombre > l.nombre);
}