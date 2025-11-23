/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedurak <zedurak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:25:57 by zedurak           #+#    #+#             */
/*   Updated: 2025/11/06 19:25:58 by zedurak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void check_signal(int i)
{
    if (i == -1)
    {
        /* code */
    }
    
}

void

int main(void)
{
    struct sigaction sig;

    sig.sa_handler = process_signal;
    sig.sa_flags = 0;
    sigemptyset(&sig.sa_mask);
    sigaddset(SIGUSR1);
    sigaddset(SIGUSR2);
    sigaction(SIGUSR1, &sig, NULL);
    check_signal(sigaction(SIGUSR1, &sig, NULL));
    sigaction(SIGUSR2, &sig, NULL);
    check_signal(sigaction(SIGUSR2, &sig, NULL));
    ft_putnbr_fd(getpid(), 1);
    while (1)
        pause();
}
