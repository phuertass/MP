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

OBJETOS = $(BIN)/Prueba_VectorMarcas_Fase8 \
$(BIN)/Prueba_MatrizMarcas_Fase8 \
$(BIN)/RankingMarcas_Fase8


OPCIONALES = 

.PHONY : clean
.PHONY : mr.proper

###############################################################################

all : preambulo $(OBJETOS) $(OPCIONALES) arbol final 

###############################################################################
#EJECUTABLES
###############################################################################

$(BIN)/% : $(OBJ)/%.o
	@echo Creando $@a
	$(CXX) -o $@ $< $(CXXFLAGS) 
	@echo

$(BIN)/RankingMarcas_Fase6 : $(OBJ)/RankingMarcas_Fase6.o \
$(LIB)/libMatrizMarcas.a $(LIB)/libVectorMarcas.a \
$(LIB)/libRegistroDeMarca.a
	@echo Creando II_Demo-MatrizMarcas
	$(CXX) -o $(BIN)/RankingMarcas_Fase6 \
	$(OBJ)/RankingMarcas_Fase6.o $(CXXFLAGS)  \
	-lMatrizMarcas -lVectorMarcas -lRegistroDeMarca -L$(LIB)
	@echo

$(BIN)/RankingMarcas_Fase8 : $(OBJ)/RankingMarcas_Fase8.o \
$(LIB)/libMatrizMarcas.a $(LIB)/libVectorMarcas.a \
$(LIB)/libRegistroDeMarca.a
	@echo Creando II_Demo-MatrizMarcas
	$(CXX) -o $(BIN)/RankingMarcas_Fase8 \
	$(OBJ)/RankingMarcas_Fase8.o $(CXXFLAGS)  \
	-lMatrizMarcas -lVectorMarcas -lRegistroDeMarca -L$(LIB)
	@echo

$(BIN)/Prueba_VectorMarcas_Fase8 : $(OBJ)/Prueba_VectorMarcas_Fase8.o \
$(LIB)/libVectorMarcas.a $(LIB)/libRegistroDeMarca.a $(OBJ)/utils.o
	@echo Creando Prueba_VectorMarcas_Fase8
	$(CXX) -o $(BIN)/Prueba_VectorMarcas_Fase8 \
	$(OBJ)/Prueba_VectorMarcas_Fase8.o $(OBJ)/utils.o $(CXXFLAGS)  \
	-lVectorMarcas -lRegistroDeMarca -L$(LIB)
	@echo

$(BIN)/Prueba_MatrizMarcas_Fase8 : $(OBJ)/Prueba_MatrizMarcas_Fase8.o \
$(LIB)/libMatrizMarcas.a $(LIB)/libRegistroDeMarca.a
	@echo Creando Prueba_MatrizMarcas_Fase8
	$(CXX) -o $(BIN)/Prueba_MatrizMarcas_Fase8 \
	$(OBJ)/Prueba_MatrizMarcas_Fase8.o $(CXXFLAGS)  \
	-lMatrizMarcas -lVectorMarcas -lRegistroDeMarca -L$(LIB)
	@echo

$(BIN)/MM7 : $(OBJ)/MM7.o $(LIB)/libMatrizMarcas.a \
$(LIB)/libVectorMarcas.a $(LIB)/libRegistroDeMarca.a
	@echo Creando MM7
	$(CXX) -o $(BIN)/MM7 $(OBJ)/MM7.o $(CXXFLAGS)  \
	-lMatrizMarcas -lVectorMarcas -lRegistroDeMarca -L$(LIB)
	@echo

$(BIN)/VM7 : $(OBJ)/VM7.o $(LIB)/libMatrizMarcas.a \
$(LIB)/libVectorMarcas.a $(LIB)/libRegistroDeMarca.a
	@echo Creando VM7
	$(CXX) -o $(BIN)/VM7 $(OBJ)/VM7.o $(CXXFLAGS)  \
	-lMatrizMarcas -lVectorMarcas -lRegistroDeMarca -L$(LIB)
	@echo

$(BIN)/main7 : $(OBJ)/main7.o $(LIB)/libMatrizMarcas.a \
$(LIB)/libVectorMarcas.a $(LIB)/libRegistroDeMarca.a
	@echo Creando main7
	$(CXX) -o $(BIN)/main7 $(OBJ)/main7.o $(CXXFLAGS)  \
	-lMatrizMarcas -lVectorMarcas -lRegistroDeMarca -L$(LIB)
	@echo

###############################################################################
#OBJETOS
###############################################################################
$(OBJ)/%.o : $(SRC)/%.cpp
	@echo Creando $@
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	@echo


