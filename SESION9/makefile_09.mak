#MAKEFILE PABLO HUERTAS ARROYO
###############################################################################


HOME = .

SRC = $(HOME)/src
OBJ = $(HOME)/obj
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
LIB = $(HOME)/lib

CXX = g++
CXXFLAGS = -std=c++14 -I./include

OBJETOS = $(BIN)/III_DemoMatriz2D


OPCIONALES = $(BIN)/III_Demo-Pila $(BIN)/III_Demo-Cola

.PHONY : clean
.PHONY : mr.proper

###############################################################################

all : preambulo $(OBJETOS) $(OPCIONALES) arbol final 

###############################################################################
#EJECUTABLES
###############################################################################

$(BIN)/III_Demo-Secuencia : \
              $(OBJ)/III_Demo-Secuencia.o \
              $(LIB)/libSecuencia.a
	@echo 
	@echo Creando ejecutable: III_Demo-Secuencia
	@echo 
	$(CXX) -o $(BIN)/III_Demo-Secuencia \
         $(OBJ)/III_Demo-Secuencia.o -L$(LIB) -lSecuencia $(CXXFLAGS)

$(BIN)/III_DemoMatriz2D : \
              $(OBJ)/III_DemoMatriz2D.o \
              $(LIB)/libMatriz2D.a
	@echo 
	@echo Creando ejecutable: III_DemoMatriz2D
	@echo 
	$(CXX) -o $(BIN)/III_DemoMatriz2D \
         $(OBJ)/III_DemoMatriz2D.o -L$(LIB) -lMatriz2D $(CXXFLAGS)
###############################################################################
#OPCIONALES
###############################################################################
$(BIN)/III_Demo-Pila : \
              $(OBJ)/III_Demo-Pila.o \
              $(LIB)/libPila.a $(LIB)/libLista.a
	@echo 
	@echo Creando ejecutable: III_Demo-Pila
	@echo 
	$(CXX) -o $(BIN)/III_Demo-Pila \
         $(OBJ)/III_Demo-Pila.o -L$(LIB) -lPila -lLista $(CXXFLAGS)

$(BIN)/III_Demo-Cola : \
			$(OBJ)/III_Demo-Cola.o \
              $(LIB)/libCola.a $(LIB)/libLista.a
	@echo 
	@echo Creando ejecutable: III_Demo-Cola
	@echo 
	$(CXX) -o $(BIN)/III_Demo-Cola \
         $(OBJ)/III_Demo-Cola.o -L$(LIB) -lCola $(CXXFLAGS)
