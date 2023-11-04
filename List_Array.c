#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#include "List_Array.h"
void main() {
	int choose = 0;
	int data = 0;
	List* list = CreateList(6);


	while (1) {
		printf("In(0), Search(1), Out(2), Exit(3) : ");
		scanf("%d", &choose);
		if (choose == 0) {
			printf("In : ");
			scanf("%d", &data);
			_insertList(list, data);
			printAllData(list);
		}
		else if (choose == 1) {
			printf("Search : ");
			scanf("%d", &data);
			if (searchList(list, data))
				printf("%d is in list\n", data);
			else
				printf("%d is not in list\n", data);
			printAllData(list);
		}
		else if (choose == 2) {
			printf("Out : ");
			scanf("%d", &data);
			if (searchList(list, data))
				deleteList(list, data);
			else
				printf("There is no %d in list\n", data);
			printAllData(list);
		}
		else if (choose == 3) {
			destroyList(list);
			exit(1);
		}
	}
}