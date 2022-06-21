#include "FuncionesDHont.h"
#include <iostream>
#include <iomanip>


using namespace std;

//Funcion que lee los votos de cada partidos y se los asigna a la vez que 
//le asigna una letra o sigla
void LeerVotos(Partido * resultado, int num_partidos)
{
	cout << "Introducir el numero de votos de cada partido." << endl;

	for (int p = 0; p < num_partidos; p++) {

		long los_votos_partido_p;
		
		cout << endl; 

		do{
			cout << "\tPartido " << (char)('A'+ p) << " : ";
			cin >>  los_votos_partido_p;
		} while (los_votos_partido_p < 0);       
			
		resultado[p].votos = los_votos_partido_p;
		resultado[p].sigla = 'A'+ p;
		resultado[p].escagnos = 0;    
	}
};


//Funcion que se utiliza para calcular los escaños conseguidos de cada partido
//de acuerdo a la ley DHont
//Recibe un puntero a un struct partido, y a cada partido le asigna el numero
//de escaños conseguidos
void CalculoEscanios(Partido * resultado, int num_escagnos, int num_partidos){
    //***********************************************************************
	// Cálculo
	
	int partido_max, max;
	    
	// Cada escaño "e" se asigna de acuerdo al mayor cociente entre votos y 
	// escaños ya conseguidos más uno.
	// Esto es, el partido "p" para el que el cociente entre los votos totales 
	// conseguidos (distribucion[p].voto) y el número de escaños que le han 
	// sido asignados hasta ese momento (distribucion[p].escagnos) más uno 
	// sea mayor consigue el escaño "e"
	
    for (int e = 0; e < num_escagnos; e++) {
    	
    	max = -1; // Primer máximo
    	
    	// El máximo se calcula entre todos los partidos
    	
        for (int p = 0; p < num_partidos; p++) {
		
			// Cociente para el partido "p"
			double coc_p = resultado[p].votos/(resultado[p].escagnos+1);
			
			if (coc_p > max ) {
				max = coc_p;
                partido_max = p; 
			}
		}

		// Asignación el eacaño al partido "p"
		resultado[partido_max].escagnos++;
    }
}

//Funcio que se utiliza para mostrar el resultado de todos los partidos
//Se muestra su sigla, el numero de votos y los escaños conseguidos 
void MuestraResultado(Partido * resultado, int num_partidos){
 	// Presentación del resultado   

    cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Distribucion de escagnos: " << endl;
    cout << endl;
    
    for (int p = 0; p < num_partidos; p++) {
        cout << "\tPartido " << resultado[p].sigla;
 	    cout << " ("<< setw(8) << resultado[p].votos <<" votos) -->";
		cout << setw(3) << resultado[p].escagnos << " Escagnos" << endl;
	}
	
    cout << "----------------------------------------------------" << endl;
    cout << endl;	

}