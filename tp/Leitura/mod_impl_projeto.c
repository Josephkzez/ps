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
}

/**
* Uma função que constroi uma lista de projetos a partir do arquivo de entrada.
* @param **epinicio o endereco do ponteiro da lista de projetos.
* @param *arquivo um array de caracteres que contem o nome do arquivo.
* @return sem retorno.
*/
void setListaProjeto(ListaProjeto **epinicio, char *arquivo) {

   FILE *pFile;

   /* abre arquivo */
   pFile = fopen(arquivo, "r");

    char* linha=NULL;
    size_t len = 0;
    ssize_t read;

    int fIntegrantes=0; //flag que indica o inicio da leitura dos autores
    int campo=0; //flag que assiste a posicao do campo
    int stateS=0; //flag que assiste o campo dos integrantes

    while ((read = getline(&linha, &len, pFile)) != -1){
        //printf("%s\n", linha);

        if(!fIntegrantes){
           char* propriedade;
           char* valor;

           char* token;

           token = strtok(linha, "=");
           printf("token1 = %s ", token);
           if(strcmp(token, "INTEGRANTES-DO-PROJETO\n")==0){
              fIntegrantes=1;
           }


           token = strtok(NULL, "=");
           if(token !=NULL && strlen(token)>1)
               printf("token 2 = %s\n", token);

        }else{



        }
    }


   fclose(pFile);
}
