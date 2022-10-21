#include "uselessSetup.h"

void space_skip(int* iter, char* buf) {
    while((buf[*iter] == ' ') || (buf[*iter] == '\t') || (buf[*iter] == '\n') || (buf[*iter] == '\r')) 
        (*iter)++; 
    printf("Now iter on \'%c\'. \n", buf[*iter]);   
}

int read_num(int* iter, char* buf) {
    char str_num[MAXNUMSIZE] = {'\0'};
    int i = 0;
    while((buf[*iter] != ' ') && (buf[*iter] != '\t') && (buf[*iter] != '\n')) {
        str_num[i] = buf[*iter];
        ++i;
        ++(*iter);
    }
    printf("Str num = %s. Str len = %ld. \n", str_num, strlen(str_num));
    printf("Now iter on \'%c\'. \n", buf[*iter]); 

    int num = 0;
    int digit = 1;
    for(i = strlen(str_num) - 1; i != -1; --i) {
        num += digit*(str_num[i] - '0');
        printf("Num = %d. \n", num);
        digit *= 10;
    }
    printf("Int num = %d. \n", num);

    return num;
}

char* read_name(int* iter, char* buf) {
    char* name = (char*)calloc(MAXNAMESIZE, sizeof(char));
    int i = 0;
    while((buf[*iter] != ' ') && (buf[*iter] != '\t') && (buf[*iter] != '\n') && (buf[*iter] != '\r') && (buf[*iter] != '\0')) {
        name[i] = buf[*iter];
        printf("Name: \"%s\". \n", name);
        i++;
        (*iter)++;
    }
    printf("NAME: \"%s\". \n", name);
   
    return name;
}