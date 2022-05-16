/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:27:19 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/29 16:38:28 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

/* Move player */
int	move_player(t_data *data)
{
	if (data->press == 1 || data->press_turn == 1)
	{
		data->x += data->add_x;
		data->y += data->add_y;
		make_player(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}

/* turn sides */
void	turning(t_data *data, int pres, int sens)
{
	data->press_turn = pres;
	if (data->press_turn == 1 && sens == 1)
	{
		if (data->direction == 360)
			data->direction = 0;
		data->direction += 3;
	}
	else if (data->press_turn == 1 && sens == 0)
	{
		if (data->direction == 0)
			data->direction = 360;
		data->direction -= 3;
	}
}

/* Check presskey */
int	presskey(int keycode, t_data *data)
{
	if (keycode == 53)
		exit_mlx(data);
	if (keycode == 2)
		moving(data, 1, 1);
	else if (keycode == 0)
	{
		moving(data, 3, 1);
	}
	else if (keycode == 13)
	{
		moving(data, 2, 1);
	}
	else if (keycode == 1)
		moving(data, 4, 1);
	else if (keycode == 124)
		turning(data, 1, 1);
	else if (keycode == 123)
		turning(data, 1, 0);
	return (0);
}

/* Check unpresskey */
int	un_presskey(int keycode, t_data *data)
{
	if (keycode == 53)
		exit_mlx(data);
	if (keycode == 2)
		moving(data, 1, 0);
	else if (keycode == 0)
		moving(data, 3, 0);
	else if (keycode == 13)
		moving(data, 2, 0);
	else if (keycode == 1)
		moving(data, 4, 0);
	else if (keycode == 124)
		turning(data, 0, 0);
	else if (keycode == 123)
		turning(data, 0, 0);
	return (0);
}
