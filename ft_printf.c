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

char	*ft_convert_d_2(int n, int i, t_list lst)
{
	char *str;
	int j;

	str = 0;
	if (i == 0)
		return (0);
	if (n < 0)
	{
		str = ft_strjoin(str, "-");
		n = -n;
	}
	j = ft_strlen(ft_itoa(n));
	if (lst.t_flag == 0)
	{
		while ((i-- > lst.max) && (lst.min > j) && (lst.max > j))
		{
			str = ft_strjoin(str, " ");
		}
		while ((lst.max--) - j)
		{
			str = ft_strjoin(str, "0");
		}
	}
	return (str);
}

char *ft_convert_d(char *av , t_list lst, va_list ap)
{
    int n;
	int i;
    char *str;

	i = 0;
	n = va_arg(ap, int);
	if (lst.min >= lst.max)
		i = lst.min - lst.max;
	if (lst.t_flag == 0)
	{
		str = ft_convert_d_2(n, i, lst);
    	str = ft_strjoin(str, ft_itoa(n));
	}
	else
	{
		str = ft_itoa(n);
		str = ft_strjoin(str, ft_convert_d_2(n, i, lst));
	}
    return (str);
}

char *ft_flag(char **s, char *av , t_list lst, va_list ap)
{
    char *str;
    if (lst.flag == 'd' || lst.flag == 'i')
		str = (ft_convert_d(av, lst, ap));
    return (str);
}

void    ft_check_mm(char *av, t_list lst, va_list ap)
{
    int i;
	int n;

    i = 0;
    if (av[i] >= 1 && av[i] <= 9 && lst.period == 1)
        lst.max = ft_atoi(av);
    if (av[i] >= 1 && av[i] <= 9 && !lst.period)
        lst.min = ft_atoi(av);
	if (lst.zero_flag == 1 && lst.t_flag == 1)
		lst.zero_flag = 0;
	if (av[i] == '*' && lst.period == 0)
	{
		n = va_arg(ap, int);
		lst.min = n;
	}
	if (av[i] == '*' && lst.period == 1)
	{
		n = va_arg(ap, int);
		lst.max = n;
	}
	if (lst.zero_flag == 1 && lst.period == 0 && lst.min)
		lst.max = lst.min;
}

char *ft_lst_flag(char *s, char *av, va_list ap, t_list lst)
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
            lst.t_flag = 1;
        if (av[i] == '.')
            lst.period = 1;
        k = 0;
        while (tab[k++])
        {
            if (tab[k] == av[i])
            {
                lst.flag = av[i];
                break;
            }
        }
        ft_check_mm(((char*)(av)) + i, lst, ap);
    }
    str = ft_flag(&s, ((char*)(av)) + i, lst, ap);
    return (str);
}

char *ft_lst_init(char *s,char *av, va_list ap)
{
	t_list lst;
	char *str;

	lst.zero_flag = 0;
	lst.t_flag = 0;
	lst.max = 0;
	lst.min = 0;
	lst.period = 0;
	lst.flag = '\0';
	lst.star1 = 0;
	lst.star2 = 0;
	str = (ft_lst_flag(s,((char*)av), ap, lst));
	return (str);
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
   while (av[i])
    {
        if (av[i] == '%')
		{
            s = ft_lst_init(str, ((char*)av) + i, ap);
			j += ft_strlen(s);
			ft_putstr_fd(s, 1);
			i+=2;
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

int main()
{
    ft_printf("aaaa%.10dna\n", 515);
	printf("aaaa%.10dna\n", 515);
}