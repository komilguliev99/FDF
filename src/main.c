/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 02:36:08 by dcapers           #+#    #+#             */
/*   Updated: 2020/06/21 02:08:51 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_fdf(t_fdf *st)
{
	int		i;

	if (!st)
		return ;
	i = 0;
	if (st->map)
	{
		while (i < st->height && st->map[i])
			free(st->map[i++]);
		free(st->map);
	}
	free(st->win_ptr);
	free(st->mlx_ptr);
	free(st);
}

t_fdf		*init_fdf(void)
{
	t_fdf		*st;

	if (!(st = (t_fdf *)malloc(sizeof(t_fdf))))
		force_exit("initilizing of fdf structure!");
	st->height = 0;
	st->width = 0;
	st->zoom = 20;
	st->shift_x = 300;
	st->shift_y = 300;
	st->top = 0;
	st->camera.alpha = 0;
	st->camera.beta = 0;
	st->camera.gamma = 0;
	st->camera.zoom = 20;
	set_rgb(&st->start, 0, 255, 0);
	set_rgb(&st->end, 255, 0, 0);
	return (st);
}

int			main(int ac, char **av)
{
	t_fdf		*st;

	if (ac > 1)
	{
		st = init_fdf();
		read_map(av[1], st);
		st->mlx_ptr = mlx_init();
		st->win_ptr = mlx_new_window(st->mlx_ptr, 1000, 1000, "FDF");
		init_controls(st);
		draw_map(st);
		mlx_loop(st->mlx_ptr);
		free_fdf(st);
	}
	else
		force_exit("couldn't find name of file!");
	return (0);
}
