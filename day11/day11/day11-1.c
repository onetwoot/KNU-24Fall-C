#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void)
{
	int a, b, c; // ��� ����
	float res1, res2; // �� ����
	
	printf("������������ ����� �Է��Ͻÿ�. (ax^2 + bx + c): ");
	scanf_s("%d %d %d", &a, &b, &c);

	if ((pow(b, 2) - 4 * a * c) < 0) // �Ǻ������� ������� Ȯ��
	{
		printf("�� ������������ ����� �����ϴ�.\n");
		return 0;
	}

	res1 = (-1 * b + sqrt(pow(b, 2) - 4 * a * c)) / (float)2 * a;
	res2 = (-1 * b - sqrt(pow(b, 2) - 4 * a * c)) / (float)2 * a;

	if ((pow(b, 2) - 4 * a * c) == 0) // �Ǻ������� �߱����� Ȯ��
	{
		printf("�� ������������ �߱��� ������ �� �ش� ������ �����ϴ�.\n");
		printf("x = %.2f\n", res1);
		return 0;
	}

	printf("�� ������������ �ش� x = %.2f �Ǵ� x = %.2f �Դϴ�.\n", res1, res2);
	return 0;
}