lab1_output: lab1.o lab1Main.o 
	gcc lab1.o lab1Main.o -o lab1_output 
   
lab1.o: lab1.c
	gcc -Wall -std=c99 -c lab1.c 
   
lab1Main.o: lab1Main.c
	gcc -Wall -std=c99 -c lab1Main.c 
 
clean: 
	rm *.o lab1_output 