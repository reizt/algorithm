#include "solve_red_conflict.h"

#include "print.h"
#include "rotate.h"
#include "type.h"

#include <stdio.h>
#include <stdlib.h>

Node *_GetUncle(Node *x) {
	if (x->$p->$p->$l == x->$p) {
		return x->$p->$p->$r;
	} else {
		return x->$p->$p->$l;
	}
}

Node *SolveRedConflict(Node *root, Node *x) {
	// Consider when x parent is red
	Node *par = x->$p;
	if (par == NULL || par->$c == BLACK) {
		return root;
	}

	// CASE 0: parent is root
	Node *gpar = x->$p->$p;
	if (gpar == NULL) {
		par->$c = BLACK;
		return root;
	}

	// CASE 1: uncle is red
	Node *uncle = _GetUncle(x);
	if (uncle != NULL && uncle->$c == RED) {
		par->$c = BLACK;
		uncle->$c = BLACK;
		gpar->$c = RED;
		root = SolveRedConflict(root, gpar);
		return root;
	}

	// CASE 2: uncle is black and parent has x at right
	// Turn problem into CASE 3
	if (gpar->$l == par && par->$r == x) {
		root = RotateLeft(root, par);
		root = SolveRedConflict(root, par);
		return root;
	}
	if (gpar->$r == par && par->$l == x) {
		root = RotateRight(root, par);
		root = SolveRedConflict(root, par);
		return root;
	}

	// CASE 3: uncle is black and parent has x at left
	par->$c = BLACK;
	gpar->$c = RED;
	if (gpar->$l == par) {
		root = RotateRight(root, gpar);
	} else {
		root = RotateLeft(root, gpar);
	}
	return root;
}