$(OBJ)/RankingMarcas_Fase6.o : $(SRC)/RankingMarcas_Fase6.cpp \
$(INCLUDE)/MatrizMarcas.h $(INCLUDE)/VectorMarcas.h \
$(INCLUDE)/RegistroDeMarca.h
	@echo Creando RankingMarcas_Fase6.o
	$(CXX) -c -o $(OBJ)/RankingMarcas_Fase6.o  \
	$(SRC)/RankingMarcas_Fase6.cpp  $(CXXFLAGS)
	@echo

$(OBJ)/Prueba_MatrizMarcas_Fase8.o : $(SRC)/Prueba_MatrizMarcas_Fase8.cpp \
$(INCLUDE)/MatrizMarcas.h $(INCLUDE)/VectorMarcas.h \
$(INCLUDE)/RegistroDeMarca.h
	@echo Creando Prueba_MatrizMarcas_Fase8.o
	$(CXX) -c -o $(OBJ)/Prueba_MatrizMarcas_Fase8.o  \
	$(SRC)/Prueba_MatrizMarcas_Fase8.cpp  $(CXXFLAGS)
	@echo

###############################################################################
#CLASES PROYECTO
###############################################################################
$(OBJ)/Tiempo.o : $(SRC)/Tiempo.cpp
	@echo Creando Tiempo.o
	$(CXX) -c -o $(OBJ)/Tiempo.o  \
	$(SRC)/Tiempo.cpp  $(CXXFLAGS)
	@echo

$(OBJ)/Fecha.o : $(SRC)/Fecha.cpp
	@echo Creando Fecha.o
	$(CXX) -c -o $(OBJ)/Fecha.o  \
	$(SRC)/Fecha.cpp  $(CXXFLAGS)
	@echo

$(OBJ)/utils.o : $(SRC)/utils.cpp
	@echo Creando utils.o
	$(CXX) -c -o $(OBJ)/utils.o  \
	$(SRC)/utils.cpp  $(CXXFLAGS)
	@echo

###############################################################################
arbol :
	-@tree $(OBJ) $(BIN) $(LIB)
###############################################################################

###############################################################################
#VECTOR_MARCAS
###############################################################################


$(LIB)/libRegistroDeMarca.a : $(OBJ)/RegistroDeMarca.o $(OBJ)/Tiempo.o\
$(OBJ)/utils.o $(OBJ)/Fecha.o
	@echo Creando biblioteca: libRegistroDeMarca.a 
	ar rvs $(LIB)/libRegistroDeMarca.a \
	$(OBJ)/RegistroDeMarca.o $(OBJ)/Tiempo.o $(OBJ)/utils.o $(OBJ)/Fecha.o
	@echo
 
$(OBJ)/RegistroDeMarca.o : $(SRC)/RegistroDeMarca.cpp \
$(INCLUDE)/MatrizMarcas.h $(INCLUDE)/Tiempo.h $(INCLUDE)/utils.h \
$(INCLUDE)/Fecha.h
	@echo Creando RegistroDeMarca.o
	$(CXX) -c -o $(OBJ)/RegistroDeMarca.o  \
	$(SRC)/RegistroDeMarca.cpp  $(CXXFLAGS)
	@echo

###############################################################################
#VECTOR_MARCAS
###############################################################################


$(LIB)/libVectorMarcas.a : $(OBJ)/VectorMarcas.o $(OBJ)/utils.o
	@echo Creando biblioteca: libVectorMarcas.a 
	ar rvs $(LIB)/libVectorMarcas.a \
	$(OBJ)/VectorMarcas.o $(OBJ)/utils.o
	@echo
 
$(OBJ)/VectorMarcas.o: $(SRC)/VectorMarcas.cpp $(INCLUDE)/utils.h
	@echo Creando II_Demo-VectorMarcas.o
	$(CXX) -c -o $(OBJ)/VectorMarcas.o \
	$(SRC)/VectorMarcas.cpp $(CXXFLAGS) 
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
#MATRIZ_MARCAS
###############################################################################
$(LIB)/libMatrizMarcas.a : $(OBJ)/MatrizMarcas.o 
	@echo Creando biblioteca: libMatrizMarcas.a 
	ar rvs $(LIB)/libMatrizMarcas.a \
	$(OBJ)/MatrizMarcas.o
	@echo
 
$(OBJ)/MatrizMarcas.o : \
$(SRC)/MatrizMarcas.cpp \
$(INCLUDE)/MatrizMarcas.h
	@echo Creando objeto: MatrizMarcas.o 
	g++ -c -o $(OBJ)/MatrizMarcas.o \
		$(SRC)/MatrizMarcas.cpp $(CXXFLAGS)
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
	@echo PROYECTO GESTION DE MARCAS DE ATLETISMO
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

