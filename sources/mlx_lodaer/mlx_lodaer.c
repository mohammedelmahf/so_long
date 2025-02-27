/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_lodaer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:12:04 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/27 12:26:37 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"
 void   draw_ass(t_build *build)
 {
    int i;
    int j;

   register_ass_path(build);
   i = 0;
   while(build->map[i])
   {
      j = 0;
      while(build->map[i][j])
      {
         ass_to_window(build , i , j);
         j++;
      }
      i++;
   }
}

void  ass_to_window(t_build *build , int x , int y)
{
   	if (build->map[x][y] == '0')
		mlx_put_image_to_window(build->mlx, build->win, build->map_ass[1], y * 64,
			x * 64);
	else if (build->map[x][y] == '1')
		mlx_put_image_to_window(build->mlx, build->win, build->map_ass[0], y * 64,
			x * 64);
}