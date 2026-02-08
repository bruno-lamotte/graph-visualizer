/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/08 20:35:57 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	start_coin_anim(t_vars *vars, int x, int y)
{
	int	i;

	i = 0;
	while (i < MAX_COIN_ANIMS)
	{
		if (!vars->coin_anims[i].active)
		{
			vars->coin_anims[i].active = 1;
			vars->coin_anims[i].x = x;
			vars->coin_anims[i].y = y;
			vars->coin_anims[i].frame = 0;
			return ;
		}
		i++;
	}
}

void	render_coin_anims(t_vars *vars)
{
	int		i;
	void	*img;

	i = 0;
	while (i < MAX_COIN_ANIMS)
	{
		if (vars->coin_anims[i].active)
		{
			img = vars->textures.coin_anim[vars->coin_anims[i].frame];
			mlx_put_image_to_window(vars->mlx, vars->win, img,
				vars->coin_anims[i].x * TILE_SIZE, vars->coin_anims[i].y
				* TILE_SIZE);
		}
		i++;
	}
}

void	update_coin_anims(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < MAX_COIN_ANIMS)
	{
		if (vars->coin_anims[i].active)
		{
			vars->coin_anims[i].frame++;
			if (vars->coin_anims[i].frame >= 3)
				vars->coin_anims[i].active = 0;
		}
		i++;
	}
}
