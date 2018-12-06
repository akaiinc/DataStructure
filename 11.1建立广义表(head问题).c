#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1//不可实行的
#define OVERFLOW -2//溢出
#define MAX_CONTAINER_SIZE 100//容器的容量
typedef int Status;//函数结果状态代码
typedef int ElemType;//存储的数据的类型
typedef struct node0 {//定义一个节点
	int flag;//1为表节点，0为数据节点
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