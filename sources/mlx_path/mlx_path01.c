/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_path01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:12:06 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/27 12:00:50 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

void    register_map_ass(t_build *build)
{
    int i;
    int w;
    int h;
    char *path[2];

    i = -1;
    path[0] = "assets/map/wall.xpm";
    path[0] = "assets/map/floor.xpm";
    while(++i < 2)
    {
        print_map(build);
        build->map_ass[i] = mlx_xpm_file_to_image(build->mlx , path[i] , &w , &h);
        if(!build->map_ass[i] || w > 64 || h > 64)
        {
            printf("w--->%d\nh--->%d\n", w , h);
            ft_putstr_fd("Error registring map assets !\n" , 1);
            destroy_game(build);
        }
    }
}

// void    register_player_ass_u(t_build *build)
// {
    
// }

void    register_ass_path(t_build *build)
{
    register_map_ass(build);
    // register_player_ass_u(build);
}