/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:27:19 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/21 14:54:36 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*int move_player(t_data *data)
{
	float tempx = data->x;
	float tempy = data->y;
	tempx += data->add_x;
	tempy += data->add_y;

	if ( data->press == 1 || data->press_turn == 1)
	{
		if(data->map[(int)tempy][(int)tempx] == '1')
			return (0);
		data->y += data->add_y;
		data->x += data->add_x;
		make_player(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return(0);
}*/

/* turn sides */
void turning(t_data *data, int pres, int sens)
{
	data->press_turn = pres;
	if (data->press_turn == 1 && sens == 1)
	{
		if (data->direction == 0)
			data->direction = 360;
		if ((data->direction) == 363)
			(data->direction) = 3;
		(data->direction) += 3;
	}
	else if (data->press_turn == 1 && sens == 0)
	{
		if ((data->direction) == 0)
			(data->direction) = 360;
		if ((data->direction) == 363)
			(data->direction) = 3;
		(data->direction) -= 3;
	}
	make_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	forward(t_data *data, int pres)
{
	data->press_turn = pres;
	if (pres == 1)
	{
		float tempx = data->x;
		float tempy = data->y;
	
		tempx += cos((data->direction) * RAD) * 0.16;
		tempy += sin((data->direction) * RAD) * 0.16;
		//if(data->map[(int)tempy][(int)tempx] == '1')
			//return ;
		data->x += cos((data->direction) * RAD) * 0.06;// on avance sur X
		data->y += sin((data->direction) * RAD) * 0.06;// on avance sur Y
		make_player(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
}

void	back(t_data *data, int pres)
{
	data->press_turn = pres;
	if (pres == 1)
	{
		float tempx = data->x;
		float tempy = data->y;
	
		tempx -= cos((data->direction) * RAD) * 0.16;
		tempy -= sin((data->direction) * RAD) * 0.16;
		if(data->map[(int)tempy][(int)tempx] == '1')
			return ;
		data->x -= cos((data->direction) * RAD) * 0.06;// on recule sur X
		data->y -= sin((data->direction) * RAD) * 0.06;// on recule sur Y
	}
	make_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	left(t_data *data, int pres)
{
	data->press_turn = pres;
	if (pres == 1)
	{
		float tempx = data->x;
		float tempy = data->y;
	
		tempx += sin((data->direction) * RAD) * 0.16;
		tempy -= cos((data->direction) * RAD) * 0.16;
		if(data->map[(int)tempy][(int)tempx] == '1')
			return ;
		data->x += sin((data->direction) * RAD) * 0.06;
		data->y -= cos((data->direction) * RAD) * 0.06;
	}
	make_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	right(t_data *data, int pres)
{
	data->press_turn = pres;
	if (pres == 1)
	{
		float tempx = data->x;
		float tempy = data->y;
	
		tempx -= sin((data->direction) * RAD) * 0.16;
		tempy += cos((data->direction) * RAD) * 0.16;
		if(data->map[(int)tempy][(int)tempx] == '1')
			return ;
		data->x -= sin((data->direction) * RAD) * 0.06;
		data->y += cos((data->direction) * RAD) * 0.06;
	}
	make_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

/* Check presskey */
int presskey(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit_mlx(data);
	if (keycode == LEFT)
		left(data, 1);
	else if (keycode == RIGHT)
		right(data, 1);
	else if (keycode == UP)
		forward(data, 1);
	else if (keycode == DOWN)
		back(data, 1);
	else if (keycode == LOOK_LEFT)
		turning(data, 1, 1);
	else if (keycode == LOOK_RIGHT)
		turning(data, 1, 0);
	return (0);
}

/* Check unpresskey */
int un_presskey(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit_mlx(data);
	if (keycode == LEFT)
		left(data, 0);
	else if (keycode == RIGHT)
		right(data, 0);
	else if (keycode == UP)
		forward(data, 0);
	else if (keycode == DOWN)
		back(data, 0);
	else if (keycode == LOOK_LEFT)
		turning(data, 0, 0);
	else if (keycode == LOOK_RIGHT)
		turning(data, 0, 0);
	return (0);
}
