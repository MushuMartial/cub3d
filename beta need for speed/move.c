/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:27:19 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/07 16:39:03 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Move player */
int move_player(t_data *data)
{
	if (data->press == 1)
	{
		make_img(data);
		data->x += data->add_x;
		data->y += data->add_y;
		make_player(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return(0);
}

/* Change variables to move */
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

/* Check presskey */
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

/* Check unpresskey */
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