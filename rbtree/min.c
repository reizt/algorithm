#include "min.h"

#include "type.h"

#include <stdio.h>
#include <stdlib.h>

Node *Min(Node *root) {
	if (root == NULL) {
		printf("empty tree\n");
		exit(1);
	}
	Node *n = root;
	while (n->$l != NULL) {
		n = n->$l;
	}
	return n;
}
