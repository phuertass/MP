// struct para guardar las parejas primo-potencia
struct Pareja {
		int primo;		// Número primo (factor primo)
		int potencia;	// Veces que aparece en la descomposición 
};

//Funcion que rellena un vector booleano con los numeros primos a true
//Tambien modifica el vector primos y le introduce todos los numeros primos
//previamente calculados
int CalcularPrimos(bool es_primo[],int primos[],int MAX_PRIMO,int MAX_DATOS);

//Funcion para mostrar los primeros num_primos numeros del vector primos

void MostrarPrimos(int primos[], int num_primos, int DATOS_POR_LINEA);