/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:07:06 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/22 13:06:08 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_forbiddenmap(t_data *data)
{
	int i;
	int k;

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
			ft_setposition(data, i, k);
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

void	ft_maperror()
{
	printf("ERROR wall or hole in map ? \n");
	exit(1);
}
void	ft_checkwall(char c, int i, int k, t_data *data)
{
	if (c == '0' || c == 'N' || c == 'E' || c == 'W' || c == 'S')
	{
		if (data->map[i][k-1] != '0' && data->map[i][k-1] != '1' && 
				data->map[i][k-1] != 'N' && data->map[i][k-1] != 'W' && 
				data->map[i][k-1] != 'E' && data->map[i][k-1] != 'S')
			ft_maperror();
		if (data->map[i][k+1] != '0' && data->map[i][k+1] != '1' && 
				data->map[i][k+1] != 'N' && data->map[i][k+1] != 'W' && 
				data->map[i][k+1] != 'E' && data->map[i][k+1] != 'S')
			ft_maperror();
		if (data->map[i-1][k] != '0' && data->map[i-1][k] != '1' && 
				data->map[i-1][k] != 'N' && data->map[i-1][k] != 'W' && 
				data->map[i-1][k] != 'E' && data->map[i-1][k] != 'S')
			ft_maperror();
		if (data->map[i+1][k] != '0' && data->map[i+1][k] != '1' && 
				data->map[i+1][k] != 'N' && data->map[i+1][k] != 'W' && 
				data->map[i+1][k] != 'E' && data->map[i+1][k] != 'S')
			ft_maperror();
	}
}

void	ft_error(t_data *data)
{
	ft_forbiddenmap(data);
}

void	ft_contentinvalid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
}

void	ft_checkchar(char c)
{
	if (c == 'C' || c == '0' || c == '1' || c == 'E' || c == 'P' || c == '\n')
		return ;
	else
	{
		printf("Forbidden key in file");
		exit(1);
	}
}

void	ft_checkprechar(char c)
{
	if (c == 'S' || c == 'N' || c == '0' || c == '1' || c == ' ' || c == '\n')
		return ;
	else if (c == 'E' || c == 'W')
		return ;
	else
	{
		printf("Forbidden key in map");
		exit(1);
	}
}
