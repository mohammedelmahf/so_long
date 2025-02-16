/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:24:13 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/16 14:29:12 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char **arg_to_map(char *av)
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
    map_1d = ft_strdup("");
    while(line)
    {
        map_1d = ft_strjoin_gnl(map_1d , line);
        line = get_next_line(fd);
    }
    close(fd);
    map_2d = ft_split(map_1d , '\n');
    free(line);
    free(map_1d);
    return(map_2d);
}