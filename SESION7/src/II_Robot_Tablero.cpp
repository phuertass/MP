#include <cstring>
#include <string>
#include <iostream>
#include "Matriz2D.h"
#include "FuncsVectorDinamico.h"

using namespace std;

typedef struct{
    int fila;
    int columna;
} Posicion;


int main(){
    char opcion='S';

    while(toupper(opcion)=='S')
    {
    int filas;
    int cols;
    cout<<"\nIntroduzca el numero de filas-->";
    cin >> filas;
    cout<<"\nIntroduzca el numero de columnas-->";
    cin >> cols;

    Matriz2D tablero = CreaMatriz(filas, cols);
    cout<<ToString(tablero);
    cout<<"\nCREANDO TABLERO DE "<<filas<<" FILAS Y "<<cols<<" COLUMNAS"<<endl;
    cout<<"\n------------------------------------------------------------\n";

    VectorDinamico v = CreaVectorDinamico();

    int fila_inic, col_inic;
    cout<<"\nIntroduzca la posicion inicial(fila)-->";
    cin>>fila_inic;
    cout<<"\nIntroduzca la posicion inicial(columna)-->";
    cin>>col_inic;
    cout<<"\nSe creara un robot en la posicion("<<fila_inic<<","<<col_inic<<")"
    <<endl;
    // ......................................................................
	// Leer valores y guardarlos en el vector din�mico. 
	// Se redimensiona cuando no hay espacio para un nuevo dato. 

	// Primera lectura - lectura adelantada
    char valor='C';
    int salto;
    int contador=0;
    while(valor!='F')
    {
        //cout << "Introducir orden ('F' para finalizar):-->"; 
        cin>>valor;
        if(valor!='F')
        {
            //cout<<"Introducir el salto-->";
            cin>>salto;
            if(salto>0)
            {
                Orden orden;
                orden.salto=salto;
                switch(valor)
                {
                    case('I') : 
                        orden.tipo = TipoMovimiento::I;
                        break;
                    case('A') : 
                        orden.tipo = TipoMovimiento::A;
                        break;
                    case('D') :
                        orden.tipo = TipoMovimiento::D;
                        break;
                    case('B') :
                        orden.tipo = TipoMovimiento::B;
                        break;
                }
                //cout<<"\nCreando objeto orden con tipo: "<<valor<<" y salto: "
                //<<salto;
                cout<<"\nOrden "<<contador<<": "<<valor<<" "<<salto;
                cout<<endl;
                contador++;
                AniadeVectorDinamico(v, orden);
            }
            
        }     
    }

    //cout<<"\n\n"<<v.usados<<endl;

    Posicion pos;
    pos.columna=fila_inic;
    pos.fila=col_inic;

    Orden * p = v.datos;
    int salto_compr = 0;
    //Comprobamos si es correcta la secuencia
    bool correcta = true;
    contador=0;
    tablero.datos[pos.fila][pos.columna]+=1;
    for(int i=0; i<v.usados && correcta; i++)
    {
        salto_compr = p[i].salto;
        switch (p[i].tipo)
        {
            case TipoMovimiento::I : 
                pos.columna-=salto_compr;
                break;
            case TipoMovimiento::A :
                pos.fila-=salto_compr;
                break;
            case TipoMovimiento::D :
                pos.columna+=salto_compr;
                break;
            case TipoMovimiento::B : 
                pos.fila+=salto_compr;
                break;
 
        }
        if(pos.fila<0 or pos.fila>tablero.fils or pos.columna<0 
        or pos.columna>tablero.cols)
            correcta=false;
         
        if(correcta)
        {
            tablero.datos[pos.fila][pos.columna]+=1;
            contador++;
        }
    }
    if(correcta)
        cout<<ToString(tablero)<<endl;
    else
    {
        cout<<"Se completaron "<<contador<<" pasos"<<endl;
        cout<<ToString(tablero)<<endl;
    }
    
    cout<<"-------------------------------------------------------\n";
    cout<<"-------------------------------------------------------\n";
    cout<<"Quiere evaluar otra configuracion? (S/N)";
    cin>>opcion;
    
    LiberaMemoria(tablero);
    LiberaVectorDinamico(v);

    }
    cout<<"\n\nTerminando programa..."<<endl;

    cout<<endl<<endl;
    return 0;
}

