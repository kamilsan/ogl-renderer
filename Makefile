CC = g++
CFLAGS = -std=c++11 -Wall -Wextra
CINC = -I ./include/
CLIBS = -lglfw -lGL -lm -ldl -lXinerama -lXrandr -lXi -lXcursor -lX11 -lXxf86vm -lpthread

renderer: shaderProgram.o main.cpp
	$(CC) -o renderer $(CFLAGS) $(CINC) ./src/glad.c shaderProgram.o main.cpp $(CLIBS)

shaderProgram.o: shaderProgram.cpp shaderProgram.h
	$(CC) -c ./src/glad.c shaderProgram.cpp $(CFLAGS) $(CINC)

clean:
	rm -rf *.o renderer