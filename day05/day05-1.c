#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int *arr;
	char **name;
	int *score;

	printf("학생 수 입력 : ");
	scanf_s("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);
	name = (char**)malloc(sizeof(char*) * n);
	score = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		name[i] = (char*)malloc(100 * sizeof(char));
	}
	
	for (int i = 0; i < n; i++)
	{
		printf("학번 : ");
		scanf_s("%d", &arr[i]);

		printf("이름 : ");
		scanf_s("%s", name[i], 100);

		printf("점수 : ");
		scanf_s("%d", &score[i]);

	}

	for (int i = 0; i < n; i++)
	{
		printf("%d %s %d\n", arr[i], name[i], score[i]);
	}

	free(arr);
	free(score);
	for (int i = 0; i < n; i++)
	{
		free(name[i]);
	}
	free(name);

	return 0;
}