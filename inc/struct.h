/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 04:05:37 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/27 10:43:22 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define STRUCT

# include <libft.h>
# include <stdint.h>
# include <global_variables.h>

typedef struct	s_map_content
{
	char			*map;
	int				width;
	int				*data_positions;
	int				initial_position;
	int				exit_position;
	uint64_t		exit_mask[MAX_DATA_CHUNKS];
}					t_map_content;

typedef struct	s_state
{
	int				state_index;
	int				x;
	int				y;
	size_t			data_size;
	uint64_t		block_data[MAX_DATA_CHUNKS];
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
