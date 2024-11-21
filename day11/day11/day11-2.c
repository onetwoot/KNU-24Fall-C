#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

//double�� ������ ���� : float�� �ϸ� ���� �սǵǼ� ���� �̻��ϰ� ����
int tries = 0; // add �Լ� ���� ���� ȸ�� ����
double startTries; // �簢���� ���̸� ���ϱ� ���� ��ǥ 
// int������ �����ؼ� float �Ҽ��� ���� ������ �սǵǼ� ���� �̻��ϰ� ������
double res = 0; // ���� ��� ����

void add(double f, int max); // ���б������� �����ϴ� �Լ�

int main(void)
{
	int start, end, max, store; // start : ���� ��, end : �� ��, max : �ִ� ����, store : ���� ���� �� �� ������ ���� ����
	double f; // �簢�� ���� ������ ����

	printf("������ ���� ���� �Է��ϼ���. : ");
	scanf_s("%d", &start);

	printf("������ �� ���� �Է��ϼ��� : ");
	scanf_s("%d", &end);

	printf("������ �ִ� ������ �Է��ϼ���(2^n) : ");
	scanf_s("%d", &max);

	store = end - start;

	for (int i = 0; i <= max; i++)
	{
		f = store / pow(2, i);
		startTries = start; // startTries�� start�� �ʱ�ȭ
		add(f, i);
	}

	return 0;
}

void add(double f, int i)
{
	while (tries < pow(2, i)) // startTries == end �ϸ� ������ ���� �� �־ ���� ȸ���� ���� ������
	{
		if (tries != 0) // ó�� ���࿡�� start�� ������ �簢���� ���̸� ���ؾ���
			startTries += f; // startTries�� ��ǥ �̵�

		res += (-1 * log10(1 / startTries) + sin(startTries)) * f;
		tries++;
	}

	printf("���� : %10d, ���� ��� : %lf\n", (int)pow(2, i), res);
	startTries = 0; // startTries �� �ʱ�ȭ
	res = 0; // res �� �ʱ�ȭ (�����߻� �� ����)
	tries = 0; // tries �� �ʱ�ȭ (�����߻� �� ����)
	return;
}

