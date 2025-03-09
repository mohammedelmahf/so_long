/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:42:43 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/09 14:05:30 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

int	event_handler(int key, t_build *build)
{
	if (key == 65307)
	{
		destroy_game(build);
	}
	else if (key == 119 || key == 65362)
		move_player(build, 0, -1);
	else if (key == 97 || key == 65361)
		move_player(build, -1, 0);
	else if (key == 115 || key == 65364)
		move_player(build, 0, 1);
	else if (key == 100 || key == 65363)
		move_player(build, 1, 0);
	return (1);
}

void	move_player(t_build *build, int x, int y)
{
	if (build->player_x + x < build->width - 1 && build->player_y
		+ y < build->height - 1 && build->player_y + y > 0 && build->player_x
		+ x > 0)
	{
		if (build->map[build->player_y + y][build->player_x + x] == '0')
		{
			move_to_position(build, x, y);
		}
		else if (build->map[build->player_y + y][build->player_x + x] == 'C')
		{
			move_to_position(build, x, y);
			(build->c)--;
		}
		else if (build->map[build->player_y + y][build->player_x + x] == 'E'
			&& build->c == 0)
		{
			move_to_position(build, x, y);
			printf("you win\n");
			destroy_game(build);
		}
		else if (build->map[build->player_y + y][build->player_x + x] == 'X')
		{
			destroy_game(build);
		}
	}
}

void	move_to_position(t_build *build, int x, int y)
{
	if (x == 1)
		build->player_direction = 'r';
	else if (x == -1)
		build->player_direction = 'l';
	else if (y == 1)
		build->player_direction = 'd';
	else if (y == -1)
		build->player_direction = 'u';
	build->map[build->player_y][build->player_x] = '0';
	build->player_x += x;
	build->player_y += y;
	build->map[build->player_y][build->player_x] = 'P';
	print_moves(build);
}

void	print_moves(t_build *build)
{
	char	*moves;
	char	*tmp;

	tmp = ft_itoa(build->player_moves);
	moves = ft_strjoin("Moves : ", tmp);
	free(tmp);
	mlx_string_put(build->mlx, build->win, 0, (build->height + 0.5) * 64,
		0x00000000, moves);
	free(moves);
	(build->player_moves)++;
	tmp = ft_itoa(build->player_moves);
	moves = ft_strjoin("Moves : ", tmp);
	free(tmp);
	mlx_string_put(build->mlx, build->win, 0, (build->height + 0.5) * 64,
		0x00FFFFFF, moves);
	free(moves);
}

void	draw_ass_animated(t_build *build)
{
	int	i;
	int	j;

	i = 0;
	while (build->map[i])
	{
		j = 0;
		while (build->map[i][j])
		{
			load_animation(build, i, j);
			j++;
		}
		i++;
	}
}
