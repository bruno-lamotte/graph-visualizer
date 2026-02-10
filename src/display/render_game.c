/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:32:02 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/10 15:16:22 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	render_game_anim(t_vars *vars, int player_px_x, int player_px_y)
{
	render_tiles_with_player(vars, player_px_x, player_px_y);
	render_anims_and_player(vars, player_px_x, player_px_y);
	print_move_count_on_screen(vars, vars->current_state->state_index);
}

void	render_tiles_with_player(t_vars *vars, int player_px_x, int player_px_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map.height)
	{
		x = 0;
		while (x < vars->map.width)
		{
			if (vars->map.map[y * vars->map.width + x] != '\n')
				render_tile(vars, (t_render_pos){x, y, player_px_x,
					player_px_y});
			x++;
		}
		y++;
	}
}

void	render_anims_and_player(t_vars *vars, int player_px_x, int player_px_y)
{
	static int	coin_frame_counter;
	void		*sprite;

	render_break_anims(vars);
	render_coin_anims(vars);
	update_break_anims(vars);
	coin_frame_counter++;
	if (coin_frame_counter >= 3)
	{
		update_coin_anims(vars);
		coin_frame_counter = 0;
	}
	sprite = get_player_sprite(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, sprite, player_px_x,
		player_px_y);
}

void	render_game_img(t_vars *vars, int index, int x, int y)
{
	void	*img;
	char	c;

	c = vars->map.map[index];
	if (c == WALL_CHAR)
		img = vars->textures.wall;
	else if (c == HOLE_CHAR || (is_collected(vars, index)
			&& c == BREAKABLE_CHAR))
		img = vars->textures.hole;
	else if (c == BREAKABLE_CHAR && !is_collected(vars, index))
		img = vars->textures.fragile_floor;
	else
		img = vars->textures.floor;
	mlx_put_image_to_window(vars->mlx, vars->win, img, x * TILE_SIZE, y
		* TILE_SIZE);
	if (c == COLECTIBLE_CHAR && !is_collected(vars, index))
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->textures.collectible, x * TILE_SIZE, y * TILE_SIZE);
	if (c == EXIT_CHAR)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.exit, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	render_game(t_vars *vars, int steps, int nb_moves)
{
	char	c;
	int		x;
	int		y;
	int		index;

	y = 0;
	while (y < vars->map.height)
	{
		x = 0;
		while (x < vars->map.width)
		{
			index = y * vars->map.width + x;
			c = vars->map.map[index];
			if (c == '\n')
			{
				x++;
				continue ;
			}
			render_game_img(vars, index, x, y);
			x++;
		}
		y++;
	}
	render_player(vars, steps, nb_moves);
}
