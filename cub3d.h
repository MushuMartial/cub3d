/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:24:21 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/08 12:22:27 by tmartial         ###   ########.fr       */
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

# define mapWidth 8
# define mapHeight 8
# define screenWidth 800
# define screenHeight 800

/* define ROTATE_LEFT 123
define ROTATE_RIGHT 124*/

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
	
	float dirY;//direction of the player
	float dirX;
	float planeX; //camera plane of the player
	float planeY;
	float posX; //x and y start position
	float posY;
	
}				t_data;

/* main */

/* utils */
int	exit_mlx(t_data	*data);

/* draw */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void put_square(t_data *data, int j, int i);
void make_img(t_data *data);
void make_player(t_data *data);

/* move */
int move_player(t_data *data);
void moving(t_data *data, float x, float y, int pres);
int presskey(int keycode, t_data *data);
int un_presskey(int keycode, t_data *data);

/* parser */
void make_map(t_data *data);

/* libft */
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif