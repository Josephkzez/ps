/**	
*	@file mod_impl_projeto.c
* 	@brief Módulo que faz a leitura dos projetos.
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

#define MOD_IMPL_PROJETO

/* 
Inclusão de módulo de definição.
*/

#include "mod_def_projeto.h"

/* 
Termina processamento de módulo de implementação.
*/

#undef MOD_IMPL_PROJETO

/*
Definição do corpo da função.
*/

/**
* Uma função que percorre a lista de projetos.
* @param *pinicio um ponteiro para o inicio da lista de projetos.
* @return sem retorno.
*/
void getListaProjeto(ListaProjeto *pinicio) {
	
	char *nome;
   
   ListaProjeto *pp1;
	TipoProjeto *projeto;
	
	pp1 = NULL;
	
	projeto = NULL;
	nome = "/0";

	if (pinicio == NULL)
		printf("Lista Vazia!");
		
	else {
		
		pp1 = pinicio;

		while (pp1 != NULL) {
			
			projeto = (TipoProjeto *) pp1->projeto;
         nome = projeto->nome;
			printf("%s\n", nome);
			pp1 = pp1->proximoProjeto;
			
		}

	}
	
}

/**
* Uma função que constroi uma lista de projetos a partir do arquivo de entrada.
* @param **epinicio o endereco do ponteiro da lista de projetos.
* @param *arquivo um array de caracteres que contem o nome do arquivo.
* @return sem retorno.
*/
void setListaProjeto(ListaProjeto **epinicio, char *arquivo) {
 
   FILE *pFile;
   
   /* contador de argumentos do buffer de linha */
   int argc;
   
   /* propriedades e valores dos projetos */
   char *args[2];
   
   /* valor da propriedade */
   char *argv;

   /* buffer de linha temporario */
   char buffer[256];
   
   /* buffer temporario para integrantes dos projetos */
   char bufferIntegrante[256];
   
   /* caracter de leitura de arquivo */
   char c;
   
   /* valor de string entre tokens do buffer de integrantes dos projetos */
   char *intv;
   
   /* valores das propriedades */
   char *propriedade[8];
   
   /* contador de caracteres do buffer de linha */
   int i;
   
   /* numero do integrante do projeto */
   int integrante;
   
   /* sinaliza leitura de secao de integrantes do projeto */
   int flagIntegrantes;
   
   /* ponteiro auxiliar de lista de projeto */
   ListaProjeto *pp1;
   
   /* ponteiro auxiliar de lista de projeto */
	ListaProjeto *pp2;
	
   /* ponteiro de projeto */
   TipoProjeto *projeto;
   
   /* abre arquivo */
   pFile = fopen(arquivo, "r");
   
   if (!pFile)
      printf("'%s' not exist\n", arquivo);
      
   else { 
      
      printf("\n");
      
      while ((c = getc(pFile)) != EOF) {
      
         /* inicializa contadores */
         argc = 0;
         i = 0;
         
         /* leitura de linha */
         do {
            
            buffer[i] = c;
            i++;
         
         } while (((c = getc(pFile)) != '\n') && (c != EOF));
         
         /* adiciona caracter de termino de string */
         buffer[i] = '\0';
         
         /* separa buffer de linha */
         argv = strtok(buffer, "=");
         
         /* propriedade = valor */
         while (argv != NULL) {
         
            args[argc] = argv;
            // printf("args[%d]: %s\n", argc, args[argc]);
            argv = strtok(NULL, "=");
            argc++;
      
         }
         
         if (strcmp("NOME-DO-PROJETO ", args[0]) == 0) {
            
            propriedade[NOME_PROJETO] = calloc(strlen(args[1]), sizeof(char));
            strcpy(propriedade[NOME_PROJETO], args[1]);
            // printf("NOME-DO-PROJETO: %s\n", propriedade[NOME_PROJETO]);
            
         } else if (strcmp("DESCRICAO-DO-PROJETO", args[0]) == 0) {
            
            propriedade[DESCRICAO_PROJETO] = calloc(strlen(args[1]), sizeof(char));
            strcpy(propriedade[DESCRICAO_PROJETO], args[1]);
            // printf("DESCRICAO-DO-PROJETO: %s\n", propriedade[DESCRICAO_PROJETO]);
            
         } else if (strcmp("ANO-INICIO ", args[0]) == 0) {
            
            propriedade[ANO_INICIO] = calloc(strlen(args[1]), sizeof(char));
            strcpy(propriedade[ANO_INICIO], args[1]);
            // printf("ANO-INICIO: %s\n", propriedade[ANO_INICIO]);
            
         } else if (strcmp("SITUACAO ", args[0]) == 0) {
            
            propriedade[SITUACAO] = calloc(strlen(args[1]), sizeof(char));
            strcpy(propriedade[SITUACAO], args[1]);
            // printf("SITUACAO: %s\n", propriedade[SITUACAO]);
            
         } else if (strcmp("NATUREZA", args[0]) == 0) {
            
            propriedade[NATUREZA] = calloc(strlen(args[1]), sizeof(char));
            strcpy(propriedade[NATUREZA], args[1]);
            // printf("NATUREZA: %s\n", propriedade[NATUREZA]);
            
         } else if (strcmp("NOME COMPLETO ", args[0]) == 0) {
            
            propriedade[REALIZADOR] = calloc(strlen(args[1]), sizeof(char));
            strcpy(propriedade[REALIZADOR], args[1]);
            // printf("REALIZADOR: %s\n", propriedade[REALIZADOR]);
            
         } else if (strcmp("NOME-PARA-CITACAO ", args[0]) == 0) {
            
            propriedade[NOME_CITACAO] = calloc(strlen(args[1]), sizeof(char));
            strcpy(propriedade[NOME_CITACAO], args[1]);
            // printf("NOME-PARA-CITACAO: %s\n", propriedade[NOME_CITACAO]);
            
         /* secao integrantes do projeto */
         } else if (strcmp("INTEGRANTES-DO-PROJETO", buffer) == 0) {
            
            printf("INTEGRANTES-DO-PROJETO:\n");
            
            do {
            
               /* inicializa sinalizador de secao */
               flagIntegrantes = 0;
               
               /* inicializa contador */
               i = 0;
               
               /* leitura de linha */
               do {

                  buffer[i] = c;
                  i++;

               } while (((c = getc(pFile)) != '\n') && (c != EOF));
               
               buffer[i] = '\0';
               
               /* examina padrao no buffer de linha */
               if (sscanf(buffer, "%d%[^\n]s", &integrante, &bufferIntegrante) == 2) {
                  
                  printf("%d\n", integrante);
                  
                  /* separa buffer de integrante */
                  intv = strtok(bufferIntegrante, " ="  );
                  
                  /* sinaliza secao */
                  if (strcmp("NOME-COMPLETO", intv) == 0)
                     flagIntegrantes = 1;
                  
                  /* integrante = responsavel */
                  while (intv != NULL) {

                     printf("%s\n", intv);
                     intv = strtok(NULL, " =");
               
                  }
                  
               /* entre projetos - nao encontra padrao da secao de integrantes */
               } else {
                  
                  /* inicializa contadores */
                  argc = 0;
                  i = 0;
                  
                  /* separa buffer de linha */
                  argv = strtok(buffer, "=");

                  /* descarta linha */
                  while (argv != NULL) {
         
                     args[argc] = argv;
                     argv = strtok(NULL, "=");
                     argc++;
               
                  }
                  
               }
               
            } while (flagIntegrantes);
            
            projeto = malloc(sizeof(TipoProjeto));
            
            projeto->nome = calloc(strlen(propriedade[NOME_PROJETO]), sizeof(char));
            strcpy(projeto->nome, propriedade[NOME_PROJETO]);
            
            projeto->descricao = calloc(strlen(propriedade[DESCRICAO_PROJETO]), sizeof(char));
            strcpy(projeto->descricao, propriedade[DESCRICAO_PROJETO]);
            
            projeto->anoInicio = calloc(strlen(propriedade[ANO_INICIO]), sizeof(char));
            strcpy(projeto->anoInicio, propriedade[ANO_INICIO]);
            
            projeto->situacao = calloc(strlen(propriedade[SITUACAO]), sizeof(char));
            strcpy(projeto->situacao, propriedade[SITUACAO]);
            
            projeto->natureza = calloc(strlen(propriedade[NATUREZA]), sizeof(char));
            strcpy(projeto->natureza, propriedade[NATUREZA]);
            
            projeto->realizador = calloc(strlen(propriedade[REALIZADOR]), sizeof(char));
            strcpy(projeto->realizador, propriedade[REALIZADOR]);
            
            pp1 = malloc(sizeof(ListaProjeto));
            
            pp1->projeto = projeto;
				pp1->proximoProjeto = NULL;
				
				if (*epinicio == NULL)
					*epinicio = pp1;
				
				else
					pp2->proximoProjeto = pp1;
					
				pp2 = pp1;
            
         }
         
      }
       
      printf("\n");
      
      fclose(pFile);
      
   }
   
}
