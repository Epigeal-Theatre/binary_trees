#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibling of a node.
 *
 * @node: ptr  to the node to find the sibling.
 *
 * Return: pointer to the sibling node...or
 *
 *...NULL if node is NULL...or
 *...NULL if the parent is NULL or...
 *.NULL if the node has no siblings.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
