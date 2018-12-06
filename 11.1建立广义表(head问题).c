#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_CONTAINER_SIZE 100
typedef int Status;
typedef int ElemType;
typedef struct node0 {
	int flag;
	union {
		ElemType data;
		struct node0* down;
	};
	struct node0* next;
}nod;

Status CreatTable(nod* node) {//遍历
	node = (nod*)malloc(sizeof(nod));
	char judge1;
	printf("Data Noed Y/N?\n");
	judge1 = getchar();
	getchar();
	if (judge1 == 'Y') {
		node->flag = 0;
		printf("Please input your Element: ");
		scanf("%d", &node->data);
	}
	else {
		node->flag = 1;
		CreatTable(node->down);
	}
	char judge2;
	printf("Next Y/N?\n");
	judge2 = getchar();
	getchar();
	if (judge2 == 'Y') {
		CreatTable(node->next);
	}
	else {
		node->next = NULL;
	}
	return OK;
}
int main() {
	nod* head;
	CreatTable(head);
	printf("Creat Over\n");
	system("pause");
	return 0;
}
