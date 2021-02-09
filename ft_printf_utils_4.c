/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:10:07 by adidion           #+#    #+#             */
/*   Updated: 2021/02/09 12:10:12 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			*ft_max(t_list lst, char *s, char *str)
{
	char	temp[2];
	int		i;
	int		k;

	i = 0;
	k = lst.max;
	while (k > i)
	{
		temp[0] = s[i];
		temp[1] = 0;
		ft_putstr_fd(temp, 1);
		i++;
	}
	return (str);
}
