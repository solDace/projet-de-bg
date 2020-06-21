main : main.o menu.o template.o reflex.o ../lib/libisentlib.a
	gcc -Wall -o main main.o menu.o reflex.o template.o ../lib/libisentlib.a -lm -lglut -lGL -lX11

main.o : main.c
	gcc -c -Wall main.c

template.o : template.c
	gcc -c -Wall template.c

reflex.o : reflex.c
	gcc -c -Wall reflex.c
	
menu.o : menu.c
	gcc -c -Wall menu.c

clean:
	rm *.o
