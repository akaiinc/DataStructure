#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_CONTAINER_SIZE 3
typedef int Status;
typedef int ElemType;

//�ڽ�����ṹ��
typedef struct {
	int vexs[MAX_CONTAINER_SIZE];
	int weight[MAX_CONTAINER_SIZE][MAX_CONTAINER_SIZE];
}AdjacencyMatrix;

//�ڽ�����������Ԫ��ָ��Ľڵ�
typedef struct arcLink {
	int weight;
	struct GraphNode* anotherNode;//�໥Ӧ�ò�Ҫ͵������
	struct arcLink* next;
}arcNode;

//�ڽ�����������ÿһ���ڵ�
typedef struct GraphNode {
	ElemType data;
	arcNode* arclink;
}graphNode;

//�ڽ�����
AdjacencyMatrix* creAdjacencyMatrix() {//��Ȼѡ������ͱ������꣬Ҫ������������
	AdjacencyMatrix* structure;
	structure = (AdjacencyMatrix*)malloc(sizeof(AdjacencyMatrix));
	printf("Directed Graph or Not, Y/N? ");
	char judge;
	judge = getchar();
	getchar();
	printf("\n");
	for (int i = 0; i < MAX_CONTAINER_SIZE; i++) {//����ͼ
		printf("Please Input The Information of Node %d		", i + 1);
		scanf("%d", &structure->vexs[i]);
		getchar();
		structure->weight[i][i] = 0;
		for (int j = 0; j < i; j++) {
			if (judge == 'Y') {
				printf("The weight Node %d  ���� Node  %d is  ", j + 1, i + 1);
				scanf("%d", &structure->weight[j][i]);
				getchar();
				printf("The weight Node %d  ���� Node  %d is  ", i + 1, j + 1);
				scanf("%d", &structure->weight[i][j]);
				getchar();
			}
			else {
				printf("The weight between Node %d  and Node  %d is  ", j + 1, i + 1);
				scanf("%d", &structure->weight[i][j]);
				getchar();
				structure->weight[i][j] = structure->weight[j][i];
			}
		}
	}
	return structure;
}

//�ڽ�����1
graphNode* creAdjacencyChain() {
	graphNode nodeArray[MAX_CONTAINER_SIZE];
	//�������Ϣ
	for (int i = 0; i < MAX_CONTAINER_SIZE; i++) {//��ͱ�ֻ�ֿܷ�������~
		printf("Please Input the Information of Node %d	", i);
		scanf("%d", &nodeArray[i].data);
		getchar();
		nodeArray[i].arclink = NULL;
	}
	//������
	for (int i = 0; i < MAX_CONTAINER_SIZE; i++) {
		//�˴����������
		if (i == 0) {
			for (int j = 0; j < MAX_CONTAINER_SIZE; j++) {
				arcNode*p1 = NULL;
				printf("Creat ARC From Node %d  to (---->)  Node %d, Y/N?  ", i, j);
				char judge2;
				judge2 = getchar();
				getchar();
				int k = 0;
				if (judge2 == 'Y') {//�漰��p��p->next�����⣡��
					k++;
					arcNode* p2 = (arcNode*)malloc(sizeof(arcNode));
					p2->anotherNode = &nodeArray[j];
					p2->anotherNode = NULL;
					printf("the Weight Between The Two Nodes   ");
					scanf("%d", &p2->weight);
					getchar();
					if (k == 1) {
						nodeArray[i].arclink = p2;
					}
					else {
						p1->next = p2;
					}
					p1 = p2;
				}
				else
				{
					continue;
				}
			}
		}
		//�˴����������
		else {
			for (int j = 0; j < MAX_CONTAINER_SIZE; j++) {
				arcNode*p1 = NULL;
				printf("Creat ARC Between Node %d  and  Node %d, Y/N?  ", i, j);
				char judge2;
				judge2 = getchar();
				getchar();
				int k = 0;
				if (judge2 == 'Y') {//�漰��p��p->next�����⣡��
					k++;
					arcNode* p2 = (arcNode*)malloc(sizeof(arcNode));
					p2->anotherNode = &nodeArray[j];
					p2->anotherNode = NULL;
					printf("the Weight Between The Two Nodes   ");
					scanf("%d", &p2->weight);
					getchar();
					//�ν�
					if (k == 1) {
						nodeArray[i].arclink = p2;
					}
					else {
						p1->next = p2;
					}
					p1 = p2;
				}
				else
				{
					continue;
				}
			}
		}
	}
		return nodeArray;
	}
	int main() {
		graphNode* nodearray = creAdjacencyChain();
		system("pause");
		return 0;
	}