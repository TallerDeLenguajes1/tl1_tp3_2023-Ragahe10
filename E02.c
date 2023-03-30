#include <stdio.h>
#include <time.h>

#define A 5
#define M 12
void cargarMatriz(long P[A][M], long *max, long *min);
int main()
{
    long Prod[A][M], max, min;
    cargarMatriz(Prod, &max, &min);
    return 0;
}
void cargarMatriz(long P[A][M], long *max, long *min)
{
    int band=0;
    for(int i = 0 ; i < A ; i++){
        for(int j = 0 ; j < M ; j++){
            P[i][j] =
        }
    }
}