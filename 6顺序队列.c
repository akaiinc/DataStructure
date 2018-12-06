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
typedef int ElemType;//ջ�洢�����ݵ�����
typedef struct {//����һ������
	ElemType queue_array[MAX_STACK_SIZE];
	int front;
	int rear;
}queue;
Status Init(void) {//��ʼ��˳�����
	queue Q;
	Q.front = Q.rear = -1;
	return OK;
}
Status addQ(queue* Q, ElemType e) {//���
	if (full(&Q))
		return ERROR;
	Q->rear += 1;
	Q->queue_array[Q->rear] = e;
	return OK;
}
Status getQ(queue* Q,ElemType *e){//����
	if (empty(&Q))
		return ERROR;
	Q->front += 1;
	*e = Q->queue_array[Q->front];
	return OK;
}
Status empty(queue* Q) {//�գ�
	if (Q->front == Q->rear)
		return TURE;
	else
		return FALSE;
}
Status full(queue* Q) {//����
	if (Q->rear == (MAX_STACK_SIZE)-1)
		return TURE;
	return FALSE;
}