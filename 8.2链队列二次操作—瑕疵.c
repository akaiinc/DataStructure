#include<stdlib.h>
#include<stdio.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1//����ʵ�е�
#define OVERFLOW -2//���
#define MAX_STACK_SIZE 100//˳��Ե�����
typedef int Status;//�������״̬����
typedef int ElemType;//���д洢�����ݵ�����
typedef struct que{//����һ�������нڵ�
	ElemType data;
	struct que *next;
}iNode;
typedef struct{//��������ָ��Ŀ��
	iNode *front, *rear;
}pNode;
pNode* init(void) {//��ʼ��
	pNode* P = (pNode*)malloc(sizeof(pNode));
	iNode* I = (iNode*)malloc(sizeof(iNode));
	P->front = P->rear = I;
	I->next = NULL;
	return P;
}
Status addNode(pNode* P, ElemType e) {//���
	iNode* I = (iNode*)malloc(sizeof(iNode));
	if (!I) return ERROR;
	I->data = e;
	I->next = NULL;
	(P->rear)->next = I;
	P->rear = I;
	return OK;
}
Status getNode(pNode* P, ElemType *e) {//����
	if (P->front == P->rear) return ERROR;
	iNode* I = (iNode*)malloc(sizeof(iNode));
	I = (P->front)->next;
	*e = I->data;
	free((P->front)->next);
	(P->front)->next = I->next;
	if ((P->front)->next == NULL) P->rear = P->front;//�����������һ���ڵ�Ļ�
	free(I);
	return OK;
}
Status destroy(pNode* p) {//���ٶ���
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