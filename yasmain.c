/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yasmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:18:03 by yasinbest         #+#    #+#             */
/*   Updated: 2022/05/06 11:43:25 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_setrange(char *path, char **tab, t_data *data)
{
	int		fd;
	char	*line;
	size_t	len;
	int		i;

	line = NULL;
	ft_25line(&len, &i);
	fd = open(path, O_RDWR);
	while (ft_control(fd, &line) && i++ >= 0)
	{
		if (ft_strlen(line) > len)
			len = ft_strlen(line);
		free(line);
	}
	close(fd);
	data->map_h = i;
	data->map_l = len;
	tab = ft_calloc(sizeof(char *), i + 3);
	fd = open(path, O_RDWR);
	i = -1;
	while (ft_control(fd, &line))
		tab[++i] = line;
	close(fd);
	ft_setup(tab, data, len);
}

void	ft_setup(char **tab, t_data *data, size_t len)
{
	len = 0;
	ft_dividein3(tab, data);
	ft_error(data);
}

void	ft_nameissues(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 5)
	{
		printf("Error in file name, too short ?\n");
		exit(1);
	}
	if (str[i - 4] != '.' && str[i - 3] != 'c' && str[i - 2] != 'u')
	{
		printf("Invalid extension ?");
		exit(1);
	}
	if (str[i - 1] != 'b')
	{
		printf("Invalid extension ?");
		exit(1);
	}
}

void	ft_revlines(t_data *data, int i, t_rev *r)
{
	r->m = -1;
	while (data->map[++r->m] != 0)
	{
		if ((int)ft_strlen(data->map[r->m]) > r->len)
			r->len = ft_strlen(data->map[r->m]);
	}
	r->k = ft_strlen(data->map[i]);
	r->m = -1;
	while (r->k != 0)
	{
		r->k--;
		if (data->map[i][r->k] == '1')
		{
			while (r->k < r->len)
			{
				data->map[i][r->k] = '1';
				r->k++;
			}
			break ;
		}
	}
	r->k = ft_strlen(data->map[i]);
	r->max = r->len / 2;
	ft_boring(data, i, r);
}

void	yasin(t_data *data, int argc, char **argv)
{
	char	**tab;
	int		i;
	int		k;
	t_rev	rev;

	rev.len = 0;
	tab = NULL;
	data->argc = argc;
	data->lowhei = 0;
	ft_nameissues(argv[1]);
	ft_setrange(argv[1], tab, data);
	i = -1;
	while (data->map[++i] != 0)
		ft_revlines(data, i, &rev);
	i = -1;
	k = -1;
	while (data->map[++i] != 0)
	{
		while (data->map[i][++k] != 0)
			ft_setposition(data, i, k);
		k = -1;
	}
}
