#include "binary_trees.h"

/**
 * array_to_heap - build a Max Binary Heap tree from an arr.
 *
 * @array: ptr to the first element of the array to be converted.
 *
 * @size: the number of element in the arr.
 *
 * Return:ptr to the root node of the created Binary Heap.or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
