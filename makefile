vyasVedantA1: vyasVedantA1.o vyasVedantA1Main.o
	gcc -Wall -std=c99 vyasVedantA1.o vyasVedantA1Main.c -o vyasVedantA1

vyasVedantA1.o: vyasVedantA1.c givenA1.h
	gcc -Wall -std=c99 -c vyasVedantA1.c

vyasVedantA1Main.o: vyasVedantA1Main.c givenA1.h
	gcc -Wall -std=c99 -c vyasVedantA1Main.c

clean:
	rm *.o vyasVedantA1
	