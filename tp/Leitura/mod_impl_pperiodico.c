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
#include <assert.h>

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

    return;
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
    TipoPessoa *integrante; /* ponteiro de integrante */
    TipoPPeriodico *pperiodico; /* ponteiro de projeto */

    
    pFile = fopen(arquivo, "r"); /* abre arquivo */

    char* linha=NULL;
    size_t len = 0;
    ssize_t read;
    
    while ((read = getline(&linha, &len, pFile)) != -1)  // le o arquivo linha a linha
    {
		printf("%s\n", linha);
		
		char* token = strtok (linha,"=");
		while(token!=NULL){
			printf("%s ", token);
			token = strtok (NULL,"=");
		}
		printf("\n");
	}
    
    
   
    printf("\n");
    fclose(pFile);
}

/*
   IMPLEMENTACAO DA FUNCAO getline() do C que roda no Windows.

   Read up to (and including) a TERMINATOR from STREAM into *LINEPTR
   + OFFSET (and null-terminate it). *LINEPTR is a pointer returned from
   malloc (or NULL), pointing to *N characters of space.  It is realloc'd
   as necessary.  Return the number of characters read (not including the
   null terminator), or -1 on error or EOF.  */

int getstr (char ** lineptr, size_t *n, FILE * stream, char terminator, int offset)
{
    int nchars_avail;             /* Allocated but unused chars in *LINEPTR.  */
    char *read_pos;               /* Where we're reading into *LINEPTR. */
    int ret;

    if (!lineptr || !n || !stream)
        return -1;

    if (!*lineptr)
    {
        *n = 64;
        *lineptr = (char *) malloc (*n);
        if (!*lineptr)
            return -1;
    }

    nchars_avail = *n - offset;
    read_pos = *lineptr + offset;

    for (;;)
    {
        register int c = getc (stream);

        /* We always want at least one char left in the buffer, since we
           always (unless we get an error while reading the first char)
           NUL-terminate the line buffer.  */

        assert(*n - nchars_avail == read_pos - *lineptr);
        if (nchars_avail < 1)
        {
            if (*n > 64)
                *n *= 2;
            else
                *n += 64;

            nchars_avail = *n + *lineptr - read_pos;
            *lineptr = (char *) realloc (*lineptr, *n);
            if (!*lineptr)
                return -1;
            read_pos = *n - nchars_avail + *lineptr;
            assert(*n - nchars_avail == read_pos - *lineptr);
        }

        if (c == EOF || ferror (stream))
        {
            /* Return partial line, if any.  */
            if (read_pos == *lineptr)
                return -1;
            else
                break;
        }

        *read_pos++ = c;
        nchars_avail--;

        if (c == terminator)
            /* Return the line.  */
            break;
    }

    /* Done - NUL terminate and return the number of chars read.  */
    *read_pos = '\0';

    ret = read_pos - (*lineptr + offset);
    return ret;
}

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
    return getstr (lineptr, n, stream, '\n', 0);
}
