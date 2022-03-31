/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:45:03 by cjad              #+#    #+#             */
/*   Updated: 2021/11/12 11:38:10 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	backwardmove(char	*src, char	*dst, size_t	i)
{
	while (i > 0)
	{
		dst[i] = src[i];
		i--;
	}
	dst[i] = src[i];
}

static void	move(char	*src, char	*dst, size_t	n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t	n)
{
	size_t	i;
	char	*cdst;
	char	*csrc;

	if (n == 0 || (!dst && !src))
		return (dst);
	i = n - 1;
	cdst = (char *) dst;
	csrc = (char *) src;
	if (cdst > csrc)
		backwardmove(csrc, cdst, i);
	else if (cdst <= csrc)
		move(csrc, cdst, n);
	return (dst);
}
