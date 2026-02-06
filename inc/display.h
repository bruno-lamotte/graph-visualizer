/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:31:32 by blamotte          #+#    #+#             */
/*   Updated: 2026/01/31 07:21:04 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H


typedef struct	s_textures
{
	void			*wall;
	void			*floor;
	void			*fragile_floor;
	void			*hole;
	void			*player;
	void			*collectible;
	void			*exit;
}					t_textures;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_textures		textures;
	t_map_content	map;
	t_state         *current_state;
}					t_vars;

#endif
