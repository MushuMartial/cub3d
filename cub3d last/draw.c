/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:17:01 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/22 10:39:40 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* My put pixel */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len_pix + x * (data->b_pix / 8));
	*(unsigned int*)dst = color;
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
			my_mlx_pixel_put(data, i, j, 0x00AAAAAA);
			i++;
		}
		j++;
	}
}

void draw_wall(t_ray *ray, t_data *data, int x)
{
    float z = (cos((data->direction - data->dir_ray)  * RAD));
    float wallheight = ((800.0) / ((ray->len * z)));
    float i = 400.0 - (wallheight / 2.0);
    float j = 400.0 + (wallheight / 2.0);
    if (i >= 0 && i < 800)
        draw_line(data, x, 0, (i), 0x0AAAAAAA);//sky
    if (i < 0)
        i = 0;
    if (i > 800)
        i = 800;
    if (j < 0)
        j = 0;
    if (j > 800)
        j = 800;
    
	float jj = 0;
	float xx = 0;
	float yy = 0;
	int color = 0;
    
    //float wall_w = ((1.0 - (ray->intersec_x - (int)ray->intersec_x)));
    if (i >= 0 && i <= 800 && j >= 0 && j <= 800)
    {
        if (ray->fish == 1 && cos((data->dir_ray + 90.0) * RAD) > 0.0)
        {
		    while (i < j)
		    {
			    xx = (x / 100) * data->west.w;
			    yy = (jj / (j - i)) * data->west.h;//deux bas - haut : 800 - 100
			    color = img_pix(&data->west, xx, yy);
			    my_mlx_pixel_put(data, x, i, color);
			    i++;
		    }
        }
        else if (ray->fish == 1)
        {
           while (i < j)
		    {
			    xx = (x / 100) * data->east.w;
			    yy = (jj / (j - i)) * data->east.h;//deux bas - haut : 800 - 100
			    color = img_pix(&data->east, xx, yy);
			    my_mlx_pixel_put(data, x, i, color);
			    i++;
		    }
        }
        else if (sin((data->dir_ray + 90.0) * RAD) > 0.0)
        {
            while (i < j)
		    {
			    xx = (x / 100) * data->north.w;
			    yy = (jj / (j - i)) * data->north.h;//deux bas - haut : 800 - 100
			    color = img_pix(&data->north, xx, yy);
			    my_mlx_pixel_put(data, x, i, color);
			    i++;
		    }
        }
        else
        {
            while (i < j)
		    {
			    xx = (x /  100) * data->south.w;
			    yy = (jj / (j - i)) * data->south.h;//deux bas - haut : 800 - 100
			    color = img_pix(&data->south, xx, yy);
			    my_mlx_pixel_put(data, x, i, color);
			    i++;
		    }
        }
    }
}

/* //printf("angle = %f\n",cos(data->dir_ray * RAD));
    if (i >= 0 && i <= 800 && j >= 0 && j <= 800)
    {
        if (ray->fish == 1 && cos((data->dir_ray + 90.0) * RAD) > 0.0)//&& cos((data->dir_ray) * RAD)> 0.0
        {
            //printf("angle = %f\n",cos(data->dir_ray * RAD));
            draw_line(data, x, (i), (j), 0x00000000);//ouest noir
        }
        else if (ray->fish == 1)
        {
            draw_line(data, x, (i), (j), 0x0000AA00);//est vert
        }
        else if (sin((data->dir_ray + 90.0) * RAD) > 0.0)//sin((data->dir_ray) * RAD) > 0.0
        {
            draw_line(data, x, (i), (j), 0x00AA0000);//nord rouge
        }
        else
        {
            draw_line(data, x, (i), (j), 0x000000AA);//nord bleu  0x000000AA
        }
    }*/



void make_player(t_data *data)
{
    draw_black(data);
    draw_rays(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
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
        init_raycast(&ray, data);
        draw_wall(&ray, data, i);
        data->dir_ray+= add;
        i++;
    }
}

void draw_line(t_data *data, int x, int up, int down, int color)
{
	while (up < down)
	{
		my_mlx_pixel_put(data, x, up, color);
		up++;
	}
}
