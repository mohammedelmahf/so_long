/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing_05.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:19:43 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/09 15:26:41 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

int	count_line(t_build *build)
{
	int	i;

	i = 0;
	while (build->map[i])
		i++;
	return (i);
}

void	handle_invalid_map(char *map_1d)
{
	ft_putstr_fd("Error\nMap is invalid\n", 1);
	free(map_1d);
	exit(1);
}
