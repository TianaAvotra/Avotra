/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:55:11 by hrasolom          #+#    #+#             */
/*   Updated: 2024/04/22 12:24:31 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
int		ft_prints(va_list lists, const char format);
int		ft_printp(void);
int		ft_putchar_pf(int a);
void	ft_puthexan(unsigned int n, const char f);
int		ft_printhex(unsigned int n, const char format);
int		ft_printnbr(int n);
void	ft_ptr(unsigned long n);
int		ft_printptr(unsigned long p);
int		ft_printstr(char *str);
char	*ft_uitoa(unsigned int n);
int		ft_printu(unsigned int n);
char	*ft_itoa(int n);

#endif
