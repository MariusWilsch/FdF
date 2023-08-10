/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:52:37 by mwilsch           #+#    #+#             */
/*   Updated: 2022/11/14 15:10:09 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	int		size;
	char	*dest;
	int		i;

	size = len;
	if (start >= ft_strlen(src))
		return (ft_strdup(""));
	if ((size_t)start + len >= ft_strlen(src))
		size = ft_strlen(src) - start;
	dest = (char *)malloc(size + 1 * sizeof(char));
	i = 0;
	if (!dest)
		return (NULL);
	while (i < size)
		dest[i++] = src[start++];
	dest[i] = '\0';
	return (dest);
}
