/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:49:46 by cjad              #+#    #+#             */
/*   Updated: 2021/11/16 14:59:51 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	result(const char	*str, int i, int s)
{
	long	n;
	long	tmp;

	n = 0;
	tmp = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = str[i] - '0' + n * 10;
		if (tmp != (n / 10))
		{
			if (s == 1)
				return (-1);
			if (s == -1)
				return (0);
		}
		tmp = n;
		i++;
	}
	return (s * n);
}

int	ft_atoi(const char	*str)
{
	int		i;
	long	n;
	int		s;

	i = 0;
	s = 1;
	n = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	n = result (str, i, s);
	return (n);
}
