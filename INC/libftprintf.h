/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:29:05 by afrolova          #+#    #+#             */
/*   Updated: 2022/07/07 20:16:59 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "libft.h"

//ft_printf.c
int		ft_printf(char const *str, ...);
int		return_value(va_list ptr, char const *str, int *we);
//ft_write.c
int		my_putchar(int c, int *we);
int		ft_write(int fd, char *c, int i, int *we);
int		ft_strlen_print(char *str, int *we);
//ft_numbers.c
int		ft_putnbr(int n, int *we);
int		ft_putnbr_unsigned(unsigned int n, int *we);
//ft_hexadecimals.c
int		to_hexadecimal(unsigned int n, char str, int *we);
int		to_hexadecimal_ptr(unsigned long long n, int *we);
int		ft_write_pointer(unsigned long long n, int *we);

#endif
