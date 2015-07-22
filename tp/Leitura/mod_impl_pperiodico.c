/**
*	@file mod_impl_pperiodico.c
*	@brief Módulo que faz a leitura dos periodicos.
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

#define MOD_IMPL_PPERIODICO

/*
Inclusão de módulo de definição.
*/

#include "mod_def_pperiodico.h"

/*
Termina processamento de módulo de implementação.
*/

#undef MOD_IMPL_PPERIODICO

/*
Definição de corpo de função.
*/

/**
* Uma função que percorre a lista de periodicos.
* @param *pinicio um ponteiro para o inicio da lista de periodicos.
* @return sem retorno.
*/
void getListaPPeriodico(ListaPPeriodico *pinicio)
{


    char *nome;

    ListaPPeriodico *pp1;
    TipoPPeriodico *pperiodico;

    pp1 = NULL;
    pperiodico = NULL;
    nome = "/0";

    if (pinicio == NULL)
    {
        printf("Lista Vazia!\n");
        return;
    } else {
        printf("HAHAHAAHA");
        pp1 = pinicio;
       /* while (pp1 != NULL)
        {

            pperiodico = (TipoPPeriodico *) pp1->pperiodico;

            nome = pperiodico->titulo_periodico;
            printf("%s\n", nome);
            pp1 = pp1->proximoPPeriodico;

        } */

    }
}



