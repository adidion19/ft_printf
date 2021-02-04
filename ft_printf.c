/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:32:13 by adidion           #+#    #+#             */
/*   Updated: 2021/02/02 13:48:34 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int		ft_strlen(const char *str)
{
	unsigned int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int			ft_strlen_2(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	while (i < len / 2)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
		i++;
	}
	return (str);
}

int		check_base_2(char *base)
{
	int i;
	int j;

	if (!base)
		return (0);
	i = -1;
	while (base[++i])
	{
		j = -1;
		while (base[++j])
		{
			if (i == j)
				;
			else if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

int     check_base(int n, char *base)
{
	unsigned long count;
	unsigned int a;
	int i;

	i = ft_strlen(base);
	a = n;
	count = 0;
	while (a >= ft_strlen(base))
	{
		a = a / ft_strlen(base);
		count++;
	}
	count++;
	return (count);
}

char    *ft_itoa_base(int n, char *base)
{
    char			*ans;
	unsigned int	a;
	int				i;

	i = 0;
	if (!(check_base_2(base)))
		return (0);
	if (!(ans = (char*)malloc(sizeof(char) * (check_base(n, base) + 1))))
		return (0);
	a = n;
	while (a >= ft_strlen(base))
	{
		ans[i++] = base[a % ft_strlen(base)];
		a = a / ft_strlen(base);
	}
	ans[i++] = base[a % ft_strlen(base)];
	ans[i] = '\0';
	ft_strrev(ans);
	return (ans);
}

int     check_base_l(int n, char *base)
{
	unsigned long		count;
	unsigned long long	a;
	int					i;

	i = ft_strlen(base);
	a = n;
	count = 0;
	while (a >= ft_strlen(base))
	{
		a = a / ft_strlen(base);
		count++;
	}
	count++;
	return (count);
}

char    *ft_itol_base(unsigned long long n, char *base)
{
    char					*ans;
	unsigned long long		a;
	int						i;

	i = 0;
	if (!(check_base_2(base)))
		return (0);
	if (!(ans = (char*)malloc(sizeof(char) * (check_base_l(n, base) + 1))))
		return (0);
	a = n;
	while (a >= ft_strlen(base))
	{
		ans[i++] = base[a % ft_strlen(base)];
		a = a / ft_strlen(base);
	}
	ans[i++] = base[a % ft_strlen(base)];
	ans[i] = '\0';
	ft_strrev(ans);
	return (ans);
}

static int	len_of_int(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = n * -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

char		*ft_itoa(int n)
{
	char			*ans;
	int				bool_;
	unsigned int	a;
	int				i;

	bool_ = 1;
	i = 0;
	if (!(ans = (char*)malloc(sizeof(char) * (len_of_int(n) + 1))))
		return (0);
	if (n < 0)
		bool_ = 0;
	a = (n >= 0) ? n : -n;
	while (a >= 10)
	{
		ans[i++] = a % 10 + 48;
		a = a / 10;
	}
	ans[i++] = a % 10 + 48;
	if (bool_ == 0)
		ans[i++] = '-';
	ans[i] = '\0';
	ft_strrev(ans);
	return (ans);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	if (!(dest = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = -1;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup((char*)s2));
	if (!s2)
		return (ft_strdup((char*)s1));
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	j = i;
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	return (str);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = -1;
	if (s && fd)
	{
		while (s[++i])
			write(fd, &s[i], 1);
	}
}

static int	ft_isspace(char c)
{
	if (c == '\n' || c == ' ' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static long	ft_strtol(const char *str)
{
	unsigned long long	i;
	long long			ans;
	int					neg;
	int					j;

	i = 0;
	ans = 0;
	neg = 1;
	j = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		((str[i] == '-') && (neg = neg * -1));
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + str[i++] - '0';
		j++;
	}
	if (ans < 0 || j > 19)
		return (ans = (neg > 0) ? -1 : 0);
	ans = ans * neg;
	return ((long)ans);
}

int			ft_atoi(const char *str)
{
	long long i;

	i = ft_strtol(str);
	return ((int)i);
}

/*void ft_printfstruct(t_list lst)
{
    printf("%c\n", lst.flag);
    printf("%d\n", lst.t_flag);
    printf("%d\n", lst.zero_flag);
    printf("%d\n", lst.zero_print);
    printf("%d\n", lst.space_print);
    printf("|%d|\n", lst.min);
    printf("%d\n", lst.emin);
    printf("%d\n", lst.emax);
    printf("%d\n", lst.max);
    printf("|%d|\n", lst.period);
}*/

