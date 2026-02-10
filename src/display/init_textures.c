/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/10 10:31:38 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	initialize_textures_2(t_vars *vars)
{
	void	*mlx;
	int		w;
	int		h;

	w = 32;
	h = 32;
	mlx = vars->mlx;
	vars->textures.exit = mlx_xpm_file_to_image(mlx, "./textures/exit.xpm", &w,
			&h);
	if (!vars->textures.exit)
		close_program(vars);
	vars->textures.fragile_floor = mlx_xpm_file_to_image(mlx,
			"./textures/breackable.xpm", &w, &h);
	if (!vars->textures.fragile_floor)
		close_program(vars);
	vars->textures.hole = mlx_xpm_file_to_image(mlx, "./textures/hole.xpm", &w,
			&h);
	if (!vars->textures.hole)
		close_program(vars);
	init_player_textures(vars, mlx, &w, &h);
	init_coin_textures(vars, mlx, &w, &h);
	init_exit_textures(vars, mlx, &w, &h);
	init_break_textures(vars, mlx, &w, &h);
	init_hole_textures(vars, mlx, &w, &h);
}

void	initialize_textures(t_vars *vars)
{
	void	*mlx;
	int		w;
	int		h;

	w = 32;
	h = 32;
	mlx = vars->mlx;
	vars->textures.wall = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &w,
			&h);
	if (!vars->textures.wall)
		close_program(vars);
	vars->textures.floor = mlx_xpm_file_to_image(mlx, "./textures/floor.xpm",
			&w, &h);
	if (!vars->textures.floor)
		close_program(vars);
	vars->textures.player = mlx_xpm_file_to_image(mlx,
			"./textures/playerdown1.xpm", &w, &h);
	if (!vars->textures.player)
		close_program(vars);
	vars->textures.collectible = mlx_xpm_file_to_image(mlx,
			"./textures/coin.xpm", &w, &h);
	if (!vars->textures.collectible)
		close_program(vars);
	initialize_textures_2(vars);
}
