/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:24:27 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/16 10:48:19 by tmartial         ###   ########.fr       */
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
	make_player(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 1L << 0, presskey, &data);
   	mlx_hook(data.win, 3, 1L << 0, un_presskey, &data); 
	mlx_hook(data.win, 17, 1L << 0, &exit_mlx, &data);
	mlx_loop_hook(data.mlx, &move_player, &data);
	mlx_loop(data.mlx);
}

/* void make_map(t_data *data)
{
	data->map = malloc(sizeof(char *) * 8);
	data->map[0] = ft_strdup("11111111");
    data->map[1] = ft_strdup("10000011");
    data->map[2] = ft_strdup("10000001");
    data->map[3] = ft_strdup("10010011");
    data->map[4] = ft_strdup("10010001");
    data->map[5] = ft_strdup("10000001");
    data->map[6] = ft_strdup("100P0101");
    data->map[7] = ft_strdup("11111111");
    data->map_h = 8;
    data->map_l = 8;
	data->x = 3.45;
    data->y = 6.45;
	data->add_x = 0;
	data->add_y = 0;
	data->press = 0;
    data->press_turn = 0;
	data->direction = 180.000;
    
}*/