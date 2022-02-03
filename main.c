/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:24:27 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/03 16:46:31 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len_pix + x * (data->b_pix / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		exit_mlx(data);
	if (keycode == 0)
	{
		move_player(data, -1, 0);
	}
	else if (keycode == 2)
	{
		move_player(data, 1, 0);
	}
	else if (keycode == 13)
	{
		move_player(data, 0, -1);
	}
	else if (keycode == 1)
	{
		move_player(data, 0, 1);
	}
	return (0);
}

void move_player(t_data *data, int x, int y)
{
	int c;

	c = 0;
	while (c < 10)
	{
		my_mlx_pixel_put(data, (int)(data->x * 100) + x, (int)(data->y * 100) + y, 0x000000FF);
		c++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}


int main()
{
    t_data data;
	make_map(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 800, 800, "cube");
	data.img = mlx_new_image(data.mlx, 800, 800);
	data.addr = mlx_get_data_addr(data.img, &data.b_pix, &data.len_pix, &data.endian);
	make_img(&data);
	make_player(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	int c;

	c = 0;
	while (c < 10)
	{
		my_mlx_pixel_put(&data, (int)(data.x * 100) + 1, (int)(data.y * 100) + 1, 0x000000FF);
		c++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	//mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 17, 1L << 0, &exit_mlx, &data);
	mlx_loop(data.mlx);
}
