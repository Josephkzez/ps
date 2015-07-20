#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../CUnit/CUnit.h"
#include "../CUnit/Basic.h" 
#include "mod_impl_discente.c"


/*
 * Função que adiciona ao registro do CUnit os testes para todas as funções 
 * presentes no arquivo mod_impldiscente_teste.c
 */
void adicionar_testes_mod_impl_discente(void);

/* Abaixo estão as funções que efetuam os testes para a função setListaDiscente */
void teste_setListaDiscente_diferente_de_nulo(void);
void teste_setListaDiscente_arquivo_nao_existe(void);
//void teste_setListaDiscente_arquivo_em_branco(void);

/* Testa ponteiro não vazio após a chamada da função */
void teste_setListaDiscente_diferente_de_nulo(void){
	
	ListaDiscente * pinicio;
	
	char * arquivo = "Arquivos/discentes_mestrado.txt"; 
	pinicio = NULL;

	setListaDiscente(&pinicio, arquivo);
	
	
	CU_ASSERT_PTR_NOT_NULL( pinicio);
	
}

/* Teste arquivo nao existe, o ponteiro pinicio deve sair nulo */
void teste_setListaDiscente_arquivo_nao_existe(void){
	
	ListaDiscente * pinicio;
	
	char * arquivo = "Arquivos/discentes_mestradwweweweweweowoo.txt"; 
	pinicio = NULL;

	
	setListaDiscente(&pinicio, arquivo);
	
	CU_ASSERT_PTR_NULL(  pinicio);
	
}

/*void teste_setListaDiscente_arquivo_em_branco(void){
	
	ListaDiscente * pinicio;
	
	char * arquivo = "Arquivos/arquivo_em_branco.txt"; 
	pinicio = NULL;

	
	setListaDiscente(&pinicio, arquivo);
	
	CU_ASSERT_PTR_NULL(  pinicio);
	
}
*/

void adicionar_testes_mod_impl_discente(void) {
	
   CU_pSuite suite;
	
	/* Cria uma suite que conterá todos os testes */
	suite = CU_add_suite("Testes da lista de discente",NULL,NULL);
   
   /* Adiciona os testes para a função DT_ChecaData */
   
   CU_ADD_TEST(suite, teste_setListaDiscente_diferente_de_nulo);
   CU_ADD_TEST(suite, teste_setListaDiscente_arquivo_nao_existe);
   //CU_ADD_TEST(suite, teste_setListaDiscente_arquivo_em_branco);
   
}

int main(void) {
	
	/* Inicializa o registro de suites e testes do CUnit */	
	if (CUE_SUCCESS != CU_initialize_registry())
    	return CU_get_error();
    
   /* Adiciona os testes ao registro */ 	
   adicionar_testes_mod_impl_discente();
	
	/* Muda o modo do CUnit para o modo VERBOSE
	 * O modo VERBOSE mostra algumas informacoes a
	 * mais na hora da execucao */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	
	/* Roda os testes e mostra na tela os resultados */
	CU_basic_run_tests();
	
	/* Limpa o registro */
	CU_cleanup_registry();
	
	return CU_get_error();
	
}


