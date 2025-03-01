/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:42:43 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/01 13:31:14 by maelmahf         ###   ########.fr       */
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

int	render_map(t_build *build)
{
	if (m_frames_calculator())
		move_enemy(build);
	draw_ass_animated(build);
	return (0);
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
		mlx_put_image_to_window(build->mlx, build->win, build->player_ass_d[0],
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

int	p_frames_calculator(void)
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
long long	current_time_in_ms(void)
{
	struct timeval	te;
	long long		milliseconds;

	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (milliseconds);
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

int	c_frames_calculator(void)
{
	static long long	last_time;
	long long			current_time;

	current_time = current_time_in_ms();
	if (current_time - last_time >= 150)
	{
		last_time = current_time;
		return (1);
	}
	return (0);
}

int	m_frames_calculator(void)
{
	static long long	last_time;
	long long			current_time;

	current_time = current_time_in_ms();
	if (current_time - last_time >= 300)
	{
		last_time = current_time;
		return (1);
	}
	return (0);
}
