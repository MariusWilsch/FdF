/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:50:25 by verdant           #+#    #+#             */
/*   Updated: 2023/01/20 16:38:30 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"




t_point	*cvt_iso(t_point *pts, t_data **data)
{
	t_data	*temp;
	int		cnt;
	int		x_prev;
	int		y_prev;
	int		z;

	cnt = 0;
	temp = (*data);
	while (cnt < temp->max_pts)
	{
		x_prev = pts[cnt].x * (temp->zoom);
		y_prev = pts[cnt].y * (temp->zoom);
		z = pts[cnt].z *(temp->z_zoom);
		
		pts[cnt].x_iso = (x_prev - y_prev) * cos(temp->angle);
		pts[cnt].y_iso = -z + (x_prev + y_prev) * sin(temp->angle);
		
		pts[cnt].x_iso += temp->x_offset;
		pts[cnt].y_iso += temp->y_offset;
		temp->flag = check_for_boders(pts[cnt].x_iso, pts[cnt].y_iso,  data);
		cnt++;
	}
	// check_for_boders(pts, data);
	return (pts);
}

void	*draw_init(t_helper *setup, t_point *p0, t_point *p1)
{
	setup->x0 = p0->x_iso;
	setup->y0 = p0->y_iso;
	setup->x1 = p1->x_iso;
	setup->y1 = p1->y_iso;
	setup->dx = abs(setup->x1 - setup->x0);
	setup->dy = -abs(setup->y1 - setup->y0);
	setup->error = (setup->dx + setup->dy);
	if (setup->x0 < setup->x1)
		setup->x_step = 1;
	else
		setup->x_step = -1;
	if (setup->y0 < setup->y1)
		setup->y_step = 1;
	else
		setup->y_step = -1;
	return (setup);
}



void	draw_line(t_point *p0, t_point *p1, t_helper *setup)
{
	int				current_x;
	int				current_y;
	int				e2;

	setup = draw_init(setup, p0, p1);
	current_x = setup->x0;
	current_y = setup->y0;
	while (current_x != setup->x1 || current_y != setup->y1)
	{
		e2 = 2 * setup->error;
		if (e2 >= setup->dy)
		{
			current_x += setup->x_step;
			setup->error += setup->dy;
		}
		if (e2 <= setup->dx)
		{
			current_y += setup->y_step;
			setup->error += setup->dx;
		}
		mlx_put_pixel(setup->img, current_x, current_y, p0->color); 
	}
}

void	draw(t_point *pts, t_data **data)
{
	const t_data	*temp = (*data);
	t_helper		*setup;
	int				i;

	setup = ft_calloc(1, sizeof(t_helper));
	if (!setup)
		ft_iserror("Setup ptr failed");
	setup->img = temp->img;
	i = 0;
	pts = cvt_iso(pts, data);
	printf("%d", temp->flag);
	while (i < temp->max_pts)
	{
		if (((i + 1) % temp->x_max) != 0 || i == 0)
			draw_line(&pts[i], &pts[i + 1], setup);
		i++;
	}
	i = 0;
	while (i < (temp->max_pts - temp->x_max))
	{
		draw_line(&pts[i], &pts[i + temp->x_max], setup);
		i++;
	}
	free(setup);
}
