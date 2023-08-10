/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:37:12 by mwilsch           #+#    #+#             */
/*   Updated: 2022/11/25 09:53:09 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <strings.h>

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (n && ((unsigned char)s1[i] == (unsigned char)s2[i]))
// 	{
// 		if ((unsigned char)s1[i] == '\0' || (unsigned char)s2[i] == '\0')
// 			return (0);
// 		n--;
// 		i++;
// 	}
// 	if (n != 0)
// 		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// 	else
// 		return (0);
// }

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		if ((unsigned char)s2[i] > (unsigned char)s1[i])
			return (-1);
		i++;
		n--;
	}
	return (0);
}

// int main(void)
// {
// 	printf("%d\n", ft_strncmp("\x12\xff\x65\x12\xbd\xde\xad", "\x12\x02", 6));
// 	printf("%d", strncmp("\x12\xff\x65\x12\xbd\xde\xad", "\x12\x02", 6));
// }