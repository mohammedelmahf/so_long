/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:37:56 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/21 16:20:47 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

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
    else
        printf("valid map\n");
    free_array(build.map);
}
