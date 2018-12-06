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
typedef struct a {
	ElemType data;
	struct a *next;
}dNode;
typedef struct {
	dNode *front;
	dNode *rear;
}pNode;
pNode *init(void) {
	pNode* P = (pNode*)malloc(sizeof(pNode));
	dNode* D = (dNode*)malloc(sizeof(dNode));
	P->front = P->rear = D;
	D->data = 0;
	D->next = NULL;
	return P;
}
Status add(pNode *P, ElemType e) {
	dNode* D;
	D = (dNode*)malloc(sizeof(dNode));
	if (!D) return ERROR;
	D->data = e;
	D->next = NULL;
	(P->rear)->next = D;
	P->rear = D;
	return OK;
}
Status get(pNode* P, ElemType *e) {//最终发现了问题
	dNode* D;
	if(P->front==P->rear) return ERROR;
	D=(P->front)->next;
	*e=D->data;
	P->front=D->next;
	free(D);
	return OK;
}
Status destroy(pNode *P) {
	while (P->front!=NULL) {
		P->rear = (P->front)->next;
		free(P->front);
		P->front = P->rear;
	}
	free(P);
	printf("QUEUE has been destroied.\n");
	return OK;
}
int main() {
	pNode*P = init();
	int i;
	printf("Please add the element:\n");
	for (i = 1;; i++) {
		printf("ELE%d ", i);
		int e;
		scanf("%d", &e);
		if (e == 0) {
			i--;
			break;
		}
		add(P, e);
	}
	printf("\n%d\n", i);
	for (int j = 1; j <= i; j++) {
		ElemType e;
		get(P, &e);
		printf("%d ", e);
	}
	system("pause");
	return 0;
}