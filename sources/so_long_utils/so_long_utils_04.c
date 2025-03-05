/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_04.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:27:58 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/05 22:06:40 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

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

int	render_map(t_build *build)
{
	if (m_frames_calculator())
		move_enemy(build);
	draw_ass_animated(build);
	return (0);
}
