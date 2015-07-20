/**	
*	@file mod_def_lista.h
* 	@brief Arquivo cabeçalho para a estrutura de listas.
*	@author Danilo Alves.
* 	@author José Siqueira.
*	@since 01/03/15.
*	@version 1.0.
*
*/

/* 
Controle visando evitar inclusões múltiplas.
*/

#ifndef MOD_DEF_LISTA
#define MOD_DEF_LISTA

/* 
Inclusão de arquivo de módulo de definição.
*/

#include "mod_def_atividade.h"
#include "mod_def_pessoa.h"
#include "mod_def_string.h"

/*
Definição de estrutura.
*/

typedef struct ListaIntegrante {
   struct TipoPessoa *integrante;
   struct ListaIntegrante *proximoIntegrante;
} ListaIntegrante;

typedef struct ListaNomeCitacao {
   struct TipoString *nomeCitacao;
   struct ListaNomeCitacao *proximaCitacao;
} ListaNomeCitacao;

typedef struct ListaProjeto {
   struct TipoProjeto *projeto;
   struct ListaProjeto *proximoProjeto;
} ListaProjeto;

typedef struct ListaDiscente {
   struct TipoPessoa *discente;
   struct ListaDiscente *proximoDiscente;
} ListaDiscente;

typedef struct ListaDocente {
   struct TipoPessoa *docente;
   struct ListaDocente *proximoDocente;
} ListaDocente;

#endif
