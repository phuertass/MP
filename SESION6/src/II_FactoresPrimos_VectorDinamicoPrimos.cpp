
#include <iostream>
#include <iomanip>
#include <string>
#include "FuncionesErastotenes.h"
#include "FuncsVectorDinamico.h"
using namespace std;


/***************************************************************************/
/***************************************************************************/

int main (int argc, char ** argv)
{

		
	// Máximo primo permitido en el resultado. 
	int max_primo = 100;

    int numero_a_descomponer=-1;

    if(argc>3)
	{
		cerr << "Error: demasiados argumentos" << endl;
        cerr << "Uso: " << argv[0] << "[r] [n]"<<endl<<endl;
        exit(1);

	}

    if(argc>1)
    {
        numero_a_descomponer = atoi(argv[1]);
        if(argc>2)
            max_primo = atoi(argv[2]);

    }
	
	
    VectorDinamico primos = CreaVectorDinamico(0);

	// Número máximo de factores primos permitidos
	const int MAX_FACTORES = 50;
	/***********************************************************************/
	// Calcular, guardar y mostrar los primos
	/***********************************************************************/

	cout << endl;
	cout << "Se calcularan los primos menores que " << max_primo << endl;
    cout << "Se factorizara el numero " << numero_a_descomponer << endl;
	
	// Emplearemos un vector de datos lógicos para la criba de manera que  
	// "es_primo[i]" será TRUE si "i" es primo. 	
	bool es_primo[max_primo+1]; 	
	
	//Calculo de los numeros primos
	int num_primos = CalcularPrimos(es_primo, primos, max_primo);

	/***********************************************************************/
	// Mostrar los primos calculados
	/***********************************************************************/
    cout<<ToString(primos);
	

    Pareja descomposicion[MAX_FACTORES] = {{0,0}};

    int utilizados_descomposicion = 0; // Inicializar descomposición

    
    /*******************************************************************/
    // Calcular descomposición en factores primos
    /*******************************************************************/
    int n = numero_a_descomponer;	

    // Los primos que se evalúan como posibles divisores de "n" se 
    // toman del array "primos". 
    // Se empieza con el 2 (ocupa la casilla 1 de "primos"). Recuerde 
    // que la casilla 0 está ocupada por el 1.
        
    int pos_primo = 1;					
    int candidato = ValorVectorDinamico(primos,pos_primo);  // El primer candidato es 2
                    
    int veces = 0; // exponente --> candidato^veces 
                                        
    while ((n > 1) && (pos_primo<num_primos) && 
            (utilizados_descomposicion<MAX_FACTORES)) {
        
        if  (n % candidato == 0)	{ // "candidato" es un factor primo
            
            veces = 1; 
            
            // Se sigue probando con el mismo factor ("candidato")
            
            n = n / candidato;
        
            while (n % candidato == 0) {
                
                veces++; 
                n = n / candidato;
            }
            
            // Actualizar el array de factores primos
            descomposicion[utilizados_descomposicion].primo = candidato;				
            descomposicion[utilizados_descomposicion].potencia = veces;
            
            utilizados_descomposicion++;
        } 
        
        // Probar con el siguiente primo
        pos_primo++;
        candidato = ValorVectorDinamico(primos,pos_primo);
            
    } // while 
    

    if ((pos_primo>=num_primos) || 
        (utilizados_descomposicion>=MAX_FACTORES))  {
    
        utilizados_descomposicion = 0; 
    }	



    /*******************************************************************/
    // Mostrar descomposición en factores primos
    /*******************************************************************/	

    if (utilizados_descomposicion == 0) {

        cout << endl; 
        cout << "ERROR: Faltan primos para resultado o se requieren " 
                << "demasiados factores." << endl;
        cout << endl; 

    }

    else {
                
        cout << endl; 
        cout << numero_a_descomponer << " = ";

        for (int i=0; i<utilizados_descomposicion; i++) {
            
            int veces_primo = descomposicion[i].potencia; 
            
            if (veces_primo > 0) { // No se muestran los 
                                    // valores no primos

                cout << setw(2) << descomposicion[i].primo;  // base

                // Se escribe el exponente solo si es mayor que 1
                if (veces_primo > 1) cout <<  "^" << veces_primo;
                
                if (i<utilizados_descomposicion-1) 
                    cout << " * "; // evita el último *
            }

        } // for

        cout << endl; 
    }
		
	
	cout << endl;
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/