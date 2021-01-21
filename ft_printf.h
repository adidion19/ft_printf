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

typedef struct  s_list
{
    int     zero_flag;
    int     t_flag;
    int     max;
    int     min;
    int     period;
    char    flag;
    int     zero_print;
    int     space_print;
    int     bool;
    int     bool2;
    int     bool3;
    int     bool4;
    int     bool5;
}               t_list;

#endif