#Fazer make out no terminal

all:
	gcc -o saida main.c montador.h montador.c -lm
	rm -rf montador.h.gch
out:
	./saida