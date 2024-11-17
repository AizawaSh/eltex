#include <stdio.h>

int main()
{
    int a;
    char c;
    
    if (scanf("%d%c", &a, &c) != 2 || c != '\n' || a < 0){
        printf("N/A");
    } else {
        int count = 0, lbit = sizeof(a) * 8;
        for (int i = lbit - 1; i >= 0; i--){
            if (a >> i & 1) {
                count++;
            }
        }
        printf("%d", count);
    }
    
    return 0;
}
