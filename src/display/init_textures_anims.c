/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_anims.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/10 10:31:22 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	init_coin_textures(t_vars *vars, void *mlx, int *w, int *h)
{
	vars->textures.coin_anim[0] = mlx_xpm_file_to_image(mlx,
			"./textures/coin.xpm", w, h);
	if (!vars->textures.coin_anim[0])
		close_program(vars);
	vars->textures.coin_anim[1] = mlx_xpm_file_to_image(mlx,
			"./textures/coin2.xpm", w, h);
	if (!vars->textures.coin_anim[1])
		close_program(vars);
	vars->textures.coin_anim[2] = mlx_xpm_file_to_image(mlx,
			"./textures/coin3.xpm", w, h);
	if (!vars->textures.coin_anim[2])
		close_program(vars);
}

void	init_exit_textures(t_vars *vars, void *mlx, int *w, int *h)
{
	vars->textures.exit_anim[0] = mlx_xpm_file_to_image(mlx,
			"./textures/exit.xpm", w, h);
	if (!vars->textures.exit_anim[0])
		close_program(vars);
	vars->textures.exit_anim[1] = mlx_xpm_file_to_image(mlx,
			"./textures/exit2.xpm", w, h);
	if (!vars->textures.exit_anim[1])
		close_program(vars);
	vars->textures.exit_anim[2] = mlx_xpm_file_to_image(mlx,
			"./textures/exit3.xpm", w, h);
	if (!vars->textures.exit_anim[2])
		close_program(vars);
	vars->textures.exit_anim[3] = mlx_xpm_file_to_image(mlx,
			"./textures/exit4.xpm", w, h);
	if (!vars->textures.exit_anim[3])
		close_program(vars);
	vars->textures.exit_anim[4] = mlx_xpm_file_to_image(mlx,
			"./textures/exit5.xpm", w, h);
	if (!vars->textures.exit_anim[4])
		close_program(vars);
	vars->textures.exit_anim[5] = mlx_xpm_file_to_image(mlx,
			"./textures/exit6.xpm", w, h);
	if (!vars->textures.exit_anim[5])
		close_program(vars);
}

void	init_break_textures(t_vars *vars, void *mlx, int *w, int *h)
{
	vars->textures.break_anim[0] = mlx_xpm_file_to_image(mlx,
			"./textures/breackable.xpm", w, h);
	if (!vars->textures.break_anim[0])
		close_program(vars);
	vars->textures.break_anim[1] = mlx_xpm_file_to_image(mlx,
			"./textures/breackable2.xpm", w, h);
	if (!vars->textures.break_anim[1])
		close_program(vars);
	vars->textures.break_anim[2] = mlx_xpm_file_to_image(mlx,
			"./textures/breackable3.xpm", w, h);
	if (!vars->textures.break_anim[2])
		close_program(vars);
	vars->textures.break_anim[3] = mlx_xpm_file_to_image(mlx,
			"./textures/breackable4.xpm", w, h);
	if (!vars->textures.break_anim[3])
		close_program(vars);
	vars->textures.break_anim[4] = mlx_xpm_file_to_image(mlx,
			"./textures/breackable5.xpm", w, h);
	if (!vars->textures.break_anim[4])
		close_program(vars);
	vars->textures.break_anim[5] = mlx_xpm_file_to_image(mlx,
			"./textures/breackable6.xpm", w, h);
	if (!vars->textures.break_anim[5])
		close_program(vars);
}

void	init_hole_textures_2(t_vars *vars, void *mlx, int *w, int *h)
{
	vars->textures.hole_anim[4] = mlx_xpm_file_to_image(mlx,
			"./textures/hole5.xpm", w, h);
	if (!vars->textures.hole_anim[4])
		close_program(vars);
	vars->textures.hole_anim[5] = mlx_xpm_file_to_image(mlx,
			"./textures/hole6.xpm", w, h);
	if (!vars->textures.hole_anim[5])
		close_program(vars);
	vars->textures.hole_anim[6] = mlx_xpm_file_to_image(mlx,
			"./textures/hole7.xpm", w, h);
	if (!vars->textures.hole_anim[6])
		close_program(vars);
	vars->textures.hole_anim[7] = mlx_xpm_file_to_image(mlx,
			"./textures/hole8.xpm", w, h);
	if (!vars->textures.hole_anim[7])
		close_program(vars);
}

void	init_hole_textures(t_vars *vars, void *mlx, int *w, int *h)
{
	vars->textures.hole_anim[0] = mlx_xpm_file_to_image(mlx,
			"./textures/hole.xpm", w, h);
	if (!vars->textures.hole_anim[0])
		close_program(vars);
	vars->textures.hole_anim[1] = mlx_xpm_file_to_image(mlx,
			"./textures/hole2.xpm", w, h);
	if (!vars->textures.hole_anim[1])
		close_program(vars);
	vars->textures.hole_anim[2] = mlx_xpm_file_to_image(mlx,
			"./textures/hole3.xpm", w, h);
	if (!vars->textures.hole_anim[2])
		close_program(vars);
	vars->textures.hole_anim[3] = mlx_xpm_file_to_image(mlx,
			"./textures/hole4.xpm", w, h);
	if (!vars->textures.hole_anim[3])
		close_program(vars);
	init_hole_textures_2(vars, mlx, w, h);
}
