/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:36:01 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/05 22:17:08 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <sys/time.h>

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
	void	*player_ass[7];
	void	*player_ass_u[7];
	void	*player_ass_l[7];
	void	*player_ass_r[7];
	void	*player_ass_d[7];
	int		player_moves;
	int		c;
	void	*c_ass[6];
	int		exit;
	int		exit_x;
	int		exit_y;
	void	*exit_ass[1];
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

// Parsing functions
int			check_ber(char *ber);
int			check_args(int ac, char **av);
void		build_args(t_build *build);
char		**arg_to_map(char **av);
int			count_line(t_build *build);
int			check_map1(t_build *build);
int			check_map(t_build *build);
int			check_map2(t_build *build);
int			check_map3(t_build *build);
int			check_map4(t_build *build);
void		elements_counter(t_build *build);
int			check_elements(t_build *build);
void		saving_elements_coordinates(t_build *build, int i, int j);
void		elements_coordinates(t_build *build);
void		flood_fill(t_build *build);
int			elements_search(char **map, char a);
void		fill_m(char **map, int px, int py);
void		fill_v(char **map, int px, int py);
char		**copy_map(t_build *build);
void		destroy_player_ass(t_build *build);
void		destroy_enemy_ass(t_build *build);

// Utils
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *str);
char		**ft_split(char const *s, char c);
void		free_array(char **map);
char		*ft_strchr(const char *s, int c);
char		*ft_itoa(int n);
char		*ft_strjoin(char const *s1, char const *s2);

// Mlx_loader
void		register_enemy_ass_d(t_build *build);
void		register_player_ass_d(t_build *build);
void		register_player_ass_u(t_build *build);
void		register_player_ass(t_build *build);
void		register_player_ass_l(t_build *build);
void		register_player_ass_r(t_build *build);
void		register_player_c_ass(t_build *build);
void		draw_ass(t_build *build);
void		register_map_ass(t_build *build);
void		ass_to_window(t_build *build, int x, int y);
void		register_ass_path(t_build *build);

// So_long_utils
int			destroy_game(t_build *build);
void		move_to_position(t_build *build, int x, int y);
void		move_player(t_build *build, int x, int y);
int			event_handler(int key, t_build *build);
void		print_moves(t_build *build);
int			render_map(t_build *build);
void		draw_ass_animated(t_build *build);
void		load_animation(t_build *build, int x, int y);
void		animate_player(t_build *build, int x, int y);
int			p_frames_calculator(void);
long long	current_time_in_ms(void);
int			m_frames_calculator(void);
int			x_frames_calculator(void);
void		animate_enemy(t_build *build, int x, int y);
int			c_frames_calculator(void);
void		animate_c(t_build *build, int x, int y);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		register_exit_ass(t_build *build);
void		destroy_player_ass_r_d(t_build *build);
void		apply_enemy_move(t_build *build, int x, int y);
void		move_enemy(t_build *build);
int			is_wall(int x, int y, t_build *build);
void		print_map(void *map, int height);
void		start_mlx(t_build *build);

#endif
