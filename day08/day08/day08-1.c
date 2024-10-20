#include <stdio.h>
#include <string.h>

int main() {
    char input[100], temp[100];
    char* poi;

    printf("문자열을 입력하세요 : ");
    scanf_s("%s", input, sizeof(input));

    poi = input + strlen(input) - 1;

    for (int i = 0; i < strlen(input); i++) {
        temp[i] = *poi;
        poi--;
    }
    temp[strlen(input)] = '\0';

    strcpy_s(input, sizeof(input), temp);

    printf("뒤집어진 문자열 : %s", input);

    return 0;
}