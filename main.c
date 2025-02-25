/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:37:56 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/25 11:18:33 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

void	start_mlx(t_build *build)
{
	build->mlx = mlx_init();
    if (!build->mlx)
    {
        fprintf(stderr, "Error: mlx_init failed\n");
        return ;
    }
	build->win = mlx_new_window(build->mlx, build->width * 32, (build->height + 1)
			* 32, "so_long");

    if (!build->win)
    {
        fprintf(stderr, "Error: mlx_new_window failed\n");
        return;
    }
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
