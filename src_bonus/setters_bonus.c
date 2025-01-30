/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:34:37 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/29 23:04:18 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_bonus.h"

void	set_hight_width(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	game->height = 0;
	game->width = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	if (!line)
		return ;
	game->width = ft_strlen(line);
	if (ft_strchr(line, '\n'))
		game->width--;
	while (line)
	{
		free(line);
		game->height++;
		line = get_next_line(fd);
	}
}

void	set_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->player != 1 || !check_rectangle(game))
	{
		game->pos_x = 0;
		game->pos_y = 0;
		return ;
	}
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->str_map[i][j] == 'P')
			{
				game->pos_x = j;
				game->pos_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	set_exit_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->exit != 1 || !check_rectangle(game))
	{
		game->exit_x = 0;
		game->exit_y = 0;
		return ;
	}
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->str_map[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
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

void	render_moves(t_game *game)
{
	char	*i;
	char	*c;
	int		color;
	int		w;
	int		h;

	i = ft_itoa(game->move);
	c = ft_itoa(game->collectibles);
	color = 0xFFFFFF;
	w = game->width * 60;
	h = game->height * 60;
	mlx_string_put(game->mlx, game->win, w - 100, h - 30, color, "Moves:");
	mlx_string_put(game->mlx, game->win, w - 50, h - 30, color, i);
	mlx_string_put(game->mlx, game->win, w - 100, h - 15, color, "Coins:");
	mlx_string_put(game->mlx, game->win, w - 50, h - 15, color, c);
	free(i);
	free(c);
}
