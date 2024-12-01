#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10000

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int older[MAX + 1] = { 0, };
    int younger[MAX + 1] = { 0, };
    int oldersTopps = 0, youngersTopps = 0, fairs = 0;

    for (int i = 0; i < topping_len; i++)
    {
        int topps = topping[i];

        if (younger[topps] == 0)
            youngersTopps++;

        younger[topps]++;
    }

    for (int i = 0; i < topping_len; i++)
    {
        int topps = topping[i];
        younger[topps]--;

        if (younger[topps] == 0)
            youngersTopps--;

        if (older[topps] == 0)
            oldersTopps++;

        older[topps]++;

        if (youngersTopps == oldersTopps)
            fairs++;
    }


    return fairs;
}