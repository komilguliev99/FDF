/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 00:52:01 by dcapers           #+#    #+#             */
/*   Updated: 2020/06/21 15:00:22 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_press(int key, t_fdf *st)
{
	if (key == 65362)
		st->shift_y -= 10;
	if (key == 65364)
		st->shift_y += 10;
	if (key == 65361)
		st->shift_x -= 10;
	if (key == 65363)
		st->shift_x += 10;
	if (key == 65451)
	{
		st->max_z += Z_STEP;
		update_points(st->map, st->height, st->width, '+');
	}
	if (key == 65453)
	{
		st->max_z -= Z_STEP;
		update_points(st->map, st->height, st->width, '-');
	}
	if (key == 105)
		st->top = 1;
	if (key == 65307)
		exit(0);
	mlx_clear_window(st->mlx_ptr, st->win_ptr);
	draw_map(st);
	return (0);
}

int			mouse_press(int button, int x, int y, t_fdf *st)
{
	(void)x;
	(void)y;
	if (button == 4)
		st->camera.zoom++;
	if (button == 5 && st->camera.zoom > 0)
		st->camera.zoom--;
	if (button == 1)
	{
		st->mouse.x = x;
		st->mouse.y = y;
	}
	st->mouse.pressed = 1;
	mlx_clear_window(st->mlx_ptr, st->win_ptr);
	draw_map(st);
	return (0);
}

int			mouse_release(int button, int x, int y, t_fdf *st)
{
	(void)x;
	(void)y;
	(void)button;
	st->mouse.pressed = 0;
	return (0);
}

int			mouse_move(int x, int y, t_fdf *st)
{
	st->mouse.prev_x = st->mouse.x;
	st->mouse.prev_y = st->mouse.y;
	st->mouse.x = x;
	st->mouse.y = y;
	st->top = 0;
	if (st->mouse.pressed)
	{
		st->camera.beta += (x - st->mouse.prev_x) * 0.002;
		st->camera.alpha += (y - st->mouse.prev_y) * 0.002;
		mlx_clear_window(st->mlx_ptr, st->win_ptr);
		draw_map(st);
	}
	return (0);
}

void		init_controls(t_fdf *st)
{
	mlx_hook(st->win_ptr, 4, 1L << 2, mouse_press, st);
	mlx_hook(st->win_ptr, 2, 1L << 0, key_press, st);
	mlx_hook(st->win_ptr, 6, 1L << 13, mouse_move, st);
	mlx_hook(st->win_ptr, 5, 1L << 3, mouse_release, st);
}
