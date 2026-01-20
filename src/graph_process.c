/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:08:49 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/20 08:13:20 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

void	complete_adjacency_matrice(t_bst *tree, char ***adj)
{
	while (tree->state->adjacencies)
	{
		*adj[tree->state->state_index][*(int *)tree->state->adjacencies->content] = 1;
		tree->state->adjacencies = tree->state->adjacencies->next;
	}
	if (tree->right)
		complete_adjacency_matrice(tree->right, adj);
	if (tree->left)
		complete_adjacency_matrice(tree->left, adj);
}

char	**make_adjacency_matrice(t_bst *tree, int nb_state)
{
	char	**adjacency;

	adjacency = ft_calloc(nb_state + 1, sizeof(char *) * nb_state + 1);
	if (!adjacency)
		return (NULL);
	complete_adjacency_matrice(tree, &adjacency);
	return (adjacency);
}

void	print_adjacency_matrice(char **adjacency)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (adjacency[x][y])
	{
		x = 0;
		while (adjacency[x][y])
		{
			write(1, &adjacency[x][y], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}


