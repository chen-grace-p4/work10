all: main.o work10.o
	gcc -o work10 main.o work10.o
main.o: main.c work10.h
	gcc -c main.c
work10.o: work10.c work10.h
	gcc -c work10.c
run:
	./work10
clean:
	rm *.o
	rm work10
