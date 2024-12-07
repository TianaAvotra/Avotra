/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:09:22 by hrasolom          #+#    #+#             */
/*   Updated: 2024/07/19 14:49:29 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdarg.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

int		ft_atoi(const char *nptr);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const s2);
void	handle_signal(int sig, siginfo_t *info, void *context);
void	handle_ack(int sig);
void	send_bits(pid_t server_pid, unsigned char bits);
void	send_message(pid_t server_pid, const char *message);
int		ft_prints(va_list lists, const char format);
int		ft_printf(const char *str, ...);
int		ft_printnbr(int n);
int		ft_printstr(char *str);
char	*ft_itoa(int n);
void	join_message(char **s, char tmp);
void	print_message(char **s);

/*bonus*/
void	send_messages(pid_t server_pid, const char *message);
void	send_bytes(pid_t server_pid, unsigned char bits);
void	handle_signal_bonus(int sig, siginfo_t *info, void *context);
void	handle_complete_character(siginfo_t *info, char **s);

#endif
