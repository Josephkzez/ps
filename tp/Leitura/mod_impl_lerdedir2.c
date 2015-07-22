#include <stdio.h>
#include <dirent.h>
#include <string.h>

void lerdedir(char *diretorio, char **arquivo)
{
    DIR *dir;
    struct dirent *ent;

    /*
    typedef struct ListaArquivos_{
    	char *nome_arquivo;
    	char *proximo_arquivo;
    }ListaArquivos;
    */

//char *arq1;
//char *arq2;

//if ((dir = opendir ("/home/josephkzez/Workspace/ps/tp/Arquivos")) != NULL) {
    if ((dir = opendir (diretorio)) != NULL)
    {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL)
        {
            if (!strcmp (ent->d_name, "."))
                continue;
            if (!strcmp (ent->d_name, ".."))
                continue;

            /*
            if (!strcmp (ent->d_name, "publicacao_eventos.txt")){
            	arq1 = ent->d_name;
            }
            if (!strcmp (ent->d_name, "publicacao_periodico.txt")){
            	arq2 = ent->d_name;
            }
            printf ("%s\n", ent->d_name);

            }
            printf("\n Publicacao Eventos : %s", arq1);
            printf("\n Publicacao Periodico : %s\n", arq2);
            */
            if (!strcmp (ent->d_name, *arquivo))
            {
                *arquivo = ent->d_name;
            }
        }
        closedir (dir);
    }
    else
    {
        /* could not open directory */
        perror ("");
        //return -1;
    }

}

int main()
{
    char *dir;
    char *arq;

    char diretorio[] = "../Arquivos";
    char arquivo[] = "publicacao_eventos.txt";

    *dir = (char *)malloc(sizeof(diretorio));
    *arq = &arquivo;

    lerdedir( &diretorio, &arquivo);
    printf("%c", &arquivo);
}
