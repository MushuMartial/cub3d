/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:38:00 by yasinbest         #+#    #+#             */
/*   Updated: 2022/03/29 16:38:10 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_first(t_data *data)
{
	float	tempx;
	float	tempy;

	tempx = data->x;
	tempy = data->y;
	tempx += cos(data->direction * RAD) * 0.16;
	tempy -= sin(data->direction * RAD) * 0.16;
	if (data->map[(int)tempy][(int)tempx] == '1')
		return ;
	data->x += cos(data->direction * RAD) * 0.06;
	data->y -= sin(data->direction * RAD) * 0.06;
}

void	ft_second(t_data *data)
{
	float	tempx;
	float	tempy;

	tempx = data->x;
	tempy = data->y;
	tempx += sin(data->direction * RAD) * 0.16;
	tempy += cos(data->direction * RAD) * 0.16;
	if (data->map[(int)tempy][(int)tempx] == '1')
		return ;
	data->x += sin(data->direction * RAD) * 0.06;
	data->y += cos(data->direction * RAD) * 0.06;
}

void	ft_third(t_data *data)
{
	float	tempx;
	float	tempy;

	tempx = data->x;
	tempy = data->y;
	tempx -= cos(data->direction * RAD) * 0.16;
	tempy += sin(data->direction * RAD) * 0.16;
	if (data->map[(int)tempy][(int)tempx] == '1')
		return ;
	data->x -= cos(data->direction * RAD) * 0.06;
	data->y += sin(data->direction * RAD) * 0.06;
}

void	ft_fourth(t_data *data)
{
	float	tempx;
	float	tempy;

	tempx = data->x;
	tempy = data->y;
	tempx -= sin(data->direction * RAD) * 0.16;
	tempy -= cos(data->direction * (PI / 180)) * 0.16;
	if (data->map[(int)tempy][(int)tempx] == '1')
		return ;
	data->x -= sin(data->direction * RAD) * 0.06;
	data->y -= cos(data->direction * RAD) * 0.06;
}

/* Change variables to move */
void	moving(t_data *data, int action, int pres)
{
	if (data->add_x != 0.0 && data->add_y != 0.0 && pres == 0)
		(void)NULL;
	else
		data->press = pres;
	if (action == 1)
		ft_first(data);
	if (action == 2)
		ft_second(data);
	if (action == 3)
		ft_third(data);
	if (action == 4)
		ft_fourth(data);
}
