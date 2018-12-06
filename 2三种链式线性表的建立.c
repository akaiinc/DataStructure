#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define lenInfo sizeof(struct node)
#define lenHead sizeof(struct HEAD)
typedef struct node {//信息节点
	char name[10];
	struct node *last;
	struct node *next;
}Info;
typedef struct HEAD {//头节点
	int length;
	Info *next;
}Head;
int main() {
	Head *oneWay(void);
	Head *bothWay(void);
	Head *cycWay(void);
	Head *head;
	printf("HI! This is a Routine designed by AKai Trinity\n");
	printf("Final Compile Time %s ,%s\n\n", __TIME__, __DATE__);//预处理一哈
	head = cycWay();
	system("pause");
	return 0;
}
Head *oneWay(void) {//单向带节点的链式线性表
	Head *head;
	Info *p1, *p2;
	char end[] = "end";//结束标志
	head = (Head*)malloc(lenHead);//相当于在内存中的某一位置创建了一个无名的Head类型结构体
	head->next = NULL;//相当于不带头节点时候的head指针
	head->length = 0;
	p1 = p2 = (Info*)malloc(lenInfo);
	p2->last = NULL;
	printf("Please input the information of member %d\n", (head->length) + 1);
	scanf("%s", &p2->name);
	if (strcmp(p2->name,end)!=0) {
		while (strcmp(p2->name, end) != 0) {//函数都没有写全！！！God！！
			//因为有一次循环是没有用的所以length不等于循环次数！
			head->length++;
			if (head->length == 1) {
				head->next = p1;
			}
			else {
				p1->next = p2;//不能让p指向p.next（不符合逻辑！！），而是p的next指向p
				p1 = p2;//这两步对于在第一个信息节点创建第二个信息节点时相当于一段重复代码。。
				p2 = (Info*)malloc(lenInfo);
				p2->last = NULL;
				printf("Please input the information of member %d\n", (head->length));
				scanf("%s", &p2->name);
			}
		}
		free(p2);
		head->length--;
	}
	p1->next = NULL;
	printf("The length of one_way (->) chain is %d\n", head->length);
	return head;
}
Head *bothWay(void) {//双向链式线性表
	Head *head;
	Info *p1, *p2;
	head = (Head*)malloc(lenHead);
	head->length = 0;
	head->next = NULL;
	char end[] = "end";
	p1 = p2 = (Info*)malloc(lenInfo);
	printf("Please input the information of member %d\n", (head->length) + 1);
	scanf("%s", p2->name);
	if (strcmp(p2->name, end) != 0) {
		while (strcmp(p2->name, end) != 0) {
			head->length++;
			if (head->length == 1) {
				head->next = p1;
			}
			else {
				p1->next = p2;
				p2->last = p1;//就多了一行代码，，而已！
				p1 = p2;
				p2 = (Info*)malloc(lenInfo);
				printf("Please input the information of member %d\n", (head->length));
				scanf("%s", p2->name);
			}
		}
		free(p2);
		head->length--;
	}
	p1->next = NULL;
	printf("The length of bothway (<->) chain is %d\n", head->length);
	return head;
}
Head *cycWay(void) {//双向循环链式线性表
	Head *head;
	Info *p1, *p2;
	head = (Head*)malloc(lenHead);
	head->length = 0;
	head->next = NULL;
	char end[] = "end";
	p1 = p2 = (Info*)malloc(lenInfo);
	printf("Please input the information of member %d\n", (head->length) + 1);
	scanf("%s", p1->name);
	if (strcmp(p1->name, end) != 0) {
		while (strcmp(p1->name, end) != 0) {
			head->length++;
			if (head->length == 1) {
				head->next = p1;
			}
			else {
				p1->next = p2;
				p2->last = p1;
				p1 = p2;
				p2 = (Info*)malloc(lenInfo);
				printf("Please input the information of member %d\n", (head->length));
				scanf("%s", p1->name);
			}
		}
		free(p2);
		head->length--;

	}
	printf("The length of cycway (@) cycle chain is %d\n", head->length);
	p1->next = head->next;
	(head->next)->last = p1;//促成循环
	return head;
}
Info* index(Head* head,char* string) {//针对于双向链表的按值查找
	Info *p;
	p = head->next;
	do {
		if (p->name == (*string))
			return p;
		else
			p = p->next;
	} while (p != head->next);
	return NULL;
}