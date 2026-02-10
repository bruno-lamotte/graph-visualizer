/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 07:53:04 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/10 14:32:06 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

typedef struct s_bfs_var
{
	t_bst		*tree;
	t_queue		*q;
	int			*counter;
}				t_bfs_var;

int	add_to_queue(t_queue *q, t_state *futur)
{
	t_qnode	*new;

	new = malloc(sizeof(t_qnode));
	if (!new)
		return (0);
	new->state = futur;
	new->next = NULL;
	if (q->front == NULL)
	{
		q->front = new;
		q->rear = new;
	}
	else
	{
		q->rear->next = new;
		q->rear = new;
	}
	return (1);
}

t_state	*get_from_queue(t_queue *q)
{
	t_qnode	*temp;
	t_state	*state;

	temp = q->front;
	state = temp->state;
	q->front = q->front->next;
	free(temp);
	return (state);
}

void	free_queue(t_queue *q)
{
	t_qnode	*temp;

	if (!q)
		return ;
	while (q->front)
	{
		temp = q->front;
		q->front = q->front->next;
		free(temp);
	}
	q->rear = NULL;
}

int	process_futur(t_state *actual, t_state *futur, t_bfs_var *var)
{
	t_state	*existing;

	existing = bst_search(var->tree, futur);
	if (!existing)
	{
		futur->state_index = (*var->counter)++;
		add_adjacency(actual, futur);
		if (!bst_insert(var->tree, futur))
			return (0);
		if (!add_to_queue(var->q, futur))
			return (0);
	}
	else
	{
		add_adjacency(actual, existing);
		free_state(futur);
	}
	return (1);
}

int	bfs(t_queue *q, t_bst *tree, t_map_content *map)
{
	t_state		*actual;
	t_state		*futur;
	int			i;
	int			state_counter;
	t_bfs_var	var;

	state_counter = 1;
	var = (t_bfs_var){tree, q, &state_counter};
	while (q->front)
	{
		actual = get_from_queue(q);
		if (is_exit(actual, map))
			return (map->min_moves = get_min_possible_moves(actual),
				free_queue(q), state_counter);
		if (is_hole(actual, map))
			continue ;
		i = 0;
		while (++i <= NB_POSSIBLE_MOVES)
		{
			futur = move(actual, i, map);
			if (futur && !process_futur(actual, futur, &var))
				return (free_queue(q), 0);
		}
	}
	return (free_queue(q), 0);
}
