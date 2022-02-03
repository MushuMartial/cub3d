/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:24:21 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/03 16:39:23 by tmartial         ###   ########.fr       */
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

/*typedef struct s_img {
	void	*img;
	char	*addr;
	void	*img_h;
	char	*addr_h;
	void	*img_f;
	char	*addr_f;
	void	*img_e;
	char	*addr_e;
	char	*path;
	int		size;
}				t_img;

typedef struct s_data {
	void	*mlx;
	void	*win;
	char	**map;
	int		len;
	int		height;
	int		x;
	int		y;
	int		count_c;
	int		walk;
}				t_data;*/

typedef struct s_data {
    void	*mlx;
	void	*win;

	void	*img;
	char	*addr;
	int		b_pix;
	int		len_pix;
	int		endian;
	
	char 	**map;
	float	x;
	float 	y;
	int 	map_l;
	int		map_h;
}				t_data;

/* main */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void move_player(t_data *data, int x, int y);

/* utils */
int	exit_mlx(t_data	*data);

/* parser */
void make_map(t_data *data);
void put_square(t_data *data, int j, int i);
void make_img(t_data *data);
void make_player(t_data *data);

/* libft */
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif