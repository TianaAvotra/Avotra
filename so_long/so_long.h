/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:52:32 by hrasolom          #+#    #+#             */
/*   Updated: 2024/08/02 15:23:20 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12

# endif

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
	int			exit_x;
	int			exit_y;
	void		*img;
}				t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img_background;
	void		*img_wall;
	void		*img_man2;
	void		*img_c;

	void		*img_door;
	int			x;
	int			y;
	char		**map;
	int			count_c;
	int			count_move;
	t_player	*player;
}				t_data;

int				key_press(int key_code, t_data *mlx);
void			exit_final(t_data *mlx);
void			condition_map(char *str, t_data *mlx, char **map);
int				close_window(t_data *param);
int				read_map_y(char *file);
int				count_player(char **map);
int				count_collect(char **map, t_data *mlx);
int				count_exit(char **map);
void			position_player(char **map, t_player *player);
void			position_exit(char **map, t_player *player);
int				ft_rectangle_check(char **map);
char			**scan_map(char *str, int fd);
int				ft_scan_wall(char **map, int x, int y, t_data *mlx);
void			name_ber(char *file_ber);
void			map_free(char **map);
void			ft_free_map(char **map);
void			ft_clean_image(t_data *image);
char			*ft_strdup(const char *s);
void			init_image(t_data *mlx);
void			image(char **map, t_data *mlx, int i, int j);
void			put_image(char **map, t_data *mlx);
void			move_right(t_data *mlx);
void			move_left(t_data *mlx);
void			move_up(t_data *mlx);
void			move_down(t_data *mlx);
void			free_flood_file(char **map);
char			**tmp_map(char **map, t_data *mlx);
void			fill(char **map, int pos_x, int pos_y, t_data to_fill);
int				check_map(char **map, int y);
void			display(int x, int y, char **map, t_data *mlx);
void			ft_putendl_fd(char *s, int fd);
void			free_mlx(t_data *data);
void			print_error(void);

/*get_next_line*/
char			*get_next_line(int fd);
char			*ft_join_free(char *text, char *buffer);
char			*read_first_line(int fd, char *text);
char			*get_line(char *text);
char			*clean_first_line(char *text);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
void			ft_bzero(void *s, unsigned int n);
void			*ft_calloc(unsigned int count, unsigned int size);

#endif
