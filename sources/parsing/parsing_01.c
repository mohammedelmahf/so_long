/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:40:48 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/09 15:18:28 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

int	check_ber(char *ber)
{
	int	i;

	i = ft_strlen(ber) - 1;
	if (i < 3)
		return (0);
	if (ber[i] != 'r')
		return (0);
	if (ber[i - 1] != 'e')
		return (0);
	if (ber[i - 2] != 'b')
		return (0);
	if (ber[i - 3] != '.')
		return (0);
	return (1);
}

int	check_args(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error\nWorng  number of arguments\n", 1);
		ft_putstr_fd("Usage : ./so_long [map.ber]\n", 1);
		return (0);
	}
	if (!check_ber(av[1]))
	{
		ft_putstr_fd("Error\nWrong file extension\n", 1);
		return (0);
	}
	if (open(av[1], O_RDONLY) == -1)
	{
		perror("Error");
		return (0);
	}
	return (1);
}

int	check_map(t_build *build)
{
	if (!build->map)
		return (0);
	if (!check_map1(build))
		return (0);
	if (!check_map2(build))
		return (0);
	if (!check_map3(build))
		return (0);
	if (!check_map4(build))
		return (0);
	if (!check_elements(build))
		return (0);
	else
		elements_coordinates(build);
	if (!flood_fill(build))
		return (0);
	return (1);
}

void	build_args(t_build *build)
{
	if (!build)
		return ;
	build->map = NULL;
	build->player = 0;
	build->player_x = 0;
	build->player_y = 0;
	build->player_direction = 'r';
	build->player_moves = 0;
	build->c = 0;
	build->exit = 0;
	build->exit_x = 0;
	build->exit_y = 0;
	build->enemy = 0;
	build->enemy_x = 0;
	build->enemy_y = 0;
	build->enemy_direction = 'l';
	build->width = 0;
	build->height = 0;
}

int	flood_fill(t_build *build)
{
	char	**duplicated_map;

	duplicated_map = copy_map(build);
	if (!duplicated_map)
	{
		ft_putstr_fd("Error\nFailed to duplicate map\n", 2);
		return (0);
	}
	fill_m(duplicated_map, build->player_x, build->player_y);
	if (elements_search(duplicated_map, 'C'))
	{
		ft_putstr_fd("Error\nMap is invalid\n", 1);
		free_array(duplicated_map);
		return (0);
	}
	duplicated_map[build->player_y][build->player_x] = 'P';
	fill_v(duplicated_map, build->player_x, build->player_y);
	if (elements_search(duplicated_map, 'E'))
	{
		ft_putstr_fd("Error\nMap is invalid\n", 1);
		free_array(duplicated_map);
		return (0);
	}
	free_array(duplicated_map);
	return (1);
}
