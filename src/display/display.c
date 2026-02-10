/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:29:22 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/10 16:27:19 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

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
	if (vars->next_state)
		free_state(vars->next_state);
	if (vars->map.map)
		free(vars->map.map);
	if (vars->map.data_positions)
		free(vars->map.data_positions);
	exit(0);
	return (0);
}

void	put_count_on_screen(t_vars *vars, char *output)
{
	int	text_pos_y;
	int	i;
	int	j;

	j = 0;
	while (j < BOTTOM_BAR_SIZE)
	{
		i = 0;
		while (i < vars->map.width * TILE_SIZE || i < 10 * TILE_SIZE)
		{
			mlx_pixel_put(vars->mlx, vars->win, i, vars->map.height * TILE_SIZE
				+ j, 0x000000);
			i++;
		}
		j++;
	}
	text_pos_y = vars->map.height * TILE_SIZE + (BOTTOM_BAR_SIZE / 2) + 5;
	mlx_string_put(vars->mlx, vars->win, 10, text_pos_y, 0xFFFFFF, output);
}

void	print_move_count_on_screen(t_vars *vars, int nb_moves)
{
	char	*nbr_moves;
	char	*min_moves;
	char	*output;
	char	*tmp;
	char	*tmp2;

	min_moves = ft_itoa(vars->map.min_moves);
	nbr_moves = ft_itoa(nb_moves);
	if (!nbr_moves || !min_moves)
		return ;
	tmp = ft_strjoin("     Moves: ", nbr_moves);
	free(nbr_moves);
	if (!tmp)
		return ;
	tmp2 = ft_strjoin("Min possible moves: ", min_moves);
	free(min_moves);
	if (!tmp2)
		return ;
	output = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
	if (!output)
		return ;
	put_count_on_screen(vars, output);
	free(output);
}

int	animation_loop(t_vars *vars)
{
	static long long	last_time;
	long long			now;
	int					px_x;
	int					px_y;

	if (vars->exit_anim.active && !vars->anim.is_animating)
		return (exit_animation_loop(vars));
	if (vars->hole_anim.active && !vars->anim.is_animating)
		return (hole_animation_loop(vars));
	if (!vars->anim.is_animating)
		return (update_idle_anims(vars), 0);
	now = get_timestamp();
	if (now - last_time < 30)
		return (0);
	last_time = now;
	vars->anim.pixel_offset += 11;
	vars->anim.frame = (vars->anim.frame + 1) % 3;
	if (vars->anim.pixel_offset >= vars->anim.total_pixels)
		vars->anim.pixel_offset = vars->anim.total_pixels;
	get_anim_position(vars, &px_x, &px_y);
	render_game_anim(vars, px_x, px_y);
	mlx_do_sync(vars->mlx);
	if (vars->anim.pixel_offset >= vars->anim.total_pixels)
		finish_animation(vars);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	ft_bzero(&vars, sizeof(vars));
	init_vars(&vars);
	if (!is_solvable(ac, av, &vars.map, 0))
		return (close_program(&vars));
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (close_program(&vars));
	initialize_textures(&vars);
	vars.win = mlx_new_window(vars.mlx, (vars.map.width - 1) * TILE_SIZE,
			vars.map.height * TILE_SIZE + BOTTOM_BAR_SIZE, "Solong");
	if (vars.win == NULL)
		close_program(&vars);
	init_player_state(&vars);
	render_game(&vars, 0, 0);
	mlx_hook(vars.win, X_EVENT_KEY_PRESS, (1L << 0), handle_keypress, &vars);
	mlx_hook(vars.win, X_EVENT_DESTROY, 0, close_program, &vars);
	mlx_loop_hook(vars.mlx, animation_loop, &vars);
	mlx_loop(vars.mlx);
	close_program(&vars);
	return (0);
}
