
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


.PHONY : clean
.PHONY : mr.proper

OBJETOS = $(BIN)/I_EliminarBlancos \
$(BIN)/I_EncuentraPalabras \
$(BIN)/I_ErastotenesFactoresPrimos \
$(BIN)/I_OrdenaMatrizEnteros \
$(BIN)/I_Ley_Dhont


###############################################################################

all : preambulo mr.proper $(OBJETOS) arbol final 

###############################################################################
#EJECUTABLES
###############################################################################


$(BIN)/I_Ley_Dhont : $(OBJ)/I_Ley_Dhont.o $(OBJ)/FuncionesDHont.o 
	@echo Creando I_Ley_Dhont
	$(CXX) -o $(BIN)/I_Ley_Dhont \
	$(OBJ)/I_Ley_Dhont.o $(CXXFLAGS) $(OBJ)/FuncionesDHont.o 
	@echo

$(BIN)/I_ErastotenesFactoresPrimos : $(OBJ)/I_ErastotenesFactoresPrimos.o \
$(OBJ)/FuncionesErastotenes.o
	@echo Creando I_ErastotenesFactoresPrimos
	$(CXX) -o $(BIN)/I_ErastotenesFactoresPrimos \
	$(OBJ)/I_ErastotenesFactoresPrimos.o $(CXXFLAGS) \
	$(OBJ)/FuncionesErastotenes.o
	@echo


$(BIN)/I_EliminarBlancos : $(OBJ)/I_EliminarBlancos.o $(OBJ)/MiCadenaClasica.o 
	@echo Creando I_EliminarBlancos
	$(CXX) -o $(BIN)/I_EliminarBlancos \
	$(OBJ)/I_EliminarBlancos.o $(CXXFLAGS) $(OBJ)/MiCadenaClasica.o 
	@echo


$(BIN)/I_EncuentraPalabras : $(OBJ)/I_EncuentraPalabras.o \
							$(OBJ)/MiCadenaClasica.o
	@echo Creando I_ErastotenesFactoresPrimos
	$(CXX) -o $(BIN)/I_EncuentraPalabras \
	$(OBJ)/I_EncuentraPalabras.o $(CXXFLAGS) \
	$(OBJ)/MiCadenaClasica.o
	@echo

$(BIN)/I_OrdenaMatrizEnteros: $(OBJ)/I_OrdenaMatrizEnteros.o \
                    $(OBJ)/Funcs_MatrizEnteros.o \
                    $(OBJ)/ProcesamientoArrayInt.o \
                    $(LIB)/libGeneradorAleatorioEnteros.a 
	@echo 
	@echo Creando ejecutable: I_OrdenaMatrizEnteros
	@echo 
	g++ -o $(BIN)/I_OrdenaMatrizEnteros $(OBJ)/I_OrdenaMatrizEnteros.o \
	       $(OBJ)/Funcs_MatrizEnteros.o \
	       $(OBJ)/ProcesamientoArrayInt.o \
		  -lGeneradorAleatorioEnteros -L$(LIB)

###############################################################################
arbol :
	@tree $(OBJ) $(BIN) $(LIB)
###############################################################################

###############################################################################
#OBJETOS
###############################################################################



$(OBJ)/I_ErastotenesFactoresPrimos.o : $(SRC)/I_ErastotenesFactoresPrimos.cpp \
$(INCLUDE)/FuncionesErastotenes.h
	@echo Creando I_ErastotenesFactoresPrimos.o
	$(CXX) -c -o $(OBJ)/I_ErastotenesFactoresPrimos.o \
	$(SRC)/I_ErastotenesFactoresPrimos.cpp $(CXXFLAGS)
	@echo

$(OBJ)/FuncionesErastotenes.o : $(SRC)/FuncionesErastotenes.cpp
	@echo Creando FuncionesErastotenes.o
	$(CXX) -c -o $(OBJ)/FuncionesErastotenes.o \
	$(SRC)/FuncionesErastotenes.cpp $(CXXFLAGS)
	@echo

