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
	printf("Wanna Creat Left ������  Node, Y/N ? ");
	judge = getchar();
	getchar();
	if (judge == 'Y') {
		node->leftnode = creatBinaryTree();
		printf("Wanna Creat Right ������ Node, Y/N ? ");
		judge = getchar();
		getchar();
		if (judge == 'Y') {//�ְ�==д��=��F**K��
			node->rightnode = creatBinaryTree();
		}//�������ڵ�Ͳ��ù���
	}
	return node;//��Ӧ����ѡ���ϵ
}

void recurRead(binaryNode* head) {//�ݹ鷽ʽ��ȡ��������PPT�������ָ�벻Ϊ����ִ�к���
	printf("%d ", head->data);
	if (head->leftnode != NULL) {
		recurRead(head->leftnode);//�����в���Ϊ��ָ�룡
		if (head->rightnode != NULL) {
			recurRead(head->rightnode);
		}
	}
}

Status pushStack(stackNode* head, binaryNode* bN) {//bNΪ���ڵ��ָ��
	stackNode* p;
	p = (stackNode*)malloc(sizeof(stackNode));
	p->next = head;
	p->pointOfBinaryNode = bN;
	head = p;
	return OK;
}

void stackRead(binaryNode* head) {//����ջ�ķǵݹ鷽ʽ��ȡ������

}

int main() {
	binaryNode* head;
	head = creatBinaryTree();
	printf("\nCreat Binary Tree Over����");
	recurRead(head);
	system("pause");
	return 0;
}