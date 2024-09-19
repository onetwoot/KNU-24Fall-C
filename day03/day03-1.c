#include <stdio.h>

int check(int num1);

int main(void) 
{
	int input;
	printf("소수인지 확인할 수를 입력하세요 : ");
	scanf_s("%d", &input);

	check(input);
}

int check(int num1)
{
	if ((num1 == 2) || (num1 == 3) || (num1 == 5) || (num1 == 7))
	{
		printf("해당 수는 소수입니다.(1)\n");
		return 0;
	}
	else
	{
		if ((num1 % 2 == 0) || (num1 % 3 == 0) || (num1 % 5 == 0) || (num1 % 7 == 0))
		{
			printf("해당 수는 소수가 아닙니다(0)\n");
			return 0;
		}
		else
		{
			printf("해당 수는 소수입니다(1).\n");
			return 0;
		}
	}
}
