/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 02:36:08 by dcapers           #+#    #+#             */
/*   Updated: 2020/06/17 04:22:50 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_map(int **m, int h, int w)
{
	int		i;
	int		j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			ft_printf("%2d ", m[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void		free_fdf(t_fdf	*st)
{
	int		i;

	if (!st)
		return;
	i = 0;
	if (st->map)
	{
		while (i < st->height && st->map[i])
			free(st->map[i++]);
		free(st->map);
	}
	free(st);		
}

t_fdf		*init_fdf(void)
{
	t_fdf		*st;

	if (!(st = (t_fdf *)malloc(sizeof(t_fdf))))
		force_exit("initilizing of fdf structure!");
	st->height = 0;
	st->width = 0;
	st->zoom = 5;
	st->shift_x = 150;
	st->shift_y = 150;
	return (st);
}

int			deal_key(int key, t_fdf *st)
{
	if (key == 65362)
		st->shift_y -= 10;
	if (key == 65364)
		st->shift_y += 10;
	if (key == 65361)
		st->shift_x -= 10;
	if (key == 65363)
		st->shift_x += 10;
	mlx_clear_window(st->mlx_ptr, st->win_ptr);
	draw_map(st);
	return (0);
}

int			mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (fdf)
		ft_putstr("FDF\n");
	ft_printf("%d\n", button);
	return (0);
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
		mlx_do_key_autorepeatoff (st->mlx_ptr);
		mlx_hook(st->win_ptr, 4, 0, mouse_press, st);
		draw_map(st);
		mlx_hook(st->win_ptr, 2, 0, deal_key, st);
		//mlx_key_hook(st->win_ptr, deal_key, st);
		mlx_loop(st->mlx_ptr);
		free_fdf(st);
	}
	else
		force_exit("couldn't find name of file!");
	return (0);
}