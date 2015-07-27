/**
*	@file mod_def_lista.h
* 	@brief Arquivo cabeçalho para a estrutura de listas.
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

/*
Definição de estrutura.
*/

typedef struct ListaIntegrante {
   struct TipoPessoa *integrante;
   char* ordemAuditoria;
   struct ListaIntegrante *proximoIntegrante;
} ListaIntegrante;

typedef struct ListaNomeCitacao {
   char* *nomeCitacao;
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

/* Para mod_impl_pevento.c */

typedef struct ListaPEvento {
	struct TipoPEvento *pevento;
	struct ListaPEvento *proximoPEvento;
} ListaPEvento;

/* Para mod_impl_pperiodico.c */
typedef struct ListaPPeriodico {
	struct TipoPPeriodico *pperiodico;
	struct ListaPPeriodico *proximoPPeriodico;
} ListaPPeriodico;


#endif
