/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:52:17 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/27 11:20:56 by blamotte         ###   ########.fr       */
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

int	is_acceptable_char(char c)
{
	if (c == WALL_CHAR || c == INITIAL_CHAR || c == EXIT_CHAR || c == EMPTY_CHAR
		|| c == COLECTIBLE_CHAR || c == BREAKABLE_CHAR || c == HOLE_CHAR)
		return (1);
	return (0);
}
int	is_map_valid(char *out, t_map_content *map)
{
	int	i;

	i = 0;
	if (!out)
		return (0);
	while (out[i])
	{
		if ((i < map->width || i > (int)ft_strlen(out) - map->width
			|| i % map->width == 0 || i % map->width == map->width - 1)
			&& out[i] != WALL_CHAR && out[i] != '\n')
			return (0);
		else if (!is_acceptable_char(out[i]) && out[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	count_special_char(char *out, t_map_content *map)
{
	int	count;
	int	i;
	int byte_index;
    int bit_index;

	count = 1;
	i = 0;
	while (out[i])
	{
		if (out[i] == COLECTIBLE_CHAR || out[i] == BREAKABLE_CHAR)
			map->data_positions[i] = count++;
		if (out[i] == COLECTIBLE_CHAR)
		{
			byte_index = (map->data_positions[i]) / 64;
			bit_index = (map->data_positions[i]) % 64;
			map->exit_mask[byte_index] |= (1ULL << bit_index);
		}
		i++;
	}
	return (count);
}

int	parsing_map(char *out, t_map_content *map)
{
	if (!out)
		return (0);
	map->data_positions = ft_calloc(ft_strlen(out), sizeof(int));
	if (!map->data_positions)
		return (0);
	map->initial_position = find_char_index(out, INITIAL_CHAR);
	if (find_char_index(out, INITIAL_CHAR + map->initial_position + 1) || 
		find_char_index(out, EXIT_CHAR + map->exit_position + 1))
		return (0);
	map->exit_position = find_char_index(out, EXIT_CHAR);
	if (!(map->initial_position) || (!map->exit_position) || (!is_map_valid(out, map)))
		return (0);
	ft_bzero(map->exit_mask, sizeof(map->exit_mask));
	if (count_special_char(out, map) >= 256)
		return (0);
	return (1);
}

int check_extension(char *filename)
{
    int len;

    if (!filename)
        return (0);
    len = ft_strlen(filename);
    if (len < 4)
        return (0);
    if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
        return (0);
    return (1);
}

char	*get_map(int ac, char **av, t_map_content *map)
{
	int		fd;
	char	*line;
	char	*out;
	char	*tmp;
	
	out = NULL;
	if (!check_extension(av[ac - 1]))
		return (NULL);
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
	if (line)
		free(line);
	if (!parsing_map(out, map))
	{
		free(out);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (out);
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
	q->rear	= first_qnode;
	return (1);
}
void	free_palestine(t_bst *tree, t_map_content *map, char **adjacency, int nb_state)
{
	free_adjacency_matrice(adjacency, nb_state);
	free_bst(tree->left);
	free_bst(tree->right);
	free_state(tree->state);
	free(map->map);
	free(map->data_positions);
}

int main (int ac, char **av)
{
	t_map_content	map;
	int				nb_state;
	t_queue			q;
	t_bst			tree;
	char			**adjacency;
	
	if (ac > 2 || ac < 2)
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
		print_adjacency_matrice(adjacency, nb_state);
	free_palestine(&tree, &map, adjacency, nb_state);
	return (0);
}
