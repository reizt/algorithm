#include "type.h"

#include <stdio.h>
#include <stdlib.h>

int _DepthRecursive(Node *node, int depth) {
	if (node == NULL) {
		return 0;
	}
	int left = _DepthRecursive(node->$l, depth);
	int right = _DepthRecursive(node->$r, depth);
	if (left > right) {
		return depth + left;
	} else {
		return depth + right;
	}
}

int Depth(Node *root) {
	//
	return _DepthRecursive(root, 1);
}
