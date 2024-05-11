#ifndef PRINT_QUEUE_H
#define PRINT_QUEUE_H

#include "type.h"

typedef struct NodeQ_Item {
		Node *node;
		struct NodeQ_Item *next;
} NodeQ_Item;

typedef struct NodeQ {
		int len;
		NodeQ_Item *first;
		NodeQ_Item *last;
} NodeQ;

NodeQ *InitNodeQ();
void PrintNodeQ(NodeQ *q);
void EnqueueNodeQ(NodeQ *q, Node *node);
Node *DequeueNodeQ(NodeQ *q);

#endif
