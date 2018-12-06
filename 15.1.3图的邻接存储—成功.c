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
typedef struct {
	int vexs[MAX_CONTAINER_SIZE];
	int weight[MAX_CONTAINER_SIZE][MAX_CONTAINER_SIZE];
}AdjacencyMatrix;

//邻接链表中数组元素指向的节点
typedef struct arcLink {
	int weight;
	struct GraphNode* anotherNode;//相互应用不要偷懒！！
	struct arcLink* next;
}arcNode;

//邻接链表数组中每一个节点
typedef struct GraphNode {
	ElemType data;
	arcNode* arclink;
}graphNode;

//邻接数组
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
				printf("The weight Node %d  —》 Node  %d is  ", j + 1, i + 1);
				scanf("%d", &structure->weight[j][i]);
				getchar();
				printf("The weight Node %d  —》 Node  %d is  ", i + 1, j + 1);
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

//邻接链表1
graphNode* creAdjacencyChain() {
	graphNode nodeArray[MAX_CONTAINER_SIZE];
	//输入点信息
	for (int i = 0; i < MAX_CONTAINER_SIZE; i++) {//点和边只能分开建立表咯~
		printf("Please Input the Data of Node %d	", i + 1);
		scanf("%d", &nodeArray[i].data);
		getchar();
		nodeArray[i].arclink = NULL;
	}
	//建立表
	int jud;
	printf("The AdjacencyChain you want to creat is Directed(1) or Undirected(2)?  ");
	scanf("%d", &jud);
	getchar();
	for (int i = 0; i < MAX_CONTAINER_SIZE; i++) {
		//此处建立有向表
		if (jud == 1) {
			for (int j = 0; j < MAX_CONTAINER_SIZE; j++) {
				if (j == i) continue;
				arcNode*p1 = NULL;
				printf("Creat ARC From Node %d  to  ---->   Node %d, Y/N?  ", i + 1, j +1);
				char judge2;
				judge2 = getchar();
				getchar();
				int k = 0;
				if (judge2 == 'Y') {//涉及到p与p->next的问题！！
					k++;
					arcNode* p2 = (arcNode*)malloc(sizeof(arcNode));
					p2->anotherNode = &nodeArray[j];
					p2->anotherNode = NULL;
					printf("the Weight  Node %d  to  ---->   Node %d  is   ", i + 1, j + 1);
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
		//此处建立无向表
		/*
		建立两点之间的关系，如1和5，在1中若与5建立关系
		（在1中建立指向5的指针，随后在5中建立指向1的指针；
		若1中不构建与5的关系，则5中也不构建与1的关系，先到先得），
		那么i不再考虑是否与比i小的数构建关系！！
		*/
		else {
			for (int j = i+1; j < MAX_CONTAINER_SIZE; j++) {
				arcNode*p1 = NULL;
				printf("Creat ARC Between Node %d  and  Node %d, Y/N?  ", i + 1, j + 1);
				char judge2;
				judge2 = getchar();
				getchar();
				int k = 0;
				if (judge2 == 'Y') {//涉及到p与p->next的问题！！
					k++;
					arcNode* p2 = (arcNode*)malloc(sizeof(arcNode));
					p2->anotherNode = &nodeArray[j];
					p2->anotherNode = NULL;
					printf("the Weight Between The Two Nodes   ");
					scanf("%d", &p2->weight);
					getchar();
					//衔接
					if (k == 1) {
						nodeArray[i].arclink = p2;
					}
					else {
						p1->next = p2;
					}
					p1 = p2;//仅仅构建完i的指向

					//构建j中的指向
					arcNode* p3 = (arcNode*)malloc(sizeof(arcNode));
					p3->anotherNode = &nodeArray[i];
					p3->next = NULL;
					p3->weight = p2->weight;
					if (nodeArray[j].arclink == NULL) {
						nodeArray[j].arclink = p3;
					}
					else {
						arcNode* p4 = nodeArray[j].arclink;
						while (p4->next!=NULL) {
							p4 = p4->next;
						}
						p4->next = p3;
					}
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
		printf("You can creat %d numbers.\n", MAX_CONTAINER_SIZE);
		graphNode* nodearray = creAdjacencyChain();
		printf("Creat Chain Over\n");
		system("pause");
		return 0;
	}