/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// PABLO HUERTAS ARROYO
//
// Proyecto Gestion de marcas de atletismo
//
// Declaraci�n del tipo "MatrizMarcas"y de las funciones de gesti�n.
// Implementaciones en MatrizMarcas.cpp
//
//  
// Fichero: MatrizMarcas.h
//
/***************************************************************************/
/***************************************************************************/
#ifndef MATRIZMARCAS_H
#define MATRIZMARCAS_H

#include "RegistroDeMarca.h"
#include "VectorMarcas.h"
#include <string>
using namespace std;

class MatrizMarcas{
    private :
        
        int num_pruebas;
        int utilizados;
        VectorMarcas * pruebas;
        int capacidad;

    public :
    /*************************************************************************/
	/*************************************************************************/
    //Constructores

        /**
         * @brief Constructor sin parametros
         * Construye una matriz de marcas vacia
         */
        MatrizMarcas();
        
        /**
         * @brief Constructor con parametros
         * Construye una matriz de marcas con capacidad inicial n
         * @param n : capacidad inicial de la matriz
         */
        MatrizMarcas(int n);

        /**
         * @brief Constructor de copia
         * Construye una matriz de marcas a partir de otra
         * @param m : matriz de marcas a copiar
         */      
        MatrizMarcas(const MatrizMarcas & m);

        /**
         * @brief Constructor a partir de un fichero de marcas
         * Crea una matriz con las marcas del fichero
         * @param nombre_fichero : nombre del fichero de marcas
         */
        MatrizMarcas (const string & nombre_fichero);


        /**
         * @brief Destroy the Matriz Marcas object
         * Elimina la matriz de marcas
         */
        ~MatrizMarcas();
        
        /**
         * @brief Guarda un dato MatrizMarcas en un fichero de texto llamado nombre. El
            fichero será un fichero de marcas.
         * 
         * @param nombre_fichero : nombre del fichero a escribir 
         * @cond La matriz no se modifica
         * @cond Si la matriz es vacia no se crea el fichero
         */
        void EscribirMatrizMarcas(const string & nombre_fichero, bool txt=true)const;

        /**
         * @brief Guarda un dato MatrizMarcas en un fichero binario llamado nombre. El
            fichero será un fichero de marcas binario.
         * 
         * @param nombre : nombre del fichero a escribir
         * @cond La matriz no se modifica
         * @cond Si la matriz es vacia no se crea el fichero
         */
        void EscribirMatrizMarcasBin (const string & nombre) const;

        /**
         * @brief Guarda un dato MatrizMarcas en un fichero de texto llamado nombre. El
            fichero será un fichero de marcas.
         * 
         * @param nombre_fichero : nombre del fichero a escribir 
         * @cond La matriz no se modifica
         * @cond Si la matriz es vacia no se crea el fichero
         */   
        void EscribirMatrizMarcasTxt (const string & nombre) const;

        /**
         * @brief Lee una matriz de marcas desde un fichero de texto llamado nombre. El
            fichero será un fichero de marcas.
         * 
         * @param nombre_fichero : nombre del fichero a leer
         * @cond La matriz siempre se modifica
         * @cond Si el fichero no existe o no es de marcas se crea una matriz vacia
         */
        void LeerMatrizMarcas(const string & nombre_fichero, bool txt=true);

        /**
         * @brief Lee una matriz de marcas desde un fichero binario llamado nombre. El
            fichero será un fichero de marcas binario.
         * 
         * @param nombre : nombre del fichero a leer
         * @cond La matriz siempre se modifica
         * @cond Si el fichero no existe o no es de marcas se crea una matriz vacia
         */
        void LeerMatrizMarcasBin (const string & nombre);

        /**
         * @brief Lee una matriz de marcas desde un fichero de texto llamado nombre. El
            fichero será un fichero de marcas.
         * 
         * @param nombre_fichero : nombre del fichero a leer
         * @cond La matriz siempre se modifica
         * @cond Si el fichero no existe o no es de marcas se crea una matriz vacia
         */
        void LeerMatrizMarcasTxt(const string & nombre_fichero);




        /**
         * @brief Ordena las marcas de la matriz por tiempos 
         */
        void OrdenarPorTiempos();

        /**
         * @brief Ordena las marcas de la matriz por nombre de prueba
         */
        void OrdenarPorNombre();
        
        /**
         * @brief Ordena las marcas de la matriz por fecha
         */
        void OrdenarPorFecha();

