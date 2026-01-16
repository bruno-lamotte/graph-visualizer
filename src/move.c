/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:05:43 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/10 00:39:52 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_state	new_state(int nb_possible_states)
{
	t_state	new;

	new = malloc(sizeof(t_state));
	if (!new)
		return (NULL);
	new->x = 0;
	new->y = 0;
	new->size_data = nb_possible_states;
	new->block_data = ft_calloc(nb_possible_states + 1, sizeof(char));
	if (!new->block-data)
		return (NULL);
	new->adjacencies = ft_lstnew(NULL);
	return (new);
}

t_state	create_futur_state(t_state actual, int i)
{
	t_state	futur;

	futur = new_state(actual->size_data);
	futur->block_data = actual->block_data;
	add_adjacency(actual, futur);

	return (futur);
}
t_state	move(t_state actual, int i)
{
	t_state	futur;

	futur = create_futur_state(actual);
}
