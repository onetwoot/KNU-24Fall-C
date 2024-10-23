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
		printf("상품 정보를 입력하세요. (입력 중단은 id에 0 입력)\n");
		printf("상품 ID : ");
		scanf_s("%d", &s[i].id);

		if (s[i].id == 0)
			break;

		printf("상품명 : ");
		scanf_s("%s", &s[i].name, 100);

		printf("가격 : ");
		scanf_s("%d", &s[i].pri);

		printf("\n");
	}

	printf("\n<<입력된 상품 목록>>\n");

	for (int i = 0; i < 5; i++) {
		if (s[i].id == 0)
			break;

		printProduct(s[i]);
	}

	return 0;
}

void printProduct(struct Product one) {
	printf("상품 ID : %d\n", one.id);
	printf("상품명 : %s\n", one.name);
	printf("가격 : %d원\n", one.pri);
	printf("\n");
}