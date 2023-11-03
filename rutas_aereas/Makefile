BIN = bin
OBJ = obj
SRC = src
INC = include
IMG=datos/imagenes/resultado.ppm



$(BIN)/rutas_aereas: $(OBJ)/rutas_aereas.o $(OBJ)/imagen.o $(OBJ)/almacen_rutas.o  $(OBJ)/Punto.o $(OBJ)/Ruta.o $(OBJ)/imagenES.o
		echo Creando el ejecutable.
		g++ $(OBJ)/rutas_aereas.o $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/almacen_rutas.o  $(OBJ)/Punto.o $(OBJ)/Ruta.o -o $(BIN)/rutas_aereas
		
		
		
$(OBJ)/almacen_rutas.o: $(SRC)/almacen_rutas.cpp $(INC)/almacen_rutas.h
		echo Creando almacen_rutas.o.
		g++ -g -c -I./$(INC) $(SRC)/almacen_rutas.cpp -o $(OBJ)/almacen_rutas.o

$(OBJ)/Punto.o: $(SRC)/Punto.cpp $(INC)/Punto.h
		echo Creando Punto.o.
		g++ -g -c -I./$(INC) $(SRC)/Punto.cpp -o $(OBJ)/Punto.o
		
$(OBJ)/Ruta.o: $(SRC)/Ruta.cpp $(INC)/Ruta.h
		echo Creando Ruta.o.
		g++ -g -c -I./$(INC) $(SRC)/Ruta.cpp -o $(OBJ)/Ruta.o
		
		
$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h 
		echo Creando imagen.o.
		g++ -g -c -I./$(INC) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o
		
$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
		echo Creando imagenES.o.
		g++ -g -c -I./$(INC) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o
		
		
		

$(OBJ)/rutas_aereas.o: $(SRC)/rutas_aereas.cpp $(INC)/imagen.h $(INC)/imagenES.h $(INC)/almacen_rutas.h $(INC)/Paises.h $(INC)/Punto.h $(INC)/Ruta.h
		echo Creando el rutas_aereas.o.
		g++ -g -c -I./$(INC)  $(SRC)/rutas_aereas.cpp -o $(OBJ)/rutas_aereas.o
		

clean:
		echo Limpiando.
		-rm $(OBJ)/* $(BIN)/* $(IMG)
		
		

rebuild:	clean $(BIN)/rutas_aereas

	
