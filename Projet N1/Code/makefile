main : main.o template.o reflex.o ../lib/libisentlib.a
	gcc -Wall -o main main.o reflex.o template.o ../lib/libisentlib.a -lm -lglut -lGL -lX11

main.o : main.c
	gcc -c -Wall main.c

template.o : template.c
	gcc -c -Wall template.c

reflex.o : reflex.c
	gcc -c -Wall reflex.c

clean:
	rm *.o
