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
                arr[i][j] = 0;
            }
        }
        int flag = 1, count = 1, i = 0, j = 0;
        while (count < N * N) {
            arr[i][j] = count;
            if (flag == 1) {
                if (j == N - 1) {
                    flag++;
                } else if (arr[i][j + 1] != 0){
                    flag++;
                } else {
                    j++;
                    count++;
                }
            }
            if (flag == 2) {
                if (i == N - 1) {
                    flag++;
                } else if (arr[i + 1][j] != 0){
                    flag++;
                } else {
                    i++;
                    count++;
                }
            }
            if (flag == 3) {
                if (j == 0) {
                    flag++;
                } else if (arr[i][j - 1] != 0){
                    flag++;
                } else {
                    j--;
                    count++;
                }
            } 
            if (flag == 4) {
                if (i == 0) {
                    flag = 1;
                } else if (arr[i - 1][j] != 0){
                    flag = 1;
                } else {
                    i--;
                    count++;
                }
            }
        }
        arr[i][j] = count;
        
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