/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:42:18 by ybestrio          #+#    #+#             */
/*   Updated: 2022/05/04 10:24:57 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_cleanpath(char **tab, int ln, int tx, t_data *data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (tab[ln][i] != '.' && tab[ln][i] != '\n')
		i++;
	while (tab[ln][i] != 0 && tab[ln][i] != '\n')
	{
		data->txtr[tx][k] = tab[ln][i];
		i++;
		k++;
	}
	data->txtr[tx][k] = 0;
}

void	ft_dividemap(int i, int k, char **tab, t_data *data)
{
	int	rest;
	int	m;

	m = 0;
	i = data->lowhei + 1;
	rest = (data->map_h - i) + 1;
	data->map = ft_calloc(sizeof(char *), rest + 3);
	while (k < rest)
	{
		data->map[k] = ft_calloc(sizeof(char), data->map_l + 200);
		k++;
	}
	k = 0;
	while (i < data->map_h)
	{
		while (k < data->map_l)
		{
			data->map[m][k] = tab[i][k];
			k++;
		}
		k = 0;
		i++;
		m++;
	}
}

void	ft_setheight(int i, t_data *data)
{
	while (data->map[i] != 0)
		i++;
	data->map_h = i;
}
