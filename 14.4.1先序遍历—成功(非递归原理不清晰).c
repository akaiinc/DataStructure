#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1//����ʵ�е�
#define OVERFLOW -2//���
#define MAX_CONTAINER_SIZE 100//����������
typedef int Status;//�������״̬����
typedef int ElemType;//�洢�����ݵ�����

typedef struct bn {//�������ڵ�
	struct bn *leftnode;
	struct bn *rightnode;
	ElemType data;
}binaryNode;

typedef struct sn {//��ջ�ڵ�
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
	printf("Wanna Creat Left <����  Node, Y/N ? ");
	judge = getchar();
	getchar();
	if (judge == 'Y') {
		node->leftnode = creatBinaryTree();
	}
	printf("Wanna Creat Right ����> Node, Y/N ? ");
	judge = getchar();
	getchar();
	if (judge == 'Y') {//�ְ�==д��=��F**K��
		node->rightnode = creatBinaryTree();
	}//�������ڵ�Ͳ��ù���
	return node;//��Ӧ����ѡ���ϵ
}

void recurRead(binaryNode* binaryHead) {//�ݹ鷽ʽ��ȡ��������PPT�������ָ�벻Ϊ����ִ�к���
	if (binaryHead != NULL) {
		printf("%d ", binaryHead->data);
		recurRead(binaryHead->leftnode);
		recurRead(binaryHead->rightnode);
	}
}

stackNode* pushStack(stackNode* stackHead, binaryNode* bN) {//bNΪ���ڵ��ָ��
	stackNode* p;
	p = (stackNode*)malloc(sizeof(stackNode));
	p->next = stackHead;
	p->pointOfBinaryNode = bN;
	stackHead = p;
	return stackHead;
}
stackNode* popStack(stackNode* stackHead, binaryNode* *bN) {//ָ��ָ���ָ�룬��������ƽ����һ����
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

void stackRead(binaryNode* binaryTreeHead) {//����ջ�ķǵݹ鷽ʽ��ȡ������
	binaryNode *p1, *p2;
	stackNode *stackHead = NULL;
	p1 = binaryTreeHead;//��p1���ʽڵ㣻
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
	printf("\nCreat Binary Tree Over����\n");
	stackRead(head);
	system("pause");
	return 0;
}