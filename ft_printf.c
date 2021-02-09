/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:32:13 by adidion           #+#    #+#             */
/*   Updated: 2021/02/05 14:15:09 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_lst_flag(char *av, va_list ap, t_list lst)
{
	int i;

	i = 0;
	while (av[++i] && lst.flag == 0)
		if (av[i] == '-')
			lst = ft_t_flag(lst);
		else if (av[i] == '0' && !lst.period)
			lst = ft_zero_flag(lst);
		else if (av[i] >= '0' && av[i] <= '9')
			lst = ft_mm_flag(lst, ((char*)av) + i);
		else if (av[i] == '.')
			lst = ft_period(lst);
		else if (av[i] == '*')
			lst = ft_star(lst, ap);
		else
			lst = ft_read_flag(lst, av, i);
	if (lst.flag == 0)
		return (0);
	if (lst.zero_flag && !lst.emax && lst.period)
		lst = ft_flag_2(lst);
	else if (lst.zero_flag && !lst.emin)
		lst = ft_flag_1(lst);
	return (ft_flag(lst, ap));
}

char			*ft_lst_init(char *av, va_list ap)
{
	t_list	lst;
	char	*str;

	str = 0;
	lst.t_flag = 0;
	lst.zero_flag = 0;
	lst.zero_print = 0;
	lst.space_print = 0;
	lst.min = 0;
	lst.flag = 0;
	lst.emin = 0;
	lst.emax = 0;
	lst.max = 0;
	lst.period = 0;
	lst.bool = 0;
	str = (ft_lst_flag(((char*)av), ap, lst));
	return (str);
}

int				ft_sum_i(char *av)
{
	int		i;
	char	*tab;
	int		count;

	count = 0;
	tab = "cspdiuxX%";
	count++;
	while (av[count])
	{
		i = -1;
		while (tab[++i])
			if (tab[i] == av[count])
				return (++count);
		count++;
	}
	return (0);
}

int				ft_printf(const char *av, ...)
{
	int		i;
	va_list	ap;
	char	*str;
	char	*s;
	int		j;

	va_start(ap, av);
	i = 0;
	str = 0;
	ft_putchar_fd(' ', -6);
	while (av[i])
	{
		if (av[i] == '%')
		{
			s = ft_lst_init(((char*)av) + i, ap);
			ft_putstr_fd(s, 1);
			if (!(i += ft_sum_i(((char*)av) + i)))
				return (-1);
		}
		else
			ft_putchar_fd(av[i++], 1);
	}
	j = ft_putchar_fd(' ', -4);
	va_end(ap);
	return (j);
}
