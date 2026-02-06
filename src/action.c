/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:44:32 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/31 08:13:29 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

int	is_exit(t_state *current, t_map_content *map)
{
	int	i;

	if (current->y * map->width + current->x != map->exit_position)
		return (0);
	i = 0;
	while (i < MAX_DATA_CHUNKS)
	{
		if ((current->block_data[i] & map->exit_mask[i]) != map->exit_mask[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_hole(t_state *current, t_map_content *map)
{
	int data_state;
    int byte_index;
    int bit_index;
	int target_pos;

	target_pos = current->y * map->width + current->x;
	if (map->map[target_pos] == HOLE_CHAR)
		return (1);
    data_state = map->data_positions[target_pos];
    if (data_state && map->map[target_pos] == BREAKABLE_CHAR)
    {
        byte_index = (data_state - 1) / 64;
        bit_index = (data_state - 1) % 64;
        if ((current->block_data[byte_index] >> bit_index) & 1)
            return (1);
    }
    return (0);
}