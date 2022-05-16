/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:04:06 by yasinbest         #+#    #+#             */
/*   Updated: 2022/05/05 20:50:45 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rgbsize(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255)
	{
		printf("Error RGB is too big ?\n");
		exit(1);
	}
	if (r < 0 || g < 0 || b < 0)
	{
		printf("Error RGB is too small ?\n");
		exit(1);
	}
}

int	ft_skipline(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line[0] != '\n')
			break ;
	}
	return (0);
}

void	ft_checkfloor(char **t, int i, int k, int m)
{
	char	r[40];
	char	g[40];
	char	b[40];

	if (t[i][k++] == 'F')
	{
		while (t[i][k] == ' ')
			k++;
		while (t[i][k] != ',' && t[i][k] != ' ')
			r[m++] = t[i][k++];
		r[m] = 0;
		m = 0;
		while (t[i][k] == ' ' || t[i][k] == ',')
			k++;
		while (t[i][k] != ',' && t[i][k] != ' ')
			g[m++] = t[i][k++];
		g[m] = 0;
		m = 0;
		while (t[i][k] == ' ' || t[i][k] == ',')
			k++;
		while (t[i][k] != 44 && t[i][k] != 32 && t[i][k] != '\n' && t[i][k + 1])
			b[m++] = t[i][k++];
		b[m] = 0;
	}
	ft_rgbsize(atoi(r), atoi(g), atoi(b));
}

void	ft_checkceiling(char **t, int i, int k, int m)
{
	char	r[40];
	char	g[40];
	char	b[40];

	if (t[i][k++] == 'C')
	{
		while (t[i][k] == ' ')
			k++;
		while (t[i][k] != ',' && t[i][k] != ' ')
			r[m++] = t[i][k++];
		r[m] = 0;
		m = 0;
		while (t[i][k] == ' ' || t[i][k] == ',')
			k++;
		while (t[i][k] != ',' && t[i][k] != ' ')
			g[m++] = t[i][k++];
		g[m] = 0;
		m = 0;
		while (t[i][k] == ' ' || t[i][k] == ',')
			k++;
		while (t[i][k] != 44 && t[i][k] != 32 && t[i][k] != '\n' && t[i][k + 1])
			b[m++] = t[i][k++];
		b[m] = 0;
	}
	ft_rgbsize(atoi(r), atoi(g), atoi(b));
}
