#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# makefile_sesion08_previa.mak
#
# makefile para la sesión de prácticas 8 (previa, para alumnos)
#
#############################################################################

SESION = "8 (preparatoria)"

HOME = .
HOME_CLASES_UTILS = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include

SRC_CLASES_UTILS =  $(HOME_CLASES_UTILS)/src
OBJ_CLASES_UTILS =  $(HOME_CLASES_UTILS)/obj
LIB_CLASES_UTILS =  $(HOME_CLASES_UTILS)/lib
INCLUDE_CLASES_UTILS = $(HOME_CLASES_UTILS)/include

#................................................
all:  preambulo \
      $(BIN)/II_EstadisticaBasica_Lista \
      $(BIN)/II_OrdenarLista_Basico \
      final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejercicios de la Relación de Problemas II
	@echo Sesion de practicas $(SESION)	
	@echo
	@echo METODOLOGÍA DE LA PROGRAMACIÓN
	@echo
	@echo "("c")" Francisco José CORTIJO BON
	@echo Depto. Ciencias de la Computación e Inteligencia Artificial
	@echo Universidad de Granada
	@echo ------------------------------------------------------------
	@echo

#................................................
final: 
	@echo

#................................................
# EJECUTABLES

$(BIN)/II_EstadisticaBasica_Lista : \
           $(OBJ)/II_EstadisticaBasica_Lista.o $(LIB)/libListaMinima.a
	@echo 
	@echo Creando ejecutable: II_EstadisticaBasica_Lista
	@echo 
	g++ -o $(BIN)/II_EstadisticaBasica_Lista \
	       $(OBJ)/II_EstadisticaBasica_Lista.o -L$(LIB) -lListaMinima
	  
$(BIN)/II_OrdenarLista_Basico : \
           $(OBJ)/II_OrdenarLista_Basico.o $(LIB)/libListaMinima.a \
           $(LIB_CLASES_UTILS)/libGeneradorAleatorioEnteros.a 
	@echo 
	@echo Creando ejecutable: II_OrdenarLista_Basico
	@echo 
	g++ -o $(BIN)/II_OrdenarLista_Basico \
	       $(OBJ)/II_OrdenarLista_Basico.o \
	       -L$(LIB) -lListaMinima \
	       -L$(LIB_CLASES_UTILS) -lGeneradorAleatorioEnteros


#................................................
# OBJETOS 

$(OBJ)/II_EstadisticaBasica_Lista.o : $(SRC)/II_EstadisticaBasica_Lista.cpp \
                           $(INCLUDE)/ListaMinima.h $(INCLUDE)/TipoBaseLista.h 
	@echo 
	@echo Creando objeto: II_EstadisticaBasica_Lista.o
	@echo 
	g++ -c -o $(OBJ)/II_EstadisticaBasica_Lista.o \
	          $(SRC)/II_EstadisticaBasica_Lista.cpp -I$(INCLUDE) -std=c++11


$(OBJ)/II_OrdenarLista_Basico.o : $(SRC)/II_OrdenarLista_Basico.cpp \
                           $(INCLUDE)/ListaMinima.h $(INCLUDE)/TipoBaseLista.h \
						   $(INCLUDE_CLASES_UTILS)/GeneradorAleatorioEnteros.h
	@echo 
	@echo Creando objeto: II_OrdenarLista_Basico.o
	@echo 
	g++ -c -o $(OBJ)/II_OrdenarLista_Basico.o \
	          $(SRC)/II_OrdenarLista_Basico.cpp -I$(INCLUDE) -std=c++11


#................................................
# BIBLIOTECAS

# libMatriz2D.a .................................

$(OBJ)/ListaMinima.o : $(SRC)/ListaMinima.cpp $(INCLUDE)/ListaMinima.h \
                       $(INCLUDE)/TipoBaseLista.h
	@echo 
	@echo Creando objeto: ListaMinima.o 
	@echo  
	g++ -c -o $(OBJ)/ListaMinima.o $(SRC)/ListaMinima.cpp  \
            -I$(INCLUDE) -I$(INCLUDE_CLASES_UTILS) -std=c++11 

$(LIB)/libListaMinima.a : $(OBJ)/ListaMinima.o
	@echo 
	@echo Creando biblioteca: libListaMinima.a 
	@echo   
	ar rvs $(LIB)/libListaMinima.a $(OBJ)/ListaMinima.o 
# ...............................................


# (Números aleatorios) ........................

$(LIB_CLASES_UTILS)/libGeneradorAleatorioEnteros.a : \
	$(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o
	@echo 
	@echo Creando biblioteca: libGeneradorAleatorioEnteros.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libGeneradorAleatorioEnteros.a \
           $(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o

$(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o : \
    $(SRC_CLASES_UTILS)/GeneradorAleatorioEnteros.cpp \
    $(INCLUDE_CLASES_UTILS)/GeneradorAleatorioEnteros.h
	@echo 
	@echo Creando objeto: GeneradorAleatorioEnteros.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o \
        $(SRC_CLASES_UTILS)/GeneradorAleatorioEnteros.cpp \
       -I$(INCLUDE_CLASES_UTILS) -std=c++11

#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs: clean-objetos-bibliotecas

	@echo Borrando objetos de la sesion de practicas $(SESION)...

	-rm $(OBJ)/II_EstadisticaBasica_Lista.o 
	-rm $(OBJ)/II_OrdenarLista_Basico.o
	
	@echo ...Borrados objetos de la sesion de practicas $(SESION)
	@echo 

clean-objetos-bibliotecas: 
	@echo Borrando objetos usados en bibliotecas de la Sesión $(SESION)......

	-rm $(OBJ)/ListaMinima.o 
	-rm $(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o 

	@echo ...Borrados
	@echo 

clean-libs: 
	@echo Borrando bibliotecas de la sesion de practicas $(SESION)...

	-rm $(LIB)/libListaMinima.a
	-rm $(LIB_CLASES_UTILS)/libGeneradorAleatorioEnteros.a 

	@echo ...Borradas bibliotecas de la sesion de practicas $(SESION)
	@echo 

clean-bins : 
	@echo Borrando ejecutables de la sesion de practicas $(SESION)...

	-rm $(BIN)/II_EstadisticaBasica_Lista
	-rm $(BIN)/II_OrdenarLista_Basico
	
	@echo ...Borrados ejecutables de la sesion de practicas $(SESION)

mr.proper:  clean-objs clean-libs clean-bins

