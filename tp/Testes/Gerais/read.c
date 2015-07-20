#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() { 
   
   FILE *pFile;
   
   char *args[2], *argv, c, buffer[256], bufferIntegrante[256], *ints, *intv, *nFile;
   int argc, i, integrante, flagIntegrantes;
   fpos_t pos;
   
   nFile = "projetos.txt";
   
   pFile = fopen(nFile, "r");
   
   if (!pFile)
      printf("'%s' not exist\n", nFile);
      
   else { 
      
      printf("\n");
      
      while ((c = getc(pFile)) != EOF) {
      
         argc = 0;
         i = 0;
         
         do {
            
            buffer[i] = c;
            i++;
         
         } while ((c = getc(pFile)) != '\n');
         
         buffer[i] = '\0';
         // printf("%s\n", buffer);
         
         argv = strtok(buffer, "=");
         // printf("%s\n", argv);
         
         // printf("\n");
         
         while (argv != NULL) {
         
            args[argc] = argv;
            printf("%s\n", args[argc]);
            argv = strtok(NULL, "=");
            argc++;
      
         }
         
         if (strcmp("INTEGRANTES-DO-PROJETO", buffer) == 0) {
            
            do {
            
               flagIntegrantes = 0;
               i = 0;
               
               // fgetpos(pFile, &pos);
               // printf("%d\n", pos);
               
               do {

                  buffer[i] = c;
                  i++;

               } while ((c = getc(pFile)) != '\n');
               
               buffer[i] = '\0';
               
               if (sscanf(buffer,"%d%[^\n]s", &integrante, &bufferIntegrante) == 2) {
                  
                  printf("%d %s\n", integrante, bufferIntegrante);
                  
                  intv = strtok(bufferIntegrante, " ="  );
                  
                  if (strcmp("NOME-COMPLETO", intv) == 0)
                     flagIntegrantes = 1;
                  
                  while (intv != NULL) {
               
                     ints = intv;
                     printf("%s\n", ints);
                     intv = strtok(NULL, " =");
               
                  }
                  
               } else {
                  
                  argc = 0;
                  i = 0;

                  /* do {
                     
                     if (buffer[i] == '\n')
                        printf("\\n\n");
                     
                     else
                        printf("%c", buffer[i]);
                     
                     i++;
                  
                  } while (buffer[i] != '\0');
                  
                  printf("%s-", buffer); */
                  
                  argv = strtok(buffer, "=");

                  while (argv != NULL) {
         
                     args[argc] = argv;
                     // printf("%s\n", args[argc]);
                     argv = strtok(NULL, "=");
                     argc++;
               
                  }
                  
               }
               
            } while (flagIntegrantes);
            // printf("%d\n", pos);
            // fsetpos (pFile, &pos);
            
         }
         
      }
       
      printf("\n");
      
      fclose(pFile);
      
   }
   
   return 0;
   
}
