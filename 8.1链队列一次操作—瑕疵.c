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
typedef struct {//����һ�������нڵ�
	ElemType data;
	qNode *next;
}qNode;
typedef struct{//��������ָ��Ŀ��
	qNode *front, *rear;
}pNode;
pNode* initPNode(void) {//��ʼ��������
	pNode* P;qNode*Q;
	P = (pNode*)malloc(sizeof(pNode));//����ָ��ڵ�
	Q = (qNode*)malloc(sizeof(qNode));//������Ϣ�ڵ�
	Q->next = NULL;
	P->front = P->rear = Q;
	return P;
}
Status addQ(pNode* P, ElemType e) {//���
	qNode* Q;
	if (!(Q = (qNode*)malloc(sizeof(qNode)))) return ERROR;
	Q->data = e;
	Q->next = NULL;
	(P->rear)->next = Q;
	P->rear = Q;
	return OK;
}
Status getQ(pNode* p, ElemType *e) {//����
	qNode*Q;
	if (p->front == p->rear) return ERROR;//p->frontʼ��Ϊ�սڵ㣡����
	Q = (p->front)->next;
	*e = Q->data;
	free((p->front)->next);
	(p->front)->next = Q->next;
	free(Q);
	return OK;
}
void destroy(pNode* p) {//���ٶ���

}