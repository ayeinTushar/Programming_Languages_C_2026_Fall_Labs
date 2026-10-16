
/** Name: Tushar SohanLal
 251ADB110*/

#include <stdio.h>
int main(void)
{
   FILE *fp;
    char line[100];
    printf("Writing lines to data.txt...\n");
    fp = fopen("data.txt", "w");
    if(fp == NULL) 
{
        perror("File error");
        return 1;  }
    fprintf(fp,"Hello, file I/O in C!\n");
    fprintf(fp,"This is another line.\n");
    fclose(fp);
    fp=fopen("data.txt","r");
    if (fp ==NULL) 
    {
      perror("File error");
        return 1; }
    printf("Reading contents:\n");
    while(fgets(line,sizeof(line),fp) != NULL) 
    {
        printf("%s",line); }
    fclose(fp);
    return 0; }
