/**	
*	@file mod_def_discente.h 
*	@brief Arquivo cabeçalho para leitura de discentes.
*	@author Danilo Alves.
* 	@author José Siqueira.
*	@since 01/03/15.
*	@version 1.0.
*
*/

/* 
Controle visando evitar inclusões múltiplas.
*/

#ifndef MOD_DEF_DISCENTE
#define MOD_DEF_DISCENTE

/* 
Controle visando identificar o servidor.
*/

#ifdef MOD_IMPL_DISCENTE
#define EXT_MOD_DEF_DISCENTE
#else
#define EXT_MOD_DEF_DISCENTE extern
#endif

/* 
Inclusão de módulo de definição.
*/

#include "../Estrutura/mod_def_lista.h"

/*
Declaração de protótipo de função.
*/

EXT_MOD_DEF_DISCENTE void getListaDiscente(ListaDiscente *pinicio);
EXT_MOD_DEF_DISCENTE void setListaDiscente(ListaDiscente **epinicio, char *arquivo);

#undef EXT_MOD_DEF_DISCENTE

#endif
