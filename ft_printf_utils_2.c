/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:09:46 by adidion           #+#    #+#             */
/*   Updated: 2021/02/09 12:52:35 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_itoa_base(int n, char *base)
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

int				check_base_l(int n, char *base)
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

char			*ft_itol_base(unsigned long long n, char *base)
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

static int		len_of_int(int n)
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

char			*ft_itoa(int n)
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
