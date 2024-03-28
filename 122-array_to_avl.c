#include "binary_trees.h"

/**
 * array_to_avl - build an AVL tree from an array.
 *
 * @array: the arr to create from
 *
 * @size: the size of the arr.
 *
 * Return: ptr to the root node of the created AVL tree
 * or return NULL on failure
 */

avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int i;

	avl_t *root = NULL;

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
