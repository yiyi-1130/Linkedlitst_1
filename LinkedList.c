#include"LinkedList.h"
//初始化一个空链表，只使用不带值的头节点
Status InitList(LinkedList* L) {
	//初始化指针
	*L = (LinkedList*)malloc(sizeof(LNode));
	//使头结点指向空
	(*L)->next = NULL;
	return SUCCESS;
}
//菜单函数，实现良好的人机交互
void menu()

{

	printf("************请输入所需操作***********\n");/*选择功能菜单*/

	printf("*************************************\n");

	printf("1.链表赋值\n");

	printf("2.插入结点\n");

	printf("3.删除结点\n");

	printf("4.判断环链\n");

	printf("5.奇偶倒置\n");

	printf("6.中间元素的值\n");

	printf("7.链表倒置\n");

	printf("8.查询数值是否在链表\n");

	printf("0.退出系统\n");

	printf("**************************************\n");

}
//链表赋值
void CreateList_Head(LinkedList L)
{
	LinkedList s; int x;
	printf("头法建立单链表，输入值（9999结束）\n");
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;                          //插入结点
		scanf_s("%d", &x);
	}
}
//输出链表的值
void PrintList(LinkedList L)
{
	LinkedList p;
	p = L->next;
	printf("链表元素如下：\n");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//插入，将q插到p的后面
Status InsertList(LNode* p, LNode* q) {
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}
//定义一个插入函数，可以选择插入的位置和数值
void Insert(LinkedList L)
{
	int x;
	int i = 0;
	printf("输入你想插入的数\n");
	scanf_s("%d", &x);
	LNode* q;
	q = (LNode*)malloc(sizeof(LNode));
	q->data = x;
	LNode* p;
	p = (LNode*)malloc(sizeof(LNode));
	p = L;
	int y;
	printf("输入你想插入的位置\n");
	scanf_s("%d", &y);
	while (p != NULL && i < y - 1)
	{
		i++;
		p = p->next;//while使其移动到要插入的结点之前 
	}
	InsertList(p, q);
	PrintList(L);//输出链表
}
//删除p结点，并把值赋给e
Status DeleteList(LNode* p, ElemType* e) {

	LNode* t = p->next;
	p->next = p->next->next;
	e = t->data;
	free(t);
	return SUCCESS;
}
//定义一个删除函数，可以选择删除的位置
void Delete(LinkedList L)
{
	int i = 0;
	LNode* p;
	p = (LNode*)malloc(sizeof(LNode));
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
	DeleteList(p, &e);
	PrintList(L);//输出链表
}
//判断链表是否成环
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
}//奇偶对换
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
//倒置函数
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
//找最中心的值
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
	printf("请输入你想查询的值：\n");
	scanf_s("%d", &b);
	SearchList(L, b);
}