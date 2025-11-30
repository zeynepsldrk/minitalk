/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedurak <zedurak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:25:57 by zedurak           #+#    #+#             */
/*   Updated: 2025/11/30 16:20:55 by zedurak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	process_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	current_bit;
	static int				bit_count;

	(void)context;
	if (sig == SIGUSR2)
		current_bit |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &current_bit, 1);
		if (current_bit == '\0')
			write(1, "\n", 1);
		current_bit = 0;
		bit_count = 0;
	}
	checker(kill(info->si_pid, SIGUSR1));
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = process_signal;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask, SIGUSR1);
	sigaddset(&sig.sa_mask, SIGUSR2);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	checker(sigaction(SIGUSR1, &sig, NULL));
	checker(sigaction(SIGUSR2, &sig, NULL));
	while (1)
		pause();
	return (0);
}
