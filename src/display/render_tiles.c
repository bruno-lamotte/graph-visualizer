/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/09 22:12:10 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	render_hole_tile(t_vars *vars, t_render_pos pos)
{
	int		index;
	char	c;
	void	*img;

	index = pos.y * vars->map.width + pos.x;
	c = vars->map.map[index];
	img = NULL;
	if (c == HOLE_CHAR || (is_collected(vars, index) && c == BREAKABLE_CHAR))
	{
		img = vars->textures.hole;
		mlx_put_image_to_window(vars->mlx, vars->win, img, pos.x * TILE_SIZE,
			pos.y * TILE_SIZE);
	}
	else if (c == BREAKABLE_CHAR && !is_collected(vars, index)
		&& is_passed(vars, index, pos))
	{
		collect_tile(vars, index);
		start_break_anim(vars, pos.x, pos.y);
		img = vars->textures.hole;
		mlx_put_image_to_window(vars->mlx, vars->win, img, pos.x * TILE_SIZE,
			pos.y * TILE_SIZE);
	}
}

void	render_collectible_tile(t_vars *vars, t_render_pos pos)
{
	int		index;
	char	c;

	index = pos.y * vars->map.width + pos.x;
	c = vars->map.map[index];
	if (c == COLECTIBLE_CHAR && !is_collected(vars, index) && is_passed(vars,
			index, pos))
	{
		collect_tile(vars, index);
		start_coin_anim(vars, pos.x, pos.y);
	}
	if (c == COLECTIBLE_CHAR && !is_collected(vars, index))
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->textures.collectible, pos.x * TILE_SIZE, pos.y * TILE_SIZE);
	if (c == EXIT_CHAR)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.exit, pos.x
			* TILE_SIZE, pos.y * TILE_SIZE);
}

void	render_tile(t_vars *vars, t_render_pos pos)
{
	void	*img;
	char	c;
	int		index;

	index = pos.y * vars->map.width + pos.x;
	c = vars->map.map[index];
	if (c == WALL_CHAR)
		img = vars->textures.wall;
	else if (c == BREAKABLE_CHAR && !is_collected(vars, index))
		img = vars->textures.fragile_floor;
	else
		img = vars->textures.floor;
	mlx_put_image_to_window(vars->mlx, vars->win, img, pos.x * TILE_SIZE, pos.y
		* TILE_SIZE);
	if (c == BREAKABLE_CHAR || c == HOLE_CHAR)
		render_hole_tile(vars, pos);
	if (c == COLECTIBLE_CHAR || c == EXIT_CHAR)
		render_collectible_tile(vars, pos);
}
