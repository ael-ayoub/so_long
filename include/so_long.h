/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:32:23 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/29 16:38:01 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	//read_map:
	int		collectibles;
	int		exit;
	int		player;
	int		pos_x;
	int		pos_y;
	char	**str_map;
	int		height;
	int		width;
	int		x;
	int		y;
	// init game :
	int		move;
	void	*win;
	void	*mlx;
	void	*img[5];
}			t_game;

char		*get_next_line(int fd);
//********************check functions**********************
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
void		print_move(int move);
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
void		set_exit_position(t_game *game);
int			read_map(char *filename, t_game *game);
void		render_help(t_game *game, int i, int j);
int			render_map(t_game *game);

#endif