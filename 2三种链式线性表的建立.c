#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define lenInfo sizeof(struct node)
#define lenHead sizeof(struct HEAD)
typedef struct node {//��Ϣ�ڵ�
	char name[10];
	struct node *last;
	struct node *next;
}Info;
typedef struct HEAD {//ͷ�ڵ�
	int length;
	Info *next;
}Head;
int main() {
	Head *oneWay(void);
	Head *bothWay(void);
	Head *cycWay(void);
	Head *head;
	printf("HI! This is a Routine designed by AKai Trinity\n");
	printf("Final Compile Time %s ,%s\n\n", __TIME__, __DATE__);//Ԥ����һ��
	head = cycWay();
	system("pause");
	return 0;
}
Head *oneWay(void) {//������ڵ����ʽ���Ա�
	Head *head;
	Info *p1, *p2;
	char end[] = "end";//������־
	head = (Head*)malloc(lenHead);//�൱�����ڴ��е�ĳһλ�ô�����һ��������Head���ͽṹ��
	head->next = NULL;//�൱�ڲ���ͷ�ڵ�ʱ���headָ��
	head->length = 0;
	p1 = p2 = (Info*)malloc(lenInfo);
	p2->last = NULL;
	printf("Please input the information of member %d\n", (head->length) + 1);
	scanf("%s", &p2->name);
	if (strcmp(p2->name,end)!=0) {
		while (strcmp(p2->name, end) != 0) {//������û��дȫ������God����
			//��Ϊ��һ��ѭ����û���õ�����length������ѭ��������
			head->length++;
			if (head->length == 1) {
				head->next = p1;
			}
			else {
				p1->next = p2;//������pָ��p.next���������߼�������������p��nextָ��p
				p1 = p2;//�����������ڵ�һ����Ϣ�ڵ㴴���ڶ�����Ϣ�ڵ�ʱ�൱��һ���ظ����롣��
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
Head *bothWay(void) {//˫����ʽ���Ա�
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
				p2->last = p1;//�Ͷ���һ�д��룬�����ѣ�
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
Head *cycWay(void) {//˫��ѭ����ʽ���Ա�
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
	(head->next)->last = p1;//�ٳ�ѭ��
	return head;
}
Info* index(Head* head,char* string) {//�����˫������İ�ֵ����
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