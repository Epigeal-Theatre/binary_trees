#include "binary_trees.h"

/**
 * bst_remove - remove  node from a Binary Search Tree
 *
 * @root: pointer to the root node of the tree where we remove a node.
 *
 * @value: val to remove in the tree.
 *
 * Return: ptr to the new root node of the tree after removal
 * or return NULL on failure.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (!root->right)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}
		tmp = bst_min_val(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}

/**
 * bst_min_val - find the smallest node from Binary Search Tree.
 *
 * @root: ptr to the root node of the tree.
 *
 * Return: ptr to the smallest node.
 */
bst_t *bst_min_val(bst_t *root)
{
	bst_t *min = root;

	while (min->left)
		min = min->left;

	return (min);
}
