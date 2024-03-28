#include "binary_trees.h"

/**
 * binary_tree_insert_left - func will insert  node as the left-child of another node
 *
 * @parent: ptr to the node into which we'll insert the left-child
 *
 * @value: value to be input in the new node
 *
 * Return: Ptr to the newly created node
 *         or NULL upon failure
 *         or still NULL if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
	return (NULL);

	
	new = malloc(sizeof(binary_tree_t));
	if (!new)
	return (NULL);

	new->n = value;
	new->parent = parent;
	new->right = NULL;
	new->left = parent->left;
	parent->left = new;

	if (new->left)
		new->left->parent = new;
	return (new);
}
