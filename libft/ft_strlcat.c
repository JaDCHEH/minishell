/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:13:29 by cjad              #+#    #+#             */
/*   Updated: 2021/11/12 16:07:10 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dest, const char	*src, size_t size)
{
	size_t	i;
	size_t	p;
	size_t	j;

	i = 0;
	p = 0;
	j = 0;
	if (!dest && size == 0)
		return (ft_strlen(src));
	i = ft_strlen(dest);
	j = ft_strlen(src);
	if (i >= size)
		return (size + j);
	while (src[p] != '\0' && p < size - i - 1)
	{
		dest[i + p] = src[p];
		p++;
	}
	dest[i + p] = '\0';
	return (i + j);
}
