#include "binary_trees.h"

/**
 * bst_search - search for a value in a Binary Search Tree.
 *
 * @tree: pointer to the root node of the BST to search.
 *
 * @value: val to search in the tree.
 *
 * Return: A pointer to the node containing an int equal to `value`.
 * return NULL if tree is NULL
 * return NULL if no match is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (node)
	{
		if (value == node->n)
			return (node);
		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
	}

	return (NULL);
}
