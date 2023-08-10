/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:04:04 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/19 12:28:43 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	*read_values(t_point *pts, char *y_line, int y, t_data **data)
{
	static int	cnt;
	char		**x_col;
	int			x;

	x_col = ft_split(y_line, ' ');
	x = 0;
	while (x_col[x])
	{
		pts[cnt].x = x;
		pts[cnt].y = y;
		pts[cnt].z = ft_atoi(x_col[x]);
		pts[cnt].color = check_for_hex(x_col[x]);
		cnt++;
		x++;
	}
	free_split(x_col);
	return (pts);
}

t_point	*parse_map(const char *filename, t_point *pts, t_data **data)
{
	const int	fd = open(filename, O_RDONLY);
	char		*y_line;
	int			y;

	pts = malloc(sizeof(t_point) * ((*data)->max_pts));
	if (!pts)
		return (NULL);
	y = 0;
	y_line = get_next_line(fd);
	while (y_line)
	{
		pts = read_values(pts, y_line, y, data);
		y++;
		free(y_line);
		y_line = get_next_line(fd);
	}
	close(fd);
	(*data)->pts = pts;
	return (pts);
}
