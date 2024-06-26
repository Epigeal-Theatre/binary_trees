#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree.
 *
 * @tree: double ptr to the root node of the BST to insert val.
 *
 * @value: val to store in the node.
 *
 * Return: ptr to the created node or otherwise NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp = *tree;
	bst_t *second = NULL;
	bst_t *new = binary_tree_node(NULL, value);

	if (*tree == NULL)
		*tree = new;

	while (tmp)
	{
		second = tmp;
		if (value < tmp->n)
			tmp = tmp->left;
		else if (value > tmp->n)
			tmp = tmp->right;
		else if (value == tmp->n)
			return (NULL);
	}

	if (second == NULL)
		second = new;
	else if (value < second->n)
	{
		second->left = new;
		new->parent = second;
	}
	else
	{
		second->right = new;
		new->parent = second;
	}

	return (new);
}

/**
 * avl_insert - insert a value in an AVL Tree.
 *
 * @tree: double ptr to root node of the AVL tree.
 *
 * @value: val to insert.
 *
 * Return: ptr to the created node NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance = 0;

	avl_t *node = bst_insert(tree, value);

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));
	if (balance < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));
	if (balance > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (balance < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}

	return (node);
}
