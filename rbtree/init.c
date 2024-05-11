#include "init.h"

#include "type.h"

#include <stdlib.h>

Node *Init(int $v, int $c) {
	Node *n = (Node *) malloc(sizeof(Node));
	n->$v = $v;
	n->$c = $c;
	n->$p = NULL;
	n->$l = NULL;
	n->$r = NULL;
	return n;
}
