/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:24:27 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/21 16:29:43 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//pos joueur
//vue pdt le spwan

int main(int argc, char **argv)
{
    t_data data;


	yasin(&data, argc, argv);
	data.press = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 800, 800, "cub3d");
	data.img = mlx_new_image(data.mlx, 800, 800);
	data.addr = mlx_get_data_addr(data.img, &data.b_pix, &data.len_pix, &data.endian);
	data.x = 5.5;
    data.y = 8.5;
	data.add_x = 0;
	data.add_y = 0;
	data.map_l = 8;
	data.map_h = 12;//24
	data.direction = 180.0;
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	make_player(&data);
	mlx_hook(data.win, 2, 1L << 0, presskey, &data);
   	mlx_hook(data.win, 3, 1L << 0, un_presskey, &data);
	mlx_hook(data.win, 17, 1L << 0, &exit_mlx, &data);
	mlx_loop(data.mlx);
	//free_tab(data.map);
}

