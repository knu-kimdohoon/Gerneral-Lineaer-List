#pragma once

typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

typedef struct {
	int count;
	ListNode* head;
	ListNode* pos;
}List;

List* CreateList() {
	List* pList = (List*)malloc(sizeof(List));
	if (pList == NULL) {
		return NULL;
	}
	pList->count = 0;
	pList->head = NULL;
	pList->pos = NULL;

	return pList;
}

/*
void Insert(List* pList, int data) {
	ListNode* pCur = NULL, * pNext = NULL;
	int i = 0;

	ListNode* pNew = (ListNode*)malloc(sizeof(ListNode));
	if (pNew == NULL) {
		return;
	}
	pNew->data = data;
	pNew->link = NULL;

	if (pList->head == NULL) {
		pNew->link = pList->head;
		pList->head = pNew;
	}
	else {
		for (pCur = pList->head, pNext = pCur->link; i == 0; pCur = pNext, pNext = pCur->link) {
			if (pNext == NULL) {
				if (pNew->data <= pCur->data) {
					pNew->link = pCur;
					pList->head = pNew;
					pCur->link = NULL;
				}
				else {
					pCur->link = pNew;
					pNew->link = NULL;
				}
				i++;
			}
			else {
				if (pNew->data <= pCur->data) {
					pNew->link = pList->head;
					pList->head = pNew;
					i++;
				}
				else if (pNew->data > pCur->data && pNew->data <= pNext->data) {
					pNew->link = pCur->link;
					pCur->link = pNew;
					i++;
				}
				else if (pNew->data > pCur->data && pNew->data > pNext->data) {
					continue;
				}
			}
		}
	}
	pList->count++;
}
*/

void InsertList(List* pList, ListNode* pPre, int data) {
	ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));
	if (pNewNode == NULL) {
		return;
	}
	pNewNode->data = data;

	if (pPre == NULL) {
		pNewNode->link = pList->head;
		pList->head = pNewNode;
	}
	else {
		pNewNode->link = pPre->link;
		pPre->link = pNewNode;
	}
	pList->count++;
}

bool SearchList(List* pList, ListNode** ppPre, ListNode** ppLoc, int data) {
	if (pList->count == 0) {
		return false;
	}

	for (*ppPre = NULL, *ppLoc = pList->head; *ppLoc != NULL; *ppPre = *ppLoc, *ppLoc = (*ppLoc)->link) {
		if ((*ppLoc)->data == data)
			return true;
		else if ((*ppLoc)->data > data)
			break;
	}
	return false;
}

int deleteList(List* pList, ListNode* pPre, ListNode* pLoc) {
	if (pPre == NULL)
		pList->head = pLoc->link;
	else
		pPre->link = pLoc->link;

	free(pLoc);
	pList->count--;

	return 0;
}

void addNodeList(List* pList, int data) {
	ListNode* pPre = NULL, * pLoc = NULL;
	bool found = SearchList(pList, &pPre, &pLoc, data);

	if (!found)
		InsertList(pList, pPre, data);
}

void removeList(List* pList, int data) {
	ListNode* pPre = NULL, * pLoc = NULL;
	bool found = SearchList(pList, &pPre, &pLoc, data);

	if (found)
		deleteList(pList, pPre, pLoc);
}

bool traverseList(List* pList, int fromWhere, int* pDataOut) {
	if (fromWhere == 0 || pList->pos == NULL)
		pList->pos = pList->head;
	else
		pList->pos = pList->pos->link;

	if (pList->pos != NULL) {
		*pDataOut = pList->pos->data;
		return true;
	}
	else {
		*pDataOut = 0;
		return false;
	}
}

void printAllData(List* pList) {
	int n = 0, data = 0;
	int ret = 0;
	printf("The current status of List : ");
	do {
		ret = traverseList(pList, n++, &data);
		if (ret)
			printf("%d ", data);
	} while (ret);
	printf("\n");
}

void destroyList(List* pList) {
	ListNode* pDel = NULL, * pNext = NULL;
	int i = pList->count;
	for (pDel = pList->head; pDel != NULL; pDel = pNext) {
		pNext = pDel->link;
		free(pDel);
		printf("%d node is destroyed\n", i--);
	}
	free(pList);
	printf("The List is Destroyed");
}