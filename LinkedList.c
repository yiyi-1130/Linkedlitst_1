#include"LinkedList.h"
//��ʼ��һ��������ֻʹ�ò���ֵ��ͷ�ڵ�
Status InitList(LinkedList* L) {
	//��ʼ��ָ��
	*L = (LinkedList*)malloc(sizeof(LNode));
	//ʹͷ���ָ���
	(*L)->next = NULL;
	return SUCCESS;
}
//�˵�������ʵ�����õ��˻�����
void menu()

{

	printf("************�������������***********\n");/*ѡ���ܲ˵�*/

	printf("*************************************\n");

	printf("1.����ֵ\n");

	printf("2.������\n");

	printf("3.ɾ�����\n");

	printf("4.�жϻ���\n");

	printf("5.��ż����\n");

	printf("6.�м�Ԫ�ص�ֵ\n");

	printf("7.������\n");

	printf("8.��ѯ��ֵ�Ƿ�������\n");

	printf("0.�˳�ϵͳ\n");

	printf("**************************************\n");

}
//����ֵ
void CreateList_Head(LinkedList L)
{
	LinkedList s; int x;
	printf("ͷ����������������ֵ��9999������\n");
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;                          //������
		scanf_s("%d", &x);
	}
}
//��������ֵ
void PrintList(LinkedList L)
{
	LinkedList p;
	p = L->next;
	printf("����Ԫ�����£�\n");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//���룬��q�嵽p�ĺ���
Status InsertList(LNode* p, LNode* q) {
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}
//����һ�����뺯��������ѡ������λ�ú���ֵ
void Insert(LinkedList L)
{
	int x;
	int i = 0;
	printf("��������������\n");
	scanf_s("%d", &x);
	LNode* q;
	q = (LNode*)malloc(sizeof(LNode));
	q->data = x;
	LNode* p;
	p = (LNode*)malloc(sizeof(LNode));
	p = L;
	int y;
	printf("������������λ��\n");
	scanf_s("%d", &y);
	while (p != NULL && i < y - 1)
	{
		i++;
		p = p->next;//whileʹ���ƶ���Ҫ����Ľ��֮ǰ 
	}
	InsertList(p, q);
	PrintList(L);//�������
}
//ɾ��p��㣬����ֵ����e
Status DeleteList(LNode* p, ElemType* e) {

	LNode* t = p->next;
	p->next = p->next->next;
	e = t->data;
	free(t);
	return SUCCESS;
}
//����һ��ɾ������������ѡ��ɾ����λ��
void Delete(LinkedList L)
{
	int i = 0;
	LNode* p;
	p = (LNode*)malloc(sizeof(LNode));
	p = L;
	int y;
	printf("��������ɾ����λ��\n");
	scanf_s("%d", &y);
	while (p != NULL && i < y - 1)
	{
		i++;
		p = p->next;//whileʹ���ƶ���Ҫɾ���Ľ��֮ǰ 
	}
	int e;
	DeleteList(p, &e);
	PrintList(L);//�������
}
//�ж������Ƿ�ɻ�
Status IsLoopList(LinkedList L) {
	LNode* slow = L;
	LNode* fast = L;
	while (fast != NULL && fast->next != NULL)
	{

		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			printf("This is a loop list.");
			return SUCCESS;
		}
	}
	printf("This isn't a loop list.");
	return ERROR;
}//��ż�Ի�
LNode* ReverseEvenList(LinkedList* L) {
	LNode* p1 = (*L)->next;
	LNode* p2 = (*L)->next->next;
	while (p2->next != NULL && p2 != NULL)
	{
		int c = p1->data;
		p1->data = p2->data;
		p2->data = c;
		p1 = p1->next->next;
		p2 = p2->next->next;

	}
	return *L;
}
//���ú���
Status ReverseList(LinkedList* L) {
	LNode* p = (*L)->next;
	LNode* t = NULL;
	LNode* q = (*L)->next->next;
	while (q->next != NULL)
	{
		t = q->next;
		q->next = p;
		p = q;
		q = t;
	}
	(*L)->next->next = NULL;
	(*L)->next = q;
	PrintList(*L);
	return SUCCESS;
}
//�������ĵ�ֵ
LNode* FindMidNode(LinkedList* L) {
	LNode* slow = *L;
	LNode* fast = *L;
	while (fast != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	printf(slow->data);
	return slow;
}

Status SearchList(LinkedList L, ElemType e) {
	LinkedList p = L->next;
	while (p->next != NULL) {
		if (p->data = e)
		{
			printf("This number is in a linked list.");
			return SUCCESS;
		}
		p = p->next;
	}
	printf("This number isn't in a linked list.");
	return ERROR;
}
void Search(LinkedList L)
{
	int b;
	printf("�����������ѯ��ֵ��\n");
	scanf_s("%d", &b);
	SearchList(L, b);
}