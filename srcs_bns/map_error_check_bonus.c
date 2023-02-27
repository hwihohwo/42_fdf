/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:13:38 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/27 21:20:31 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

	i = 0;
	while (i < 3 && line[i])
	{
		if ((i == 1 && line[i] != '0') || (i == 2 && line[i] != 'x'))
			return (0);
		i++;
	}
	if (i != 3)
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
