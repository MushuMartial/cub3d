/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datadivider.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:14:20 by yasinbest         #+#    #+#             */
/*   Updated: 2022/03/29 18:21:24 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_divideno(int i, int k, char **tab, t_data *data)
{
	while (i < data->map_h)
	{
		while (k < data->map_l)
		{
			if (tab[i][k] == 'N' && tab[i][k + 1] == 'O')
			{
				ft_cleanpath(tab, i, 0, data);
				if (i > data->lowhei)
					data->lowhei = i;
				return ;
			}
			k++;
		}
		k = 0;
		i++;
	}
}

void	ft_divideso(int i, int k, char **tab, t_data *data)
{
	while (i < data->map_h)
	{
		while (k < data->map_l)
		{
			if (tab[i][k] == 'S' && tab[i][k + 1] == 'O')
			{
				ft_cleanpath(tab, i, 1, data);
				if (i > data->lowhei)
					data->lowhei = i;
				return ;
			}
			k++;
		}
		k = 0;
		i++;
	}
}

void	ft_divideea(int i, int k, char **tab, t_data *data)
{
	while (i < data->map_h)
	{
		while (k < data->map_l)
		{
			if (tab[i][k] == 'E' && tab[i][k + 1] == 'A')
			{
				ft_cleanpath(tab, i, 2, data);
				if (i > data->lowhei)
					data->lowhei = i;
				return ;
			}
			k++;
		}
		k = 0;
		i++;
	}
}

void	ft_dividewe(int i, int k, char **tab, t_data *data)
{
	while (i < data->map_h)
	{
		while (k < data->map_l)
		{
			if (tab[i][k] == 'W' && tab[i][k + 1] == 'E')
			{
				ft_cleanpath(tab, i, 3, data);
				if (i > data->lowhei)
					data->lowhei = i;
				return ;
			}
			k++;
		}
		k = 0;
		i++;
	}
}
