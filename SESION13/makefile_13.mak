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

OBJETOS = $(BIN)/NumeraLineas_Ampliacion \
$(BIN)/MensajesOcultos-2 \
$(BIN)/InfoPGM \
$(BIN)/VI_Demo-Lista \
$(BIN)/VI_Demo-Matriz \
$(BIN)/Verifica_FicheroMarcas


OPCIONALES = 

.PHONY : clean
.PHONY : mr.proper

###############################################################################

all : preambulo $(OBJETOS) $(OPCIONALES) arbol final 

###############################################################################
#EJECUTABLES
###############################################################################
$(BIN)/NumeraLineas_Ampliacion : $(OBJ)/NumeraLineas_Ampliacion.o
	$(CXX) -o $(BIN)/NumeraLineas_Ampliacion \
	$(OBJ)/NumeraLineas_Ampliacion.o $(CXXFLAGS) 

$(BIN)/MensajesOcultos-2 : $(OBJ)/MensajesOcultos-2.o
	$(CXX) -o $(BIN)/MensajesOcultos-2 \
	$(OBJ)/MensajesOcultos-2.o $(CXXFLAGS)

$(BIN)/InfoPGM : $(OBJ)/InfoPGM.o
	$(CXX) -o $(BIN)/InfoPGM \
	$(OBJ)/InfoPGM.o $(CXXFLAGS)

$(BIN)/VI_Demo-Lista: $(OBJ)/VI_Demo-Lista.o $(LIB)/libLista.a
	$(CXX) -o $(BIN)/VI_Demo-Lista \
	$(OBJ)/VI_Demo-Lista.o $(CXXFLAGS) -L$(LIB) -lLista

$(BIN)/VI_Demo-Matriz : $(OBJ)/VI_Demo-Matriz.o $(LIB)/libMatriz2D.a
	$(CXX) -o $(BIN)/VI_Demo-Matriz \
	$(OBJ)/VI_Demo-Matriz.o $(CXXFLAGS) -L$(LIB) -lMatriz2D

$(BIN)/Verifica_FicheroMarcas : $(OBJ)/Verifica_FicheroMarcas.o
	$(CXX) -o $(BIN)/Verifica_FicheroMarcas \
	$(OBJ)/Verifica_FicheroMarcas.o $(CXXFLAGS)

$(BIN)/IV_Demo-Matriz : $(OBJ)/VI_Demo-Matriz.o $(LIB)/libMatriz2D.a \
$(LIB)/libSecuencia.a
	$(CXX) -o $(BIN)/IV_Demo-Matriz \
	$(OBJ)/VI_Demo-Matriz.o $(CXXFLAGS) -L$(LIB) -lMatriz2D -lSecuencia

###############################################################################
#OPCIONALES
###############################################################################
$(BIN)/CopiaCodigoSinComentarios: $(OBJ)/CopiaCodigoSinComentarios.o
	$(CXX) -o $(BIN)/CopiaCodigoSinComentarios \
	$(OBJ)/CopiaCodigoSinComentarios.o $(CXXFLAGS)

$(BIN)/Cabecera: $(OBJ)/Cabecera.o
	$(CXX) -o $(BIN)/Cabecera \
	$(OBJ)/Cabecera.o $(CXXFLAGS)

$(BIN)/Final: $(OBJ)/Final.o
	$(CXX) -o $(BIN)/Final \
	$(OBJ)/Final.o $(CXXFLAGS)

###############################################################################
#OBJETOS
###############################################################################
$(OBJ)/NumeraLineas_Ampliacion.o : $(SRC)/NumeraLineas_Ampliacion.cpp
	$(CXX) -c -o $(OBJ)/NumeraLineas_Ampliacion.o \
	$(SRC)/NumeraLineas_Ampliacion.cpp $(CXXFLAGS) 

$(OBJ)/MensajesOcultos-2.o : $(SRC)/MensajesOcultos-2.cpp
	$(CXX) -c -o $(OBJ)/MensajesOcultos-2.o \
	$(SRC)/MensajesOcultos-2.cpp $(CXXFLAGS)

$(OBJ)/InfoPGM.o : $(SRC)/InfoPGM.cpp
	$(CXX) -c -o $(OBJ)/InfoPGM.o \
	$(SRC)/InfoPGM.cpp $(CXXFLAGS)

$(OBJ)/VI_Demo-Lista.o: $(SRC)/VI_Demo-Lista.cpp $(INCLUDE)/Lista.h
	$(CXX) -c -o $(OBJ)/VI_Demo-Lista.o \
	$(SRC)/VI_Demo-Lista.cpp $(CXXFLAGS)

$(OBJ)/VI_Demo-Matriz.o : $(SRC)/VI_Demo-Matriz.cpp $(INCLUDE)/Matriz2D.h
	$(CXX) -c -o $(OBJ)/VI_Demo-Matriz.o \
	$(SRC)/VI_Demo-Matriz.cpp $(CXXFLAGS)

$(OBJ)/Verifica_FicheroMarcas.o : $(SRC)/Verifica_FicheroMarcas.cpp
	$(CXX) -c -o $(OBJ)/Verifica_FicheroMarcas.o \
	$(SRC)/Verifica_FicheroMarcas.cpp $(CXXFLAGS)

$(OBJ)/VI_Demo-Matriz.o: $(SRC)/VI_Demo-Matriz.cpp $(INCLUDE)/Matriz2D.h
	$(CXX) -c -o $(OBJ)/VI_Demo-Matriz.o \
	$(SRC)/VI_Demo-Matriz.cpp $(CXXFLAGS)

###############################################################################
#OPCIONALES
###############################################################################
$(OBJ)/CopiaCodigoSinComentarios.o: $(SRC)/CopiaCodigoSinComentarios.cpp
	$(CXX) -c -o $(OBJ)/CopiaCodigoSinComentarios.o \
	$(SRC)/CopiaCodigoSinComentarios.cpp $(CXXFLAGS)

$(OBJ)/Cabecera.o: $(SRC)/Cabecera.cpp
	$(CXX) -c -o $(OBJ)/Cabecera.o \
	$(SRC)/Cabecera.cpp $(CXXFLAGS)

$(OBJ)/Final.o: $(SRC)/Final.cpp
	$(CXX) -c -o $(OBJ)/Final.o \
	$(SRC)/Final.cpp $(CXXFLAGS)

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
$(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBaseMatriz2D.h
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

