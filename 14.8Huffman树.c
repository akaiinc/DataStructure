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
typedef struct HuffmanNode {
	int weight;
	struct HuffmanNode* LNode;
	struct HuffmanNode* RNode;
}HuffNode;
/*���������ڵ�*/
typedef struct Link {
	union
	{
		HuffNode* HuffmanPoint;//��Ź������������ָ��
		int Length;
	};
	struct Link* next;
}ChainNode;
/*���ڵ�*/

/*���뽨��һ���������������һ��Ȩ�أ�Ȼ������ͷ�ڵ�ͳ�Ƹ��������԰��մ�С����*/

/*������*/
ChainNode* creatChain() {
	ChainNode *head, *p1, *p2;
	p1 =p2 = (ChainNode*)malloc(sizeof(ChainNode));
	head = p1;
	head->Length = 0;
	head->next = NULL;
	printf("You Ought To Enter No Less Than 2 Weights\n");
	while (1) {
		head->Length++;
		p1->next = p2;
		p1 = p2;
		p2 = (ChainNode*)malloc(sizeof(ChainNode));
		p2->next = NULL;
		HuffNode* p = (HuffNode*)malloc(sizeof(HuffNode));
		p2->HuffmanPoint = p;
		p->LNode = NULL;
		p->RNode = NULL;
		printf("Please Enter Weight %d  (End With -1 ): ", head->Length);
		scanf("%d",&p->weight);
		getchar();
		if (p->weight == -1) {
			head->Length--;
			free(p2);
			free(p);
			break;
		}
	}
	return head;
}
/*������*/
ChainNode* bubbleSortChain(ChainNode* head) {
	for (int i = 1; i < head->Length; i++) {
		ChainNode *p1, *p2;
		p1 = head->next;
		p2 = p1->next;
		for (int j = 1; j < head->Length; j++) {
			if ((p1->HuffmanPoint)->weight > (p2->HuffmanPoint)->weight) {
				int t = (p1->HuffmanPoint)->weight;
				(p1->HuffmanPoint)->weight = (p2->HuffmanPoint)->weight;
				(p2->HuffmanPoint)->weight = t;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	return head;
}

int main() {

	system("pause");
	return 0;
}