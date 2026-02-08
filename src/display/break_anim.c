/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/08 20:36:31 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	start_break_anim(t_vars *vars, int x, int y)
{
	int	i;

	i = 0;
	while (i < MAX_BREAK_ANIMS)
	{
		if (!vars->break_anims[i].active)
		{
			vars->break_anims[i].active = 1;
			vars->break_anims[i].x = x;
			vars->break_anims[i].y = y;
			vars->break_anims[i].frame = 0;
			vars->break_anims[i].delay = 0;
			return ;
		}
		i++;
	}
}

void	render_break_anims(t_vars *vars)
{
	int		i;
	void	*img;

	i = 0;
	while (i < MAX_BREAK_ANIMS)
	{
		if (vars->break_anims[i].active)
		{
			img = vars->textures.break_anim[vars->break_anims[i].frame];
			mlx_put_image_to_window(vars->mlx, vars->win, img,
				vars->break_anims[i].x * TILE_SIZE, vars->break_anims[i].y
				* TILE_SIZE);
		}
		i++;
	}
}

void	update_break_anims(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < MAX_BREAK_ANIMS)
	{
		if (vars->break_anims[i].active)
		{
			if (vars->break_anims[i].frame == 2
				&& vars->break_anims[i].delay < 4)
				vars->break_anims[i].delay++;
			else
			{
				vars->break_anims[i].delay = 0;
				vars->break_anims[i].frame++;
				if (vars->break_anims[i].frame >= 6)
					vars->break_anims[i].active = 0;
			}
		}
		i++;
	}
}
