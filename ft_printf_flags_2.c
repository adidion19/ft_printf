/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:22:49 by adidion           #+#    #+#             */
/*   Updated: 2021/02/10 11:35:54 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_sum(int i, char *av)
{
	int j;

	j = 0;
	while (av[i] >= '0' && av[i] <= '9')
	{
		i++;
		j++;
	}
	return (j);
}

t_list			ft_read_flag(t_list lst, char *av, int i)
{
	int		k;
	char	*tab;

	tab = "cspdiuxX%";
	k = -1;
	while (tab[++k])
	{
		if (tab[k] == av[i])
		{
			lst.flag = av[i];
		}
	}
	if (lst.flag == 0)
		ft_putchar_fd(av[i], 1);
	return (lst);
}

t_list			ft_period(t_list lst)
{
	lst.period = 1;
	if (lst.zero_flag && !lst.emin)
	{
		lst.min = 0;
		lst.emin = 1;
		lst.zero_flag = 0;
	}
	return (lst);
}

t_list			ft_flag_2(t_list lst)
{
	lst.max = 0;
	lst.emax = 1;
	lst.zero_flag = 0;
	return (lst);
}

t_list			ft_flag_1(t_list lst)
{
	lst.min = 0;
	lst.emin = 1;
	lst.zero_flag = 0;
	return (lst);
}
