/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_05.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:27:56 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/05 22:00:43 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

int	x_frames_calculator(void)
{
	static long long	last_time;
	long long			current_time;

	current_time = current_time_in_ms();
	if (current_time - last_time >= 100)
	{
		last_time = current_time;
		return (1);
	}
	return (0);
}



void	animate_c(t_build *build, int x, int y)
{
	static int	i;

	mlx_put_image_to_window(build->mlx, build->win, build->map_ass[1], y * 64, x
		* 64);
	mlx_put_image_to_window(build->mlx, build->win, build->c_ass[i], y * 64, x
		* 64);
	if (c_frames_calculator())
	{
		i++;
		if (i >= 4)
			i = 0;
	}
}
void	animate_player(t_build *build, int x, int y)
{
	static int	i;

	mlx_put_image_to_window(build->mlx, build->win, build->map_ass[1], y * 64, x
		* 64);
	if (build->player_direction == 'r')
		mlx_put_image_to_window(build->mlx, build->win, build->player_ass_r[i],
			y * 64, x * 64);
	else if (build->player_direction == 'l')
		mlx_put_image_to_window(build->mlx, build->win, build->player_ass_l[i],
			y * 64, x * 64);
	else if (build->player_direction == 'u')
		mlx_put_image_to_window(build->mlx, build->win, build->player_ass_u[i],
			y * 64, x * 64);
	else if (build->player_direction == 'd')
		mlx_put_image_to_window(build->mlx, build->win, build->player_ass_d[i],
			y * 64, x * 64);
	else
		mlx_put_image_to_window(build->mlx, build->win, build->player_ass[0],
			y * 64, x * 64);
	if (p_frames_calculator())
	{
		i++;
		if (i >= 6)
			i = 0;
	}
}

void	animate_enemy(t_build *build, int x, int y)
{
	static int	i;

	mlx_put_image_to_window(build->mlx, build->win, build->map_ass[1], y * 64, x
		* 64);
	if (build->enemy_direction == 'r')
		mlx_put_image_to_window(build->mlx, build->win, build->enemey_ass_r[i],
			y * 64, x * 64);
	else if (build->enemy_direction == 'l')
		mlx_put_image_to_window(build->mlx, build->win, build->enemey_ass_l[i],
			y * 64, x * 64);
	else if (build->enemy_direction == 'u')
		mlx_put_image_to_window(build->mlx, build->win, build->enemey_ass_u[i],
			y * 64, x * 64);
	else
		mlx_put_image_to_window(build->mlx, build->win, build->enemey_ass_d[i],
			y * 64, x * 64);
	if (x_frames_calculator())
	{
		i++;
		if (i >= 1)
			i = 0;
	}
}

void	load_animation(t_build *build, int x, int y)
{
	if (build->map[x][y] == '0')
		mlx_put_image_to_window(build->mlx, build->win, build->map_ass[1], y
			* 64, x * 64);
	else if (build->map[x][y] == '1')
		mlx_put_image_to_window(build->mlx, build->win, build->map_ass[0], y
			* 64, x * 64);
	else if (build->map[x][y] == 'P')
		animate_player(build, x, y);
	else if (build->map[x][y] == 'E')
	{
		if (build->c == 0)
			mlx_put_image_to_window(build->mlx, build->win, build->c_ass[5], y
				* 64, x * 64);
	}
	else if (build->map[x][y] == 'C')
		animate_c(build, x, y);
	else if (build->map[x][y] == 'X')
		animate_enemy(build, x, y);
}
