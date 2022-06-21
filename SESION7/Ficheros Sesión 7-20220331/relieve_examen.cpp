/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA 
//
// CURSO 2019 - 2020
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// EXAMEN CONV.ORDINARIA - ENERO 2020
//
// RELIEVE
//
/*********************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Punto2D
{
private:
	
	// La pareja (x,y) son las coordenadas de un punto en un espacio 2D
	int x;
	int y;

public:
	
	/***********************************************************************/
	// Constructor sin argumentos.
	//
	// MUY IMPORTANTE: Nos vemos obligados a escribir este constructor por la
	// clase "ColeccionPuntos2D": cuando actúa el constructor sin argumentos 
	// de esa clase crea un vector de objetos "Punto2D" y cada elemento del  
	// vector se crea usando este constructor. La implementación dada no 
	// hace nada, pero debe estar.
		
	Punto2D (void) { }

	/***********************************************************************/
	// Constructor con argumentos.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se está creando.
	
	Punto2D (int abscisaPunto, int ordenadaPunto)
	{
		SetCoordenadas (abscisaPunto, ordenadaPunto);
	}

	/***********************************************************************/
	// Método Set para fijar simultaneamente las coordenadas. 
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se está modificando.
	
	void SetCoordenadas (int abscisaPunto, int ordenadaPunto)
	{
		x = abscisaPunto;
		y = ordenadaPunto;
	}

	/***********************************************************************/
	// Métodos Get para leer las coordenadas

	double GetX (void)
	{
		return (x);
	}
	double GetY (void)
	{
		return (y);
	}

	/***********************************************************************/
	// Calcula la distancia Euclídea del punto (objeto implícito) a otro que 
	// se recibe como argumento. 
	//
	// Recibe: otro, el punto respecto al cual que se quiere calcular la 
	// distancia euclídea.
	// Devuelve: la distancia entre los dos puntos. 

	double DistanciaEuclidea (Punto2D otro)
	{
		double dif_x = pow (x - otro.x, 2);
		double dif_y = pow (y - otro.y, 2);

		return (sqrt(dif_x + dif_y));
	}
	
	/***********************************************************************/
	// Devuelve la representación en una cadena de un punto
	string ToString (void)
	{
		string cad;
		cad = "[ " + to_string (x) + ", " + to_string (y) + "]";	
		return (cad);
	}
	
	/***********************************************************************/		
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class ColeccionPuntos2D 
{
private:

	// Datos asociados a la estructura de datos empleada para guardar 
	// los valores de la coleccion.

	static const int TAMANIO = 200; // Número de casillas disponibles

	Punto2D vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas
	

public:
	
	/***********************************************************************/
	// Constructor sin parámetros. 
	// Cada objeto de la colección (cada casilla de "vector_privado") se 
	// crea usando el constructor sin argumentos de la clase Punto2D. 

	ColeccionPuntos2D (void) : total_utilizados(0) { }

	/***********************************************************************/
	// Constructor a partir de un punto. 
	//
	// Recibe: nuevo_punto, el único punto que forma la nueva colección. 
	
	ColeccionPuntos2D (Punto2D nuevo_punto) : total_utilizados(0)
	{ 
		Aniade (nuevo_punto);
	}

	/***********************************************************************/
	// Métodos de lectura (Get) sobre tamaño y capacidad de la colección 

	// Devuelve el número de puntos que componen la colección.
	int NumPuntos ()
	{
		return (total_utilizados);
	}

	// Devuelve el número de puntos que podrían formar una colección completa.
	int CapacidadColeccion()
	{
		return (TAMANIO);
	}


	/***********************************************************************/
	// Añade un punto a la colección.
	// Recibe: nuevo_punto, el punto que se va a añadir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adición se realiza si hay espacio para el nuevo elemento. 
	// 		El nuevo elemento se coloca al final del vector. 
	// 		Si no hay espacio, no se hace nada.	

	void Aniade (Punto2D nuevo_punto)
	{
		if (total_utilizados < TAMANIO) {
			vector_privado[total_utilizados] = nuevo_punto;
			total_utilizados++;
		}
	}

	/***********************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	//
	// PRE: 0 <= indice < total_utilizados 

	Punto2D Elemento (int indice)
	{
		return (vector_privado[indice]);
	}
	
	/***********************************************************************/	
	// Devuelve la representación en una cadena de un punto
	string ToString (void)
	{
		string cad;
		
		for (int pos=0; pos<total_utilizados; pos++)
			cad = cad + vector_privado[pos].ToString() + " ";

		return (cad);
	}
	
	/***********************************************************************/		

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Relieve {

private:

	static const int NUM_FILAS = 50; // Núm. filas disponibles
	static const int NUM_COLS  = 50; // Núm. columnas disponibles
    
    int t[NUM_FILAS][NUM_COLS]; 

    // PRE: 0 <= filas_utilizadas < NUM_FILAS
    // PRE: 0 <= cols_utilizadas  < NUM_FILAS

    int filas_utilizadas; // Núm. filas ocupadas
    int cols_utilizadas;  // Núm. columnas ocupadas

public:


    /***********************************************************************/
    // Constructor sin argumentos
    Relieve (void) : filas_utilizadas(0), cols_utilizadas(0)
    {}
    
    /***********************************************************************/
    // Constructor con argumentos
	Relieve (int nf, int nc)
	{
		for (int f=0; f<=nf; f++)
			for (int c=0; c<=nc; c++) 
				t[f][c] = 0;
				
		filas_utilizadas = nf;
		cols_utilizadas  = nc;		
	} 

    /***********************************************************************/
    // Devuelve el número de filas ocupadas
    int FilasUtilizadas (void)
    {
        return (filas_utilizadas);
    }

    /***********************************************************************/
    // Devuelve el número de columnas ocupadas
    int ColumnasUtilizadas (void)
    {
        return (cols_utilizadas);
    }

    /***********************************************************************/
    // Devuelve el número de filas disponibles
    int CapacidadFilas (void)
    {
        return (NUM_FILAS);
    }  
    
    /***********************************************************************/
    // Devuelve el número de columnas disponibles
    int CapacidadColumnas (void)
    {
        return (NUM_COLS);
    }  
    
    /***********************************************************************/
    // "Vacía" completamente la tabla

	void EliminaTodos()
	{
		filas_utilizadas = cols_utilizadas = 0;
	}

    /***********************************************************************/
    // Devuelve el elemento de la casilla (f,c)
    // PRE: 0 <= f < filas_utilizadas
    // PRE: 0 <= c < cols_utilizadas
    
    int ObtenerAltura (int f, int c)
    {
        return (t[f][c]);
    }

    /***********************************************************************/
    // Cambia el contenido de la casilla (f,c) por "alt"
    // PRE: 0 <= f < filas_utilizadas
    // PRE: 0 <= c < cols_utilizadas

   void ModificarAltura (int f, int c, int alt)
   {
   		bool fila_ok = ((f >= 0) && (f < filas_utilizadas));
   		bool col_ok  = ((c >= 0) && (f < cols_utilizadas));

        if (fila_ok && col_ok)  
        	t[f][c] = alt;
   }

    /***********************************************************************/
    // Compone un string con todos los datos que están almacenados en la 
	// tabla y lo devuelve.

    string ToString()
    {
        string cadena;

	    cadena = cadena + "Filas = " + to_string(filas_utilizadas) + 
			          " Columnas = " + to_string(cols_utilizadas) + "\n\n";

		cadena = cadena + "     "; 
		for (int c=0; c<cols_utilizadas; c++) {
	     	string prev = ((c<10) ? "0":"");
			cadena = cadena + prev + to_string(c) + " "; 
		}
		cadena = cadena + "\n"; 

		cadena = cadena + "    "; 
		for (int c=0; c<cols_utilizadas; c++) {
			cadena = cadena + "..."; 
		}
		cadena = cadena + "\n"; 		
			        
        for (int f=0; f<filas_utilizadas; f++)  {
        	
			cadena = cadena + ((f<10) ? "0":"") + to_string(f) + " : ";
	    
			for (int c=0; c<cols_utilizadas; c++) {
		     	string prev = ((t[f][c]<10) ? " ":"");
				cadena = cadena + prev + to_string(t[f][c]) + " "; 
			}
			cadena = cadena + "\n"; 			
		}
		
        return (cadena);
    }

    /***********************************************************************/
	// EXAMEN
    /***********************************************************************/
	
    /***********************************************************************/
    // Calcula si el punto (f,c) es un pico. 
    // Una parcela es un pico si su altura es mayor que las de sus 8 vecinos 
    // más cercanos. Por simplicidad se supone que las parcelas de los bordes 
	// NO pueden ser picos. 
    //
	// PRE: 0 <= f <= filas_utilizadas-1
    // PRE: 0 <= c <= cols_utilizadas-1
    
	bool EsPico (int f, int c)
	{
		// Comprobar si no es un borde. Si es borde, NO es un pico 
   		bool f_es_fila_borde = ((f == 0) || (f == filas_utilizadas-1));
   		bool c_es_col_borde  = ((c == 0) || (c == cols_utilizadas-1));
   		bool f_c_en_borde = (f_es_fila_borde || c_es_col_borde);
   		
   		bool es_pico;
			
        if (!f_c_en_borde) {
        
	        es_pico = true;  
        	bool sigo = true; 	// Toma el valor "false" cuando detectamos 
        						// que la parcela central NO es un pico.  
        						
        	// Recorrer los ocho vecinos (y evitamos el punto central)
        	
        	for (int desp_f=-1; desp_f<=1 && sigo; desp_f++) {
       			int fila = f+desp_f; // fila: f-1, f, f+1

	        	for (int desp_c=-1; desp_c<=1 && sigo; desp_c++) {
        			int col  = c+desp_c;  // col: c-1, c, c+1 
        			
					// Evitamos evaluar el punto central (f,c)
					if ((fila!=f) || (col!=c)) { 
					
						// Si no es pico, terminar.
						// Si la parcela examinada es más baja, debemos  
						// seguir probando con las demás. 
						  
						if (t[fila][col] >= t[f][c]) {	
							sigo = false;
							es_pico = false;	
						}	
					}
					
				} // for c
				
			} // for f
        	
        	/* Otra implementación más "clásica"
        	
        	// Filas: f-1, f, f+1
			int fila = f-1; 
			
        	while (sigo && (fila<=f+1)) { // Puede terminar antes, si se 
        								  // detecta que no es un pico

	        	// Columnas: c-1, c, c+1
				int col = c-1;
				
	        	while (sigo && (col<=c+1)) { // Puede terminar antes, si se 
        									 // detecta que no es un pico

					if ((fila!=f) || (col!=c)) { // No es el punto central 
					
						if (t[fila][col] >= t[f][c]) {	// Si no es pico,  
														// ternminar.  
							sigo = false;
							es_pico = false;	
						}	
					}
	
					col++;	
        			
        		} // while (sigo && (col<=c+1)) 
        		
				fila++;	
				
        	} // while (sigo && (fila<=f+1)) 
        	*/
        	
		} // if (fila_ok && col_ok)
		
		else { // La casilla está en un borde --> NO es pico
		
			es_pico = false;	
		}
        
        return (es_pico);
	}

    /***********************************************************************/
	// FIN EXAMEN
    /***********************************************************************/

    /***********************************************************************/
    // Compone un string con todos los datos que están almacenados en la 
	// tabla y lo devuelve. Los picos son 'X' y los no picos '.'

    string Picos()
    {
        string cadena;

	    cadena = cadena + "Filas = " + to_string(filas_utilizadas) + 
			          " Columnas = " + to_string(cols_utilizadas) + "\n\n";

		cadena = cadena + "     "; 
		for (int c=0; c<cols_utilizadas; c++) {
	     	string prev = ((c<10) ? "0":"");
			cadena = cadena + prev + to_string(c) + " "; 
		}
		cadena = cadena + "\n"; 

		cadena = cadena + "    "; 
		for (int c=0; c<cols_utilizadas; c++) {
			cadena = cadena + "..."; 
		}
		cadena = cadena + "\n"; 		
		
					        
        for (int f=0; f<filas_utilizadas; f++)  {
        	
			cadena = cadena + ((f<10) ? "0":"") + to_string(f) + " : ";
	    
			for (int c=0; c<cols_utilizadas; c++) {	
			
				bool es_un_pico_f_c = EsPico(f,c);
				cadena = cadena + (es_un_pico_f_c ? " X":" .") + " "; 
			}
			cadena = cadena + "\n"; 		
		}
		
        return (cadena);
    }
    
    
    /***********************************************************************/
	// EXAMEN
    /***********************************************************************/

    /***********************************************************************/
	// Devuelve una secuencia de datos Punto2D que contiene los picos del 
	// objeto Relieve. El orden es el del recorrido por filas.
	     
	ColeccionPuntos2D CalculaSecuenciaPicos ()
	{
		ColeccionPuntos2D picos; 
			        
        for (int f=0; f<filas_utilizadas; f++)  
        	
			for (int c=0; c<cols_utilizadas; c++) 
			
				if (EsPico(f,c)) picos.Aniade(Punto2D (f, c));
					
		return (picos);
	}

    /***********************************************************************/
	// FIN EXAMEN
    /***********************************************************************/

    /***********************************************************************/
	// EXAMEN
    /***********************************************************************/

    /***********************************************************************/
	// Devuelve un objeto relieve, resultado de fusionar dos objetos Relieve.
	     
	Relieve Fusion (Relieve otro)
	{
		int filas_fusion = ((filas_utilizadas < otro.filas_utilizadas) ? 
							 filas_utilizadas : otro.filas_utilizadas);
		int cols_fusion  = ((cols_utilizadas < otro.cols_utilizadas) ? 
							 cols_utilizadas : otro.cols_utilizadas);
		
		Relieve fusionado (filas_fusion, cols_fusion); 
			        
        for (int f=0; f<filas_fusion; f++)  
        	
			for (int c=0; c<cols_fusion; c++) {
				
				if (t[f][c] > otro.t[f][c])  fusionado.t[f][c] = t[f][c];
				else fusionado.t[f][c] = otro.t[f][c];
			}
					
		return (fusionado);
	}
    /***********************************************************************/

    /***********************************************************************/
	// FIN EXAMEN
    /***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////


/***************************************************************************/
/***************************************************************************/

int main()
{
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
 
  	int filas_r1, cols_r1;
 	int filas_r2, cols_r2;

	int valor_altura;


 	// Crear, leer y mostrar relieve 1
 	
 	cin >> filas_r1; // 11
 	cin >> cols_r1;  // 11
 	
	Relieve r1 (filas_r1, cols_r1); // Todo a ceros			
	
	// Leer valores de altura de r1
	
	for (int f=0; f<r1.FilasUtilizadas(); f++)
		for (int c=0; c<r1.ColumnasUtilizadas(); c++) {
			cin >> valor_altura;
			r1.ModificarAltura(f, c, valor_altura);
		}		
	cout << r1.ToString() << endl; 
	

 	// Crear, leer y mostrar relieve 2

 	cin >> filas_r2; // 3
 	cin >> cols_r2;  // 5
 	
	Relieve r2 (filas_r2, cols_r2); // Todo a ceros	
	
	// Leer valores de altura de r2

	for (int f=0; f<r2.FilasUtilizadas(); f++)
		for (int c=0; c<r2.ColumnasUtilizadas(); c++) {
			cin >> valor_altura;
			r2.ModificarAltura(f, c, valor_altura);
		}			
	cout << r2.ToString() << endl; 
	
	// Mostrar picos
	
	cout << r1.Picos() << endl; 
	cout << r2.Picos() << endl; 
	
	
    /***********************************************************************/
	// EXAMEN
    /***********************************************************************/
    
	// Calcular el pico más alto

	// El pico más alto será, por definición, un pico. Para evitar reescribir 
	// código y emplear los métodos disponibles parece razonable: 
	//	1) obtener una secuencia con todos los picos del relieve, y
	//	2) calcular el pico más alto de la secuencia 

	ColeccionPuntos2D picos = r1.CalculaSecuenciaPicos();

	// El primer pico más alto será el primero
	Punto2D pico_mas_alto = picos.Elemento(0); 
	int altura_pico_mas_alto = 
	          r1.ObtenerAltura(pico_mas_alto.GetX(), pico_mas_alto.GetY());
	
	// Calcular el máximo considerando los restantes
	for (int pos=1; pos<picos.NumPuntos(); pos++) {
		
		Punto2D pico_actual = picos.Elemento(pos); // candidato
		int altura_pico_actual = 
			r1.ObtenerAltura(pico_actual.GetX(), pico_actual.GetY());
			
		if (altura_pico_actual > altura_pico_mas_alto) { // nuevo máximo
			altura_pico_mas_alto = altura_pico_actual;
			pico_mas_alto = pico_actual;
		}
	}
	cout << endl; 
	cout << "El pico mas alto esta en " << pico_mas_alto.ToString() << endl;
	cout << "Su altura es: " << altura_pico_mas_alto << endl;	 
	cout << endl; 


	// Calcular la longitud del cable que une todos los picos
	
	// Seguimos trabajando con la secuencia de picos (ya está calculada). 
	// La distancia horizontal entre dos picos se calcula con el método 
	// Distancia. La diferencia de altura se debe calcular. 
	
	double long_total = 0.0;
	
	// Primer pico
	Punto2D un_pico = picos.Elemento(0); 
	int altura_un_pico =  r1.ObtenerAltura(un_pico.GetX(), un_pico.GetY());
	
	for (int pos=1; pos<picos.NumPuntos(); pos++) {
		
		// Siguiente pico 
		Punto2D otro_pico = picos.Elemento(pos); 
		int altura_otro_pico = 
		           r1.ObtenerAltura(otro_pico.GetX(), otro_pico.GetY());
		
		// Cálculo (¡¡Pitágoras!!)
		double dist_horizontal = un_pico.DistanciaEuclidea(otro_pico);
		double dif_altura = abs(altura_un_pico-altura_otro_pico); 
		
		long_total += sqrt(pow(dist_horizontal,2)+pow(dif_altura,2));
		
		// Para la siguiente vuelta, actualizar "un_pico" (y su altura)
		un_pico = otro_pico;
		altura_un_pico = altura_otro_pico;	
	}
	
	cout << endl; 
	cout << "Longitud del cable que une los picos = " << long_total << endl;
	cout << endl; 
	

	// Fusionar los dos relieves y obtener los picos
	
	// En un paso: 
	// ColeccionPuntos2D picos_fusion = (r1.Fusion(r2)).CalculaSecuenciaPicos();

	// En dos pasos: 
	
	Relieve fusion_r1_r2 = r1.Fusion(r2);
	ColeccionPuntos2D picos_fusion = fusion_r1_r2.CalculaSecuenciaPicos();

	/*	
	cout << "Fusion de los relieves. " << endl;
	cout << fusion_r1_r2.ToString() << endl; 
	*/
			
	cout << "Se han encontrado " << setw(3) << picos_fusion.NumPuntos() 
	     << " picos en la fusion --> "; 
	     
	for (int pos=0; pos<picos_fusion.NumPuntos(); pos++) {
		
		Punto2D el_pico = picos_fusion.Elemento(pos); 
		int altura_el_pico = 
		    fusion_r1_r2.ObtenerAltura(el_pico.GetX(), el_pico.GetY());
			
		cout << "(" << el_pico.ToString() << " , "  << altura_el_pico << ") ";
			
	}
	cout << endl; 

    /***********************************************************************/
	// EXAMEN
    /***********************************************************************/
				
	return 0;
}

/***************************************************************************/
/***************************************************************************/
