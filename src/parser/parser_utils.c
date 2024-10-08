/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:00:53 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/30 13:41:10 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	count_lines(char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		system_error(file);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!ft_strncmp(line, "\n", 1))
		{
			free(line);
			continue ;
		}
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

void	fill_data(char ***data, int fd)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line && !ft_strncmp(line, "\n", 2))
		{
			free(line);
			continue ;
		}
		tmp = ft_strtrim(line, "\n");
		(*data)[i++] = tmp;
		free(line);
	}
	(*data)[i] = NULL;
}

char	**copy_elements(char *file)
{
	int		fd;
	int		count;
	char	**data;

	count = count_lines(file);
	if (count == 0)
		return (NULL);
	data = malloc(sizeof(char *) * (count + 1));
	fd = open(file, O_RDONLY);
	if (fd == -1 || !data)
		system_error("malloc");
	fill_data(&data, fd);
	close(fd);
	return (data);
}

int	element_id(char *elem)
{
	if (!ft_strncmp(elem, "A", 2))
		return (AMBIENT);
	else if (!ft_strncmp(elem, "C", 2))
		return (CAMERA);
	else if (!ft_strncmp(elem, "L", 2))
		return (LIGHT);
	else if (!ft_strncmp(elem, "sp", 3))
		return (SPHERE);
	else if (!ft_strncmp(elem, "pl", 3))
		return (PLANE);
	else if (!ft_strncmp(elem, "cy", 3))
		return (CYLINDER);
	else
		return (-1);
}
