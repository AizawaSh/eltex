#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    char c;
           
    if (scanf("%d%c", &N, &c) != 2 || c != '\n' || N <= 0){
        printf("N/A");
    } else {
        int **arr = malloc(N * sizeof(int *));
        for (int i = 0; i < N; i++){
            arr[i] = malloc(N * sizeof(int));
        }
        for(int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (i + j >= N - 1) {
                    arr[i][j] = 1;
                } else {
                    arr[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (j != N - 1) {
                    printf("%d ", arr[i][j]);
                } else if ((j == N - 1) && (i != N - 1)){
                    printf("%d\n", arr[i][j]);
                } else {
                    printf("%d", arr[i][j]);
                }
            }
        }
        for (int i = 0; i < N; i++){
            free(arr[i]);
        }
        free(arr);
    }

    return 0;
}
