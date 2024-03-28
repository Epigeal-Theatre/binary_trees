#include "binary_trees.h"

/**
 * binary_tree_is_heap - check if binary tree is a valid Max BinaryHeap.
 *
 * @tree: ptr to root node of thetree
 *
 * Return: 1 if tree is a valid Max Binary Heap...or
 *... 0 if tree is NULL...or still return
 * 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btih_helper(tree));
}

/**
 * btih_helper - check if a binary tree is a valid Max Binary Heap.
 *
 * @tree: ptr to the root node of the tree
 *
 * Return: 1 if tree is a valid Max Binary Heap... or
 * ...1 if tree is NULL
 * or still 0 otherwise
 */
int btih_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (btih_helper(tree->left) &&
		btih_helper(tree->right));
}

/**
 * binary_tree_is_complete - check if a binary tree is complete.
 *
 * @tree: ptr to the root node of the tree.
 *
 * Return: 1 if the tree is complete
 *
 *...or  0 if the tree is not complete
 * ... or still 0 if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (btic_helper(tree, 0, size));
}

/**
 * btic_helper - check if a binary tree is complete.
 *
 * @tree:  ptr to the root node of the tree to check.
 *
 * @index: node index to check.
 *
 * @size: number of nodes in the tree.
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (btic_helper(tree->left, 2 * index + 1, size) &&
		btic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - measure the size of a binary tree.
 *
 * @tree: the tree that we want to measure the size
 *
 * Return: size of the tree or otherwise 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
