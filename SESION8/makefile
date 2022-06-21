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

OBJETOS = $(BIN)/II_OrdenarLista \
$(BIN)/II_Demo-Lista \
$(BIN)/II_EstadisticaBasica_ListaAleatoria \
$(BIN)/II_Invierte_Lista


OPCIONALES = $(BIN)/II_GestionarListaOrdenada

.PHONY : clean
.PHONY : mr.proper

###############################################################################

all : preambulo $(OBJETOS) $(OPCIONALES) arbol final 

###############################################################################
#EJECUTABLES
###############################################################################
$(BIN)/II_OrdenarLista : $(OBJ)/II_OrdenarLista.o \
		$(LIB)/libLista.a $(LIB)/libGeneradorAleatorioEnteros.a
		@echo 
	@echo Creando : $(BIN)/II_OrdenarLista
	@echo 
	$(CXX) -o $(BIN)/II_OrdenarLista \
	       $(OBJ)/II_OrdenarLista.o \
	       -L$(LIB) -lLista \
	       -lGeneradorAleatorioEnteros $(CXXFLAGS)

$(BIN)/II_Demo-Lista : $(OBJ)/II_Demo-Lista.o \
		$(LIB)/libLista.a $(LIB)/libGeneradorAleatorioEnteros.a
		@echo 
	@echo Creando : $(BIN)/II_Demo-ListadenarLista
	@echo 
	$(CXX) -o $(BIN)/II_Demo-Lista \
	       $(OBJ)/II_Demo-Lista.o \
	       -L$(LIB) -lLista \
	       -lGeneradorAleatorioEnteros $(CXXFLAGS)

$(BIN)/II_EstadisticaBasica_ListaAleatoria : \
		$(OBJ)/II_EstadisticaBasica_ListaAleatoria.o \
		$(LIB)/libLista.a $(LIB)/libGeneradorAleatorioEnteros.a
		@echo 
	@echo Creando : $(BIN)/II_EstadisticaBasica_ListaAleatoria
	@echo 
	$(CXX) -o $(BIN)/II_EstadisticaBasica_ListaAleatoria \
	       $(OBJ)/II_EstadisticaBasica_ListaAleatoria.o \
	       -L$(LIB) -lLista \
	       -lGeneradorAleatorioEnteros $(CXXFLAGS)

$(BIN)/II_Invierte_Lista : \
		$(OBJ)/II_Invierte_Lista.o \
		$(LIB)/libLista.a $(LIB)/libGeneradorAleatorioEnteros.a
		@echo 
	@echo Creando : $(BIN)/II_Invierte_Lista
	@echo 
	$(CXX) -o $(BIN)/II_Invierte_Lista \
	       $(OBJ)/II_Invierte_Lista.o \
	       -L$(LIB) -lLista \
	       -lGeneradorAleatorioEnteros $(CXXFLAGS)
###############################################################################
#OPCIONALES
###############################################################################
$(BIN)/II_GestionarListaOrdenada : \
		$(OBJ)/II_GestionarListaOrdenada.o \
		$(LIB)/libLista.a $(LIB)/libGeneradorAleatorioEnteros.a
		@echo 
	@echo Creando : $(BIN)/II_GestionarListaOrdenada
	@echo 
	$(CXX) -o $(BIN)/II_GestionarListaOrdenada \
	       $(OBJ)/II_GestionarListaOrdenada.o \
	       -L$(LIB) -lLista \
	       -lGeneradorAleatorioEnteros $(CXXFLAGS)


###############################################################################
#OBJETOS
###############################################################################
$(OBJ)/II_OrdenarLista.o : $(SRC)/II_OrdenarLista.cpp \
		$(INCLUDE)/Lista.h $(INCLUDE)/GeneradorAleatorioEnteros.h
		@echo 
	@echo Creando : $(OBJ)/II_OrdenarLista.o
	@echo 
	$(CXX) -c -o  $(OBJ)/II_OrdenarLista.o \
	       $(SRC)/II_OrdenarLista.cpp $(CXXFLAGS)

$(OBJ)/II_Demo-Lista.o : $(SRC)/II_Demo-Lista.cpp \
		$(INCLUDE)/Lista.h $(INCLUDE)/GeneradorAleatorioEnteros.h
		@echo 
	@echo Creando : $(OBJ)/II_Demo-Lista.o
	@echo 
	$(CXX) -c -o  $(OBJ)/II_Demo-Lista.o\
	       $(SRC)/II_Demo-Lista.cpp $(CXXFLAGS)

$(OBJ)/II_EstadisticaBasica_ListaAleatoria.o : \
		$(SRC)/II_EstadisticaBasica_ListaAleatoria.cpp \
		$(INCLUDE)/Lista.h $(INCLUDE)/GeneradorAleatorioEnteros.h
		@echo 
	@echo Creando : $(OBJ)/II_EstadisticaBasica_ListaAleatoria.o
	@echo 
	$(CXX) -c -o  $(OBJ)/II_EstadisticaBasica_ListaAleatoria.o\
	       $(SRC)/II_EstadisticaBasica_ListaAleatoria.cpp $(CXXFLAGS)

$(OBJ)/II_Invierte_Lista.o : \
		$(SRC)/II_Invierte_Lista.cpp \
		$(INCLUDE)/Lista.h $(INCLUDE)/GeneradorAleatorioEnteros.h
		@echo 
	@echo Creando : $(OBJ)/II_Invierte_Lista.o
	@echo 
	$(CXX) -c -o  $(OBJ)/II_Invierte_Lista.o\
	       $(SRC)/II_Invierte_Lista.cpp $(CXXFLAGS)

###############################################################################
#OPCIONALES
###############################################################################
$(OBJ)/II_GestionarListaOrdenada.o : \
		$(SRC)/II_GestionarListaOrdenada.cpp \
		$(INCLUDE)/Lista.h $(INCLUDE)/GeneradorAleatorioEnteros.h
		@echo 
	@echo Creando : $(OBJ)/II_GestionarListaOrdenada.o
	@echo 
	$(CXX) -c -o  $(OBJ)/II_GestionarListaOrdenada.o\
	       $(SRC)/II_GestionarListaOrdenada.cpp $(CXXFLAGS)
###############################################################################
arbol :
	@tree $(OBJ) $(BIN) $(LIB)
###############################################################################

###############################################################################
#LISTA
###############################################################################
$(LIB)/libLista.a : $(OBJ)/Lista.o $(OBJ)/GeneradorAleatorioEnteros.o
	@echo Creando biblioteca: libLista.a 
	ar rvs $(LIB)/libLista.a \
	$(OBJ)/Lista.o $(OBJ)/GeneradorAleatorioEnteros.o
	@echo
 
$(OBJ)/Lista.o: $(SRC)/Lista.cpp $(INCLUDE)/GeneradorAleatorioEnteros.h
	@echo Creando Lista.o
	$(CXX) -c -o $(OBJ)/Lista.o \
	$(SRC)/Lista.cpp $(CXXFLAGS) 
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
$(LIB)/libMatriz2D.a : $(OBJ)/Matriz2D.o 
	@echo Creando biblioteca: libMatriz2D.a 
	ar rvs $(LIB)/libMatriz2D.a \
	$(OBJ)/Matriz2D.o
	@echo
 
$(OBJ)/Matriz2D.o : \
$(SRC)/Matriz2D.cpp \
$(INCLUDE)/Matriz2D.h
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

