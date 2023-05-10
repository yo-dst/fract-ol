/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 08:46:04 by ydanset           #+#    #+#             */
/*   Updated: 2021/12/06 08:46:07 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	grey(t_var *var, int nb_iteration)
{
	t_rgb	rgb;

	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.3 * nb_iteration) * 127 + 128;
	rgb.g = sin(0.3 * nb_iteration) * 127 + 128;
	rgb.b = sin(0.3 * nb_iteration) * 127 + 128;
	return (rgb_to_int(rgb));
}

unsigned int	smooth_red(t_var *var, int nb_iteration)
{
	t_rgb	rgb;

	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = nb_iteration * 255 / var->iteration_max;
	rgb.g = 0;
	rgb.b = 0;
	return (rgb_to_int(rgb));
}

unsigned int	rainbow_0(t_var *var, int nb_iteration)
{
	t_rgb	rgb;

	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.3 * nb_iteration + 3) * 127 + 128;
	rgb.g = sin(0.3 * nb_iteration + 2) * 127 + 128;
	rgb.b = sin(0.3 * nb_iteration + 1) * 127 + 128;
	rgb.b = (rgb.b + var->iteration_max) % 256;
	return (rgb_to_int(rgb));
}

unsigned int	rainbow_1(t_var *var, int nb_iteration)
{
	t_rgb	rgb;

	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.4 * nb_iteration) * 127 + 128;
	rgb.g = sin(0.5 * nb_iteration + 2) * 127 + 128;
	rgb.b = sin(0.6 * nb_iteration + 1) * 127 + 128;
	return (rgb_to_int(rgb));
}

unsigned int	zebra(t_var *var, int nb_iteration)
{
	if ((var->iteration_max - nb_iteration) % 3)
		return (0xffffff);
	return (0x0);
}
