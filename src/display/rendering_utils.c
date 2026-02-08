/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/08 18:36:57 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	update_idle_anims(t_vars *vars)
{
	static long long	last_idle_time;
	long long			now;
	int					px_x;
	int					px_y;

	now = get_timestamp();
	if (now - last_idle_time < 30)
		return ;
	last_idle_time = now;
	px_x = vars->current_state->x * TILE_SIZE;
	px_y = vars->current_state->y * TILE_SIZE;
	render_game_anim(vars, px_x, px_y);
	mlx_do_sync(vars->mlx);
}

void	render_player(t_vars *vars, int steps, int nb_moves)
{
	(void)steps;
	(void)nb_moves;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.player,
		vars->current_state->x * TILE_SIZE,
		vars->current_state->y * TILE_SIZE);
}

int	is_player_on_tile(t_render_pos pos)
{
	int	player_tile_x;
	int	player_tile_y;

	player_tile_x = (pos.player_px_x + TILE_SIZE / 2) / TILE_SIZE;
	player_tile_y = (pos.player_px_y + TILE_SIZE / 2) / TILE_SIZE;
	return (player_tile_x == pos.x && player_tile_y == pos.y);
}

void	*get_player_sprite(t_vars *vars)
{
	int	frame;

	frame = vars->anim.frame;
	if (vars->anim.direction == UP)
		return (vars->textures.player_up[frame]);
	else if (vars->anim.direction == DOWN)
		return (vars->textures.player_down[frame]);
	else if (vars->anim.direction == LEFT)
		return (vars->textures.player_left[frame]);
	else if (vars->anim.direction == RIGHT)
		return (vars->textures.player_right[frame]);
	return (vars->textures.player);
}
