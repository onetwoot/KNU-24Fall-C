#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

//double로 선언한 이유 : float로 하면 값이 손실되서 답이 이상하게 나옴
int tries = 0; // add 함수 내의 시행 회수 저장
double startTries; // 사각형의 높이를 구하기 위한 좌표 
// int값으로 선언해서 float 소수점 이하 값들이 손실되서 답이 이상하게 나왔음
double res = 0; // 적분 결과 저장

void add(double f, int max); // 구분구적법을 시행하는 함수

int main(void)
{
	int start, end, max, store; // start : 시작 값, end : 끝 값, max : 최대 구간, store : 시작 값과 끝 값 사이의 값을 저장
	double f; // 사각형 간의 간격의 길이

	printf("적분할 시작 값을 입력하세요. : ");
	scanf_s("%d", &start);

	printf("적분할 끝 값을 입력하세요 : ");
	scanf_s("%d", &end);

	printf("시행할 최대 구간을 입력하세요(2^n) : ");
	scanf_s("%d", &max);

	store = end - start;

	for (int i = 0; i <= max; i++)
	{
		f = store / pow(2, i);
		startTries = start; // startTries를 start로 초기화
		add(f, i);
	}

	return 0;
}

void add(double f, int i)
{
	while (tries < pow(2, i)) // startTries == end 하면 오류가 생길 수 있어서 시행 회수를 따로 선언함
	{
		if (tries != 0) // 처음 시행에는 start의 값으로 사각형의 넓이를 구해야함
			startTries += f; // startTries의 좌표 이동

		res += (-1 * log10(1 / startTries) + sin(startTries)) * f;
		tries++;
	}

	printf("구간 : %10d, 적분 결과 : %lf\n", (int)pow(2, i), res);
	startTries = 0; // startTries 값 초기화
	res = 0; // res 값 초기화 (오류발생 후 수정)
	tries = 0; // tries 값 초기화 (오류발생 후 수정)
	return;
}

