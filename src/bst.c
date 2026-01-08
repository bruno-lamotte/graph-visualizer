/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 06:43:46 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/08 07:52:30 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




int compare_states(t_state *a, t_state *b)
{
    if (a->x != b->x)
		return (a->x - b->x);
    if (a->y != b->y)
		return (a->y - b->y);
    return (ft_memcmp(a->block_data, b->block_data, DATA_SIZE)
}

int	bst_search(t_bst **tree, t_state *futur)
{
	int	direction;

	while (tree)
	{
		direction = compare_state((tree->state), futur);
		if (!direction)
			return (1);
		if (direction > 0)
			tree = tree->left;
		else
			tree = tree->right;
	}
	return (0);
}

void	bst_insert(t_bst **tree, t_state *new)
{
	t_bst *temp;

	temp = *tree;
	while (tree)
	{
		direction = compare_state((tree->state), new);
		if (direction > 0)
			tree = tree->left;
		else
			tree = tree->right;
	}
	temp->state = new;
	temp->left = NULL;
	temp->right = NULL;
}

