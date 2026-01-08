/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 04:05:37 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/08 08:59:06 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH
# define GRAPH

# include <libft.h>

# ifndef START
#  define START 0
# endif

# ifndef EXIT
#  define EXIT 2
# endif


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct	s_state
{
	int				x;
	int				y;
	unsigned char	block_data;
	struct	s_state	*parent;
	t_list			*adjacency;
}					t_state;

typedef struct	s_bst
{
	t_state			*state;
	struct	s_bst	*left;
	struct	s_bst	*right;
}					t_bst;

typedef struct      s_qnode
{
    t_state         *state;
    struct s_qnode  *next;
}                   t_qnode;

typedef struct      s_queue
{
    t_qnode         *front;
    t_qnode         *rear;
}                   t_queue;
