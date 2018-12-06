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
typedef struct nodeStructure {
	int type;//数据1
	union {
		ElemType data;//数据2
		struct nodeStructure *down;//or 向下的指针
	};
	struct nodeStructure* after;//向后的指针
}node;
node* creatGenList() {
	node * knot= (node*)malloc(sizeof(node));
	printf("Creat down node(Y) or Input data(N) :");
	char judge1;
	judge1 = getchar();
	getchar();
	if (judge1 == 'Y') {
		knot->type = 1;
		knot->down = creatGenList();
	}
	else {
		knot->type = 0;
		printf("Now, please input your data: ");
		scanf("%d", &knot->data);
		getchar();
	}
	printf("Creat after node Y/N? :");
	char judge2;
	judge2 = getchar();
	getchar();
	if (judge2 == 'Y') {
		knot->after = creatGenList();
	}
	else {
		knot->after = NULL;
	}
	return knot;
}
int main() {
	node *head = creatGenList();
	printf("\nCreat general list over\n");
	system("pause");
	return 0;
}