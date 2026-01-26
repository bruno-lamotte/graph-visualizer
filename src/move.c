/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:05:43 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/26 04:10:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

t_state	*new_state(int nb_possible_states)
{
	t_state	*new;

	new = malloc(sizeof(t_state));
	if (!new)
		return (NULL);
	new->state_index = 0;
	new->x = 0;
	new->y = 0;
	new->data_size = nb_possible_states;
	new->block_data = ft_calloc(nb_possible_states + 1, sizeof(char));
	if (!new->block_data)
		return (NULL);
	new->adjacencies = NULL;
	return (new);
}

void	free_state(t_state *state)
{
	if (!state)
		return ;
	if (state->block_data)
		free(state->block_data);
	if (state->adjacencies)
		ft_lstclear(&state->adjacencies, free);
	free(state);
}

t_state	*create_futur_state(t_state *actual, int x, int y)
{
	t_state	*futur;

	futur = new_state(actual->data_size);
	if (!futur)
		return (NULL);
	ft_memcpy(futur->block_data, actual->block_data, actual->data_size);
	futur->x = x;
	futur->y = y;
	return (futur);
}

int is_blocked(int target_pos, t_map_content *map, t_state *current)
{
    int data_state;
    int byte_index;
    int bit_index;

    if (map->map[target_pos] == WALL_CHAR)
        return (1);
    data_state = map->data_positions[target_pos];
    if (data_state)
    {
        byte_index = (data_state - 1) / 8;
        bit_index = (data_state - 1) % 8;
        if ((current->block_data[byte_index] >> bit_index) & 1)
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
		while (!is_blocked(new_position - width, map, actual))
			new_position -= width;
	if (move == RIGHT)
		while (!is_blocked(new_position + 1, map, actual))
			new_position += 1;
	if (move == DOWN)
		while (!is_blocked(new_position + width, map, actual))
			new_position += width;
	if (move == LEFT)
		while (!is_blocked(new_position - 1, map, actual))
			new_position -= 1;
	*x = new_position % width;
	*y = new_position / width;
	return (*x > 0 && *y > 0 && new_position != original_position);
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
	futur = create_futur_state(actual, new_x , new_y);
	if (!futur)
		return (NULL);
	return (futur);
}
