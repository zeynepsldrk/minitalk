#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void process_signal(int sig);
void check_signal(int i);
void move_bit(int pid, unsigned char c);
void	ft_putnbr_fd(int n, int fd);
int	ft_atoi(const char *str);

#endif