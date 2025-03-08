/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_path02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:20:28 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/08 21:06:00 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

void	register_player_ass(t_build *build)
{
	int		i;
	int		h;
	int		w;
	char	*path[1];

	i = 0;
	path[0] = "assets/player/playerdown/01.xpm";
	while (i < 1)
	{
		build->player_ass[i] = mlx_xpm_file_to_image(build->mlx, path[i], &w,
				&h);
		if (!build->player_ass[i] || w > 64 || h > 64)
		{
			ft_putstr_fd("Error registring player assets !\n", 1);
			destroy_game(build);
		}
		i++;
	}
}

void	register_player_c_ass(t_build *build)
{
	int		i;
	int		w;
	int		h;
	char	*path[6];

	i = 0;
	path[0] = "assets/coin/01.xpm";
	path[1] = "assets/coin/02.xpm";
	path[2] = "assets/coin/03.xpm";
	path[3] = "assets/coin/04.xpm";
	path[4] = "assets/coin/05.xpm";
	path[5] = "assets/exit/02.xpm";
	while (i < 6)
	{
		build->c_ass[i] = mlx_xpm_file_to_image(build->mlx, path[i], &w, &h);
		if (!build->c_ass[i] || w > 64 || h > 64)
		{
			exit(0);
			ft_putstr_fd("Error registring collectibles assets !\n", 1);
			destroy_game(build);
		}
		i++;
	}
}

void	register_enemy_ass_d(t_build *build)
{
	int		i;
	int		w;
	int		h;
	char	*path[1];

	i = 0;
	path[0] = "assets/enemy/01.xpm";
	while (i < 1)
	{
		build->enemey_ass_d[i] = mlx_xpm_file_to_image(build->mlx, path[i], &w,
				&h);
		if (!build->enemey_ass_d[i] || w > 64 || h > 64)
		{
			ft_putstr_fd("Error registring enemy assets !\n", 1);
			destroy_game(build);
		}
		i++;
	}
}

void	register_exit_ass(t_build *build)
{
	int		i;
	int		h;
	int		w;
	char	*path[1];

	i = 0;
	path[0] = "assets/exit/01.xpm";
	while (i < 1)
	{
		build->exit_ass[i] = mlx_xpm_file_to_image(build->mlx, path[i], &w, &h);
		if (!build->exit_ass[i] || w > 64 || h > 64)
		{
			ft_putstr_fd("Error registring exit assets !\n", 1);
			destroy_game(build);
		}
		i++;
	}
}

void	register_ass_path(t_build *build)
{
	register_map_ass(build);
	register_player_ass(build);
	register_player_ass_u(build);
	register_player_ass_r(build);
	register_player_ass_l(build);
	register_player_ass_d(build);
	register_player_c_ass(build);
	register_enemy_ass_d(build);
	register_exit_ass(build);
}
