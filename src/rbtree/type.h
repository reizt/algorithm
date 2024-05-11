#ifndef TYPE_H
#define TYPE_H

#include <limits.h>

#define NULLISH_INT INT_MAX
#define RED 1
#define BLACK 2

typedef struct Node {
		int $v;
		int $c;
		struct Node *$p;
		struct Node *$l;
		struct Node *$r;
} Node;

#endif
