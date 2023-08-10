/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:10:21 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/19 16:00:27 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	background_color(t_data **data, uint32_t colour)
{
	int							x;
	int							y;
	t_data					*temp;
	
	y = 0;
	temp = (*data);

	mlx_image_t	*img	= mlx_new_image(temp->mlx, temp->width, temp->height);
	if (!img)
		ft_iserror("Background img failed");
	while (y < temp->height)
	{
		x = 0;
		while (x < temp->width)
		{
			mlx_put_pixel(img, x, y, colour);
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(temp->mlx, img, 0, 0) > 0)
		ft_iserror("Background failed");
}

// printf("Before %s\t", str);
// printf("After %s\n", str);
uint32_t	convert_hex(char *str, u_int32_t hex, int i)
{
	int	value;
	
	value = 0;
	ft_memmove(str, str + i, 9); // Overwriting everthing before (inc.) Ox
	i = 6;
	while (i < 8)
		str[i++] = 'F'; // Adding FF for a channel
	str[i] = '\0';

	i = 0;
	while (i < 8)
	{
		value = 0;
		if (str[i] >= '0' && str[i] <= '9')
			value = str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			value = str[i] - 'A' + 10;
		hex = (hex << 4) | value;
		i++;
	}
	return (hex);
}


uint32_t	check_for_hex(char *str)
{
	// printf("%s\t", str);
	int	i = 0;
	uint32_t hex;
	

	hex = 0x39FF14FF;
	while (str[i] && str[i + 1]) // str[i] and str[i + 1] exsits
	{
		if (str[i] == '0' && str[i + 1] == 'x')
			hex = convert_hex(str, hex, i + ft_strlen("0x"));
		i++;
	}
	return (hex);
}



















// int get_rgba(int r, int g, int b, int a)
// {
// 		return (r << 24 | g << 16 | b << 8 | a);
// }

// How do colors work?

// 1. get_rgba() needs int values
// 2. 0x810202 needs to be converted to fit the 4 parameters of the func above
// 3. Forget about 0x
// 4. The 6 numbers need to be seperated into 3 pairs
	// For example 81 02 02
	// Those numbers are hex but each pair needs to be converted into ints
// 5. Convert each pair into ints
	// 81 = 129; 02 = 2; 02 = 2;
	// a is always 255 (max value)

// I need a function which splits the 6 numbers into 3 pairs with 2 nums
// Then I need to convert each pair from hex to int
// I can pass each pair into the rgba function

// 0x810202

// somehow memory get's overwritten when I do all 6 but let's do this tom

// I could use a char **arr and then malloc char *in them like in split

// So in theory 
	// arr = malloc(sizeof(char *) * 3);
// and then I could use arr[0], arr[1], arr[2]
// and arr[0][0] = 8; arr[0][1] = 1;

// void	get_rbga_ints(void)
// {
// 	char	r[3];
// 	char	b[3];
// 	char	g[3];
	
// 	int	i = 0;
// 	int k = 0;
	
// 	r[2] = '\0';
// 	b[2] = '\0';
// 	g[2] = '\0';

// 	char *str = "0x810202";
// 	while (i < 6)
// 	{
// 		if (i < 2)
// 		{
// 			r[k] = str[i + 2];
// 			putchar(r[k]);
// 			k++;
// 		}
// 		// if (i < 4)
// 		// {
// 		// 	b[k] = str[i + 2];
// 		// 	k++;
// 		// }
// 		if (i < 6)
// 		{
// 			g[k] = str[i + 2];
// 			k++;
// 		}
// 		if (i % 2 == 0)
// 			k = 0;
		
// 		i++;
// 	}
// }
