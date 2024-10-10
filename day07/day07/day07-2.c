#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void)
{
	double x = 0, y = 0;
	int count = 0, circle = 0, i = 0, j = 0, k = 0, z = 0;

	srand(time(NULL));


	for (i = 0; i <= 1000000000; i++)
	{
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX;
		count++;

		if (sqrt(pow(x, 2) + pow(y, 2)) <= 1)
		{
			circle++;
		}

		if (i % 10000000 == 0 && !i == 0)
		{
			printf("%d%%진행.. 원주율 : %0.6f ", i / 10000000, ((double)circle / count) * 4.0);

			j = i / 50000000;
			k = 20 - j;

			for (z = 0; z <= j - 1; z++)
			{
				printf("\u25A0");
			}

			for (z = 0; z <= k - 1; z++)
			{
				printf("\u25A1");
			}

			printf("\n");

		}

		/* if (i % 10000000 == 0 && !i == 0)
		{
			printf("%d%%진행.. 원주율 : %0.6f ", i / 10000000, ((double)circle / count) * 4.0);
			if (i < 50000000)
				printf("\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 100000000 && i >= 50000000)
				printf("\u25A0\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 150000000 && i >= 100000000)
				printf("\u25A0\u25A0\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 200000000 && i >= 150000000)
				printf("\u25A0\u25A0\u25A0\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 250000000 && i >= 200000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 300000000 && i >= 250000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 350000000 && i >= 300000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 400000000 && i >= 350000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 450000000 && i >= 400000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 500000000 && i >= 450000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 550000000 && i >= 500000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 600000000 && i >= 550000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 650000000 && i >= 600000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 700000000 && i >= 650000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 750000000 && i >= 700000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A1\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 800000000 && i >= 750000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A1\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 850000000 && i >= 800000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A1\u25A1\u25A1\u25A1\n");
			else if (i < 900000000 && i >= 850000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A1\u25A1\u25A1\n");
			else if (i < 950000000 && i >= 900000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A1\u25A1\n");
			else if (i < 1000000000 && i >= 950000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A1\n");
			else if (i == 1000000000)
				printf("\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\n");
		} */
	}

	printf("원주율 : %0.6f\n", ((double)circle / count) * 4.0);


	return 0;
}