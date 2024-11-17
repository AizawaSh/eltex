#include <stdio.h>

int main()
{
    int a, b;
    char c1, c2;
    
    if (scanf("%d%c%d%c", &a, &c1, &b, &c2) != 4 || (c1 != '\n' && c1 != ' ') || a < 0 || c2 != '\n' || b < 0 || b > 255){
        printf("N/A");
    } else {
        int mask = 0xFFFF00FF;
        int new_a = (a & mask) | (b << 8);
        printf("%d", new_a);
    }
    
    return 0;
}
