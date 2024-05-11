#include "remove.h"

#include "find.h"
#include "min.h"
#include "type.h"

#include <stdio.h>
#include <stdlib.h>

void _SubstituteParent(Node *x, Node *y) {
	if (x->$p->$l == x) {
		x->$p->$l = y;
	} else {
		x->$p->$r = y;
	}
}

Node *Remove(Node *root, int $v) {
	printf("remove %d\n", $v);

	Node *x = Find(root, $v);

	if (x == NULL) {
		printf("%d is not found\n", $v);
		return x;
	}

	if (x->$p == NULL) {
		printf("%d is root\n", $v);
		return x;
	}

	// x child: 2
	if (x->$l != NULL && x->$r != NULL) {
		Node *s = Min(x->$r);
		if (s->$p != x) {
			s->$p->$l = s->$r;
		}
		x->$l->$p = s;
		s->$l = x->$l;
		if (x->$r != s) {
			x->$r->$p = s;
			s->$r = x->$r;
		}
		s->$p = x->$p;
		if (x->$p->$l == x) {
			x->$p->$l = s;
		} else {
			x->$p->$r = s;
		}
	}

	// x child: 1
	if (x->$l != NULL && x->$r == NULL) {
		if (x->$p->$l == x) {
			x->$p->$l = x->$l;
			x->$l->$p = x->$p;
		}
		if (x->$p->$r == x) {
			x->$p->$r = x->$l;
			x->$l->$p = x->$p;
		}
	}
	if (x->$l == NULL && x->$r != NULL) {
		if (x->$p->$l == x) {
			x->$p->$l = x->$r;
			x->$r->$p = x->$p;
		}
		if (x->$p->$r == x) {
			x->$p->$r = x->$r;
			x->$r->$p = x->$p;
		}
	}

	// x child: 0
	if (x->$l == NULL && x->$r == NULL) {
		if (x->$p->$l == x) {
			x->$p->$l = NULL;
		}
		if (x->$p->$r == x) {
			x->$p->$r = NULL;
		}
	}

	return x;
}
