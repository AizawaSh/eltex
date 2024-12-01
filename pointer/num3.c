#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr = arr;

    for (int i = 0; i < 9; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("%d", *(ptr + 9));

    return 0;
}