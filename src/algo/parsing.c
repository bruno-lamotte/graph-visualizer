/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/10 12:46:03 by blamotte         ###   ########.fr       */
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
		|| c == COLECTIBLE_CHAR || c == BREAKABLE_CHAR || c == HOLE_CHAR
		|| c == '\n')
		return (1);
	return (print_error(INVALID_CHAR_ERROR), 0);
}

int	is_map_valid(char *out, t_map_content *map)
{
	int	i;

	i = 0;
	if (!out)
		return (0);
	while (out[i])
	{
		if ((i < map->width || i > (int)ft_strlen(out) - map->width || i
				% map->width == 0 || i % map->width == map->width - 1)
			&& out[i] != WALL_CHAR && out[i] != '\n')
			return (print_error(MAP_NOT_SURROUNDED_ERROR), 0);
		else if (!is_acceptable_char(out[i]))
			return (0);
		i++;
	}
	return (1);
}

int	count_special_char(char *out, t_map_content *map)
{
	int	count;
	int	i;
	int	byte_index;
	int	bit_index;

	count = 1;
	i = 0;
	while (out[i])
	{
		if (out[i] == COLECTIBLE_CHAR || out[i] == BREAKABLE_CHAR)
			map->data_positions[i] = count++;
		if (count >= MAX_DATA_CHUNKS * 64)
			return (-1);
		if (out[i] == COLECTIBLE_CHAR)
		{
			byte_index = (map->data_positions[i] - 1) / 64;
			bit_index = (map->data_positions[i] - 1) % 64;
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
		return (free(out), 0);
	map->initial_position = find_char_index(out, INITIAL_CHAR);
	map->exit_position = find_char_index(out, EXIT_CHAR);
	if (find_char_index(out + map->initial_position + 1, INITIAL_CHAR)
		|| find_char_index(out + map->exit_position + 1, EXIT_CHAR)
		|| !find_char_index(out, COLECTIBLE_CHAR))
		return (print_error(EXIT_PLAYER_COLLECTIBLE_ERROR), free(out), 0);
	if (!(map->initial_position) || (!map->exit_position))
		return (print_error(EXIT_PLAYER_COLLECTIBLE_ERROR), free(out), 0);
	if (!is_map_valid(out, map))
		return (free(out), 0);
	ft_bzero(map->exit_mask, sizeof(map->exit_mask));
	if (count_special_char(out, map) < 0)
		return (print_error(TOO_MUCH_DATA_ERROR), free(out), 0);
	return (1);
}
