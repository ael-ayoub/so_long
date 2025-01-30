/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:48:00 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/29 22:54:18 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_BONUS_H
# define SO_BONUS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define ESC_KEY 65307

typedef struct s_game
{
	int		collectibles;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		player;
	int		enemy;
	int		pos_x;
	int		pos_y;
	char	**str_map;
	int		height;
	int		width;
	int		move;
	void	*win;
	void	*mlx;
	void	*animation[8];
	int		frame_timer;
	int		current_frame;
	void	*img[5];
}			t_game;

char		*get_next_line(int fd);
void		error_msg(char *msg);
void		error_msg_clear(char *msg, t_game *game);
/********************check functions**********************/
int			check_extension(char *path);
int			check_rectangle(t_game *game);
int			check_wall(t_game *game);
int			check_map(t_game *game);
int			check_path(t_game *game);
int			check_char(t_game *game);
int			check_valid_move(t_game *game, int x, int y);
void		player_move(t_game *game, int x, int y);
char		**creat_copy(t_game *game);
/* ************************************************************************** */
int			close_window(t_game *game);
void		print_2d(int size, char **array);
void		free_2d_array(int size, char **array);
void		free_map(t_game *game);
/* ************************************************************************** */
void		init_map(t_game *game);
char		**fill_map(t_game *game, char *filename);
int			init_game(t_game *game);
int			key_hook(int keycode, t_game *game);
/* ************************************************************************** */
int			check_valid_move_1(t_game *game, int x, int y);
void		move_left(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_right(t_game *game);
/* ************************************************************************** */
void		set_hight_width(char *filename, t_game *game);
void		set_player_position(t_game *game);
int			read_map(char *filename, t_game *game);
void		render_help(t_game *game, int i, int j);
int			render_map(t_game *game);
void		set_exit_position(t_game *game);
int			check_animation(t_game *game);
void		render_moves(t_game *game);
#endif