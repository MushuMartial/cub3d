/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:17:01 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/19 15:33:55 by tmartial         ###   ########.fr       */
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

void draw_black(t_data *data)
{
    int i;
	int j;

	j = 0;
	while (j < 800)
	{
		i = 0;
		while (i < 800)
		{
			my_mlx_pixel_put(data, i, j, 0x00FFFFFF);
			i++;
		}
		j++;
	}
}



void draw_wall(t_ray *ray, t_data *data, int x)
{
    float z = (cos((data->direction - data->dir_ray)  * 0.01745329251));
    float wallheight = ((800.0) / ((ray->len * z)));
    float i = 400.0 - (wallheight / 2.0);
    float j = 400.0 + (wallheight / 2.0);
    if (i >= 0 && i < 800)
        draw_line(data, x, 0, x, (i),0x00AAAAAA);//sky gris
    if (i < 0)
        i = 0;
    if (i > 800)
        i = 800;
    if (j < 0)
        j = 0;
    if (j > 800)
        j = 800;
    if (i >= 0 && i <= 800 && j >= 0 && j <= 800)
    {
        if (ray->fish == 1 && cos((data->dir_ray + 90.0) * 0.01745329251) > 0.0)//&& cos((data->dir_ray) * 0.01745329251)> 0.0
        {
            //printf("angle = %f\n",cos(data->dir_ray * 0.01745329251));
            draw_line(data, x, (i), x, (j), 0x00000000);//ouest noir
        }
        else if (ray->fish == 1)
        {
            //printf("angle = %f\n",cos((data->dir_ray + 90.0)* 0.01745329251));
            draw_line(data, x, (i), x, (j), 0x0000AA00);//est vert
        }
        else if (sin((data->dir_ray + 90.0) * 0.01745329251) > 0.0)//sin((data->dir_ray) * 0.01745329251) > 0.0
        {
            draw_line(data, x, (i), x, (j), 0x00AA0000);//nord rouge
        }
        else
        {
            draw_line(data, x, (i), x, (j), 0x000000AA);//nord bleu  0x000000AA
        }
    }
    /*else
    {
       draw_line(data, x, 0, x, 799, 0x0000AA00);
    }*/
}



void make_player(t_data *data)
{
    draw_black(data);
    draw_rays(data);
    
    //write(1,"mov\n",4);
    //printf("direction = %f\n", data->direction);
   // printf("direction = %f\n", data->direction);
}

void draw_rays(t_data *data)
{
    float i;
    float add;
    t_ray ray;
    
    data->dir_ray = data->direction;
    i = 0;
    add = 60.0 / 800.0;
    if (data->dir_ray <= 29)
        data->dir_ray = data->dir_ray + 360;
    data->dir_ray -= 30;
    while(i < 800)
    {
        //printf("dir ray = %f\n", data->dir_ray);
        init_raycast(&ray, data);
        draw_wall(&ray, data, i);
        data->dir_ray+= add;
        i++;
    }
}

void    draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
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
        my_mlx_pixel_put(data, x0, y0, color);//mauve 0x006A0DAD
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

