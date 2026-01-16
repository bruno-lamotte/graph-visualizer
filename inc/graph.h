/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:52:29 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/09 23:09:27 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH
# define GRAPH

# include <libft.h>
# include <struct.h>

/* action.c */
int		is_exit(t_state *current);
int		exit_or_action(t_state *current);

/* bfs.c */
int		add_to__queue(t_queue q, t_state futur);
t_state	get_from_queue(t_queue q);
void	add_adjacency(t_state *actual, t_state *futur);
int		bfs(t_queue **q, t_bst **tree);

/* bst.c */
int		compare_states(t_state *a, t_state *b);
int		bst_search(t_bst **tree, t_state *futur);
void	bst_insert(t_bst **tree, t_state *new);


