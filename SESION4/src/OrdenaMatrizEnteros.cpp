#include <iostream>
#include "GeneradorAleatorioEnteros.h"
#include "ProcesamientoArrayInt.h"
using namespace std;

void MuestraMatriz(string msg, int *m, int nf, int nc ){
    cout<<msg<<endl;
    for(int i=0; i<nf*nc; i++){
        if( i%nc == 0){
            cout<<endl;
        }
        cout<<*(m+i)<<'\t';      
    }
    cout<<endl;
};

void CopiaMatriz(int *nueva, int *original, int nf_inicial, int nc_inicial,
int nf_final, int nc_final){
    //int k;
    //int contador=0;
    //for(int i=0; i<nf*5; i+=5)
    //{
    //    for(int j=i,k=0; k<nc; j++,k++,contador++){
    //        *(nueva+contador) = *(original+j);
    //    }
    //}
    int filas_copia=0;
    int columna_copia=0;

    for(int i=nf_inicial; i<nf_final; i++){
        for(int j=nc_inicial; j<nc_final; j++,columna_copia++){

        }
    }    
}

int main(){
    const int NUM_FILAS = 40;
    const int NUM_COLUMNAS = 20;
    int matriz_base[NUM_FILAS][NUM_COLUMNAS] = {0};
    int util_filas_base = 1;
    int util_columnas_base = 1;

    int min_aleatorio = 0;
    int max_aleatorio = 100;

    GeneradorAleatorioEnteros generador(min_aleatorio, max_aleatorio);

    for(int i = 0; i < NUM_FILAS; i++){
        for(int j = 0; j < NUM_COLUMNAS; j++){
            matriz_base[i][j] = generador.Siguiente();
        }
    }

    cout<<"---------------------------------------------------------"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"MATRIZ BASE GENERADA"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
   
    MuestraMatriz("MBASE CON FUNCION",matriz_base[0], NUM_FILAS, NUM_COLUMNAS);
    

    //AQUI PEDIR LOS DATOS AL USUARIO CON CONTROL DE ERRORES
    int util_filas_orden_filas;
    do{
        cout<<"\nIntroduzca el numero de filas a usar de la matriz orden" 
        <<"filas-> ";
        cin>>util_filas_orden_filas;
    }while(util_filas_orden_filas<=0 or util_filas_orden_filas>NUM_FILAS);

    int util_columnas_orden_filas;
    do{
        cout<<"\nIntroduzca el numero de columnas a usar de la matriz "
        <<"filas-> ";
        cin>>util_columnas_orden_filas;
    }while(util_columnas_orden_filas<=0 or 
    util_columnas_orden_filas>NUM_COLUMNAS);

    
    int orden_filas[util_filas_orden_filas][util_columnas_orden_filas]
    = {0};


    int util_filas_orden_columnas;
    do{
        cout<<"\nIntroduzca el numero de filas a usar de la matriz orden" 
        <<"columnas-> ";
        cin>>util_filas_orden_columnas;
    }while(util_filas_orden_columnas<=0 or 
                    util_filas_orden_columnas>NUM_FILAS);

    int util_columnas_orden_columnas;
    do{
        cout<<"\nIntroduzca el numero de columnas a usar de la matriz "
        <<"columnas-> ";
        cin>>util_columnas_orden_columnas;
    }while(util_columnas_orden_columnas<=0 or 
    util_columnas_orden_columnas>NUM_COLUMNAS);

    int orden_columnas[util_filas_orden_columnas][util_columnas_orden_columnas]
    = {0};
    
    //Copiamos la matriz a ordenar por filas
    for(int i=0;i<util_filas_orden_filas;i++){
        for(int j=0;j<util_columnas_orden_filas; j++){
            orden_filas[i][j] = matriz_base[i+1][j+1];
        }
    }
    
    

    cout<<"\n---------------------------------------------------------"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"ORDENACION POR FILAS"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"---------------------------------------------------------"<<endl;

    MuestraMatriz("MATRIZ ORDEN FILAS",orden_filas[0], util_filas_orden_filas,
    util_columnas_orden_filas);

    
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"MATRIZ FILAS COMO VECTOR"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    int * pm = orden_filas[0];
    for(int i=0; i<util_columnas_orden_filas*util_filas_orden_filas; i++)
    {
        if(i%util_columnas_orden_filas==0 && i!=0)  cout<<"| ";
        cout<<pm[i]<<' ';
    }
    cout<<endl;
    cout<<"---------------------------------------------------------"<<endl;


    //Ordenar por filas 
    for(int i=0; i<util_filas_orden_filas; i++){
        OrdenaSeleccion(pm+i*util_columnas_orden_filas,
        util_columnas_orden_filas);
    }

    MuestraMatriz("MATRIZ FILAS ORDENADA", orden_filas[0], 
    util_filas_orden_filas, util_columnas_orden_filas);


    //Copiamos la matriz a ordenar por columns
    for(int i=0;i<util_filas_orden_columnas;i++){
        for(int j=0;j<util_columnas_orden_columnas; j++){
            orden_columnas[i][j] = matriz_base[i][j];
        }
    }

    cout<<"\n---------------------------------------------------------"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"ORDENACION POR COLUMNAS"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    MuestraMatriz("MATRI ORDEN COLUMNAS", orden_columnas[0],
    util_filas_orden_columnas,util_columnas_orden_columnas);
    
    //Ordenar por columnas 
    //HACEMOS LA TRASPUESTA. LA ORDENAMOS POR FINLAS COMO ANTES Y VOLVEMOS
    //A HACER LA TRASPUESTA
    int columnas_traspuesta = util_filas_orden_columnas;
    int filas_traspuesta = util_columnas_orden_columnas;
    int orden_columnas_tras[filas_traspuesta][columnas_traspuesta];
    for(int i=0; i<columnas_traspuesta; i++){
        for(int j=0; j<filas_traspuesta; j++){
            orden_columnas_tras[j][i] = orden_columnas[i][j];
        }
    }


    int * pmcols = orden_columnas_tras[0];

    cout<<"---------------------------------------------------------"<<endl;
    cout<<"MATRIZ ORDEN COLUMNAS COMO VECTOR"<<endl;
    cout<<"---------------------------------------------------------"<<endl;


    int * pmc = orden_columnas[0];
    for(int i=0; i<util_columnas_orden_columnas*util_filas_orden_columnas; i++)
    {       
        if(i%util_columnas_orden_columnas==0 && i!=0)  cout<<"| ";    
        cout<<pmc[i]<<' ';
            
    }
    cout<<"\n---------------------------------------------------------"<<endl;

    ////Ordenar por filas la traspuesta
    int * pmtras = orden_columnas_tras[0];
    for(int i=0; i<filas_traspuesta; i++){
        OrdenaSeleccion(pmtras+i*columnas_traspuesta,
        columnas_traspuesta);
    }


    for(int i=0; i<util_filas_orden_columnas; i++){
        for(int j=0; j<util_columnas_orden_columnas; j++){
            orden_columnas[i][j] = orden_columnas_tras[j][i];
        }
    }

    MuestraMatriz("MATRI ORDEN COLUMNAS ORDENADA", orden_columnas[0],
    util_filas_orden_columnas,util_columnas_orden_columnas);


    return 0;
}