/**	
*	@file mod_def_projeto.h 
*	@brief Arquivo cabeçalho para leitura de projeto.
*	@author Danilo Alves.
* 	@author José Siqueira.
*	@since 01/03/15.
*	@version 1.0.
*
*/

/* 
Controle visando evitar inclusões múltiplas.
*/

#ifndef MOD_DEF_PROJETO
#define MOD_DEF_PROJETO

/* 
Controle visando identificar o servidor.
*/

#ifdef MOD_IMPL_PROJETO
#define EXT_MOD_DEF_PROJETO
#else
#define EXT_MOD_DEF_PROJETO extern
#endif

/* 
Inclusão de módulo de definição.
*/

#include "../Estrutura/mod_def_lista.h"

/*
Enumerações de propriedades de projeto.
*/

typedef enum {
   NOME_PROJETO = 0,
   DESCRICAO_PROJETO = 1,
   ANO_INICIO = 2,
   SITUACAO = 3,
   NATUREZA = 4,
   REALIZADOR = 5,
   NOME_CITACAO = 6,
   INTEGRANTES = 7
} Propriedade;

/*
Declaração de protótipo de funções.
*/

EXT_MOD_DEF_PROJETO void getListaProjeto(ListaProjeto *pinicio);
EXT_MOD_DEF_PROJETO void setListaProjeto(ListaProjeto **epinicio, char *arquivo);

#undef EXT_MOD_DEF_PROJETO

#endif
