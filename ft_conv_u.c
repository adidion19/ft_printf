/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:08:39 by adidion           #+#    #+#             */
/*   Updated: 2021/02/09 12:08:44 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_convert_u_3(int j, t_list lst)
{
	int m;

	m = 0;
	if (lst.max >= j)
		m = lst.min - lst.max;
	else
		m = lst.min - j;
	return (m);
}

int				ft_convert_u_4(int j, int m, t_list lst)
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

char			*ft_convert_u_2(char *base, unsigned int n, t_list lst)
{
	char	*str;
	int		j;
	int		k;
	int		m;

	str = ft_itoa_base(n, base);
	j = ft_strlen(str);
	m = ft_convert_u_3(j, lst);
	k = ft_convert_u_4(j, m, lst);
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

char			*ft_convert_u(t_list lst, va_list ap)
{
	unsigned int	n;
	char			*str;
	char			*base;

	n = va_arg(ap, unsigned int);
	base = "0123456789";
	str = ft_convert_u_2(base, n, lst);
	return (str);
}
