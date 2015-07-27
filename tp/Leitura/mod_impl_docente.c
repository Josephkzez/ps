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
    ListaDocente* ptr;
    ptr = pinicio;

    while(ptr!=NULL) {
       printf("%s", ptr->docente->nome);
       ptr=ptr->proximoDocente;
     }

}

/**
* Uma função que constroi uma lista de docentes a partir do arquivo de entrada.
* @param **epinicio o endereco do ponteiro da lista de discentes.
* @param *arquivo um array de caracteres que contem o nome do arquivo.
* @return sem retorno.
*/
void setListaDocente(ListaDocente **epinicio, char *arquivo) {


    FILE *pArquivo;
    pArquivo = fopen(arquivo, "r");

    char* linha=NULL;
    size_t len = 0;
    ssize_t read;

    int contadorLinha=0;
    while ((read = getline(&linha, &len, pArquivo)) != -1){

        ListaDocente* listaPtr = (ListaDocente*)malloc(sizeof(ListaDocente));
        listaPtr->docente = (TipoPessoa*)malloc(sizeof(TipoPessoa));
        listaPtr->docente->nome = (char*)malloc(strlen(linha)+1);
        strcpy(listaPtr->docente->nome, linha);
        listaPtr->docente->categoria = (char*)malloc(strlen("Docente")+1);
        listaPtr->proximoDocente = NULL;

        if(*epinicio==NULL){
           *epinicio=listaPtr;
        }else{
           ListaDocente* ld = *epinicio;
           while(ld->proximoDocente!=NULL) ld=ld->proximoDocente;
           ld->proximoDocente=listaPtr;
        }
    }
   fclose(pArquivo);
}
