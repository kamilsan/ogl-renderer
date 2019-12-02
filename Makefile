CC = g++
CFLAGS = -std=c++11 -Wall -Wextra
CINC = -I ./include/
CLIBS = -lglfw -lGL -lm -ldl -lXinerama -lXrandr -lXi -lXcursor -lX11 -lXxf86vm -lpthread

renderer: window.o shaderProgram.o main.cpp
	$(CC) -o renderer $(CFLAGS) $(CINC) ./src/glad.c window.o shaderProgram.o main.cpp $(CLIBS)

window.o: window.hpp window.cpp
	$(CC) -c window.cpp $(CFLAGS) $(CINC)

shaderProgram.o: shaderProgram.cpp shaderProgram.hpp
	$(CC) -c shaderProgram.cpp $(CFLAGS) $(CINC)

clean:
	rm -rf *.o renderer