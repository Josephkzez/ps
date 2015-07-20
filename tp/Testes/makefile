all: mod_impl_discente.c mod_impl_discente_teste.c
	gcc -I ../CUnit -L ../CUnit mod_impl_discente_teste.c -lcunit_amd64 -o teste
	./teste
	
gcov: mod_impl_discente.c mod_impl_discente_teste.c
	gcc -Wall -ftest-coverage -fprofile-args -I ../Cunit -L ../CUnit mod_impl_discente_teste.c -lcunit_amd64 -o teste_gcov
	./teste_gcov
	
limpa: rm *.gcda *.gcno *gcov
