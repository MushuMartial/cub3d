/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:17:01 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/16 11:31:03 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/* draw_line(data, (int)(data->x * 100) + 5, (int)(data->y * 100) + 5, 
((int)(data->x * 100) + 5) + ((int)(cos(data->direction * (PI / 180)) * 100)),
((int)(data->y * 100) + 5) +  (int)(sin(data->direction * (PI / 180)) * 100));//vert imprimer les directions de regards*/
/* My put pixel */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len_pix + x * (data->b_pix / 8));
	*(unsigned int*)dst = color;
}

/* Draw one square in map */
void put_square(t_data *data, int j, int i)
{
	int k;
	int l;

	k = 0;
	while(k < 100)
	{
		l = 0;
		while(l < 99)
		{
			if (k == 99)
				my_mlx_pixel_put(data, (int)(i * 100) + l, (int)(j * 100) + k, 0x00AAAAAA);
			else if (data->map[j][i] == '1')
				my_mlx_pixel_put(data, (int)(i * 100) + l, (int)(j * 100) + k, 0x00FFFFFF);
			else
				my_mlx_pixel_put(data, (int)(i * 100) + l, (int)(j * 100) + k, 0x00000000);
			l++;
		}
		my_mlx_pixel_put(data, (int)(i * 100) + l, (int)(j * 100) + k, 0x00AAAAAA);
		k++;
	}
}

/* Draw map with squares*/
void make_img(t_data *data)
{
	int i;
	int j;

	j = 0;
	while (j < data->map_h)
	{
		i = 0;
		while (i < data->map_l)
		{
			put_square(data, j ,i);
			i++;
		}
		j++;
	}
}

void make_player(t_data *data)
{
	float i;
	float j;
	
	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			my_mlx_pixel_put(data, (int)(data->x * 100) + i , (int)(data->y * 100) + j, 14443520);
			i++;
		}
		j++;
	}
    draw_rays(data);
    printf("direcetion = %f\n",data->direction);
}

void draw_rays(t_data *data)
{
    float i;
    float add;
    t_ray ray;
    
    i = 0;
    add = 60.0 / 800.0;
    init_raycast(&ray, data);
    printf("ray = %f\n",ray.len);
    //if(wall write NO SU OUESt WEST)
	draw_line(data, (data->x * 100) + 5, (data->y * 100) + 5, (ray.intersec_x) * 100, (ray.intersec_y) * 100);//vert
}

void    draw_line(t_data *data, int x0, int y0, int x1, int y1)
{
    int    dx;
    int    dy;
    int    sx;
    int    sy;
    int    err;
    int    e2;

    dx = abs (x1 - x0);
    dy = -abs (y1 - y0);
    if (x0 < x1)
        sx = 1;
    else
        sx = -1;
    if (y0 < y1)
        sy = 1;
    else
        sy = -1;
    err = dx + dy;
    while (1)
    {
        my_mlx_pixel_put(data, x0, y0, 0x0000FF00);//mauve 0x006A0DAD
        e2 = 2 * err;
        if (e2 >= dy)
        {
            if (x0 == x1)
                break ;
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            if (y0 == y1)
                break ;
            err += dx;
            y0 += sy;
        }
    }
}

/* int	get_img_pixel(t_img *img, int x, int y)
{
	char	*ptr;

	ptr = img->addr + (y * img->ll + x * (img->bpp / 8));
	return (*((int *)ptr));
}
300 = hauteurdelafenetre/distance;
(10, 55) (10 / 300 * 800, 55 / 300 * 800)
*/