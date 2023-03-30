#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define A 5
#define M 12
void cargarMatriz(long P[A][M], long max[3], long min[3], float prom[5]);
void mostrarMatriz(long P[A][M]);
int main()
{
    srand(time(NULL));
    long Prod[A][M], max[3], min[3];
    float prom[5];
    cargarMatriz(Prod, max, min, prom);
    mostrarMatriz(Prod);

    puts("EL promedio por anio es: ");
    for (int i = 0; i < 5; i++){
        printf("\n- %d : %.2f", i+2023, prom[i]);
    }
    

    printf("\nEl valor maximo es : %ld, fecha %ld/%ld", max[0], max[2], max[1]);
    printf("\nEl valor minimo es : %ld, fecha %ld/%ld", min[0], min[2], min[1]);

    return 0;
}
void cargarMatriz(long P[A][M], long max[3], long min[3], float prom[5])
{
    int band=0;
    float panio;
    for(int i = 0 ; i < A ; i++){
        panio=0;
        for(int j = 0 ; j < M ; j++){
            P[i][j] = rand()%40001 + 10000;
            panio += P[i][j];
            if(band==0){
                max[0] = P[i][j];
                max[1] = i+1;
                max[2] = j+1;
                min[0] = P[i][j];
                min[1] = i+2023;
                min[2] = j+1;
                band = 1;
            }
            if((P[i][j] > (max[0]))){
                max[0] = P[i][j];
                max[1] = i+2023;
                max[2] = j+1;
            }
            if((P[i][j] < (min[0]))){
                min[0] = P[i][j];
                min[1] = i+2023;
                min[2] = j+1;
            }
        }
        prom[i] = panio/M;
    }
}
void mostrarMatriz(long P[A][M])
{
    printf("\nanio/mes");
    for (int i = 0; i < M; i++){
        printf("   %d  ", i+1);
    }
    printf("\n");
    
    for(int i = 0 ; i < A ; i++){
        printf("  %d    ", i+2023);
        for(int j = 0 ; j < M ; j++){
            printf("%ld ", P[i][j]);
        }
        printf("\n");
    }

}