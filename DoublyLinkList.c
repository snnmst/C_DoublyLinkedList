#include "DoublyLinkList.h"
#include <stdlib.h>
#include <stdio.h>

static NODE* createNode(DATATYPE data)
{
	NODE* pNewNode;
	if ((pNewNode = (NODE*)malloc(sizeof(NODE))) == NULL)
	{
		printf("cannot allocate memory!\n");
		exit(EXIT_FAILURE);
	}

	pNewNode->data = data;
	pNewNode->pNext = NULL;
	pNewNode->pPrev = NULL;

	return pNewNode;

}

HLLIST CreateList(void)
{
	HLLIST list;
	if ((list = (HLLIST)malloc(sizeof(LLIST))) == NULL)
	{
		printf("cannot allocate memory!\n");
		exit(EXIT_FAILURE);
	}

	list->pHead = NULL;
	list->pTail = NULL;
	list->count = 0;

	return list;

}
void PushBack(HLLIST list, DATATYPE data)
{
	NODE* pNode;
	if ((pNode = createNode(data)) == NULL)
		return 0;

	if (list->pTail == NULL)
		list->pHead = pNode;
	
	else{
		list->pTail->pNext = pNode;
		pNode->pPrev = list->pTail;
	}

	list->pTail = pNode;
	++list->count;
}

void PushFront(HLLIST list, DATATYPE data)
{
	NODE* pNode;
	pNode = createNode(data);

	if (list->pHead == NULL)
		list->pTail = pNode;
	else {
		list->pHead->pPrev = pNode;
		pNode->pNext = list->pHead;
	}

	list->pHead = pNode;
	++list->count;

}

DATATYPE PopBack(HLLIST list)
{
	int popVal = list->pTail->data;
	
	list->pTail = list->pTail->pPrev;
	list->pTail->pNext = NULL;
	
	--list->count;
	
	return popVal;
	
}
DATATYPE PopFront(HLLIST list)
{
	int popVal = list->pHead;
	list->pHead = list->pHead->pNext;
	list->pHead->pPrev = NULL;

	--list->count;

	return popVal;
}


NODE* InsertItemAfterNode(HLLIST list, NODE* pNode, DATATYPE data)
{
	NODE* pNewNode;
	if ((pNewNode = createNode(data)) == NULL)
		return NULL;

	if (pNode->pNext != NULL) //that means we gonna insert after tail
		pNode->pNext->pPrev = pNewNode;
	else
		list->pTail = pNewNode;
		

	pNewNode->pPrev = pNode;
	pNewNode->pNext = pNode->pNext;
	pNode->pNext = pNewNode;
	++list->count;

	return pNewNode;
}
NODE* InsertItemBeforeNode(HLLIST list, NODE* pNode, DATATYPE data)
{

	// x1 <-> ox2 <-> x3 <-> x4 

	NODE *pNewNode;
	if ((pNewNode = createNode(data)) == NULL)
		return NULL;

	if (pNode->pPrev != NULL)
		pNode->pPrev->pNext = pNewNode;
	else
		list->pHead = pNewNode;
	pNewNode->pNext = pNode;
	pNewNode->pPrev = pNode->pPrev;
	pNode->pPrev = pNewNode;

	++list->count;

	return pNewNode;
}

NODE* InsertItemIndexNode(HLLIST list, size_t index, DATATYPE data)
{

	size_t i;
	NODE *pTemp;

	if (index > list->count)
		return NULL;

	if (index == 0)
		PushFront(list, data);

	pTemp = list->pHead;

	for (i = 0; i < index - 1; i++)
		pTemp = pTemp->pNext;

	return InsertItemAfterNode(list, pTemp, data);


}

void Display(HLLIST list)
{
	if (list->count == 0)
	{
		printf("Empty List!\n");
	}
	else {
		NODE* pTemp;
		for (pTemp = list->pHead; pTemp != NULL; pTemp = pTemp->pNext)
			printf("%3d ", pTemp->data);
		printf("\n");
	}

}

void ClearList(HLLIST list)
{
	NODE *pNode, *pNext;

	pNode = list->pHead;
	while (pNode != NULL)
	{
		pNext = pNode->pNext;
		free(pNode);
		pNode = pNext;
	}

	list->pHead = list->pTail = NULL;
	list->count = 0;
}
void CloseList(HLLIST list)
{
	ClearList(list);
	free(list);
}