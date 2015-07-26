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


}

void setListaPPeriodico(ListaPPeriodico **epinicio, char *arquivo){
    FILE *pFile;


    //TipoPessoa *integrante; /* ponteiro de integrante */
    TipoPPeriodico *pperiodico; /* ponteiro de projeto */


    pFile = fopen(arquivo, "r"); /* abre arquivo */

    char* linha=NULL;
    size_t len = 0;
    ssize_t read;

    int fAutores=0; //flag que indica o inicio da leitura dos autores
    int campo=0; //flag que assiste a posicao do campo
    int stateS=0; //flag que assiste o campo dos integrantes

    while ((read = getline(&linha, &len, pFile)) != -1){  // le o arquivo linha a linha
		pperiodico = (TipoPPeriodico*) malloc(sizeof(TipoPPeriodico));
		if(linha[0]=='A' && linha[1]=='U'){
			fAutores = 1;
			continue;
		}
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
			//printf("prop: %s valor: %s", propriedade, valor);

			if(strcmp(propriedade, "NOME COMPLETO ")==0){
				pperiodico->nome_completo = valor;
				printf("NOME COMPLETO = %s\n", pperiodico->nome_completo->valor);
			} else if (strcmp(propriedade, "NOME-PARA-CITACAO ")==0){
				pperiodico->nome_citacao=valor;
				printf("nome citacao: %s", pperiodico->nome_citacao->valor);
			} else if (strcmp(propriedade, "NATUREZA ")==0){
				pperiodico->natureza= (char*)valor;
				printf("natureza: %s", pperiodico->natureza->valor);
			} else if (strcmp(propriedade, "TITULO do ARTIGO ")==0){
				pperiodico->titulo_artigo = valor;
				printf("titulo artigo: %s", pperiodico->titulo_artigo->valor);
			} else if (strcmp(propriedade, "ANO ")==0){
				pperiodico->ano = valor;
				printf("ano: %s", pperiodico->ano->valor);
			} else if (strcmp(propriedade, "IDIOMA ")==0){
				pperiodico->idioma = valor;
				printf("idioma: %s", pperiodico->idioma->valor);
			} else if (strcmp(propriedade, "TITULO do PERIODICO ")==0){
				pperiodico->titulo_periodico = valor;
				printf("titulo do periodico: %s", pperiodico->titulo_periodico->valor);
			} else if (strcmp(propriedade, "VOLUME ")==0 && valor != NULL){
				pperiodico->volume = valor;
				printf("volume: %s", pperiodico->volume->valor);
			} else if (strcmp(propriedade, "SERIE ")==0 && valor != NULL){
				pperiodico->serie = (char*) valor;
				printf("serie: %s", pperiodico->serie->valor);
			} else if (strcmp(propriedade, "PAGINA INICIAL ")==0 && valor != NULL){
				pperiodico->paginaInicial = (char*) valor;
				printf("pagina inicial: %s", pperiodico->paginaInicial->valor);
			} else if (strcmp(propriedade, "PAGINA FINAL ")==0 && valor != NULL){
				pperiodico->paginaFinal = (char*) valor;
				printf("pagina final: %s", pperiodico->paginaFinal->valor);
			}
			campo=0;
		}else{ // Analisar integrantes

			if(stateS==0){
				printf("nome do integrante: %s", linha);
			}else if (stateS==1){
				printf("nome para citacao: %s", linha);
			}  else if (stateS==2){
				printf("ordem de auditoria: %s", linha);
				stateS=0;
			}
			stateS++;
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
