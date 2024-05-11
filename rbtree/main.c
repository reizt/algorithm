#include "find.h"
#include "init.h"
#include "insert.h"
#include "max.h"
#include "min.h"
#include "print.h"
#include "remove.h"
#include "solve_black_height.h"
#include "solve_red_conflict.h"
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
	// int len = 30;
	// int *values = generate_random_values(len);
	// int len = 10;
	// int values[] = { 26, 17, 35, 14, 21, 28, 41, 36, 45, 38 };
	int len = 17;
	int values[] = { 26, 17, 41, 14, 21, 30, 47, 12, 15, 18, 24, 28, 38, 28, 38, 22, 25 };
	Node *root = Init(values[0], RED);
	// Print(root);
	int i;
	for (i = 1; i < len; i++) {
		Node *inserted = Insert(root, values[i]);
		root = SolveRedConflict(root, inserted);
		Print(root);
	}
	// for (i = 1; i < len; i++) {
	// 	Node *removed = Remove(root, values[i]);
	// 	RemoveAdjust(root, removed);
	// 	Print(root);
	// }
	// Remove(root, values[0]);

	return 0;
}
