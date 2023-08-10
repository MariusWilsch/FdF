/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 09:12:23 by verdant           #+#    #+#             */
/*   Updated: 2023/01/16 17:14:20 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	check_map(char *line, int x_cnt)
{
	const int		size = ft_strlen(line) - 1;
	char			**line2;
	int				i;
	int				cnt;

	i = 0;
	cnt = 0;
	line2 = ft_split(line, ' ');
	while (line2[i])
		i++;
	if (i != x_cnt)
		ft_iserror("Numbers are missing");
	if (line[size] == '\n')
	{
		if (ft_isdigit(line[size - 1]))
			return (free_split(line2));
	}
	else
	{
		if (ft_isdigit(line[size]))
			return (free_split(line2));
	}
	ft_iserror("Check for spaces at the end of the line");
}

void	ft_iserror(char *msg)
{
	ft_printf("%s", msg);
	exit(1);
}
