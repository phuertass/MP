#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# sesion07.mak
#
# makefile para la sesión de prácticas 7
#
#############################################################################

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
	  $(LIB_CLASES_UTILS)/libMatriz2D_char_RLE.a \
	  $(BIN)/II_RLE \
	  final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejercicios de la Relación de Problemas I
	@echo Sesion de practicas 7
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


$(BIN)/II_RLE :  \
          $(OBJ)/II_RLE.o \
          $(OBJ)/Funcs_VectorDinamicoCadenas.o \
          $(LIB)/libMatriz2D_char_RLE.a

	@echo 
	@echo Creando ejecutable: II_RLE
	@echo 
	g++ -o $(BIN)/II_RLE $(OBJ)/II_RLE.o \
           $(OBJ)/Funcs_VectorDinamicoCadenas.o \
           -L$(LIB) -lMatriz2D_char_RLE

#................................................
# OBJETOS 

$(OBJ)/II_RLE.o : $(SRC)/II_RLE.cpp \
            $(INCLUDE)/Funcs_VectorDinamicoCadenas.h\
            $(INCLUDE)/Matriz2D_char_RLE.h \
            $(INCLUDE)/TipoBase_char.h \

	@echo 
	@echo Creando objeto: II_RLE.o
	@echo 
	g++ -c -o $(OBJ)/II_RLE.o  $(SRC)/II_RLE.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Funcs_VectorDinamicoCadenas.o : \
            $(SRC)/Funcs_VectorDinamicoCadenas.cpp \
            $(INCLUDE)/Funcs_VectorDinamicoCadenas.h
	@echo 
	@echo Creando objeto: Funcs_VectorDinamicoCadenas.o
	@echo 
	g++ -c -o $(OBJ)/Funcs_VectorDinamicoCadenas.o \
              $(SRC)/Funcs_VectorDinamicoCadenas.cpp \
             -I$(INCLUDE) -std=c++11

#................................................
# BIBLIOTECAS


# libMatriz2D_char.a .................................

$(OBJ)/Matriz2D_char_RLE.o : $(SRC)/Matriz2D_char_RLE.cpp \
                    $(INCLUDE)/Matriz2D_char_RLE.h \
                    $(INCLUDE)/TipoBase_char.h 
	@echo 
	@echo Creando objeto: Matriz2D_char_RLE.o
	@echo 
	g++ -c -o $(OBJ)/Matriz2D_char_RLE.o $(SRC)/Matriz2D_char_RLE.cpp \
	         -I$(INCLUDE) -std=c++11

$(LIB)/libMatriz2D_char_RLE.a : $(OBJ)/Matriz2D_char_RLE.o 
	@echo 
	@echo Creando biblioteca: libMatriz2D_char_RLE.a 
	@echo   
	ar rvs $(LIB)/libMatriz2D_char_RLE.a $(OBJ)/Matriz2D_char_RLE.o 

#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs: 
	@echo Borrando objetos de la sesion de practicas 7...

	-rm $(OBJ)/II_RLE.o

	-rm $(OBJ)/Funcs_VectorDinamicoCadenas.o 
	-rm $(OBJ)/Matriz2D_char_RLE.o

	@echo ...Borrados objetos de la sesion de practicas 7
	@echo 

clean-libs: 
	@echo Borrando bibliotecas de la sesion de practicas 7...

	-rm $(LIB_CLASES_UTILS)/libMatriz2D_char_RLE.a

	@echo ...Borradas bibliotecas de la sesion de practicas 7
	@echo 

clean-bins : 
	@echo Borrando ejecutables de la sesion de practicas 7...

	-rm $(BIN)/II_RLE 

	@echo ...Borrados ejecutables de la sesion de practicas 7

mr.proper:  clean-objs clean-libs clean-bins

