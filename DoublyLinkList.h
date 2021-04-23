#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_
#include <stddef.h>


#define GetCount(list)		((list)->count)

typedef int DATATYPE;

typedef struct tagNODE {
	struct tagNODE *pNext;
	struct tagNODE *pPrev;
	DATATYPE data;
}NODE;

typedef struct tagHANDLE {
	NODE *pHead;
	NODE *pTail;
	size_t count;
}LLIST, *HLLIST;



HLLIST CreateList(void);
void PushBack(HLLIST list, DATATYPE data);
void PushFront(HLLIST list, DATATYPE data);
DATATYPE PopBack(HLLIST list);
DATATYPE PopFront(HLLIST list);
NODE* InsertItemAfterNode(HLLIST list, NODE* pNode, DATATYPE data);
NODE* InsertItemBeforeNode(HLLIST list, NODE* pNode, DATATYPE data);
NODE* InsertItemIndexNode(HLLIST list, size_t index, DATATYPE data);

void Display(HLLIST list);
void ClearList(HLLIST list);
void CloseList(HLLIST list);


#endif // !DOUBLYLINKEDLIST_H_



