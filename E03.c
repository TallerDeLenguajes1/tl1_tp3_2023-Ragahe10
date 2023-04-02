#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cargarnombres(char *k[]);
void mostrar(char *k[]);

int main()
{
    char *nombres[5];
    
    cargarnombres(nombres);
    mostrar(nombres);
    
    
    for (int i = 0; i < 5; i++){
        free(nombres[i]);
    }
    return 0;
}
void cargarnombres(char *k[])
{
    char *buff;
    buff = malloc(sizeof(char)*100);
    for (int i = 0; i < 5; i++){
        printf("\nIngrese nombre %d", i+1);
        gets(buff);
        k[i] = malloc(sizeof(char)*((strlen(buff))+1));
        strcpy(k[i],buff);
    }
    free(buff);
}
void mostrar(char *k[])
{
    for (int i = 0; i < 5; i++){
        puts(k[i]);
    }
}