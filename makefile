app: main.cpp idtag.o
	g++ -o app main.cpp idtag.o
idtag.o: idtag.cpp
	g++ idtag.cpp -c
clean:
	rm -f *.o app
