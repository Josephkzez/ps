#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main()
{
    DIR *dir;
    struct dirent *ent;
    /*
    typedef struct ListaArquivos_{
    	char *nome_arquivo;
    	char *proximo_arquivo;
    }ListaArquivos;
    */
    char *arq1;
    char *arq2;

    if ((dir = opendir ("../Arquivos")) != NULL)
    {
        /* imprimir todos os arquivos e diretorios dentro do diretorio*/
        while ((ent = readdir (dir)) != NULL)
        {
            if (!strcmp (ent->d_name, "."))
                continue;
            if (!strcmp (ent->d_name, ".."))
                continue;


            if (!strcmp (ent->d_name, "publicacao_eventos.txt"))
            {
                arq1 = ent->d_name;
            }
            if (!strcmp (ent->d_name, "publicacao_periodico.txt"))
            {
                arq2 = ent->d_name;
            }
            printf ("%s\n", ent->d_name);

        }
        printf("\n Publicacao Eventos : %s", arq1);
        printf("\n Publicacao Periodico : %s\n", arq2);

        closedir (dir);
    }
    else
    {
        /* Nao foi possivel abrir o diretorio */
        perror ("Não foi possível abrir o diretório");
        return -1;
    }
}
