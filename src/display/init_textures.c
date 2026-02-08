/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/08 18:36:57 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	init_player_textures(t_vars *vars, void *mlx, int *w, int *h)
{
	vars->textures.player_up[0] = mlx_xpm_file_to_image(mlx,
			"./textures/playerup1.xpm", w, h);
	vars->textures.player_up[1] = mlx_xpm_file_to_image(mlx,
			"./textures/playerup2.xpm", w, h);
	vars->textures.player_up[2] = mlx_xpm_file_to_image(mlx,
			"./textures/playerup3.xpm", w, h);
	vars->textures.player_down[0] = mlx_xpm_file_to_image(mlx,
			"./textures/playerdown1.xpm", w, h);
	vars->textures.player_down[1] = mlx_xpm_file_to_image(mlx,
			"./textures/playerdown2.xpm", w, h);
	vars->textures.player_down[2] = mlx_xpm_file_to_image(mlx,
			"./textures/playerdown3.xpm", w, h);
	vars->textures.player_left[0] = mlx_xpm_file_to_image(mlx,
			"./textures/playerleft1.xpm", w, h);
	vars->textures.player_left[1] = mlx_xpm_file_to_image(mlx,
			"./textures/playerleft2.xpm", w, h);
	vars->textures.player_left[2] = mlx_xpm_file_to_image(mlx,
			"./textures/playerleft3.xpm", w, h);
	vars->textures.player_right[0] = mlx_xpm_file_to_image(mlx,
			"./textures/playerright1.xpm", w, h);
	vars->textures.player_right[1] = mlx_xpm_file_to_image(mlx,
			"./textures/playerright2.xpm", w, h);
	vars->textures.player_right[2] = mlx_xpm_file_to_image(mlx,
			"./textures/playerright3.xpm", w, h);
}

void	init_coin_textures(t_vars *vars, void *mlx, int *w, int *h)
{
	vars->textures.coin_anim[0] = mlx_xpm_file_to_image(mlx,
			"./textures/coin.xpm", w, h);
	vars->textures.coin_anim[1] = mlx_xpm_file_to_image(mlx,
			"./textures/coin2.xpm", w, h);
	vars->textures.coin_anim[2] = mlx_xpm_file_to_image(mlx,
			"./textures/coin3.xpm", w, h);
}

void	init_exit_textures(t_vars *vars, void *mlx, int *w, int *h)
{
	vars->textures.exit_anim[0] = mlx_xpm_file_to_image(mlx,
			"./textures/exit.xpm", w, h);
	vars->textures.exit_anim[1] = mlx_xpm_file_to_image(mlx,
			"./textures/exit2.xpm", w, h);
	vars->textures.exit_anim[2] = mlx_xpm_file_to_image(mlx,
			"./textures/exit3.xpm", w, h);
	vars->textures.exit_anim[3] = mlx_xpm_file_to_image(mlx,
			"./textures/exit4.xpm", w, h);
	vars->textures.exit_anim[4] = mlx_xpm_file_to_image(mlx,
			"./textures/exit5.xpm", w, h);
	vars->textures.exit_anim[5] = mlx_xpm_file_to_image(mlx,
			"./textures/exit6.xpm", w, h);
}

void	init_break_textures(t_vars *vars, void *mlx, int *w, int *h)
{
	vars->textures.break_anim[0] = mlx_xpm_file_to_image(mlx,
			"./textures/breackable.xpm", w, h);
	vars->textures.break_anim[1] = mlx_xpm_file_to_image(mlx,
			"./textures/breackable2.xpm", w, h);
	vars->textures.break_anim[2] = mlx_xpm_file_to_image(mlx,
			"./textures/breackable3.xpm", w, h);
	vars->textures.break_anim[3] = mlx_xpm_file_to_image(mlx,
			"./textures/breackable4.xpm", w, h);
	vars->textures.break_anim[4] = mlx_xpm_file_to_image(mlx,
			"./textures/breackable5.xpm", w, h);
	vars->textures.break_anim[5] = mlx_xpm_file_to_image(mlx,
			"./textures/breackable6.xpm", w, h);
}

void	init_hole_textures(t_vars *vars, void *mlx, int *w, int *h)
{
	vars->textures.hole_anim[0] = mlx_xpm_file_to_image(mlx,
			"./textures/hole.xpm", w, h);
	vars->textures.hole_anim[1] = mlx_xpm_file_to_image(mlx,
			"./textures/hole2.xpm", w, h);
	vars->textures.hole_anim[2] = mlx_xpm_file_to_image(mlx,
			"./textures/hole3.xpm", w, h);
	vars->textures.hole_anim[3] = mlx_xpm_file_to_image(mlx,
			"./textures/hole4.xpm", w, h);
	vars->textures.hole_anim[4] = mlx_xpm_file_to_image(mlx,
			"./textures/hole5.xpm", w, h);
	vars->textures.hole_anim[5] = mlx_xpm_file_to_image(mlx,
			"./textures/hole6.xpm", w, h);
	vars->textures.hole_anim[6] = mlx_xpm_file_to_image(mlx,
			"./textures/hole7.xpm", w, h);
	vars->textures.hole_anim[7] = mlx_xpm_file_to_image(mlx,
			"./textures/hole8.xpm", w, h);
}
