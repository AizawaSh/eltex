#include <stdio.h>
#include <string.h>

struct abonent {
    char name[10];
    char second_name[10];
    char tel[10];
};
 
int main()
{
    struct abonent book[100];
    int len_abonent = 0;
    while (1){
        printf("1) Добавить абонента\n");
        printf("2) Удалить абонента\n");
        printf("3) Поиск абонентов по имени\n");
        printf("4) Вывод всех записей\n");
        printf("5) Выход\n");
        int comand = 0;
        char c = '\0';
        if (scanf("%d%c", &comand, &c) != 2 || c != '\n' || comand > 5 || comand < 1) {
            printf("ERROR\n");
            while (getchar() != '\n');
            continue;
        }
        if (comand == 1 && len_abonent == 100) {
            printf("ERROR\n");
            continue;
        } else if (comand == 1) {
            int flag_1 = 1;
            struct abonent new_abonent;
            char new_name[100];
            
            fgets(new_name, sizeof(new_name), stdin);
            if (strlen(new_name) >= 11 || new_name[0] == '\n' || strchr(new_name, ' ')){
                printf("ERROR\n");
                flag_1 = 0;
                continue;
            }
            new_name[strcspn(new_name, "\n")] = '\0';
            strcpy(new_abonent.name, new_name);
            if (flag_1) {
                char new_second_name[100];
                fgets(new_second_name, sizeof(new_second_name), stdin);
                if (strlen(new_second_name) >= 11 || new_second_name[0] == '\n' || strchr(new_second_name, ' ')){
                    printf("ERROR\n");
                    flag_1 = 0;
                    continue;
                }
                new_second_name[strcspn(new_second_name, "\n")] = '\0';
                strcpy(new_abonent.second_name, new_second_name);
            }
            if (flag_1) {
                char new_tel[100];
                fgets(new_tel, sizeof(new_tel), stdin);
                if (strlen(new_tel) >= 11 || new_tel[0] == '\n' || strchr(new_tel, ' ')){
                    printf("ERROR\n");
                    continue;
                }
                new_tel[strcspn(new_tel, "\n")] = '\0';
                strcpy(new_abonent.tel, new_tel);
                book[len_abonent] = new_abonent;
                len_abonent++;
            }            
        }
        if (comand == 2 && len_abonent != 0) {
            char name[100];
            fgets(name, sizeof(name), stdin);
            if (strlen(name) >= 11 || name[0] == '\n' || strchr(name, ' ')){
                printf("ERROR\n");
                continue;
            }
            name[strcspn(name, "\n")] = '\0';
            for (int i = 0; i < len_abonent; i++) {
                if (strcmp(book[i].name, name) != 0) {
                    continue;
                }
                
                for (int j = 0; j < 10; j++){
                    book[i].name[j] = 0;
                    book[i].second_name[j] = 0;
                    book[i].tel[j] = 0;
                }
                for (int j = i; j < len_abonent - 1; j++){
                    struct abonent temp;
                    temp = book[j];
                    book[j] = book[j + 1];
                    book[j + 1] = temp;
                }
                i--;
                len_abonent--;
            }
            continue;
        }
        if (comand == 3 && len_abonent != 0) {
            char name[100];
            fgets(name, sizeof(name), stdin);
            if (strlen(name) >= 11 || name[0] == '\n' || strchr(name, ' ')){
                printf("ERROR\n");
                continue;
            }
            name[strcspn(name, "\n")] = '\0';
            for (int i = 0; i < len_abonent; i++) {
                if (strcmp(book[i].name, name) != 0) {
                    continue;
                }
                printf("%s ", book[i].name);
                printf("%s ", book[i].second_name);
                printf("%s\n", book[i].tel);
            }
            continue;
        } 
        if ((comand == 3 || comand == 2 || comand == 4) && len_abonent == 0){
            printf("ERROR\n");
            continue;
        }
        if (comand == 4 && len_abonent != 0){
            for (int i = 0; i < len_abonent; i++) {
                printf("%s ", book[i].name);
                printf("%s ", book[i].second_name);
                printf("%s\n", book[i].tel);
            }
            continue;
        }
        if (comand == 5) {
            break;
        }
    }
    return 0;
}