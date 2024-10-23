#include <stdio.h>

void vecAdd(struct save vec1, struct save vec2);
void vecSub(struct save vec1, struct save vec2);
void vecDot(struct save vec1, struct save vec2);
void vecCro(struct save vec1, struct save vec2);

struct save {
	int arr1, arr2, arr3;
};

struct save res;

int main(void) {
	struct save vec1, vec2;
	int input;
	
	printf("ù��° ����(x, y, z) : ");
	scanf_s("%d %d %d", &vec1.arr1, &vec1.arr2, &vec1.arr3);
	printf("�ι�° ����(x, y, z) : ");
	scanf_s("%d %d %d", &vec2.arr1, &vec2.arr2, &vec2.arr3);

	printf("�Էµ� ù��° ����\t%d,\t%d,\t%d\n", vec1.arr1, vec1.arr2, vec1.arr3);
	printf("�Էµ� �ι�° ����\t%d,\t%d,\t%d\n", vec2.arr1, vec2.arr2, vec2.arr3);

	printf("\n--------------------------------------------\n");

	printf("1. ������ ��\n");
	printf("2. ������ ��\n");
	printf("3. ������ ����\n");
	printf("4. ������ ����\n");
	printf("5. ����\n");

	printf("\n--------------------------------------------\n");

	printf("��� �Է� : ");
	scanf_s("%d", &input);

	switch (input) {
	case 1 :
		vecAdd(vec1, vec2);
		break;
	case 2 :
		vecSub(vec1, vec2);
		break;
	case 3 :
		vecDot(vec1, vec2);
		break;
	case 4 :
		vecCro(vec1, vec2);
		break;
	case 5 :
		return 0;
	}

	printf("\n--------------------------------------------\n");

	return 0;
}

void vecAdd(struct save vec1, struct save vec2) {
	res.arr1 = vec1.arr1 + vec2.arr1;
	res.arr2 = vec1.arr2 + vec2.arr2;
	res.arr3 = vec1.arr3 + vec2.arr3;

	printf("������ ����   x = %d   y = %d   z = %d", res.arr1, res.arr2, res.arr3);
}

void vecSub(struct save vec1, struct save vec2) {
	res.arr1 = vec1.arr1 - vec2.arr1;
	res.arr2 = vec1.arr2 - vec2.arr2;
	res.arr3 = vec1.arr3 - vec2.arr3;

	printf("������ ����   x = %d   y = %d   z = %d", res.arr1, res.arr2, res.arr3);
}

void vecDot(struct save vec1, struct save vec2) {
	int dotRes;

	dotRes = vec1.arr1 * vec2.arr1 + vec1.arr2 * vec2.arr2 + vec1.arr3 * vec2.arr3;

	printf("������ ������   %d", dotRes);
}

void vecCro(struct save vec1, struct save vec2) {
	res.arr1 = vec1.arr2 * vec2.arr3 - vec1.arr3 * vec2.arr2;
	res.arr2 = vec1.arr3 * vec2.arr1 - vec1.arr1 * vec2.arr3;
	res.arr3 = vec1.arr1 * vec2.arr2 - vec1.arr2 * vec2.arr1;

	printf("������ ������   x = %d   y = %d   z = %d", res.arr1, res.arr2, res.arr3);
}