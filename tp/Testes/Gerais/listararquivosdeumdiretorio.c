#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

// Colocar a função fora do main, em que ela receba evento ou periodicos, trocando o que tem dentro do opendir("./");

int main (void)
{
  DIR *dp;
  struct dirent *ep;

  dp = opendir ("./");
  if (dp != NULL)
    {
      while (ep = readdir (dp))
        puts (ep->d_name);
      (void) closedir (dp);
    }
  else
    perror ("Couldn't open the directory");

  return 0;
}
