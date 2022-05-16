/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:42:29 by ybestrio          #+#    #+#             */
/*   Updated: 2022/05/05 20:36:38 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_forbiddenmap(t_data *data)
{
	int	i;
	int	k;

	data->playercount = 0;
	i = 0;
	k = 0;
	while (data->map[i] != 0)
	{
		while (data->map[i][k] != 0)
		{
			ft_checkcount(data->map[i][k], data);
			ft_checkprechar(data->map[i][k]);
			ft_checkwall(data->map[i][k], i, k, data);
			k++;
		}
		k = 0;
		i++;
	}
	if (data->playercount != 1)
	{
		printf("Error : player number is incorrect\n");
		exit(1);
	}
}

void	ft_setposition(t_data *data, int i, int k)
{
	if (data->map[i][k] == 'N')
	{
		data->x = (float)k + 0.5;
		data->y = (float)i + 0.5;
		data->direction = 180;
	}
	if (data->map[i][k] == 'E')
	{
		data->x = (float)k + 0.5;
		data->y = (float)i + 0.5;
		data->direction = 270;
	}
	if (data->map[i][k] == 'W')
	{
		data->x = (float)k + 0.5;
		data->y = (float)i + 0.5;
		data->direction = 90;
	}
	if (data->map[i][k] == 'S')
	{
		data->x = (float)k + 0.5;
		data->y = (float)i + 0.5;
		data->direction = 0;
	}
}

void	ft_checkcount(char c, t_data *data)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		data->playercount++;
}

void	ft_maperror(void)
{
	printf("ERROR wall or hole in map ? \n");
	exit(1);
}
