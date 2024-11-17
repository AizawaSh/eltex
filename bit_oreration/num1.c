#include <stdio.h>

int main()
{
    int a;
    char c;
    
    if (scanf("%d%c", &a, &c) != 2 || c != '\n' || a < 0){
        printf("N/A");
    } else {
        int lbit = sizeof(a) * 8;
        for (int i = lbit - 1; i >= 0; i--){
            printf("%d", a >> i & 1);
        }
    }
    
    return 0;
}
