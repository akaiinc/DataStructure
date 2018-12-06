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
typedef int ElemType;//存储的数据的类型
typedef struct infoNode {
	ElemType data;
	struct infoNode * next;
}dNode;
typedef struct {
	dNode *front;
	dNode *rear;
}pNode;
/*初始化队列*/
pNode* init(void) {
	dNode* d = (dNode*)malloc(sizeof(dNode));
	pNode* p = (pNode*)malloc(sizeof(pNode));
	d->data = 0;
	d->next = NULL;
	p->front = p->rear = d;
	return p;
}
/*队列是否为空*/
Status isEmpty(pNode* p) {
	if (p->front == p->rear) return TURE;
	return FALSE;
}
/*入队*/
Status add(pNode* p, ElemType e) {
	dNode* d;
	if (!(d = (dNode*)malloc(sizeof(dNode)))) return ERROR;
	d->data = e;
	d->next = NULL;
	(p->rear)->next = d;
	p->rear = d;
	return OK;
}
/*出队*/
Status get(pNode* p, ElemType* e) {
	if (isEmpty(p)) {
		printf("This queue is EMPTY!!, please import the data\n");
		return ERROR;
	}
	dNode*tem = (p->front)->next;
	*e = tem->data;//写入异常？？
	(p->front)->next = tem->next;
	if (tem->next == NULL) p->rear = p->front;//如果取得是最后一个元素的话——一定要考虑这一步啊！！
	free(tem);
	return OK;
}
/*销毁队*/
Status destroy(pNode* p) {
	while (p->rear == NULL) {
		p->rear = (p->front)->next;
		free(p->front);
		p->front = p->rear;
	}
	return OK;
}
/*按序读取队中的数据*/
void read(pNode* p) {
	dNode* tem;
	tem = p->front;
	while (tem->next != NULL) {//靠，居然把if当成了循环，我也是醉了！！
		printf("%d ", (tem->next)->data);
		tem = tem->next;
	}
}
/*将两个队穿插合并到第三个队*/
pNode *cross1(pNode* p1, pNode*p2) {
	pNode* p3 = init();
	dNode* tem3 = p3->front;
	while ((!(isEmpty(p1)) || (!(isEmpty(p2))))) {
		if (!(isEmpty(p1))) {
			tem3 = tem3->next;
			get(p1, &(tem3->data));
		}
		if (!(isEmpty(p2))) {
			tem3 = tem3->next;
			get(p2, &(tem3->data));
		}
	}
	return p3;
}
int main() {
	pNode* p1 = init();
	pNode* p2 = init();
	int i1 = 1, i2 = 0;
	for (int i = 1; i <= 10; i++) {
		add(p1, i1);
	}
	for (int i = 1; i <= 5; i++) {
		add(p2, i2);
	}
	pNode* p3 = cross1(p1, p2);
	read(p3);
	system("pause");
	return 0;
}