/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:55:25 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/27 10:58:59 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

int destroy_game(t_build *build)
{
    if(build->mlx)
    {
        if(build->win)
        {
            mlx_destroy_window(build->mlx, build->win);
			mlx_destroy_image(build->mlx, build->exit_ass);
			mlx_destroy_image(build->mlx, build->map_ass[0]);
			mlx_destroy_image(build->mlx, build->map_ass[1]);
			mlx_destroy_image(build->mlx, build->c_ass[0]);
			mlx_destroy_image(build->mlx, build->c_ass[1]);
			mlx_destroy_image(build->mlx, build->c_ass[2]);
			mlx_destroy_image(build->mlx, build->c_ass[3]);
			mlx_destroy_image(build->mlx, build->c_ass[4]);
			mlx_destroy_image(build->mlx, build->c_ass[5]);
            destroy_player_ass(build);
            destroy_enemy_ass(build);
        }
    }
}