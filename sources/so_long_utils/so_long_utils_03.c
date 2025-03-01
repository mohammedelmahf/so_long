/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_03.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:42:42 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/01 12:16:52 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

int	is_wall(int x, int y, t_build *build)
{
	if (x < 0 || x >= build->width || y < 0 || y >= build->height)
		return (1);
	if (build->map[y][x] == '1' || build->map[y][x] == 'E'
		|| build->map[y][x] == 'C')
		return (1);
	return (0);
}

void	move_enemy(t_build *build)
{
	int	distance_x;
	int	distance_y;

	distance_x = build->player_x - build->enemy_x;
	distance_y = build->player_y - build->enemy_y;
	if (abs(distance_x) > abs(distance_y))
	{
		if (distance_x > 0 && !is_wall(build->enemy_x + 1, build->enemy_y,
				build))
			apply_enemy_move(build, build->enemy_x + 1, build->enemy_y);
		else if (distance_x < 0 && !is_wall(build->enemy_x - 1, build->enemy_y,
				build))
			apply_enemy_move(build, build->enemy_x - 1, build->enemy_y);
	}
	else
	{
		if (distance_y > 0 && !is_wall(build->enemy_x, build->enemy_y + 1,
				build))
			apply_enemy_move(build, build->enemy_x, build->enemy_y + 1);
		else if (distance_y < 0 && !is_wall(build->enemy_x, build->enemy_y - 1,
				build))
			apply_enemy_move(build, build->enemy_x, build->enemy_y - 1);
	}
}

void	apply_enemy_move(t_build *build, int x, int y)
{
	if (build->enemy_x > x)
		build->enemy_direction = 'd';
	else if (build->enemy_x < x)
		build->enemy_direction = 'd';
	else if (build->enemy_y > y)
		build->enemy_direction = 'd';
	else if (build->enemy_y < y)
		build->enemy_direction = 'd';
	if (build->map[y][x] == 'P')
		destroy_game(build);
	build->map[build->enemy_y][build->enemy_x] = '0';
	build->enemy_x = x;
	build->enemy_y = y;
	build->map[build->enemy_y][build->enemy_x] = 'X';
}
