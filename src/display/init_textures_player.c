/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/10 10:23:42 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	init_player_textures(t_vars *vars, void *mlx, int *w, int *h)
{
	vars->textures.player_up[0] = mlx_xpm_file_to_image(mlx,
			"./textures/playerup1.xpm", w, h);
	if (!vars->textures.player_up[0])
		close_program(vars);
	vars->textures.player_up[1] = mlx_xpm_file_to_image(mlx,
			"./textures/playerup2.xpm", w, h);
	if (!vars->textures.player_up[1])
		close_program(vars);
	vars->textures.player_up[2] = mlx_xpm_file_to_image(mlx,
			"./textures/playerup3.xpm", w, h);
	if (!vars->textures.player_up[2])
		close_program(vars);
	init_player_textures_down(vars, mlx, w, h);
	init_player_textures_left(vars, mlx, w, h);
	init_player_textures_right(vars, mlx, w, h);
}

void	init_player_textures_down(t_vars *vars, void *mlx, int *w, int *h)
{
	vars->textures.player_down[0] = mlx_xpm_file_to_image(mlx,
			"./textures/playerdown1.xpm", w, h);
	if (!vars->textures.player_down[0])
		close_program(vars);
	vars->textures.player_down[1] = mlx_xpm_file_to_image(mlx,
			"./textures/playerdown2.xpm", w, h);
	if (!vars->textures.player_down[1])
		close_program(vars);
	vars->textures.player_down[2] = mlx_xpm_file_to_image(mlx,
			"./textures/playerdown3.xpm", w, h);
	if (!vars->textures.player_down[2])
		close_program(vars);
}

void	init_player_textures_left(t_vars *vars, void *mlx, int *w, int *h)
{
	vars->textures.player_left[0] = mlx_xpm_file_to_image(mlx,
			"./textures/playerleft1.xpm", w, h);
	if (!vars->textures.player_left[0])
		close_program(vars);
	vars->textures.player_left[1] = mlx_xpm_file_to_image(mlx,
			"./textures/playerleft2.xpm", w, h);
	if (!vars->textures.player_left[1])
		close_program(vars);
	vars->textures.player_left[2] = mlx_xpm_file_to_image(mlx,
			"./textures/playerleft3.xpm", w, h);
	if (!vars->textures.player_left[2])
		close_program(vars);
}

void	init_player_textures_right(t_vars *vars, void *mlx, int *w, int *h)
{
	vars->textures.player_right[0] = mlx_xpm_file_to_image(mlx,
			"./textures/playerright1.xpm", w, h);
	if (!vars->textures.player_right[0])
		close_program(vars);
	vars->textures.player_right[1] = mlx_xpm_file_to_image(mlx,
			"./textures/playerright2.xpm", w, h);
	if (!vars->textures.player_right[1])
		close_program(vars);
	vars->textures.player_right[2] = mlx_xpm_file_to_image(mlx,
			"./textures/playerright3.xpm", w, h);
	if (!vars->textures.player_right[2])
		close_program(vars);
}
