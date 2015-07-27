/**
*	@file mod_def_pperiodico.h
*	@brief Arquivo cabeçalho para leitura de publicacao em periodico.
*	@author Danilo Alves.
* 	@author José Siqueira.
*	@since 01/03/15.
*	@version 1.0.
*
*/

/*
Controle visando evitar inclusões múltiplas.
*/

#ifndef MOD_DEF_PPERIODICO
#define MOD_DEF_PPERIODICO

/*
Controle visando identificar o servidor.
*/

#ifdef MOD_IMPL_PPERIODICO
#define EXT_MOD_DEF_PPERIODICO
#else
#define EXT_MOD_DEF_PPERIODICO extern
#endif

/*
Inclusão de módulo de definição.
*/

#include "../Estrutura/mod_def_lista.h"

/*
Enumerações de propriedades de peridico
*/

typedef enum {
   TITULO = 0,
   NATUREZA = 1,
   REALIZADOR = 2,
   NOME_CITACAO = 3,
   INTEGRANTES = 4,
   NOME_DA_EDITORA = 5,
   VOLUME = 6,
   SERIE = 7,
   NUMERO_PAGINA_INICIAL = 8,
   NUMERO_PAGINA_FINAL = 9

} Propriedade_periodicos;

/*
Declaração de protótipo de função.
*/

EXT_MOD_DEF_PPERIODICO FILE* getArquivoPPeriodicos(void);

EXT_MOD_DEF_PPERIODICO void getListaPPeriodico(ListaPPeriodico *pinicio);
EXT_MOD_DEF_PPERIODICO void setListaPPeriodico(ListaPPeriodico **epinicio, char *arquivo);

#undef EXT_MOD_DEF_PPERIODICO

#endif
