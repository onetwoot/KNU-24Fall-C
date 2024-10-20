#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);

int i, j;

int main(void)
{
	int array[SIZE][SIZE];

	fillRandom(array);
	printArray(array);
	movePointer(array);

	return 0;
}

void fillRandom(int array[SIZE][SIZE])
{
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			array[i][j] = rand() % 20 + 1;
		}
	}
}

void printArray(int array[SIZE][SIZE])
{
	printf("배열 출력 :\n");

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("%3d", array[i][j]);
		}
		printf("\n");
	}
}

void movePointer(void* array)
{
	int x = 0, y = 0, move = 0, before = 0;

	while (1)
	{
		x = move % 10;
		y = move / 10;

		before = *((int*)array + move);

		printf("%d", move);
		printf("현재 위치 : (%d, %d), 배열의 값 : %d\n", x, y, *((int*)array + move));

		move += *((int*)array + move);

		if (move >= 100)
		{
			printf("더이상 이동할 수 없습니다.\n");
			break;
		}
	}

	printf("종료 위치 : (%d, %d), 배열의 값 : %d\n", x, y, before);
}