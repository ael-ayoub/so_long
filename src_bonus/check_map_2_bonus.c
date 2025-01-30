/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:17:47 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/29 22:55:29 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_bonus.h"

int	check_extension(char *path)
{
	char	*dot;

	if (!path)
		return (0);
	dot = ft_strchr(path, '.');
	if (!dot)
		return (0);
	if (ft_strncmp(dot, ".ber", ft_strlen(dot)) != 0)
		return (0);
	return (1);
}

int	check_rectangle(t_game *game)
{
	int	i;

	i = 0;
	if (!game || !game->str_map)
		return (0);
	game->width = ft_strlen(game->str_map[0]);
	while (i < game->height)
	{
		if (ft_strlen(game->str_map[i]) != game->width)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(t_game *game)
{
	int	i;
	int	hight;
	int	width;

	i = 0;
	hight = game->height;
	width = game->width;
	while (i < hight)
	{
		if (game->str_map[i][0] != '1' || game->str_map[i][width - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < width - 1)
	{
		if (game->str_map[0][i] != '1' || game->str_map[hight - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_game *game)
{
	int	valid;

	valid = 0;
	if (!check_rectangle(game))
		valid = 1;
	else if (!check_wall(game))
		valid = 1;
	else if (!check_char(game))
		valid = 1;
	else if (!check_path(game))
		valid = 1;
	if (valid)
	{
		free_map(game);
		return (0);
	}
	return (1);
}

int	check_path(t_game *game)
{
	int		exit;
	int		c;
	char	**copy;

	copy = creat_copy(game);
	c = game->collectibles;
	exit = game->exit;
	player_move(game, game->pos_x, game->pos_y);
	free_map(game);
	game->str_map = copy;
	if (game->collectibles == 0 && game->exit == 0)
	{
		game->collectibles = c;
		game->exit = exit;
		return (1);
	}
	else
		return (0);
}
