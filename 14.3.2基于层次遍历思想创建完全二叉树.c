#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int ElemType;

//树节点
typedef struct tNode {
	ElemType data;
	struct tNode* leftson;
	struct tNode* rightson;
}treeNode;

//队列节点
typedef struct qNode {
	//偷懒行为！
	union 
	{
		ElemType data;
		treeNode** treepoint;		//存放指向树节点指针的地址
	};
	struct qNode *next;
}queueNode;

//队列的头节点
typedef struct hNode {
	queueNode *front;
	queueNode *rear;
}headNode;

//队列节点的初始化
headNode* initQ() {
	headNode* head = (headNode*)malloc(sizeof(headNode));
	queueNode* blankNode = (queueNode*)malloc(sizeof(queueNode));
	head->front = head->rear = blankNode;
	blankNode->data = 0;
	blankNode->next = NULL;
	return head;
}

//数据队列的进队
headNode* addData(headNode* head, ElemType e) {
	queueNode* p = (queueNode*)malloc(sizeof(queueNode));
	p->next = NULL;
	p->data = e;
	(head->rear)->next = p;
	head->rear = p;
	return head;
}

//指针队列的进队,参数指针指向已开辟的节点
headNode* addPoint(headNode* head, treeNode** point) {		//不应该存放指针，而是存放树节点左右指针的地址，传入是&treenode* 型变量即可
	queueNode* p = (queueNode*)malloc(sizeof(queueNode));
	p->treepoint = point;
	p->next = NULL;
	(head->rear)->next = p;
	head->rear = p;
	return head;
}

//判断队列是否为空
int isEmpty(headNode* head) {
	if (head->front == head->rear) {
		return 1;
	}
	else
	{
		return 0;
	}
}

//数据出队列
headNode* getData(headNode* head, ElemType* e) {
	if (isEmpty(head)) exit(0);
	queueNode *p;
	p = (head->front)->next;
	*e = p->data;
	(head->front)->next = p->next;
	if (p->next == NULL)
		head->rear = head->front;
	free(p);
	return head;
}

//指针地址出队列
headNode* getPoint(headNode*head, treeNode***addrofpoin) {//外面的地址需要把它的地址传进来，以便修改外部的地址
	if (isEmpty(head)) exit(0);
	queueNode *p;
	p = (head->front)->next;
	*addrofpoin = p->treepoint;		//*addrofpoin是外面的地址
	(head->front)->next = p->next;
	if (p->next == NULL)
		head->rear = head->front;
	free(p);
	return head;
}

//销毁存储数据的队列——直接 .clear()多好！！
int destroyD_Q(headNode* head) {
	queueNode* p1, *p2;
	p1 = head->front;
	p2 = p1->next;
	while (p2!=NULL)
	{
		free(p1);
		p1 = p2;
		p2 = p1->next;
	}
	free(p1);
	free(head);
	return 1;
}

//销毁指针队列及其指向
int destrouP_Q(headNode*head) {
	queueNode* p1, *p2;
	p1 = head->front;
	p2 = p1->next;
	while (p2 != NULL)
	{
		if (p1->treepoint) {
			free(*(p1->treepoint));
			*(p1->treepoint) = NULL;
		}
		free(p1);
		p1 = p2;
		p2 = p1->next;
	}
	if (p1->treepoint) {
		free(*(p1->treepoint));
		*(p1->treepoint) = NULL;
	}
	free(p1);
	free(head);
	return 1;
}

//创建树
treeNode* creTree() {
	//初始化两条队列
	headNode* dataQ = initQ();
	headNode* pointQ = initQ();
	printf("请向完全二叉树中输入数据,Enter换行, -1结束\n");
	ElemType i = 0;
	scanf("%d", &i);
	getchar();
	while (i!=-1)
	{
		dataQ = addData(dataQ, i);
		scanf("%d", &i);
		getchar();
	}

	//接下来？？
	treeNode* root = NULL;

	//数据队列不为空
	while (isEmpty(dataQ)==0)
	{
		if (root == NULL) {
			root = (treeNode*)malloc(sizeof(treeNode));
			dataQ = getData(dataQ, &(root->data));
			root->leftson = (treeNode*)malloc(sizeof(treeNode));
			//没有想到处理开辟出来的空间
			(root->leftson)->data = 0;
			(root->leftson)->leftson = (root->leftson)->rightson =NULL;
			pointQ = addPoint(pointQ, &(root->leftson));		//根据自己定义的函数，传入指针的地址
			root->rightson = (treeNode*)malloc(sizeof(treeNode));
			(root->rightson)->data = 0;
			(root->rightson)->leftson = (root->rightson)->rightson = NULL;
			pointQ = addPoint(pointQ, &(root->rightson));
		}
		else
		{
			treeNode**p;
			pointQ = getPoint(pointQ, &p);
			dataQ = getData(dataQ, &((*p)->data));
			(*p)->leftson= (treeNode*)malloc(sizeof(treeNode));
			((*p)->leftson)->data = 0;
			((*p)->leftson)->leftson = ((*p)->leftson)->rightson = NULL;
			pointQ = addPoint(pointQ, &((*p)->leftson));
			(*p)->rightson = (treeNode*)malloc(sizeof(treeNode));
			((*p)->rightson)->data = 0;
			((*p)->rightson)->leftson = ((*p)->rightson)->rightson = NULL;
			pointQ = addPoint(pointQ, &((*p)->rightson));
		}
	}
	//free掉队列中多余的指针以及指针指向的区域
	destrouP_Q(pointQ);
	return root;
}

int main() {
	int preOder(treeNode* root);
	treeNode* root = creTree();
	preOder(root);
	system("pause");
	return;
}

//递归先序遍历
int preOder(treeNode* root) {
	printf("%d  ", root->data);
	if (root->leftson!=NULL)
	{
		preOder(root->leftson);
	}
	if (root->rightson!=NULL)
	{
		preOder(root->rightson);
	}
	return 1;
}
