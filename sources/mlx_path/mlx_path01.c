/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_path01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:12:06 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/27 13:48:27 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

void    register_map_ass(t_build *build)
{
    int i;
    int w;
    int h;
    char *path[2];

    i = 0;
    path[0] = "assets/map/wall.xpm";
    path[1] = "assets/map/floor.xpm";
    while(i < 2)
    {
        build->map_ass[i] = mlx_xpm_file_to_image(build->mlx , path[i] , &w , &h);
        if(!build->map_ass[i] || w > 64 || h > 64)
        {
            ft_putstr_fd("Error registring map assets !\n" , 1);
            destroy_game(build);
        }
        i++;
    }
}

void    register_player_ass_u(t_build *build)
{
    int i;
    int h;
    int w;
    char *path[7];

    i = 0;
    path[0] = "assets/player/playerup01.xpm";
    path[1] = "assets/player/playerup02.xpm";
    path[2] = "assets/player/playerup03.xpm";
    path[3] = "assets/player/playerup04.xpm";
    path[4] = "assets/player/playerup05.xpm";
    path[5] = "assets/player/playerup06.xpm";
    path[6] = "assets/player/playerup07.xpm";
    while(i < 4)
    {
        build->player_ass_u[i] = mlx_xpm_file_to_image(build->mlx ,path[i] , &w , &h);
        if(!build->player_ass_r[i] || w > 64 || h > 64)
        {
            ft_putstr_fd("Error registring map assets !\n",1);
            destroy_game(build);
        }
        i++;
    }
}

void    register_player_ass_d(t_build *build)
{
    int i;
    int h;
    int w;
    char *path[4];

    i = 0;
    path[0] = "";
    path[1] = "";
    path[2] = "";
    path[3] = "";
    while(i < 4)
    {
        build->player_ass_d[i] = mlx_xpm_file_to_image(build->mlx ,path[i] , &w , &h);
        if(!build->player_ass_d[i] || w > 64 || h > 64)
        {
            ft_putstr_fd("Error registring map assets !\n",1);
            destroy_game(build);
        }
        i++;
    }
}

void    register_player_ass_r(t_build *build)
{
    int i;
    int h;
    int w;
    char *path[4];

    i = 0;
    path[0] = "";
    path[1] = "";
    path[2] = "";
    path[3] = "";
    while(i < 4)
    {
        build->player_ass_r[i] = mlx_xpm_file_to_image(build->mlx ,path[i] , &w , &h);
        if(!build->player_ass_r[i] || w > 64 || h > 64)
        {
            ft_putstr_fd("Error registring map assets !\n",1);
            destroy_game(build);
        }
        i++;
    }
}

void    register_player_ass_l(t_build *build)
{
    int i;
    int h;
    int w;
    char *path[4];

    i = 0;
    path[0] = "";
    path[1] = "";
    path[2] = "";
    path[3] = "";
    while(i < 4)
    {
        build->player_ass_l[i] = mlx_xpm_file_to_image(build->mlx ,path[i] , &w , &h);
        if(!build->player_ass_l[i] || w > 64 || h > 64)
        {
            ft_putstr_fd("Error registring map assets !\n",1);
            destroy_game(build);
        }
        i++;
    }
}

void    register_ass_path(t_build *build)
{
    register_map_ass(build);
    register_player_ass_u(build);
    register_player_ass_d(build);
    register_player_ass_l(build);
    register_player_ass_r(build);

}