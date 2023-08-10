/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:43:07 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/20 16:46:20 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

	// else if (temp->pts[temp->max_pts - temp->x_max].x_iso)
	// 	return (true);
bool	y_border_up(t_data **data)
{
	t_data	*temp = (*data);
	const int	height = temp->height;
	if (temp->pts[0].y_iso > 100)
		return (true);
	else 
	{
		temp->y_offset += 5;
		return (false);
	}
}

bool y_border_down(t_data **data)
{
	t_data	*temp = (*data);
	const int	height = temp->height;
	if (temp->pts[temp->max_pts - 1].y_iso < height - 100)
		return (true);
	else
	{
		temp->y_offset -= 5;
		return (false);
	}
}
