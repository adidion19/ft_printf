/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:08:28 by adidion           #+#    #+#             */
/*   Updated: 2021/02/09 12:08:33 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_convert_s_4(int m, t_list lst)
{
	int k;

	k = 0;
	if (((!lst.max && !lst.period) || lst.bool) && lst.zero_flag)
		k = m;
	return (k);
}

int				ft_convert_s_3(int j, t_list lst)
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

char			*ft_convert_s_2(char *s, t_list lst)
{
	char	*str;
	int		j;
	int		m;
	int		k;

	str = 0;
	if (s == NULL)
		s = "(null)";
	j = ft_strlen(s);
	m = ft_convert_s_3(j, lst);
	k = ft_convert_s_4(m, lst);
	if (((!lst.max && !lst.period) || lst.bool) && lst.zero_flag)
		m = 0;
	while (!lst.t_flag && m-- > 0)
		ft_putchar_fd(' ', 1);
	while (k-- > 0)
		ft_putchar_fd('0', 1);
	if (j != 0 && ft_strlen_2(s) > lst.max && lst.max)
		str = ft_max(lst, s, str);
	else if (j != 0 && (lst.max || !lst.period || lst.bool))
		ft_putstr_fd(s, 1);
	while (lst.t_flag && m-- > 0)
		ft_putchar_fd(' ', 1);
	return (str);
}

char			*ft_convert_s(t_list lst, va_list ap)
{
	char *str;
	char *s;

	s = va_arg(ap, char*);
	str = ft_convert_s_2(s, lst);
	return (str);
}
