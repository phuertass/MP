#ifndef FUNCIONES_D_HONT
#define FUNCIONES_D_HONT

// La informacion de cada partido se guarda en un struct
struct Partido {
   	char sigla;		// "Nombre" del partido
   	long votos;		// Votos recibidos
   	int escagnos;	// Escaños conseguidos
};

//Funcion que lee los votos de cada partidos y se los asigna a la vez que 
//le asigna una letra o sigla
void LeerVotos(Partido * resultado, int num_partidos);

//Funcion que se utiliza para calcular los escaños conseguidos de cada partido
//de acuerdo a la ley DHont
//Recibe un puntero a un struct partido, y a cada partido le asigna el numero
//de escaños conseguidos
void CalculoEscanios(Partido * resultado, int num_escagnos, int num_partidos);

//Funcio que se utiliza para mostrar el resultado de todos los partidos
//Se muestra su sigla, el numero de votos y los escaños conseguidos 
void MuestraResultado(Partido * resultado, int num_partidos);
#endif