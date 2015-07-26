/**
*	@file mod_impl_discente.c
*	@brief Módulo que faz a leitura dos discentes.
* 	@author José Siqueira.
*	@since 01/03/15.
*	@version 1.0.
*
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
char* getNomeDiscente(char *linha);
/**
* Uma função que percorre a lista de discentes.
* @param *pinicio um ponteiro para o inicio da lista de discentes.
* @return sem retorno.
*/
void getListaDiscente(ListaDiscente *inicioPtr) {

    if(inicioPtr==NULL) return;

	ListaDiscente* pd1=inicioPtr;

    while(pd1!=NULL){
        printf("%s\n", pd1->discente->nome);
        pd1=pd1->proximoDiscente;
    }
}

/**
* Uma função que constroi uma lista de discentes a partir do arquivo de entrada.
* @param **epinicio o endereco do ponteiro da lista de discentes.
* @param *arquivo um array de caracteres que contem o nome do arquivo.
* @return sem retorno.
*/
void setListaDiscente(ListaDiscente **inicioPtr, char *arquivo) {

    FILE *pArquivo;
    //ListaDiscente* listaPtr;

    pArquivo = fopen(arquivo, "r");

    char* linha=NULL;
    size_t len = 0;
    ssize_t read;

    int contadorLinha=0;
    while ((read = getline(&linha, &len, pArquivo)) != -1){ //le o arquivo linha por linha
        if(contadorLinha++<9 || linha[91]!='S') continue; //ignora os cabecalhos do arquivo de discentes
        char* pt=linha; //faz o tratamento para pegar apenas o nome completo na lista
        pt+=26;
        *(pt+50)='\0'; //finaliza tratamento para pegar nome completo

        char buffer[52];
        strcpy(buffer, pt);

        TipoPessoa* tp = (TipoPessoa*)malloc(sizeof(TipoPessoa));
        tp->nome = (char*)malloc(strlen(buffer)+1);
        strcpy(tp->nome, buffer);
        tp->categoria = malloc(strlen("Discente")+1);
        strcpy(tp->categoria, "Discente");

        ListaDiscente* ld = (ListaDiscente*)malloc(sizeof(ListaDiscente));
        ld->discente = tp;
        ld->proximoDiscente = NULL;

        if(*inicioPtr==NULL)
            *inicioPtr = ld;
        else{
            ListaDiscente* pt = *inicioPtr;
            while(pt->proximoDiscente!=NULL){
               pt=pt->proximoDiscente;
            }
            pt->proximoDiscente=ld;

        }
    }
    fclose (pArquivo);
}
