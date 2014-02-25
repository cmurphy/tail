#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  char * filename = argv[1];
  FILE * fp = fopen(filename, "r");
  fseek(fp, -2, SEEK_END);
  int i;
  for(i = 0; i < 10; ++i) {
    if(ftell(fp) <= 0) break;
    int cc = 0;
    int c;
    while((c = getc(fp)) != '\n')
    {
      fseek(fp, -3, SEEK_CUR);
      if(ftell(fp) <= 0) break;
    }
  }
  int c;
  while((c = getc(fp)) != EOF) {
    printf("%c", (char) c);
  }
  fclose(fp);
  return 0;
}
