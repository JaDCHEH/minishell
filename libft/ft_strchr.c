/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:54:43 by cjad              #+#    #+#             */
/*   Updated: 2021/11/16 14:28:28 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*s, int c)
{
	int		i;
	char	*str;
	char	cc;

	i = 0;
	cc = (char) c;
	str = (char *) s;
	while (str[i] != '\0')
	{
		if (str[i] == cc)
			return (str + i);
		i++;
	}
	if (s[i] == cc)
		return (str + i);
	else
		return (NULL);
}
