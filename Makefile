#My first makefile

all: compila teste limpasaida executa clean

compila: *.c
	gcc -c $^

teste: *.o
	gcc $^ -o test

limpasaida:
	rm -rf *.txt *~ ./Saida

executa:
	mkdir Saida
	valgrind ./test

%.o: %.c 
	gcc -c $<

clean:
	rm -rf *.o *~ trabalho
	rm test