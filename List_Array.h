#pragma once

typedef struct {
	int size;
	int front, rear;
	int* list;
}List;

List* CreateList(int size) {
	List* list = (List*)malloc(sizeof(List));
	if (list == NULL)
		return NULL;

	list->list = (int*)malloc(size * sizeof(int));
	if (list->list == NULL) {
		free(list);
		return NULL;
	}
	list->size = size;
	list->front = 0;
	list->rear = 0;

	return list;
}

void makeOrderList(List* list) {
	int i = 0, j = 0;
	int temp = 0;

	for (i = (list->front+2)%list->size; i != (list->rear+1)%list->size; i=(i+1) % list->size) {
		for (j = (list->front+1)%list->size; j != i; j=(j+1)%list->size) {
			if (list->list[j] <= list->list[i])
				continue;
			else {
				temp = list->list[j];
				list->list[j] = list->list[i];
				list->list[i] = temp;
			}
		}
	}
}

void _insertList(List* list, int data) {
	int i = list->front+1;
	int j = list->rear;

	if ((list->rear+1) % list->size == list->front) {
		printf("too full\n");
		return;
	}
	for (i; i != (list->rear+1)%list->size; i = (i + 1) % list->size) {
		if (list->list[i] == data)
			return;
	}
	list->rear = (list->rear + 1) % list->size;
	list->list[list->rear] = data;

	makeOrderList(list);
}

void deleteList(List* list, int data) {
	int i = 0;
	int ListData = 0;
	
	for (i = (list->front+1)%list->size; i != (list->rear+1)%list->size; i=(i+1)%list->size) {
		ListData = list->list[i];
		if (ListData == data) {
			printf("%d is deleted\n", list->list[i]);
			list->list[i] = NULL;
		}
	}
	makeOrderList(list);

	list->front=(list->front + 1) % list->size;
}

void printAllData(List* list) {
	int i = 0;
	printf("The current status of List : ");
	for (i = (list->front+1)%list->size; i != (list->rear+1)%list->size; i=(i+1)%list->size) {
		printf("%d ", list->list[i]);
	}
	printf("\n");
}

void destroyList(List* list) {
	free(list->list);
	free(list);

	return;
}

bool searchList(List* list, int data) {
	int i = 0;
	for (i = (list->front+1)%list->size; i != (list->rear+1)%list->size; i=(i+1)%list->size) {
		if (list->list[i] == data)
			return true;
	}
	return false;
}