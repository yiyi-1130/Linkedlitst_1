#include "DuLinkedList.h"
Status InitList_DuL(DuLinkedList* L) {
	*L = (DuLinkedList*)malloc(sizeof(DuLNode));
	//ʹͷ���ָ���
	(*L)->next = (*L)->prior = NULL;
	return SUCCESS;
}
//˫������Ĳ���
void InsertDuLinkList(DuLinkedList* L, ElemType data)
{
	if (*L == NULL) {
		printf("The list is empty.\n");		//  ͷ���Ϊ�գ����޷�����
		return;
	}
	DuLNode* tmpHead = (*L);		//  ����һ����ʱ��ͷ���ָ��
	if (tmpHead ->next== NULL) {
		DuLNode* addition = (DuLNode*)malloc(sizeof(DuLNode));
			addition->data = data;		//  ������ֵ
			addition->next = tmpHead->next;//  ����ָ������
			addition->prior = tmpHead;//  ���������prior ָ��ͷ���
			tmpHead->next = addition;
	}
	else{
		DuLNode* addition = (DuLNode*)malloc(sizeof(DuLNode));
		addition->data = data;		//  ������ֵ
		tmpHead->next->prior = addition;		//  ͷ������һ������priorָ��
		addition->prior = *L;		//  ����Ľ���priorָ��ָ��ͷ���
		addition->next = tmpHead->next;		//  �������next ָ��ָ��ԭ��ͷָ�����һ���	
	}
}
//��ֵ����
void CreatedDuLinkList(DuLinkedList* L)
{
	int  n;
	printf("����˫��������ֵ��9999������\n");
	scanf_s("%d", &n);
	while (n != 9999) {
		InsertDuLinkList(&L, n);
		scanf_s("%d", &n);
	}
	PrintList(L);
}
void menu()

{

	printf("************�������������***********\n");/*ѡ���ܲ˵�*/

	printf("*************************************\n");

	printf("1.����ֵ\n");

	printf("2.������\n");

	printf("3.ɾ�����\n");

	printf("4.����б�\n");

	printf("0.�˳�ϵͳ\n");

	printf("**************************************\n");

}
//�������
void PrintList(DuLinkedList L)
{
	DuLNode*p;
	p = L->next;
	printf("����Ԫ�����£�\n");
	if (p == NULL) {
		printf("The list is empty.\n");
	}
	while (p->next!= NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
	//����Ҫ�������ͷ���
	if (p->prior == NULL) {
		q->next = p;
		q->prior = NULL;
	}

	else
	{
		p->prior->next = q;
		q->prior = p->prior;
		q->next = p;
		p->prior = q;
	}
	return SUCCESS;
}
//���һ��Insert1����ʵ�ֶ��㶨ֵ����
void Insert1(DuLinkedList L)
{
	int x;
	int i = 0;
	printf("��������������\n");
	scanf_s("%d", &x);
	DuLNode* q;
	q = (DuLNode*)malloc(sizeof(DuLNode));
	q->data = x;
	DuLNode* p;
	p = (DuLNode*)malloc(sizeof(DuLNode));
	p = L;
	int y;
	printf("������������λ��\n");
	scanf_s("%d", &y);
	while (p != NULL && i < y)
	{
		i++;
		p = p->next;//whileʹ���ƶ���Ҫ����Ľ��֮ǰ 
	}
	InsertBeforeList_DuL(p, q);
	PrintList(L);//�������
}
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
	//����Ҫ�������β�ڵ�
	if (p->next == NULL) {
		p->next = q;
		q->next = NULL;
		q->prior = p;
	}
	else
	{
		p->next->prior = q;
		q->next = p->next;
		q->prior = p;
		p->next = q;
		return SUCCESS;
	}
}
void Insert2(DuLinkedList L)
{
	int x;
	int i = 0;
	printf("��������������\n");
	scanf_s("%d", &x);
	DuLNode* q;
	q = (DuLNode*)malloc(sizeof(DuLNode));
	q->data = x;
	DuLNode* p;
	p = (DuLNode*)malloc(sizeof(DuLNode));
	p = L;
	int y;
	printf("������������λ��\n");
	scanf_s("%d", &y);
	while (p != NULL && i < y - 1)
	{
		i++;
		p = p->next;//whileʹ���ƶ���Ҫ����Ľ��֮ǰ 
	}
	InsertAfterList_DuL(p, q);
	PrintList(L);//�������
}
Status DeleteList_DuL(DuLNode* p, ElemType* e) {
	DuLNode* t = p->next;
	e = t->data;
	p->next = p->next->next;
	p->next->prior = p;
	free(t);
	return SUCCESS;
}
//����һ��ɾ������������ѡ��ɾ����λ��
void Delete(DuLinkedList L)
{
	int i = 0;
	DuLNode* p;
	p = (DuLNode*)malloc(sizeof(DuLNode));
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
	DeleteList_DuL(p, &e);
	PrintList(L);//�������
}
void DestroyList_DuL(DuLinkedList* L) {
	DuLNode* p = (*L)->next;
	DuLNode* q;
	q = (DuLNode*)malloc(sizeof(DuLNode));
	while (p->next != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	if (p != NULL)
		free(p);
}


