/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedurak <zedurak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:25:39 by zedurak           #+#    #+#             */
/*   Updated: 2025/11/30 20:29:52 by zedurak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		exit(1);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		exit(1);
	if ((signal(SIGUSR1, move_again)) == SIG_ERR)
		exit(1);
	i = 0;
	while (av[2][i])
	{
		move_bit(pid, av[2][i]);
		i++;
	}
	move_bit(pid, '\0');
	return (0);
}
