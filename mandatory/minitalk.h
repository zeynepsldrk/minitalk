/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedurak <zedurak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:25:42 by zedurak           #+#    #+#             */
/*   Updated: 2025/11/06 19:25:43 by zedurak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void process_signal(int sig);
void check_signal(int i);
void move_bit(int pid, unsigned char c);
void	ft_putnbr_fd(int n, int fd);
int	ft_atoi(const char *str);

#endif