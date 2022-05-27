/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:16:50 by cjad              #+#    #+#             */
/*   Updated: 2021/11/14 15:45:52 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*cpys;

	i = 0;
	if (!s)
		return (NULL);
	cpys = (char *) s;
	str = (char *) malloc (sizeof (char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (cpys[i])
	{
		str[i] = (*f)(i, cpys[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
