/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:13:15 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/29 16:29:43 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_char(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->str_map[i][j] != '\0')
		{
			c = game->str_map[i][j];
			if (c != 'C' && c != 'E' && c != 'P' && c != '0' && c != '1')
				return (0);
			j++;
		}
		i++;
	}
	if (game->collectibles < 1 || game->player != 1 || game->exit != 1)
		return (0);
	else
		return (1);
}

int	check_valid_move(t_game *game, int x, int y)
{
	if (!game->str_map)
		return (0);
	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return (0);
	else if (game->str_map[y][x] == '1' || game->str_map[y][x] == 'V')
		return (0);
	return (1);
}

void	player_move(t_game *game, int x, int y)
{
	if (!check_valid_move(game, x, y))
		return ;
	if (game->str_map[y][x] == 'C')
		game->collectibles--;
	if (game->str_map[y][x] == 'E')
		game->exit--;
	game->str_map[y][x] = 'V';
	player_move(game, x + 1, y);
	player_move(game, x - 1, y);
	player_move(game, x, y - 1);
	player_move(game, x, y + 1);
}

char	**creat_copy(t_game *game)
{
	int		i;
	char	**copy;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!copy)
		return (NULL);
	while (i < game->height)
	{
		copy[i] = ft_strdup(game->str_map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
