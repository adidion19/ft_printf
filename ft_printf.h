/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:24:10 by adidion           #+#    #+#             */
/*   Updated: 2020/12/16 11:28:04 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define INT_MAX 2147483647

typedef struct  s_list
{
    int     zero_flag;
    int     t_flag;
    int     max;
    int     min;
    int     period;
    char    flag;
    int     star1;
    int     star2;
}               t_list;

#endif
