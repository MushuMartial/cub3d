/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:04:46 by yasinbest         #+#    #+#             */
/*   Updated: 2022/05/05 21:14:02 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_dividein3(char **tab, t_data *data)
{
	int	i;
	int	k;
	int	turn;

	i = 0;
	k = 0;
	turn = -1;
	data->m = 0;
	data->l = 0;
	data->txtr = ft_calloc(sizeof(char *), 4);
	while (++turn < 4)
	{
		data->txtr[turn] = ft_calloc(sizeof(char), data->map_l + 1);
	}
	ft_divideno(i, k, tab, data);
	ft_divideso(i, k, tab, data);
	ft_dividewe(i, k, tab, data);
	ft_divideea(i, k, tab, data);
	ft_verifrgb(tab, i, k, data);
	ft_dividefloor(i, k, tab, data);
	ft_divideceiling(i, k, tab, data);
	ft_dividemap(i, k, tab, data);
	ft_setheight(i, data);
	free_tab(tab);
}

void	ft_empty(char **tab, int i, int k, int counter)
{
	int	commas;

	commas = 0;
	while (tab[i][k] != '\n' && tab[i][k])
	{
		while (tab[i][k] != '\n' && tab[i][k])
		{
			if (tab[i][k] == ',')
				ft_afou(&commas, &k);
			while (tab[i][k] >= 48 && tab[i][k] <= 57)
			{
				if (tab[i][k + 1] < 48 || tab[i][k + 1] > 57)
				{
					ft_losstime(&counter, &k);
					break ;
				}
				k++;
			}
			if (tab[i][k] != '\n' && tab[i][k] != ',')
				k++;
		}
		if (tab[i][k] != '\n')
			k++;
	}
	ft_enroule(counter, commas);
}

void	ft_locatefloor(char **tab, int i, int k, t_data *data)
{
	int	m;
	int	counter;

	counter = 0;
	m = 0;
	while (i < data->map_h)
	{
		while (tab[i][k] != '\n' && tab[i][k])
		{
			if (tab[i][k] == 'F' && tab[i][k + 1] == ' ')
			{
				ft_empty(tab, i, 0, counter);
				ft_rgbinvalid(tab, i, k + 1);
				ft_checkfloor(tab, i, 0, m);
				break ;
			}
			k++;
		}
		k = 0;
		i++;
	}
}

void	ft_locateceiling(char **tab, int i, int k, t_data *data)
{
	int	m;
	int	counter;

	m = 0;
	counter = 0;
	while (i < data->map_h)
	{
		while (tab[i][k] != '\n' && tab[i][k])
		{
			if (tab[i][k] == 'C' && tab[i][k + 1] == ' ')
			{
				ft_empty(tab, i, 0, counter);
				ft_rgbinvalid(tab, i, k + 1);
				ft_checkceiling(tab, i, 0, m);
				break ;
			}
			k++;
		}
		k = 0;
		i++;
	}
}

void	ft_verifrgb(char **tab, int i, int k, t_data *data)
{
	ft_locatefloor(tab, i, k, data);
	ft_locateceiling(tab, i, k, data);
}
