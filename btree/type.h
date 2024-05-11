#ifndef TYPE_H
#define TYPE_H

#include <limits.h>

#define NULLISH_INT INT_MAX

typedef struct Node {
		int $v;
		struct Node *$p;
		struct Node *$l;
		struct Node *$r;
} Node;

#endif
