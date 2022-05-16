/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:35:42 by yasinbest         #+#    #+#             */
/*   Updated: 2022/03/29 18:59:05 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_couple(char *str1, char *str2)
{
	char	*temp;

	temp = ft_strjoin(str1, str2);
	free(str1);
	return (temp);
}

char	*chargenext(char *buffer)
{
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tmp = ft_calloc((ft_strlen(buffer) - i + 1), 1);
	i++;
	while (buffer[i] != 0)
	{
		tmp[k] = buffer[i];
		i++;
		k++;
	}
	free(buffer);
	return (tmp);
}

char	*chargeline(char *buffer)
{
	char	*output;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	output = ft_calloc(i + 200, 1);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		output[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		output[i] = '\n';
	return (output);
}

char	*chargebuff(int fd, char *buffer, int BUFFER_SIZE)
{
	int		read_byte;
	char	*tmp;

	read_byte = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, 1);
	while (read_byte > 0)
	{
		read_byte = read(fd, tmp, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(tmp);
			printf("Error\n");
			exit(1);
		}
		ft_contentinvalid(tmp);
		tmp[read_byte] = 0;
		buffer = ft_couple(buffer, tmp);
		if (ft_strchr(tmp, '\n') != 0)
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			buffer_size;

	buffer_size = 1;
	if (fd < 0 || read(fd, 0, 0) < 0 || buffer_size < 1)
	{
		printf("Error\n");
		exit(1);
	}
	buffer = chargebuff(fd, buffer, buffer_size);
	if (!buffer)
		return (NULL);
	line = chargeline(buffer);
	buffer = chargenext(buffer);
	return (line);
}
