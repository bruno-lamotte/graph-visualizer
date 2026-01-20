/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:44:32 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/20 07:19:04 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

int	is_exit(t_state *current, t_map_content *map)
{
	return (current->y * map->width + current->x == map->exit_position);
}

int	exit_or_action(t_state *current, t_map_content *map)
{
	if (is_exit(current, map))
		return (1);
	return (0);
}


