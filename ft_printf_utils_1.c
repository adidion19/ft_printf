unsigned int	ft_strlen(const char *str)
{
	unsigned int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int				ft_strlen_2(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char		*ft_strrev(char *str)
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

int				check_base_2(char *base)
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

int				check_base(int n, char *base)
{
	unsigned long	count;
	unsigned int	a;
	int				i;

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