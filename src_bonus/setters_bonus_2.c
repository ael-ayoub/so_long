/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_bonus_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:11:57 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/29 22:13:47 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_bonus.h"

void	render_help(t_game *game, int i, int j)
{
	int	w;
	int	h;

	game->frame_timer++;
	if (game->frame_timer >= 10)
	{
		game->current_frame = (game->current_frame + 1) % 8;
		game->frame_timer = 0;
	}
	w = i * 60;
	h = j * 60;
	if (game->str_map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img[0], h, w);
	else if (game->str_map[i][j] == '0' || (game->str_map[i][j] == 'E'
				&& game->collectibles > 0))
		mlx_put_image_to_window(game->mlx, game->win, game->img[3], h, w);
	else if (game->str_map[i][j] == 'E' && game->collectibles == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img[2], h, w);
	else if (game->str_map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img[1], h, w);
	else if (game->str_map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img[4], h, w);
	else if (game->str_map[i][j] == 'M')
		mlx_put_image_to_window(game->mlx, game->win,
			game->animation[game->current_frame], h, w);
}

int	render_map(t_game *game)
{
	int	i;
	int	j;

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
	render_moves(game);
	return (0);
}

int	check_valid_move_enemy(t_game *game, int x, int y)
{
	if (!game->str_map)
		return (0);
	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return (0);
	else if (game->str_map[y][x] == '1')
		return (0);
	return (1);
}
