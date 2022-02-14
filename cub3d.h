/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:24:21 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/14 14:53:10 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CU_B3D_H
# define CU_B3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# define PI 3.1415926535

# define MapWidth 8
# define MapHeight 8
# define ScreenWidth 800
# define ScreenHeight 800

/* define LEFT 123
define RIGHT 124*/

typedef struct s_data {
    void	*mlx;
	void	*win;

	void	*img;
	char	*addr;
	int		b_pix;
	int		len_pix;
	int		endian;
	
	char 	**map;
	float	x; //pos player
	float	add_x;
	float 	y; //pos player
	float	add_y;
	int 	map_l;
	int		map_h;
	float	direction;
	
	int     press;
	int		press_turn;
	
}				t_data;

typedef struct s_ray {
	float start_x;
	float start_y;
	float dir_x;
	float dir_y;
	float ustep_x;
	float ustep_y;
	float map_x;
	float map_y;
	float lenx;
	float leny;
	float vStep_x;
	float vStep_y;
	float intersec_x;
	float intersec_y;
} t_ray;
/* main */

/* utils */
int	exit_mlx(t_data	*data);

/* raycast */
float init_raycast(t_ray *ray, t_data *data);

/* draw */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void put_square(t_data *data, int j, int i);
void make_img(t_data *data);
void make_player(t_data *data);
void draw_ray(t_data *data, t_ray *ray);
void    draw_line(t_data *data, int x0, int y0, int x1, int y1);
void draw_rays(t_data *data);

/* move */
int move_player(t_data *data);
void moving(t_data *data, float x, float y, int pres);
int presskey(int keycode, t_data *data);
int un_presskey(int keycode, t_data *data);
void turning(t_data *data, int pres, int sens);

/* parser */
void make_map(t_data *data);

/* libft */
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif