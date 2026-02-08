/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blamotte <blamotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:31:32 by blamotte          #+#    #+#             */
/*   Updated: 2026/02/08 19:04:52 by blamotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <struct.h>

# define MAX_COIN_ANIMS 16
# define MAX_BREAK_ANIMS 16

typedef struct s_render_pos
{
	int				x;
	int				y;
	int				player_px_x;
	int				player_px_y;
}					t_render_pos;

typedef struct s_coin_anim
{
	int				active;
	int				x;
	int				y;
	int				frame;
}					t_coin_anim;

typedef struct s_break_anim
{
	int				active;
	int				x;
	int				y;
	int				frame;
	int				delay;
}					t_break_anim;

typedef struct s_exit_anim
{
	int				active;
	int				frame;
	int				total_frames;
}					t_exit_anim;

typedef struct s_hole_anim
{
	int				active;
	int				frame;
	int				total_frames;
}					t_hole_anim;

typedef struct s_textures
{
	void			*wall;
	void			*floor;
	void			*fragile_floor;
	void			*hole;
	void			*player;
	void			*player_up[3];
	void			*player_down[3];
	void			*player_left[3];
	void			*player_right[3];
	void			*collectible;
	void			*coin_anim[3];
	void			*exit;
	void			*exit_anim[6];
	void			*break_anim[6];
	void			*hole_anim[8];
}					t_textures;

typedef struct s_anim
{
	int				is_animating;
	int				direction;
	int				pixel_offset;
	int				total_pixels;
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	int				frame;
}					t_anim;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_textures		textures;
	t_map_content	map;
	t_state			*current_state;
	t_state			*next_state;
	t_anim			anim;
	t_coin_anim		coin_anims[MAX_COIN_ANIMS];
	t_break_anim	break_anims[MAX_BREAK_ANIMS];
	t_exit_anim		exit_anim;
	t_hole_anim		hole_anim;
}					t_vars;

/* display.c */
int					close_program(t_vars *vars);
int					animation_loop(t_vars *vars);

/* animation_loop_utils.c */
void				get_anim_position(t_vars *vars, int *px_x, int *px_y);
void				finish_animation(t_vars *vars);

/* exit_anim.c */
int					exit_animation_loop(t_vars *vars);

/* hole_anim.c */
int					hole_animation_loop(t_vars *vars);

/* rendering_utils.c */
void				update_idle_anims(t_vars *vars);
int					is_player_on_tile(t_render_pos pos);
long long			get_timestamp(void);
void				*get_player_sprite(t_vars *vars);
void				render_player(t_vars *vars, int steps, int nb_moves);

/* render_game.c */
void				render_game_anim(t_vars *vars, int player_px_x,
						int player_px_y);
void				render_game(t_vars *vars, int player_px_x, int player_px_y);
void				render_tiles_with_player(t_vars *vars, int player_px_x,
						int player_px_y);
void				render_anims_and_player(t_vars *vars, int player_px_x,
						int player_px_y);

/* render_tiles.c */
void				render_hole_tile(t_vars *vars, t_render_pos pos);
void				render_collectible_tile(t_vars *vars, t_render_pos pos);
void				render_tile(t_vars *vars, t_render_pos pos);

void				render_coin_anims(t_vars *vars);
void				update_coin_anims(t_vars *vars);
void				render_coin_anims(t_vars *vars);
void				update_coin_anims(t_vars *vars);
void				start_coin_anim(t_vars *vars, int x, int y);

/* break_anim.c */
void				render_break_anims(t_vars *vars);
void				update_break_anims(t_vars *vars);
void				start_break_anim(t_vars *vars, int x, int y);

/* verif_actions_on_path.c */
int					is_collected(t_vars *vars, int index);
int					is_passed(t_vars *vars, int index, t_render_pos pos);
void				collect_tile(t_vars *vars, int index);

/* initialization.c */
void				init_vars(t_vars *vars);
void				init_player_state(t_vars *vars);

/* init_textures.c */
void				init_player_textures(t_vars *vars, void *mlx, int *w,
						int *h);
void				init_coin_textures(t_vars *vars, void *mlx, int *w, int *h);
void				init_exit_textures(t_vars *vars, void *mlx, int *w, int *h);
void				init_break_textures(t_vars *vars, void *mlx, int *w,
						int *h);
void				init_hole_textures(t_vars *vars, void *mlx, int *w, int *h);
void				initialize_textures(t_vars *vars);

/* free_textures.c */
void				free_textures(t_vars *vars);

/* keypress.c */
int					handle_keypress(int keycode, t_vars *vars);

#endif
