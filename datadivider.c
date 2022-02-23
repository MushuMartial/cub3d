/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datadivider.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:25:51 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/21 10:54:11 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_divideno(int i, int k, char **tab, t_data *data)
{
	while (i < data->map_h)
	{
		while (k < data->map_l)
		{
			if (tab[i][k] == 'N' && tab[i][k+1] == 'O')
			{
				ft_cleanpath(tab, i, 0, data);
				if (i > data->lowhei)
					data->lowhei = i;
				break;
			}
			k++;
		}
		k = 0;
		i++;
	}
}

void ft_divideso(int i, int k, char **tab, t_data *data)
{
	while (i < data->map_h)
	{
		while (k < data->map_l)
		{
			if (tab[i][k] == 'S' && tab[i][k+1] == 'O')
			{
				ft_cleanpath(tab, i, 1, data);

				if (i > data->lowhei)
					data->lowhei = i;
				break;
			}
			k++;
		}
		k = 0;
		i++;
	}
}

void ft_divideea(int i, int k, char **tab, t_data *data)
{
	while (i < data->map_h)
	{
		while (k < data->map_l)
		{
			if (tab[i][k] == 'E' && tab[i][k+1] == 'A')
			{
				ft_cleanpath(tab, i, 2, data);

				if (i > data->lowhei)
					data->lowhei = i;
				break;
			}
			k++;
		}
		k = 0;
		i++;
	}
}

void ft_dividewe(int i, int k, char **tab, t_data *data)
{
	while (i < data->map_h)
	{
		while (k < data->map_l)
		{
			if (tab[i][k] == 'W' && tab[i][k+1] == 'E')
			{
				ft_cleanpath(tab, i, 3, data);

				if (i > data->lowhei)
					data->lowhei = i;
				break;
			}
			k++;
		}
		k = 0;
		i++;
	}
}

void	ft_dividefloor(int i, int k, char **tab, t_data *data)
{
	while (i < data->map_h)
	{
		while (k < data->map_l)
		{
			if (tab[i][k] == 'F' && tab[i][k+1] == ' ')
			{
				ft_makefloor(tab, i, k, data);
				if (i > data->lowhei)
					data->lowhei = i;
				break;
			}
			k++;
		}
		k = 0;
		i++;
	}
//	ft_checkrgb();
}
	
void	ft_divideceiling(int i, int k, char **tab, t_data *data)
{
	while (i < data->map_h)
	{
		while (k < data->map_l)
		{
			if (tab[i][k] == 'C' && tab[i][k+1] == ' ')
			{
				ft_makeceiling(tab, i, k, data);
				if (i > data->lowhei)
					data->lowhei = i;
				break;
			}
			k++;
		}
		k = 0;
		i++;
	}
}
