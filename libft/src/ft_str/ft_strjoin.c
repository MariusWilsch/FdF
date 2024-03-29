/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:03:18 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/16 17:22:15 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*target;
	int		i;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2);
	target = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	if (target == NULL)
		return (NULL);
	ft_strlcpy(target, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(target, (char *)s2, size + 1);
	return (target);
}
