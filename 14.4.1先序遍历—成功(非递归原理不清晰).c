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
	printf("Wanna Creat Left <——  Node, Y/N ? ");
	judge = getchar();
	getchar();
	if (judge == 'Y') {
		node->leftnode = creatBinaryTree();
	}
	printf("Wanna Creat Right ——> Node, Y/N ? ");
	judge = getchar();
	getchar();
	if (judge == 'Y') {//又把==写成=，F**K！
		node->rightnode = creatBinaryTree();
	}//不创建节点就不用管了
	return node;//不应该是选择关系
}

void recurRead(binaryNode* binaryHead) {//递归方式读取二叉树；PPT：传入的指针不为空则执行函数
	if (binaryHead != NULL) {
		printf("%d ", binaryHead->data);
		recurRead(binaryHead->leftnode);
		recurRead(binaryHead->rightnode);
	}
}

stackNode* pushStack(stackNode* stackHead, binaryNode* bN) {//bN为树节点的指针
	stackNode* p;
	p = (stackNode*)malloc(sizeof(stackNode));
	p->next = stackHead;
	p->pointOfBinaryNode = bN;
	stackHead = p;
	return stackHead;
}
stackNode* popStack(stackNode* stackHead, binaryNode* *bN) {//指向指针的指针，我马寅驰平生第一次用
	if (stackHead == NULL) {
		printf("the Stack Is Empty, Please Input Data!\n");
		exit(ERROR);
	}
	stackNode *p;
	p = stackHead;
	*bN = stackHead->pointOfBinaryNode;//???
	stackHead = stackHead->next;
	free(p);
	return stackHead;
}

void stackRead(binaryNode* binaryTreeHead) {//利用栈的非递归方式读取二叉树
	binaryNode *p1, *p2;
	stackNode *stackHead = NULL;
	p1 = binaryTreeHead;//用p1访问节点；
loop: {
	printf("%d ", p1->data);
	p2 = p1->rightnode;
	if (p2 != NULL) stackHead= pushStack(stackHead, p2);
	p1 = p1->leftnode;
	if (p1 != NULL) {
		goto loop;
	}
	else
	{
		if (stackHead==NULL) goto end;
		else {
			stackHead = popStack(stackHead, &p1);
			goto loop;
		}
	}
	}
  end:
	  printf("Use Stack Read Binary Tree Over!");
}

int main() {
	binaryNode* head;
	head = creatBinaryTree();
	printf("\nCreat Binary Tree Over……\n");
	stackRead(head);
	system("pause");
	return 0;
}