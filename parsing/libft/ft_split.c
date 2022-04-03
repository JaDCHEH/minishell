/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:33:21 by cjad              #+#    #+#             */
/*   Updated: 2021/11/16 14:53:23 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_counter(const char	*s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			j++;
		}
		i++;
	}
	return (j);
}

static char	*ft_strndup(const char	*s1, size_t	n)
{
	size_t		i;
	char		*scpy;

	scpy = (char *) malloc (sizeof(char) * n + 1);
	if (!scpy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		scpy[i] = s1[i];
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}

void	ft_fill_string(char const	*s, char c, char	**strs, int count)
{
	int	i;
	int	j;
	int	a;

	a = 0;
	i = 0;
	while (s[i] != '\0' && a < count)
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] != c && s[j] != '\0')
				j++;
			strs[a] = ft_strndup(&s[i], (j - i));
			i = j - 1;
			a++;
		}
		i++;
	}
	strs[a] = NULL;
}

char	**ft_split(char const	*s, char c)
{
	int		count;
	char	**strs;

	if (!s)
		return (NULL);
	count = words_counter(s, c);
	strs = (char **) malloc (sizeof(char *) * count + 1);
	if (!strs)
		return (NULL);
	ft_fill_string(s, c, strs, count);
	return (strs);
}
