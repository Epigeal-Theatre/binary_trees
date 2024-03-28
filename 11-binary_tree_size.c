#include "binary_trees.h"

/**
 * binary_tree_size - measuret he size of binary tree.
 *
 * @tree: thetree to measure the size of.
 *
 * Return: the size of the tree...
 * or .... 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
