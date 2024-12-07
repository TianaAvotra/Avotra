/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:08:33 by hrasolom          #+#    #+#             */
/*   Updated: 2024/07/19 14:49:12 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_char_accumulated = '\0';

void	join_message(char **s, char tmp)
{
	char	*new_s;

	new_s = ft_strjoin(*s, tmp);
	free(*s);
	*s = new_s;
}

void	print_message(char **s)
{
	ft_printf("%s\n", *s);
	free(*s);
	*s = NULL;
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	bits = 0;
	static char	*s = NULL;
	char		temp[2];

	(void)context;
	if (sig == SIGUSR2)
		g_char_accumulated |= (1 << bits);
	bits++;
	if (bits == 8)
	{
		temp[0] = g_char_accumulated;
		temp[1] = '\0';
		if (s == NULL)
			s = ft_strjoin("", g_char_accumulated);
		else
		{
			join_message(&s, temp[0]);
		}
		if (g_char_accumulated == '\0')
			print_message(&s);
		bits = 0;
		g_char_accumulated = '\0';
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("PID du serveur : %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		usleep(100);
	}
	return (0);
}
