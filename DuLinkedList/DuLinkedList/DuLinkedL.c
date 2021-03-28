#include "DuLinkedList.h"
Status InitList_DuL(DuLinkedList* L) {
	*L = (DuLinkedList*)malloc(sizeof(DuLNode));
	//使头结点指向空
	(*L)->next = (*L)->prior = NULL;
	return SUCCESS;
}
//双向链表的插入
void InsertDuLinkList(DuLinkedList* L, ElemType data)
{
	if (*L == NULL) {
		printf("The list is empty.\n");		//  头结点为空，则无法插入
		return;
	}
	DuLNode* tmpHead = (*L);		//  创建一个临时的头结点指针
	if (tmpHead ->next== NULL) {
		DuLNode* addition = (DuLNode*)malloc(sizeof(DuLNode));
			addition->data = data;		//  数据域赋值
			addition->next = tmpHead->next;//  后向指针连接
			addition->prior = tmpHead;//  将插入结点的prior 指向头结点
			tmpHead->next = addition;
	}
	else{
		DuLNode* addition = (DuLNode*)malloc(sizeof(DuLNode));
		addition->data = data;		//  数据域赋值
		tmpHead->next->prior = addition;		//  头结点的下一个结点的prior指针
		addition->prior = *L;		//  插入的结点的prior指针指向头结点
		addition->next = tmpHead->next;		//  插入结点的next 指针指向原本头指针的下一结点	
	}
}
//赋值函数
void CreatedDuLinkList(DuLinkedList* L)
{
	int  n;
	printf("建立双链表，输入值（9999结束）\n");
	scanf_s("%d", &n);
	while (n != 9999) {
		InsertDuLinkList(&L, n);
		scanf_s("%d", &n);
	}
	PrintList(L);
}
void menu()

{

	printf("************请输入所需操作***********\n");/*选择功能菜单*/

	printf("*************************************\n");

	printf("1.链表赋值\n");

	printf("2.插入结点\n");

	printf("3.删除结点\n");

	printf("4.清空列表\n");

	printf("0.退出系统\n");

	printf("**************************************\n");

}
//输出函数
void PrintList(DuLinkedList L)
{
	DuLNode*p;
	p = L->next;
	printf("链表元素如下：\n");
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
	//假设要插入的是头结点
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
//添加一个Insert1函数实现定点定值插入
void Insert1(DuLinkedList L)
{
	int x;
	int i = 0;
	printf("输入你想插入的数\n");
	scanf_s("%d", &x);
	DuLNode* q;
	q = (DuLNode*)malloc(sizeof(DuLNode));
	q->data = x;
	DuLNode* p;
	p = (DuLNode*)malloc(sizeof(DuLNode));
	p = L;
	int y;
	printf("输入你想插入的位置\n");
	scanf_s("%d", &y);
	while (p != NULL && i < y)
	{
		i++;
		p = p->next;//while使其移动到要插入的结点之前 
	}
	InsertBeforeList_DuL(p, q);
	PrintList(L);//输出链表
}
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
	//假设要插入的是尾节点
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
	printf("输入你想插入的数\n");
	scanf_s("%d", &x);
	DuLNode* q;
	q = (DuLNode*)malloc(sizeof(DuLNode));
	q->data = x;
	DuLNode* p;
	p = (DuLNode*)malloc(sizeof(DuLNode));
	p = L;
	int y;
	printf("输入你想插入的位置\n");
	scanf_s("%d", &y);
	while (p != NULL && i < y - 1)
	{
		i++;
		p = p->next;//while使其移动到要插入的结点之前 
	}
	InsertAfterList_DuL(p, q);
	PrintList(L);//输出链表
}
Status DeleteList_DuL(DuLNode* p, ElemType* e) {
	DuLNode* t = p->next;
	e = t->data;
	p->next = p->next->next;
	p->next->prior = p;
	free(t);
	return SUCCESS;
}
//定义一个删除函数，可以选择删除的位置
void Delete(DuLinkedList L)
{
	int i = 0;
	DuLNode* p;
	p = (DuLNode*)malloc(sizeof(DuLNode));
	p = L;
	int y;
	printf("输入你想删除的位置\n");
	scanf_s("%d", &y);
	while (p != NULL && i < y - 1)
	{
		i++;
		p = p->next;//while使其移动到要删除的结点之前 
	}
	int e;
	DeleteList_DuL(p, &e);
	PrintList(L);//输出链表
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


