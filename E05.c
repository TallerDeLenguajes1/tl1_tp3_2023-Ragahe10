#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cargarnombres(char *k[], int c);
void mostrar(char *k[], int c);

int main()
{
    char **nombres;
    int cant;
    puts("Ingrese la cantidad de nombres");
    scanf("%d", &cant);
    fflush(stdin);

    nombres = malloc(sizeof(char*)*cant);
    cargarnombres(nombres, cant);
    mostrar(nombres, cant);
    
    
    for (int i = 0; i < 5; i++){
        free(nombres[i]);
    }
    free(nombres);
    return 0;
}
void cargarnombres(char *k[], int c)
{
    char *buff;
    buff = malloc(sizeof(char)*100);
    for (int i = 0; i < c; i++){
        printf("\nIngrese nombre %d", i+1);
        gets(buff);
        k[i] = malloc(sizeof(char)*((strlen(buff))+1));
        strcpy(k[i],buff);
    }
    free(buff);
}
void mostrar(char *k[], int c)
{
    for (int i = 0; i < c; i++){
        puts(k[i]);
    }
}