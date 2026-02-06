/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:52:17 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/06 03:39:41 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

int	get_line(char **out, char *line, t_map_content *map)
{
	char	*tmp;

	map->height++;
	tmp = *out;
	if (*out)
		*out = ft_strjoin(tmp, line);
	else
		*out = ft_strdup(line);
	if (tmp)
		free(tmp);
	if ((int)ft_strlen(line) != map->width)
		return (0);
	if (!*out)
		return (0);
	free(line);
	return (1);
}

char	*get_map(int ac, char **av, t_map_content *map)
{
	int		fd;
	char	*line;
	char	*out;

	out = NULL;
	if (!check_extension(av[ac - 1]))
		return (NULL);
	fd = open(av[ac - 1], O_RDONLY);
	line = get_next_line(fd);
	map->width = ft_strlen(line);
	map->height = 0;
	while (line)
	{
		if (!get_line(&out, line, map))
			return (NULL);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (!parsing_map(out, map))
		return (free(out), close(fd), NULL);
	return (close(fd), out);
}

int	initialize_all(t_queue *q, t_bst *tree, t_map_content *map)
{
	t_state	*first_state;
	t_qnode	*first_qnode;

	first_state = new_state();
	first_qnode = malloc(sizeof(t_qnode));
	if (!first_state || !first_qnode)
		return (0);
	first_state->y = map->initial_position / map->width;
	first_state->x = map->initial_position % map->width;
	first_qnode->state = first_state;
	first_qnode->next = NULL;
	tree->left = NULL;
	tree->right = NULL;
	tree->state = first_state;
	q->front = first_qnode;
	q->rear = first_qnode;
	return (1);
}

int	is_solvable(int ac, char **av, t_map_content *map, int is_test)
{
	int		nb_state;
	t_queue	q;
	t_bst	tree;
	char	**adjacency;

	adjacency = NULL;
	if (ac == 2)
		map->map = get_map(ac, av, map);
	if (!map->map)
		return (0);
	if (!initialize_all(&q, &tree, map))
		return (0);
	nb_state = bfs(&q, &tree, map);
	if (!nb_state)
		return (free_palestine(&tree, adjacency, nb_state), 0);
	if (is_test)
		adjacency = make_adjacency_matrice(&tree, nb_state);
	if (adjacency)
		print_adjacency_matrice(adjacency, nb_state);
	free_palestine(&tree, adjacency, nb_state);
	return (nb_state);
}
