/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 02:27:42 by dcapers           #+#    #+#             */
/*   Updated: 2020/06/17 03:27:05 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MOD(a) (a > 0 ? a : -a)

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <math.h>

typedef struct					s_point
{
	float						x;
	float						y;
	int							z;
}								t_point;

typedef struct					s_step
{
	float						x;
	float						y;
}								t_step;


typedef struct					s_fdf
{
	int							width;
	int							height;
	int							zoom;
	int							shift_x;
	int							shift_y;
	t_point						**map;

	void						*mlx_ptr;
	void						*win_ptr;
}								t_fdf;

void							read_map(char *file_name, t_fdf *st);
void							strup_to(char **line, char c);
void							draw_map(t_fdf *st);
void							force_exit(char *s);

#endif