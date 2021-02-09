/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:09:56 by adidion           #+#    #+#             */
/*   Updated: 2021/02/09 12:52:07 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_putchar_fd(char c, int fd)
{
	static int	i;
	int			z;

	z = 0;
	if (fd == -6)
	{
		i = 0;
		return (i);
	}
	else if (fd == -4)
		return (i);
	else if (c == '\0')
	{
		write(1, &z, 1);
		i++;
		return (i);
	}
	else
	{
		write(fd, &c, 1);
		i++;
		return (i);
	}
}

void			ft_putstr_fd(char *s, int fd)
{
	int i;

	i = -1;
	if (s && fd)
	{
		while (s[++i])
			ft_putchar_fd(s[i], fd);
	}
}

static int		ft_isspace(char c)
{
	if (c == '\n' || c == ' ' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static long		ft_strtol(const char *str)
{
	unsigned long long	i;
	long long			ans;
	int					neg;
	int					j;

	i = 0;
	ans = 0;
	neg = 1;
	j = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		((str[i] == '-') && (neg = neg * -1));
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + str[i++] - '0';
		j++;
	}
	if (ans < 0 || j > 19)
		return (ans = (neg > 0) ? -1 : 0);
	ans = ans * neg;
	return ((long)ans);
}

int				ft_atoi(const char *str)
{
	long long i;

	i = ft_strtol(str);
	return ((int)i);
}
