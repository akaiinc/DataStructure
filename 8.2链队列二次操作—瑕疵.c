#include<stdlib.h>
#include<stdio.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1//不可实行的
#define OVERFLOW -2//溢出
#define MAX_STACK_SIZE 100//顺序对的容量
typedef int Status;//函数结果状态代码
typedef int ElemType;//队列存储的数据的类型
typedef struct que{//定义一个链队列节点
	ElemType data;
	struct que *next;
}iNode;
typedef struct{//定义两个指针的块块
	iNode *front, *rear;
}pNode;
pNode* init(void) {//初始化
	pNode* P = (pNode*)malloc(sizeof(pNode));
	iNode* I = (iNode*)malloc(sizeof(iNode));
	P->front = P->rear = I;
	I->next = NULL;
	return P;
}
Status addNode(pNode* P, ElemType e) {//入队
	iNode* I = (iNode*)malloc(sizeof(iNode));
	if (!I) return ERROR;
	I->data = e;
	I->next = NULL;
	(P->rear)->next = I;
	P->rear = I;
	return OK;
}
Status getNode(pNode* P, ElemType *e) {//出队
	if (P->front == P->rear) return ERROR;
	iNode* I = (iNode*)malloc(sizeof(iNode));
	I = (P->front)->next;
	*e = I->data;
	free((P->front)->next);
	(P->front)->next = I->next;
	if ((P->front)->next == NULL) P->rear = P->front;//考虑若是最后一个节点的话
	free(I);
	return OK;
}
Status destroy(pNode* p) {//销毁队列
	while (p->front != NULL) {
		p->rear = (p->front)->next;
		free(p->front);
		p->front = p->rear;
	}
	free(p);
	return OK;
}
int main() {
	pNode* p;
	p = init();
	for (int i = 1;i <= 10;i++) {
		addNode(p, i);
	}
	system("pause");
	return 0;
}