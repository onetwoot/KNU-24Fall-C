#include <stdio.h>

void swap(int *pnum1, int *pnum2);

int main(void)
{
	int num1 = 10 , num2 = 20;
	printf("swap 함수 호출 전 : num1 = %d, num2 = %d\n", num1, num2);

	swap(&num1, &num2);

	printf("swap 함수 호출 후 : num1 = %d, num2 = %d\n", num1, num2);

	return 0;
}

void swap(int *pnum1, int *pnum2)
{
	int num3 = *pnum1;
	*pnum1 = *pnum2;
	*pnum2 = num3;
}