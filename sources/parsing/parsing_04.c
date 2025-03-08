/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_04.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:07:18 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/08 22:23:00 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

int	check_map3(t_build *build)
{
	int	i;

	i = 0;
	while (build->map[i])
	{
		if (build->map[i][0] != '1' || build->map[i][ft_strlen(build->map[i])
			- 1] != '1')
		{
			ft_putstr_fd("Error\nMap is not valid\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map4(t_build *build)
{
	int	i;
	int	j;

	i = 0;
	while (build->map[i])
	{
		j = 0;
		while (build->map[i][j])
		{
			if (!ft_strchr("10PECX", build->map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_elements(t_build *build)
{
	elements_counter(build);
	if (build->c < 1)
	{
		ft_putstr_fd("Error\nWrong number of collectibles\n", 1);
		return (0);
	}
	if (build->player != 1)
	{
		ft_putstr_fd("Error\nWrong number of players\n", 1);
		return (0);
	}
	if (build->exit != 1)
	{
		ft_putstr_fd("Error\nWrong number of exits\n", 1);
		return (0);
	}
	if (build->enemy < 1)
	{
		ft_putstr_fd("Error\nWrong number of enemies\n", 1);
		return (0);
	}
	return (1);
}

void	elements_counter(t_build *build)
{
	int	i;
	int	j;

	i = 0;
	while (build->map[i])
	{
		j = 0;
		while (build->map[i][j])
		{
			if (build->map[i][j] == 'E')
				build->exit++;
			if (build->map[i][j] == 'P')
				build->player++;
			if (build->map[i][j] == 'C')
				build->c++;
			if (build->map[i][j] == 'X')
				build->enemy++;
			j++;
		}
		i++;
	}
	build->width = j;
	build->height = i;
}

void	elements_coordinates(t_build *build)
{
	int	i;
	int	j;

	i = 0;
	while (build->map[i])
	{
		j = 0;
		while (build->map[i][j])
		{
			saving_elements_coordinates(build, i, j);
			j++;
		}
		i++;
	}
}
