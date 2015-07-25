/**
*	@file main.c
* 	@brief Módulo principal do trabalho.
* 	@author José Siqueira.
*	@since 01/03/15.
*	@version 1.0.
*
*/

#include <stdio.h>
#include <stdlib.h>

#include "Estrutura/mod_def_atividade.h"
#include "Estrutura/mod_def_lista.h"
#include "Estrutura/mod_def_pessoa.h"
#include "Leitura/mod_def_projeto.h"


int main() {

   char discentesMestrado[] = "Arquivos/discentes_mestrado.txt";
   char discentesDoutorado[] = "Arquivos/discentes_doutorado.txt";
    //char projetos[] = "Arquivos/projetos.txt";
    //char periodicos[] = "Arquivos/publicacao_periodico.txt";

   struct ListaDiscente* pInicioDiscentesMestrado;
   struct ListaDiscente* pInicioDiscentesDoutorado;
   //struct ListaDocente *pInicioDocentes;
   //struct ListaProjeto *pInicioProjetos;
   //struct ListaPPeriodico *pInicioPPeriodicos;

   pInicioDiscentesMestrado = NULL;
   pInicioDiscentesDoutorado = NULL;
   //pInicioDocentes = NULL;
   //pInicioProjetos = NULL;
   //pInicioPPeriodicos = NULL;

   setListaDiscente(&pInicioDiscentesMestrado, discentesMestrado);
   setListaDiscente(&pInicioDiscentesDoutorado, discentesDoutorado);
   //setListaProjeto(&pInicioProjetos, projetos);
   //setListaPPeriodico(&pInicioPPeriodicos, periodicos);

   // PercorreListaDiscente(pInicioDiscentes);

   //getListaProjeto(pInicioProjetos);
   //getListaProjeto(&pInicioProjetos); // Imprime lista de discentes do PPGI


   printf("\n\n\nLISTA PERIODICOS \n");

   //getListaPPeriodico(pInicioPPeriodicos);

   return 0;

}
