#include<stdlib.h>
#include<stdio.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1//����ʵ�е�
#define OVERFLOW -2//���
#define MAX_STACK_SIZE 100//˳��ջ������
typedef int Status;//�������״̬����
typedef int ElemType;//ջ�洢�����ݵ�����
//ջ�����Ͷ��塪������һ��ջ
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

	system("pause");
	return 0;
}