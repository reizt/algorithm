#include "print.h"

#include "depth.h"
#include "init.h"
#include "print_queue.h"
#include "type.h"

#include <stdio.h>
#include <stdlib.h>

int power(int x, int y) {
	int z = 1;
	int i;
	for (i = 0; i < y; i++) {
		z *= x;
	}
	return z;
}

void Print(Node *root) {
	if (root == NULL) {
		return;
	}

	int depth = Depth(root);
	int iter = power(2, depth) - 1;
	int i, j;
	Node nullish_node = { .$v = NULLISH_INT, .$p = NULL, .$l = NULL, .$r = NULL };

	NodeQ *q = InitNodeQ();
	EnqueueNodeQ(q, root);
	Node *x;

	int floor = 0;
	int gap = power(2, depth - 1) - 1;
	int width = 1;

	for (i = 0; i < iter; i++) {
		printf("--");
	}
	printf("\n");

	for (i = 0; i < iter; i++) {
		x = DequeueNodeQ(q);
		if (x == NULL) {
			break;
		}

		// before
		for (j = 0; j < gap; j++) {
			printf("  ");
		}

		// node value
		if (x->$v == NULLISH_INT) {
			printf("  ");
		} else {
			printf("%2d", x->$v);
		}
		if (x->$l != NULL) {
			EnqueueNodeQ(q, x->$l);
		} else {
			EnqueueNodeQ(q, &nullish_node);
		}
		if (x->$r != NULL) {
			EnqueueNodeQ(q, x->$r);
		} else {
			EnqueueNodeQ(q, &nullish_node);
		}

		// after
		for (j = 0; j < gap; j++) {
			printf("  ");
		}
		if (i % width != width - 1) {
			printf("  ");
		}
		if (i % width == width - 1) {
			printf("\n");
		}

		// update
		if (i % width == width - 1) {
			floor++;
			width = width * 2 + 1;
			gap = power(2, depth - floor - 1) - 1;
		}
	}

	for (i = 0; i < iter; i++) {
		printf("--");
	}
	printf("\n");
}
