/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:14:55 by yasinbest         #+#    #+#             */
/*   Updated: 2022/03/29 17:15:09 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_checkwall(char c, int i, int k, t_data *data)
{
	if (c == '0' || c == 'N' || c == 'E' || c == 'W' || c == 'S')
	{
		if (data->map[i][k - 1] != '0' && data->map[i][k - 1] != '1' &&
				data->map[i][k - 1] != 'N' && data->map[i][k - 1] != 'W' &&
				data->map[i][k - 1] != 'E' && data->map[i][k - 1] != 'S')
			ft_maperror();
		if (data->map[i][k + 1] != '0' && data->map[i][k + 1] != '1' &&
				data->map[i][k + 1] != 'N' && data->map[i][k + 1] != 'W' &&
				data->map[i][k + 1] != 'E' && data->map[i][k + 1] != 'S')
			ft_maperror();
		if (data->map[i - 1][k] != '0' && data->map[i - 1][k] != '1' &&
				data->map[i - 1][k] != 'N' && data->map[i - 1][k] != 'W' &&
				data->map[i - 1][k] != 'E' && data->map[i - 1][k] != 'S')
			ft_maperror();
		if (data->map[i + 1][k] != '0' && data->map[i + 1][k] != '1' &&
				data->map[i + 1][k] != 'N' && data->map[i + 1][k] != 'W' &&
				data->map[i + 1][k] != 'E' && data->map[i + 1][k] != 'S')
			ft_maperror();
	}
}

void	ft_error(t_data *data)
{
	ft_forbiddenmap(data);
}

void	ft_contentinvalid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
}

void	ft_checkchar(char c)
{
	if (c == 'C' || c == '0' || c == '1' || c == 'E' || c == 'P' || c == '\n')
		return ;
	else
	{
		printf("Forbidden key in file");
		exit(1);
	}
}

void	ft_checkprechar(char c)
{
	if (c == 'S' || c == 'N' || c == '0' || c == '1' || c == ' ' || c == '\n')
		return ;
	else if (c == 'E' || c == 'W')
		return ;
	else
	{
		printf("Forbidden key in map");
		exit(1);
	}
}
