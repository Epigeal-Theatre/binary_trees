#include "binary_trees.h"

/**
 * binary_tree_inorder - func will go through a binary tree using in-order traversal.
 *
 * @tree: the tree to be traversed.
 *
 * @func: ptr to a function to call for each node.
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
