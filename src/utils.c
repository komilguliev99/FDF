/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 02:30:43 by dcapers           #+#    #+#             */
/*   Updated: 2020/06/21 01:15:01 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			strup_to(char **line, char c)
{
	char		*tmp;

	if (!line)
		return ;
	if (**line == c)
		(*line)++;
	tmp = *line;
	while (tmp && *tmp != '\0' && *tmp != c)
		tmp++;
	if (*tmp != '\0')
		tmp++;
	*line = tmp;
}

void			update_points(t_point **mp, int n, int m, char c)
{
	int			i;

	while (--n >= 0)
	{
		i = m;
		while (--i >= 0)
		{
			if (c == '+' && mp[n][i].has_z)
				mp[n][i].z += Z_STEP;
			else if (mp[n][i].has_z)
				mp[n][i].z -= Z_STEP;
		}
	}
}

void			set_rgb(t_rgb *rgb, int r, int g, int b)
{
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
}

void			force_exit(char *s)
{
	ft_putstr("Error in ");
	ft_putstr(s);
	ft_putchar('\n');
	exit(0);
}
