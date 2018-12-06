#include<stdlib.h>
#include<stdio.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1//不可实行的
#define OVERFLOW -2//溢出
#define MAX_CONTAINER_SIZE 100//容器的容量
typedef int Status;//函数结果状态代码
typedef int ElemType;//栈存储的数据的类型
typedef struct a {
	ElemType queue[MAX_CONTAINER_SIZE];
	int num;
	int front;
	int rear;
}seqQueue;
seqQueue* init(void) {
	seqQueue* q = (seqQueue*)malloc(sizeof(seqQueue));
	q->front = q->rear = -1;
	q->num = 0;
	return q;
}
Status add(seqQueue*q, ElemType e) {
	if (q->rear == (MAX_CONTAINER_SIZE-1 )) q->rear = -1;
	if (&(q->queue[q->rear + 1]) == &(q->queue[q->front])) {
		printf("The queue has been FULL, Please get the Element\n");
		return ERROR;
	}
	q->rear++;
	q->queue[q->rear] = e;
	return OK;
}
Status get(seqQueue*q, ElemType *e) {
	if (q->front == (MAX_CONTAINER_SIZE - 1)) q->front = -1;
	if (q->front == q->rear) {
		printf("The queue has been EMPTY, Please add the Element\n");
		return ERROR;
	}
	q->front++;
	*e = q->queue[q->front];
	q->num--;
	return OK;
}
int main() {

	system("pause");
	return 0;
}