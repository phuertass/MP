#ifndef LICENCIA_H
#define LICENCIA_H

#include "utils.h"
#include <string>

using namespace std;

class Licencia {
    private:
        string nombre;
    public:

        /***********************************************************************/
        // Constructor sin argumentos.
        Licencia();

        /***********************************************************************/
        // Constructor con un string.
        Licencia(const string nombre);

        /***********************************************************************/
        // Constructor con un char*.
        Licencia(const char* nombre);

        /***********************************************************************/
        // Constructor de copia.
        Licencia(const Licencia& l);

        /***********************************************************************/
        // Destructor.
        ~Licencia();

        /***********************************************************************/
        // Getters y Setters.
        string GetNombre();
        void SetNombre(string nombre);
        int size();

        /***********************************************************************/
        // Devuelve el dato nombre en formato char*.
        char * ToChar() const;

        /***********************************************************************/
        // Sobrecarga del operador <<.
        friend ostream & operator << (ostream & os, const Licencia & l);
        
        /***********************************************************************/
        // Sobrecarga del operador >>.
        friend istream & operator >> (istream & is, Licencia & l);

        /***********************************************************************/
        // Sobrecarga del operador =.
        Licencia & operator = (const Licencia & l);
        
        /***********************************************************************/
        // Sobrecarga del operador ==.
        bool operator == (const Licencia & l);

        /***********************************************************************/
        // Sobrecarga del operador !=.
        bool operator != (const Licencia & l);

        /***********************************************************************/
        // Sobrecarga del operador <.
        bool operator < (const Licencia & l);

        /***********************************************************************/
        // Sobrecarga del operador >.
        bool operator > (const Licencia & l);
};

#endif // LICENCIA_H