/**	
*	@file mod_impl_discente.c 
*	@brief Módulo que faz a leitura dos discentes.
*	@author Danilo Alves.
* 	@author José Siqueira.
*	@since 01/03/15.
*	@version 1.0.
*
*/

/* 
Inclusão de biblioteca do compilador.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Declaração visando identificar o módulo como servidor.
*/

#define MOD_IMPL_DISCENTE

/* 
Inclusão de módulo de definição.
*/

#include "mod_def_discente.h"

/* 
Termina processamento de módulo de implementação.
*/

#undef MOD_IMPL_DISCENTE

/*
Definição de corpo de função.
*/

/**
* Uma função que percorre a lista de discentes.
* @param *pinicio um ponteiro para o inicio da lista de discentes.
* @return sem retorno.
*/
void getListaDiscente(ListaDiscente *pinicio) {
	
	int matricula;
	int anoMatricula;
	
	ListaDiscente *pd1;
	
	TipoPessoa *discente;
	char *nome;
	
	matricula = 0;
	anoMatricula = 0;
	
	pd1 = NULL;
	
	discente = NULL;
	nome = "/0";

	if (pinicio == NULL)
		printf("Lista Vazia!");
		
	else {
		
		pd1 = pinicio;

		while (pd1 != NULL) {
			
			discente = (TipoPessoa *) pd1->discente;
			nome = discente->nome;
			anoMatricula = discente->anoMatricula;
			matricula = discente->matricula;
			printf("%02d/%07d %s\n", anoMatricula, matricula, nome);
			pd1 = pd1->proximoDiscente;
			
		}

	}
	
}

/**
* Uma função que constroi uma lista de discentes a partir do arquivo de entrada.
* @param **epinicio o endereco do ponteiro da lista de discentes.
* @param *arquivo um array de caracteres que contem o nome do arquivo.
* @return sem retorno.
*/
void setListaDiscente(ListaDiscente **epinicio, char *arquivo) {
   
   FILE *pArquivo;
   
   char separador;
   char buffer[78];
   char nome[30];

	int anoMatricula;
	int matricula;
	
	ListaDiscente *pd1;
	ListaDiscente *pd2;
	
   TipoPessoa *discente;

   pArquivo = fopen(arquivo, "r");

   if (!pArquivo)
      printf("'%s' not exist\n", arquivo);

   else {
		
		/* descarta informacoes de cabecalho do arquivo de entrada 
       *  ate encontrar a palavra Matricula */
		while (strcmp("Matricula", nome) != 0) {
				
			fgets(buffer, sizeof(buffer), pArquivo);
			sscanf(buffer,"%s", &nome);
			
		}
		
		/* filtra informacoes e constroi lista de discentes */
		while ((fgets(buffer, sizeof(buffer), pArquivo)) != NULL ) {
			
			if (sscanf(buffer,"%d%c%d %[^\n]s", &anoMatricula, &separador, &matricula, nome) == 4) {
				
				discente = malloc(sizeof(TipoPessoa));
				 
				discente->anoMatricula = anoMatricula;
				discente->matricula = matricula;
				
            discente->nome = calloc(strlen(nome), sizeof(char));
            strcpy(discente->nome, nome);
				
				pd1 = malloc(sizeof(ListaDiscente));
				
				pd1->discente = discente;
				pd1->proximoDiscente = NULL;
				
				if (*epinicio == NULL)
					*epinicio = pd1;
				
				else
					pd2->proximoDiscente = pd1;
					
				pd2 = pd1;
				
				while (getc(pArquivo) != 10);
		
			}
			
		}
		
		fclose (pArquivo);
		
	}
	
	
   
}
