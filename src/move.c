/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:05:43 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/27 11:54:03 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

t_state	*new_state(void)
{
	t_state	*new;

	new = malloc(sizeof(t_state));
	if (!new)
		return (NULL);
	new->state_index = 0;
	new->x = 0;
	new->y = 0;
	ft_bzero(new->block_data, sizeof(new->block_data));
	new->adjacencies = NULL;
	return (new);
}

void	free_state(t_state *state)
{
	if (!state)
		return ;
	if (state->adjacencies)
		ft_lstclear(&state->adjacencies, free);
	free(state);
}

t_state	*create_futur_state(t_state *actual, int x, int y)
{
	t_state	*futur;

	futur = new_state();
	if (!futur)
		return (NULL);
	ft_memcpy(futur->block_data, actual->block_data, sizeof(futur->block_data));
	futur->x = x;
	futur->y = y;
	return (futur);
}

int is_blocked(int current_pos, int target_pos, t_map_content *map, t_state *current)
{
    int data_state;
    int byte_index;
    int bit_index;

    if (map->map[target_pos] == WALL_CHAR)
        return (1);
    if (map->map[current_pos] == HOLE_CHAR)
        return (1);
    data_state = map->data_positions[current_pos];
    if (data_state && map->map[current_pos] == BREAKABLE_CHAR)
    {
        byte_index = (data_state) / 64;
        bit_index = (data_state) % 64;
        if ((current->block_data[byte_index] >> bit_index) & 1ULL)
            return (1);
    }
    return (0);
}

int	get_xy(t_state *actual, int *x, int *y, int move, t_map_content *map)
{
	int	new_position;
	int	width;
	int	original_position;

	width = map->width;
	original_position = actual->y * width + actual->x;
	new_position = original_position;
	if (move == UP)
		while (!is_blocked(new_position, new_position - width, map, actual))
			new_position -= width;
	if (move == RIGHT)
		while (!is_blocked(new_position, new_position + 1, map, actual))
			new_position += 1;
	if (move == DOWN)
		while (!is_blocked(new_position, new_position + width, map, actual))
			new_position += width;
	if (move == LEFT)
		while (!is_blocked(new_position, new_position - 1, map, actual))
			new_position -= 1;
	*x = new_position % width;
	*y = new_position / width;
	return (*x > 0 && *y > 0 && new_position != original_position);
}

int	get_step(t_state *actual, t_state *futur, t_map_content *map)
{
	if (actual->x == futur->x)
	{
		if (actual->y < futur->y)
			return (map->width);
		else
			return (-map->width);
	}
	if (actual->x < futur->x)
		return (1);
	if (actual->x > futur->x)
		return (-1);
	return (0);
}

void	actualize_bitmask(t_state *actual, t_state *futur, t_map_content *map)
{
	int	step;
	int	position;
	int data_state;
	int byte_index;
	int bit_index;

	step = get_step(actual, futur, map);
	position = actual->y * map->width + actual->x;
	while (position != (futur->y * map->width + futur->x) + step)
	{
		data_state = map->data_positions[position];
		if (data_state)
		{
			byte_index = (data_state - 1) / 64;
			bit_index = (data_state - 1) % 64;
			futur->block_data[byte_index] |= (1ULL << bit_index);
		}
		position += step;
	}
}

t_state	*move(t_state *actual, int move, t_map_content *map)
{
	t_state	*futur;
	int		new_x;
	int		new_y;

	new_x = 0;
	new_y = 0;
	
	if (move == UP || move == RIGHT || move == DOWN || move == LEFT)
		if (!get_xy(actual, &new_x, &new_y, move, map))
			return (NULL);
	futur = create_futur_state(actual, new_x, new_y);
	if (!futur)
		return (NULL);
	actualize_bitmask(actual, futur, map);
	return (futur);
}
