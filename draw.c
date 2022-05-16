/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:17:01 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/15 14:20:12 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* My put pixel */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len_pix + x * (data->b_pix / 8));
	*(unsigned int *)dst = color;
}

/* get color in image */
int	img_pix(t_img *img, int x, int y)
{
	char	*ptr;

	ptr = img->addr + (y * img->l_l + x * (img->bpp / 8));
	return (*((int *)ptr));
}

/* draw one wall */
void	draw_one_wall(t_ray *ray, t_data *data, t_img *wall, int x)
{
	data->i2 = data->up;
	while (data->up < data->down)
	{
		if (data->up >= 0 && data->up <= 799)
		{
			if (ray->vertical == 1)
				my_mlx_pixel_put(data, x, data->up,
					img_pix(wall, ((ray->intersec_y
								- (int)(ray->intersec_y))) * (float)wall->w,
						(((float)data->up - data->i2)
							/ (float)(data->down - data->i2))
						* (float)wall->h));
			else
				my_mlx_pixel_put(data, x, data->up,
					img_pix(wall, ((ray->intersec_x
								- (int)(ray->intersec_x))) * (float)wall->w,
						(((float)data->up - data->i2)
							/ (float)(data->down - data->i2))
						* (float)wall->h));
		}
		data->up++;
	}
}

/* draw walls up = starting point and down = end of wall*/
void	draw_wall(t_ray *ray, t_data *data, int x)
{
	int	i;

	i = 0;
	data->up = 400.0 - (((WINDOW)
				/ ((ray->len * (cos((data->direction - data->dir_ray)
								* RAD))))) / 2.0);
	data->down = 400.0 + (((WINDOW)
				/ ((ray->len * (cos((data->direction - data->dir_ray)
								* RAD))))) / 2.0);
	if (data->up >= 0)
	{
		while (i < data->up)
			my_mlx_pixel_put(data, x, i++, data->ceiling);
		i = data->down;
		while (i < WINDOW)
			my_mlx_pixel_put(data, x, i++, data->floor);
	}
	if (ray->vertical == 1 && cos((data->dir_ray + 90.0) * RAD) > 0.0)
		draw_one_wall(ray, data, &data->west, x);
	else if (ray->vertical == 1)
		draw_one_wall(ray, data, &data->east, x);
	else if (sin((data->dir_ray + 90.0) * RAD) > 0.0)
		draw_one_wall(ray, data, &data->south, x);
	else
		draw_one_wall(ray, data, &data->north, x);
}

/* draw lines 60 = fov of player angle de vu */
void	make_player(t_data *data)
{
	float	i;
	float	add;
	t_ray	ray;

	data->dir_ray = data->direction;
	i = 0;
	add = 60.0 / WINDOW;
	if (data->dir_ray <= 29)
		data->dir_ray = data->dir_ray + 360;
	data->dir_ray -= 30;
	while (i < WINDOW)
	{
		init_raycast(&ray, data);
		draw_wall(&ray, data, i);
		data->dir_ray += add;
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
