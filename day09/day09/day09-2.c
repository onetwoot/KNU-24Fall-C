#include <stdio.h>

void printProduct(struct Product one);

struct Product {
	int id;
	char name[100];
	int pri;
};

int main(void) {
	struct Product s[5];

	for (int i = 0; i < 5; i++) {
		printf("��ǰ ������ �Է��ϼ���. (�Է� �ߴ��� id�� 0 �Է�)\n");
		printf("��ǰ ID : ");
		scanf_s("%d", &s[i].id);

		if (s[i].id == 0)
			break;

		printf("��ǰ�� : ");
		scanf_s("%s", &s[i].name, 100);

		printf("���� : ");
		scanf_s("%d", &s[i].pri);

		printf("\n");
	}

	printf("\n<<�Էµ� ��ǰ ���>>\n");

	for (int i = 0; i < 5; i++) {
		if (s[i].id == 0)
			break;

		printProduct(s[i]);
	}

	return 0;
}

void printProduct(struct Product one) {
	printf("��ǰ ID : %d\n", one.id);
	printf("��ǰ�� : %s\n", one.name);
	printf("���� : %d��\n", one.pri);
	printf("\n");
}