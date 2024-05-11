#include "max.h"

#include "type.h"

#include <stdio.h>
#include <stdlib.h>

Node *Max(Node *root) {
	if (root == NULL) {
		printf("empty tree\n");
		exit(1);
	}
	Node *n = root;
	while (n->$r != NULL) {
		n = n->$r;
	}
	return n;
}