void setListaPPeriodico(ListaPPeriodico **epinicio, char *arquivo){
    FILE *pFile;
    int argc; /* contador de argumentos do buffer de linha */
    char *args[2]; /* propriedades e valores dos projetos */
    char *argv; /* valor da propriedade */
    char buffer[256]; /* buffer de linha temporario */
    char bufferIntegrante[256]; /* buffer temporario para integrantes dos projetos */
    char c; /* caracter de leitura de arquivo */
    char *intv; /* valor de string entre tokens do buffer de integrantes dos projetos */
    char *propriedadePP[10]; /* valores das propriedades */
    int i; /* contador de caracteres do buffer de linha */
    int numeroIntegrante; /* numero do integrante do projeto */
    int flagIntegrantes; /* sinaliza leitura de secao de integrantes do projeto */
    ListaPPeriodico *pp1; /* ponteiro auxiliar de lista de projeto */


    ListaPPeriodico *pp2; /* ponteiro auxiliar de lista de projeto */


    //ListaPPeriodico *pi1; /* ponteiro auxiliar de lista de integrante */
    //ListaPPeriodico *pi2; /* ponteiro auxiliar de lista de integrante */

    /* ponteiro de integrante */
    TipoPessoa *integrante;

    /* ponteiro de projeto */
    TipoPPeriodico *pperiodico;

    /* abre arquivo */
    pFile = fopen(arquivo, "r");

    //if (!pFile)
    //   printf("'%s' not exist\n", arquivo);

    //c = fgetc(pFile);

    if(ferror(pFile))
        printf("Arquivo '%s' vazio\n", arquivo);
    else
    {

        printf("\n");

        while ((c = getc(pFile)) != EOF)
        {

            /* inicializa contadores */
            argc = 0;
            i = 0;

            /* leitura de linha */
            do
            {

                buffer[i] = c;
                i++;

            }
            while (((c = getc(pFile)) != '\n') && (c != EOF));

            /* adiciona caracter de termino de string */
            buffer[i] = '\0';

            /* separa buffer de linha */
            argv = strtok(buffer, "=");

            /* propriedade = valor */
            while (argv != NULL)
            {
                args[argc] = argv;
                printf("args[%d]: %s\n", argc, args[argc]);
                argv = strtok(NULL, "=");
                argc++;

            }

            if (strcmp("TITULO do ARTIGO ", args[0]) == 0)
            {

                propriedadePP[TITULO] = calloc(strlen(args[1]), sizeof(char));
                strcpy(propriedadePP[TITULO], args[1]);
                printf("TITULO : %s\n", propriedadePP[TITULO]);

            }
            else if (strcmp("TITULO do PERIODICO ", args[0]) == 0)
            {

                propriedadePP[NOME_DA_EDITORA] = calloc(strlen(args[1]), sizeof(char));
                strcpy(propriedadePP[NOME_DA_EDITORA], args[1]);
                printf("NOME DA EDITORA: %s\n", propriedadePP[NOME_DA_EDITORA]);

            }
            else if (strcmp("PAGINA INICIAL ", args[0]) == 0)
            {

                propriedadePP[NUMERO_PAGINA_INICIAL] = calloc(strlen(args[1]), sizeof(char));
                strcpy(propriedadePP[NUMERO_PAGINA_INICIAL], args[1]);
                printf("NUMERO DA PAGINA INICIAL: %s\n", propriedadePP[NUMERO_PAGINA_INICIAL]);

            }
            else if (strcmp("PAGINA FINAL ", args[0]) == 0)
            {

                propriedadePP[NUMERO_PAGINA_FINAL] = calloc(strlen(args[1]), sizeof(char));
                strcpy(propriedadePP[NUMERO_PAGINA_FINAL], args[1]);
                printf("NUMERO DA PAGINA FINAL: %s\n", propriedadePP[NUMERO_PAGINA_FINAL]);

            }
            else if (strcmp("VOLUME ", args[0]) == 0)
            {

                propriedadePP[VOLUME] = calloc(strlen(args[1]), sizeof(char));
                strcpy(propriedadePP[VOLUME], args[1]);
                printf("VOLUME: %s\n", propriedadePP[VOLUME]);

            }
            else if (strcmp("SERIE ", args[0]) == 0)
            {

                propriedadePP[SERIE] = calloc(strlen(args[1]), sizeof(char));
                strcpy(propriedadePP[SERIE], args[1]);
                printf("SERIE: %s\n", propriedadePP[SERIE]);

            }
            else if (strcmp("NATUREZA", args[0]) == 0)
            {

                propriedadePP[NATUREZA] = calloc(strlen(args[1]), sizeof(char));
                strcpy(propriedadePP[NATUREZA], args[1]);
                printf("NATUREZA: %s\n", propriedadePP[NATUREZA]);

            }
            else if (strcmp("NOME COMPLETO ", args[0]) == 0)
            {

                propriedadePP[REALIZADOR] = calloc(strlen(args[1]), sizeof(char));
                strcpy(propriedadePP[REALIZADOR], args[1]);
                printf("REALIZADOR: %s\n", propriedadePP[REALIZADOR]);

            }
            else if (strcmp("NOME-PARA-CITACAO ", args[0]) == 0)
            {

                propriedadePP[NOME_CITACAO] = calloc(strlen(args[1]), sizeof(char));
                strcpy(propriedadePP[NOME_CITACAO], args[1]);
                printf("NOME-PARA-CITACAO: %s\n", propriedadePP[NOME_CITACAO]);

                /* secao integrantes do projeto */
            }
            else if (strcmp("AUTORES", buffer) == 0)
            {
                printf("AUTORES:\n");


            }

            pperiodico = malloc(sizeof(TipoPPeriodico));

            pperiodico->titulo_artigo = calloc(strlen(propriedadePP[TITULO]), sizeof(char));
            strcpy(pperiodico->titulo_artigo, propriedadePP[TITULO]);

            pperiodico->natureza = calloc(strlen(propriedadePP[NATUREZA]), sizeof(char));
            strcpy(pperiodico->natureza, propriedadePP[NATUREZA]);

            pperiodico->paginaInicial = calloc(strlen(propriedadePP[NUMERO_PAGINA_INICIAL]), sizeof(char));
            strcpy(pperiodico->paginaInicial, propriedadePP[NUMERO_PAGINA_INICIAL]);

            pperiodico->paginaFinal = calloc(strlen(propriedadePP[NUMERO_PAGINA_FINAL]), sizeof(char));
            strcpy(pperiodico->paginaFinal, propriedadePP[NUMERO_PAGINA_FINAL]);

            pperiodico->natureza = calloc(strlen(propriedadePP[NATUREZA]), sizeof(char));
            strcpy(pperiodico->natureza, propriedadePP[NATUREZA]);

            pp1 = malloc(sizeof(ListaPPeriodico));

            pp1->proximoPPeriodico = pperiodico;
            pp1->pperiodico = NULL;

            if (*epinicio == NULL)
                *epinicio = pp1;
            else
                pp2->proximoPPeriodico = pp1;
            pp2 = pp1;
       }

    }
    printf("\n");
    fclose(pFile);
}
