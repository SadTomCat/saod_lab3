main: ./built/Dijkstra.o ./built/generation.o ./built/heap.o ./built/main.o
	gcc -o ./bin/main ./built/Dijkstra.o  ./built/generation.o ./built/heap.o  ./built/main.o 
	 
./built/Dijkstra.o: ./src/Dijkstra.c
	gcc -o ./built/Dijkstra.o -c ./src/Dijkstra.c

./built/heap.o: ./src/heap.c
	gcc -o ./built/heap.o -c ./src/heap.c

./built/main.o: ./src/main.c
	gcc -o ./built/main.o -c ./src/main.c

./built/generation.o: ./src/generation.c
	gcc -o ./built/generation.o -c ./src/generation.c

run: ./bin/main
	./bin/main

clean:
	rm ./bin/main 

clean_o: 
	rm ./built/*.o
	rm ./bin/*
