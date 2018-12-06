#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1//不可实行的
#define OVERFLOW -2//溢出
#define MAX_CONTAINER_SIZE 100//容器的容量
typedef int Status;//函数结果状态代码
typedef int ElemType;//存储的数据的类型

typedef struct bn {//二叉树节点
	struct bn *leftnode;
	struct bn *rightnode;
	ElemType data;
}binaryNode;

typedef struct sn {//链栈节点
	binaryNode *pointOfBinaryNode;
	struct sn *next;
}stackNode;

binaryNode *creatBinaryTree(void) {
	binaryNode *node;
	node = (binaryNode*)malloc(sizeof(binaryNode));
	node->leftnode = NULL;
	node->rightnode = NULL;
	printf("Please input your DATA ");
	scanf("%d", &node->data);
	getchar();
	char judge;
	printf("Wanna Creat Left 《——  Node, Y/N ? ");
	judge = getchar();
	getchar();
	if (judge == 'Y') {
		node->leftnode = creatBinaryTree();
		printf("Wanna Creat Right ——》 Node, Y/N ? ");
		judge = getchar();
		getchar();
		if (judge == 'Y') {//又把==写成=，F**K！
			node->rightnode = creatBinaryTree();
		}//不创建节点就不用管了
	}
	return node;//不应该是选择关系
}

void recurRead(binaryNode* head) {//递归方式读取二叉树；PPT：传入的指针不为空则执行函数
	printf("%d ", head->data);
	if (head->leftnode != NULL) {
		recurRead(head->leftnode);//括号中不能为空指针！
		if (head->rightnode != NULL) {
			recurRead(head->rightnode);
		}
	}
}

Status pushStack(stackNode* head, binaryNode* bN) {//bN为数节点的指针
	stackNode* p;
	p = (stackNode*)malloc(sizeof(stackNode));
	p->next = head;
	p->pointOfBinaryNode = bN;
	head = p;
	return OK;
}

void stackRead(binaryNode* head) {//利用栈的非递归方式读取二叉树

}

int main() {
	binaryNode* head;
	head = creatBinaryTree();
	printf("\nCreat Binary Tree Over……");
	recurRead(head);
	system("pause");
	return 0;
}