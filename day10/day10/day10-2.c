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

struct Customer* create_node(char* name, int rank, int order_amount, int point) // char ������
{
	struct Customer* new_node = (struct Customer*)malloc(sizeof(struct Customer));
	new_node->prev = NULL;
	new_node->customerName = (char*)malloc(sizeof(char) * NAME);
	strcpy_s(new_node->customerName, NAME, name); // strcpy_s(new_node->name, <ũ��>, <�ҽ�>)
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
	struct Customer* cur = head->next; // ���� ���

	if (cur == NULL) return head; // ù ��° �� ���� ����

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
		printf("�̸� : %s, ��� : %d, �ֹ��� : %d, ����Ʈ : %d\n", cur->customerName, cur->rank, cur->order_amount, cur->point);
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
			printf("��� : ");
			scanf_s("%d", &cur->rank);
			printf("�ֹ��� : ");
			scanf_s("%d", &cur->order_amount);
			printf("����Ʈ : ");
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
		printf("1. ���� ������ �Է�\n");
		printf("2. �� ���� ����\n");
		printf("3. �� ���� ����\n");
		printf("4. ��ü �� ���� ����Ʈ ���\n");
		printf("5. ���α׷� ����\n");
		printf("input : ");
		scanf_s("%d", &input);

		switch (input) {
		case 1:
			printf("�� �̸� : ");
			scanf_s("%s", name, NAME);
			printf("��� : ");
			scanf_s("%d", &rank);
			printf("�ֹ��� : ");
			scanf_s("%d", &orders);
			printf("����Ʈ : ");
			scanf_s("%d", &points);

			create_node(name, rank, orders, points);
			break;
		case 2:
			printf("������ ���� �̸� : ");
			scanf_s("%s", name, NAME);
			delete_node(name);
			break;
		case 3:
			printf("������ ������ ���� �̸� : ");
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
