/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:10:14 by cjad              #+#    #+#             */
/*   Updated: 2021/11/16 17:12:03 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	int		i;
	char	*str;
	char	cc;

	str = (char *) s;
	i = 0;
	cc = (char) c;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == cc)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
