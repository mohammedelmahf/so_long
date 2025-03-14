/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:55:25 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/08 13:44:15 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

int	destroy_game(t_build *build)
{
	if (build->mlx)
	{
		if (build->win)
		{
			mlx_destroy_window(build->mlx, build->win);
			mlx_destroy_image(build->mlx, build->exit_ass[0]);
			mlx_destroy_image(build->mlx, build->map_ass[0]);
			mlx_destroy_image(build->mlx, build->map_ass[1]);
			mlx_destroy_image(build->mlx, build->c_ass[0]);
			mlx_destroy_image(build->mlx, build->c_ass[1]);
			mlx_destroy_image(build->mlx, build->c_ass[2]);
			mlx_destroy_image(build->mlx, build->c_ass[3]);
			mlx_destroy_image(build->mlx, build->c_ass[4]);
			mlx_destroy_image(build->mlx, build->c_ass[5]);
			mlx_destroy_image(build->mlx, build->enemey_ass_d[0]);
			destroy_player_ass(build);
		}
		mlx_destroy_display(build->mlx);
		free(build->mlx);
	}
	free_array(build->map);
	exit(0);
	return (0);
}

void	destroy_player_ass(t_build *build)
{
	mlx_destroy_image(build->mlx, build->player_ass[0]);
	mlx_destroy_image(build->mlx, build->player_ass_u[0]);
	mlx_destroy_image(build->mlx, build->player_ass_u[1]);
	mlx_destroy_image(build->mlx, build->player_ass_u[2]);
	mlx_destroy_image(build->mlx, build->player_ass_u[3]);
	mlx_destroy_image(build->mlx, build->player_ass_u[4]);
	mlx_destroy_image(build->mlx, build->player_ass_u[5]);
	mlx_destroy_image(build->mlx, build->player_ass_u[6]);
	mlx_destroy_image(build->mlx, build->player_ass_l[0]);
	mlx_destroy_image(build->mlx, build->player_ass_l[1]);
	mlx_destroy_image(build->mlx, build->player_ass_l[2]);
	mlx_destroy_image(build->mlx, build->player_ass_l[3]);
	mlx_destroy_image(build->mlx, build->player_ass_l[4]);
	mlx_destroy_image(build->mlx, build->player_ass_l[5]);
	mlx_destroy_image(build->mlx, build->player_ass_l[6]);
	destroy_player_ass_r_d(build);
}

void	destroy_player_ass_r_d(t_build *build)
{
	mlx_destroy_image(build->mlx, build->player_ass_r[0]);
	mlx_destroy_image(build->mlx, build->player_ass_r[1]);
	mlx_destroy_image(build->mlx, build->player_ass_r[2]);
	mlx_destroy_image(build->mlx, build->player_ass_r[3]);
	mlx_destroy_image(build->mlx, build->player_ass_r[4]);
	mlx_destroy_image(build->mlx, build->player_ass_r[5]);
	mlx_destroy_image(build->mlx, build->player_ass_r[6]);
	mlx_destroy_image(build->mlx, build->player_ass_d[0]);
	mlx_destroy_image(build->mlx, build->player_ass_d[1]);
	mlx_destroy_image(build->mlx, build->player_ass_d[2]);
	mlx_destroy_image(build->mlx, build->player_ass_d[3]);
	mlx_destroy_image(build->mlx, build->player_ass_d[4]);
	mlx_destroy_image(build->mlx, build->player_ass_d[5]);
	mlx_destroy_image(build->mlx, build->player_ass_d[6]);
}
