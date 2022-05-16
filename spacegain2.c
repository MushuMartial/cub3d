/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacegain2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:52:20 by yasinbest         #+#    #+#             */
/*   Updated: 2022/05/05 22:31:48 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_25line(size_t *len, int *i)
{
	*len = 0;
	*i = 0;
}

int	ft_control(int fd, char **line)
{
	char	*tmp;

	tmp = get_next_line(fd);
	*line = tmp;
	if (tmp)
	{
		return (1);
	}
	return (0);
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_opencheck(t_data *data)
{
	data->press = 0;
	if (open(data->txtr[0], O_RDWR) == -1)
	{
		printf("Texture failure\n");
		exit(1);
	}
	if (open(data->txtr[1], O_RDWR) == -1)
	{
		printf("Texture failure\n");
		exit(1);
	}
	if (open(data->txtr[2], O_RDWR) == -1)
	{
		printf("Texture failure\n");
		exit(1);
	}
	if (open(data->txtr[3], O_RDWR) == -1)
	{
		printf("Texture failure\n");
		exit(1);
	}
}
