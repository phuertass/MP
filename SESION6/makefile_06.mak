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

OBJETOS = $(BIN)/II_Demo-VectorDinamicoCadenas \
$(BIN)/II_FactoresPrimos_VectorDinamicoPrimos \
$(BIN)/II_Demo-VectorDinamico 

OPCIONALES = $(BIN)/II_Demo2-VectorDinamico  

.PHONY : clean
.PHONY : mr.proper

###############################################################################

all : preambulo mr.proper $(OBJETOS) $(OPCIONALES) arbol final 

###############################################################################
#EJECUTABLES
###############################################################################
$(BIN)/II_Demo-VectorDinamico : $(OBJ)/II_Demo-VectorDinamico.o \
$(LIB)/libFuncsVectorDinamico.a $(LIB)/libGeneradorAleatorioEnteros.a
	@echo Creando II_Demo-VectorDinamico.o 
	$(CXX) -o $(BIN)/II_Demo-VectorDinamico \
	$(OBJ)/II_Demo-VectorDinamico.o $(CXXFLAGS) \
	-lFuncsVectorDinamico -lGeneradorAleatorioEnteros -L$(LIB)
	@echo


$(BIN)/II_FactoresPrimos_VectorDinamicoPrimos : \
$(OBJ)/II_FactoresPrimos_VectorDinamicoPrimos.o \
$(OBJ)/FuncionesErastotenes.o \
$(LIB)/libFuncsVectorDinamico.a
	@echo Creando II_FactoresPrimos_VectorDinamicoPrimos
	$(CXX) -o $(BIN)/II_FactoresPrimos_VectorDinamicoPrimos \
	$(OBJ)/II_FactoresPrimos_VectorDinamicoPrimos.o $(CXXFLAGS) \
	$(OBJ)/FuncionesErastotenes.o \
	-lFuncsVectorDinamico -L$(LIB)
	@echo

$(BIN)/II_Demo-VectorDinamicoCadenas :  \
          $(OBJ)/II_Demo-VectorDinamicoCadenas.o \
          $(OBJ)/Funcs_VectorDinamicoCadenas.o
		  
	@echo
	@echo Creando ejecutable: II_Demo-VectorDinamicoCadenas
	@echo 
	$(CXX) -o $(BIN)/II_Demo-VectorDinamicoCadenas \
           $(OBJ)/II_Demo-VectorDinamicoCadenas.o \
           $(OBJ)/Funcs_VectorDinamicoCadenas.o $(CXXFLAGS)

###############################################################################
#OPCIONALES
###############################################################################
$(BIN)/II_EncuentraPalabras_MemDin :  \
          $(OBJ)/II_EncuentraPalabras_MemDin.o \
		  $(OBJ)/MiCadenaClasica.o \
		  $(LIB)/libFuncsVectorDinamico.a
	@echo
	@echo Creando ejecutable: II_EncuentraPalabras_MemDin
	@echo 
	$(CXX) -o $(BIN)/II_EncuentraPalabras_MemDin \
           $(OBJ)/II_EncuentraPalabras_MemDin.o \
		   -lFuncsVectorDinamico -L$(LIB) \
		   $(OBJ)/MiCadenaClasica.o $(CXXFLAGS)

$(BIN)/II_Demo2-VectorDinamico : $(OBJ)/II_Demo2-VectorDinamico.o \
$(LIB)/libFuncsVectorDinamico.a $(LIB)/libGeneradorAleatorioEnteros.a
	@echo Creando II_Demo2-VectorDinamico.o 
	$(CXX) -o $(BIN)/II_Demo2-VectorDinamico \
	$(OBJ)/II_Demo2-VectorDinamico.o $(CXXFLAGS) \
	-lFuncsVectorDinamico -lGeneradorAleatorioEnteros -L$(LIB)
	@echo

###############################################################################
#OBJETOS
###############################################################################
$(OBJ)/II_Demo-VectorDinamico.o: $(SRC)/II_Demo-VectorDinamico.cpp \
$(INCLUDE)/FuncsVectorDinamico.h $(INCLUDE)/GeneradorAleatorioEnteros.h
	@echo Creando II_Demo-VectorDinamico.o
	$(CXX) -c -o $(OBJ)/II_Demo-VectorDinamico.o \
	$(SRC)/II_Demo-VectorDinamico.cpp $(CXXFLAGS) 
	@echo

