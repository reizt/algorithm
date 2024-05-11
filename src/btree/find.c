#include "find.h"

#include "type.h"

#include <stdlib.h>

Node *Find(Node *start, int $v) {
	Node *x = start;
	for (;;) {
		if (x == NULL) return NULL;
		if (x->$v == $v) return x;
		if ($v < x->$v) {
			x = x->$l;
		} else {
			x = x->$r;
		}
	}
}
