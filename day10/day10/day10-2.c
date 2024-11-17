#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME (50)

enum rank {A = 1, B, C, D, F};

struct Customer {
	struct Customer* prev;
	char* customerName;
	enum rank rank;
	int order_amount;
	int point;
	struct Customer* next;
};

struct Customer* head = NULL;
struct Customer* tail = NULL;

struct Customer* create_node(char* name, int rank, int order_amount, int point) // char 포인터
{
	struct Customer* new_node = (struct Customer*)malloc(sizeof(struct Customer));
	new_node->prev = NULL;
	new_node->customerName = (char*)malloc(sizeof(char) * NAME);
	strcpy_s(new_node->customerName, NAME, name); // strcpy_s(new_node->name, <크기>, <소스>)
	new_node->rank = rank;
	new_node->order_amount = order_amount;
	new_node->point = point;
	new_node->next = NULL;

	return new_node;
}

struct Customer* last_node()
{
	struct Customer* cur = head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	return cur;
}

/* struct Customer* connect_node(char* name, int rank, int order_amount, int point) {
	struct Customer* new_node = create_node(name, rank, order_amount, point);
	struct Customer* p = tail;
	p->prev->next = new_node;
	new_node->prev = p->prev;
	p->prev = new_node;
	new_node->next = p;

	return new_node;
} */

void insert_node_last(struct Customer* new_node)
{
	struct Customer* last = last_node();
	last->next = new_node;
}

struct Customer* find_node_insert(enum rank rank, int order_amount, int point)
{
	struct Customer* cur = head->next; // 현재 노드

	if (cur == NULL) return head; // 첫 번째 때 오류 방지

	while (cur != NULL)
	{
		if (cur->rank < rank)
		{
			if (cur->next == NULL) return cur;

			cur->prev = cur;
			cur = cur->next;
		}
		else if (cur->order_amount > order_amount)
		{
			if (cur->next == NULL) return cur;

			cur->prev = cur;
			cur = cur->next;
		}
		else if (cur->point > point)
		{
			if (cur->next == NULL) return cur;

			cur->prev = cur;
			cur = cur->next;
		}
		else
		{
			return cur->prev;
		}
	}

	return cur;
}

void insert_node_priority(struct Customer* new_node)
{
	struct Customer* N = find_node_insert(new_node->rank, new_node->order_amount, new_node->point);
	new_node->next = N->next;
	N->next = new_node;
}

void print_nodes()
{
	struct Customer* cur = head->next;

	printf("----------------------------------------------------------------\n");

	while (cur != NULL)
	{
		printf("이름 : %s, 등급 : %d, 주문량 : %d, 포인트 : %d\n", cur->customerName, cur->rank, cur->order_amount, cur->point);
		cur = cur->next;
	}
	printf("----------------------------------------------------------------\n");

}

int delete_node(char* name)
{
	struct Customer* cur = head->next;
	while (cur != NULL)
	{
		if (strcmp(name, cur->customerName) == 0)
		{
			cur->next->prev = cur->prev;
			cur->prev->next = cur->next;
			free(cur);
			return 1;
		}

		cur->prev = cur;
		cur = cur->next;
	}
	return 0;
}

int modify_node(char* name)
{
	struct Customer* cur = head->next;
	while (cur != NULL)
	{
		if (strcmp(name, cur->customerName) == 0)
		{
			printf("등급 : ");
			scanf_s("%d", &cur->rank);
			printf("주문량 : ");
			scanf_s("%d", &cur->order_amount);
			printf("포인트 : ");
			scanf_s("%d", &cur->point);

			return cur;
		}
	}

}

int main()
{
	head = (struct Customer*)malloc(sizeof(struct Customer));
	tail = (struct Customer*)malloc(sizeof(struct Customer));
	
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;

	int input;
	int status = 1;

	char name[NAME];
	enum rank rank;
	int orders, points;

	while (status) {
		printf("1. 고객의 정보를 입력\n");
		printf("2. 고객 정보 삭제\n");
		printf("3. 고객 정보 수정\n");
		printf("4. 전체 고객 정보 리스트 출력\n");
		printf("5. 프로그램 종료\n");
		printf("input : ");
		scanf_s("%d", &input);

		switch (input) {
		case 1:
			printf("고객 이름 : ");
			scanf_s("%s", name, NAME);
			printf("등급 : ");
			scanf_s("%d", &rank);
			printf("주문량 : ");
			scanf_s("%d", &orders);
			printf("포인트 : ");
			scanf_s("%d", &points);

			create_node(name, rank, orders, points);
			break;
		case 2:
			printf("삭제할 고객의 이름 : ");
			scanf_s("%s", name, NAME);
			delete_node(name);
			break;
		case 3:
			printf("정보를 수정할 고객의 이름 : ");
			scanf_s("%s", name, NAME);

			insert_node_priority(modify_node(name));
			break;
		case 4:
			break;
		case 5:
		default:
			status = 0;
			break;
		}

		print_nodes();
	}

	return 0;
}
