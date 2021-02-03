/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:32:31 by adidion           #+#    #+#             */
/*   Updated: 2021/02/02 13:48:42 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct  s_list
{
    char    flag;
    int     t_flag;
    int     zero_flag;
    int     zero_print;
    int     space_print;
    int     min;
    int     emin;
    int     emax;
    int     max;
    int     period;
    int     bool;
}              t_list;

int     ft_printf(const char *av, ...);

#endif
