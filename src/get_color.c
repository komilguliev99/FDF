/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 21:17:09 by dcapers           #+#    #+#             */
/*   Updated: 2020/06/21 01:09:41 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			mod(double a)
{
	return (a > 0 ? a : -a);
}

int				get_color(float z, t_fdf *st)
{
	int		red;
	int		green;
	int		blue;

	z /= st->max_z;
	red = st->start.r + (st->end.r - st->start.r) * mod(z);
	green = st->start.g + (st->end.g - st->start.g) * mod(z);
	blue = st->start.b + (st->end.b - st->start.b) * mod(z);
	if (red == 0 && green == 0 && blue == 0)
		return ((st->start.r << 16) | (st->start.g << 8) | (st->start.b));
	return ((red << 16) | (green << 8) | blue);
}
