/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 02:30:43 by dcapers           #+#    #+#             */
/*   Updated: 2020/06/16 03:18:07 by dcapers          ###   ########.fr       */
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

void			force_exit(char *s)
{
	ft_putstr("Error in ");
	ft_putstr(s);
	ft_putchar('\n');
	exit(0);
}
