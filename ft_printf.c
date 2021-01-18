/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:58:38 by adidion           #+#    #+#             */
/*   Updated: 2021/01/11 13:59:12 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
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

/*void	print_struct(t_list lst)
{
	printf("%d\n", lst.zero_flag);
	printf("%d\n", lst.t_flag);
	printf("%d\n", lst.max);
	printf("%d\n", lst.min);
	printf("%d\n", lst.period);
	printf("%c\n", lst.flag);
	printf("%d\n", lst.zero_print);
	printf("%d\n", lst.space_print);
}*/

char	*ft_convert_s_2(char *s, t_list lst)
{
	int i;
	int k;
	int m;
	char *str;

	i = ft_strlen(s) + 1;
	if (!lst.bool && !lst.bool2)
		k = lst.min;
	if (lst.space_print == 1)
		k = lst.min;
	m = lst.min + 1;
	while (0 < m-- - k && lst.t_flag == 1 && !lst.bool && (!lst.bool3 || lst.t_flag == 0))
		str = ft_strjoin(str, " ");
	while (0 <= ((k--) - i) && lst.zero_print == 0 && (!lst.bool3 || lst.t_flag == 0))
		str = ft_strjoin(str, "0");
	str = ft_strjoin(str, s);
	k = lst.max;
	i--;
	if (lst.t_flag == 1 || lst.bool)
	{
		while (0 < m-- - i - k && (!lst.bool || lst.bool2))
			str = ft_strjoin(str, " ");
		m++;
		while (0 < m-- - i && lst.bool && !lst.bool2)
			str = ft_strjoin(str, " ");
	}
	return (str);
}

char	*ft_convert_s(t_list lst, va_list ap)
{
	char *str;
	char *s;

	s = va_arg(ap,char*);
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
	j = ft_strlen(ft_itoa(n)) + 1;
	k = lst.max;
	if (lst.space_print == 1)
		k = lst.min - 2;
	m = lst.min;
	//print_struct(lst);
	if ((n < 0 || lst.max == 0) && lst.t_flag == 0)
	{
		if (lst.bool == 1 || lst.t_flag == 1 || lst.bool3 == 1)
			k += 2;
		else
			k += 1;
	}
	if (n < 0 && lst.t_flag == 1)
		j--;
	if (lst.t_flag == 0 && lst.space_print == 0)
		while (0 < m-- - k)
			str = ft_strjoin(str, " ");
	if (n < 0)
	{
		str = ft_strjoin(str, "-");
		if (n < 0)
			m--;
		n = -n;
	}
	while (0 <= ((k--) - j) && lst.zero_print == 0)
		str = ft_strjoin(str, "0");
	str = ft_strjoin(str, ft_itoa(n));
	k = lst.max;
	j--;
	if (lst.t_flag == 1)
	{
		while (0 < m-- - j - k && lst.space_print == 0 && lst.bool && !lst.bool2 && lst.zero_print == 1)
			str = ft_strjoin(str, " ");
		m += 1;
		while (0 < m-- - k && lst.bool && !lst.bool2 && lst.space_print == 0 && lst.zero_print == 0)
			str = ft_strjoin(str, " ");
		m += 1;
		while (0 < m-- - j && !lst.bool && !lst.bool2 && lst.zero_print == 0 && lst.bool3)
			str = ft_strjoin(str, " ");
		m++;
		while (0 < m-- - k && !lst.bool && !lst.bool2 && lst.space_print == 0 && !lst.bool3)
			str = ft_strjoin(str, " ");
	}
	return (str);
}

char *ft_convert_d(t_list lst, va_list ap)
{
	int n;
	char *str;

	n = va_arg(ap, int);
	str = ft_convert_d_2(n, lst);
	return (str);
}

char *ft_flag(t_list lst, va_list ap)
{
	char *str;

	str = 0;
	if (lst.flag == 'd' || lst.flag == 'i')
		str = (ft_convert_d(lst, ap));
	if (lst.flag == 's')
		str = (ft_convert_s(lst, ap));
	return (str);
}

t_list    ft_check_mm(char *av, t_list lst, va_list ap)
{
	int i;
	int n;

	i = 0;
	if (av[i] >= '1' && av[i] <= '9' && lst.period == 1 && lst.max == 0)
		lst.max = ft_atoi(av + i);
	if (av[i] >= '1' && av[i] <= '9' && !lst.period && lst.min == 0)
		lst.min = ft_atoi(av + i);
	if (lst.zero_flag == 1 && lst.t_flag == 1)
		lst.zero_flag = 0;
	if (av[i] == '*' && lst.period == 0)
	{
		n = va_arg(ap, int);
		if (n < 0)
		{
			lst.bool = 1;
			lst.t_flag = 1;
			lst.min = -n;
		}
		else
			lst.min = n;
	}
	if (av[i] == '*' && lst.period == 1)
	{
		n = va_arg(ap, int);
		if (n < 0)
		{
			lst.bool3 = 1;
			if (lst.bool == 1)
				lst.zero_print = 1;
			else if (lst.t_flag == 1)
				lst.space_print = 0;
			else
				lst.space_print = 1;
			lst.max = 0;
		}
		else
			lst.max = n;
	}
	if (lst.zero_flag == 1 && lst.period == 0 && lst.min)
		lst.max = lst.min;
	return (lst);
}

char *ft_lst_flag(char *av, va_list ap, t_list lst)
{
	char *tab;
	int k;
	char *str;
	int i;

	tab = "cspdiuxX%";
	i = 0;
	while (av[++i])
	{
		if (av[i] == '0')
			lst.zero_flag = 1;
		if (av[i] == '-')
		{
			if (lst.period == 1)
				lst.zero_print = 1;
			lst.t_flag = 1;
		}
		if (av[i] == '.')
		{
			lst.period = 1;
			lst.max = 0;
		}
		k = 0;
		while (tab[k++])
		{
			if (tab[k] == av[i])
			{
				lst.flag = av[i];
				break;
			}
		}
		lst = ft_check_mm(((char*)(av)) + i, lst, ap);
		if ((av[i] >= '1' && av[i] <= '9') || (av[i] == '0' && av[i - 1] >= '1' && av[i - 1] <= '9'))
		{
			while ((av[i] >= '1' && av[i] <= '9') || (av[i] == '0' && av[i - 1] >= '1' && av[i - 1] <= '9'))
				i++;
			i--;
		}
	}
	str = ft_flag(lst, ap);
	return (str);
}

char *ft_lst_init(char *av, va_list ap)
{
	t_list lst;
	char *str;

	lst.zero_flag = 0;
	lst.t_flag = 0;
	lst.max = 0;
	lst.min = 0;
	lst.period = 0;
	lst.flag = '\0';
	lst.zero_print = 0;
	lst.space_print = 0;
	lst.bool = 0;
	lst.bool2 = 0;
	lst.bool3 = 0;
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
			ft_putchar_fd(av[i], 1);
			i++;
			j++;
		}
	}
	va_end(ap);
	return (j);
}

#include <stdio.h>

int main()
{
	ft_printf("aaaa%*.*dna\n", 40, -20, "abcdef");
	printf("aaaa%*.*dna\n", 40, -20, "abcdef");
}