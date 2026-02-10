/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/10 13:09:39 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	init_next_frames(t_vars *vars, t_state *next_state, int move_dir)
{
	int	dist_x;
	int	dist_y;

	vars->next_state = next_state;
	vars->next_state->state_index = vars->current_state->state_index + 1;
	vars->anim.direction = move_dir;
	vars->anim.start_x = vars->current_state->x;
	vars->anim.start_y = vars->current_state->y;
	vars->anim.end_x = next_state->x;
	vars->anim.end_y = next_state->y;
	dist_x = ft_abs(next_state->x - vars->current_state->x);
	dist_y = ft_abs(next_state->y - vars->current_state->y);
	vars->anim.total_pixels = (dist_x + dist_y) * TILE_SIZE;
	vars->anim.pixel_offset = 0;
	vars->anim.frame = 0;
	vars->anim.is_animating = 1;
	if (is_exit(next_state, &vars->map))
	{
		vars->exit_anim.active = 1;
		vars->exit_anim.frame = 1;
	}
}

int	handle_keypress(int keysym, t_vars *vars)
{
	int		move_dir;
	t_state	*next_state;

	if (vars->anim.is_animating)
		return (0);
	move_dir = 0;
	next_state = NULL;
	if (keysym == KEY_ESC)
		close_program(vars);
	if (keysym == KEY_W || keysym == KEY_UP)
		move_dir = UP;
	else if (keysym == KEY_S || keysym == KEY_DOWN)
		move_dir = DOWN;
	else if (keysym == KEY_A || keysym == KEY_LEFT)
		move_dir = LEFT;
	else if (keysym == KEY_D || keysym == KEY_RIGHT)
		move_dir = RIGHT;
	if (move_dir != 0)
	{
		next_state = move(vars->current_state, move_dir, &vars->map);
		if (next_state != NULL)
			init_next_frames(vars, next_state, move_dir);
	}
	return (0);
}
