/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:58:52 by cjad              #+#    #+#             */
/*   Updated: 2021/11/14 16:13:24 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t	n)
{
	size_t	i;
	char	*cdst;
	char	*csrc;

	i = 0;
	if (!dst && !src)
		return (NULL);
	cdst = (char *) dst;
	csrc = (char *) src;
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
