/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:24:53 by yasinbest         #+#    #+#             */
/*   Updated: 2022/05/06 11:52:05 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_makefloor(char **t, int i, int k, t_data *data)
{
	char	r[256];
	char	g[256];
	char	b[256];

	if (t[i][k++] == 'F')
	{
		while (t[i][k] == ' ')
			k++;
		while (t[i][k] != ',' && t[i][k] != ' ')
			r[data->m++] = t[i][k++];
		r[data->m] = 0;
		data->m = 0;
		while (t[i][k] == ' ' || t[i][k] == ',')
			k++;
		while (t[i][k] != ',' && t[i][k] != ' ')
			g[data->m++] = t[i][k++];
		g[data->m] = 0;
		data->m = 0;
		while (t[i][k] == ' ' || t[i][k] == ',')
			k++;
		while (t[i][k] != ',' && t[i][k] != ' ' && t[i][k] != '\n' && t[i][k])
			b[data->m++] = t[i][k++];
		b[data->m] = 0;
	}
	data->floor = create_rgb(atoi(r), atoi(g), atoi(b));
}

void	ft_rgbinvalid(char **tab, int i, int m)
{
	while (tab[i][m] != 0 && tab[i][m] != '\n')
	{
		if (tab[i][m] > 57 || tab[i][m] < 48)
		{
			if (tab[i][m] != ' ' && tab[i][m] != ',')
			{
				printf("Error : invalid RGB value\n");
				exit(1);
			}
		}
		m++;
	}
}

void	ft_makeceiling(char **t, int i, int k, t_data *data)
{
	char	r[256];
	char	g[256];
	char	b[256];

	if (t[i][k++] == 'C')
	{
		while (t[i][k] == ' ')
			k++;
		while (t[i][k] != ',' && t[i][k] != ' ')
			r[data->l++] = t[i][k++];
		r[data->l] = 0;
		data->l = 0;
		while (t[i][k] == ' ' || t[i][k] == ',')
			k++;
		while (t[i][k] != ',' && t[i][k] != ' ')
			g[data->l++] = t[i][k++];
		g[data->l] = 0;
		data->l = 0;
		while (t[i][k] == ' ' || t[i][k] == ',')
			k++;
		while (t[i][k] != ',' && t[i][k] != ' ' && t[i][k] != '\n' && t[i][k])
			b[data->l++] = t[i][k++];
		b[data->l] = 0;
	}
	data->ceiling = create_rgb(atoi(r), atoi(g), atoi(b));
}
