/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inite_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:26:42 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/29 23:03:19 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	game->collectibles = 0;
	game->exit = 0;
	game->player = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < ft_strlen(game->str_map[i]))
		{
			if (game->str_map[i][j] == 'P')
				game->player++;
			else if (game->str_map[i][j] == 'C')
				game->collectibles++;
			else if (game->str_map[i][j] == 'E')
				game->exit++;
			j++;
		}
		i++;
	}
	set_player_position(game);
	set_exit_position(game);
}

char	**fill_map(t_game *game, char *filename)
{
	char	**map;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < game->height)
	{
		map[i] = get_next_line(fd);
		if (ft_strchr(map[i], '\n'))
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	init_game(t_game *game)
{
	int	w;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	w = 60;
	game->win = mlx_new_window(game->mlx, game->width * 60, game->height * 60,
			"so_long Game");
	if (!game->win)
		return (0);
	game->img[0] = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm", &w, &w);
	game->img[1] = mlx_xpm_file_to_image(game->mlx, "img/player.xpm", &w, &w);
	game->img[2] = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm", &w, &w);
	game->img[3] = mlx_xpm_file_to_image(game->mlx, "img/empty.xpm", &w, &w);
	game->img[4] = mlx_xpm_file_to_image(game->mlx, "img/coll.xpm", &w, &w);
	if (!game->img[0] || !game->img[1] || !game->img[2] || !game->img[3]
		|| !game->img[4])
		return (0);
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == LEFT_ARROW && check_valid_move_1(game, game->pos_x - 1,
			game->pos_y))
		move_left(game);
	else if (keycode == RIGHT_ARROW && check_valid_move_1(game, game->pos_x + 1,
			game->pos_y))
		move_right(game);
	else if (keycode == UP_ARROW && check_valid_move_1(game, game->pos_x,
			game->pos_y - 1))
		move_up(game);
	else if (keycode == DOWN_ARROW && check_valid_move_1(game, game->pos_x,
			game->pos_y + 1))
		move_down(game);
	else if (keycode == ESC_KEY)
		close_window(game);
	if (game->collectibles == 0)
		game->str_map[game->y][game->x] = 'E';
	if (game->exit == 0)
	{
		ft_putstr_fd("You Win.\n", 1);
		close_window(game);
	}
	render_map(game);
	return (0);
}

int	read_map(char *filename, t_game *game)
{
	if (!check_extension(filename))
		return (0);
	set_hight_width(filename, game);
	set_hight_width(filename, game);
	if (game->height == 0 || game->width == 0)
		return (0);
	game->str_map = fill_map(game, filename);
	if (!game->str_map)
		return (0);
	init_map(game);
	game->move = 0;
	return (1);
}
