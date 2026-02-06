/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:08:49 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/05 20:55:39 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

void	complete_adjacency_matrice(t_bst *tree, char ***adj)
{
	t_list	*current;

	if (!tree || !tree->state)
	return ;
current = tree->state->adjacencies;
while (current && current->content)
{
	(*adj)[tree->state->state_index][*(int *)current->content] = '1';
		current = current->next;
	}
	if (tree->right)
	complete_adjacency_matrice(tree->right, adj);
if (tree->left)
complete_adjacency_matrice(tree->left, adj);
}

char	**make_adjacency_matrice(t_bst *tree, int nb_state)
{
	char	**adjacency;
	int		i;
	
	adjacency = ft_calloc(nb_state + 1, sizeof(char *));
	if (!adjacency)
		return (NULL);
	i = 0;
	while (i < nb_state)
	{
		adjacency[i] = ft_calloc(nb_state + 1, sizeof(char));
		if (!adjacency[i])
			return (NULL);
		i++;
	}
	complete_adjacency_matrice(tree, &adjacency);
	return (adjacency);
}

void	free_adjacency_matrice(char **adjacency, int nb_state)
{
	int	i;

	if (!adjacency)
		return ;
	i = 0;
	while (i < nb_state)
	{
		if (adjacency[i])
			free(adjacency[i]);
		i++;
	}
	free(adjacency);
}

void	print_adjacency_matrice(char **adjacency, int nb_state)
{
	int	x;
	int	y;

	y = 0;
	while (y < nb_state)
	{
		x = 0;
		while (x < nb_state)
		{
			if (adjacency[y][x] == '1')
				write(1, "1 ", 2);
			else
				write(1, "0 ", 2);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}


