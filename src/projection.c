/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 22:57:00 by dcapers           #+#    #+#             */
/*   Updated: 2020/06/21 14:59:32 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_point *p, double alpha)
{
	int p_y;

	p_y = p->y;
	p->y = p_y * cos(alpha) + p->z * sin(alpha);
	p->z = -p_y * sin(alpha) + p->z * cos(alpha);
}

static void	rotate_y(t_point *p, double beta)
{
	int p_x;

	p_x = p->x;
	p->x = p_x * cos(beta) + p->z * sin(beta);
	p->z = -p_x * sin(beta) + p->z * cos(beta);
}

static void	rotate_z(t_point *p, double gamma)
{
	int p_x;
	int p_y;

	p_x = p->x;
	p_y = p->y;
	p->x = p_x * cos(gamma) - p_y * sin(gamma);
	p->y = p_x * sin(gamma) + p_y * cos(gamma);
}

void		isometric(t_point *p)
{
	float	p_x;
	float	p_y;

	p_x = p->x;
	p_y = p->y;
	p->x = (p_x - p_y) * cos(0.523599);
	p->y = (p_x + p_y) * sin(0.523599) - p->z;
}

void		projection(t_point *p, t_fdf *st)
{
	p->x *= st->camera.zoom;
	p->y *= st->camera.zoom;
	if (!st->top)
	{
		rotate_x(p, st->camera.alpha);
		rotate_y(p, st->camera.beta);
		rotate_z(p, st->camera.gamma);
		isometric(p);
	}
	p->x += st->shift_x;
	p->y += st->shift_y;
}
