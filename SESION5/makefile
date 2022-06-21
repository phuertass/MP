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

OBJETOS = $(BIN)/I_MezclaArrays_ref $(BIN)/I_DemoSecuenciaEnteros \
$(BIN)/I_NuevoOrdenEnteros_Ampliacion

OPCIONALES = $(BIN)/I_PalabrasSeudoSimetricas \
$(BIN)/I_MaxMin_Array \
$(BIN)/I_LeeEntero \
$(BIN)/I_TextoRectangular 


.PHONY : clean
.PHONY : mr.proper

###############################################################################

all : preambulo $(OBJETOS) $(OPCIONALES) arbol final 

###############################################################################
#EJECUTABLES
###############################################################################

$(BIN)/I_MezclaArrays_ref : $(OBJ)/I_MezclaArrays_ref.o \
$(OBJ)/ProcesamientoArrayInt.o $(LIB)/libGeneradorAleatorioEnteros.a 
	@echo Creando I_MezclaArrays_ref
	$(CXX) -o $(BIN)/I_MezclaArrays_ref \
	$(OBJ)/I_MezclaArrays_ref.o $(CXXFLAGS) $(OBJ)/ProcesamientoArrayInt.o \
	-lGeneradorAleatorioEnteros -L$(LIB)
	@echo

$(BIN)/I_DemoSecuenciaEnteros: $(OBJ)/I_DemoSecuenciaEnteros.o \
$(LIB)/libSecuenciaEnteros.a $(LIB)/libGeneradorAleatorioEnteros.a
	@echo Creando I_DemoSecuenciaEnteros
	$(CXX) -o $(BIN)/I_DemoSecuenciaEnteros \
	$(OBJ)/I_DemoSecuenciaEnteros.o $(CXXFLAGS) -lSecuenciaEnteros \
	-lGeneradorAleatorioEnteros -L$(LIB)
	@echo

$(BIN)/I_NuevoOrdenEnteros_Ampliacion : $(OBJ)/I_NuevoOrdenEnteros_Ampliacion.o \
$(OBJ)/ProcesamientoArrayInt.o $(LIB)/libGeneradorAleatorioEnteros.a
	@echo Creando I_NuevoOrdenEnteros_Ampliacion
	$(CXX) -o $(BIN)/I_NuevoOrdenEnteros_Ampliacion \
	$(OBJ)/I_NuevoOrdenEnteros_Ampliacion.o $(CXXFLAGS) $(OBJ)/ProcesamientoArrayInt.o \
	-lGeneradorAleatorioEnteros -L$(LIB)
	@echo

#OPCIONALES
$(BIN)/I_LeeEntero : $(OBJ)/I_LeeEntero.o \
$(OBJ)/MiCadenaClasica.o $(OBJ)/LecturaEnteros.o \
$(OBJ)/ProcesamientoArrayInt.o \
$(LIB)/libGeneradorAleatorioEnteros.a
	@echo Creando $@
	$(CXX) -o $@ $< $(CXXFLAGS) $(OBJ)/MiCadenaClasica.o \
	$(OBJ)/LecturaEnteros.o $(OBJ)/ProcesamientoArrayInt.o \
	-lGeneradorAleatorioEnteros -L./$(LIB)
	@echo


$(BIN)/I_PalabrasSeudoSimetricas : $(OBJ)/I_PalabrasSeudoSimetricas.o \
$(OBJ)/MiCadenaClasica.o
	@echo Creando $@
	$(CXX) -o $@ $< $(CXXFLAGS) $(OBJ)/MiCadenaClasica.o
	@echo

$(BIN)/I_TextoRectangular : $(OBJ)/I_TextoRectangular.o \
$(OBJ)/MiCadenaClasica.o
	@echo Creando $@
	$(CXX) -o $@ $< $(CXXFLAGS) $(OBJ)/MiCadenaClasica.o
	@echo

$(BIN)/I_MaxMin_Array : $(OBJ)/I_MaxMin_Array.o \
$(OBJ)/ProcesamientoArrayInt.o $(LIB)/libGeneradorAleatorioEnteros.a
	@echo Creando I_MaxMin_Array
	$(CXX) -o $(BIN)/I_MaxMin_Array \
	$(OBJ)/I_MaxMin_Array.o $(CXXFLAGS) $(OBJ)/ProcesamientoArrayInt.o \
	-lGeneradorAleatorioEnteros -L$(LIB)
	@echo
