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
        if (younger[topping[i]] == 0)
            youngersTopps++;

        younger[topping[i]]++;
    }

    for (int i = 0; i < topping_len; i++)
    {
        younger[topping[i]]--;

        if (younger[topping[i]] == 0)
            youngersTopps--;

        if (older[topping[i]] == 0)
            oldersTopps++;

        older[topping[i]]++;

        if (youngersTopps == oldersTopps)
            fairs++;
    }


    return fairs;
}