/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:24:27 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/07 15:49:48 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len_pix + x * (data->b_pix / 8));
	*(unsigned int*)dst = color;
}

int move_test(t_data *data)
{
	if (data->press == 1)
	{
		make_img(data);
		make_player(data, 1);
		data->x += data->add_x;
		data->y += data->add_y;
		make_player(data, 0);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return(0);
}

void moving(t_data *data, float x, float y, int pres)
{
	if (data->add_x != 0 && data->add_y != 0 && pres == 0)
		(void)NULL;
	else
		data->press = pres;
	if (data->add_x != x)
		data->add_x += x;
	if (data->add_y != y)
		data->add_y += y;
}

int presskey(int keycode, t_data *data)
{
	if (keycode == 53)
		exit_mlx(data);
	if (keycode == 0)//left
		moving(data, -0.015, 0, 1);
	else if (keycode == 2)//droit
		moving(data, 0.015, 0, 1);
	else if (keycode == 13)//up
		moving(data, 0, -0.015, 1);
	else if (keycode == 1)//down
		moving(data, 0, 0.015, 1);
	return (0);
}

int un_presskey(int keycode, t_data *data)
{
	if (keycode == 53)
		exit_mlx(data);
	if (keycode == 0)//left
		moving(data, 0.015, 0, 0);
	else if (keycode == 2)//droit
		moving(data, -0.015, 0, 0);
	else if (keycode == 13)//up
		moving(data, 0, 0.015, 0);
	else if (keycode == 1)//down
		moving(data, 0, -0.015, 0);
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
	mlx_hook(data.win, 2, 1L << 0, presskey, &data);
    mlx_hook(data.win, 3, 1L << 0, un_presskey, &data); 
	mlx_loop_hook(data.mlx, &move_test, &data);
	mlx_loop(data.mlx);
}
