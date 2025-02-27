/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_path01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:12:06 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/27 11:41:17 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

void    register_map_path(t_build *build)
{
    int i ;
    int w;
    int h;
    char *path[2];

    int i = -1;

    while(++i < 2)
    {
        build->map_ass[i] = mlx_xpm_file_to_image(build->mlx , path[i] , &w , &h);
        if(!build->map_ass[i] || w > 64 || w > 64)
        {
            ft_putstr_fd("Error registring map assets !" , 1);
        }
    }
}

void    register_path(t_build *build)
{
    register_map_path(build);
}