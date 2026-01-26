/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_variables.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:08:29 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/26 03:42:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_VARIABLES
#define GLOBAL_VARIABLES

/*statut changes*/
# ifndef INITIAL_CHAR
#  define INITIAL_CHAR 'P'
# endif

# ifndef EXIT_CHAR
#  define EXIT_CHAR 'E'
# endif

# ifndef COLLECTIBLE_CHAR
#  define COLLECTIBLE_CHAR 'C'
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

#endif