$(OBJ)/I_Ley_Dhont.o : $(SRC)/I_Ley_Dhont.cpp $(INCLUDE)/FuncionesDHont.h 
	@echo Creando I_Ley_Dhont.o
	$(CXX) -c -o $(OBJ)/I_Ley_Dhont.o \
	$(SRC)/I_Ley_Dhont.cpp $(CXXFLAGS)
	@echo

$(OBJ)/FuncionesDHont.o : $(SRC)/FuncionesDHont.cpp $(INCLUDE)/FuncionesDHont.h
	@echo Creando FuncionesDHont.o
	$(CXX) -c -o $(OBJ)/FuncionesDHont.o \
	$(SRC)/FuncionesDHont.cpp $(CXXFLAGS)
	@echo


$(OBJ)/I_EliminarBlancos.o : $(SRC)/I_EliminarBlancos.cpp $(INCLUDE)/MiCadenaClasica.h
	@echo Creando I_EliminarBlancos.o 
	$(CXX) -c -o $(OBJ)/I_EliminarBlancos.o \
	$(SRC)/I_EliminarBlancos.cpp $(CXXFLAGS)
	@echo

$(OBJ)/MiCadenaClasica.o : $(SRC)/MiCadenaClasica.cpp
	@echo Creando MiCadenaClasica.o 
	$(CXX) -c -o $(OBJ)/MiCadenaClasica.o \
	$(SRC)/MiCadenaClasica.cpp $(CXXFLAGS)
	@echo

$(OBJ)/I_EncuentraPalabras.o : $(SRC)/I_EncuentraPalabras.cpp \
$(INCLUDE)/MiCadenaClasica.h
	@echo Creando I_EncuentraPalabras.o 
	$(CXX) -c -o $(OBJ)/I_EncuentraPalabras.o \
	$(SRC)/I_EncuentraPalabras.cpp $(CXXFLAGS)
	@echo

$(OBJ)/I_OrdenaMatrizEnteros.o : $(SRC)/I_OrdenaMatrizEnteros.cpp \
$(INCLUDE)/GeneradorAleatorioEnteros.h \
$(INCLUDE)/ProcesamientoArrayInt.h \
$(INCLUDE)/config_matrices.h
	@echo 
	@echo Creando objeto: I_OrdenaMatrizEnteros.o
	@echo 
	g++ -c -o $(OBJ)/I_OrdenaMatrizEnteros.o \
	          $(SRC)/I_OrdenaMatrizEnteros.cpp \
	          -I$(INCLUDE) -std=c++14 

####################################################################
$(OBJ)/Funcs_MatrizEnteros.o : $(SRC)/Funcs_MatrizEnteros.cpp \
                               $(INCLUDE)/Funcs_MatrizEnteros.h \
                         	   $(INCLUDE)/ProcesamientoArrayInt.h \
                  			   $(INCLUDE)/config_matrices.h
	@echo 
	@echo Creando objeto: Funcs_MatrizEnteros.o 
	@echo 
	g++ -c -o $(OBJ)/Funcs_MatrizEnteros.o $(SRC)/Funcs_MatrizEnteros.cpp \
        -I$(INCLUDE) -I$(INCLUDE) -std=c++14
###############################################################################
#PROCESAMIENTO_ARRAY_INT
###############################################################################
$(OBJ)/ProcesamientoArrayInt.o : $(SRC)/ProcesamientoArrayInt.cpp \
                  $(INCLUDE)/ProcesamientoArrayInt.h 
	@echo Creando objeto: ProcesamientoArrayInt.o
	$(CXX) -c -o $(OBJ)/ProcesamientoArrayInt.o \
			$(SRC)/ProcesamientoArrayInt.cpp $(CXXFLAGS)
	@echo

###############################################################################
#GENERADOR_ALEATORIO_ENTEROS
###############################################################################


$(LIB)/libGeneradorAleatorioEnteros.a : $(OBJ)/GeneradorAleatorioEnteros.o 
	@echo Creando biblioteca: libGeneradorAleatorioEnteros.a LÑL
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
