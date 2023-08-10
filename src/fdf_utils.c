/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:28:29 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/19 12:49:14 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_max_points(const char *filename, t_data **data)
{
	const int	fd = open(filename, O_RDONLY);
	char		*y_row;
	char		**x_col;
	int			y_cnt;
	int			x_cnt;

	if (!fd)
		ft_iserror("open failed");
	y_cnt = 0;
	x_cnt = 0;
	y_row = get_next_line(fd);
	x_col = ft_split(y_row, ' ');
	while (x_col[x_cnt] && x_col[x_cnt][0] != '\n')
		x_cnt++;
	while (y_row)
	{
		check_map(y_row, x_cnt);
		free(y_row);
		y_row = get_next_line(fd);
		y_cnt++;
	}
	(*data)->x_max = x_cnt;
	(*data)->y_max = y_cnt;
	free_split(x_col);
	return (close(fd), free(y_row), x_cnt * y_cnt);
}

void	free_split(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}

void	mlx_setup(t_data **data)
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	t_data				*temp;
	

	int	x = 0;
	int	y = 0;

	temp = (*data);
	mlx = mlx_init(temp->width, temp->height, "FdF", true);
	if (!mlx)
		ft_iserror("mlx ptr failed");
	img = mlx_new_image(mlx, temp->width, temp->height);
	if (!img)
		ft_iserror("img ptr failed");
	temp->mlx = mlx;
	temp->img = img;
	
}

void	cleaning_draw(t_data **data)
{
	t_data	*temp;

	temp = (*data);
	mlx_delete_image(temp->mlx, temp->img);
	mlx_terminate(temp->mlx);
}

// x_offset 
	// is the width - x_new + the most left points to to center it;
// y_offset is the height - y_new + z value

void	calc_space(t_point *pts, t_data **data)
{
	t_data		*t_d;
	int			dimensions;
	float		x_new;
	float		y_new;
	int			corner;

	t_d = (*data);
	dimensions = (t_d->x_max - 1) + (t_d->y_max - 1);
	t_d->zoom = (t_d->width + t_d->height) / dimensions / 2;
	x_new = dimensions * t_d->zoom * cos(t_d->angle);
	y_new = dimensions * t_d->zoom * sin(t_d->angle);
	corner = ((t_d->y_max - 1) * t_d->zoom * cos(t_d->angle));
	t_d->x_offset = (t_d->width - x_new) / 2 + corner;
	t_d->y_offset = ((t_d->height - y_new) / 2) + (pts[0].z * t_d->z_zoom);
}
