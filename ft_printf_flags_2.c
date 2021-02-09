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