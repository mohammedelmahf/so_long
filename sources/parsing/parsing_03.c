/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:07:22 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/08 13:41:21 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

char	**copy_map(t_build *build)
{
	char	**map;
	int		i;

	i = 0;
	while (build->map[i])
		i++;
	map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (build->map[i])
	{
		map[i] = ft_strdup_gnl(build->map[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	fill_m(char **map, int px, int py)
{
	if (map[py][px] == '1' || map[py][px] == 'X' || map[py][px] == 'E'
		|| map[py][px] == 'M')
		return ;
	if (map[py][px] == '1' || map[py][px] == 'X' || map[py][px] == 'E' || map[py][px] == 'M')
		return;
	map[py][px] = 'M';
	fill_m(map, px + 1, py);
	fill_m(map, px - 1, py);
	fill_m(map, px, py + 1);
	fill_m(map, px, py - 1);
}

void	fill_v(char **map, int px, int py)
{
	if (map[py][px] == '1' || map[py][px] == 'X' || map[py][px] == 'V')
		return ;
	if (map[py][px] == '1' || map[py][px] == 'X' || map[py][px] == 'V')
		return;
	map[py][px] = 'V';
	fill_v(map, px + 1, py);
	fill_v(map, px - 1, py);
	fill_v(map, px, py + 1);
	fill_v(map, px, py - 1);
}

void	saving_elements_coordinates(t_build *build, int i, int j)
{
	if (build->map[i][j] == 'E')
	{
		build->exit_x = j;
		build->exit_y = i;
	}
	if (build->map[i][j] == 'P')
	{
		build->player_x = j;
		build->player_y = i;
	}
	if (build->map[i][j] == 'X')
	{
		build->enemy_x = j;
		build->enemy_y = i;
	}
}

int	elements_search(char **map, char a)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], a))
			return (1);
		i++;
	}
	return (0);
}