$(OBJ)/II_FactoresPrimos_VectorDinamicoPrimos.o : \
$(SRC)/II_FactoresPrimos_VectorDinamicoPrimos.cpp \
$(INCLUDE)/FuncionesErastotenes.h
	@echo Creando II_FactoresPrimos_VectorDinamicoPrimos.o
	$(CXX) -c -o $(OBJ)/II_FactoresPrimos_VectorDinamicoPrimos.o \
	$(SRC)/II_FactoresPrimos_VectorDinamicoPrimos.cpp $(CXXFLAGS)
	@echo


$(OBJ)/FuncionesErastotenes.o : $(SRC)/FuncionesErastotenes.cpp \
$(INCLUDE)/FuncsVectorDinamico.h
	@echo Creando FuncionesErastotenes.o
	$(CXX) -c -o $(OBJ)/FuncionesErastotenes.o \
	$(SRC)/FuncionesErastotenes.cpp $(CXXFLAGS)
	@echo

$(OBJ)/II_Demo-VectorDinamicoCadenas.o : \
            $(SRC)/II_Demo-VectorDinamicoCadenas.cpp \
			$(INCLUDE)/Funcs_VectorDinamicoCadenas.h
	@echo 
	@echo Creando objeto: II_Demo-VectorDinamicoCadenas.o
	@echo 
	$(CXX) -c -o $(OBJ)/II_Demo-VectorDinamicoCadenas.o \
              $(SRC)/II_Demo-VectorDinamicoCadenas.cpp \
              $(CXXFLAGS)

$(OBJ)/Funcs_ColeccionCadenas.o : \
            $(SRC)/Funcs_ColeccionCadenas.cpp \
            $(INCLUDE)/Funcs_ColeccionCadenas.h
	@echo 
	@echo Creando objeto: Funcs_ColeccionCadenas.o
	@echo 
	$(CXX) -c -o $(OBJ)/Funcs_ColeccionCadenas.o \
              $(SRC)/Funcs_ColeccionCadenas.cpp  \
              $(CXXFLAGS)

$(OBJ)/Funcs_VectorDinamicoCadenas.o : \
			$(SRC)/Funcs_VectorDinamicoCadenas.cpp \
            $(INCLUDE)/Funcs_VectorDinamicoCadenas.h
	@echo 
	@echo Creando objeto: Funcs_VectorDinamicoCadenas.o
	@echo 
	$(CXX) -c -o $(OBJ)/Funcs_VectorDinamicoCadenas.o \
              $(SRC)/Funcs_VectorDinamicoCadenas.cpp  \
              $(CXXFLAGS)
###############################################################################
#OPCIONALES
###############################################################################
$(OBJ)/II_EncuentraPalabras_MemDin.o : $(SRC)/II_EncuentraPalabras_MemDin.cpp \
$(INCLUDE)/FuncsVectorDinamico.h $(INCLUDE)/MiCadenaClasica.h
	@echo Creando II_EncuentraPalabras_MemDin.o
	$(CXX) -c -o $(OBJ)/II_EncuentraPalabras_MemDin.o \
	$(SRC)/II_EncuentraPalabras_MemDin.cpp $(CXXFLAGS)
	@echo

$(OBJ)/MiCadenaClasica.o : $(SRC)/MiCadenaClasica.cpp
	@echo Creando MiCadenaClasica.o 
	$(CXX) -c -o $(OBJ)/MiCadenaClasica.o \
	$(SRC)/MiCadenaClasica.cpp $(CXXFLAGS)
	@echo

$(OBJ)/II_Demo2-VectorDinamico.o: $(SRC)/II_Demo2-VectorDinamico.cpp \
$(INCLUDE)/FuncsVectorDinamico.h $(INCLUDE)/GeneradorAleatorioEnteros.h
	@echo Creando II_Demo2-VectorDinamico.o
	$(CXX) -c -o $(OBJ)/II_Demo2-VectorDinamico.o \
	$(SRC)/II_Demo2-VectorDinamico.cpp $(CXXFLAGS) 
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

