#include <stdio.h>

int check(int num1);

int main(void) 
{
	int input;
	printf("�Ҽ����� Ȯ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &input);

	check(input);
}

int check(int num1)
{
	if ((num1 == 2) || (num1 == 3) || (num1 == 5) || (num1 == 7))
	{
		printf("�ش� ���� �Ҽ��Դϴ�.(1)\n");
		return 0;
	}
	else
	{
		if ((num1 % 2 == 0) || (num1 % 3 == 0) || (num1 % 5 == 0) || (num1 % 7 == 0))
		{
			printf("�ش� ���� �Ҽ��� �ƴմϴ�(0)\n");
			return 0;
		}
		else
		{
			printf("�ش� ���� �Ҽ��Դϴ�(1).\n");
			return 0;
		}
	}
}
