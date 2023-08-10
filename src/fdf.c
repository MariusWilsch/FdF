/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 08:51:07 by verdant           #+#    #+#             */
/*   Updated: 2023/01/20 21:04:03 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// Add to main if you wanna check leaks
void	leaks(void)
{
	system("leaks -q FdF");
}

// Colors are added in the mlx_put_pixel when I'm drawing. 
// I need to somehow parse the colors and convert them to int


// I could use a jumptable for this
// I also need to make it that It can only be increased to a max and min value

// NO border checking implemented
	// if (mlx_is_key_down(temp->mlx, MLX_KEY_KP_ADD))
	// 	zoom(data, 1);
	// if (mlx_is_key_down(temp->mlx, MLX_KEY_KP_SUBTRACT))
	// 	zoom(data, -1);
void	my_keyhook(t_data **data)
{
	t_data *temp = (*data);
	
	if (mlx_is_key_down(temp->mlx, MLX_KEY_ESCAPE))
		return (mlx_close_window(temp->mlx));
	
	if (mlx_is_key_down(temp->mlx, MLX_KEY_RIGHT))
		move_x(data, 20);
	if (mlx_is_key_down(temp->mlx, MLX_KEY_LEFT))
		move_x(data, -20);
	if (mlx_is_key_down(temp->mlx, MLX_KEY_DOWN))
		move_y(data, 20);
	if (mlx_is_key_down(temp->mlx, MLX_KEY_UP))
		move_y(data, -20);
	if (mlx_is_key_down(temp->mlx, MLX_KEY_W))
		z_zoom(data, 1);
	if (mlx_is_key_down(temp->mlx, MLX_KEY_S))
		z_zoom(data, -1);
	if (mlx_is_key_down(temp->mlx, MLX_KEY_R))
		center(data);
}

void	set_data(t_data **data, const char *filename)
{
	CGDirectDisplayID	mainDisplay;
	CGRect						screenRect;

	mainDisplay = CGMainDisplayID();
	screenRect = CGDisplayBounds(mainDisplay);
	(*data)->width = screenRect.size.width;
	(*data)->height = screenRect.size.height;
	(*data)->max_pts = (get_max_points(filename, data));
	if ((*data)->max_pts < 4)
		ft_iserror("Smaller than 4");
	(*data)->angle = 30 * (M_PI / 180);
	(*data)->z_zoom = 1;
	mlx_setup(data);
	background_color(data, 0xFFFFFFFF);
}


// Why does it segfault when a point reaches the bottom of y or the top of y?
// And how can I fix it?
// How can I keep the drawing inside of the screen?


int	main(int argc, char *argv[])
{
	const char	*filename = argv[1];
	t_point		*pts;
	t_data		*data;

	data = ft_calloc(1, sizeof(t_data));
	if (argc != 2 || open(filename, O_RDONLY) < 0 || !data)
		ft_iserror("Wrong Inputs or malloc failed");
	set_data(&data, filename);
	pts = parse_map(filename, pts, &data);
	calc_space(pts, &data);
	draw(pts, &data);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) > 0)
		ft_iserror("img ptr failed");
	// mlx_key_hook(data->mlx, &my_keyhook, &data);
	mlx_loop_hook(data->mlx, &my_keyhook, &data);
	mlx_loop(data->mlx);
	cleaning_draw(&data);
	return (free(data), free(pts), EXIT_SUCCESS);
}
// atexit(leaks);
