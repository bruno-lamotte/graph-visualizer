/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 04:05:37 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/10 00:29:53 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define STRUCT

# include <libft.h>

typedef struct	s_state
{
	int				x;
	int				y;
	size_t			data_size;
	unsigned char	*block_data;
	struct	s_state	*parent;
	t_list			*adjacencies;
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
