/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:24:13 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/23 12:38:47 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char **arg_to_map(char **av)
{
    int fd;
    char *line;
    char *map_1d;
    char **map_2d;
    
    fd = open(av[1] , O_RDONLY);
    line = get_next_line(fd);
    if(!line)
    {
        ft_putstr_fd("Map is empty\n" , 1);
        exit(0);
    }
    map_1d = ft_strdup_gnl("");
    while(line)
    {
        map_1d = ft_strjoin_gnl(map_1d , line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    map_2d = ft_split(map_1d , '\n');
    free(line);
    free(map_1d);
    return(map_2d);
}

int     count_line(t_build *build)
{
    int i;
    i = 0;
    while(build->map[i])
        i++;
    return(i);
}

int check_map1(t_build *build)
{
    int i;
    i = 0;
    
    while (build->map[0][i])
    {
        if(build->map[0][i] != '1')
        {
            ft_putstr_fd("Error : Invalid top border (not a wall).\n" ,1);
            return(0);
        }
        i++;
    }
    i = 0;
    while (build->map[count_line(build) - 1 ][i])
    {
        if(build->map[count_line(build) - 1 ][i] != '1')
        {
            ft_putstr_fd("Error : Invalid bottom border (not a wall).\n" , 1);
            return(0);
        }
        i++;
    }
    return(1);
}

int     check_map2(t_build *build)
{
    int i ;
    size_t len;

    len = ft_strlen(build->map[0]);
    i = 0;

    while(build->map[i])
    {
        if(ft_strlen(build->map[i]) != len)
        {
            ft_putstr_fd("Map is not rectangular\n" , 1);
            return(0);
        }
        i++;
    }
    return(1);
}

int     check_map3(t_build *build)
{
    int i;
    i = 0;

    while(build->map[i])
    {
        if(build->map[i][0] != '1' || build->map[i][ft_strlen(build->map[i]) - 1] != '1')
        {
            ft_putstr_fd("Map is not valid\n",1);
            return(0);
        }
        i++;
    }
    return(1);
}

int     check_map4(t_build *build)
{
    int i;
    int j;

    i = 0;

    while(build->map[i])
    {
        j = 0;
        while(build->map[i][j])
        {
            printf("%d" ,build->map[i][j]);
            if(!ft_strchr("10PECX" , build->map[i][j]))
                return(0);
            j++;
        }
        i++;
    }
    return(1);
}

int     check_elements(t_build *build)
{
    
}