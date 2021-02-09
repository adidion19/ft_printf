/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:08:18 by adidion           #+#    #+#             */
/*   Updated: 2021/02/09 12:08:23 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_convert_p_4(int m, int j, t_list lst)
{
	int k;

	k = 0;
	if (!m)
		k = lst.max - j;
	else
		k = lst.max - j;
	if (((!lst.max && !lst.period) || lst.bool) && lst.zero_flag)
	{
		k = m;
		m = 0;
	}
	return (k);
}

int				ft_convert_p_3(int j, t_list lst)
{
	int m;

	m = 0;
	if (lst.max >= j)
		m = lst.min - lst.max - 2;
	else
		m = lst.min - j - 2;
	return (m);
}

char			*ft_convert_p_2(char *base, long n, t_list lst)
{
	char	*str;
	int		j;
	int		k;
	int		m;

	str = ft_itol_base(n, base);
	j = ft_strlen(str);
	if (n == 0 && lst.min && lst.period && !lst.max)
		j = 0;
	m = ft_convert_p_3(j, lst);
	k = ft_convert_p_4(m, j, lst);
	if (!lst.t_flag)
		while (m-- > 0)
			ft_putchar_fd(' ', 1);
	ft_putstr_fd("0x", 1);
	while (k-- > 0)
		ft_putchar_fd('0', 1);
	if (!(n == 0 && lst.period && (!lst.max && !lst.bool)))
		ft_putstr_fd(str, 1);
	if (lst.t_flag)
		while (m-- > 0)
			ft_putchar_fd(' ', 1);
	free(str);
	return (0);
}

char			*ft_convert_p(t_list lst, va_list ap)
{
	unsigned long long	n;
	char				*str;
	char				*base;

	n = va_arg(ap, unsigned long long);
	base = "0123456789abcdef";
	str = ft_convert_p_2(base, n, lst);
	return (str);
}
