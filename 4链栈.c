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
int main() {
	pnode top;//����������������ջ��interface��

	system("pause");
	return 0;
}



ջ���޸�һ
typedef struct a{//����ڵ�
	ElemType  info;
	struct a*next;
}node;
node* push(node* head, ElemType e) {
	node*p = (node*)malloc(sizeof(node));
	p->info = e;
	p->next = head;
	head = p;
	return head;
}
node* pop(node* head, ElemType* e) {
	if (head == NULL) exit(ERROR);
	node *p = head;
	*e = head->info;
	head = head->next;
	free(p);
	return head;
}
