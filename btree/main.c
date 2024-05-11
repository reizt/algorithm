#include "find.h"
#include "init.h"
#include "insert.h"
#include "max.h"
#include "min.h"
#include "print.h"
#include "remove.h"
#include "type.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generate_random_values(int n) {
	int *nums = (int *) malloc(sizeof(int) * n);
	int i, j, tmp;

	for (i = 0; i < n; i++) {
		nums[i] = i;
	}
	srand(time(NULL));
	// Shuffle with Fisher-Yates
	for (i = n - 1; i > 0; i--) {
		j = rand() % (i + 1);

		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	return nums;
}

int main() {
	int len = 10;
	int *values = generate_random_values(len);
	Node *root = Init(values[0]);
	Print(root);
	int i;
	for (i = 1; i < len; i++) {
		Insert(root, values[i]);
		Print(root);
	}
	for (i = 1; i < len; i++) {
		Remove(root, values[i]);
		Print(root);
	}
	Remove(root, values[0]);

	return 0;
}
