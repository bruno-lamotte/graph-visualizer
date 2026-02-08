/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/08 18:41:42 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	free_textures_players(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (vars->textures.player_up[i])
			mlx_destroy_image(vars->mlx, vars->textures.player_up[i]);
		if (vars->textures.player_down[i])
			mlx_destroy_image(vars->mlx, vars->textures.player_down[i]);
		if (vars->textures.player_left[i])
			mlx_destroy_image(vars->mlx, vars->textures.player_left[i]);
		if (vars->textures.player_right[i])
			mlx_destroy_image(vars->mlx, vars->textures.player_right[i]);
		if (vars->textures.coin_anim[i])
			mlx_destroy_image(vars->mlx, vars->textures.coin_anim[i]);
	}
}

void	free_textures_anims(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (vars->textures.exit_anim[i])
			mlx_destroy_image(vars->mlx, vars->textures.exit_anim[i]);
		if (vars->textures.break_anim[i])
			mlx_destroy_image(vars->mlx, vars->textures.break_anim[i]);
	}
	i = -1;
	while (++i < 8)
	{
		if (vars->textures.hole_anim[i])
			mlx_destroy_image(vars->mlx, vars->textures.hole_anim[i]);
	}
}

void	free_textures(t_vars *vars)
{
	if (vars->textures.wall)
		mlx_destroy_image(vars->mlx, vars->textures.wall);
	if (vars->textures.floor)
		mlx_destroy_image(vars->mlx, vars->textures.floor);
	if (vars->textures.player)
		mlx_destroy_image(vars->mlx, vars->textures.player);
	if (vars->textures.collectible)
		mlx_destroy_image(vars->mlx, vars->textures.collectible);
	if (vars->textures.exit)
		mlx_destroy_image(vars->mlx, vars->textures.exit);
	if (vars->textures.fragile_floor)
		mlx_destroy_image(vars->mlx, vars->textures.fragile_floor);
	if (vars->textures.hole)
		mlx_destroy_image(vars->mlx, vars->textures.hole);
	free_textures_players(vars);
}
