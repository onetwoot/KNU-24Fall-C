#include <stdio.h>

int main(void)
{
    int n = 5000, jump = 0; // input == n, jump�� ���� ȸ�� ���� �� ���͸� ��뷮

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