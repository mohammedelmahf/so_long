/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_path01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:12:06 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/08 22:23:22 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

void	register_map_ass(t_build *build)
{
	int		i;
	int		w;
	int		h;
	char	*path[2];

	i = -1;
	path[0] = "assets/map/wall.xpm";
	path[1] = "assets/map/floor.xpm";
	while (++i < 2)
	{
		build->map_ass[i] = mlx_xpm_file_to_image(build->mlx, path[i], &w, &h);
		if (!build->map_ass[i] || w > 64 || h > 64)
		{
			ft_putstr_fd("Error\nregistring map assets !\n", 1);
			destroy_game(build);
		}
	}
}

void	register_player_ass_u(t_build *build)
{
	int		i;
	int		h;
	int		w;
	char	*path[7];

	i = 0;
	path[0] = "assets/player/playerup/01.xpm";
	path[1] = "assets/player/playerup/02.xpm";
	path[2] = "assets/player/playerup/03.xpm";
	path[3] = "assets/player/playerup/04.xpm";
	path[4] = "assets/player/playerup/05.xpm";
	path[5] = "assets/player/playerup/06.xpm";
	path[6] = "assets/player/playerup/07.xpm";
	while (i < 7)
	{
		build->player_ass_u[i] = mlx_xpm_file_to_image(build->mlx, path[i], &w,
				&h);
		if (!build->player_ass_u[i] || w > 64 || h > 64)
		{
			ft_putstr_fd("Error\nregistring player up assets !\n", 1);
			destroy_game(build);
		}
		i++;
	}
}

void	register_player_ass_d(t_build *build)
{
	int		i;
	int		h;
	int		w;
	char	*path[7];

	i = 0;
	path[0] = "assets/player/playerdown/01.xpm";
	path[1] = "assets/player/playerdown/02.xpm";
	path[2] = "assets/player/playerdown/03.xpm";
	path[3] = "assets/player/playerdown/04.xpm";
	path[4] = "assets/player/playerdown/05.xpm";
	path[5] = "assets/player/playerdown/06.xpm";
	path[6] = "assets/player/playerdown/07.xpm";
	while (i < 7)
	{
		build->player_ass_d[i] = mlx_xpm_file_to_image(build->mlx, path[i], &w,
				&h);
		if (!build->player_ass_d[i] || w > 64 || h > 64)
		{
			ft_putstr_fd("Error\nregistring player down assets !\n", 1);
			destroy_game(build);
		}
		i++;
	}
}

void	register_player_ass_r(t_build *build)
{
	int		i;
	int		h;
	int		w;
	char	*path[7];

	i = 0;
	path[0] = "assets/player/playerright/01.xpm";
	path[1] = "assets/player/playerright/02.xpm";
	path[2] = "assets/player/playerright/03.xpm";
	path[3] = "assets/player/playerright/04.xpm";
	path[4] = "assets/player/playerright/05.xpm";
	path[5] = "assets/player/playerright/06.xpm";
	path[6] = "assets/player/playerright/07.xpm";
	while (i < 7)
	{
		build->player_ass_r[i] = mlx_xpm_file_to_image(build->mlx, path[i], &w,
				&h);
		if (!build->player_ass_r[i] || w > 64 || h > 64)
		{
			ft_putstr_fd("Error\nregistring player right assets !\n", 1);
			destroy_game(build);
		}
		i++;
	}
}

void	register_player_ass_l(t_build *build)
{
	int		i;
	int		h;
	int		w;
	char	*path[7];

	i = 0;
	path[0] = "assets/player/playerleft/01.xpm";
	path[1] = "assets/player/playerleft/02.xpm";
	path[2] = "assets/player/playerleft/03.xpm";
	path[3] = "assets/player/playerleft/04.xpm";
	path[4] = "assets/player/playerleft/05.xpm";
	path[5] = "assets/player/playerleft/06.xpm";
	path[6] = "assets/player/playerleft/07.xpm";
	while (i < 7)
	{
		build->player_ass_l[i] = mlx_xpm_file_to_image(build->mlx, path[i], &w,
				&h);
		if (!build->player_ass_l[i] || w > 64 || h > 64)
		{
			ft_putstr_fd("Error\nregistring player left assets !\n", 1);
			destroy_game(build);
		}
		i++;
	}
}
