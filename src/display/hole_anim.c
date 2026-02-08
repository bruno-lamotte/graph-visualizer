/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hole_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/08 18:36:57 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	render_hole_anim_frame(t_vars *vars)
{
	int		hole_x;
	int		hole_y;
	int		x;
	int		y;
	void	*img;

	y = -1;
	while (++y < vars->map.height)
	{
		x = -1;
		while (++x < vars->map.width)
			if (vars->map.map[y * vars->map.width + x] != '\n')
				render_tile(vars, (t_render_pos){x, y, -100, -100});
	}
	hole_x = vars->current_state->x;
	hole_y = vars->current_state->y;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.floor, hole_x
		* TILE_SIZE, hole_y * TILE_SIZE);
	img = vars->textures.hole_anim[vars->hole_anim.frame];
	mlx_put_image_to_window(vars->mlx, vars->win, img, hole_x * TILE_SIZE,
		hole_y * TILE_SIZE);
	mlx_do_sync(vars->mlx);
}

void	render_hole_last_anim_frame(t_vars *vars)
{
	static int	end_delay;
	int			hole_x;
	int			hole_y;

	hole_x = vars->current_state->x;
	hole_y = vars->current_state->y;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.hole, hole_x
		* TILE_SIZE, hole_y * TILE_SIZE);
	mlx_do_sync(vars->mlx);
	end_delay++;
	if (end_delay >= 3)
	{
		write(1, "GAME OVER\n", 10);
		close_program(vars);
	}
}

int	hole_animation_loop(t_vars *vars)
{
	static long long	last_hole_time;
	static int			start_delay;
	long long			now;

	if (!vars->hole_anim.active)
		return (0);
	now = get_timestamp();
	if (now - last_hole_time < 200)
		return (0);
	last_hole_time = now;
	if (vars->hole_anim.frame >= vars->hole_anim.total_frames)
		return (render_hole_last_anim_frame(vars), 0);
	render_hole_anim_frame(vars);
	if (vars->hole_anim.frame == 1 && start_delay < 3)
	{
		start_delay++;
		return (0);
	}
	vars->hole_anim.frame++;
	return (0);
}
