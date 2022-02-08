/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:17:01 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/08 13:45:26 by tmartial         ###   ########.fr       */
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
	//char 
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
	i = 5;
	j = 5;
	/*while (i < 20)
	{
		my_mlx_pixel_put(data, (int)(data->x * 100) + i , (int)(data->y * 100) + j, 0x0000FF00);
		i += data->direction;
		j += data->direction;
	}*/
}