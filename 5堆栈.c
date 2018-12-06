#include<stdlib.h>
#include<stdio.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1//����ʵ�е�
#define OVERFLOW -2//���
#define MAX_STACK_SIZE 100//˳��ջ������
#define LEN sizeof(node)
typedef int Status;//�������״̬����
typedef int ElemType;//����Ҫ�洢�����ݵ�����
/*��ջ����*/
typedef struct {//����ڵ�
	ElemType  info;
	node *next;
}node,*pnode;
void InitL(pnode top) {//������ʼ���������ܼ�&
	top = NULL;
}
Status empty(pnode top) {//�Ƿ�Ϊ��
	if (top == NULL)
		return TURE;
}
Status pushL(pnode top, ElemType infor) {//Ӧ�ô���top��������һ���ڵ㣡����
	pnode p;
	if (!(p = (pnode)malloc(LEN)))
		return ERROR;
	p->info = infor;
	p->next = top;//��ʱtop����ײ�Ķ������ڵ��ָ���Ӧ��ָ����һ���ڵ�
	top = p;//top����
	return OK;//���һ��ѹջ
}
Status popL(pnode top, ElemType *e) {//�����ַ
	pnode p;
	if (top == NULL)
		return ERROR;
	*e = top->info;
	p = top;
	top = top->next;
	free(p);
	return OK;//���һ�γ�ջ
}
/*˳��ջ����*/
typedef struct sqstack {
	ElemType stack_array[MAX_STACK_SIZE];//��������
	int top;//ջ��
	int bottom;//ջ��
}SqStack;
//ջ�ĳ�ʼ������һ������
SqStack Init_Stack() {//initialize ��ʼ��
	SqStack S;//һ������ΪS��ջ
	S.bottom = S.top = -1;
	return S;
}
//ѹջ
Status push(SqStack S, ElemType e) {//ʹԪ��e�����ݣ���ջ(S)��Ϊ�µ�ջ��
	if (S.top == MAX_STACK_SIZE - 1)
		return ERROR;
	S.top++;
	S.stack_array[S.top] = e;//ʵ���Ͼ���������������Ӷ����������ѡ�
	return OK;
}
int Full(SqStack S) {//����ջ�Ƿ�����
	return S.top == MAX_STACK_SIZE;
}
Status pop(SqStack S, ElemType *e) {//��ջ����Ŀ��Ӧ����e��ȡ�������Ԫ��
	if (S.top == -1)
		return ERROR;
	*e = S.stack_array[S.top];
	S.top--;
	return OK;
}
int Empty(SqStack S) {//���ջ�Ƿ�Ϊ��
	return S.top == -1;
}
int main() {
	pnode top;//����������������ջ��interface��
	system("pause");
	return 0;
}