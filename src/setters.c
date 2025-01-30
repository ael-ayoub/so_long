/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:34:37 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/29 21:51:15 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		game->x = 0;
		game->y = 0;
		return ;
	}
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->str_map[i][j] == 'E')
			{
				game->x = j;
				game->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	render_help(t_game *game, int i, int j)
{
	int	w;
	int	h;

	w = i * 60;
	h = j * 60;
	if (game->str_map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img[0], h, w);
	else if (game->str_map[i][j] == '0' || (game->str_map[i][j] == 'E'
				&& game->collectibles != 0))
		mlx_put_image_to_window(game->mlx, game->win, game->img[3], h, w);
	else if (game->str_map[i][j] == 'E' && game->collectibles == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img[2], h, w);
	else if (game->str_map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img[1], h, w);
	else if (game->str_map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img[4], h, w);
}

int	render_map(t_game *game)
{
	int			i;
	static int	prev;
	int			j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			render_help(game, i, j);
			j++;
		}
		i++;
	}
	if (prev != game->move)
	{
		print_move(game->move);
		prev = game->move;
	}
	return (0);
}
