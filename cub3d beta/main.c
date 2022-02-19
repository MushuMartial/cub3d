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

int main()
{
    t_data data;
	data.press = 0;
	make_map(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 800, 800, "cub3d");
	data.img = mlx_new_image(data.mlx, 800, 800);
	data.addr = mlx_get_data_addr(data.img, &data.b_pix, &data.len_pix, &data.endian);
	
	//data.img_xpm = mlx_xpm_file_to_image(data.mlx, "./sekiro", xpm_height, );

	make_player(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 1L << 0, presskey, &data);
   	mlx_hook(data.win, 3, 1L << 0, un_presskey, &data); 
	mlx_hook(data.win, 17, 1L << 0, &exit_mlx, &data);
	mlx_loop_hook(data.mlx, &move_player, &data);
	mlx_loop(data.mlx);
}

/* int	get_img_pixel(t_img *img, int x, int y)
{
	char	*ptr;

	ptr = img->addr + (y * img->ll + x * (img->bpp / 8));
	return (*((int *)ptr));
}
300 = hauteurdelafenetre/distance;
(10, 55) (10 / 300 * 800, 55 / 300 * 800)
*/

/* void	*mlx;
	void	*img;
	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);*/