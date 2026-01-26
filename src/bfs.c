/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 07:53:04 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/25 03:11:55 by marvin           ###   ########.fr       */
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

void	add_adjacency(t_state *actual, t_state *futur)
{
	t_list	*new_adj;
	int		*index_copy;

	index_copy = malloc(sizeof(int));
	if (!index_copy)
		return ;
	*index_copy = futur->state_index;
	new_adj = ft_lstnew(index_copy);
	if (!new_adj)
	{
		free(index_copy);
		return ;
	}
	ft_lstadd_back(&actual->adjacencies, new_adj);
}

int	bfs(t_queue *q, t_bst *tree, t_map_content *map)
{
	t_state *actual;
	t_state *futur;
	t_state *existing;
	int		i;
	int		state_counter;

	state_counter = 1;
	while (q->front)
	{
		actual = get_from_queue(q);
	//	printf("Processing state %d (x=%d, y=%d), front=%p\n", 
	//		actual->state_index, actual->x, actual->y, (void*)q->front);
		if (exit_or_action(actual, map))
		{
			write(1, "\n\nEXIT\n\n", 9);
	//		continue ;
		}
		i = 1;
		while (i <= NB_POSSIBLE_MOVES)
		{
			futur = move(actual, i, map);
			if (futur)
			{
	//			printf("  Move %d -> (x=%d, y=%d)\n", i, futur->x, futur->y);
				existing = bst_search(tree, futur);
				if (!existing)
				{
					futur->state_index = state_counter++;
					printf("  New state: %d\n", futur->state_index);
					add_adjacency(actual, futur);
					bst_insert(tree, futur);
					if (!add_to_queue(q, futur))
						return (0);
				}
				else
				{
	//				printf("  Already visited (state %d)\n", existing->state_index);
					add_adjacency(actual, existing);
					free_state(futur);
				}
			}
			i++;
		}
	}
	printf("BFS finished, total states: %d\n", state_counter);
	return (state_counter);
}
