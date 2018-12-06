#include<stdlib.h>
#include<stdio.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1//不可实行的
#define OVERFLOW -2//溢出
#define MAX_STACK_SIZE 100//顺序栈的容量
typedef int Status;//函数结果状态代码
typedef int ElemType;//栈存储的数据的类型
//栈的类型定义——定义一个栈
typedef struct sqstack {
	ElemType stack_array[MAX_STACK_SIZE];//定义容器
	int top;//栈顶
	int bottom;//栈底
}SqStack;
//栈的初始化——一个函数
SqStack Init_Stack() {//initialize 初始化
	SqStack S;//一个名字为S的栈
	S.bottom = S.top = -1;
	return S;
}
//压栈
Status push(SqStack S, ElemType e) {//使元素e（数据）进栈(S)成为新的栈顶
	if (S.top == MAX_STACK_SIZE - 1)
		return ERROR;
	S.top++;
	S.stack_array[S.top] = e;//实质上就是向数组里面添加东西，，而已。
	return OK;
}
int Full(SqStack S) {//测试栈是否已满
	return S.top == MAX_STACK_SIZE;
}
Status pop(SqStack S, ElemType *e) {//出栈，其目的应该是e获取最外面的元素
	if (S.top == -1)
		return ERROR;
	*e = S.stack_array[S.top];
	S.top--;
	return OK;
}
int Empty(SqStack S) {//检测栈是否为空
	return S.top == -1;
}

int main() {

	system("pause");
	return 0;
}