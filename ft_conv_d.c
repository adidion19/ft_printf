/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:08:04 by adidion           #+#    #+#             */
/*   Updated: 2021/02/09 12:08:10 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_convert_d_3(int n, int j, t_list lst)
{
	int m;

	m = 0;
	if (lst.max >= j)
		m = lst.min - lst.max;
	else
		m = lst.min - j;
	if (lst.max >= j && n < 0)
		m--;
	return (m);
}

void			ft_convert_d_5(int n, int m, int k, t_list lst)
{
	char *s;

	s = 0;
	while (!lst.t_flag && m-- > 0)
		ft_putchar_fd(' ', 1);
	if (n < 0)
		ft_putchar_fd('-', 1);
	if (n < 0)
		n = -n;
	while (k-- > 0)
		ft_putchar_fd('0', 1);
	s = ft_itoa(n);
	if (n == -2147483648)
		ft_putstr_fd("2147483648", 1);
	else if (n == 0 && lst.period && (!lst.max && !lst.bool))
	{
		if (lst.min)
			ft_putchar_fd(' ', 1);
	}
	else
		ft_putstr_fd(s, 1);
	while (lst.t_flag && m-- > 0)
		ft_putchar_fd(' ', 1);
	free(s);
}

int				ft_convert_d_4(int n, int m, int j, t_list lst)
{
	int k;

	k = 0;
	if (!m)
		k = lst.max - j;
	else
		k = lst.max - j;
	if (n < 0)
		k++;
	return (k);
}

char			*ft_convert_d_2(int n, t_list lst)
{
	char	*s;
	int		j;
	int		k;
	int		m;

	s = ft_itoa(n);
	j = ft_strlen(s);
	free(s);
	m = ft_convert_d_3(n, j, lst);
	k = ft_convert_d_4(n, m, j, lst);
	if (((!lst.max && !lst.period) || lst.bool) && lst.zero_flag)
		k = m;
	if (((!lst.max && !lst.period) || lst.bool) && lst.zero_flag)
		m = 0;
	ft_convert_d_5(n, m, k, lst);
	return (0);
}

char			*ft_convert_d(t_list lst, va_list ap)
{
	int n;

	n = va_arg(ap, int);
	return (ft_convert_d_2(n, lst));
}
