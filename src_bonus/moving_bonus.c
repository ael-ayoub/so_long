/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:29:54 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/29 21:54:29 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_bonus.h"

int	check_valid_move_1(t_game *game, int x, int y)
{
	if (!game->str_map)
		return (0);
	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return (0);
	else if (game->str_map[y][x] == '1')
		return (0);
	return (1);
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (game->str_map[y][x - 1] == 'M')
		error_msg_clear("You touch enemy\n", game);
	if (game->str_map[y][x - 1] == 'C')
		game->collectibles--;
	else if (game->str_map[y][x - 1] == 'E' && game->collectibles == 0)
		game->exit--;
	game->str_map[y][x] = '0';
	game->str_map[y][x - 1] = 'P';
	game->pos_x--;
	game->move++;
	set_player_position(game);
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (game->str_map[y][x + 1] == 'M')
		error_msg_clear("You touch enemy\n", game);
	if (game->str_map[y][x + 1] == 'C')
		game->collectibles--;
	else if (game->str_map[y][x + 1] == 'E' && game->collectibles == 0)
		game->exit--;
	game->str_map[y][x] = '0';
	game->str_map[y][x + 1] = 'P';
	game->pos_x++;
	game->move++;
	set_player_position(game);
}

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (game->str_map[y - 1][x] == 'M')
		error_msg_clear("You touch enemy\n", game);
	if (game->str_map[y - 1][x] == 'C')
		game->collectibles--;
	else if (game->str_map[y - 1][x] == 'E' && game->collectibles == 0)
		game->exit--;
	game->str_map[y][x] = '0';
	game->str_map[y - 1][x] = 'P';
	game->pos_y--;
	game->move++;
	set_player_position(game);
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (game->str_map[y + 1][x] == 'M')
		error_msg_clear("You touch enemy\n", game);
	if (game->str_map[y + 1][x] == 'C')
		game->collectibles--;
	else if (game->str_map[y + 1][x] == 'E' && game->collectibles == 0)
		game->exit--;
	game->str_map[y][x] = '0';
	game->str_map[y + 1][x] = 'P';
	game->pos_y++;
	game->move++;
	set_player_position(game);
}
