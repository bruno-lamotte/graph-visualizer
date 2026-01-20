/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 07:53:04 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/20 10:42:38 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

int	add_to_queue(t_queue *q, t_state *futur)
{
	t_qnode	*new;

	new = malloc(sizeof(t_qnode));
	if (!new)
		return (0);
	new->state = futur;
	new->next = NULL;
	q->rear->next = new;
	q->rear = new;
	return (1);
}

t_state	*get_from_queue(t_queue *q)
{
	t_qnode	*temp;

	temp = q->front;
	q->front = q->front->next;
	return (temp->state);
}

void	add_adjacency(t_state *actual, t_state *futur)
{
	actual->adjacencies->next = actual->adjacencies;
	actual->adjacencies->content = &futur->state_index;
}

int	bfs(t_queue *q, t_bst *tree, t_map_content *map)
{
	t_state *actual;
	t_state *futur;
	int		i;

	while (q->front)
	{
		actual = get_from_queue(q);
		printf("%d\n", actual->state_index);
		if (exit_or_action(actual, map))
		{
			write(1, "OK\n", 3);
			continue ;
		}
		i = 1;
		while (i <= NB_POSSIBLE_MOVES)
		{
			futur = move(actual, i, map);
			printf("%d\n", futur->state_index);
			if (futur)
			{
				add_adjacency(actual, futur);
				if (!bst_search(tree, futur))
				{
					bst_insert(tree, futur);
					if (!add_to_queue(q, futur))
						return (0);
				}
				else
					free_state(futur);
			}
			i++;
		}
	}
	return (actual->state_index);
}
