/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:05:43 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/20 11:13:07 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

t_state	*new_state(int nb_possible_states)
{
	t_state	*new;

	new = malloc(sizeof(t_state));
	if (!new)
		return (NULL);
	new->state_index = 0;
	new->x = 0;
	new->y = 0;
	new->data_size = nb_possible_states;
	new->block_data = ft_calloc(nb_possible_states + 1, sizeof(char));
	if (!new->block_data)
		return (NULL);
	new->adjacencies = ft_lstnew(NULL);
	return (new);
}

void	free_state(t_state *state)
{
	if (!state)
		return ;
	if (state->block_data)
		free(state->block_data);
	if (state->adjacencies)
		ft_lstclear(&state->adjacencies, NULL);
	free(state);
}

t_state	*create_futur_state(t_state *actual, int x, int y)
{
	t_state	*futur;

	futur = new_state(actual->data_size);
	futur->block_data = actual->block_data;
	add_adjacency(actual, futur);
	futur->x = x;
	futur->y = y;
	return (futur);
}

void	get_xy(t_state *actual, int *x, int *y, int move, t_map_content *map)
{
	int	new_position;
	int	width;

	width = map->width;
	new_position = actual->y * width + actual->x;
	if (move == UP)
		while (map->map[new_position - width] != '1')
			new_position -= width;
	if (move == RIGHT)
		while (map->map[new_position + 1] != '1')
			new_position += 1;
	if (move == DOWN)
		while (map->map[new_position + width] != '1')
			new_position += width;
	if (move == LEFT)
		while (map->map[new_position - 1] != '1')
			new_position -= 1;
	*x = new_position % width;
	*y = new_position / width;
}

t_state	*move(t_state *actual, int move, t_map_content *map)
{
	t_state	*futur;
	int		new_x;
	int		new_y;

	new_x = -1;
	new_y = -1;
	
	if (move == UP || move == RIGHT || move == DOWN || move == LEFT)
		get_xy(actual, &new_x, &new_y, move, map);
	futur = create_futur_state(actual, new_x , new_y);
	futur->state_index = actual->state_index + move;
	return (futur);
}
