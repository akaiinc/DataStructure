#include<stdlib.h>
#include<stdio.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1//����ʵ�е�
#define OVERFLOW -2//���
#define MAX_CONTAINER_SIZE 100//����������
typedef int Status;//�������״̬����
typedef int ElemType;//�洢�����ݵ�����
typedef struct dataPointStructure {
	struct dataStructure * down;
	struct dataPointStructure *next;
}sonChain;
typedef struct dataStructure {
	ElemType data;
	sonChain* son;//ͷ�ڵ�
}node;
node* createTree() {
	node* knot = (node*)malloc(sizeof(node));
	printf("Please input the data: ");
	scanf("%d", &knot->data);
	getchar();	
	
	int i = 0;
	knot->son = NULL;//�൱��ͷָ��
	printf("Wanna creat Son %d  Y/N?  ",i+1);
	char judge1 = getchar();
	getchar();
	if (judge1 == 'Y') {//�ȴ�������һ���ڵ���ܸ�ֵ��ͷ�ڵ�Ŷ
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