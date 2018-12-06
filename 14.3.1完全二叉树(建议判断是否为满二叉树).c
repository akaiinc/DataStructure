#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_CONTAINER_SIZE 100
typedef int Status;
typedef int ElemType;
typedef struct tree {
	struct tree *leftTree;
	ElemType data;
	int number;
	struct tree *rightTree;
}binaryTreeNode;
binaryTreeNode* indexNumber(binaryTreeNode *head, int num) {
	binaryTreeNode *p1, *p2, *p;
	p = head;
	p1 = p->leftTree;
	p2 = p->rightTree;
	if (p->number == num) {
		return p;
	}
	if (p = indexNumber(p1, num)) return p;//�˴�ò��������Ŷ
	else
	{
		p = indexNumber(p2, num);
		return p;
	}
}
/*����numֵ��Ӧ��ָ��ָ��*/
binaryTreeNode* creatBinaryTree() {
	int line = 1;
	binaryTreeNode *head, *p2, *fatherP;
	head = p2 = fatherP = NULL;
	int i = 1;//�ڵ���Ŀ
	int fathernumber = 0;//���ڵ��number
	char judge = 'Y';
	head = (binaryTreeNode*)malloc(sizeof(binaryTreeNode));
	head->leftTree = NULL;
	head->rightTree = NULL;
	head->number = i;
	printf("Please input Data %d  ", i);
	scanf("%d", &head->data);
	getchar();
	printf("Do you want to input the next DATA, Y/N? ");
	judge = getchar();
	getchar();
	while (judge == 'Y') {
		i++;
		p2 = (binaryTreeNode*)malloc(sizeof(binaryTreeNode));
		p2->number = i;
		printf("Please input Data %d  ", i);
		scanf("%d", &p2->data);
		getchar();
		p2->leftTree = NULL;
		p2->rightTree = NULL;
		/*�ڵ�������*/
		fathernumber = i / 2;
		/*�жϸ��ڵ��Ƕ��ٺţ�*/
		fatherP = indexNumber(head, fathernumber);
		if (i % 2 == 0) {
			fatherP->leftTree = p2;
		}
		else {
			fatherP->rightTree = p2;
		}
		/*�ҵ�numberΪfathernumber�Ľڵ�,�����½ڵ����ȥ��*/
		printf("Do you want to input the next DATA, Y/N? ");
		judge = getchar();
		getchar();
	}
	return head;
}
int main() {
	binaryTreeNode* head;
	head = creatBinaryTree();
	printf("Creat Binary-Tree Over\n");
	system("pause");
	return 0;
}