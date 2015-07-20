ARCH = i386
#ARCH = amd64
LEITURA = ./Leitura

all: prog limpa

prog: main.o mod_discente.o mod_projeto.o
	gcc -g -Wall main.o mod_discente.o mod_projeto.o -o prog
	./prog
	
#	test: main.c main_test.c
#	gcc -I ./CUnit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test
#	./test

main.o: main.c
	gcc -c -g -Wall main.c
	
mod_discente.o: $(LEITURA)/mod_def_discente.h $(LEITURA)/mod_impl_discente.c
	gcc -c -g -Wall $(LEITURA)/mod_impl_discente.c -o mod_discente.o
	
mod_projeto.o: $(LEITURA)/mod_def_projeto.h $(LEITURA)/mod_impl_projeto.c
	gcc -c -g -Wall $(LEITURA)/mod_impl_projeto.c -o mod_projeto.o
	
#	gcov: main.c main_test.c
#	gcc -Wall -ftest-coverage -fprofile-args -I ./Cunit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test_gcov
#	./test_gcov
	
limpa: 
	rm *.o 
#	rm *.gcda *.gcno *gcov
