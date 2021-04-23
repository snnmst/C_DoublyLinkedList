#include <stdio.h>
#include "DoublyLinkList.h"

int main()
{
	HLLIST list;
	list = CreateList();
	
	PushFront(list, 12);
	Display(list);
	PushBack(list, 25);
	Display(list);
	PushFront(list, 32);
	Display(list);
	PushBack(list, 17);
	Display(list);

	PopBack(list);
	Display(list);
	PopFront(list);
	Display(list);
	
	PushBack(list, 98);
	Display(list);

	NODE* pTemp;
	int i = 1;
	pTemp = list->pHead;
	while (i--)
		pTemp = pTemp->pNext;


	InsertItemAfterNode(list, pTemp, 91);
	Display(list);

	InsertItemBeforeNode(list, pTemp, 19);
	Display(list);

	return 0;
}