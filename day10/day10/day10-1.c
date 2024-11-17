#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME (50)

struct NODE {
	char name[NAME];
	int score;
	struct NODE* link;
};

struct NODE* head = NULL;

struct NODE* create_node(char* name, int score) // char 포인터
{
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	strcpy_s(new_node->name, NAME, name); // strcpy_s(new_node->name, <크기>, <소스>)
	new_node->score = score;
	new_node->link = NULL;

	return new_node;
}

struct NODE* last_node()
{
	struct NODE* cur = head;
	while (cur->link != NULL)
	{
		cur = cur->link;
	}

	return cur;
}

void insert_node_last(struct NODE* new_node)
{
	struct NODE* last = last_node();
	last->link = new_node;
}

struct NODE* find_node_insert(int score)
{
	struct NODE* prev = head; // 이전 노드
	struct NODE* cur = head->link; // 현재 노드

	if (cur == NULL) return head; // 첫 번째 때 오류 방지

	while (cur != NULL)
	{
		if (cur->score >= score)
		{
			if (cur->link == NULL) return cur;

			prev = cur;
			cur = cur->link;
		}
		else
		{
			return prev;
		}
	}

	return cur;
}

void insert_node_priority(struct NODE* new_node)
{
	struct NODE* N = find_node_insert(new_node->score);
	new_node->link = N->link; // ! 로직 파악할 것
	N->link = new_node;
}

void print_nodes()
{
	struct NODE* cur = head->link;

	printf("--------------------------------\n");

	while (cur != NULL)
	{
		printf("%s  :		%d\n", cur->name, cur->score);
		cur = cur->link;
	}
	printf("--------------------------------\n");

}

int delete_node(char *name)
{
	struct NODE* prev = head;
	struct NODE* cur = head->link;
	while (cur != NULL)
	{
		if (strcmp(name, cur->name) == 0)
		{
			prev->link = cur->link;
			free(cur);
			return 1;
		}

		prev = cur;
		cur = cur->link;
	}
	return 0;
}

int main()
{
	head = (struct NODE*)malloc(sizeof(struct NODE));
	head->link = NULL;

	int input;
	int status = 1;

	char name[NAME];
	int score;

	while (status) {
		printf("1. 학생의 성적을 입력\n");
		printf("2. 학생 정보 삭제\n");
		printf("3. 프로그램 종료\n");
		printf("input : ");
		scanf_s("%d", &input);

		switch (input) {
		case 1:
			printf("학생 이름 : ");
			scanf_s("%s", name, NAME);
			printf("점수 : ");
			scanf_s("%d", &score);

			insert_node_priority(create_node(name, score));
			break;
		case 2:
			printf("삭제할 학생의 이름 : ");
			scanf_s("%s", name, NAME);
			delete_node(name);
			break;
		case 3:
		default:
			status = 0;
			break;
		}

		print_nodes();
	}

	return 0;
}



