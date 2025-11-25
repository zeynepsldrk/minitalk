#include "minitalk_bonus.h"

void move_bit(int pid, unsigned char c)
{
    int i;
    int captured_bit;

    i = 7;
    while (i >= 0)
    {
        captured_bit = (c >> i) & 1;
        if (captured_bit == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(400);
        i--;
    }
    
}

int main(int ac, char **av)
{
    int pid;
    int i;

    if (ac != 3)
        exit(1);
    else
    {
        pid = ft_atoi(av[1]);
        if (pid < 0)
            exit(1);
        i = 0;
        while (av[2][i])
        {
            move_bit(pid, av[2][i]);
            i++;
        }
        move_bit(pid, av[2][i]);
    }
    return (0);
}
