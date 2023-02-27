/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol_16_fdf_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:08:29 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/27 21:20:14 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_strtol_get_val(char c)
{
	int		i;
	char	*num;
	char	*upper_num;

	i = 0;
	num = "0123456789abcdef";
	upper_num = "0123456789ABCDEF";
	if ((c >= 'a' && c <= 'f') || (c >= '0' && c <= '9'))
	{
		while (c != num[i])
			i++;
		return (i);
	}
	else
	{
		while (c != upper_num[i])
			i++;
		return (i);
	}
}

int	ft_strtol_16_fdf(char *str)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != ',')
		return (0xFFFFFF);
	else
		i += 3;
	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
		ret = ret * 16 + ft_strtol_get_val(str[i++]);
	return (ret);
}
