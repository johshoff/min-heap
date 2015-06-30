#include <stdio.h>
#include <assert.h>
#include "priqueue.h"

void test_small() {
	printf("Testing small queue\n");

	MinHeap q = pqNew(10);

	pqAdd(&q, 3);
	pqAdd(&q, 1);
	pqAdd(&q, 2);

	assert(pqSize(&q) == 3);
	assert(pqPop(&q) == 1);
	assert(pqPop(&q) == 2);
	assert(pqPop(&q) == 3);
	assert(pqSize(&q) == 0);

	pqCleanUp(&q);
}

void test_grow() {
	printf("Testing growing queue\n");

	MinHeap q = pqNew(0);

	pqAdd(&q, 3);
	pqAdd(&q, 1);
	pqAdd(&q, 2);

	assert(pqSize(&q) == 3);
	assert(pqPop(&q) == 1);
	assert(pqPop(&q) == 2);
	assert(pqPop(&q) == 3);
	assert(pqSize(&q) == 0);

	pqCleanUp(&q);
}

void test_bigger() {
	printf("Testing bigger queue\n");

	MinHeap q = pqNew(10);

	const int num_elms = 50;

	int elms[num_elms] = { 76, 21, 26, 52, 15, 16, 24, 85, 68, 80, 21, 91, 65,
		69, 53, 23, 45, 12, 81, 69, 1,92, 34, 9, 10, 73, 21, 64, 21, 83, 31,
		70, 23, 53, 97, 88, 64, 51, 84, 2, 59, 42, 1, 3, 8, 54, 51, 92, 30, 31 };

	int sorted[num_elms] = { 1, 1, 2, 3, 8, 9, 10, 12, 15, 16, 21, 21, 21, 21,
		23, 23, 24, 26, 30, 31, 31, 34, 42, 45, 51, 51, 52, 53, 53, 54, 59, 64,
		64, 65, 68, 69, 69, 70, 73, 76, 80, 81, 83, 84, 85, 88, 91, 92, 92, 97 };

	for (int i=0; i<num_elms; ++i) {
		pqAdd(&q, elms[i]);
	}

	for (int i=0; i<num_elms; ++i) {
		assert(pqSize(&q) == num_elms - i);
		assert(pqTop(&q)  == sorted[i]);
		assert(pqPop(&q)  == sorted[i]);
	}

	assert(pqSize(&q) == 0);

	pqCleanUp(&q);
}

int main() {
	test_small();
	test_grow();
	test_bigger();

	return 0;
}