char	*ft_max(t_list lst, char *s, char *str)
{
	char temp[2];
	int i;
	int k;

	str = 0;
	i = 0;
	k = lst.max;
	while (k > i)
	{
		temp[0] = s[i];
		temp[1] = 1;
		str = ft_strjoin(str, temp);
		i++;
	}
	return (str);
}

char	*ft_convert_s_2(char *s, t_list lst)
{
	char *str;
	int j;
	int k;
	int m;

	str = 0;
	j = ft_strlen(s);
	if (lst.max >= j)
		m = lst.min - lst.max;
	else
		m = lst.min - j;
	if (!m)
		k = lst.max - j;
	else
		k = lst.max - j;
	if (((!lst.max && !lst.period) || lst.bool) && lst.zero_flag)
	{
		k = m;
		m = 0;
	}
	if (!lst.t_flag)
		while (m-- > 0)
			str = ft_strjoin(str, " ");
	while (k-- > 0)
		str = ft_strjoin(str, "0");
	if (s == NULL)
	{
		str = ft_strjoin(str, "");
	}
	else if (j != 1 && ft_strlen_2(s) > lst.max && lst.max)
		str = ft_max(lst, s, str);
	else if (j != 1)
		str = ft_strjoin(str, s);
	if (lst.t_flag)
		while (m-- > 0)
			str = ft_strjoin(str, " ");
    return (str);
}

char	*ft_convert_s(t_list lst, va_list ap)
{
	char *str;
	char *s;

	s = va_arg(ap, char*);
	str = ft_convert_s_2(s, lst);
	return (str);
}

char	*ft_convert_d_2(int n, t_list lst)
{
    char *str;
	int j;
	int k;
	int m;

    str = 0;
	j = ft_strlen(ft_itoa(n));
	if (lst.max >= j)
		m = lst.min - lst.max;
	else
		m = lst.min - j;
	if (!m)
		k = lst.max - j;
	else
		k = lst.max - j;
	if (n < 0)
		k++;
	if (lst.max >= j && n < 0)
		m--;
	if (((!lst.max && !lst.period) || lst.bool) && lst.zero_flag)
	{
		k = m;
		m = 0;
	}
	if (!lst.t_flag)
		while (m-- > 0)
			str = ft_strjoin(str, " ");
	if (n < 0)
	{
		str = ft_strjoin(str, "-");
		n = -n;
	}
	while (k-- > 0)
		str = ft_strjoin(str, "0");
	if (n == -2147483648)
		str = ft_strjoin(str, "2147483648");
	else if (n == 0 && lst.period && (!lst.max && !lst.bool))
	{
		if (!lst.min)
			;
		else
			str = ft_strjoin(str, " ");
	}
	else
    	str = ft_strjoin(str, ft_itoa(n));
	if (lst.t_flag)
		while (m-- > 0)
			str = ft_strjoin(str, " ");
    return (str);
}

char *ft_convert_d(t_list lst, va_list ap)
{
	int n;

	n = va_arg(ap, int);
	return (ft_convert_d_2(n, lst));
}

