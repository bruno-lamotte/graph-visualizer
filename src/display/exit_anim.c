/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/08 18:36:57 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	render_exit_anim_frame(t_vars *vars)
{
	int		exit_x;
	int		exit_y;
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
	exit_x = vars->map.exit_position % vars->map.width;
	exit_y = vars->map.exit_position / vars->map.width;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.floor, exit_x
		* TILE_SIZE, exit_y * TILE_SIZE);
	img = vars->textures.exit_anim[vars->exit_anim.frame];
	mlx_put_image_to_window(vars->mlx, vars->win, img, exit_x * TILE_SIZE,
		exit_y * TILE_SIZE);
	mlx_do_sync(vars->mlx);
}

int	exit_animation_loop(t_vars *vars)
{
	static long long	last_exit_time;
	static int			end_delay;
	long long			now;

	if (!vars->exit_anim.active)
		return (0);
	now = get_timestamp();
	if (now - last_exit_time < 300)
		return (0);
	last_exit_time = now;
	if (vars->exit_anim.frame >= vars->exit_anim.total_frames)
	{
		end_delay++;
		if (end_delay >= 3)
		{
			write(1, "VICTORY !\n", 10);
			close_program(vars);
		}
		return (0);
	}
	render_exit_anim_frame(vars);
	vars->exit_anim.frame++;
	return (0);
}
