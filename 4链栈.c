#include<stdlib.h>
#include<stdio.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1//不可实行的
#define OVERFLOW -2//溢出
#define MAX_STACK_SIZE 100//顺序栈的容量
#define LEN sizeof(node)
typedef int Status;//函数结果状态代码
typedef int ElemType;//定义要存储的数据的类型
typedef struct {//定义节点
	ElemType  info;
	node *next;
}node,*pnode;
void InitL(pnode top) {//——初始化，，不能加&
	top = NULL;
}
Status empty(pnode top) {//是否为空
	if (top == NULL)
		return TURE;
}
Status pushL(pnode top, ElemType infor) {//应该传入top，而不是一个节点！！！
	pnode p;
	if (!(p = (pnode)malloc(LEN)))
		return ERROR;
	p->info = infor;
	p->next = top;//此时top是最底层的东西，节点的指针就应该指向下一个节点
	top = p;//top上移
	return OK;//完成一次压栈
}
Status popL(pnode top, ElemType *e) {//传入地址
	pnode p;
	if (top == NULL)
		return ERROR;
	*e = top->info;
	p = top;
	top = top->next;
	free(p);
	return OK;//完成一次出栈
}
int main() {
	pnode top;//在主函数中设置链栈的interface！

	system("pause");
	return 0;
}



栈的修改一
typedef struct a{//定义节点
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
