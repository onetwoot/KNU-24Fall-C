#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void)
{
	int a, b, c; // 계수 저장
	float res1, res2; // 해 저장
	
	printf("이차방정식의 계수를 입력하시오. (ax^2 + bx + c): ");
	scanf_s("%d %d %d", &a, &b, &c);

	if ((pow(b, 2) - 4 * a * c) < 0) // 판별식으로 허근임을 확인
	{
		printf("이 이차방정식은 허근을 갖습니다.\n");
		return 0;
	}

	res1 = (-1 * b + sqrt(pow(b, 2) - 4 * a * c)) / (float)2 * a;
	res2 = (-1 * b - sqrt(pow(b, 2) - 4 * a * c)) / (float)2 * a;

	if ((pow(b, 2) - 4 * a * c) == 0) // 판별식으로 중근임을 확인
	{
		printf("이 이차방정식은 중근을 가지며 그 해는 다음과 같습니다.\n");
		printf("x = %.2f\n", res1);
		return 0;
	}

	printf("이 이차방정식의 해는 x = %.2f 또는 x = %.2f 입니다.\n", res1, res2);
	return 0;
}