        /**
         * @brief Elimina todos los datos de la matriz
         * 
         */
        void EliminaTodos();
        
        /*********************************************************************/
        /*********************************************************************/
        // Metodos de acceso Get y Set

        int getNumPruebas() const;
        void setNumPruebas(int n);

        /**
         * @brief Devuelve true si no tiene datos o false si tiene
         * 
         * @return true 
         * @return false 
         */
        bool EstaVacia() const;

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
        MatrizMarcas & operator=(const MatrizMarcas & m);



        /**
         * @brief Suma binaria de dos matrices
         * 
         * @param m1 : matriz de marcas a sumar
         * @param m2 : matriz de marcas a sumar
         * @return MatrizMarcas 
         */
        friend MatrizMarcas operator+(const MatrizMarcas & m1, 
        const MatrizMarcas & m2);

        // Suma binaria de una matriz con un vector

        /**
         * @brief Suma binaria de una matriz con un vector
         * 
         * @param m1 : matriz de marcas a sumar
         * @param v : vector de marcas a sumar
         * @return MatrizMarcas 
         */

        friend MatrizMarcas operator+(const MatrizMarcas & m, 
        const VectorMarcas & v);
        friend MatrizMarcas operator+(const VectorMarcas & v, 
        const MatrizMarcas & m);



        /**
         * @brief Resta binaria de matriz con un string
         * 
         * Elimina de la matriz todas las marcas cuyo campo licencia sea igual al valor dado.
         * 
         * @param m : matriz de marcas a modificar
         * @param n : licencia a eliminar
         * @return MatrizMarcas 
         */
        friend MatrizMarcas operator-(const MatrizMarcas & m, const string & n);



        /**
         * @brief Sobrecarga del operador +=
         * 
         * Suma a la matriz actual los datos de la matriz dada
         * 
         * @param m : matriz de marcas a sumar
         * @return MatrizMarcas& 
         */
        MatrizMarcas & operator +=(const MatrizMarcas & m);



        /**
         * @brief Sobrecarga del operador +=
         * 
         * Añade a la matriz actual el vector dado
         * 
         * @param v : vector de marcas a sumar
         * @return MatrizMarcas& 
         */
        MatrizMarcas & operator +=(const VectorMarcas & v);


        /**
         * @brief Sobrecarga del operador -=
         * 
         * Elimina de una copia del dato VectorMarca todas las marcas cuyo campo
         * licencia sea igual al valor dado.
         * 
         * @param n : licencia a eliminar
         * @return MatrizMarcas& 
         */
        MatrizMarcas & operator -=(const string & n);

        /**
         * @brief Devuelve el vector marcas en la posicion i
         * 
         * @param i : posicion del vector marcas a devolver
         * @return VectorMarcas 
         */
        VectorMarcas & operator()(int i);
        VectorMarcas operator()(int i) const;
        VectorMarcas & operator[](int i);
        VectorMarcas operator[](int i) const;
    

        /***************************************************************************/

        /**
         * @brief Sobrecarga del operador <<
         * 
         * @param os : flujo de salida
         * @param m : matriz de marcas a escribir
         * @return ostream& 
         */
        friend ostream & operator <<(ostream & os, const MatrizMarcas & m);

        /**
         * @brief Sobrecarga del operador >>
         * 
         * @param is : flujo de entrada
         * @param m : matriz de marcas a modificar
         * @return istream& 
         */
        friend istream & operator >>(istream & is, MatrizMarcas & m);
   

    private:
        /**
         * @brief Elimina todos los datos de la matriz
         * 
         */
        void LiberaMatrizMarcas();

        
        /**
         * @brief Reserva memoria para la matriz
         * 
         * @param n : tamano de la matriz
         */
        void ReservaMemoria(int n = TAM_INICIAL);

        // Devuelve el vector marcas en la posicion i
        /**
         * @brief Devuelve el vector marcas en la posicion i
         * 
         * @param i : posicion del vector marcas a devolver
         * @return VectorMarcas& 
         */
        VectorMarcas & Marcas(int i);

        /*********************************************************************/
        /*********************************************************************/
        
        /**
         * @brief Añade un vector de marcas a la matriz
         * 
         * @param v : vector de marcas a añadir
         */
        void AniadeVectorMarcas(VectorMarcas v);

        /**
         * @brief Aumenta el tamano y capacidad de la matriz
         * 
         */
        void RedimensionaMatrizMarcas();

};

#endif