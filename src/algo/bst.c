/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 06:43:46 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/10 13:59:37 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

int	compare_states(t_state *a, t_state *b)
{
	if (a->x != b->x)
		return (a->x - b->x);
	if (a->y != b->y)
		return (a->y - b->y);
	return (ft_memcmp(a->block_data, b->block_data, sizeof(a->block_data)));
}

t_state	*bst_search(t_bst *tree, t_state *futur)
{
	int	direction;

	while (tree)
	{
		direction = compare_states((tree->state), futur);
		if (!direction)
			return (tree->state);
		if (direction > 0)
			tree = tree->left;
		else
			tree = tree->right;
	}
	return (NULL);
}

void	free_bst(t_bst *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		free_bst(tree->left);
	if (tree->right)
		free_bst(tree->right);
	if (tree->state)
		free_state(tree->state);
	free(tree);
}

int	bst_insert(t_bst *tree, t_state *new)
{
	t_bst	*new_node;
	int		direction;

	new_node = malloc(sizeof(t_bst));
	if (!new_node)
		return (0);
	new_node->state = new;
	(1 && (new_node->left = NULL), (new_node->right = NULL));
	while (tree)
	{
		direction = compare_states(tree->state, new);
		if (direction > 0)
		{
			if (!tree->left)
				return ((tree->left = new_node), 1);
			tree = tree->left;
		}
		else
		{
			if (!tree->right)
				return ((tree->right = new_node), 1);
			tree = tree->right;
		}
	}
	return (0);
}
