/**
*	@file mod_impl_pevento.c
*	@brief Módulo que faz a leitura dos eventos.
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
#include <dirent.h>


/*
Declaração visando identificar o módulo como servidor.
*/

#define MOD_IMPL_PEVENTO

/*
Inclusão de módulo de definição.
*/

#include "mod_def_pevento.h"

/*
Termina processamento de módulo de implementação.
*/

#undef MOD_IMPL_PEVENTO

/*
Definição de corpo de função.
*/

/**
* Uma função que percorre a lista de discentes.
* @param *pinicio um ponteiro para o inicio da lista de discentes.
* @return sem retorno.
*/

void getListaPEvento(ListaPEvento *pinicio) {

}


FILE* getArquivoPEvento(void){
      DIR* dir;
      struct dirent *ent;
      char* arq;

    if ((dir = opendir ("./Arquivos")) != NULL)
    {

       while ((ent = readdir (dir)) != NULL)
       {

           if (strcmp (ent->d_name, ".")==0)
                continue;
           if (strcmp (ent->d_name, "..")==0)
                continue;

            if (strcmp (ent->d_name, "publicacao_eventos.txt")==0)
            {
                 printf("ent: %s\n", ent->d_name);
                 arq = ent->d_name;
            }


       }
    }
    if(arq!=NULL){
      char abs[100];
      strcpy(abs, "Arquivos/");
      strcat(abs, arq);
      printf("abs %s ", abs);
      closedir(dir);
      FILE* fp = fopen(abs, "r");

      return fp;
    }else
       return NULL;
}

/**
* Uma função que constroi uma lista de projetos a partir do arquivo de entrada.
* @param **epinicio o endereco do ponteiro da lista de projetos.
* @param *arquivo um array de caracteres que contem o nome do arquivo.
* @return sem retorno.
*/
void setListaPEvento(ListaPEvento **epinicio, char *arquivo) {
   FILE *pFile;
    //pFile = fopen(arquivo, "r");


    pFile = getArquivoPEvento();

    char* linha=NULL;
    size_t len = 0;
    ssize_t read;

    int fAutores=0; //flag que indica o inicio da leitura dos autores
    int campo=0; //flag que assiste a posicao do campo
    int stateS=0; //flag que assiste o campo dos integrantes
    int campoState=0; //flag que assiste a contagem dos campos de integrantes

    ListaIntegrante* integrantes = NULL; // CRIA UMA lista de integrante inicial

    while ((read = getline(&linha, &len, pFile)) != -1){  // loop de leitura linha a linha
       TipoPEvento* evento = (TipoPEvento*)malloc(sizeof(TipoPEvento));
       if(linha[0]=='A' && linha[1]=='U'){
			fAutores = 1;
			break;
       }

       printf("%s", linha);

       if(!fAutores){
            char* propriedade;
			char* valor;
			char* token = strtok (linha,"=");
			if(token!=NULL && strlen(token)>1){
				//printf("token %d: %s ", campo++, token);
				propriedade = token;
			}
			token = strtok (NULL,"=");
			if(token!=NULL && strlen(token)>1){
				//printf("token %d: %s ", campo++, token);
				valor = token;
			}
			//printf("propridade: %s valor: %s", propriedade, valor);

			if(strcmp(propriedade, "NOME COMPLETO ")==0){
			  evento->nome_completo = (char*) malloc(strlen(valor)+1);
			  strcpy(evento->nome_completo, valor);
			} else if (strcmp(propriedade, "NOME-PARA-CITACAO ")==0){
			  evento->nome_citacao = (char*) malloc(strlen(valor)+1);
			  strcpy(evento->nome_citacao, valor);
            } else if (strcmp(propriedade, "NATUREZA ")==0){
              evento->natureza= (char*)malloc(strlen(valor)+1);
              strcpy(evento->natureza, valor);
			} else if (strcmp(propriedade, "TITULO ")==0){
              evento->titulo= (char*)malloc(strlen(valor)+1);
              strcpy(evento->titulo, valor);
			} else if (strcmp(propriedade, "PAIS ")==0){
              evento->pais= (char*)malloc(strlen(valor)+1);
              strcpy(evento->pais, valor);
			} else if (strcmp(propriedade, "IDIOMA ")==0){
              evento->idioma= (char*)malloc(strlen(valor)+1);
              strcpy(evento->idioma, valor);
			} else if (strcmp(propriedade, "NOME DO EVENTO ")==0){
              evento->nome_evento= (char*)malloc(strlen(valor)+1);
              strcpy(evento->nome_evento, valor);
			} else if (strcmp(propriedade, "ANO ")==0){
              evento->ano= (char*)malloc(strlen(valor)+1);
              strcpy(evento->ano, valor);
			} else if (strcmp(propriedade, "PROCEEDINGS ")==0){
              evento->proceedings= (char*)malloc(strlen(valor)+1);
              strcpy(evento->proceedings, valor);
			} else if (strcmp(propriedade, "VOLUME ")==0){
              evento->volume= (char*)malloc(strlen(valor)+1);
              strcpy(evento->volume, valor);
			} else if (strcmp(propriedade, "PAGINA INICIAL ")==0){
              evento->paginaInicial= (char*)malloc(strlen(valor)+1);
              strcpy(evento->paginaInicial, valor);
			} else if (strcmp(propriedade, "PAGINA-FINAL ")==0){
              evento->paginaFinal= (char*)malloc(strlen(valor)+1);
              strcpy(evento->paginaFinal, valor);
			}

       }else{
           if(strlen(linha)==1){
              fAutores=0;
            }
              continue;
           }
		}
        printf("\n");

      fclose(pFile);
}
