#include "insert.h"

#include "init.h"
#include "type.h"

#include <stdio.h>
#include <stdlib.h>

#define DIRECTION_LEFT 1
#define DIRECTION_RIGHT 2

void Insert(Node *root, int $v) {
	printf("insert %d\n", $v);

	Node *new = Init($v);
	Node *current = root;
	Node *parent = NULL;
	int direction;
	while (current != NULL) {
		parent = current;
		if (new->$v < current->$v) { // go left
			direction = DIRECTION_LEFT;
			current = current->$l;
		} else { // go right
			direction = DIRECTION_RIGHT;
			current = current->$r;
		}
	}
	new->$p = parent;
	if (direction == DIRECTION_LEFT) {
		parent->$l = new;
	} else {
		parent->$r = new;
	}
}
