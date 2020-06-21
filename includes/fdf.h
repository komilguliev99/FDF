/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 02:27:42 by dcapers           #+#    #+#             */
/*   Updated: 2020/06/21 01:17:09 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MOD(a) (a > 0 ? a : -a)
# define Z_STEP	5
# define START_COLOR 0x00241e
# define MID_COLOR 0x097479
# define END_COLOR 0xaaff00

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <math.h>

typedef struct					s_rgb
{
	int							r;
	int							g;
	int							b;
}								t_rgb;

typedef struct					s_point
{
	float						x;
	float						y;
	int							z;
	char						has_z;
}								t_point;

typedef struct					s_camera
{
	float						alpha;
	float						beta;
	float						gamma;
	int							zoom;
}								t_camera;

typedef struct					s_mouse
{
	int							prev_x;
	int							prev_y;
	int							x;
	int							y;
	char						pressed;
}								t_mouse;

typedef struct					s_step
{
	float						x;
	float						y;
	float						z_step;
}								t_step;

typedef struct					s_fdf
{
	int							width;
	int							height;
	int							zoom;
	int							shift_x;
	int							shift_y;
	int							max_z;
	t_rgb						start;
	t_rgb						end;
	int							top;
	t_point						**map;
	t_camera					camera;
	t_mouse						mouse;
	void						*mlx_ptr;
	void						*win_ptr;
}								t_fdf;

void							read_map(char *file_name, t_fdf *st);
void							strup_to(char **line, char c);
void							draw_map(t_fdf *st);
int								get_color(float z, t_fdf *st);
void							projection(t_point *p, t_fdf *st);
void							force_exit(char *s);
int								mouse_move(int x, int y, t_fdf *st);
int								mouse_release(int button, int x, int y,
															t_fdf *st);
int								mouse_press(int button, int x, int y,
															t_fdf *st);
int								key_press(int key, t_fdf *st);
void							init_controls(t_fdf *st);
void							update_points(t_point **mp, int n,
													int m, char c);
void							set_rgb(t_rgb *rgb, int r, int g, int b);

#endif
