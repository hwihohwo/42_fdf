/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:44:31 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/10 05:53:57 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*input_file(char *argv)
{
	int		fd;
	int		col_num;
	char	*line;
	char	*total;

	col_num = 0;
	total = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		open_error();
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		check_line(line, &col_num, total);
		if (total == NULL)
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
	if (*col_num == 0)
		*col_num = i;
	else
		if (*col_num != i)
			map_error_exit(line_sep, line, total);
	i = 0;
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

	if (total == NULL)
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

void	open_error(void)
{
	perror(0);
	exit(1);
}
