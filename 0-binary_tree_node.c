#include "binary_trees.h"

/**
 * binary_tree_node - finc creates a binary tree node
 *
 * @parent: ptr to parent node of node to be created
 *
 * @value: val to put in the new node
 *
 * Return: Pointer to newly created node or
 * ...return NULL upon  failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)

	return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
