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
typedef struct {//定义一个链队列节点
	ElemType data;
	qNode *next;
}qNode;
typedef struct{//定义两个指针的块块
	qNode *front, *rear;
}pNode;
pNode* initPNode(void) {//初始化链队列
	pNode* P;qNode*Q;
	P = (pNode*)malloc(sizeof(pNode));//开辟指针节点
	Q = (qNode*)malloc(sizeof(qNode));//开辟信息节点
	Q->next = NULL;
	P->front = P->rear = Q;
	return P;
}
Status addQ(pNode* P, ElemType e) {//入队
	qNode* Q;
	if (!(Q = (qNode*)malloc(sizeof(qNode)))) return ERROR;
	Q->data = e;
	Q->next = NULL;
	(P->rear)->next = Q;
	P->rear = Q;
	return OK;
}
Status getQ(pNode* p, ElemType *e) {//出队
	qNode*Q;
	if (p->front == p->rear) return ERROR;//p->front始终为空节点！！！
	Q = (p->front)->next;
	*e = Q->data;
	free((p->front)->next);
	(p->front)->next = Q->next;
	free(Q);
	return OK;
}
void destroy(pNode* p) {//销毁队列

}