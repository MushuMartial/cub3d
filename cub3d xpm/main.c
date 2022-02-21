/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:24:27 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/21 18:45:44 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	img_pix(t_data *data, int x, int y)
{
	char	*ptr;

	ptr = data->addr_n + (y * data->ll_n + x * (data->bpp_n / 8));
	return (*((int *)ptr));
}

int main()
{
    t_data data;
	data.press = 0;
	make_map(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 800, 800, "cub3d");
	data.img = mlx_new_image(data.mlx, 800, 800);
	data.addr = mlx_get_data_addr(data.img, &data.b_pix, &data.len_pix, &data.endian);
	

	//make_player(&data);
	//mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	data.img_n = mlx_xpm_file_to_image(data.mlx, "./north.xpm", &data.w_n, &data.h_n);
	data.addr_n = mlx_get_data_addr(data.img_n, &data.bpp_n, &data.ll_n, &data.endian_n);
	float i = 0;
	float j = 0;
	float x = 0;
	float y = 0;
	int color = 0;
	while (j < 200)
	{
		i = 0;
		while (i < 200)
		{
			x = (i / 200.0) * data.w_n;
			y = (j / 200.0) * data.h_n;
			color = img_pix(&data, x, y);
			my_mlx_pixel_put(&data, i, j, color);
			i++;
		}
		j++;
	}
	
	
	
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 1L << 0, presskey, &data);
   	mlx_hook(data.win, 3, 1L << 0, un_presskey, &data); 
	mlx_hook(data.win, 17, 1L << 0, &exit_mlx, &data);
	//mlx_loop_hook(data.mlx, &move_player, &data);
	mlx_loop(data.mlx);
}

/*
300 = hauteurdelafenetre/distance;
(10, 55) (10 / 300 * 800, 55 / 300 * 800)
*/
// imahe haut / hauteur du mur
