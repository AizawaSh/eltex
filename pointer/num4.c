#include <stdio.h>

int main() {
    char str[100];
    char sub_str[99];
    int len_sub = 0, len_str = 0, flag = 1;
    char c = '\0';
    while (c != '\n') {
        if (len_str >= 100) {
            flag = 0;
            break;
        }
        if (scanf("%c", &c) != 1 || (c == '\n' && len_str == 0)) {
            flag = 0;
            break;
        }
        if (c != '\n') {
            len_str++;
            str[len_str] = c;
        }
    }
    c = '\0';
    if (flag) {
        while (c != '\n') {
            if (len_sub >= 100) {
                flag = 0;
                break;
            }
            if (scanf("%c", &c) != 1 || (c == '\n' && len_sub == 0)) {
                flag = 0;
                break;
            }
            if (c != '\n') {
                sub_str[len_sub] = c;
                len_sub++;
            }
        }
    }
    char *ptr1 = str;
    if (flag) {
        for (int i = 0; i < len_str - len_sub + 2; i++){
            int flag_ = 1;
            for (int j = 0; j < len_sub; j++){
                if (str[i + j] != sub_str[j]){
                    flag_ = 0;
                    break;
                }
            }
            if (flag_){
                printf("%d", *(ptr1 + i));
                flag = 0;
                break;
            }
        }
    } else {
        printf("N/A");
    }
    if (flag) {
        printf("NULL");
    }
    return 0;
}