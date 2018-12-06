typedef struct node0 {
	ElemType data;
	int deep;
	struct node0* pointArray[MAX_CONTAINER_SIZE];
}nod;
Status creatTree(nod* head) {
	head = (nod*)malloc(sizeof(nod));
	printf("Please Input the Element:");
	scanf("%d", &head->data);
	printf("Wanna next Y/N?\n");
	char judge1;
	scanf("%c", &judge1);
	if (judge1 == 'Y') {
		for (int i = 0;i < (MAX_CONTAINER_SIZE);i++) {

		}
	}
}



#include<stdlib.h>
#include<stdio.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_CONTAINER_SIZE 100
typedef int Status;
typedef int ElemType;//存储的数据的类型
typedef struct b {//父节点的指向问题
	struct a* son;//指向一个子节点
	struct b* sonNext;//指向父节点的下一个子节点的信息—平级关系
}sonPoint;
sonPoint* creSonPoint() {//指向多个son的链表
	sonPoint *head, *p1, *p2;
	int i = 0;
	head = NULL;
	p1 = p2 = (sonPoint*)malloc(sizeof(sonPoint));
	creatTree(p1->son);
	if((p1->son)->)
}
typedef struct a {//定义一个节点，a是一个名称而已。
	ElemType data;
	struct b* pointLine;
}node;
Status creatTree(node* head) {
	head = (node*)malloc(sizeof(node));
	printf("Please Input the data:\n");
	scanf("%d", &head->data);
	printf("Wanna creat son Y/N ?");
	char judge;
	judge = getchar();
	if (judge == 'Y') {

	}
	else {
		head->pointLine = NULL;
	}
	return OK;
}
int main() {

	system("pause");
	return 0;
}
