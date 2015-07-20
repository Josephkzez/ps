/**	
*	@file mod_impl_grafo.c
* 	@brief Módulo que faz o grafo de relacionamento.
*	@author Danilo Alves.
* 	@author José Siqueira.
*	@since 01/03/15.
*	@version 1.0.
*
*/


#include <stdio.h>

#include "mod_def_grafo.h"

/*
Estruturas necessárias
*/
typedef struct vertexTag {
	graphElementT element;
	int visited;
	struct edgeTag *edges;
	struct vertexTag *next;
} vertexT;

typedef struct edgeTag {
	struct vertexTag *connectsTo;
	struct edgeTag *next;
} edgeT;

typedef struct graphCDT {
	vertexT *vertices;
} graphCDT;


/* 
Definição de funções 
*/

void constroiGrafo(){
	
}

void imprimeRelacionamento() {
	
}


/*
Saída:

Grafo de relacionamentos:
GENAINA NUNES RODRIGUES: A. ZAGHETTO, C. RALHA, V. ALVES
ALEXANDRE ZAGHETTO: B. MACHIAVELLO, C. RALHA.

NOME: NOME_CITACAO, NOME_CITACAO, NOME_CITACAO
NOME: NOME_CITACAO, NOME_CITACAO, NOME_CITACAO
*/
