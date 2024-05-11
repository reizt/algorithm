#include "type.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct NodeQ_Item {
		Node *node;
		struct NodeQ_Item *next;
} NodeQ_Item;

typedef struct NodeQ {
		int len;
		NodeQ_Item *first;
		NodeQ_Item *last;
} NodeQ;

NodeQ *InitNodeQ() {
	NodeQ *q = (NodeQ *) malloc(sizeof(NodeQ));
	q->len = 0;
	q->first = NULL;
	q->last = NULL;
	return q;
}

void PrintNodeQ(NodeQ *q) {
	if (q->len == 0) {
		printf("empty queue\n");
		return;
	}
	NodeQ_Item *x = q->first;
	while (x != NULL) {
		printf("%d ", x->node->$v);
		x = x->next;
	}
	printf("\n");
}

void EnqueueNodeQ(NodeQ *q, Node *node) {
	NodeQ_Item *prev_last = q->last;
	q->last = (NodeQ_Item *) malloc(sizeof(NodeQ_Item));
	q->last->node = node;
	q->last->next = NULL;
	if (prev_last != NULL) {
		prev_last->next = q->last;
	} else {
		q->first = q->last;
	}
	q->len++;
}

Node *DequeueNodeQ(NodeQ *q) {
	if (q->first == NULL) {
		return NULL;
	}
	NodeQ_Item *dequeued = q->first;
	q->first = dequeued->next;
	if (q->first == NULL) {
		q->last = NULL;
	}
	q->len--;
	return dequeued->node;
}
