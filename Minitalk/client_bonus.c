/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:08:50 by hrasolom          #+#    #+#             */
/*   Updated: 2024/07/15 13:50:00 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_bits_received = 0;

void	handle_ack(int sig)
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		g_bits_received++;
		if (g_bits_received == 0 || g_bits_received % 8 == 0)
		{
			ft_printf("Le server a bien recu le message.\n");
			if (g_bits_received == 0)
				exit(0);
		}
	}
}

void	send_bits(pid_t server_pid, unsigned char bits)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((bits >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(1000);
		i++;
	}
}

void	send_message(pid_t server_pid, const char *message)
{
	while (*message)
	{
		send_bits(server_pid, *message);
		message++;
	}
	send_bits(server_pid, '\0');
}

int	main(int argc, char *argv[])
{
	pid_t		pid;
	const char	*message;

	message = argv[2];
	if (argc != 3)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, handle_ack);
	signal(SIGUSR2, handle_ack);
	g_bits_received = ft_strlen(message) * 8;
	send_message(pid, message);
	return (0);
}
