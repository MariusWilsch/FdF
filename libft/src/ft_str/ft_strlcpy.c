/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:28:54 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/18 21:25:23 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i] = '\0';
	return (ft_strlen(src));
}

// int main()
// {
// 	char dst[50];
// 	char src[] = "Elon Musk";
// 	size_t len = 0;

// 	printf("%lu\t", strlcpy(dst, src, len));
// 	printf("%s", dst);

// 	// printf("%lu\t", ft_strlcpy(dst, src, len));
// 	// printf("%s", dst);
// }
