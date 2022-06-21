#include "SecuenciaEnteros.h"
#include <iostream>

/*******************************************************/
// Construye una secuencia con "n_datos" valores
// PRE: 0 <= n_datos <= TAMANIO
// PRE: A partir de "p" hay "n_datos" valores
SecuenciaEnteros::SecuenciaEnteros (int * p, int n_datos){
    total_utilizados=0;
    int * p_ref = p;
    for(int i=0; i<n_datos; i++, p_ref++, total_utilizados++){
        vector_privado[i] = *p_ref;
    }
};

/*******************************************************/
// Construye una secuencia con "n_datos" valores iguales
// PRE: 0 <= n_datos <= TAMANIO
SecuenciaEnteros::SecuenciaEnteros (int n_datos, int valor){
    total_utilizados=0;
    for(int i=0; i<n_datos;i++,total_utilizados++)
        vector_privado[i] = valor;
};

/*******************************************************/
// Construye una secuencia con "n_datos" valores aleatorios
// PRE: 0 <= n_datos <= TAMANIO
SecuenciaEnteros::SecuenciaEnteros (int n_datos, int min_aleat, int max_aleat){
    total_utilizados=0;
    GeneradorAleatorioEnteros generador(min_aleat, max_aleat);

    for(int i=0; i<n_datos; i++,total_utilizados++){
        vector_privado[i] = generador.Siguiente(); 
    }

};

int SecuenciaEnteros::TotalUtilizados(){
    return total_utilizados;
};

int SecuenciaEnteros::Capacidad(){
    return TAMANIO;
};

void SecuenciaEnteros::Aniade (int nuevo)
{
    if (total_utilizados < TAMANIO){
        vector_privado[total_utilizados] = nuevo;
        total_utilizados++;
    }
}

int SecuenciaEnteros::Elemento(int indice)
{
    return (vector_privado[indice]);
};

void SecuenciaEnteros::Elimina(int indice)
{
    if ((indice >= 0) && (indice < total_utilizados)) {

        int tope = total_utilizados-1; // posic. del último
        
        int num_bytes = sizeof(int)*(total_utilizados-indice);

        memmove(vector_privado+indice-1, vector_privado+indice, num_bytes);

        total_utilizados--;
    }
}

void SecuenciaEnteros::Inserta(int indice, int valor)
{
    total_utilizados++;

    int num_bytes = sizeof(int)*(total_utilizados-indice);

    memmove(vector_privado+indice, vector_privado+indice-1, num_bytes);

    vector_privado[indice] = valor; 
};

int & SecuenciaEnteros::Valor(int indice){
    return vector_privado[indice];
}

bool SecuenciaEnteros::EsIgualA(const SecuenciaEnteros & otra)
{
    bool salida = true;
    if(total_utilizados == otra.total_utilizados)
    {
        for(int i=0; i<total_utilizados; i++){
            if(vector_privado[i] != otra.vector_privado[i]){
                return false;
            }
        }
    }
    return salida;
}

string SecuenciaEnteros::ToString()
{
    string cadena = "{";

    if (total_utilizados > 0) {

        for (int i=0; i<total_utilizados-1; i++)

            cadena = cadena + to_string(vector_privado[i])+", ";

        // Añadie el último seguido de '}'
        cadena = cadena + to_string(vector_privado[total_utilizados-1]);
    }

    cadena = cadena + "}";

    return (cadena);
}