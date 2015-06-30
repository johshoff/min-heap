#include <stdlib.h>
#include <string.h>

struct MinHeap {
	int size;
	int capacity;
	int* elements;
};

typedef struct MinHeap MinHeap;

MinHeap pqNew(int initialCapacity) {
	MinHeap pq;
	pq.size = 0;
	pq.capacity = initialCapacity > 0 ? initialCapacity : 1;
	pq.elements = malloc(pq.capacity * sizeof(int));
	return pq;
}

// clean up, not delete/free, as it doesn't delete the structure itself
void pqCleanUp(MinHeap *q) {
	free(q->elements);

	q->size = 0;
	q->capacity = 0;
	q->elements = NULL;
}

int pqSize(MinHeap *q) {
	return q->size;
}

void pqAdd(MinHeap *q, int element) {
	int pos = q->size; // where the added elements is inserted

	q->size++;
	if (q->size > q->capacity) {
		// we need to grow the queue
		int  new_capacity = q->capacity * 2;
		int* new_elements = malloc(new_capacity * sizeof(int));
		memcpy(new_elements, q->elements, (q->size - 1) * sizeof(int));
		free(q->elements);

		q->capacity = new_capacity;
		q->elements = new_elements;
	}

	q->elements[pos] = element;

	// bubble up
	while (pos > 0) {
		int parent_pos = (pos - 1) / 2; // see description of elements array in README

		int value_at_pos    = q->elements[pos];
		int value_at_parent = q->elements[parent_pos];

		if (value_at_pos < q->elements[parent_pos]) {
			q->elements[pos] = value_at_parent;
			q->elements[parent_pos] = value_at_pos;

			// bubble up parent_pos (this would be the recursion)
			pos = parent_pos;
		}
		else {
			// we're as high as we should be
			break;
		}
	}
}

int pqPop(MinHeap *q) {
	int top = q->elements[0];
	int pos = 0;

	// shrink the queue and move the element outside the queue to the top
	q->size--;
	q->elements[pos] = q->elements[q->size];

	// bubble the top element down
	while (1) {
		// position of children
		int left_pos  = pos * 2 + 1;
		int right_pos = pos * 2 + 2;

		int smallest_value;
		int index_of_smallest;

		if (right_pos < q->size) {
			// right and left are valid
			int left_value  = q->elements[left_pos];
			int right_value = q->elements[right_pos];

			if (left_value < right_value) {
				smallest_value = left_value;
				index_of_smallest = left_pos;
			}
			else {
				smallest_value = right_value;
				index_of_smallest = right_pos;
			}
		}
		else if (left_pos < q->size) {
			// only left is valid
			smallest_value = q->elements[left_pos];
			index_of_smallest = left_pos;
		}
		else {
			// we're at the bottom
			break;
		}

		if (smallest_value < q->elements[pos]) {
			q->elements[index_of_smallest] = q->elements[pos];
			q->elements[pos] = smallest_value;
			pos = index_of_smallest;
		}
		else
			break;
	}

	return top;
}

int pqTop(MinHeap *q) {
	return q->elements[0];
}
