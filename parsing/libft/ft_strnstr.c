/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:18:27 by cjad              #+#    #+#             */
/*   Updated: 2021/11/11 11:38:13 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*str, const char	*needle, size_t	len)
{
	size_t	a;
	size_t	b;
	char	*s;

	a = 0;
	s = (char *) str;
	if (needle[0] == '\0')
		return (s);
	while (s[a] != '\0' && a < len)
	{
		b = 0;
		while (s[a + b] == needle[b])
		{
			if (needle[b + 1] == '\0' && (a + b) < len)
				return (&s[a]);
			b++;
		}
		a++;
	}
	return (0);
}
