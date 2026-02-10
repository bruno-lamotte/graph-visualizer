/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/10 14:22:49 by blamotte         ###   ########.fr       */
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
		return (print_error(MAP_DO_NOT_EXIST_ERROR), 0);
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		return (print_error(MAP_DO_NOT_EXIST_ERROR), 0);
	return (1);
}

void	free_palestine(t_bst *tree, char **adjacency, int nb_state)
{
	if (adjacency)
		free_adjacency_matrice(adjacency, nb_state);
	if (tree->left)
		free_bst(tree->left);
	if (tree->right)
		free_bst(tree->right);
	if (tree->state)
		free_state(tree->state);
}

long long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_error(int error_type)
{
	if (error_type == MAP_NOT_RECTANGULAR_ERROR)
		write(2, "Error: Map is not rectangular\n", 30);
	else if (error_type == MAP_NOT_SURROUNDED_ERROR)
		write(2, "Error: Map is not surrounded by walls\n", 38);
	else if (error_type == EXIT_PLAYER_COLLECTIBLE_ERROR)
	{
		write(2, "Error: Map must contain exactly one exit", 35);
		write(2, " and player and at least one collectible\n", 41);
	}
	else if (error_type == INVALID_CHAR_ERROR)
		write(2, "Error: Map contains invalid characters\n", 39);
	else if (error_type == MAP_NOT_SOLVABLE_ERROR)
		write(2, "Error: Map is not solvable\n", 28);
	else if (error_type == WRONG_ARGUMENT_NUMBER_ERROR)
		write(2, "Error: Wrong number of arguments\n", 33);
	else if (error_type == MAP_DO_NOT_EXIST_ERROR)
		write(2, "Error: Map file does not exist\n", 32);
	else if (error_type == TOO_MUCH_DATA_ERROR)
		write(2, "Error: Too much collectibles or breakables\n", 43);
}

int	get_min_possible_moves(t_state *last_state)
{
	int	min_moves;

	min_moves = 0;
	while (last_state)
	{
		min_moves++;
		last_state = last_state->parent;
	}
	return (min_moves);
}
