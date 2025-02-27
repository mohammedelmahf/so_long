/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:36:01 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/27 11:30:37 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H


#include "get_next_line.h"
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h> 
typedef struct s_build
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*map_ass[2];
	int		player;
	int		player_x;
	int		player_y;
	char	player_direction;
	void	*player_ass_u[4];
	void	*player_ass_l[4];
	void	*player_ass_r[4];
	void	*player_ass_d[4];
	int		player_moves;
	int		c;
	void	*c_ass[6];
	int		exit;
	int		exit_x;
	int		exit_y;
	void	*exit_ass;
	int		enemy;
	int		enemy_x;
	int		enemy_y;
	char	enemy_direction;
	void	*enemey_ass_u[2];
	void	*enemey_ass_l[2];
	void	*enemey_ass_r[2];
	void	*enemey_ass_d[2];
	int		width;
	int		height;
}			t_build;

//parsing
int			check_ber(char *ber);
int			check_args(int ac , char **av);
void		build_args(t_build *build);
char		**arg_to_map(char **av);
int			count_line(t_build *build);
int 		check_map1(t_build *build);
int			check_map(t_build *build);
int    	    check_map2(t_build *build);
int			check_map3(t_build *build);
int     check_map4(t_build *build);
void    elements_counter(t_build *build);
int     check_elements(t_build *build);
void    saving_elements_coordinates(t_build *build ,int i , int j);
void    elements_coordinates(t_build *build);
void	flood_fill(t_build *build);
int     elements_search(char **map , char a);
void	fill_M(char **map , int px , int py);
void	fill_V(char **map , int px , int py);
char **copy_map(t_build *build);
void	destroy_player_ass(t_build *build);
void	destroy_enemy_ass(t_build *build);
//utils
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
void		free_array(char **map);
char	*ft_strchr(const char *s, int c);
//so_long_utils
int destroy_game(t_build *build);






void print_map(char **map, int height);

void	start_mlx(t_build *build);
#endif