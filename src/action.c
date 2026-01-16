/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:44:32 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/09 20:49:25 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graph.h>

int	is_exit(t_state *current)
{
	return (current->block_data[0] == EXIT);
}

int	exit_or_action(t_state *current)
{
	if (is_exit(current))
		return (1);
	return (0);
}