char *ft_flag(t_list lst, va_list ap)
{
	char *str;

	str = 0;
	if (lst.flag == 'd' || lst.flag == 'i')
		str = (ft_convert_d(lst, ap));
	else if (lst.flag == 's')
		str = (ft_convert_s(lst, ap));
	//else if (lst.flag == 'c' || lst.flag == '%')
	//	str = (ft_convert_c(lst, ap));
	//else if (lst.flag == 'x' || lst.flag == 'X')
	//	str = (ft_convert_x(lst, ap));
	//else if (lst.flag == 'p')
	//	str = (ft_convert_p(lst, ap));
	//else if (lst.flag == 'u')
	//	str = (ft_convert_u(lst, ap));
	return (str);
}

t_list      ft_mm_flag(t_list lst, char *av)
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

t_list      ft_t_flag(t_list lst)
{
    if (lst.zero_flag)
        lst.zero_flag = 0;
    lst.t_flag = 1;
    return (lst);
}

t_list     ft_zero_flag(t_list lst)
{
    if (lst.t_flag)
        return (lst);
    lst.zero_flag = 1;
    return (lst);
}

t_list     ft_star(t_list lst, va_list ap)
{
    int n; 

    if (lst.period == 0)
    {
        lst.emin = 1;
        n = va_arg(ap, int);
        if (n < 0)
		{
			lst = ft_t_flag(lst);
			lst.min = -n;
		}
		else
			lst.min = n;
    }
    else if (lst.period == 1)
    {
        lst.emax = 1;
        n = va_arg(ap, int);
        if (n < 0)
		{
			//lst = ft_t_flag(lst);
			lst.max = 0;
			lst.bool = 1;
		}
		else
			lst.max = n;
    }
    return (lst);
}

int     ft_sum(int i, char *av)
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

t_list      ft_read_flag(t_list lst, char *av, int i)
{
    int k;
    char *tab;

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

char *ft_lst_flag(char *av, va_list ap, t_list lst)
{
    int i;

    i = 0;
    while (av[++i] && lst.flag == 0)
    {
        if (av[i] == '-')
            lst = ft_t_flag(lst);
        else if (av[i] == '0' && !lst.period) //&& av[i + 1] >= '1' && av[i + 1] <= '9')
            lst = ft_zero_flag(lst);
        else if (av[i] >= '0' && av[i] <= '9')
        {
           lst = ft_mm_flag(lst, ((char*)av) + i);
		   //i += ft_sum(i, ((char*)av) + i);
        }
        else if (av[i] == '.')
		{
            lst.period = 1;
			if (lst.zero_flag && !lst.emin)
			{
				lst.min = 0;
				lst.emin = 1;
				lst.zero_flag = 0;
			}
		}
        else if (av[i] == '*')
            lst = ft_star(lst, ap);
        lst = ft_read_flag(lst, av, i);
    }
	if (lst.zero_flag && !lst.emax && lst.period)
	{
		lst.max = 0;
		lst.emax = 1;
		lst.zero_flag = 0;
	}
	else if (lst.zero_flag && !lst.emin)
			{
				lst.min = 0;
				lst.emin = 1;
				lst.zero_flag = 0;
			}
	return (ft_flag(lst, ap));
}

char *ft_lst_init(char *av, va_list ap)
{
	t_list lst;
	char *str;

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

int		ft_sum_i(char *av)
{
	int i;
	char *tab;
	int count;

	count = 0;
	tab = "cspdiuxX%";
	count++;
	while (av[count])
	{
		i = -1;
		while (tab[++i])
			if(tab[i] == av[count])
				return (++count);
		count++;
	}
	return (0);
}

int     ft_printf(const char *av, ...)
{
	int i;
	va_list ap;
	va_start(ap, av);
	char *str;
	char *s;
	int j;

	i = 0;
	j = 0;
	str = 0;
	while (av[i])
	{
		if (av[i] == '%')
		{
			s = ft_lst_init(((char*)av) + i, ap);
			j += ft_strlen(s);
			ft_putstr_fd(s, 1);
			i += ft_sum_i(((char*)av) + i);
		}
		else
		{
			ft_putchar_fd(av[i++], 1);
			j++;
		}
	}
	va_end(ap);
	return (j);
}
