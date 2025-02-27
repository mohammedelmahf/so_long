/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:40:48 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/27 11:34:28 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"
int     check_ber(char *ber)
{
    int i;
    i = ft_strlen(ber) - 1;

    if(i < 3)
        return(0);
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

int     check_args(int ac , char **av)
{
    if(ac != 2)
    {
        ft_putstr_fd("Error : Worng  number of arguments\n" , 1);
        ft_putstr_fd("Usage : ./so_long [map.ber]\n" , 1);
        return(0);
    }
    if(!check_ber(av[1]))
    {
        ft_putstr_fd("Error : Wrong file extension\n",1);
        return(0);
    }
    if(open(av[1] , O_RDONLY) == -1)
    {
        perror("Error");
        return(0);
    }
    return(1);
}

int		check_map(t_build *build)
{
	if(!build->map)
		return(0);
	if(!check_map1(build))
		return(0);
	if(!check_map2(build))
		return(0);
	if(!check_map3(build))
		return(0);
	if(!check_map4(build))
		return(0);
	if(!check_elements(build))
		return(0);
	else
		elements_coordinates(build);
	flood_fill(build);
	return(1);
}

void    build_args(t_build *build)
{
	if (!build)
		return;
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


void	flood_fill(t_build *build)
{
	char	**duplicated_map;
	duplicated_map = copy_map(build);
	// fill(duplicated_map , build->player_x  , build->player_y);
	// if(elements_search(duplicated_map , 'C'))
	// {
	// 	ft_putstr_fd("Map is invalid\n" , 1);
	// 	free_array(duplicated_map);
	// 	destroy_game(build);
	// }
	// duplicated_map[build->player_y][build->player_x] = 'P';
	// _fill(duplicated_map , build->player_x , build->player_y);
	// if(elements_search(duplicated_map , 'E'))
	// {
	// 	ft_putstr_fd("Map is invalid\n" , 1);
	// 	free_array(duplicated_map);
	// 	destroy_game(build);
	// }
	free_array(duplicated_map);
}

char **copy_map(t_build *build)
{
	char **map;
	int i;

	i = 0;
	while(build->map[i])
		i++;
	map = malloc(sizeof(char *) * (i + 1));
	i= 0;
	while(build->map[i])
	{
		map[i] = ft_strdup_gnl(build->map[i]);
		i++;
	}
	map[i] = NULL;
	return(map);	
}

void	fill_M(char **map , int px , int py)
{
	if(map[py][px] == '1' || map[py][px] == 'X' || map[py][px] == 'E' || map[py][px] == 'M' )
		return;
	map[py][px] = 'M';
	fill(map , px + 1 , py);
	fill(map , px - 1 , py);
	fill(map , px , py + 1);
	fill(map , px , py - 1); 
}

void	fill_V(char **map, int px, int py)
{
	if (map[py][px] == '1' || map[py][px] == 'X' || map[py][px] == 'V')
		return ;
	map[py][px] = 'V';
	_fill(map, px + 1, py);
	_fill(map, px - 1, py);
	_fill(map, px, py + 1);
	_fill(map, px, py - 1);
}


// void print_map(char **map, int height)
// {
//     int i = 0;
//     while (i < height)
//     {
//         printf("%s\n", map[i]);
//         i++;
//     }
// }