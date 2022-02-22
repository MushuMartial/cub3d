/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:27:19 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/22 11:21:24 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Move player */
int move_player(t_data *data)
{
	if (data->press == 1 || data->press_turn == 1)
	{
		data->x += data->add_x;
		data->y += data->add_y;
		make_player(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return(0);
}

/* Change variables to move */
void moving(t_data *data, int action, int pres)
{
	float	tempx = data->x;
	float	tempy = data->y;

	if (data->add_x != 0.0 && data->add_y != 0.0 && pres == 0)
		(void)NULL;
	else
		data->press = pres;


	if (action == 1)
	{
		tempx += cos(data->direction * (PI / 180)) * 0.16;
		tempy -= sin(data->direction * (PI / 180)) * 0.16;
		if (data->map[(int)tempy][(int)tempx] == '1')
			return;
		data->x += cos(data->direction * (PI / 180)) * 0.06;
		data->y -= sin(data->direction * (PI / 180)) * 0.06;
	}
	if (action == 2)
	{
		tempx += sin(data->direction * (PI / 180)) * 0.16;
		tempy += cos(data->direction * (PI / 180)) * 0.16;
		if (data->map[(int)tempy][(int)tempx] == '1')
			return;
		data->x += sin(data->direction * (PI / 180)) * 0.06;
		data->y += cos(data->direction * (PI / 180)) * 0.06;
	}
	if (action == 3)
	{
		tempx -= cos(data->direction * (PI / 180)) * 0.16;
		tempy += sin(data->direction * (PI / 180)) * 0.16;
		if (data->map[(int)tempy][(int)tempx] == '1')
			return;
		data->x -= cos(data->direction * (PI / 180)) * 0.06;
		data->y += sin(data->direction * (PI / 180)) * 0.06;
	}
	if (action == 4)
	{
		tempx -= sin(data->direction * (PI / 180)) * 0.16;
		tempy -= cos(data->direction * (PI / 180)) * 0.16;
		if (data->map[(int)tempy][(int)tempx] == '1')
			return;
		data->x -= sin(data->direction * (PI / 180)) * 0.06;
		data->y -= cos(data->direction * (PI / 180)) * 0.06;
	}
	
	
	
	/*if (data->add_x != x)
		data->add_x += x;
	if (data->add_y != y)
		data->add_y += y;
*/}

/* turn sides */
void turning(t_data *data, int pres, int sens)
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
int presskey(int keycode, t_data *data)
{
	if (keycode == 53)
		exit_mlx(data);
	if (keycode == 2)//left
		moving(data, 1 , 1);
	else if (keycode == 0)//right
	{
		moving(data, 3, 1);
	}
	else if (keycode == 13)//up
	{
		moving(data, 2, 1);
	}

	else if (keycode == 1)//down
		moving(data, 4, 1);
	else if (keycode == 124)//left g
		turning(data, 1, 1);
	else if (keycode == 123)//right
		turning(data, 1, 0);
	return (0);
}

/* Check unpresskey */
int un_presskey(int keycode, t_data *data)
{
	if (keycode == 53)
		exit_mlx(data);
	if (keycode == 2)//left
		moving(data, 1, 0);
	else if (keycode == 0)//right
		moving(data, 3, 0);
	else if (keycode == 13)//up
		moving(data, 2, 0);
	else if (keycode == 1)//down
		moving(data, 4, 0);
	else if (keycode == 124)//left g
		turning(data, 0, 0);
	else if (keycode == 123)//right
		turning(data, 0, 0);
	return (0);
}
