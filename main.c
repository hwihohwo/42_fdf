/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:08:34 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/08 04:29:19 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	char	*format;

	if (argc != 2)
	{
		perror("input one .fdf file");
		return (-1);
	}
	format = ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1]));
	if (format == NULL || format[4] != '\0')
	{
		perror("invalid file format");
		return (-1);
	}
	input_file(argv[1]);
	return (0);
}
