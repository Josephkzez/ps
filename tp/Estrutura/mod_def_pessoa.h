/**	
*	@file mod_def_pessoa.h
* 	@brief Arquivo cabeçalho para a estrutura de pessoas.
*	@author Danilo Alves.
* 	@author José Siqueira.
*	@since 01/03/15.
*	@version 1.0.
*
*/

/* 
Controle visando evitar inclusões múltiplas.
*/

#ifndef MOD_DEF_PESSOA
#define MOD_DEF_PESSOA

/* 
Inclusão de arquivo de módulo de definição.
*/

#include "mod_def_atividade.h"
#include "mod_def_lista.h"
#include "mod_def_string.h"

/*
Definição de estrutura.
*/

typedef struct TipoPessoa {
  struct TipoString *nome;
  int anoMatricula;
  int matricula;
  struct TipoString *vinculo;
  struct ListaNomeCitacao *nomesCitacao;
} TipoPessoa;

#endif
