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

OBJETOS =  $(BIN)/II_Robot_Tablero \
$(BIN)/II_Demo-Matriz2D 


OPCIONALES = $(BIN)/II_ProblemaAsignacion \
$(BIN)/II_ProblemaViajanteComercio \
$(BIN)/II_ProblemaViajanteComercio_Ampliacion 
.PHONY : clean
.PHONY : mr.proper

###############################################################################

all : preambulo $(OBJETOS) $(OPCIONALES) arbol final 

###############################################################################
#EJECUTABLES
###############################################################################
$(BIN)/II_Demo-Matriz2D : $(OBJ)/II_Demo-Matriz2D.o \
$(LIB)/libMatriz2D.a
	@echo Creando II_Demo-Matriz2D
	$(CXX) -o $(BIN)/II_Demo-Matriz2D \
	$(OBJ)/II_Demo-Matriz2D.o $(CXXFLAGS) \
	-lMatriz2D -L$(LIB)
	@echo

$(BIN)/II_Robot_Tablero : $(OBJ)/II_Robot_Tablero.o \
$(LIB)/libMatriz2D.a $(LIB)/libFuncsVectorDinamico.a
	@echo Creando II_Robot_Tablero
	$(CXX) -o $(BIN)/II_Robot_Tablero \
	$(OBJ)/II_Robot_Tablero.o $(CXXFLAGS) \
	-lMatriz2D -lFuncsVectorDinamico -L$(LIB)
	@echo

###############################################################################
#OPCIONALES
###############################################################################
$(BIN)/II_ProblemaAsignacion : $(OBJ)/II_ProblemaAsignacion.o \
$(LIB)/libMatriz2D.a $(LIB)/libFuncsVectorDinamico.a
	@echo Creando II_ProblemaAsignacion
	$(CXX) -o $(BIN)/II_ProblemaAsignacion \
	$(OBJ)/II_ProblemaAsignacion.o $(CXXFLAGS) \
	-lMatriz2D -lFuncsVectorDinamico -L$(LIB)
	@echo

$(BIN)/II_ProblemaViajanteComercio : $(OBJ)/II_ProblemaViajanteComercio.o \
$(LIB)/libMatriz2D.a $(LIB)/libFuncsVectorDinamico.a
	@echo Creando II_ProblemaViajanteComercio
	$(CXX) -o $(BIN)/II_ProblemaViajanteComercio \
	$(OBJ)/II_ProblemaViajanteComercio.o $(CXXFLAGS) \
	-lMatriz2D -lFuncsVectorDinamico -L$(LIB)
	@echo

$(BIN)/II_ProblemaViajanteComercio_Ampliacion : \
$(OBJ)/II_ProblemaViajanteComercio_Ampliacion.o \
$(LIB)/libMatriz2D.a $(LIB)/libFuncsVectorDinamico.a
	@echo Creando II_ProblemaViajanteComercio_Ampliacion
	$(CXX) -o $(BIN)/II_ProblemaViajanteComercio_Ampliacion \
	$(OBJ)/II_ProblemaViajanteComercio_Ampliacion.o $(CXXFLAGS) \
	-lMatriz2D -lFuncsVectorDinamico -L$(LIB)
	@echo
###############################################################################
#OBJETOS
###############################################################################
$(OBJ)/II_Demo-Matriz2D.o : $(SRC)/II_Demo-Matriz2D.cpp \
$(INCLUDE)/Matriz2D.h
	@echo Creando II_Demo-Matriz2D.o
	$(CXX) -c -o $(OBJ)/II_Demo-Matriz2D.o  \
	$(SRC)/II_Demo-Matriz2D.cpp  $(CXXFLAGS)
	@echo

$(OBJ)/II_Robot_Tablero.o : $(SRC)/II_Robot_Tablero.cpp \
$(INCLUDE)/Matriz2D.h $(INCLUDE)/FuncsVectorDinamico.h
	@echo Creando III_Robot_Tablero.o
	$(CXX) -c -o $(OBJ)/II_Robot_Tablero.o  \
	$(SRC)/II_Robot_Tablero.cpp  $(CXXFLAGS)
	@echo

###############################################################################
#OPCIONALES
###############################################################################
$(OBJ)/II_ProblemaAsignacion.o : $(SRC)/II_ProblemaAsignacion.cpp \
$(INCLUDE)/Matriz2D.h $(INCLUDE)/FuncsVectorDinamico.h
	@echo Creando II_ProblemaAsignacion.o
	$(CXX) -c -o $(OBJ)/II_ProblemaAsignacion.o  \
	$(SRC)/II_ProblemaAsignacion.cpp  $(CXXFLAGS)
	@echo

$(OBJ)/II_ProblemaViajanteComercio.o : $(SRC)/II_ProblemaViajanteComercio.cpp \
$(INCLUDE)/Matriz2D.h $(INCLUDE)/FuncsVectorDinamico.h
	@echo Creando II_ProblemaViajanteComercio.o
	$(CXX) -c -o $(OBJ)/II_ProblemaViajanteComercio.o  \
	$(SRC)/II_ProblemaViajanteComercio.cpp  $(CXXFLAGS)
	@echo

$(OBJ)/II_ProblemaViajanteComercio_Ampliacion.o : \
$(SRC)/II_ProblemaViajanteComercio_Ampliacion.cpp \
$(INCLUDE)/Matriz2D.h $(INCLUDE)/FuncsVectorDinamico.h
	@echo Creando II_ProblemaViajanteComercio_Ampliacion.o
	$(CXX) -c -o $(OBJ)/II_ProblemaViajanteComercio_Ampliacion.o  \
	$(SRC)/II_ProblemaViajanteComercio_Ampliacion.cpp  $(CXXFLAGS)
	@echo
###############################################################################
arbol :
	@tree $(OBJ) $(BIN) $(LIB)
###############################################################################

###############################################################################
#FUNCIONES_VECTOR_DINAMICO
###############################################################################


$(LIB)/libFuncsVectorDinamico.a : $(OBJ)/FuncsVectorDinamico.o 
	@echo Creando biblioteca: libFuncsVectorDinamico.a 
	ar rvs $(LIB)/libFuncsVectorDinamico.a \
	$(OBJ)/FuncsVectorDinamico.o
	@echo
 
$(OBJ)/FuncsVectorDinamico.o: $(SRC)/FuncsVectorDinamico.cpp
	@echo Creando II_Demo-VectorDinamico.o
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

