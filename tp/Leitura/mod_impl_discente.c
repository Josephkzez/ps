/**	
*	@file mod_impl_discente.c 
*	@brief Módulo que faz a leitura dos discentes.
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
	
	ListaDiscente *pd1;
	
	TipoPessoa *discente;
	char *nome;

	
}

/**
* Uma função que constroi uma lista de discentes a partir do arquivo de entrada.
* @param **epinicio o endereco do ponteiro da lista de discentes.
* @param *arquivo um array de caracteres que contem o nome do arquivo.
* @return sem retorno.
*/
void setListaDiscente(ListaDiscente **epinicio, char *arquivo) {
   
   
    int anoMatricula;
	int matricula;
	char separador;
   char buffer[78];
   char nome[30];
   char c; //SERA QUE EH ISSO AQUI
   
    FILE *pArquivo;
   
    pArquivo = fopen(arquivo, "r");
    
    char* linha=NULL;
    size_t len = 0;
    ssize_t read;
    
    if(ferror(pArquivo)){
		printf("Arquivo '%s' vazio\n", arquivo);
	}else {
		// descarta informacoes de cabecalho do arquivo de entrada 
       //  ate encontrar a palavra Matricula
		while (strcmp("Matricula", nome) != 0) {
				
			fgets(buffer, sizeof(buffer), pArquivo);
			sscanf(buffer,"%s", &nome);
			
		}
		
		/* filtra informacoes e constroi lista de discentes */
		while ((fgets(buffer, sizeof(buffer), pArquivo)) != NULL ) {
			TipoPessoa* discente;
			if (sscanf(buffer,"%d%c%d %[^\n]s", &anoMatricula, &separador, &matricula, nome) == 4) {
				
				discente = malloc(sizeof(TipoPessoa));
				 printf("%d %d %s \n",anoMatricula, matricula, nome);
				/*discente->anoMatricula = anoMatricula;
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
				
				while (getc(pArquivo) != 10); */
		
			}
			
		}
		
	}

    fclose (pArquivo);	

}
