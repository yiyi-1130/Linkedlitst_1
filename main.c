#include"LinkedList.h"
int main()
{
    LinkedList head = NULL;
    InitList(&head);
    menu();
    while (1)
    {
        char ch = getchar();
        switch (ch)
        {
        case '1':

            CreateList_Head(head); PrintList(head); break;

        case '2':

            Insert(head); break;

        case '3':

            Delete(head); break;

        case '4':
            IsLoopList(head); break;

        case '5':
            ReverseEvenList(&head); PrintList(head); break;

        case '6':
            FindMidNode(&head); break;

        case '7':
            ReverseList(&head); break;

        case '8':
            Search(head); break;

        case '0':

            printf("ллʹ��!�ټ�!\n");

            return;

        default:

            printf("����������\n");
        }
    }
}