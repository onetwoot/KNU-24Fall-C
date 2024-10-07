#include <stdio.h>

int main()
{
	FILE* fp = NULL;
	fopen_s(&fp, "data.txt", "rt");

	int n1, n2, n3;
	
	while (fscanf_s(fp, "%d %d %d", &n1, &n2, &n3) != EOF)
	{
		printf("%d %d %d\n", n1, n2, n3);
	}

	fclose(fp);

	return 0;
}