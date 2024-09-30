#include <stdio.h>

int main(void)
{
	int input;

	printf("층수를 입력하십시오. : ");
	scanf_s("%d", &input);

	for (int i = 0; i < input; i++)
	{
		for (int j = 1; j < input - i; j++)
		{
			printf(" ");
		}
		for (int k = 0; k < i * 2 + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}