/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:54:41 by cjad              #+#    #+#             */
/*   Updated: 2021/11/12 11:37:50 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

static int	numlen(long n)
{
	int	l;

	l = 1;
	if (n < 0)
	{
		n = -n;
		l++;
	}
	while (n > 9)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

static void	fillthestring(char	*s, int len, long n)
{
	int	i;

	i = len - 1;
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (i >= 0 && n > 9)
	{
		s[i] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	s[i] = n + 48;
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*s;
	int		i;

	nb = (long) n;
	i = 0;
	len = numlen(nb);
	s = (char *) malloc (sizeof (char) * (len + 1));
	if (!s)
		return (NULL);
	while (i < len)
	{
		s[i] = '1';
		i++;
	}
	s[i] = '\0';
	fillthestring(s, len, nb);
	return (s);
}
