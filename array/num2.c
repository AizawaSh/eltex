#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	char c;
		
	if (scanf("%d%c", &N, &c) != 2 || c != '\n' || N <= 0){
		printf("N/A");
	} else {
		int* arr = malloc(N * sizeof(int));
		for(int i = 0; i < N; i++){
			int a;
			if ((i != N - 1) && !(scanf("%d%c", &a, &c) != 2 || (c != '\n' && c != ' '))){
				arr[i] = a;
			} else if (!(scanf("%d%c", &a, &c) != 2 || c != '\n')){
				arr[i] = a;
			} else {
				printf("N/A");
			}
		}
		for(int i = N - 1; i >= 0; i--){
			if (i != 0) {
				printf("%d ", arr[i]);
			} else {
				printf("%d", arr[i]);
			}
		}
		free(arr);
	}
		
	return 0;
}
