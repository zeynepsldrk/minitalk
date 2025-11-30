/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedurak <zedurak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:52:25 by zedurak           #+#    #+#             */
/*   Updated: 2025/11/30 19:29:14 by zedurak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	g_valid;

void	move_again(int signal)
{
	(void)signal;
	g_valid = 1;
}

void	move_bit(int pid, unsigned char c)
{
	int	i;
	int	captured_bit;

	i = 7;
	while (i >= 0)
	{
		g_valid = 0;
		captured_bit = (c >> i) & 1;
		if (captured_bit == 0)
			checker(kill(pid, SIGUSR1));
		else
			checker(kill(pid, SIGUSR2));
		while (!g_valid)
			pause();
		if (g_valid == 1)
			write(1, "Approved\n",9);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;
	struct sigaction	sig;

	if (ac != 3)
		exit(1);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		exit(1);
	sig.sa_handler = move_again;
	sig.sa_flags = 0;
	checker(sigaction(SIGUSR1, &sig, NULL));
	i = 0;
	while (av[2][i])
	{
		move_bit(pid, av[2][i]);
		i++;
	}
	move_bit(pid, '\0');
	return (0);
}
