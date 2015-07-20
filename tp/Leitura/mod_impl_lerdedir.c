#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>


int main(int argc, char **argv)
{
    DIR* FD;
    struct dirent* in_file;
    //FILE    *output_file;
    FILE    *entry_file;
    char    buffer[BUFSIZ];

    /* Opening common file for writing */
    /*output_file = fopen("/home/pnp/snort_rules_folder/rulesoutput.txt", "a+");
    if (output_file == NULL)
    {
        fprintf(stderr, "Error : Failed to open output_file\n");

        return 1;
    }*/

    /* Scanning the in directory */
    if (NULL == (FD = opendir ("/home/josephkzez/Workspace/ps/tp/Arquivos"))) 
    {
        fprintf(stderr, "Error : Failed to open input directory\n");
        //fclose(output_file);

        return 1;
    }
    while ((in_file = readdir(FD))) 
    {
        /* On linux/Unix we don't want current and parent directories
         * If you're on Windows machine remove this two lines
         */
        /*if (!strcmp (in_file->d_name, "."))
            continue;
        if (!strcmp (in_file->d_name, ".."))    
            continue; */
        /* Open directory entry file for common operation */
        /* TODO : change permissions to meet your need! */
        entry_file = fopen(in_file->d_name, "r");
        printf(
        if (entry_file == NULL)
        {
            fprintf(stderr, "Error : Failed to open entry file\n");
            //fclose(output_file);

            return 1;
        }

        /* Doing some stuff with entry_file : */

        while (fgets(buffer, BUFSIZ, entry_file) != NULL)
        {
			printf("Ta dando certo");
            /* Use fprintf or fwrite to write some stuff into common_file*/
        }

    //fprintf(output_file, "reading file %s", in_file->d_name);

        /* When you finish with the file, close it */
        fclose(entry_file);
    }

    /* Don't forget to close common file before leaving */
    //fclose(output_file);

    return 0;
     }
