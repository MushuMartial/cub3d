/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:37:38 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/03 16:42:06 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void make_map(t_data *data)
{
	data->map = malloc(sizeof(char *) * 8);
	data->map[0] = ft_strdup("11111111");
    data->map[1] = ft_strdup("10010001");
    data->map[2] = ft_strdup("10010001");
    data->map[3] = ft_strdup("10010001");
    data->map[4] = ft_strdup("10000001");
    data->map[5] = ft_strdup("10000001");
    data->map[6] = ft_strdup("100P0101");
    data->map[7] = ft_strdup("11111111");
    data->map_h = 8;
    data->map_l = 8;
	data->x = 3.45;
	data->y = 6.45;
}

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
				my_mlx_pixel_put(data, (int)(i * 100) + l, (int)(j * 100) + k, 0xA0DDDDDD);
			else
				my_mlx_pixel_put(data, (int)(i * 100) + l, (int)(j * 100) + k, 0x00000000);
			l++;
		}
		my_mlx_pixel_put(data, (int)(i * 100) + l, (int)(j * 100) + k, 0x00AAAAAA);
		k++;
	}
}

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
	int i;
	int j;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			my_mlx_pixel_put(data, (int)(data->x * 100) + i , (int)(data->y * 100) + j, 0x000000FF);
			i++;
		}
		j++;
	}
}