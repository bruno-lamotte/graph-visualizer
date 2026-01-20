/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 06:43:46 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/20 07:47:17 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>


int compare_states(t_state *a, t_state *b)
{
    if (a->x != b->x)
		return (a->x - b->x);
    if (a->y != b->y)
		return (a->y - b->y);
    return (ft_memcmp(a->block_data, b->block_data, a->data_size));
}

int	bst_search(t_bst *tree, t_state *futur)
{
	int	direction;

	while (tree)
	{
		direction = compare_states((tree->state), futur);
		if (!direction)
			return (1);
		if (direction > 0)
			tree = tree->left;
		else
			tree = tree->right;
	}
	return (0);
}

void	bst_insert(t_bst *tree, t_state *new)
{
	t_bst	*temp;
	int		direction;

	temp = tree;
	while (tree)
	{
		direction = compare_states((tree->state), new);
		if (direction > 0)
			tree = tree->left;
		else
			tree = tree->right;
	}
	temp->state = new;
	temp->left = NULL;
	temp->right = NULL;
}

