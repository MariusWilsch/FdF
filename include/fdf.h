/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 09:08:04 by verdant           #+#    #+#             */
/*   Updated: 2023/01/20 16:31:50 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/MLX42/include/MLX42/MLX42_Input.h"
# include "../lib/MLX42/include/MLX42/MLX42_Int.h"
# include <CoreGraphics/CoreGraphics.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>

#define BPP sizeof(int32_t)

typedef struct point
{
	float			x;
	float			y;
	float			z;
	float			x_iso;
	float			y_iso;
	uint32_t	color;
}	t_point;

typedef struct draw_setup
{
	mlx_image_t			*img;
	int					dx;
	int					dy;
	int					error;
	int					x_step;
	int					y_step;
	int					x0;
	int					x1;
	int					y0;
	int					y1;
}	t_helper;

typedef struct data
{
	double		angle;
	int			max_pts;
	int			zoom;
	int			z_zoom;
	int32_t			width;
	int32_t			height;
	int			x_offset;
	int			y_offset;
	int			x_max;
	int			y_max;
	mlx_image_t		*img;
	mlx_t					*mlx;
	bool		flag;
	t_point *pts;
}	t_data;

/*			Utils			*/
int			get_max_points(const char *filename, t_data **data);
void		calc_space(t_point *pts, t_data **data);
void		free_split(char **line);
void		mlx_setup(t_data **data);
void		cleaning_draw(t_data **data);
int			get_rgba(int r, int g, int b, int a);

/*			Error Handling			*/
void		check_map(char *line, int x_cnt);
void		ft_iserror(char *msg);

/*			Parsing			*/
t_point		*parse_map(const char *filename, t_point *pts, t_data **data);
int			get_max_points(const char *filename, t_data **data);

/*			Drawing			*/
t_point		*cvt_iso(t_point *pts, t_data **data);
void		*draw_init(t_helper *setup, t_point *p0, t_point *p1);
void		draw_line(t_point *p0, t_point *p1, t_helper *setup);
void		draw(t_point *pts, t_data **data);

/*			Keys			*/
void	move_x(t_data **data, int num);
void	move_y(t_data **data, int num);
void	zoom(t_data **data, int num);
void	z_zoom(t_data **data, int num);
void	center(t_data **data);

/*			Colors			*/
void			background_color(t_data **data, uint32_t colour);
uint32_t	convert_hex(char *str, u_int32_t hex, int i);
uint32_t	check_for_hex(char *str);


bool	y_border_up(t_data **data);
bool y_border_down(t_data **data);
bool	check_for_boders(float x_iso, float y_iso, t_data **data);

#endif