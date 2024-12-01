#include <stdio.h>

int main(void)
{
    int n = 5000, jump = 0; // input == n, jump은 점프 회수 저장 겸 배터리 사용량

    while (n != 0)
    {
        if (n % 2 == 1)
        {
            jump++;
            n--;
        }
        n /= 2;
    }
           
    printf("%d", jump);
    return 0;
}