###############################################################################
#OBJETOS
###############################################################################



$(OBJ)/I_MezclaArrays_ref.o: $(SRC)/I_MezclaArrays_ref.cpp \
$(INCLUDE)/ProcesamientoArrayInt.h
	@echo Creando I_MezclaArrays_ref.o
	$(CXX) -c -o $(OBJ)/I_MezclaArrays_ref.o \
	$(SRC)/I_MezclaArrays_ref.cpp $(CXXFLAGS) 
	@echo

$(OBJ)/I_DemoSecuenciaEnteros.o: $(SRC)/I_DemoSecuenciaEnteros.cpp \
$(INCLUDE)/SecuenciaEnteros.h
	@echo Creando I_DemoSecuenciaEnteros.o
	$(CXX) -c -o $(OBJ)/I_DemoSecuenciaEnteros.o \
	$(SRC)/I_DemoSecuenciaEnteros.cpp $(CXXFLAGS) 
	@echo

$(OBJ)/I_NuevoOrdenEnteros_Ampliacion.o: $(SRC)/I_NuevoOrdenEnteros_Ampliacion.cpp \
$(INCLUDE)/ProcesamientoArrayInt.h
	@echo Creando I_NuevoOrdenEnteros_Ampliacion.o
	$(CXX) -c -o $(OBJ)/I_NuevoOrdenEnteros_Ampliacion.o \
	$(SRC)/I_NuevoOrdenEnteros_Ampliacion.cpp $(CXXFLAGS) 
	@echo

#OPCIONALES
$(OBJ)/I_LeeEntero.o : $(SRC)/I_LeeEntero.cpp \
$(INCLUDE)/MiCadenaClasica.h $(INCLUDE)/LecturaEnteros.h \
$(INCLUDE)/ProcesamientoArrayInt.h $(INCLUDE)/GeneradorAleatorioEnteros.h
	@echo Creando $@
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	@echo

$(OBJ)/I_PalabrasSeudoSimetricas.o : $(SRC)/I_PalabrasSeudoSimetricas.cpp \
$(INCLUDE)/MiCadenaClasica.h
	@echo Creando $@
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	@echo

$(OBJ)/I_TextoRectangular.o : $(SRC)/I_TextoRectangular.cpp \
$(INCLUDE)/MiCadenaClasica.h
	@echo Creando $@
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	@echo

$(OBJ)/I_MaxMin_Array.o: $(SRC)/I_MaxMin_Array.cpp \
$(INCLUDE)/ProcesamientoArrayInt.h
	@echo Creando I_MaxMin_Array.o
	$(CXX) -c -o $(OBJ)/I_MaxMin_Array.o \
	$(SRC)/I_MaxMin_Array.cpp $(CXXFLAGS) 
	@echo

#FUNCIONES
$(OBJ)/MiCadenaClasica.o : $(SRC)/MiCadenaClasica.cpp
	@echo Creando MiCadenaClasica.o 
	$(CXX) -c -o $(OBJ)/MiCadenaClasica.o \
	$(SRC)/MiCadenaClasica.cpp $(CXXFLAGS)
	@echo

$(OBJ)/LecturaEnteros.o : $(SRC)/LecturaEnteros.cpp
	@echo Creando LecturaEnteros.o 
	$(CXX) -c -o $(OBJ)/LecturaEnteros.o \
	$(SRC)/LecturaEnteros.cpp $(CXXFLAGS)
	@echo

###############################################################################
arbol :
	@tree $(OBJ) $(BIN) $(LIB)
###############################################################################

###############################################################################
#SECUENCIA ENTEROS
###############################################################################
$(OBJ)/SecuenciaEnteros.o : $(SRC)/SecuenciaEnteros.cpp \
                  $(INCLUDE)/SecuenciaEnteros.h \
				  $(INCLUDE)/GeneradorAleatorioEnteros.h
	@echo Creando objeto: SecuenciaEnteros.o
	$(CXX) -c -o $(OBJ)/SecuenciaEnteros.o \
			$(SRC)/SecuenciaEnteros.cpp $(CXXFLAGS)
	@echo

$(LIB)/libSecuenciaEnteros.a : $(OBJ)/SecuenciaEnteros.o 
	@echo Creando biblioteca: libSecuenciaEnteros.a 
	ar rvs $(LIB)/libSecuenciaEnteros.a \
	$(OBJ)/SecuenciaEnteros.o
	@echo

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



