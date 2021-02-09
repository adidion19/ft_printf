/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:09:35 by adidion           #+#    #+#             */
/*   Updated: 2021/02/09 12:09:40 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_flag(t_list lst, va_list ap)
{
	char *str;

	str = 0;
	if (lst.flag == 'd' || lst.flag == 'i')
		str = (ft_convert_d(lst, ap));
	else if (lst.flag == 's')
		str = (ft_convert_s(lst, ap));
	else if (lst.flag == 'c' || lst.flag == '%')
		str = (ft_convert_c(lst, ap));
	else if (lst.flag == 'x' || lst.flag == 'X')
		str = (ft_convert_x(lst, ap));
	else if (lst.flag == 'p')
		str = (ft_convert_p(lst, ap));
	else if (lst.flag == 'u')
		str = (ft_convert_u(lst, ap));
	return (str);
}

t_list			ft_mm_flag(t_list lst, char *av)
{
	if (lst.period == 1 && !lst.max)
	{
		lst.max = ft_atoi(av);
		lst.emax = 1;
	}
	else if (lst.period == 0 && !lst.min)
	{
		lst.min = ft_atoi(av);
		lst.emin = 1;
	}
	return (lst);
}

t_list			ft_t_flag(t_list lst)
{
	if (lst.zero_flag)
		lst.zero_flag = 0;
	lst.t_flag = 1;
	return (lst);
}

t_list			ft_zero_flag(t_list lst)
{
	if (lst.t_flag)
		return (lst);
	if (!lst.min)
		lst.zero_flag = 1;
	return (lst);
}

t_list			ft_star(t_list lst, va_list ap)
{
	int n;

	if (lst.period == 0)
	{
		lst.emin = 1;
		n = va_arg(ap, int);
		if (n < 0)
			lst = ft_t_flag(lst);
		if (n < 0)
			lst.min = -n;
		else
			lst.min = n;
	}
	else if (lst.period == 1)
	{
		lst.emax = 1;
		n = va_arg(ap, int);
		if (n < 0)
			lst.max = 0;
		if (n < 0)
			lst.bool = 1;
		else
			lst.max = n;
	}
	return (lst);
}
