/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:28:59 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/28 22:37:11 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
		error_msg("invalid input.\nclosing Game...\n");
	if (!read_map(av[1], &game))
		error_msg("Error: invalid map file.\n");
	if (!check_map(&game))
		error_msg("Error: invalid map.\n");
	if (!init_game(&game))
	{
		printf("Error in Game Initialization.\n");
		close_window(&game);
	}
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0L, close_window, &game);
	render_map(&game);
	mlx_loop(game.mlx);
	return (0);
}
