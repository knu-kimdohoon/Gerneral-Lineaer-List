#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

#include "List_Link.h"

void main() {
	List* pList = CreateList();
	int choose = 0, data = 0;
	ListNode* pPre = NULL, * pLoc = NULL;
	bool search = NULL, search1 = NULL;

	while (1) {
		printf("In(0), Search(1), Out(2), Exit(3) : ");
		scanf("%d", &choose);
		if (choose == 0) {
			printf("In : ");
			scanf("%d", &data);
			addNodeList(pList, data);
		}
		else if (choose == 1) {
			printf("Search : ");
			scanf("%d", &data);
			search = SearchList(pList, &pPre, &pLoc, data);
			if (search == false) {
				printf("My List does not have %d\n", data);
			}
			else {
				printf("My List has %d\n", data);
			}
		}
		else if (choose == 2) {
			printf("Out : ");
			scanf("%d", &data);
			search1 = SearchList(pList, &pPre, &pLoc, data);
			if (search1 == false) {
				printf("My List does not have %d\n", data);
				printAllData(pList);
				continue;
			}
			else {
				removeList(pList, data);
				printf("%d was removed\n", data);
			}
		}
		else if(choose == 3) {
			destroyList(pList);
			exit(1);
		}
		else {
			printf("Error, put another number\n");
			continue;
		}
		printAllData(pList);
	}
}