###############################################################################
#OBJETOS
###############################################################################
$(OBJ)/III_Demo-Secuencia.o : \
              $(SRC)/III_Demo-Secuencia.cpp \
              $(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBase_Secuencia.h
	@echo 
	@echo Creando objeto: III_Demo-Secuencia.o
	@echo
	$(CXX) -c -o $(OBJ)/III_Demo-Secuencia.o $(SRC)/III_Demo-Secuencia.cpp  \
        $(CXXFLAGS) 

$(OBJ)/III_DemoMatriz2D.o : \
              $(SRC)/III_DemoMatriz2D.cpp \
              $(INCLUDE)/Matriz2D.h $(INCLUDE)/TipoBaseMatriz.h
	@echo 
	@echo Creando objeto: III_DemoMatriz2D.o
	@echo
	$(CXX) -c -o $(OBJ)/III_DemoMatriz2D.o $(SRC)/III_DemoMatriz2D.cpp  \
	$(CXXFLAGS)

###############################################################################
#OPCIONALES
###############################################################################
$(OBJ)/III_Demo-Pila.o : \
              $(SRC)/III_Demo-Pila.cpp \
              $(INCLUDE)/Pila.h $(INCLUDE)/Lista.h
	@echo 
	@echo Creando objeto: III_Demo-Pila.o
	@echo
	$(CXX) -c -o $(OBJ)/III_Demo-Pila.o $(SRC)/III_Demo-Pila.cpp  \
        $(CXXFLAGS) 

$(OBJ)/III_Demo-Cola.o: \
              $(SRC)/III_Demo-Cola.cpp \
              $(INCLUDE)/Cola.h $(INCLUDE)/Lista.h
	@echo 
	@echo Creando objeto: III_Demo-Cola.o
	@echo
	$(CXX) -c -o $(OBJ)/III_Demo-Cola.o $(SRC)/III_Demo-Cola.cpp  \
    $(CXXFLAGS)

###############################################################################
arbol :
	-@tree $(OBJ) $(BIN) $(LIB)
###############################################################################

###############################################################################
#SECUENCIA
###############################################################################
$(OBJ)/Secuencia.o : $(SRC)/Secuencia.cpp \
                     $(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBase_Secuencia.h
	@echo 
	@echo Creando objeto: Secuencia.o
	@echo  
	g++ -c -o $(OBJ)/Secuencia.o  $(SRC)/Secuencia.cpp \
       -I$(INCLUDE) -std=c++11

$(LIB)/libSecuencia.a : $(OBJ)/Secuencia.o
	@echo 
	@echo Creando biblioteca: libSecuencia.a 
	@echo  
	ar rvs $(LIB)/libSecuencia.a  $(OBJ)/Secuencia.o


###############################################################################
#LISTA
###############################################################################
$(LIB)/libLista.a : $(OBJ)/Lista.o
	@echo Creando biblioteca: libLista.a 
	ar rvs $(LIB)/libLista.a \
	$(OBJ)/Lista.o 
	@echo
 
$(OBJ)/Lista.o: $(SRC)/Lista.cpp
	@echo Creando Lista.o
	$(CXX) -c -o $(OBJ)/Lista.o \
	$(SRC)/Lista.cpp $(CXXFLAGS) 
	@echo

###############################################################################
#PILA
###############################################################################
$(LIB)/libPila.a : $(OBJ)/Pila.o $(OBJ)/Lista.o
	@echo Creando biblioteca: libPila.a 
	ar rvs $(LIB)/libPila.a \
	$(OBJ)/Pila.o $(OBJ)/Lista.o
	@echo
 
$(OBJ)/Pila.o: $(SRC)/Pila.cpp $(INCLUDE)/Lista.h
	@echo Creando Pila.o
	$(CXX) -c -o $(OBJ)/Pila.o \
	$(SRC)/Pila.cpp $(CXXFLAGS) 
	@echo

###############################################################################
#COLA
###############################################################################
$(LIB)/libCola.a : $(OBJ)/Cola.o $(OBJ)/Lista.o
	@echo Creando biblioteca: libCola.a 
	ar rvs $(LIB)/libCola.a \
	$(OBJ)/Cola.o $(OBJ)/Lista.o
	@echo
 
$(OBJ)/Cola.o: $(SRC)/Cola.cpp $(INCLUDE)/Lista.h
	@echo Creando Cola.o
	$(CXX) -c -o $(OBJ)/Cola.o \
	$(SRC)/Cola.cpp $(CXXFLAGS) 
	@echo

###############################################################################
#FUNCIONES_VECTOR_DINAMICO
###############################################################################
$(LIB)/libFuncsVectorDinamico.a : $(OBJ)/FuncsVectorDinamico.o 
	@echo Creando biblioteca: libFuncsVectorDinamico.a 
	ar rvs $(LIB)/libFuncsVectorDinamico.a \
	$(OBJ)/FuncsVectorDinamico.o
	@echo
 
$(OBJ)/FuncsVectorDinamico.o: $(SRC)/FuncsVectorDinamico.cpp
	@echo Creando FuncsVectorDinamico.o
	$(CXX) -c -o $(OBJ)/FuncsVectorDinamico.o \
	$(SRC)/FuncsVectorDinamico.cpp $(CXXFLAGS) 
	@echo


###############################################################################
#GENERADOR_ALEATORIO_ENTEROS
###############################################################################
$(LIB)/libGeneradorAleatorioEnteros.a : $(OBJ)/GeneradorAleatorioEnteros.o 
	@echo Creando biblioteca: libGeneradorAleatorioEnteros.a 
	ar rvs $(LIB)/libGeneradorAleatorioEnteros.a \
	$(OBJ)/GeneradorAleatorioEnteros.o
	@echo
 
$(OBJ)/GeneradorAleatorioEnteros.o : \
$(SRC)/GeneradorAleatorioEnteros.cpp \
$(INCLUDE)/GeneradorAleatorioEnteros.h
	@echo Creando objeto: GeneradorAleatorioEnteros.o 
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
		$(SRC)/GeneradorAleatorioEnteros.cpp $(CXXFLAGS)
	@echo

###############################################################################
#MATRIZ2D
###############################################################################
$(LIB)/libMatriz2D.a : $(OBJ)/Matriz2D.o $(OBJ)/Secuencia.o
	@echo Creando biblioteca: libMatriz2D.a 
	ar rvs $(LIB)/libMatriz2D.a \
	$(OBJ)/Matriz2D.o $(OBJ)/Secuencia.o
	@echo
 
$(OBJ)/Matriz2D.o : $(SRC)/Matriz2D.cpp $(INCLUDE)/Matriz2D.h \
$(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBaseMatriz.h
	@echo Creando objeto: Matriz2D.o 
	g++ -c -o $(OBJ)/Matriz2D.o \
		$(SRC)/Matriz2D.cpp $(CXXFLAGS)
	@echo


###############################################################################
#LIMPIEZA
###############################################################################
clean :
	@echo  Borrando objetos...
	-rm -r $(OBJ)/*
	@echo

clean-objs :
	@echo  Borrando objetos...
	-rm -r $(OBJ)/*
	@echo

clean-bin :
	@echo Borrando ejecutables...
	-rm -r $(BIN)/*
	@echo

clean-lib :
	@echo Borrando bibliotecas...
	-rm -r $(LIB)/*
	@echo

mr.proper : clean-objs clean-bin clean-lib

###############################################################################
#PREAMBULO
###############################################################################

preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo
	@echo Fichero makefile
	@echo
	@echo METODOLOGÍA DE LA PROGRAMACIÓN
	@echo
	@echo Pablo Huertas Arroyo
	@echo
	@echo ------------------------------------------------------------
	@echo

###############################################################################
#FINAL
###############################################################################

final :
	@echo ------------------------------------------------------------
	@echo

###############################################################################
#TEST
###############################################################################

test :

