/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 04:11:49 by dcapers           #+#    #+#             */
/*   Updated: 2020/06/21 01:49:46 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			calc_step(t_step *stp, t_point *p1, t_point *p2)
{
	float		max;

	stp->x = p2->x - p1->x;
	stp->y = p2->y - p1->y;
	max = MOD(stp->x) > MOD(stp->y) ? MOD(stp->x) : MOD(stp->y);
	stp->x /= max;
	stp->y /= max;
	stp->z_step = (p2->z - p1->z) / max;
}

void			draw_line(t_point p1, t_point p2, t_fdf *st)
{
	t_step		step;
	int			i;
	int			color;

	color = (p1.z || p2.z) ? 0xff0000 : 0x0000ff;
	projection(&p1, st);
	projection(&p2, st);
	calc_step(&step, &p1, &p2);
	i = 0;
	while ((int)(p2.x - p1.x) || (int)(p2.y - p1.y))
	{
		mlx_pixel_put(st->mlx_ptr, st->win_ptr, p1.x, p1.y, color);
		p1.x += step.x;
		p1.y += step.y;
		i++;
	}
}

void			draw_map(t_fdf *st)
{
	int		x;
	int		y;

	y = 0;
	while (y < st->height)
	{
		x = 0;
		while (x < st->width)
		{
			if (y < st->height - 1)
				draw_line(st->map[y][x], st->map[y + 1][x], st);
			if (x < st->width - 1)
				draw_line(st->map[y][x], st->map[y][x + 1], st);
			x++;
		}
		y++;
	}
}
