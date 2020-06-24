main : main.o accueil.o synchro.o menu.o memoire.o template.o reflex.o ../lib/libisentlib.a
	gcc -Wall -o main main.o synchro.o accueil.o memoire.o menu.o reflex.o template.o ../lib/libisentlib.a -lm -lglut -lGL -lX11

main.o : main.c
	gcc -c -Wall main.c

template.o : template.c
	gcc -c -Wall template.c

reflex.o : reflex.c
	gcc -c -Wall reflex.c
	
menu.o : menu.c
	gcc -c -Wall menu.c

accueil.o : accueil.c
	gcc -c -Wall accueil.c
	
memoire.o : memoire.c
	gcc -c -Wall memoire.c
	
synchro.o : synchro.c
	gcc -c -Wall synchro.c

clean:
	rm *.o
