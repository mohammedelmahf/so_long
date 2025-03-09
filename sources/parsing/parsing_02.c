/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:24:13 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/09 15:25:14 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

void	free_gnl_buffer(int fd)
{
	char	*temp;

	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
	}
}

char	*read_map(int fd)
{
	char	*line;
	char	*map_1d;

	map_1d = ft_strdup_gnl("");
	line = get_next_line(fd);
	if (!line)
		handle_invalid_map(map_1d);
	while (line)
	{
		if (strcmp(line, "\n") == 0)
		{
			ft_putstr_fd("Error\nMap contains an empty line\n", 2);
			free(map_1d);
			free(line);
			free_gnl_buffer(fd);
			close(fd);
			exit(1);
		}
		map_1d = ft_strjoin_gnl(map_1d, line);
		free(line);
		line = get_next_line(fd);
	}
	return (map_1d);
}

char	**arg_to_map(char **av)
{
	int		fd;
	char	*map_1d;
	char	**map_2d;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCannot open file\n", 2);
		exit(1);
	}
	map_1d = read_map(fd);
	close(fd);
	map_2d = ft_split(map_1d, '\n');
	free(map_1d);
	return (map_2d);
}

int	check_map1(t_build *build)
{
	int	i;

	i = 0;
	while (build->map[0][i])
	{
		if (build->map[0][i] != '1')
		{
			ft_putstr_fd("Error\nInvalid top border (not a wall).\n", 1);
			return (0);
		}
		i++;
	}
	i = 0;
	while (build->map[count_line(build) - 1][i])
	{
		if (build->map[count_line(build) - 1][i] != '1')
		{
			ft_putstr_fd("Error\nInvalid bottom border (not a wall).\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map2(t_build *build)
{
	int		i;
	size_t	len;

	len = ft_strlen(build->map[0]);
	i = 0;
	while (build->map[i])
	{
		if (ft_strlen(build->map[i]) != len)
		{
			ft_putstr_fd("Error\nMap is not rectangular\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}
