/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_actions_on_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/08 20:35:13 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	collect_tile(t_vars *vars, int index)
{
	int	data_id;
	int	byte_index;
	int	bit_index;

	data_id = vars->map.data_positions[index];
	if (data_id)
	{
		byte_index = (data_id - 1) / 64;
		bit_index = (data_id - 1) % 64;
		vars->current_state->block_data[byte_index] |= (1ULL << bit_index);
		if (vars->next_state)
			vars->next_state->block_data[byte_index] |= (1ULL << bit_index);
	}
}

int	is_collected(t_vars *vars, int index)
{
	int	data_id;
	int	byte;
	int	bit;

	data_id = vars->map.data_positions[index];
	if (data_id == 0)
		return (0);
	byte = (data_id - 1) / 64;
	bit = (data_id - 1) % 64;
	return ((vars->current_state->block_data[byte] >> bit) & 1ULL);
}

int	is_on_path(t_vars *vars, int tile_x, int tile_y)
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;

	start_x = vars->anim.start_x;
	start_y = vars->anim.start_y;
	(1 && (end_x = vars->anim.end_x), (end_y = vars->anim.end_y));
	if (vars->anim.direction == UP || vars->anim.direction == DOWN)
	{
		if (tile_x != start_x)
			return (0);
		if (start_y < end_y)
			return (tile_y >= start_y && tile_y <= end_y);
		return (tile_y >= end_y && tile_y <= start_y);
	}
	if (vars->anim.direction == LEFT || vars->anim.direction == RIGHT)
	{
		if (tile_y != start_y)
			return (0);
		if (start_x < end_x)
			return (tile_x >= start_x && tile_x <= end_x);
		return (tile_x >= end_x && tile_x <= start_x);
	}
	return (0);
}

int	is_passed(t_vars *vars, int index, t_render_pos pos)
{
	int	tile_x;
	int	tile_y;
	int	tile_center_x;
	int	tile_center_y;

	tile_x = index % vars->map.width;
	tile_y = index / vars->map.width;
	if (!is_on_path(vars, tile_x, tile_y))
		return (0);
	tile_center_x = tile_x * TILE_SIZE + TILE_SIZE / 2;
	tile_center_y = tile_y * TILE_SIZE + TILE_SIZE / 2;
	if (vars->anim.direction == UP)
		return (pos.player_px_y + TILE_SIZE / 2 <= tile_center_y);
	else if (vars->anim.direction == DOWN)
		return (pos.player_px_y + TILE_SIZE / 2 >= tile_center_y);
	else if (vars->anim.direction == LEFT)
		return (pos.player_px_x + TILE_SIZE / 2 <= tile_center_x);
	else if (vars->anim.direction == RIGHT)
		return (pos.player_px_x + TILE_SIZE / 2 >= tile_center_x);
	return (0);
}
