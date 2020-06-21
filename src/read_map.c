/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 02:39:23 by dcapers           #+#    #+#             */
/*   Updated: 2020/06/21 01:14:48 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			set_sizes(t_fdf *st, char *file_name)
{
	int			process_id;
	char		*line;

	process_id = open(file_name, O_RDONLY);
	if (process_id <= 2)
		force_exit("opening of file!");
	while (get_next_line(process_id, &line) > 0)
	{
		if (!st->width)
			st->width = ft_wordcount(line, ' ');
		st->height++;
		free(line);
	}
	close(process_id);
}

static void			init_map(char *file_name, t_fdf *st)
{
	int		i;

	set_sizes(st, file_name);
	if (!(st->map = (t_point **)malloc(sizeof(t_point *) * st->height)))
		force_exit("allocating of (int *) sector!");
	i = 0;
	while (i < st->height)
		if (!(st->map[i++] = (t_point *)malloc(sizeof(t_point) * st->width)))
			force_exit("allocating of (int) sector!");
}

static void			set_map_cords(t_fdf *st, char *line, int i, int j)
{
	st->map[i][j].z = ft_atoi(line);
	st->map[i][j].x = j;
	st->map[i][j].y = i;
	st->map[i][j].has_z = st->map[i][j].z != 0;
	if (st->map[i][j].z > st->max_z)
		st->max_z = st->map[i][j].z;
}

void				read_map(char *file_name, t_fdf *st)
{
	int		i;
	int		j;
	int		id;
	char	*line;
	char	*start;

	init_map(file_name, st);
	id = open(file_name, O_RDONLY);
	i = 0;
	while (i < st->height)
	{
		j = 0;
		get_next_line(id, &line);
		start = line;
		while (j < st->width)
		{
			set_map_cords(st, line, i, j);
			strup_to(&line, ' ');
			j++;
		}
		i++;
		free(start);
	}
	close(id);
}
