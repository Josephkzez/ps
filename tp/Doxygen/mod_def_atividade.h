/**	
*	@file mod_def_atividade.h
* 	@brief Arquivo cabeçalho para a estrutura de atividades.
*	@author Danilo Alves.
* 	@author José Siqueira.
*	@since 01/03/15.
*	@version 1.0.
*
*/

/* 
Controle visando evitar inclusões múltiplas.
*/

#ifndef MOD_DEF_ATIVIDADE
#define MOD_DEF_ATIVIDADE

/* 
Inclusão de arquivo de módulo de definição.
*/

#include "mod_def_lista.h"
#include "mod_def_pessoa.h"
#include "mod_def_string.h"

/*
Definição de estrutura
*/

typedef enum {
   EM_ANDAMENTO = 1
} Situacao;

typedef enum {
   PESQUISA = 1
} Natureza;

typedef struct TipoProjeto {
   struct TipoString *nome;
   struct TipoString *descricao;
   struct TipoString *situacao;
   struct TipoString *natureza;
   struct TipoString *anoInicio;
   int anoFim;
   int mesFim;
   struct Pessoa *realizador;
   struct Pessoa *responsavel;
   struct ListaIntegrante *integrantes;
} TipoProjeto;

#endif
