/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datadivider2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:13:22 by yasinbest         #+#    #+#             */
/*   Updated: 2022/03/29 19:01:33 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	ft_incomplete(int i, int k, char **tab)
{
	while (tab[i][k] != '\n')
	{
		k++;
		if (tab[i][k] != ' ')
			return (0);
		else if (tab[i][k] == ' ' && tab[i][k + 1] == '\n')
			return (1);
	}
	return (1);
}

void	ft_dividefloor(int i, int k, char **tab, t_data *data)
{
	while (i < data->map_h)
	{
		while (k < data->map_l)
		{
			if (tab[i][k] == '\n')
				break ;
			if (tab[i][k] == 'F' && tab[i][k + 1] == ' ')
			{
				if (ft_incomplete(i, k, tab) == 1)
				{
					printf("Error with RGB input ?");
					exit(1);
				}
				ft_makefloor(tab, i, k, data);
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

void	ft_divideceiling(int i, int k, char **tab, t_data *data)
{
	while (i < data->map_h)
	{
		while (k < data->map_l)
		{
			if (tab[i][k] == '\n')
				break ;
			if (tab[i][k] == 'C' && tab[i][k + 1] == ' ')
			{
				if (ft_incomplete(i, k, tab) == 1)
				{
					printf("Error with RGB input ?");
					exit(1);
				}
				ft_makeceiling(tab, i, k, data);
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
