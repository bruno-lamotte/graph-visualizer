/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:52:17 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/20 10:19:19 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

int	find_char_index(char *line, char c)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	count_special_char(char *out)
{
	(void)out;
	return (0);
}

int	parsing_map(char *out, t_map_content *map)
{
	map->initial_position = find_char_index(out, INITIAL_CHAR);
	map->exit_position = find_char_index(out, EXIT_CHAR);
	if (!(map->initial_position) || (!map->exit_position))
		return (0);
	map->data_size = count_special_char(out);
	return (1);
}

char	*get_map(int ac, char **av, t_map_content *map)
{
	int		fd;
	char	*line;
	char	*out;
	char	*tmp;
	
	out = NULL;
	fd = open(av[ac - 1], O_RDONLY);
	line = get_next_line(fd);
	map->width = ft_strlen(line);
	while (line)
	{
		tmp = out;
		if (out)
			out = ft_strjoin(tmp, line);
		else 
			out = ft_strdup(line);
		if (tmp)
			free(tmp);
		if ((int)ft_strlen(line) != map->width)
			return (NULL);
		if (!out)
			return (NULL);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (!parsing_map(out, map))
		return (NULL);
	close(fd);
	return (out);
}

int	initialize_all(t_queue *q, t_bst *tree, t_map_content *map)
{
	t_state	*first_state;
	t_qnode	*first_qnode;

	first_state = new_state(map->data_size);
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
	q->rear	= first_qnode;
	return (1);
}

int main (int ac, char **av)
{
	//ft_printf("bjr/n");
	t_map_content	map;
	int				nb_state;
	t_queue			q;
	t_bst			tree;
	char			**adjacency;
	
	if (ac > 2 || ac < 1)
		return (0);
	map.map = get_map(ac, av, &map);
	if (!map.map)
		return (0);
	if (!initialize_all(&q, &tree, &map))
		return (0);
	nb_state = bfs(&q, &tree, &map);
	if (!nb_state)
		return (0);
	adjacency = make_adjacency_matrice(&tree, nb_state);
	if (adjacency)
		print_adjacency_matrice(adjacency);
	return (0);
}
