/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:08:50 by hrasolom          #+#    #+#             */
/*   Updated: 2024/07/15 13:42:28 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_bits_received = 0;

void	handle_ack(int sig)
{
	(void)sig;
	g_bits_received--;
}

void	send_bytes(pid_t server_pid, unsigned char bits)
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

void	send_messages(pid_t server_pid, const char *message)
{
	while (*message)
	{
		send_bytes(server_pid, *message);
		message++;
	}
	send_bytes(server_pid, '\0');
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
	send_messages(pid, message);
	return (0);
}
