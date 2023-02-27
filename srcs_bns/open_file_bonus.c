/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:44:31 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/27 21:20:35 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

char	*open_file(char *argv)
{
	int		fd;
	int		col_num;
	char	*line;
	char	*total;

	col_num = 0;
	total = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		open_error_exit();
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		check_line(line, &col_num, total);
		if (total == 0)
			total = line;
		else
			total = join_line(total, line);
	}
	close(fd);
	return (total);
}

void	check_line(char *line, int *col_num, char *total)
{
	int		i;
	char	**line_sep;

	i = 0;
	line_sep = ft_split(line, ' ');
	while (line_sep[i])
	{
		if (!error_check(line_sep[i]))
			map_error_exit(line_sep, line, total);
		i++;
	}
	if (line_sep[i - 1][0] == '\n')
		i--;
	if (*col_num == 0)
		*col_num = i;
	else
		if (*col_num != i)
			map_error_exit(line_sep, line, total);
	free_string_array(line_sep);
}

void	free_string_array(char **line_sep)
{
	int	i;

	i = 0;
	while (line_sep[i])
		free(line_sep[i++]);
	free(line_sep);
}

char	*join_line(char *total, char *line)
{
	char	*temp;

	if (total == 0)
		total = line;
	else
	{
		temp = total;
		total = ft_strjoin(temp, line);
		free(temp);
		free(line);
	}
	return (total);
}
