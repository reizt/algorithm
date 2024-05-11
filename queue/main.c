#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define Q_EMPTY INT_MAX

typedef struct Item {
		int value;
		struct Item *next;
} Item;

typedef struct Q {
		int len;
		Item *first;
		Item *last;
} Q;

Q *Init() {
	Q *q = (Q *) malloc(sizeof(Q));
	q->len = 0;
	q->first = NULL;
	q->last = NULL;
	return q;
}

void Print(Q *q) {
	if (q->len == 0) {
		printf("empty queue\n");
		return;
	}
	Item *x = q->first;
	while (x != NULL) {
		printf("%d ", x->value);
		x = x->next;
	}
	printf("\n");
}

void Enqueue(Q *q, int value) {
	if (value == Q_EMPTY) {
		printf("queued value is reserved int\n");
		exit(1);
	}
	Item *item = (Item *) malloc(sizeof(Item));
	item->value = value;
	item->next = NULL;
	if (q->last != NULL) {
		q->last->next = item;
	}
	q->last = item;
	q->len++;
	if (q->first == NULL) {
		q->first = item;
	}
}

int Dequeue(Q *q) {
	if (q->first == NULL) {
		return Q_EMPTY;
	}
	Item *first = q->first;
	int value = first->value;
	q->first = q->first->next;
	if (q->first == NULL) {
		q->last = NULL;
	}
	free(first);
	q->len--;
	return value;
}

int main() {
	Q *q = Init();
	int values[] = { 3, 1, 2, 4 };
	int len = sizeof(values) / sizeof(int);
	int i;
	for (i = 0; i < len; i++) {
		Enqueue(q, values[i]);
		Print(q);
	}
	int x;
	while (q->len > 0) {
		x = Dequeue(q);
		Print(q);
	}

	free(q);

	exit(0);
}
