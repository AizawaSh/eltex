#include <stdio.h>

int main()
{
    int N;
    char c;
    
    if (scanf("%d%c", &N, &c) != 2 || c != '\n' || N <= 0){
        printf("N/A");
    } else {
	int count = 0;
	for(int i = 0; i < N; i++){
	    for(int j = 0; j < N; j++){
		count++;
		if(j != N - 1){
		    printf("%d ", count);
		} else {
		    printf("%d\n", count);
		}
	    }
	}
    }
    
    return 0;
}
