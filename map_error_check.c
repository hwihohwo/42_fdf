/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:13:38 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/10 06:02:41 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (i == 0 && (line[i] == '+' || line[i] == '-'))
		{
			i++;
			continue ;
		}
		if (i != 0 && line[i] == ',')
			break ;
		else if (line[i] < '0' || line[i] > '9')
			return (0);
		i++;
	}
	if (line[i] == ',')
		return (color_error_check(&line[i]));
	return (1);
}

int	color_error_check(char *line)
{
	int	i;

	i = 3;
	if (line[i - 2] != '0' || line[i - 1] != 'x')
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (i > 8)
			return (0);
		if ((line[i] >= '0' && line[i] <= '9') || \
		(line[i] >= 'a' && line[i] <= 'f') || \
		(line[i] >= 'A' && line[i] <= 'F'))
			i++;
		else
			return (0);
	}
	return (1);
}

void	map_error_exit(char **line_sep, char *line, char *total)
{
	perror("invalid map");
	free_string_array(line_sep);
	if (line != NULL)
		free(line);
	if (total != NULL)
		free(total);
	exit(1);
}
