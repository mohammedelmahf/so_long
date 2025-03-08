/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:37:56 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/08 23:29:26 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

void	start_mlx(t_build *build)
{
	build->mlx = mlx_init();
	build->win = mlx_new_window(build->mlx, build->width * 64, (build->height
				+ 1) * 64, "so_long");
	draw_ass(build);
	mlx_string_put(build->mlx, build->win, 0, (build->height + 0.5) * 64,
		0x00FFFFFF, "Moves : 0");
	mlx_hook(build->win, 2, 1L << 0, &event_handler, build);
	mlx_hook(build->win, 17, 1L << 17, &destroy_game, build);
	mlx_loop_hook(build->mlx, &render_map, build);
	mlx_loop(build->mlx);
}

int	main(int ac, char **av)
{
	t_build	build;

	if (!check_args(ac, av))
		return (0);
	build_args(&build);
	build.map = arg_to_map(av);
	if (!check_map(&build))
	{
		free_array(build.map);
		return (0);
	}
	start_mlx(&build);
	free_array(build.map);
}
