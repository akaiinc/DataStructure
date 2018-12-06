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
//邻接数组结构体
typedef struct  {
	int vexs[MAX_CONTAINER_SIZE];
	int weight[MAX_CONTAINER_SIZE][MAX_CONTAINER_SIZE];
}AdjacencyMatrix;
//邻接链表中的链表节点
typedef struct arcLink {
	int weight;
	graphNode* anotherNode;
	struct arcLink* next;
}arcNode;
//邻接链表中的图节点—处于数组当中
typedef struct {
	ElemType data;
	arcNode* arclink;
}graphNode;
AdjacencyMatrix* creAdjacencyMatrix() {//既然选择数组就必须用完，要不就用链表！！
	AdjacencyMatrix* structure;
	structure = (AdjacencyMatrix*)malloc(sizeof(AdjacencyMatrix));
	printf("Directed Graph or Not, Y/N? ");
	char judge;
	judge = getchar();
	getchar();
	printf("\n");
	for (int i = 0; i < MAX_CONTAINER_SIZE; i++) {//无向图
		printf("Please Input The Information of Node %d		", i + 1);
		scanf("%d", &structure->vexs[i]);
		getchar();
		structure->weight[i][i] = 0;
		for (int j = 0; j < i; j++) {
			if (judge == 'Y') {
				printf("The weight Node %d  —》 Node  %d is  ", j+1, i+1);
				scanf("%d", &structure->weight[j][i]);
				getchar();
				printf("The weight Node %d  —》 Node  %d is  ", i+1, j+1);
				scanf("%d", &structure->weight[i][j]);
				getchar();
			}
			else {
				printf("The weight between Node %d  and Node  %d is  ", j+1, i+1);
				scanf("%d", &structure->weight[i][j]);
				getchar();
				structure->weight[i][j] = structure->weight[j][i];
			}
		}
	}
	return structure;
}
graphNode* creAdjacencyChain() {
	graphNode nodeArray[MAX_CONTAINER_SIZE];
	for (int i = 0; i < MAX_CONTAINER_SIZE; i++) {//点和边只能分开建立表咯~
		printf("Please Input the Information of Node %d	", i);
		scanf("%d", &nodeArray[i].data);
		getchar();
		nodeArray[i].arclink = NULL;
	}
	for (int i = 0; i < MAX_CONTAINER_SIZE; i++) {//建立无向图的链表
		for (int j = 0; j < MAX_CONTAINER_SIZE&&j != i; j++) {//别人
			arcNode*p1 = nodeArray[i].arclink;
			printf("Creat ARC Between Node %d  and  Node %d, Y/N?  ", i, j);
			char judge2;
			judge2 = getchar();
			getchar();
			if (judge2 == 'Y') {//涉及到p与p->next的问题！！
				arcNode* p2 = (arcNode*)malloc(sizeof(arcNode));
				p2->anotherNode = &nodeArray[j];
				p2->anotherNode = NULL;
				printf("the Weight Between The Two Nodes   ");
				scanf("%d", &p2->weight);
				getchar();

			}
			else
			{
				continue;
			}
			
		}
	}
	return nodeArray;
}
int main() {
	AdjacencyMatrix* Graph = creAdjacencyMatrix();
	system("pause");
	return 0;
