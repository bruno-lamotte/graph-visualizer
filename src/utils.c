/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/06 03:31:55 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

int	check_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

void	free_palestine(t_bst *tree, char **adjacency, int nb_state)
{
	free_adjacency_matrice(adjacency, nb_state);
	free_bst(tree->left);
	free_bst(tree->right);
	free_state(tree->state);
}
