/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:32:31 by adidion           #+#    #+#             */
/*   Updated: 2021/02/09 12:26:12 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_list
{
	char	flag;
	int		t_flag;
	int		zero_flag;
	int		zero_print;
	int		space_print;
	int		min;
	int		emin;
	int		emax;
	int		max;
	int		period;
	int		bool;
}				t_list;

int				ft_printf(const char *av, ...);
int				ft_sum_i(char *av);
char			*ft_lst_init(char *av, va_list ap);
char			*ft_lst_flag(char *av, va_list ap, t_list lst);
void			*ft_max(t_list lst, char *s, char *str);
int				ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *str);
char			*ft_itoa_base(int n, char *base);
int				check_base_l(int n, char *base);
char			*ft_itol_base(unsigned long long n, char *base);
char			*ft_itoa(int n);
unsigned int	ft_strlen(const char *str);
int				ft_strlen_2(char *str);
int				check_base_2(char *base);
int				check_base(int n, char *base);
int				ft_sum(int i, char *av);
t_list			ft_read_flag(t_list lst, char *av, int i);
t_list			ft_period(t_list lst);
t_list			ft_flag_2(t_list lst);
t_list			ft_flag_1(t_list lst);
char			*ft_flag(t_list lst, va_list ap);
t_list			ft_mm_flag(t_list lst, char *av);
t_list			ft_t_flag(t_list lst);
t_list			ft_zero_flag(t_list lst);
t_list			ft_star(t_list lst, va_list ap);
int				ft_convert_x_3(int j, t_list lst);
int				ft_convert_x_4(int m, int j, t_list lst);
char			*ft_convert_x_2(char *base, long n, t_list lst);
char			*ft_convert_x(t_list lst, va_list ap);
int				ft_convert_u_3(int j, t_list lst);
int				ft_convert_u_4(int j, int m, t_list lst);
char			*ft_convert_u_2(char *base, unsigned int n, t_list lst);
char			*ft_convert_u(t_list lst, va_list ap);
int				ft_convert_s_4(int m, t_list lst);
int				ft_convert_s_3(int j, t_list lst);
char			*ft_convert_s_2(char *s, t_list lst);
char			*ft_convert_s(t_list lst, va_list ap);
int				ft_convert_p_4(int m, int j, t_list lst);
int				ft_convert_p_3(int j, t_list lst);
char			*ft_convert_p_2(char *base, long n, t_list lst);
char			*ft_convert_p(t_list lst, va_list ap);
int				ft_convert_d_3(int n, int j, t_list lst);
void			ft_convert_d_5(int n, int m, int k, t_list lst);
int				ft_convert_d_4(int n, int m, int j, t_list lst);
char			*ft_convert_d_2(int n, t_list lst);
char			*ft_convert_d(t_list lst, va_list ap);
int				ft_convert_c_3(int j, t_list lst);
char			*ft_convert_c_2(char c, t_list lst);
char			*ft_convert_c(t_list lst, va_list ap);

#endif
