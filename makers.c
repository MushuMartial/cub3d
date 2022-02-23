/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:24:53 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/21 12:44:11 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_makefloor(char **tab, int i, int k, t_data *data) // need to rewrite and optimize
{
	char r[4];
	char g[4];
	char b[4];
	int m;
	
	m = 0;
	if (tab[i][k] == 'F')
	{
		k++;
		while (tab[i][k] == ' ')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ')
			r[m++] = tab[i][k++];
		r[m] = 0;
		m = 0;
		while (tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ')
			g[m++] = tab[i][k++];
		g[m] = 0;
		m = 0;
		while (tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ' && tab[i][k] != '\n')
			b[m++] = tab[i][k++];
		b[m] = 0;
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

void	ft_makeceiling(char **tab, int i, int k, t_data *data)
{
	char r[4];
	char g[4];
	char b[4];
	int m;
	m = 0;

	if (tab[i][k] == 'C')
	{
		k++;
		while (tab[i][k] == ' ')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ')
			r[m++] = tab[i][k++];
		r[m] = 0;
		m = 0;
		while (tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ')
			g[m++] = tab[i][k++]; 
		g[m] = 0;
		m = 0;
		while (tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ' && tab[i][k] != '\n')
			b[m++] = tab[i][k++]; 
		b[m] = 0;
	}
	data->ceiling = create_rgb(atoi(r), atoi(g), atoi(b)); //switch to ft_atoi
}
