/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:09:20 by adidion           #+#    #+#             */
/*   Updated: 2021/02/09 12:09:26 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_convert_x_3(int j, t_list lst)
{
	int m;

	m = 0;
	if (lst.max >= j)
		m = lst.min - lst.max;
	else
		m = lst.min - j;
	return (m);
}

int				ft_convert_x_4(int m, int j, t_list lst)
{
	int k;

	k = 0;
	if (!m)
		k = lst.max - j;
	else
		k = lst.max - j;
	if (((!lst.max && !lst.period) || lst.bool) && lst.zero_flag)
		k = m;
	return (k);
}

char			*ft_convert_x_2(char *base, long n, t_list lst)
{
	char	*str;
	int		j;
	int		k;
	int		m;

	str = ft_itoa_base(n, base);
	j = ft_strlen(str);
	m = ft_convert_x_3(j, lst);
	k = ft_convert_x_4(m, j, lst);
	if (((!lst.max && !lst.period) || lst.bool) && lst.zero_flag)
		m = 0;
	while (!lst.t_flag && m-- > 0)
		ft_putchar_fd(' ', 1);
	while (k-- > 0)
		ft_putchar_fd('0', 1);
	if (!(n == 0 && lst.period && (!lst.max && !lst.bool)))
		ft_putstr_fd(str, 1);
	else if (lst.min)
		ft_putchar_fd(' ', 1);
	while (lst.t_flag && m-- > 0)
		ft_putchar_fd(' ', 1);
	free(str);
	return (0);
}

char			*ft_convert_x(t_list lst, va_list ap)
{
	int		n;
	char	*str;
	char	*base;

	n = va_arg(ap, int);
	if (lst.flag == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	str = 0;
	str = ft_convert_x_2(base, n, lst);
	return (str);
}
