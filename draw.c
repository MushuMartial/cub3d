/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:17:01 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/13 16:39:23 by tmartial         ###   ########.fr       */
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

/* Draw Player */
void make_player(t_data *data)
{
	float i;
	float j;
	float len;
	t_ray ray;
	
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
    //printf("dir = %f\n", data->direction);
     printf("direction = %f\n", data->direction);
	len = init_raycast(&ray, data);
	draw_line(data, (data->x * 100) + 5, (data->y * 100) + 5, (ray.intersec_x) * 100, (ray.intersec_y) * 100);//vert
	//i = 0;
    //draw_line(data, (int)(data->x * 100) + 5, (int)(data->y * 100) + 5, ((int)(data->x * 100) + 5) + ((int)(cos(data->direction * (PI / 180)) * 100)),((int)(data->y * 100) + 5) +  (int)(sin(data->direction * (PI / 180)) * 100));//vert
    //printf("x cos = %f\n",cos(data->direction * (PI / 180)) * 100);
    //printf("dir = %f\n",data->direction);
	//data->direction = -180;
	//len = init_raycast(&ray, data);
	//draw_line(data, (int)(data->x * 100) + 5, (int)(data->y * 100) + 5, (int)(ray.intersec_x) * 100, (int)(ray.intersec_y) * 100);//vert
	//data->direction = PI + 1;
	//len = init_raycast(&ray, data);
	//draw_line2(data, (int)(data->x * 100) + 5, (int)(data->y * 100) + 5, (int)(ray.intersec_x) * 100, (int)(ray.intersec_y) * 100);//mauve
	//data->direction = 2 * PI;
	//len = init_raycast(&ray, data);
	//draw_line3(data, (int)(data->x * 100) + 5, (int)(data->y * 100) + 5, (int)(ray.intersec_x) * 100, (int)(ray.intersec_y) * 100);//bleu
}

void    draw_line2(t_data *data, float x0, float y0, float x1, float y1)
{
    float   dx;
    float    dy;
    float    sx;
    float    sy;
    float    err;
    float    e2;

    dx = fabs (x1 - x0);
    dy = -fabs (y1 - y0);
    if (x0 < x1)
        sx = 1;
    else
        sx = -1;
    if (y0 < y1)
        sy = 1;
    else
        sy = -1;
    err = dx + dy;
    //write(1, "Hello\n", 6);
    printf("direction = %f\n", data->direction);
    //printf("x = %f\n",x0);
    //printf("y = %f\n",y0);
    while (1)
    {
        //printf("x = %f",x0);
        //printf("y = %f",y0);
        //my_mlx_pixel_put(data, (int)(x0), (int)(y0), 0x0000FFFF);//mauve 0x006A0DAD
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

void    draw_line3(t_data *data, int x0, int y0, int x1, int y1)
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
        my_mlx_pixel_put(data, x0, y0, 0x00FF00FF);//mauve 0x006A0DAD
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