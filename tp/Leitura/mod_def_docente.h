/**	
*	@file mod_def_docente.h 
*	@brief Arquivo cabeçalho para leitura de docentes.
*	@author Danilo Alves.
* 	@author José Siqueira.
*	@since 01/03/15.
*	@version 1.0.
*
*/

/* 
Controle visando evitar inclusões múltiplas.
*/

#ifndef MOD_DEF_DOCENTE
#define MOD_DEF_DOCENTE

/* 
Controle visando identificar o servidor.
*/

#ifdef MOD_IMPL_DOCENTE
#define EXT_MOD_DEF_DOCENTE
#else
#define EXT_MOD_DEF_DOCENTE extern
#endif

/* 
Inclusão de módulo de definição.
*/

#include "../Estrutura/mod_def_lista.h"

/*
Declaração de protótipo de função.
*/

EXT_MOD_DEF_DOCENTE void getListaDocente(ListaDocente *pinicio);
EXT_MOD_DEF_DOCENTE void setListaDocente(ListaDocente **epinicio, char *arquivo);

#undef EXT_MOD_DEF_DOCENTE

#endif
