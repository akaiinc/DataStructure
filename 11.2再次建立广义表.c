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
typedef struct nodeStructure {
	int type;//����1
	union {
		ElemType data;//����2
		struct nodeStructure *down;//or ���µ�ָ��
	};
	struct nodeStructure* after;//����ָ��
}node;
node* creatGenList() {
	node * knot= (node*)malloc(sizeof(node));
	printf("Creat down node(Y) or Input data(N) :");
	char judge1;
	judge1 = getchar();
	getchar();
	if (judge1 == 'Y') {
		knot->type = 1;
		knot->down = creatGenList();
	}
	else {
		knot->type = 0;
		printf("Now, please input your data: ");
		scanf("%d", &knot->data);
		getchar();
	}
	printf("Creat after node Y/N? :");
	char judge2;
	judge2 = getchar();
	getchar();
	if (judge2 == 'Y') {
		knot->after = creatGenList();
	}
	else {
		knot->after = NULL;
	}
	return knot;
}
int main() {
	node *head = creatGenList();
	printf("\nCreat general list over\n");
	system("pause");
	return 0;
}