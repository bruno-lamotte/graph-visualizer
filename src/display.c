/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:29:22 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/06 04:06:08 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

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
}

int	close_program(t_vars *vars)
{
	free_textures(vars);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	if (vars->current_state)
		free_state(vars->current_state);
	if (vars->map.map)
		free(vars->map.map);
	if (vars->map.data_positions)
		free(vars->map.data_positions);
	exit(0);
	return (0);
}

long long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	is_collected(t_vars *vars, int index)
{
	int	data_id;
	int	byte;
	int	bit;

	data_id = vars->map.data_positions[index];
	if (data_id == 0)
		return (0);
	byte = (data_id - 1) / 64;
	bit = (data_id - 1) % 64;
	return ((vars->current_state->block_data[byte] >> bit) & 1ULL);
}

void	render_player(t_vars *vars, int steps, int nb_moves)
{
	static long long	last_update_time;
	long long			current_time;
	int					position;

	position = vars->current_state->y * vars->map.width
		+ vars->current_state->x;
	position -= (steps * nb_moves);
	while (nb_moves > 0)
	{
		current_time = get_timestamp();
		if (current_time - last_update_time > 100)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.floor,
				position % vars->map.width * TILE_SIZE, position
				/ vars->map.width * TILE_SIZE);
			position += steps;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.player,
				position % vars->map.width * TILE_SIZE, position
				/ vars->map.width * TILE_SIZE);
			mlx_do_sync(vars->mlx);
			last_update_time = current_time;
			nb_moves--;
		}
	}
}

void	render_game(t_vars *vars, int steps, int nb_moves)
{
	void	*img;
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
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->textures.exit, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	render_player(vars, steps, nb_moves);
}

int	handle_keypress(int keysym, t_vars *vars)
{
	int		move_dir;
	int		steps;
	int		nb_moves;
	t_state	*next_state;
	int		pos_current;
	int		pos_next;

	move_dir = 0;
	nb_moves = 0;
	next_state = NULL;
	if (keysym == 65307)
		close_program(vars);
	if (keysym == 'w' || keysym == 65362)
		move_dir = UP;
	else if (keysym == 's' || keysym == 65364)
		move_dir = DOWN;
	else if (keysym == 'a' || keysym == 65361)
		move_dir = LEFT;
	else if (keysym == 'd' || keysym == 65363)
		move_dir = RIGHT;
	if (move_dir != 0)
	{
		next_state = move(vars->current_state, move_dir, &vars->map);
		if (next_state != NULL)
		{
			steps = get_step(vars->current_state, next_state, &vars->map);
			if (steps != 0)
			{
				pos_current = vars->current_state->y * vars->map.width
					+ vars->current_state->x;
				pos_next = next_state->y * vars->map.width + next_state->x;
				nb_moves = (pos_next - pos_current) / steps;
				if (nb_moves < 0)
					nb_moves = -nb_moves;
			}
			free_state(vars->current_state);
			vars->current_state = next_state;
			if (is_hole(next_state, &vars->map))
			{
				write(1, "GAME OVER (Hole)\n", 17);
				close_program(vars);
			}
			if (is_exit(next_state, &vars->map))
			{
				write(1, "VICTORY !\n", 10);
				close_program(vars);
			}
			render_game(vars, steps, nb_moves);
		}
	}
	return (0);
}

void	init_player_state(t_vars *vars)
{
	vars->current_state = new_state();
	if (!vars->current_state)
		close_program(vars);
	vars->current_state->x = vars->map.initial_position % vars->map.width;
	vars->current_state->y = vars->map.initial_position / vars->map.width;
	vars->current_state->parent = NULL;
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
}

void	initialize_textures(t_vars *vars)
{
	void	*mlx;
	int		w;
	int		h;

	mlx = vars->mlx;
	vars->textures.wall = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &w,
			&h);
	vars->textures.floor = mlx_xpm_file_to_image(mlx, "./textures/floor.xpm",
			&w, &h);
	vars->textures.player = mlx_xpm_file_to_image(mlx, "./textures/player.xpm",
			&w, &h);
	vars->textures.collectible = mlx_xpm_file_to_image(mlx,
			"./textures/coin.xpm", &w, &h);
	vars->textures.exit = mlx_xpm_file_to_image(mlx, "./textures/exit.xpm", &w,
			&h);
	vars->textures.fragile_floor = mlx_xpm_file_to_image(mlx,
			"./textures/breackable.xpm", &w, &h);
	vars->textures.hole = mlx_xpm_file_to_image(mlx, "./textures/hole.xpm", &w,
			&h);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	init_vars(&vars);
	if (!is_solvable(ac, av, &vars.map, 0))
		return (1);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	initialize_textures(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.map.width * TILE_SIZE,
			vars.map.height * TILE_SIZE, "Solong");
	if (vars.win == NULL)
		close_program(&vars);
	init_player_state(&vars);
	render_game(&vars, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);
	mlx_hook(vars.win, 17, 0, close_program, &vars);
	mlx_loop(vars.mlx);
	close_program(&vars);
	return (0);
}
