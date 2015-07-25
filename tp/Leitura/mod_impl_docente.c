/**	
*	@file mod_impl_docente.c 
*	@brief Módulo que faz a leitura dos docentes.
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

#define MOD_IMPL_DOCENTE

/* 
Inclusão de módulo de definição.
*/

#include "mod_def_docente.h"

/* 
Termina processamento de módulo de implementação.
*/

#undef MOD_IMPL_DOCENTE

/*
Definição de corpo de função.
*/

/* AQUI SOH TEM O NOME DAS FUNÇOES MESMO */

/**
* Uma função que retorna a lista de docentes.
* @param *pinicio um ponteiro para o inicio da lista de discentes.
* @return sem retorno.
*/
void getListaDocente(ListaDocente *pinicio) {

}

/**
* Uma função que constroi uma lista de docentes a partir do arquivo de entrada.
* @param **epinicio o endereco do ponteiro da lista de discentes.
* @param *arquivo um array de caracteres que contem o nome do arquivo.
* @return sem retorno.
*/
void setListaDocente(ListaDiscente **epinicio, char *arquivo) {
   
   /*
   FILE *pArquivo;
   
   char separador;
   char buffer[78];
   char nome[30];
   char c; //SERA QUE EH ISSO AQUI

	int anoMatricula;
	int matricula;
	
	ListaDocente *pd1;
	ListaDocente *pd2;
	
    TipoPessoa *docente;

    pArquivo = fopen(arquivo, "r");

    //if (!pArquivo)
    //   printf("'%s' not exist\n", arquivo);
    
	//c = fgetc(pArquivo); SEM ISSO AQUI FUNCIONA MELHOR
	
	if(ferror(pArquivo))
		printf("Arquivo '%s' vazio\n", arquivo);
    else {
		
		/* descarta informacoes de cabecalho do arquivo de entrada 
       *  ate encontrar a palavra Matricula */
       
       /*
		while (strcmp("Matricula", nome) != 0) {
				
			fgets(buffer, sizeof(buffer), pArquivo);
			sscanf(buffer,"%s", &nome);
			
		}
		
		/* filtra informacoes e constroi lista de discentes */
		
		/*
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
	
	
   */
}

