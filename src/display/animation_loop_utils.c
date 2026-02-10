/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_loop_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/10 13:35:10 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	get_anim_position(t_vars *vars, int *px_x, int *px_y)
{
	if (vars->anim.direction == UP)
	{
		*px_x = vars->anim.start_x * TILE_SIZE;
		*px_y = vars->anim.start_y * TILE_SIZE - vars->anim.pixel_offset;
	}
	else if (vars->anim.direction == DOWN)
	{
		*px_x = vars->anim.start_x * TILE_SIZE;
		*px_y = vars->anim.start_y * TILE_SIZE + vars->anim.pixel_offset;
	}
	else if (vars->anim.direction == LEFT)
	{
		*px_x = vars->anim.start_x * TILE_SIZE - vars->anim.pixel_offset;
		*px_y = vars->anim.start_y * TILE_SIZE;
	}
	else
	{
		*px_x = vars->anim.start_x * TILE_SIZE + vars->anim.pixel_offset;
		*px_y = vars->anim.start_y * TILE_SIZE;
	}
}

void	finish_animation(t_vars *vars)
{
	vars->anim.is_animating = 0;
	vars->anim.frame = 0;
	free_state(vars->current_state);
	vars->current_state = vars->next_state;
	vars->next_state = NULL;
	if (is_hole(vars->current_state, &vars->map))
	{
		vars->hole_anim.active = 1;
		vars->hole_anim.frame = 1;
	}
}
