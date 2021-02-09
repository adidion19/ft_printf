/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:07:41 by adidion           #+#    #+#             */
/*   Updated: 2021/02/09 12:07:50 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_convert_c_3(int j, t_list lst)
{
	int m;

	m = 0;
	if (lst.max <= j && lst.max)
		m = lst.min - lst.max;
	else if (!lst.max && lst.period && lst.min && !lst.bool)
		m = lst.min;
	else
		m = lst.min - j;
	return (m);
}

char			*ft_convert_c_2(char c, t_list lst)
{
	char	*str;
	int		j;
	int		m;
	int		k;

	str = 0;
	j = 1;
	m = ft_convert_c_3(j, lst);
	k = 0;
	if (((!lst.max && !lst.period) || lst.bool) && lst.zero_flag)
	{
		k = m;
		m = 0;
	}
	if (!lst.t_flag)
		while (m-- > 0)
			ft_putchar_fd(' ', 1);
	while (k-- > 0)
		ft_putchar_fd('0', 1);
	ft_putchar_fd(c, 1);
	if (lst.t_flag)
		while (m-- > 0)
			ft_putchar_fd(' ', 1);
	return (str);
}

char			*ft_convert_c(t_list lst, va_list ap)
{
	char c;
	char *str;

	str = 0;
	if (lst.flag == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	str = ft_convert_c_2(c, lst);
	return (str);
}
