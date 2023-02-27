/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:49:44 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/27 19:14:06 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	z_rotate(double *x, double *y, double *z, double angle)
{
	double	temp_x;
	double	temp_y;
	double	temp_z;

	temp_x = *x;
	temp_y = *y;
	temp_z = *z;
	*x = temp_x * cos(PI / 180 * angle) - temp_y * sin(PI / 180 * angle);
	*y = temp_x * sin(PI / 180 * angle) + temp_y * cos(PI / 180 * angle);
}

void	y_rotate(double *x, double *y, double *z, double angle)
{
	double	temp_x;
	double	temp_y;
	double	temp_z;

	temp_x = *x;
	temp_y = *y;
	temp_z = *z;
	*x = temp_x * cos(PI / 180 * angle) + temp_z * sin(PI / 180 * angle);
	*z = (-1) * temp_x * sin(PI / 180 * angle) + temp_z * cos(PI / 180 * angle);
}

void	x_rotate(double *x, double *y, double *z, double angle)
{
	double	temp_x;
	double	temp_y;
	double	temp_z;

	temp_x = *x;
	temp_y = *y;
	temp_z = *z;
	*y = temp_z * sin(PI / 180 * angle) + temp_y * cos(PI / 180 * angle);
	*z = temp_z * cos(PI / 180 * angle) - temp_y * sin(PI / 180 * angle);
}