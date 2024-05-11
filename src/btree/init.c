#include "init.h"

#include "type.h"

#include <stdlib.h>

Node *Init(int $v) {
	Node *n = (Node *) malloc(sizeof(Node));
	n->$v = $v;
	n->$p = NULL;
	n->$l = NULL;
	n->$r = NULL;
	return n;
}
