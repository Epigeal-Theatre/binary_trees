#include "binary_trees.h"

/**
 * array_to_bst - build a Binary Search Tree from an array.
 *
 * @array: ptr to the first element of the array to be converted.
 *
 * @size: number of elements in array.
 *
 * Return: ptr to the root node of the created BST. or return
 * ... NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int i;
	bst_t *root = NULL;

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
