/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initi_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/10 12:49:06 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	init_vars_anims(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < MAX_COIN_ANIMS)
		vars->coin_anims[i].active = 0;
	i = -1;
	while (++i < MAX_BREAK_ANIMS)
		vars->break_anims[i].active = 0;
}

void	init_player_state(t_vars *vars)
{
	if (!vars->current_state)
		vars->current_state = new_state();
	if (!vars->current_state)
		close_program(vars);
	if (vars->map.width > 0)
	{
		vars->current_state->x = vars->map.initial_position % vars->map.width;
		vars->current_state->y = vars->map.initial_position / vars->map.width;
	}
	else
	{
		vars->current_state->x = 0;
		vars->current_state->y = 0;
	}
	vars->current_state->state_index = 0;
	vars->current_state->parent = NULL;
	vars->current_state->adjacencies = NULL;
}

void	init_vars_textures(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		vars->textures.player_up[i] = NULL;
		vars->textures.player_down[i] = NULL;
		vars->textures.player_left[i] = NULL;
		vars->textures.player_right[i] = NULL;
		vars->textures.coin_anim[i] = NULL;
	}
	i = -1;
	while (++i < 6)
	{
		vars->textures.exit_anim[i] = NULL;
		vars->textures.break_anim[i] = NULL;
	}
	i = -1;
	while (++i < 8)
		vars->textures.hole_anim[i] = NULL;
}

void	init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->textures.wall = NULL;
	vars->textures.floor = NULL;
	vars->textures.player = NULL;
	vars->textures.collectible = NULL;
	vars->textures.exit = NULL;
	vars->textures.fragile_floor = NULL;
	vars->textures.hole = NULL;
	vars->next_state = NULL;
	vars->anim.is_animating = 0;
	vars->anim.direction = 0;
	vars->anim.pixel_offset = 0;
	vars->anim.total_pixels = 0;
	vars->anim.frame = 0;
	vars->exit_anim.active = 0;
	vars->exit_anim.frame = 0;
	vars->exit_anim.total_frames = 6;
	vars->hole_anim.active = 0;
	vars->hole_anim.frame = 0;
	vars->hole_anim.total_frames = 8;
	init_vars_textures(vars);
	init_vars_anims(vars);
	init_player_state(vars);
}
