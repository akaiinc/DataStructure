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
typedef struct dataPointStructure {
	struct dataStructure * down;
	struct dataPointStructure *next;
}sonChain;
typedef struct dataStructure {
	ElemType data;
	sonChain* son;//头节点
}node;
node* createTree() {
	node* knot = (node*)malloc(sizeof(node));
	printf("Please input the data: ");
	scanf("%d", &knot->data);
	getchar();	
	
	int i = 0;
	knot->son = NULL;//相当于头指针
	printf("Wanna creat Son %d  Y/N?  ",i+1);
	char judge1 = getchar();
	getchar();
	if (judge1 == 'Y') {//先创建出第一个节点才能赋值给头节点哦
		sonChain *p1, *p2;
		p1 = p2 = (sonChain*)malloc(sizeof(sonChain));
		p1->down = createTree();
		p1->next = NULL;
		while (judge1 == 'Y') {
			i++;
			if (i == 1) {
				knot->son = p1;
				printf("Wanna creat Son %d  Y/N?  ", i + 1);
				judge1 = getchar();
				getchar();
			}
			else {
				p2 = (sonChain*)malloc(sizeof(sonChain));
				p2->next = NULL;
				p2->down = createTree();
				p1->next = p2;
				p1 = p2;
				printf("Wanna creat Son %d  Y/N?  ", i + 1);
				judge1 = getchar();
				getchar();
			}
		}
	}
	return knot;
}
int main() {
	node* head = createTree();
	printf("Create Tree over!\n");
	system("pause");
	return 0;
}