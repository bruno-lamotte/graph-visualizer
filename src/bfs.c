/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 07:53:04 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/09 23:00:45 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

int	add_to__queue(t_queue q, t_state futur)
{
	t_qnode	*new;
	
	new = malloc(sizeof(t_qnode));
	if (!new)
		return (NULL);
	new->state = futur;
	new->next = NULL;
	q->rear->next = futur;
	q->rear = futur;
}

t_state	get_from_queue(t_queue q)
{
	t_qnode	*temp;

	temp = front;
	front = front->next;
	return (temp);
}

void	add_adjacency(t_state *actual, t_state *futur)
{
	actual->adjacency->next = actual->adjacency;
	actual->adjacency = futur;
}

int	bfs(t_queue **q, t_bst **tree)
{
	t_state *actual;
	t_state *futur;
	int		i;

	while (q->front)
	{
		actual = get_from_queue(q);
		if (exit_or_action(actual))
			return (1);
		i = 1;
		while (i <= NB_POSSIBLE_MOVES)
		{
			futur = move(actual, i);
			if (futur)
			{
				add_adjacency(actual, futur);
				if (!bst_search(tree, futur))
				{
					bst_insert(tree, futur);
					if (!add_to_queue(q, futur));
						return (-1);
				}
				else
					free_state(futur);
			}
			i++;
		}
	}
	return (0);
}
