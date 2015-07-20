/**	
*	@file mod_def_grafo.h 
*	@brief Arquivo cabeçalho para o grafo de relacionamento
*	@author Danilo Alves.
* 	@author José Siqueira.
*	@since 01/03/15.
*	@version 1.0.
*
*/

/* 
Controle visando evitar inclusões múltiplas.
*/

#ifndef MOD_DEF_GRAFO
#define MOD_DEF_GRAFO

/* 
Controle visando identificar o servidor.
*/

#ifdef MOD_IMPL_GRAFO
#define EXT_MOD_DEF_GRAFO
#else
#define EXT_MOD_DEF_GRAFO extern
#endif


/* 
Inclusão de módulo de definição.
*/
#include "mod_def_lista.h"


/*
So, the type-of-an-element is just:
*/
typedef char graphElementT;


/*
The abstract-type-of-graph is always the same, a pointer to the CDT: 
*/
typedef struct graphCDT *graphADT;

/*
Declaração de protótipo de funções.
*/

EXT_MOD_DEF_GRAFO void getListaGRAFO(ListaGRAFO *pinicio);
EXT_MOD_DEF_GRAFO void setListaGRAFO(ListaGRAFO **epinicio, char *arquivo);

#undef EXT_MOD_DEF_GRAFO

#endif
