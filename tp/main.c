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

#define SAIR_DO_SISTEMA 6

struct ListaDiscente* pInicioDiscentesMestrado;
struct ListaDiscente* pInicioDiscentesDoutorado;
struct ListaProjeto *pInicioProjetos;
struct ListaPEvento* pInicioPEventos;
struct ListaPPeriodico* pInicioPPeriodicos;

int main() {

   char discentesMestrado[] = "Arquivos/discentes_mestrado.txt";
   char discentesDoutorado[] = "Arquivos/discentes_doutorado.txt";
   char projetos[] = "Arquivos/projetos.txt";
   char periodicos[] = "Arquivos/publicacao_periodico.txt";
   char eventos[] = "Arquivos/publicacao_eventos.txt";


   //struct ListaDocente *pInicioDocentes;

   //struct ListaPPeriodico *pInicioPPeriodicos;

   pInicioDiscentesMestrado = NULL;
   pInicioDiscentesDoutorado = NULL;
   pInicioProjetos=NULL;
   //pInicioDocentes = NULL;
   pInicioPPeriodicos = NULL;

   setListaDiscente(&pInicioDiscentesMestrado, discentesMestrado);
   setListaDiscente(&pInicioDiscentesDoutorado, discentesDoutorado);


   //setListaProjeto(&pInicioProjetos, projetos);
   //setListaPPeriodico(&pInicioPPeriodicos, periodicos);
   setListaPEvento(&pInicioPEventos, eventos);


   //getListaProjeto(pInicioProjetos);
   //getListaProjeto(&pInicioProjetos); // Imprime lista de discentes do PPGI
   //getListaPPeriodico(pInicioPPeriodicos);
   int opcaoEscolhida=exibirOpcoes();
   printf("opcao>%d\n", opcaoEscolhida);


   while(opcaoEscolhida!=SAIR_DO_SISTEMA){
       switch(opcaoEscolhida){
          case 1:
             break;
          case 2:
             break;
          case 6:
            exit(0);
          default:
             break;


       }
   }



   return 0;

}

int exibirOpcoes(){

   printf("======================================================================");
   printf("\n                    SISTEMA CURUPIRA v0.0.1                           ");

   printf("\n");
   printf("Digite uma opcao:");
   printf("\n");
   printf("1. Visualizar Docentes \n");
   printf("2. Visuazliar Discentes \n");
   printf("3. Visualizar Periodicos \n");
   printf("4. Visualizar Eventos \n");
   printf("5. Visualizar Curriculo de Docente \n");
   printf("6. Sair do sistema\n\n");

   int opcao;
   scanf("%d", &opcao);

   return opcao;

}
