/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:24:21 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/24 14:31:07 by tmartial         ###   ########.fr       */
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
# define RAD 0.01745329251
# define ESC 53
# define LEFT 0
# define RIGHT 2
# define UP 13
# define DOWN 1
# define LOOK_LEFT 123
# define LOOK_RIGHT 124
# define WINDOW 800.0

typedef struct s_img {
	void	*img;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		l_l;
	int		endian;

}			t_img;

typedef struct s_data {

	/* mlx */
    void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		b_pix;
	int		len_pix;
	int		endian;

	/* data */
	int 	map_l;
	int		map_h;
	char	**map;
	int		floor;
	int		ceiling;
	float	x; //pos player
	float 	y; //pos player
	float	direction; //ray du milieu
	float	dir_ray; //dir pour ray unique

	/* moves */
	float	add_x;
	float	add_y;
	int     press;
	int		press_turn;
	
	/* parsing */
	int		argc; 
	int		lowhei;
	int 	playercount;
	char	**txtr;
	
	/* wall */
	float	up; //wall form the top point
	float	down;
	float	i2;
	
	t_img north;
	t_img south;
	t_img west;
	t_img east;
}				t_data;


typedef struct	s_ray {
	float	start_x;
	float	start_y;
	float	dir_x;
	float	dir_y;
	float	ustep_x;
	float	ustep_y;
	float	map_x;
	float	map_y;
	float	lenx;
	float	leny;
	float	vStep_x;
	float	vStep_y;
	float	intersec_x;
	float	intersec_y;
	float	len;
	int		vertical;
	int		bTileFound;
	float	fmaxdistance;
	float	fdistance;
}				t_ray;

/* main */


/* yasin main */ //errors
void	yasin(t_data *data, int argc, char **argv);
void	free_tab(char **tab);
void	ft_setrange(char *path, char **tab, t_data *data);
void	ft_setup(char **tab, t_data *data, size_t len);

/* data divider */ //too much ft
void 	ft_divideno(int i, int k, char **tab, t_data *data);
void 	ft_divideso(int i, int k, char **tab, t_data *data);
void 	ft_divideea(int i, int k, char **tab, t_data *data);
void 	ft_dividewe(int i, int k, char **tab, t_data *data);
void	ft_dividefloor(int i, int k, char **tab, t_data *data);
void	ft_divideceiling(int i, int k, char **tab, t_data *data);

/* error */ //too much ft
void	ft_forbiddenmap(t_data *data);
void	ft_checkcount(char c, t_data *data);
void	ft_maperror();
void	ft_checkwall(char c, int i, int k, t_data *data);
void	ft_error(t_data *data);
void	ft_contentinvalid(char *str);
void	ft_checkchar(char c);
void	ft_checkprechar(char c);
void	ft_setposition(t_data *data, int i, int k);

/* gnl utils */
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *string, int searchedChar );
size_t	ft_strlen(const char *theString);
void	ft_bzero(void *s, size_t n);

/* gnl */
char	*ft_couple(char *str1, char *str2);
char	*chargenext(char *buffer);
char	*chargeline(char *buffer);
char	*chargebuff(int fd, char *buffer, int BUFFER_SIZE);
char	*get_next_line(int fd);

/* makers */ //norminette
int		create_rgb(int r, int g, int b);
void	ft_makefloor(char **tab, int i, int k, t_data *data);
void	ft_rgbinvalid(char **tab, int i, int m);
void	ft_makeceiling(char **tab, int i, int k, t_data *data);

/* images */
void	ft_fillnorth(t_data *data, t_img *north, char *file);
void	ft_fillsouth(t_data *data, t_img *south, char *file);
void	ft_filleast(t_data *data, t_img *east, char *file);
void	ft_fillwest(t_data *data, t_img *west, char *file);
void	ft_images(t_data *data);

/* parser */
void	ft_cleanpath(char **tab, int ln, int tx, t_data *data);
void	ft_dividemap(int i, int k, char **tab, t_data *data);
void	ft_setheight(int i, t_data *data);
void	ft_dividein3(char **tab, t_data *data);
void	ft_locatefloor(char **tab, int i, int k, t_data *data);
void	ft_locateceiling(char **tab, int i, int k, t_data *data);
void	ft_verifrgb(char **tab, int i, int k, t_data *data);
int		ft_skipline(int fd);
void	ft_checkfloor(char **tab, int i, int k);
void	ft_checkceiling(char **tab, int i, int k);
void	ft_rgbsize(int r, int g, int b);

/* utils */
int		exit_mlx(t_data	*data);
char	*ft_strdup(const char *s1);
void	sprites_init(t_data *data);

/* raycast */
void 	init_raycast(t_ray *ray, t_data *data);
void raycast2(t_ray *ray, t_data *data);
void raycast3(t_ray *ray, t_data *data);
void raycast4(t_ray *ray, t_data *data);

/* draw */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		img_pix(t_img *img, int x, int y);
void	draw_one_wall(t_ray *ray, t_data *data, t_img *wall, int x);
void	draw_wall(t_ray *ray, t_data *data, int x);
void	make_player(t_data *data);

/* move */
int move_player(t_data *data);
void moving(t_data *data, int action, int pres);
void turning(t_data *data, int pres, int sens);
int presskey(int keycode, t_data *data);
int un_presskey(int keycode, t_data *data);

#endif