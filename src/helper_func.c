/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:03:32 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/28 09:36:17 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_game *game)
{
	int	i;

	free_map(game);
	i = 0;
	while (i < 5)
	{
		if (game->img[i])
			mlx_destroy_image(game->mlx, game->img[i]);
		i++;
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_putstr_fd("Closing the Game ...\n", 1);
	exit(0);
}

void	print_move(int move)
{
	if (move != 0)
	{
		ft_putstr_fd("move: ", 1);
		ft_putnbr_fd(move, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	print_2d(int size, char **array)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%s\n", array[i]);
		i++;
	}
}

void	free_2d_array(int size, char **array)
{
	int	i;

	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(*array);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->str_map)
	{
		while (i < game->height)
		{
			free(game->str_map[i]);
			i++;
		}
		free(game->str_map);
		game->str_map = NULL;
	}
}
