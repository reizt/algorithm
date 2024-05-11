#include "rotate.h"

#include "type.h"

#include <stdio.h>
#include <stdlib.h>

Node *RotateLeft(Node *root, Node *x) {
	Node *xp = x->$p;
	Node *xr = x->$r;
	Node *xrl = x->$r->$l;
	if (xp != NULL) {
		if (xp->$l == x) xp->$l = xr;
		if (xp->$r == x) xp->$r = xr;
	}
	x->$p = xr;
	x->$r = xrl;
	xr->$p = xp;
	xr->$l = x;
	if (xrl != NULL) {
		xrl->$p = x;
	}

	if (x == root) {
		return xr;
	}
	return root;
}

Node *RotateRight(Node *root, Node *x) {
	Node *xp = x->$p;
	Node *xl = x->$l;
	Node *xlr = x->$l->$r;
	if (xp != NULL) {
		if (xp->$r == x) xp->$r = xl;
		if (xp->$l == x) xp->$l = xl;
	}
	x->$p = xl;
	x->$l = xlr;
	xl->$p = xp;
	xl->$r = x;
	if (xlr != NULL) {
		xlr->$p = x;
	}

	if (x == root) {
		return xl;
	}
	return root;
}
