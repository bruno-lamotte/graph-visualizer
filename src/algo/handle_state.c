/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/10 14:33:40 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

t_state	*new_state(void)
{
	t_state	*new;

	new = malloc(sizeof(t_state));
	if (!new)
		return (NULL);
	new->state_index = 0;
	new->x = 0;
	new->y = 0;
	ft_bzero(new->block_data, sizeof(new->block_data));
	new->adjacencies = NULL;
	new->parent = NULL;
	return (new);
}

void	free_state(t_state *state)
{
	if (!state)
		return ;
	if (state->adjacencies)
		ft_lstclear(&state->adjacencies, free);
	free(state);
}

t_state	*create_futur_state(t_state *actual, int x, int y)
{
	t_state	*futur;

	futur = new_state();
	if (!futur)
		return (NULL);
	ft_memcpy(futur->block_data, actual->block_data, sizeof(futur->block_data));
	futur->x = x;
	futur->y = y;
	futur->parent = actual;
	return (futur);
}
