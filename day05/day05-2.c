#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	int arr;
	char *name;
	int score;
};

int main()
{
	int n;
	struct Student person;

	person.arr = 1111;
	person.name = (char*)malloc(sizeof(char) * 50);
	strcpy_s(person.name, 50, "Ã¶¼ö");
	person.score = 100;

	printf("%d %s %d\n", person.arr, person.name, person.score);
}