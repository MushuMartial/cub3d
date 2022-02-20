/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:18:03 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/17 11:31:37 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_setrange(char *path, char **tab, t_data *data)
{
	int		fd;
	char	*line;
	int		len;
	int		i;
	
	len = 0;
	i = 0;
	fd = open(path, O_RDWR);//if open fail fd == -1
	while ((line = get_next_line(fd)))//if gnl malloc fail return null
	{
		if (strlen(line) > len)
			len = strlen(line);
		i++;
		free(line);
	}
	close(fd);
	data->maphei = i;
	data->maplen = len;
	tab = calloc(sizeof(char *), i + 1);//tab non protege
	fd = open(path, O_RDWR);//if open fail fd == -1
	i = -1;
	while ((line = get_next_line(fd)))
		tab[++i] = line;
	close(fd);
	ft_setup(tab, data, len);
}

void	ft_setup(char **tab, t_data *data, int len)
{
//	ft_exception(tab, data, len);
	ft_dividein3(tab, data);
	ft_error(data);
}


void yasin(t_data *data, int argc, char **argv)
{
	char **tab;

	data->argc = argc;
	data->lowhei = 0;

	ft_setrange(argv[1], tab, data);
	ft_images(data);//matrix

	free_tab(data->map);
}