/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:24:27 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/04 15:01:17 by tmartial         ###   ########.fr       */
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
	if (keycode == 0)//left
	{
		move_player(data, -1, 0);
	}
	else if (keycode == 2)//droit
	{
		move_player(data, 1, 0);
	}
	else if (keycode == 13)//up
	{
		move_player(data, 0, -1);
	}
	else if (keycode == 1)//down
	{
		move_player(data, 0, 1);
	}
	return (0);
}

void move_player(t_data *data, float x, float y)
{
	int c;

	c = 0;
	//while (data->press == 1 && c < 50)
	//{
	make_player(data, 1);
	data->x += (x / 100);
	data->y += (y / 100);
	make_player(data, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		//c++;
	//}
}
int presskey(t_data *data)
{
	mlx_hook(data->win, 2, 0L, &un_presskey, data);
	return (0);
}

int un_presskey(t_data *data)
{
	printf("%d",data->press);
	return (0);
}

int main()
{
    t_data data;
	data.press = 0;
	make_map(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 800, 800, "cube");
	data.img = mlx_new_image(data.mlx, 800, 800);
	data.addr = mlx_get_data_addr(data.img, &data.b_pix, &data.len_pix, &data.endian);
	make_img(&data);
	make_player(&data, 0);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	//mlx_key_hook(data.win, key_hook, &data);
	//mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 17, 0L, &exit_mlx, &data);
	mlx_loop_hook(data.mlx, &presskey, &data);
	//mlx_hook(data.win, 2, 0L, &presskey, &data);
	//mlx_hook(data.win, 3, 1L << 1, &un_presskey, &data);
	mlx_loop(data.mlx);
}
