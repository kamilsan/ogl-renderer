CC = g++
CFLAGS = -std=c++11 -Wall -Wextra
CINC = -I ./include/
CLIBS = -lglfw -lGL -lm -ldl -lXinerama -lXrandr -lXi -lXcursor -lX11 -lXxf86vm -lpthread

all:
	$(CC) -o renderer $(CFLAGS) $(CINC) ./src/glad.c main.cpp $(CLIBS)

clean:
	rm -rf *.o renderer