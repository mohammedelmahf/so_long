/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:37:56 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/27 11:39:07 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

void	start_mlx(t_build *build)
{
	build->mlx = mlx_init();
	build->win = mlx_new_window(build->mlx, build->width * 64, (build->height + 1)
			* 64, "so_long");
    draw_ass(build);
    mlx_loop(build->mlx);
}

int main(int ac , char **av)
{
    t_build build;
    
    if(!check_args(ac , av))
        return(0);
    build_args(&build);
    build.map = arg_to_map(av);
    if(!check_map(&build))
    {
        free_array(build.map);
        return(0);
    }
    start_mlx(&build);
    free_array(build.map);
}
