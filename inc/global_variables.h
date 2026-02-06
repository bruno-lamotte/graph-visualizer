/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_variables.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:08:29 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/06 04:45:51 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_VARIABLES_H
# define GLOBAL_VARIABLES_H

/*mlx*/

# ifndef MLX_ERROR
#  define MLX_ERROR 1
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif

/*limits*/

# ifndef MAX_DATA_CHUNKS
#  define MAX_DATA_CHUNKS 4 // 4 * 64 = 256 objets max
# endif

/*statut changes*/

# ifndef INITIAL_CHAR
#  define INITIAL_CHAR 'P'
# endif

# ifndef EXIT_CHAR
#  define EXIT_CHAR 'E'
# endif

# ifndef COLECTIBLE_CHAR
#  define COLECTIBLE_CHAR 'C'
# endif

# ifndef BREAKABLE_CHAR
#  define BREAKABLE_CHAR '?'
# endif

# ifndef HOLE_CHAR
#  define HOLE_CHAR '!'
# endif

# ifndef WALL_CHAR
#  define WALL_CHAR '1'
# endif

# ifndef EMPTY_CHAR
#  define EMPTY_CHAR '0'
# endif

/*moves*/

# ifndef NB_POSSIBLE_MOVES
#  define NB_POSSIBLE_MOVES 4
# endif

# ifndef UP
#  define UP 1
# endif

# ifndef RIGHT
#  define RIGHT 2
# endif

# ifndef DOWN
#  define DOWN 3
# endif

# ifndef LEFT
#  define LEFT 4
# endif

/*keys*/

# ifndef KEY_ESC
#  define KEY_ESC 65307
# endif

# ifndef KEY_W
#  define KEY_W 'w'
# endif

# ifndef KEY_A
#  define KEY_A 'a'
# endif

# ifndef KEY_S
#  define KEY_S 's'
# endif

# ifndef KEY_D
#  define KEY_D 'd'
# endif

# ifndef KEY_UP
#  define KEY_UP 65362
# endif

# ifndef KEY_DOWN
#  define KEY_DOWN 65364
# endif

# ifndef KEY_LEFT
#  define KEY_LEFT 65361
# endif

# ifndef KEY_RIGHT
#  define KEY_RIGHT 65363
# endif

/*x11 events*/

# ifndef X_EVENT_KEY_PRESS
#  define X_EVENT_KEY_PRESS 2
# endif

# ifndef X_EVENT_DESTROY
#  define X_EVENT_DESTROY 17
# endif

# ifndef X_MASK_KEY_PRESS
#  define X_MASK_KEY_PRESS (1L << 0)
# endif

#endif