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
typedef int ElemType;//栈存储的数据的类型
typedef struct {//定义一个队列
	ElemType queue_array[MAX_STACK_SIZE];
	int front;
	int rear;
}queue;
Status Init(void) {//初始化顺序队列
	queue Q;
	Q.front = Q.rear = -1;
	return OK;
}
Status addQ(queue* Q, ElemType e) {//入队
	if (full(&Q))
		return ERROR;
	Q->rear += 1;
	Q->queue_array[Q->rear] = e;
	return OK;
}
Status getQ(queue* Q,ElemType *e){//出队
	if (empty(&Q))
		return ERROR;
	Q->front += 1;
	*e = Q->queue_array[Q->front];
	return OK;
}
Status empty(queue* Q) {//空？
	if (Q->front == Q->rear)
		return TURE;
	else
		return FALSE;
}
Status full(queue* Q) {//满？
	if (Q->rear == (MAX_STACK_SIZE)-1)
		return TURE;
	return FALSE;
}