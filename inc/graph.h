/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:52:29 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/06 03:52:31 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>
# include <struct.h>
# include <stdint.h>
# include <global_variables.h>
# include "mlx.h"
# include "mlx_int.h"
# include "display.h"
# include <sys/time.h>

/* action.c */
int		is_exit(t_state *current, t_map_content *map);
int		is_hole(t_state *current, t_map_content *map);

/* bfs.c */
int		add_to_queue(t_queue *q, t_state *futur);
t_state	*get_from_queue(t_queue *q);
void	add_adjacency(t_state *actual, t_state *futur);
int		bfs(t_queue *q, t_bst *tree, t_map_content *map);

/* bst.c */
int		compare_states(t_state *a, t_state *b);
t_state	*bst_search(t_bst *tree, t_state *futur);
void	free_bst(t_bst *tree);
void	bst_insert(t_bst *tree, t_state *new);

/* graph_process.c */
void	complete_adjacency_matrice(t_bst *tree, char ***adj);
char	**make_adjacency_matrice(t_bst *tree, int nb_state);
void	free_adjacency_matrice(char **adjacency, int nb_state);
void	print_adjacency_matrice(char **adjacency, int nb_state);

/* handle_state.c */
t_state	*new_state(void);
void	free_state(t_state *state);
t_state	*create_futur_state(t_state *actual, int x, int y);

/* move.c */
int		get_xy(t_state *actual, int move, t_map_content *map);
t_state	*move(t_state *actual, int move, t_map_content *map);
int		get_step(t_state *actual, t_state *futur, t_map_content *map);

/* parsing.c */
int		find_char_index(char *line, char c);
int		is_acceptable_char(char c);
int		is_map_valid(char *out, t_map_content *map);
int		count_special_char(char *out, t_map_content *map);
int		parsing_map(char *out, t_map_content *map);

/* utils.c */
int		check_extension(char *filename);
void	free_palestine(t_bst *tree, char **adjacency, int nb_state);

/* solve_map.c */
int		is_solvable(int ac, char **av, t_map_content *map, int is_test);

#endif
