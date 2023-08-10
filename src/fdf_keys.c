/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:42:32 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/20 16:43:32 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

	// x_borders(data, temp->x_offset);
	// if (x_flip(data))
	// else
	// {
	// 	temp->x_offset -= (num * -1);
	// 	draw(temp->pts, data);
	// }
void	move_x(t_data **data, int num)
{
	t_data *temp = (*data);
	temp->x_offset += num;
	ft_bzero(temp->img->pixels, temp->width * temp->height * BPP);
	draw(temp->pts, data);
}


void	move_y(t_data **data, int num)
{
	t_data *temp = (*data);
	ft_bzero(temp->img->pixels, temp->width * temp->height * BPP);
	if (temp->flag == true)
		temp->y_offset += num;
	// else 
	// 	temp->y_offset += num;
	draw(temp->pts, data);
}

// I need a extra check for z_zoom
	// find higest number in map and check for that y_border as well

void	z_zoom(t_data **data, int num)
{
	t_data *temp = (*data);
	ft_bzero(temp->img->pixels, temp->width * temp->height * BPP);
	if (temp->flag == true)
		temp->z_zoom += num;
	draw(temp->pts, data);
}
	// printf("pts: %f\theight: %d\n", temp->pts[0].y_iso, temp->height);

void	center(t_data **data)
{
	t_data *temp = (*data);
	ft_bzero(temp->img->pixels, temp->width * temp->height * BPP);
	calc_space(temp->pts, data);
	draw(temp->pts, data);
}
// NO border checking implemented
// void	zoom(t_data **data, int num)
// {
// 	t_data *temp = (*data);
// 	ft_bzero(temp->img->pixels, temp->width * temp->height * BPP);
// 	temp->zoom += num;
// 	draw(temp->pts, data);
// 
// }